#if !defined(AVL_HPP)
#define AVL_HPP

#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

#include "avlNode.hpp"
#include "avlIterator.hpp"
#include "../utils/pair.hpp"

namespace ft
{
	template <typename K, typename V, typename alloc = std::allocator<avlNode <K,V> > >
	class avlTree
	{
	public:
		typedef alloc									allocator_type;
		typedef avlNode<K, V> 							node_type;
		typedef node_type 								*node_pointer;
		typedef ft::pair<K,V>							content_type;
		typedef avlIterator<node_type, content_type> 	iterator;

		allocator_type	m_alloc;
		node_pointer	m_root;

	public:
		avlTree() : m_root(NULL) {}
		avlTree(const avlTree & x) 
		{ 
			for (avlTree::iterator it = x.begin(); it < x.end(); it++)
			{
				std::cout << it->first << std::endl;
				create_node(*it);
			}	
		}
		~avlTree()
		{
			delete_branch(m_root);
		}

		int getHeight() { return m_root->getHeight(); }

		node_pointer create_node(content_type content)
		{
			node_pointer node = m_alloc.allocate(1);
			m_alloc.construct(node, node_type(content));
			node->content = content;
			return node;
		}

		void delete_node(node_pointer node)
		{
			m_alloc.destroy(node);
			m_alloc.deallocate(node, 1);
		}
		void delete_branch(node_pointer node)
		{
			if (node == NULL)
				return;
			delete_branch(node->left);
			delete_branch(node->right);
			delete_node(node);
		}

		bool insert(content_type pair)
		{
			if (m_root == NULL)
				m_root = create_node(pair);
			else
			{
				node_pointer added_node = NULL;
				node_pointer temp = m_root;
				while (temp != NULL && added_node == NULL)
				{
					if (pair.first < temp->content.first)
					{
						if (temp->left == NULL)
							added_node = temp->setLeft(create_node(pair));
						else
							temp = temp->left;
					}
					else if (pair.first > temp->content.first)
					{
						if (temp->right == NULL)
							added_node = temp->setRight(create_node(pair));
						else
							temp = temp->right;
					}
					else
						return false;
				}

				temp = added_node;
				while (temp != NULL)
				{
					temp->updateHeight();
					balanceAtNode(temp);
					temp = temp->parent;
				}
			}
			return true;
		}

		bool remove(K key)
		{
			node_pointer toBeRemoved = findNode(key);
			if (toBeRemoved == NULL)
				return false;
			enum
			{
				left,
				right
			} side;
			node_pointer p = toBeRemoved->parent;
			if (p != NULL &&
				p->left == toBeRemoved)
				side = left;
			else
				side = right;
			if (toBeRemoved->left == NULL)
				if (toBeRemoved->right == NULL)
				{
					if (p == NULL)
					{
						setRoot(NULL);
						delete_node(toBeRemoved);
					}
					else
					{
						if (side == left)
							p->setLeft(NULL);
						else
							p->setRight(NULL);
						delete_node(toBeRemoved);
						p->updateHeight();
						balanceAtNode(p);
					}
				}
				else
				{
					if (p == NULL)
					{
						setRoot(toBeRemoved->right);
						delete_node(toBeRemoved);
					}
					else
					{
						if (side == left)
							p->setLeft(toBeRemoved->right);
						else
							p->setRight(toBeRemoved->right);
						delete_node(toBeRemoved);
						p->updateHeight();
						balanceAtNode(p);
					}
				}
			else if (toBeRemoved->right == NULL)
			{
				if (p == NULL)
				{
					setRoot(toBeRemoved->left);
					delete_node(toBeRemoved);
				}
				else
				{
					if (side == left)
						p->setLeft(toBeRemoved->left);
					else
						p->setRight(toBeRemoved->left);
					delete_node(toBeRemoved);
					p->updateHeight();
					balanceAtNode(p);
				}
			}
			else
			{
				node_pointer replacement;
				node_pointer replacement_parent;
				node_pointer temp_node;
				int bal = toBeRemoved->getBalance();
				if (bal > 0)
				{
					if (toBeRemoved->left->right == NULL)
					{
						replacement = toBeRemoved->left;
						replacement->setRight(toBeRemoved->right);
						temp_node = replacement;
					}
					else
					{
						replacement = toBeRemoved->left->right;
						while (replacement->right != NULL)
							replacement = replacement->right;
						replacement_parent = replacement->parent;
						replacement_parent->setRight(replacement->left);
						temp_node = replacement_parent;
						replacement->setLeft(toBeRemoved->left);
						replacement->setRight(toBeRemoved->right);
					}
				}
				else if (toBeRemoved->right->left == NULL)
				{
					replacement = toBeRemoved->right;
					replacement->setLeft(toBeRemoved->left);
					temp_node = replacement;
				}
				else
				{
					replacement = toBeRemoved->right->left;
					while (replacement->left != NULL)
						replacement = replacement->left;

					replacement_parent = replacement->parent;
					replacement_parent->setLeft(replacement->right);
					temp_node = replacement_parent;
					replacement->setLeft(toBeRemoved->left);
					replacement->setRight(toBeRemoved->right);
				}
				if (p == NULL)
					setRoot(replacement);
				else if (side == left)
					p->setLeft(replacement);
				else
					p->setRight(replacement);
				delete_node(toBeRemoved);
				balanceAtNode(temp_node);
			}
			return true;
		}
		V getValue(K key)
		{
			node_pointer n = findNode(key);
			if (n == NULL)
				return 0;
			return n->content.second;
		}
		node_pointer getFirst()
		{
			if (m_root == NULL)
				return NULL;
			node_pointer node = m_root;
			while (node->left != NULL)
				node = node->left;
			return node;
		}

		iterator begin()
		{
			iterator it(m_root, getFirst());
			return it;
		}

		node_pointer getLast()
		{
			if (m_root == NULL)
				return NULL;
			node_pointer node = m_root;
			while (node->right != NULL)
				node = node->right;
			return node;
		}
		iterator end()
		{
			iterator it(m_root, getLast() + 1);
			return it;
		}

		// debug
		void print()
		{
			if (m_root == NULL)
			{
				std::cout << "Empty" << std::endl;
				return;
			}
			int max = m_root->getHeight();
			for (int depth = 0; depth <= max; depth++)
			{
				printSubtree(m_root, depth, max - depth + 1, true);
				std::cout << std::endl;
			}
		}

	private:
		void balanceAtNode(node_pointer n)
		{
			int bal = n->getBalance();
			if (bal > 1)
			{
				if (n->left->getBalance() < 0)
					rotateLeft(n->left);
				rotateRight(n);
			}
			else if (bal < -1)
			{
				if (n->right->getBalance() > 0)
					rotateRight(n->right);
				rotateLeft(n);
			}
		}
		void rotateLeft(node_pointer n)
		{
			enum
			{
				left,
				right
			} side;
			node_pointer p = n->parent;
			if (p != NULL && p->left == n)
				side = left;
			else
				side = right;
			node_pointer temp = n->right;
			n->setRight(temp->left);
			temp->setLeft(n);
			if (p == NULL)
				setRoot(temp);
			else if (side == left)
				p->setLeft(temp);
			else
				p->setRight(temp);
		}
		void rotateRight(node_pointer n)
		{
			enum
			{
				left,
				right
			} side;
			node_pointer p = n->parent;
			if (p != NULL && p->left == n)
				side = left;
			else
				side = right;
			node_pointer temp = n->left;
			n->setLeft(temp->right);
			temp->setRight(n);
			if (p == NULL)
				setRoot(temp);
			else if (side == left)
				p->setLeft(temp);
			else
				p->setRight(temp);
		}
		void setRoot(node_pointer n)
		{
			m_root = n;
			if (m_root != NULL)
				m_root->removeParent();
		}

		node_pointer findNode(K key)
		{
			node_pointer temp = m_root;
			while (temp != NULL)
			{
				if (key == temp->content.first)
					break;
				else if (key < temp->content.first)
					temp = temp->left;
				else
					temp = temp->right;
			}
			return temp;
		}

		// debug
		void printSubtree(node_pointer subtree, int depth, int level, bool first)
		{
			if (depth > 0)
			{
				if (subtree == NULL)
				{
					printSubtree(subtree, depth - 1, level, first);
					printSubtree(subtree, depth - 1, level, false);
				}
				else
				{
					printSubtree(subtree->left, depth - 1, level, first);
					printSubtree(subtree->right, depth - 1, level, false);
				}
			}
			else if (subtree == NULL)
				std::cout << std::setw((first) ? spacing(level) / 2 : spacing(level)) << "-";
			else
				std::cout << std::setw((first) ? spacing(level) / 2 : spacing(level)) << subtree->content.first;
		}
		int spacing(int level)
		{
			int result = 2;
			for (int i = 0; i < level; i++)
				result += result;
			return result;
		}
	};

} // ft
#endif // AVL_HPP

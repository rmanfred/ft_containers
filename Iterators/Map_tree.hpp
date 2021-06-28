#pragma once

#include <iostream>
#include "Map_iterator.hpp"

template< class Key, class T >
class Map_node
{
    public:
		typedef Key								key_type;
		typedef T								mapped_type;
    	std::pair<key_type, mapped_type>		pair;
        Map_node								*left;
        Map_node								*right;
        Map_node								*parent;

		Map_node();
		~Map_node();

		Map_node<key_type, mapped_type>*    create_node(std::pair<key_type, mapped_type> value);
		Map_node<key_type, mapped_type>*    delete_node_2(key_type value, Map_node<key_type, mapped_type>* node, Map_node<key_type, mapped_type>* end);
		Map_node<key_type, mapped_type>*    getMin(Map_node<key_type, mapped_type>* node);
		Map_node<key_type, mapped_type>*    insert_node(Map_node<key_type, mapped_type>* node, std::pair<key_type, mapped_type> value, Map_node<Key, T>* end);
        Map_node                            &operator=(Map_node const &rhs);

};

template< class Key, class T >
Map_node<Key, T>::Map_node()
{
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
}

template< class Key, class T >
Map_node<Key, T>::~Map_node(){}

template< class Key, class T >
Map_node<Key, T>* Map_node<Key, T>::create_node(std::pair<Key, T> value)
{
	Map_node<Key, T> *new_node = new Map_node<Key, T>();
	new_node->pair = std::make_pair(value.first, value.second);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	return new_node;
}

template< class Key, class T >
Map_node<Key, T>* Map_node<Key, T>::insert_node(Map_node<Key, T>* node, std::pair<Key, T> value, Map_node<Key, T>* end)
{
    if (node == NULL)
		return create_node(value);
	if (value.first < node->pair.first)
    {
		node->left = insert_node(node->left, value, end);
        node->left->parent = node;
    }
	else if (value.first > node->pair.first)
    {
		if (node->right != end)
        {
            node->right = insert_node(node->right, value, end);
            node->right->parent = node;
        }
        else
        {
            node->right = create_node(value);
            node->right->parent = node;
            node->right->right = end;
            end->parent = node->right;
        }
    }
    return node;
}

template< class Key, class T >
Map_node<Key, T>* Map_node<Key, T>::getMin(Map_node<Key, T>* node)
{
    Map_node<Key, T>* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

template< class Key, class T >
Map_node<Key, T>* Map_node<Key, T>::delete_node_2(key_type value, Map_node<key_type, mapped_type>* node, Map_node<key_type, mapped_type>* end)
{
    if (node == NULL)
        return node;
    if (node == end)
        return node;
    if (value < node->pair.first)
        node->left = delete_node_2(value, node->left, end);
    else if (value > node->pair.first)
        node->right = delete_node_2(value, node->right, end);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            if (node->parent != NULL && node->parent->left == node)
                node->parent->left = NULL;
            else if (node->parent != NULL && node->parent->right == node)
                node->parent->right = NULL;
            delete node;
            return NULL; 
        }
        else if (node->right == NULL)
        {
            Map_node<Key, T>* tmp = node->left;

            if (node->parent != NULL && node->parent->left == node)
                node->parent->left = node->left;
            else if (node->parent != NULL && node->parent->right == node)
                node->parent->right = node->left;
            tmp->parent = node->parent;
            delete node;
            return tmp;
        }
        else if (node->left == NULL)
        {
            Map_node<Key, T>* tmp = node->right;

            if (node->parent != NULL && node->parent->left == node)
                node->parent->left = node->right;
            else if (node->parent != NULL && node->parent->right == node)
                node->parent->right = node->right;
            tmp->parent = node->parent;
            delete node;
            return tmp;
        }
        Map_node<Key, T>* tmp = getMin(node->right);
        node->pair.first = tmp->pair.first;
        node->pair.second = tmp->pair.second;
        node->right = delete_node_2(tmp->pair.first, node->right, end);
    }
    return node;
}

template< class Key, class T >
Map_node<Key, T>& Map_node<Key, T>::operator=(Map_node<Key, T> const &rhs)
{
    if (this != rhs)
    {
        parent = rhs.parent;
        left = rhs.left;
        right = rhs.right;
        pair = rhs.pair;
    }
    return *this;
}

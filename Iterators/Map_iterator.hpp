#pragma once

#include "Map_tree.hpp"

template< typename Key, typename T, typename Pointer, typename Reference>
class Map_iterator
{
	public:
		typedef std::pair<Key, T>						    value;
		typedef std::pair<Key, T>&					        reference;
		typedef Map_iterator<Key, T, T*, T&>				iter;
		typedef Map_iterator<Key, T, Pointer, Reference>	iter_class;
		typedef Map_node<Key, T>*							map_node;
		map_node											m_ptr;
	
	Map_iterator() 
    {
        m_ptr = NULL;
        m_ptr->left = NULL;
        m_ptr->right = NULL;
        m_ptr->parent = NULL;
    }
	Map_iterator(map_node const ptr) : m_ptr(ptr) {}
	~Map_iterator(){}

	Map_iterator(iter const &other)
	{
		*this = other;
	}
	Map_iterator &operator=(iter const &other)
	{
		m_ptr = other.m_ptr;
		return *this;
	}
	bool operator==(iter_class const &other)
	{
		return m_ptr == other.m_ptr;
	}
	bool operator!=(iter_class const &other)
	{
		return m_ptr != other.m_ptr;
	}
	value &operator*() const
	{
		return m_ptr->pair;
	}
	value *operator->() const
	{
		return &m_ptr->pair;
	}

    Map_iterator &operator++()
    {
        m_ptr = next_ptr(m_ptr);
        return *this;
    }

    Map_iterator operator++(int)
    {
        Map_iterator tmp = *this;
        m_ptr = next_ptr(m_ptr);
        return tmp;
    }

    Map_iterator &operator--()
    {
        m_ptr = previous_ptr(m_ptr);
        return *this;
    }

    Map_iterator operator--(int)
    {
        Map_iterator tmp = *this;
        m_ptr = previous_ptr(m_ptr);
        return tmp;
    }

    map_node node(void) { return m_ptr;}

    private:
        map_node next_ptr(map_node ptr)
        {
            map_node to_return;

            if (ptr == NULL)
                return NULL;
            if (ptr->right)
            {
                to_return = ptr->right;
                while (to_return && to_return->left)
                    to_return = to_return->left;
                return to_return;
            }
            to_return = ptr;
            while (to_return->parent && to_return == to_return->parent->right)
                to_return = to_return->parent;
            to_return = to_return->parent;
            return to_return;
        }

        map_node previous_ptr(map_node ptr)
        {
            map_node to_return;

            if (ptr == NULL)
                return NULL;
            if (ptr->left)
            {
                to_return = ptr->left;
                while (to_return->right)
                    to_return = to_return->right;
                return to_return;
            }
            to_return = ptr;
            while (to_return->parent && to_return == to_return->parent->left)
                to_return = to_return->parent;
            to_return = to_return->parent;
            return to_return;
        }
};


template< typename Key, typename T, typename Pointer, typename Reference>
class Reverse_Map_iterator
{
	public:
		typedef std::pair<Key, T>								    value;
		typedef std::pair<Key, T>&							        reference;
		typedef Map_node<Key, T>*									map_node;
		typedef Reverse_Map_iterator<Key, T, T*, T&>				iter;
		typedef Reverse_Map_iterator<Key, T, Pointer, Reference>	iter_class;
		map_node													m_ptr;
	
	Reverse_Map_iterator() : m_ptr(nullptr){}
	Reverse_Map_iterator(map_node const ptr) : m_ptr(ptr) {}
	~Reverse_Map_iterator(){}

	Reverse_Map_iterator(iter const &other)
	{
		*this = other;
	}
	Reverse_Map_iterator &operator=(iter const &other)
	{
		m_ptr = other.m_ptr;
		return *this;
	}
	bool operator==(iter_class const &other)
	{
		return m_ptr == other.m_ptr;
	}
	bool operator!=(iter_class const &other)
	{
		return m_ptr != other.m_ptr;
	}
	value &operator*() const
	{
		return m_ptr->pair;
	}
	value *operator->() const
	{
		return &m_ptr->pair;
	}

    Reverse_Map_iterator &operator--()
    {
        m_ptr = next_ptr(m_ptr);
        return *this;
    }

    Reverse_Map_iterator operator--(int)
    {
        Reverse_Map_iterator tmp = *this;
        m_ptr = next_ptr(m_ptr);
        return tmp;
    }

    Reverse_Map_iterator &operator++()
    {
        m_ptr = previous_ptr(m_ptr);
        return *this;
    }

    Reverse_Map_iterator operator++(int)
    {
        Reverse_Map_iterator tmp = *this;
        m_ptr = previous_ptr(m_ptr);
        return tmp;
    }

    private:
        map_node next_ptr(map_node ptr)
        {
            map_node to_return;

            if (ptr == NULL)
                return NULL;
            if (ptr->right)
            {
                to_return = ptr->right;
                while (to_return->left)
                    to_return = to_return->left;
                return to_return;
            }
            to_return = ptr;
            while (to_return->parent && to_return == to_return->parent->right)
                to_return = to_return->parent;
            to_return = to_return->parent;
            return to_return;
        }

        map_node previous_ptr(map_node ptr)
        {
            map_node to_return;

            if (ptr == NULL)
                return NULL;
            if (ptr->left)
            {
                to_return = ptr->left;
                while (to_return->right)
                    to_return = to_return->right;
                return to_return;
            }
            to_return = ptr;
            while (to_return->parent && to_return == to_return->parent->left)
                to_return = to_return->parent;
            to_return = to_return->parent;
            return to_return;
        }
};

#pragma once
#include <map>

#include <iostream>
#include "Iterators/Map_iterator.hpp"

namespace ft
{
    template< typename Key, typename T, typename Compare = std::less<Key>, class Allocator = std::allocator< std::pair<const Key, T> > >
    class map
    {
        public:
			typedef Key                                             										key_type;
			typedef T                                               										mapped_type;
			typedef std::pair<const key_type, mapped_type>          										value_type;
			typedef Compare                                        											key_compare;
			typedef Allocator																				allocator_type;
			typedef T&																						reference;
			typedef const T&																				const_reference;
			typedef T*																						pointer;
			typedef const T*																				const_pointer;
			typedef Map_node<key_type, mapped_type>*														map_node_ptr;
			typedef Map_iterator<key_type, mapped_type, pointer, reference>									iterator;
			typedef Map_iterator<key_type, mapped_type, const_pointer, const_reference>						const_iterator;
			typedef Reverse_Map_iterator<key_type, mapped_type, pointer, reference>							reverse_iterator;
			typedef Reverse_Map_iterator<key_type, mapped_type, const_pointer, const_reference>				const_reverse_iterator;
			typedef std::size_t																				size_type;
			typedef std::ptrdiff_t																			difference_type;
			
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
		private:
			allocator_type		_alloc;
			map_node_ptr		_root;
			map_node_ptr		_end;
			size_type			_size;
			key_compare			_compare;

			void init_map(const key_compare& comp, const allocator_type& alloc)
			{
				_compare = comp;
				_alloc = alloc;
				_size = 0;
			}

			map_node_ptr find_node(map_node_ptr root, key_type key)
			{
				if (!root)
					return root;
				if (root && root->pair.first == key)
					return root;
				if (root->pair.first < key)
					return find_node(root->right, key);
				return find_node(root->left, key);
			}

		public:
			/*********************
            ** Member functions **
            ***********************/

            /****Construct list****/
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				init_map(comp, alloc);
				_root = _root->create_node(value_type());
				_end = _end->create_node(value_type());
				_root->right = _end;
				_end->parent = _root;
			}

  			map (iterator first, iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				init_map(comp, alloc);
				_root = _root->create_node(value_type());
				_end = _end->create_node(value_type());
				_root->right = _end;
				_end->parent = _root;
				insert(first, last);
			}

			map (const map& x) {*this = x;}

			~map() {clear();}

			map& operator=(const map& x)
			{
				clear();
				_root = _root->create_node(value_type());
				_end = _end->create_node(value_type());
				_size = 0;
				_root->right = _end;
				_end->parent = _root;
				this->insert(x.begin(), x.end());
				return *this;
			}

			/****Iterators****/
			
			iterator begin()
			{
				map_node_ptr to_return = _root;
				if (!_root->right && !_root->left)
					return _root;
				else if (!_root->left && _root->right)
					to_return = _root->right;
				while (to_return && to_return->left)
					to_return = to_return->left;
				return iterator(to_return);
			}
			
			const_iterator begin() const
			{
				map_node_ptr to_return = _root;
				if (!_root->right && !_root->left)
					return _root;
				else if (!_root->left && _root->right)
					to_return = _root->right;
				while (to_return && to_return->left)
					to_return = to_return->left;
				return const_iterator(to_return);
			}

			iterator end() {return iterator(_end);}

			const_iterator end() const {return const_iterator(_end);}

			reverse_iterator rbegin()
			{
				map_node_ptr to_return = _root;
				if (_root->left && !_root->right)
					to_return = _root->left;
				while (to_return->right)
					to_return = to_return->right;
				return reverse_iterator(to_return);
			}

			const_reverse_iterator rbegin() const
			{
				map_node_ptr to_return = _root;
				if (_root->left && !_root->right)
					to_return = _root->left;
				while (to_return->right)
					to_return = to_return->right;
				return reverse_iterator(to_return);
			}

			reverse_iterator rend() {return reverse_iterator(_root);}
			const_reverse_iterator rend() const {return const_reverse_iterator(_root);}

			/****Capacity****/
            bool empty() const
            {
                if (_size == 0)
                    return true;
                return false;
            }

            size_type 				size()      const       {return _size;}
			
			// https://stackoverflow.com/questions/27508872/why-does-stdlist-have-a-max-size
            size_type 				max_size()  const       {
				if (typeid(mapped_type) == typeid(std::string))
					return (std::numeric_limits<difference_type>::max() / sizeof(std::pair<key_type, mapped_type>));
				return (std::numeric_limits<size_type>::max() / (sizeof(Map_node<key_type, mapped_type>) + sizeof(std::pair<key_type, mapped_type>)));
			}
    
			/****Element-access****/
			mapped_type& operator[](const key_type& k)
			{
				map_node_ptr to_return;
				to_return = find_node(_root, k);
				if (to_return)
					return to_return->pair.second;
				std::pair<key_type, mapped_type> tmp = std::make_pair(k, mapped_type());
				this->insert(tmp);
				return (*((this->insert(std::make_pair(k,mapped_type()))).first)).second;
			}

            /****Modifiers****/
			std::pair<iterator, bool> insert(const value_type& val)
			{
				map_node_ptr to_return = NULL;
				to_return = find_node(_root, val.first);
				if (to_return != NULL)
					return(std::make_pair(iterator(to_return), false));
				_size++;
				to_return = _root->insert_node(_root, val, _end);
				return(std::make_pair(iterator(to_return), true));
			}

			iterator insert(iterator position, const value_type& val)
			{
				map_node_ptr to_return = NULL;
				to_return = find_node(_root, val.first);
				if (to_return != NULL)
					return(iterator(to_return));
				_size++;
				to_return = _root->insert_node(_root, val, _end);
				if (to_return == position.node())
					return (iterator(to_return));
				return(iterator(to_return));
			}

  			void insert (iterator first, iterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void insert (const_iterator first, const_iterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void erase (iterator position)
			{
				map_node_ptr to_delete;
				
				to_delete = position.node();
				if (to_delete != NULL)
					_root->delete_node_2(to_delete->pair.first, _root, _end);
				_size--;
			}

			size_type erase (const key_type& k)
			{
				erase(this->find(k));
				return _size;
			}

			void erase (iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			void swap (map &x)
			{
				ft::map<key_type, mapped_type> tmp;
				tmp = x;
                x = *this;
				*this = tmp;
			}

			void clear()
			{
				if (_root != NULL)
					erase(this->begin(), this->end());
			}

            /****Observers****/

			key_compare key_comp() const
			{
				return _compare();
			}

			value_compare value_comp() const
			{
				return value_compare(_compare());
			}

            /****Operations****/
			
			//Find - if not found -> return mapp::end();
			iterator find (const key_type& k)
			{
				map_node_ptr to_find = NULL;
				to_find = find_node(this->_root, k);
				if (to_find == NULL)
					return (end());
				return (iterator(to_find));
			}

			const_iterator find (const key_type& k) const
			{
				map_node_ptr to_find = NULL;
				to_find = find_node(this->_root, k);
				if (to_find == NULL)
					return (end());
				return (const_iterator(to_find));
			}

			size_type count (const key_type& k) const
			{
				map_node_ptr to_return = NULL;
				to_return = find_node(_root, k);
				if (to_return != NULL)
					return(1);
				return 0;
			}

			//Returns an iterator to the first element whose key is not considered to go before k
			iterator lower_bound (const key_type& k)
			{
				iterator it = begin();
				iterator it_e = end();

				for (; it != it_e; it++)
					if (_compare(it->first, k) <= 0)
						return (it);
				return(it_e);
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = begin();
				const_iterator it_e = end();

				for (; it != it_e; it++)
					if (_compare(it->first, k) <= 0)
						return (it);
				return(it_e);
			}

			iterator upper_bound (const key_type& k)
			{
				iterator it = begin();
				iterator it_e = end();
				for (; it != it_e; it++)
					if (it->first != k && _compare(it->first, k) <= 0)
						return (it);
				return(it_e);
			}

			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it = begin();
				const_iterator it_e = end();
				for (; it != it_e; it++)
					if (it->first != k && _compare(it->first, k) <= 0)
						return (it);
				return(it_e);
			}
			//Returns the bounds of a range that includes all the elements which have a key equivalent to k.
			std::pair<iterator,iterator>	equal_range (const key_type& k)
			{
				iterator start = lower_bound(k);
				iterator end = upper_bound(k);

				return std::pair<iterator, iterator>(start, end);
			}

			std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				const_iterator start = lower_bound(k);
				const_iterator end = upper_bound(k);

				return std::pair<const_iterator, const_iterator>(start, end);
			}
	};
}

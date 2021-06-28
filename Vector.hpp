#pragma once

#include <exception>
#include "Iterators/Random.hpp"
#include <iostream>

namespace ft
{
    template<class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                                                                       value_type;
            typedef Allocator                                                                               allocator_type;
            typedef T&                                                                                      reference;
            typedef const T&                                                                                const_reference;
            typedef T*                                                                                      pointer;
            typedef const T*                                                                                const_pointer;
            typedef std::size_t                                                                             size_type;
            typedef std::ptrdiff_t                                                                          difference_type;
			typedef Random_iterator<value_type, difference_type, pointer, reference>                 		iterator;
            typedef Random_iterator<value_type, difference_type, const_pointer, const_reference>     		const_iterator;
            typedef ReRandom_iterator<value_type, difference_type, pointer, reference>               		reverse_iterator;
            typedef ReRandom_iterator<value_type, difference_type, const_pointer, const_reference>   		const_reverse_iterator;

		private:
			pointer				_ptr;
			size_type			_size;
			allocator_type		_alloc;
			size_type			_capacity;

			void init_vector(const allocator_type& alloc, size_type size, size_type capacity)
			{
				_size = size;
				_capacity = capacity;
				_alloc = alloc;
				_ptr = nullptr;
			}

		public:

			/*********************
			** Member functions **
			***********************/

			/****Construct vector****/
			explicit vector(const allocator_type& alloc = allocator_type())
			{
				init_vector(alloc, 0, 0);
				if (_capacity > 0)
					_ptr = new value_type[_capacity];
			}

			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
			{
				init_vector(alloc, n, n);
				if (_capacity > 0)
					_ptr = new value_type[_capacity];
				assign(n, val);
			}

			vector (iterator first, iterator last,
                 const allocator_type& alloc = allocator_type())
			{
				size_type i = 0;
				iterator f_copy = first;
				iterator l_copy = last;
				while (first != last)
				{
					first++;
					i++;
				}
				init_vector(alloc, i, i);
				if (_capacity > 0)
					_ptr = new value_type[_capacity];
				assign(f_copy, l_copy);
			}

			vector (const_iterator first, const_iterator last,
                 const allocator_type& alloc = allocator_type())
			{
				init_vector(alloc, (last - first), (last - first));
				assign(first, last);
			}

			vector (const vector& x)
			{
				init_vector(x._alloc, x._size, x._capacity);
				*this = x;
			}

			/****Vector destructor****/
			~vector()
			{
				if (_ptr)
				{
					delete [] _ptr;
					_ptr = nullptr;
				}
			}

			/****Assign content****/
			vector& operator= (const vector& x)
			{
				if (_ptr)
				{
					delete[] _ptr;
					_ptr = nullptr;
				}
				init_vector(x._alloc, x._size, x._capacity);
				if (_capacity > 0)
					_ptr = new value_type[x._capacity];
				assign(x.begin(), x.end());
				return *this;
			}

			/****Iterators****/
			iterator 						begin() 			{return iterator(_ptr);}
			const_iterator 					begin() 	const 	{return const_iterator(_ptr);}
			iterator 						end() 				{return (_ptr + _size);}
			const_iterator 					end() 		const	{return const_iterator(_ptr + _size);}
			reverse_iterator 				rbegin() 			{return reverse_iterator(_ptr + _size - 1);}
			const_reverse_iterator 			rbegin() 	const 	{return const_reverse_iterator(_ptr + _size - 1);}
			reverse_iterator 				rend() 				{return reverse_iterator(_ptr - 1);}
			const_reverse_iterator 			rend() 		const 	{return const_reverse_iterator(_ptr - 1);}

			/****Capacity****/
			// Returns the number of elements in the vector -> not necessarily equal to its storage capacity
			size_type 						size() 		const 	{return _size;}
			// https://stackoverflow.com/questions/27508872/why-does-stdlist-have-a-max-size
            //Incorrect size for char 
			size_type 						max_size() 	const	
			{
				if (typeid(value_type) == typeid('c'))
					return std::numeric_limits<difference_type>::max() / sizeof(value_type);
				return std::numeric_limits<size_type>::max() / sizeof(value_type);
			}

			// Resizes the container so that it contains n elements
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
                {
                    while (n < _size)
                        pop_back();
                }
                else if (n > _size && _capacity >= n)
                {
                    while (n > _size)
                        push_back(val);
                }
				else if (n > _size && _capacity < n)
				{
					if (_capacity * 2 < n)
						reserve(n);
					else
						reserve(_size * 2);
					while (n > _size)
                        push_back(val);
				}
			}

			// Returns the size of the storage space currently allocated for the vector
			size_type capacity() const {return _capacity;}

			// Returns whether the vector is empty
			bool empty() const
            {
                if (_size == 0)
                    return true;
                return false;
            }

			// Requests that the vector capacity be at least enough to contain n elements
			void reserve (size_type n) // n should be (twice _size)
			{
				if (n > _capacity)
				{
					pointer tmp = new value_type[n];
					for (size_type i = 0; i < _size; i++)
						tmp[i] = _ptr[i];
					if (_ptr)
					{
						delete [] _ptr;
						_ptr = nullptr;
					}
					_ptr = tmp;
					_capacity = n;
				}
			}

			/****Element access****/

			reference 			operator[] (size_type n) 		{return _ptr[n];}
			const_reference 	operator[] (size_type n) const 	{return _ptr[n];}
			reference 	at (size_type n)
			{
				if (n < 0 || n >= _size)
					throw std::exception();
				return _ptr[n];
			}
			const_reference at (size_type n) const
			{
				if (n < 0 || n >= _size)
					throw std::exception();
				return _ptr[n];
			}
			reference 			front() 		{return _ptr[0];}
			const_reference 	front() const 	{return _ptr[0];}
			reference 			back() 			{return _ptr[_size - 1];}
			const_reference 	back() 	const 	{return _ptr[_size - 1];}

			/****Modifiers****/

			// he new contents are elements constructed from each of the elements in the range between first and last
			void assign (iterator first, iterator last)
			{
				clear();
				while (first != last)
					push_back(*first++);
			}

			void assign (const_iterator first, const_iterator last)
			{
				clear();
				while (first != last)
					push_back(*first++);
			}

			// The new contents are n elements, each initialized to a copy of val
			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			// Adds a new element at the end of the vector, after its current last element
			void push_back (const value_type& val)
			{
				if (_size == 0)
					reserve(2);
				else if (_capacity == _size)
					reserve(_size * 2);
				_ptr[_size] = val;
				_size++;
			}

			// Removes the last element in the vector, effectively reducing the container size by one
			void pop_back()
			{
				if (_size > 0)
					_size--;
			}

			// The vector is extended by inserting new elements before the element at the specified position,
			// effectively increasing the container size by the number of elements inserted
			iterator insert (iterator position, const value_type& val)
			{
				insert(position, 1, val);
				return &_ptr[(position - begin())];
			}
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				vector<value_type, Allocator> tmp(position, end());
				if (_capacity < _size + n && (_capacity * 2) >= _size + n)
					tmp.reserve(_size * 2);
				else if (_capacity <= _size + n && (_capacity * 2) < _size + n)
					tmp.reserve(_size+n);
				_size -= (end() - position);
				while (n-- > 0)
					push_back(val);
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
			}

			void insert (iterator position, iterator first, iterator last)
			{
				vector<value_type, Allocator> tmp(position, end());
				size_type n = last - first;
				if (_capacity < _size + n && (_capacity * 2) >= _size + n)
					tmp.reserve(_size * 2);
				else if (_capacity <= _size + n && (_capacity * 2) < _size + n)
					tmp.reserve(_size+n);
				_size -= (end() - position);
				while (first != last)
					push_back(*first++);
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
			}

			//capcaity is still not reliable

			void insert (iterator position, const_iterator first, const_iterator last)
			{
				vector<value_type, Allocator> tmp(position, end());
				size_type n = last - first;
				if (_capacity < _size + n && (_capacity * 2) >= _size + n)
					tmp.reserve(_size * 2);
				else if (_capacity <= _size + n && (_capacity * 2) < _size + n)
					tmp.reserve(_size+n);
				_size -= (end() - position);
				while (first != last)
					push_back(*first++);
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
			}

			// Removes from the vector either a single element (position) or a range of elements ([first,last))
			iterator erase (iterator position)
			{
				iterator f = begin();
				pointer tmp = new value_type[_size - 1];
				size_type i = 0;
				size_type j = 0;
				while (f != end())
				{
					if (f != position)
						tmp[i++] = _ptr[j];
					j++;
					f++;
				}
				if (_ptr)
					delete [] _ptr;
				_ptr = tmp;
				_size--;
				return position;
			}

			iterator erase (iterator first, iterator last)
			{
				iterator f = begin();
				iterator f_copy = first;
				iterator l_copy = last;
				size_type n = 0;
				while (f_copy++ != l_copy)
					n++;
				pointer tmp = new value_type[_size - n];
				size_type i = 0;
				size_type j = 0;
				while (f != end())
				{
					if (f == first)
					{
						while (f != last)
						{
							j++;
							f++;
						}
					}
					else
					{
						tmp[i++] = _ptr[j++];
						f++;
					}
				}
				if (_ptr)
					delete [] _ptr;
				_ptr = tmp;
				_size -= n;
				return first;
			}

			// Exchanges the content of the container by the content of x
			void swap (vector& x)
			{
				ft::vector<value_type> tmp(*this);
				*this = x;
				x = tmp;
			}

			// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0
			void clear()
			{
				while (_size)
					pop_back();
			}
	};

	/***********************************
    ** Non-member function overloads **
    ************************************/

	template <class T, class Allocator>
  	bool operator== (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		typename ft::vector<T, Allocator>::const_iterator f1 = lhs.begin();
		typename ft::vector<T, Allocator>::const_iterator f2 = rhs.begin();
		if (lhs.size() == rhs.size())
		{
			while (f1 != lhs.end())
			{
				if (!(*f1 == *f2))
					return false;
				f1++;
				f2++;
			}
			return true;
		}
		return false;
	}

	template <class T, class Allocator>
  	bool operator!= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) { return !(&lhs == &rhs);}

	template <class T, class Allocator>
  	bool operator<  (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
	{
		typename ft::vector<T, Allocator>::const_iterator f1 = lhs.begin();
		typename ft::vector<T, Allocator>::const_iterator f2 = rhs.begin();
		while (f1 != lhs.end())
        {
            if (f2 == rhs.end() || *f2 < *f1)
                return true;
            else if (*f1 < *f2)
                return true;
            f1++;
            f2++;
        }
        return (f2 != rhs.end());
	}
	template <class T, class Allocator>
  	bool operator<= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {return !(lhs > rhs);}
	
	template <class T, class Allocator>
  	bool operator>  (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {return !(lhs < rhs);}

	template <class T, class Allocator>
  	bool operator>= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {return !(lhs <= rhs);}

	template <class T, class Allocator>
  	void swap (vector<T,Allocator>& x, vector<T,Allocator>& y){x.swap(y);}

}

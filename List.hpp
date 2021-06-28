#pragma once

#include "Iterators/Bidirectional.hpp"
#include "Iterators/Node.hpp"

namespace ft
{
    template< typename T, class Allocator = std::allocator<T> > 
    class list
    {
       
        public:
            typedef T                                                                                       value_type;
            typedef Allocator                                                                               allocator_type;
            typedef std::size_t                                                                             size_type;
            typedef std::ptrdiff_t                                                                          difference_type;
            typedef T&                                                                                      reference;
            typedef const T&                                                                                const_reference;
            typedef T*                                                                                      pointer;
            typedef const T*                                                                                const_pointer;
            typedef Node<T>*                                                                                node_ptr;
            typedef BiDirectional_iterator<value_type, difference_type, pointer, reference>                 iterator;
            typedef BiDirectional_iterator<value_type, difference_type, const_pointer, const_reference>     const_iterator;
            typedef ReBiDirectional_iterator<value_type, difference_type, pointer, reference>               reverse_iterator;
            typedef ReBiDirectional_iterator<value_type, difference_type, const_pointer, const_reference>   const_reverse_iterator;

        private:

            node_ptr            _head;
            node_ptr            _tail;
            allocator_type      _alloc;
            size_type           _size;

            void init_list(const allocator_type& alloc){
                _head = new Node<value_type>();
                _tail = new Node<value_type>();
                _head->next = _tail;
                _tail->previous = _head;
                _size = 0;
                _alloc = alloc;
            };

            void swap_help(value_type& a, value_type& b)
            {
                value_type tmp = a;
                a = b;
                b = tmp;
            };
            
        public:

            /*********************
            ** Member functions **
            ***********************/

            /****Construct list****/
            explicit list(const allocator_type& alloc = allocator_type())
            {
                init_list(alloc);
            }

            explicit list(size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type())
            {
                init_list(alloc);
                assign(n, val);
            }

            list(const list& other)
            {
                init_list(other._alloc);
                assign(other.begin(), other.end());
            }

            explicit list (iterator first, iterator last,
                    const allocator_type& alloc = allocator_type())
            {
                init_list(alloc);
                assign(first, last);
            }

            explicit list (const_iterator first, const_iterator last,
                    const allocator_type& alloc = allocator_type())
            {
                init_list(alloc);
                assign(first, last);
            }

            /****List destructor****/
            ~list()
            {
                clear();
                delete _head;
                delete _tail;
            }

            /****Assign content****/
            list& operator= (const list& x)
            {
                clear();
                _head->next = _tail;
                _tail->previous = _head;
                _size = 0;
                this->assign(x.begin(), x.end());
                return *this;
            }

            /****Iterators****/
            iterator 				begin()                 {return iterator(_head->next);}
            const_iterator 			begin()     const       {return const_iterator(_head->next);}
            iterator 				end()                   {return iterator(_tail);}
            const_iterator 			end()       const       {return const_iterator(_tail);}
            reverse_iterator 		rbegin()                {return reverse_iterator(_tail->previous);}
            const_reverse_iterator 	rbegin()    const       {return const_reverse_iterator(_tail->previous);}
            reverse_iterator 		rend()                  {return reverse_iterator(_head);}
            const_reverse_iterator 	rend()      const       {return const_reverse_iterator(_head);}

            /****Capacity****/
            bool empty() const
            {
                if (_size == 0)
                    return true;
                return false;
            }

            size_type 				size()      const       {return _size;}

            // https://stackoverflow.com/questions/27508872/why-does-stdlist-have-a-max-size
            size_type 				max_size()  const       {return std::numeric_limits<size_type>::max() / sizeof(Node<value_type>);}

            /****Element****/
            reference 				front()                 {return _head->next->data;}
            const_reference 		front()     const       {return _head->next->data;}
            reference 				back()                  {return _tail->previous->data;}
            const_reference 		back()      const       {return _tail->previous->data;}

            /****Modifiers****/

            // The new contents are n elements, each initialized to a copy of val.
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

            void assign (size_type n, const value_type& val)
            {
                clear();
                while (n--)
                    push_front(val);
            }

			// Prepends the given element value to the beginning of the container.
            void push_front(const value_type& val)
            {
                node_ptr tmp = new Node<value_type>(val);
                node_ptr to_next = _head->next;
                tmp->next = to_next;
                tmp->previous = _head;
                to_next->previous = tmp;
                _head->next = tmp;
                _size++;
            }

            // Removes the first element in the list container, effectively reducing its size by one.
            void pop_front()
            {
                if (_size > 0)
                {
                    node_ptr tmp = _head->next->next;
                    delete _head->next;
                    tmp->previous = _head;
                    _head->next = tmp;
                    _size--;
                }
            }

            // Inserts a new element at the beginning of the list, right before its current first element.
            void push_back(const value_type& val)
            {
                node_ptr tmp = new Node<value_type>(val);
                node_ptr to_prev = _tail->previous;
                tmp->previous = to_prev;
                tmp->next = _tail;
                to_prev->next = tmp;
                _tail->previous = tmp;
                _size++;
            }

            // Removes the last element of the container.
            void pop_back()
            {
                if (_size > 0)
                {
                    node_ptr tmp = _tail->previous->previous;
                    delete _tail->previous;
                    tmp->next = _tail;
                    _tail->previous = tmp;
                    _size--;
                }
            }
            
            // The container is extended by inserting new elements before the element at the specified position.
            iterator insert (iterator position, const value_type& val)
            {
                for (iterator it = begin(); it != end(); ++it)
                {
                    if (it == position)
                    {
                        node_ptr tmp = new Node<value_type>(val);
                        node_ptr t = it.m_ptr; 
                        tmp->previous = t->previous;
                        t->previous->next = tmp;
                        tmp->next = t;
                        t->previous = tmp;
                        _size++;
                    }
                }
                return position;
            }

            void insert (iterator position, size_type n, const value_type& val)
            {
                while (n-- > 0)
                    insert(position, val);
            }

            void insert (iterator position, iterator first, iterator last)
            {
                while (first != last)
                {
                    insert(position, *first);
                    first++;
                }
            }

            void insert (iterator position, const_iterator first, const_iterator last)
            {
                while (first != last)
                {
                    insert(position, *first);
                    first++;
                }
            }

            // Removes from the list container either a single element (position)
            iterator erase (iterator position)
            {
                if (position != end())
                {
					node_ptr tmp = position.m_ptr;
					tmp->previous->next = tmp->next;
					tmp->next->previous = tmp->previous;
					delete tmp;
                    _size--;
                }
                return position;
            }

            // or a range of elements ([first,last])
            iterator erase (iterator first, iterator last)
            {
                while (first++ != last)
                    erase(first);
                return first;
            } 

            // Exchanges the content of the container by the content of x, which is another list of the same type
            void swap (list& x)
            {
                ft::list<value_type> tmp(*this);
				*this = x;
                x = tmp;
            }

            // Resizes the container so that it contains n elements
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _size)
                {
                    while (n < _size)
                        pop_back();
                }
                else if (n > _size)
                {
                    while (n > _size)
                        push_back(val);
                }
            }

            // Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0
            void clear()
            {
                while(_size)
                    pop_back();
            }

            /****Operations****/

            // Transfers all the elements of x into the container
            void splice (iterator position, list& x)
            {
                if (this != &x)
                {
                    iterator f = x.begin();
                    iterator l = x.end();
                    insert(position, f, l);
					x.clear();
                }
            }

            // Transfers only the element pointed by i from x into the container
            void splice (iterator position, list& x, iterator i)
            {
                if (this != &x)
                    insert(position, *i);
				x.clear();
            }

            // Transfers the range [first,last) from x into the container
            void splice (iterator position, list& x, iterator first, iterator last)
            {
                if (this != &x)
                    insert(position, first, last);
				x.clear();
            }

            // Removes from the container all the elements that compare equal to val
            void remove (const value_type& val)
            {
                for (iterator it = begin(); it != end(); ++it)
                {
                    if (*it == val)
                        erase(it);
                }
            }
            
            // Removes from the container all the elements for which Predicate pred returns true
            template <class Predicate>
            void remove_if (Predicate pred)
            {
                for (iterator it = begin(); it != end(); ++it)
                {
                    if (pred(*it))
                        erase(it);
                }
            }

            // Removes all but the first element from every consecutive group of equal elements in the container
            void unique()
            {
                iterator comp = begin();
                iterator it = begin();
                for (iterator ite = ++it; ite != end(); ite++)
                {
                    if(*ite == *comp)
                        erase(ite);
                    else
                        comp++;
                }
            }

            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred)
            {
                sort(binary_pred);
                for (iterator it = begin(); it != end(); ++it)
                {
                    if(binary_pred(*it, *it->previous->data))
                        it = erase(it);
                }
            }

            template <class Compare>
            void merge (list& x, Compare comp)
            {
                iterator f1 = begin();
                iterator f2 = x.begin();
                // iterator l1 = end();
                iterator l2 = x.end();

                while (f2 != l2)
                {
                    insert(f1, *f2);
                    f2++;
                }
                sort(comp);
                x.clear();
            }

            //Merges x into the list by transferring all of its elements at their respective ordered positions into the container (both containers shall already be ordered)
            template <class Compare>
            void merge (list& x)
            {
                merge(x, Compare());
            }

            template <class Compare>
            void sort (Compare comp)
            {
                iterator beg = begin();
                iterator f = begin();
                while (++f != end())
                {
                    if (comp(*f, *beg))
                    {
                        swap_help(*f, *beg);
                        f = begin();
                        beg = begin();
                    }
                    else
                        beg++;
                }
            }

            void sort()
            {
                iterator beg = begin();
                iterator f = begin();
                while (++f != end())
                {
                    if (*f < *beg)
                    {
                        swap_help(*f, *beg);
                        f = begin();
                        beg = begin();
                    }
                    else
                        beg++;
                }
            }

            // Reverses the order of the elements in the list container
            void reverse()
            {
                iterator it = begin();
                iterator e = end();
                iterator ite = --e;
                size_type n = 0;
                while (n++ < size()/2)
                {
                    swap_help(*it, *ite);
                    it++;
                    ite--;
                }
            }
    	};

    /***********************************
    ** Non-member function overloads **
    ************************************/

    //The equality comparison (operator==) is performed by first comparing sizes, and if they match,
    //the elements are compared sequentially using operator==, stopping at the first mismatch.
    
    template<typename T, typename Allocator>
    bool operator== (const list<T,Allocator>& lhs, const list<T,Allocator>& rhs)
    {
        typename ft::list<T, Allocator>::const_iterator f1 = lhs.begin();
        typename ft::list<T, Allocator>::const_iterator f2 = rhs.begin();
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

    template<typename T, typename Allocator>
    bool operator!= (const list<T,Allocator>& lhs, const list<T,Allocator>& rhs){ return !(&lhs == &rhs);}
    
    template< class T, class Allocator>
    bool operator< (const list<T,Allocator>& lhs, const list<T,Allocator>& rhs)
    {
        typename ft::list<T, Allocator>::const_iterator f1 = lhs.begin();
        typename ft::list<T, Allocator>::const_iterator f2 = rhs.begin();
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
    
    template< class T, class Allocator>
    bool operator>  (const list<T,Allocator>& lhs, const list<T,Allocator>& rhs){return (rhs < lhs);}
    
    template< class T, class Allocator>
    bool operator<= (const list<T,Allocator>& lhs, const list<T,Allocator>& rhs){return !(lhs > rhs);}
    
    template< class T, class Allocator>
    bool operator>= (const list<T,Allocator>& lhs, const list<T,Allocator>& rhs){return !(lhs < rhs);}
}

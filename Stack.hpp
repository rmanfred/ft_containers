#pragma once

#include <iostream>
#include "List.hpp"

namespace ft
{
    template< typename T, class Container = list<T> >
    class stack
    {
        public:
            typedef T                       value_type;
            typedef list<value_type>        container_type;
            typedef std::size_t             size_type;
            container_type                  container;
        
        /*********************
        ** Member functions **
        ***********************/

        /****Construct stack****/
        // This container object is a copy of the ctnr argument
        explicit stack (const container_type& ctnr = container_type())  {container = ctnr;};

        bool empty() const                                              {return container.empty();}
        size_type size() const                                          {return container.size();}
        value_type& top()                                               {return container.back();}
        const value_type& top() const                                   {return container.back();}
        void push (const value_type& val)                               {container.push_back(val);}
        void pop()                                                      {container.pop_back();}
    };

    /***********************************
    ** Non-member function overloads **
    ************************************/

    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)  {return lhs.container == rhs.container;}
    
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)  {return !(lhs.container == rhs.container);}
    
    template <class T, class Container>
    bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)  {return lhs.container < rhs.container;}
    
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)  {return lhs.container <= rhs.container;}
    
    template <class T, class Container>
    bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)  {return lhs.container > rhs.container;}
    
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)  {return lhs.container >= rhs.container;}
}

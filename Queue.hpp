#pragma once

#include "List.hpp"

namespace ft
{
    template< typename T, class Container = list<T> >
    class queue
    {
        public:
            typedef T                       value_type;
            typedef list<value_type>        container_type;
            typedef std::size_t             size_type;
            container_type                  container;
        
        /*********************
        ** Member functions **
        ***********************/

        /****Construct queue****/
        // This container object is a copy of the ctnr argument
        explicit queue (const container_type& ctnr = container_type())  {container = ctnr;};

        bool empty() const                                              {return container.empty();}
        size_type size() const                                          {return container.size();}
        value_type& front()                                             {return container.front();}
        const value_type& front() const                                 {return container.front();}
        value_type& back()                                              {return container.back();}
        const value_type& back() const                                  {return container.back();}
        void push (const value_type& val)                               {container.push_back(val);}
        void pop()                                                      {container.pop_front();}
    };

    /***********************************
    ** Non-member function overloads **
    ************************************/

    template <class T, class Container>
    bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)  {return lhs.container == rhs.container;}
    
    template <class T, class Container>
    bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)  {return !(lhs.container == rhs.container);}
    
    template <class T, class Container>
    bool operator< (const queue<T,Container>& lhs, const queue<T,Container>& rhs)  {return lhs.container < rhs.container;}
    
    template <class T, class Container>
    bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)  {return lhs.container <= rhs.container;}
    
    template <class T, class Container>
    bool operator> (const queue<T,Container>& lhs, const queue<T,Container>& rhs)  {return lhs.container > rhs.container;}
    
    template <class T, class Container>
    bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)  {return lhs.container >= rhs.container;}
}

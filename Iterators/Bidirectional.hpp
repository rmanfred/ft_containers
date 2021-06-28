#pragma once

#include "Node.hpp"

template<typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
class BiDirectional_iterator
{
public:
    typedef Distance                                                    difference_type;
    typedef Pointer                                                     pointer;
    typedef Reference                                                   reference;
    typedef BiDirectional_iterator<T, std::ptrdiff_t, T*, T&>           iter;
    typedef Node<T>*                                                    node_ptr;
    node_ptr                                                            m_ptr;

    BiDirectional_iterator() : m_ptr(nullptr) {}
    BiDirectional_iterator(node_ptr const ptr) : m_ptr(ptr){}
    ~BiDirectional_iterator(){}
    BiDirectional_iterator(iter const &other)
    { 
        *this = other;
    }
    BiDirectional_iterator &operator=(iter const &other)
    {
        m_ptr = other.m_ptr;
        return *this;
    }
    bool operator==(BiDirectional_iterator const &other)
    {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(BiDirectional_iterator const &other)
    {
        return m_ptr != other.m_ptr;
    }
    reference operator*() const
    {
        return m_ptr->data;
    }
    pointer operator->() const
    {
        return &m_ptr->data;
    }
    // Префиксная форма
    BiDirectional_iterator &operator++()
    {
        m_ptr = m_ptr->next;
        return *this;
    }
    // Постфиксная форма
    BiDirectional_iterator operator++(int)
    {
        BiDirectional_iterator tmp = *this;
        m_ptr = m_ptr->next;
        return tmp;
    }
    BiDirectional_iterator &operator--()
    {
        m_ptr = m_ptr->previous;
        return *this;
    }
    BiDirectional_iterator operator--(int)
    {
        BiDirectional_iterator tmp = *this;
        m_ptr = m_ptr->previous;
        return tmp;
    }
};

template<typename T, typename Distance = std::ptrdiff_t, typename Pointer =  T*, typename Reference = T&>
class ReBiDirectional_iterator
{
public:
    typedef Distance                                                    difference_type;
    typedef Pointer                                                     pointer;
    typedef Reference                                                   reference;
    typedef ReBiDirectional_iterator<T, std::ptrdiff_t, T*, T&>         iter;
    typedef Node<T>*                                                    node_ptr;
    node_ptr                                                            m_ptr;

    ReBiDirectional_iterator() : m_ptr(nullptr) {}
    ReBiDirectional_iterator(node_ptr const ptr) : m_ptr(ptr){}
    ~ReBiDirectional_iterator(){}
    ReBiDirectional_iterator(iter const &other)
    {
        *this = other;
    }
    ReBiDirectional_iterator &operator=(iter const &other)
    {
        m_ptr = other.m_ptr;
        return *this;
    }
    bool operator==(ReBiDirectional_iterator const &other)
    {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(ReBiDirectional_iterator const &other)
    {
        return m_ptr != other.m_ptr;
    }
    reference operator*() const
    {
        return m_ptr->data;
    }
    pointer operator->() const
    {
        return &m_ptr->data;
    }
    ReBiDirectional_iterator &operator--()
    {
        m_ptr = m_ptr->next;
        return *this;
    }
    ReBiDirectional_iterator operator--(int)
    {
        ReBiDirectional_iterator tmp = *this;
        m_ptr = m_ptr->next;
        return tmp;
    }
    ReBiDirectional_iterator &operator++()
    {
        m_ptr = m_ptr->previous;
        return *this;
    }
    ReBiDirectional_iterator operator++(int)
    {
        ReBiDirectional_iterator tmp = *this;
        m_ptr = m_ptr->previous;
        return tmp;
    }
};

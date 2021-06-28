#pragma once

#include <iostream>

template<typename T>
class Node
{
public:
    typedef Node*           node_ptr;
    typedef T               value;
    node_ptr                previous;
    node_ptr                next;
    value                   data;

    Node();
    Node(const T &data);
    Node(Node const &other);
    Node &operator=(Node const &rhs);
    ~Node();
};

template<typename T>
Node<T>::Node()
{
    previous = NULL;
    next = NULL;
}

template<typename T>
Node<T>::Node(T const &data)
{
    previous = NULL;
    next = NULL;
    this->data = data;
}

template<typename T>
Node<T>::Node(Node<T> const &other)
{
    this->previous = other.previous;
    this->next = other.next;
    this->data = other.data;
}

template<typename T>
Node<T> & Node<T>::operator=(Node<T> const &rhs)
{
    if (this != &rhs)
    {
        previous = rhs.previous;
        next = rhs.next;
        data = rhs.data;
    }
    return *this;
}

template<typename T>
Node<T>::~Node(){}


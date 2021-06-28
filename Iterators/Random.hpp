#pragma once

template<typename T, typename Distance = std::ptrdiff_t, typename Pointer =  T*, typename Reference = T&>
class Random_iterator
{
public:
    typedef Distance                                                    difference_type;
    typedef Pointer                                                     pointer;
    typedef Reference                                                   reference;
    typedef size_t                                                      size_type;
    typedef Random_iterator<T, std::ptrdiff_t, T*, T&>                  iter;
    pointer                                                             m_ptr;

    Random_iterator() : m_ptr(nullptr) {}
    Random_iterator(pointer const ptr) : m_ptr(ptr){}
    ~Random_iterator(){}
    Random_iterator(iter const &other) 
    { 
        *this = other;
    }
    Random_iterator &operator=(iter const &other)
    {
        m_ptr = other.m_ptr;
        return *this;
    }
    bool operator==(Random_iterator const &other)
    {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(Random_iterator const &other)
    {
        return !(*this == other);
    }
    reference operator*() const
    {
        return *m_ptr;
    }
    pointer operator->() const
    {
        return m_ptr;
    }
    Random_iterator &operator++()
    {
        m_ptr++;
        return *this;
    }
    Random_iterator operator++(int)
    {
        Random_iterator tmp = *this;
        ++(*this).m_ptr;
        return tmp;
    }
    Random_iterator &operator--()
    {
        m_ptr--;
        return *this;
    }
    Random_iterator operator--(int)
    {
        Random_iterator tmp = *this;
        --(*this).m_ptr;
        return tmp;
    }
    Random_iterator &operator+=(size_type off)
    {
        m_ptr += off;
        return *this;
    }
    Random_iterator &operator-=(size_type off)
    {
        return *this += -off;
    }
    Random_iterator operator+(size_type off) const
    {
        Random_iterator tmp = *this;
        return tmp += off;
    }
    Random_iterator operator-(size_type off) const
    {
        Random_iterator tmp = *this;
        return tmp -= off;
    }
    size_type operator-(Random_iterator off) const
    {
        return (m_ptr - off.m_ptr);
    }
    reference operator[](size_type off) const
    {
        return *(m_ptr + off);
    }

    // Using difference type explaination:
    // Programs that use other types, such as int, may fail on, e.g. 64-bit systems
    // when the index exceeds INT_MAX or if it relies on 32-bit modular arithmetic

};

template<typename T, typename Distance = std::ptrdiff_t, typename Pointer =  T*, typename Reference = T&>
class ReRandom_iterator
{
public:
    typedef Distance                                                    difference_type;
    typedef Pointer                                                     pointer;
    typedef Reference                                                   reference;
    typedef size_t                                                      size_type;
    typedef ReRandom_iterator<T, std::ptrdiff_t, T*, T&>                iter;
    pointer                                                             m_ptr;

    ReRandom_iterator() : m_ptr(nullptr) {}
    ReRandom_iterator(pointer const ptr) : m_ptr(ptr){}
    ~ReRandom_iterator(){}
    ReRandom_iterator(iter const &other)
    {
        *this = other;
    }
    ReRandom_iterator &operator=(iter const &other)
    {
        m_ptr = other.m_ptr;
        return *this;
    }
    bool operator==(ReRandom_iterator const &other)
    {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(ReRandom_iterator const &other)
    {
        return !(*this == other);
    }
    reference operator*() const
    {
        return *m_ptr;
    }
    pointer operator->() const
    {
        return m_ptr;
    }
    ReRandom_iterator &operator--()
    {
        m_ptr++;
        return *this;
    }
    ReRandom_iterator operator--(int)
    {
        ReRandom_iterator tmp = *this;
        ++(*this).m_ptr;
        return tmp;
    }
    ReRandom_iterator &operator++()
    {
        m_ptr--;
        return *this;
    }
    ReRandom_iterator operator++(int)
    {
        ReRandom_iterator tmp = *this;
        --(*this).m_ptr;
        return tmp;
    }
    ReRandom_iterator &operator+=(size_type off)
    {
        return *this += -off;
    }
    ReRandom_iterator &operator-=(size_type off)
    {
        m_ptr += off;
        return *this;
    }
    ReRandom_iterator operator+(size_type off) const
    {
        ReRandom_iterator tmp = *this;
        return tmp -= off;
    }
    size_type operator-(ReRandom_iterator off) const
    {
        return (m_ptr + off.m_ptr);
    }
    reference operator[](size_type off) const
    {
        return *(m_ptr + off);
    }
};

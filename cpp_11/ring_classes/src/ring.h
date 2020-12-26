#ifndef RING_H
#define RING_H

template<typename T>
class ring
{
private:
    int m_pos;
    int m_size;
    T *m_values;
public:
    class iterator;

public:
    ring(int size) :
        m_pos(0), m_size(size), m_values(nullptr)
    {
        m_values = new T[m_size];
    }

    ~ring()
    {
        delete [] m_values;
    }

    int size()
    {
        return m_size;
    }

    void add(T item)
    {
        m_values[m_pos++] = item;

        if(m_pos == m_size)
        {
            m_pos = 0;
        }
    }

    T &get(int pos)
    {
        return m_values[pos];
    }

    iterator begin()
    {
        return iterator(0, *this);
    }

    iterator end()
    {
        return iterator(m_size, *this);
    }
};

template<typename T>
class ring<T>::iterator
{
private:
    int m_pos;
    ring &m_ring;
public:
    iterator(int pos, ring &a_ring):
        m_pos(pos), m_ring(a_ring)
    {

    }

    bool operator!=(const iterator &other) const
    {
        return m_pos != other.m_pos;
    }

    // prefix operator
    iterator &operator++()
    {
        ++m_pos;

        return *this;
    }

    // postfix operator
    iterator &operator++(int)
    {
        ++m_pos;

        return *this;
    }

    T &operator*()
    {
        return m_ring.get(m_pos);
    }
};

#endif // RING_H
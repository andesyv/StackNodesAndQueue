#ifndef NODEDL_H
#define NODEDL_H

/* A double linked node
 * A node that links to both the
 * next and previous node in the
 * linked chain.
 */

template <class T>
class NodeDL
{
public:
    NodeDL(T data, NodeDL<T> *next = nullptr, NodeDL<T> *last = nullptr)
        : m_data{data}, m_next{next}, m_last{last} {}

    T& getData() { return m_data; }
    NodeDL<T>* next() { return m_next; }
    NodeDL<T>* last() { return m_last; }
private:
    T m_data{};
    NodeDL<T> *m_next{nullptr};
    NodeDL<T> *m_last{nullptr};
};

#endif // NODEDL_H

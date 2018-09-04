#ifndef STACKDL_H
#define STACKDL_H

template <class T>
class StackDL;

#include <initializer_list>
#include <stdexcept>
#include "nodedl.h"

template <class T>
class StackDL {
private:
    NodeDL<T> *m_topPtr{nullptr};
    NodeDL<T> *m_backPtr{nullptr};
    unsigned int m_nodeCount{0};

public:
    StackDL(const std::initializer_list<T> &list);

    void push(T value);
    void pop();
    T& top();
    T& bottom();
    unsigned int size();
    void empty();
};



/// Function definitions
template<class T>
StackDL<T>::StackDL(const std::initializer_list<T> &list)
{
    for (const auto &item : list) {
        push(item);
    }
}

template<class T>
void StackDL<T>::push(T value)
{
    NodeDL<T> *newNode = new NodeDL<T>{value, m_topPtr, nullptr};
    if (m_topPtr != nullptr) {
        m_topPtr->m_last = newNode;
    }
    m_topPtr = newNode;

    // Set pointer to last element if there are no elements in the stack.
    if (m_backPtr == nullptr) {
        m_backPtr = newNode;
    }

    m_nodeCount++;
}

template<class T>
void StackDL<T>::pop()
{
    if (m_topPtr == nullptr)
        return;

    NodeDL<T>* tempPtr{m_topPtr};
    /* Hvis den neste pointeren til top pointeren er 0,
     * jobber vi med det siste leddet og backPtr må derfor
     * bli satt til nullptr. */
    if (m_topPtr->m_next == nullptr) {
        m_backPtr = nullptr;
        m_topPtr = nullptr;
    } else {
        m_topPtr = m_topPtr->m_next; // flytt top til neste i stacken
        m_topPtr->m_last = nullptr; // Fjerner en dangling pointer. Farlig!
    }

    delete tempPtr;
    m_nodeCount--;
}

template<class T>
T& StackDL<T>::top()
{   if (m_topPtr == nullptr) {
        throw std::runtime_error{"Trying to receive top entry in empty stack."};
    }
    return m_topPtr->getData();
}

template<class T>
T& StackDL<T>::bottom()
{
    if (m_backPtr == nullptr) {
            throw std::runtime_error{"Trying to receive bottom entry in empty stack."};
    }
    return m_backPtr->getData();
}

template<class T>
unsigned int StackDL<T>::size()
{
    return m_nodeCount;
}

template<class T>
void StackDL<T>::empty()
{
    while (size() > 0) {
        pop();
    }
}



#endif // STACKDL_H


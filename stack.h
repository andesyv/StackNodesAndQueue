#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <stdexcept>
#include <initializer_list>

template <class T>
class Stack
{
public:
    Stack(const std::initializer_list<T> &list);

    void push(const T &element);
    /* Note:
     * Having pop return the thing it popped off is more expensive and very rarely usefull.
     * For example if the stack is responsible for memory allocation of the elements,
     * it would need to return a copy because the original value would be destroyed when
     * it is popped off the stack. Therefore it would be easier, and more efficient to
     * separate top and pop.
     */
    T pop();
    // void pop();
    T& top();
    unsigned int size() const;
    void empty();


private:
    unsigned int nodeCount{0};
    Node<T> *topPtr{nullptr};
};


// Function definitions
template<class T>
Stack<T>::Stack(const std::initializer_list<T> &list)
{
    for (const auto &item : list) {
        push(item);
    }
}

template<class T>
void Stack<T>::push(const T &element)
{
    topPtr = new Node<T>{element, topPtr};
    nodeCount++;
}

template<class T>
T Stack<T>::pop()
{
    if (topPtr != nullptr) {
        Node<T>* tempPtr = topPtr;
        topPtr = topPtr->getNextPtr(); // flytt top til neste i stacken
        T returnValue{tempPtr->getData()};
        delete tempPtr;
        nodeCount--;
        return returnValue;
    } else {
        return T{};
    }
}

/* Pop function that doesn't return anything: Cheaper.
template<class T>
void Stack::pop()
{
    if (topPtr != nullptr) {
        Node<T>* tempPtr = topPtr;
        topPtr = topPtr->getNextPtr(); // flytt top til neste i stacken
        delete tempPtr;
    }
}
*/

template<class T>
T& Stack<T>::top()
{
    if (topPtr == nullptr) {
        throw std::runtime_error{"Trying to receive top entry in empty stack."};
    }
    return topPtr->getData();
}

template<class T>
unsigned int Stack<T>::size() const
{
    return nodeCount;
}

template<class T>
void Stack<T>::empty()
{
    Node<T>* p{topPtr};
    while (p != nullptr) {
        Node<T>* current{p};
        p = p->getNextPtr();
        delete current;
    }

    /* Kan gjøre dette også, men jeg lurer på om det kanskje er litt mindre effektivt?
     * (Veldig mye enklere da)
    while (nodeCount > 0) {
        this->pop();
    } */

    nodeCount = 0;
}

#endif // STACK_H

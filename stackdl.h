#ifndef STACKDL_H
#define STACKDL_H

template <class T>
class StackDL;

#include <initializer_list>
#include <stdexcept>
#include "nodedl.h"

/* A doubly linked stack class
 * that supports sorting as well
 * as insertion of elements
 * inbetween nodes. */

template <class T>
class StackDL {
private:
    NodeDL<T> *m_topPtr{nullptr};
    NodeDL<T> *m_backPtr{nullptr};
    unsigned int m_nodeCount{0};

    /** Jeg kan ikke vite om stacken er sorta
     * eller ikke på grunn av at top() og
     * bottom() kan endre verdiene i stacken
     * uten at jeg kan se at de har blitt endret.
     * Hvis jeg skulle kontrollert om stacken
     * hadde vært sorta eller ikke burde jeg nok
     * ha brukt getters / setters, men det hadde
     * gjort stacken litt mer tungvinn å bruke.
     *
     * Stacken blir derfor litt mindre effektiv
     * fordi den må sorte stacken hvis den skal
     * legge inn et element i midten av stacken,
     * uansett om stacken er sortert eller ikke
     * på forrhånd. */
    // bool isSorted{false};

public:
    StackDL(const std::initializer_list<T> &list);

    void push(T value);
    void pop();
    T& top();
    T& bottom();
    unsigned int size();
    void empty();

    /* Sorterer verdiene i nodene slik at de
     * laveste er nederst og de høyeste øverst. */
    void sort();

    // void insert(T value, int index);
    // void insert(T value, T before);
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

    // It's not sorted anymore.
//    if (isSorted)
//        isSorted = false;
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

template<class T>
void StackDL<T>::sort()
{
//    // No need to sort an already sorted
//    if (isSorted)
//        return;

    // Using selection sort
    for (NodeDL<T>* outer{m_topPtr}; outer != nullptr; outer = outer->m_next) {
        NodeDL<T>* currentHighest{outer};
        for (NodeDL<T>* inner{outer}; inner != nullptr; inner = inner->m_next) {
            // Er den nye høyere?
            if (inner->getData() > currentHighest->getData()) {
                currentHighest = inner;
            }
        }
        // Hvis currentHighest ikke er det den startet på, bytt om på dem.
        if (currentHighest != outer) {
            std::swap(currentHighest->getData(), outer->getData());
        }
    }
//    isSorted = true;
}



#endif // STACKDL_H


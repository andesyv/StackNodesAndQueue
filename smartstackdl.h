#ifndef SMARTSTACKDL_H
#define SMARTSTACKDL_H

#include "smartnodedl.h"

template <class T>
class SmartStackDL {
private:
    std::unique_ptr<SmartNodeDL<T>> top{};

public:
    SmartStackDL() {

    }

    void push(const T &value) {
        top = std::make_unique<SmartNodeDL<int>>(value, std::move(top));


    }
};

//template<class T>
//void StackDL<T>::push(T value)
//{
//    NodeDL<T> *newNode = new NodeDL<T>{value, m_topPtr, nullptr};
//    if (m_topPtr != nullptr) {
//        m_topPtr->m_last = newNode;
//    }
//    m_topPtr = newNode;

//    // Set pointer to last element if there are no elements in the stack.
//    if (m_backPtr == nullptr) {
//        m_backPtr = newNode;
//    }

//    m_nodeCount++;

//    // It's not sorted anymore.
////    if (isSorted)
////        isSorted = false;
//}

#endif // SMARTSTACKDL_H

#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    template <class P>
    friend class Queue;
public:
    Node(T value, Node<T>* next = nullptr)
        : data{value}, nextPtr{next} {
    }
    Node<T>* getNextPtr();
    T& getData();

private:
    T data{};
    Node<T>* nextPtr{nullptr};
};


// Function definitions
template<class T>
Node<T>* Node<T>::getNextPtr()
{
    return (nextPtr != nullptr) ? nextPtr : nullptr;
}

template<class T>
T& Node<T>::getData()
{
    return data;
}

#endif // NODE_H

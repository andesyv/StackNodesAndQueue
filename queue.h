#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue;

#include "node.h"

template <class T>
class Queue {
private:
   Node<T>* m_front;
   Node<T>* m_bak;
   unsigned int m_size{0};
public:
   Queue();
   void push(T data);
   T front() const;
   void pop();
   int size();
};


// Function definitions
template <class T>
Queue<T>::Queue() {
   m_front = m_bak = nullptr;
}
template <class T>
void Queue<T>::push(T data) {
   Node<T>* ny = new Node<T>(data);
   if (m_bak)
       m_bak->nextPtr = ny;
   m_bak = ny;

   if (m_front == nullptr)
       m_front = m_bak;
   m_size++;
}
template <class T>
void Queue<T>::pop() {
   if (m_front != nullptr) {
       Node<T>* ut = m_front;
       m_front = m_front->getNextPtr();
       delete ut;
   }
   // Hvis vi sletter siste node, blir m_bak en dingle-peker :-(
   if (m_front == nullptr)
       m_bak = nullptr;
   m_size--;
}
template <class T>
T Queue<T>::front() const {
   return m_front->getData();
}
template <class T>
int Queue<T>::size() { return m_size; }

#endif // TQUEUE_H

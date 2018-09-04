#ifndef STACKDL_H
#define STACKDL_H

#include <initializer_list>
#include "nodedl.h"

template <class T>
class StackDL {
private:
    NodeDL<T> *m_topPtr{nullptr};
    NodeDL<T> *m_backPtr{nullptr};
    unsigned int m_nodeCount{0};

public:
    StackDL(const std::initializer_list<T> &list);

};


/// Function definitions


#endif // STACKDL_H

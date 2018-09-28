#ifndef SMARTNODEDL_H
#define SMARTNODEDL_H

#include <memory>
#include <iostream>

/* A smart double-linked node
 * A node who is doubly linked
 * and also uses smart pointers.
 */

template <class T>
class SmartNodeDL {
private:
    std::unique_ptr<SmartNodeDL<T>> m_next{};
    T m_data;

public:
    SmartNodeDL(const T &data) : m_data{data} {
        std::cout << "Node constructed!" << std::endl;
    }
    SmartNodeDL(const T &data, std::unique_ptr<SmartNodeDL<T>> next) : m_data{data}, m_next{std::move(next)} {
        std::cout << "Node constructed!" << std::endl;
    }

    ~SmartNodeDL() {
        std::cout << "Node destructed!" << std::endl;
    }
};

#endif // SMARTNODEDL_H

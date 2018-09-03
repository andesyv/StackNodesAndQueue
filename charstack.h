#ifndef CHARSTACK_H
#define CHARSTACK_H

#include "charnode.h"

using namespace ADS101;

class CharStack
{
public:
    CharStack();
    char push(char newChar);
    char pop();
    char top();
    void empty();
    unsigned int size();

private:
    CharNode *topPtr{nullptr};
    unsigned int stackCount{0};
};

#endif // CHARSTACK_H

#include "charstack.h"

CharStack::CharStack()
{

}

char CharStack::push(char newChar)
{
    topPtr = new CharNode{newChar, topPtr};
    stackCount++;

    return newChar;
}

char CharStack::pop()
{
    if (topPtr != nullptr) {
        CharNode* tempPtr = topPtr;
        topPtr = topPtr->hentNeste(); // flytt top til neste i stacken
        char returnedChar{tempPtr->hentData()};
        delete tempPtr;
        stackCount--;
        return returnedChar;
    } else {
        return '0';
    }
}

char CharStack::top()
{
    return topPtr->hentData();
}

void CharStack::empty()
{
    /* Hadde hver node hatt en referanse til noden over seg kunne jeg gått
     * til den nederste noden og slettet den først, før jeg gikk videre
     * oppover stacken. */

//    for (CharNode* p{topPtr}; p != nullptr; p=p->hentNeste())
//        delete p;
    CharNode* p{topPtr};
    while (p != nullptr) {
        CharNode* current{p};
        p = p->hentNeste();
        delete current;
    }
    topPtr = nullptr;
    stackCount = 0;

    /* Mye enklere:
     * while (size() > 0)
     *  pop();
     *
     */
}

unsigned int CharStack::size()
{
    return stackCount;
}

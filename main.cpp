// ADS101 Algoritmer og datastrukturer H2017-2018

#include <iostream>
// #include "charnode.h"
#include <charstack.h>
#include "queue.h"
#include <queue>
// #include "stack.h"
// using namespace ADS101;
#include <stack>
#include "stackdl.h"
#include "smartstackdl.h"
int main()
{
    /*ADS101::CharNode* liste = new ADS101::CharNode('a');
    liste = new ADS101::CharNode('b', liste);
    liste = new ADS101::CharNode('c', liste);
    liste = new ADS101::CharNode('d', liste);

    for (ADS101::CharNode* p=liste; p!=0; p=p->hentNeste())
        std::cout << p->hentData();

    std::cout << std::endl << "static antall: " << liste->hentAntall();
    std::cout << std::endl;

    std::cout << "Skriver baklengs; ";
    liste->skrivBaklengs();

    // Slette den første i lista
    ADS101::CharNode* ut = liste;
    liste = liste->hentNeste();
    delete ut;

    std::cout << std::endl << "static antall: " << liste->hentAntall() << std::endl;*/

    // Del 2, oppgave 1
    /*
    CharStack stack{};
    stack.push('a');
    stack.push('b');
    stack.push('g');
    std::cout << "size of stack: " << stack.size() << std::endl;

    while (stack.size() > 1) {
        std::cout << "Popped \'" << stack.pop() << "\' off the stack." << std::endl;
    }

    std::cout << "The top of the stack belongs to \'" << stack.top() << '\'' << std::endl;
    stack.push('k');
    std::cout << "Size before emptying: " << stack.size() << std::endl;
    stack.empty();
    std::cout << "Size after emptying: " << stack.size() << std::endl; */

//    // Stack<char> myStack{'h', 'p', 'c', 'x', 's', 't', 'G', 'H', '*'};
//    std::stack<char> myStack{};
//    myStack.push('h');
//    myStack.push('p');
//    myStack.push('c');
//    myStack.push('x');

//    std::cout << "Top is: " << myStack.top() << std::endl;
//    /* while (myStack.size() > 0) {
//        std::cout << "Popped \"" << myStack.pop() << "\" off the stack." << std::endl;
//    } */
//    while (myStack.size() > 0) {
//        std::cout << "Popped \"" << myStack.top() << "\" off the stack." << std::endl;
//        myStack.pop();
//    }
//    std::cout << "Size is: " << myStack.size() << std::endl;
//    myStack.empty();
//    std::cout << "Size is: " << myStack.size() << std::endl;
//    myStack.top(); // This is expected to throw an exception when using custom Stack class.


    /*
    std::cout << "std::queue har push(), pop(), front(), size()\n";
    std::cout << "\nTester egen queue\n";

    Queue<char> queue;
    queue.push('a');
    queue.push('b');
    queue.push('c');
    auto ch = queue.front();
    std::cout << "queue front = " << ch << std::endl;
    queue.pop();
    queue.pop();
    queue.push('a');
    std::cout << "queue size = " << queue.size() << std::endl;

    std::cout << "\nTester std::queue\n";

    std::queue<char> q;
    q.push('a');
    q.push('b');
    q.push('c');
    ch = q.front();
    std::cout << "queue front = " << ch << std::endl;
    q.pop();
    q.pop();
    q.push('a');
    std::cout << "queue size = " << q.size() << std::endl;

    std::cin >> ch;
    */

//    StackDL<char> doubleStack{'a', 'c'};
//    std::cout << "Top of stack is: " << doubleStack.top() << std::endl;
//    doubleStack.push('b');
//    doubleStack.sort();
//    std::cout << "Top of stack is: " << doubleStack.top() << std::endl;
//    std::cout << "Bottom of stack is: " << doubleStack.bottom() << std::endl;
//    doubleStack.pop();
//    doubleStack.pop();
//    doubleStack.pop();
//    doubleStack.pop();
//    // std::cout << "Top of stack is: " << doubleStack.top() << std::endl;
//    std::cout << "Size of stack is: " << doubleStack.size() << std::endl;
//    doubleStack.empty();
//    std::cout << "Size of stack is: " << doubleStack.size() << std::endl;

//    auto node = std::make_unique<SmartNodeDL<int>>(4);
//    std::cout << "This is a message to stop the flow of the program!" << std::endl;
//    node = std::make_unique<SmartNodeDL<int>>(6, std::move(node));
//    std::cout << "This is another message." << std::endl;
    // SmartNodeDL<int> *firstNode = new SmartNodeDL<int>{4};

    auto node = std::make_unique<SmartStackDL<int>>();
    node->push(5);
    node->push(8);
    node->push(3);
    std::cout << "This is a message!" << std::endl;
    node = nullptr;
    std::cout << "This is another message!" << std::endl;

    return 0;
}



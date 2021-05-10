#include "Node.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Node::Node(int payload)
{
    this->payload = payload;
    this->prevNode = NULL;
    this->nextNode = NULL;
}

int Node::getPayload()
{
    return this->payload;
}

void Node::setPayload(int c)
{
    this->payload = c;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}

Node* Node::getPrevNode()
{
    return this->prevNode;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

void Node::setPrevNode(Node* n)
{
    this->prevNode = n;
}

void Node::display()
{
    cout << this->getPayload() << endl;
}
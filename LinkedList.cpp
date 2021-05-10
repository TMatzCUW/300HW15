#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}

void LinkedList::mergeSort(LinkedList* ll, int begin, int end)
{
    //displayArray(ar, begin, end);
    
    //we only need to do anything in here, if the list is bigger than a 1 list
    if(begin != end)
    {
        //we DO NOT HAVE A 1 LIST!!!!!
        //so we need to divide our list in half and call mergesort on each half
        int begin1 = begin;
        int end1 = (begin + end) / 2;
        int begin2 = end1 + 1;
        int end2 = end;
        mergeSort(ll, begin1, end1);
        mergeSort(ll, begin2, end2);
        
        //now the left half is sorted and the right half is sorted
        //we need to merge them together into a single sorted portion
        //of our list from begin to end 
        merge(ll, begin1, end1, begin2, end2);
    }
    
}

void LinkedList::merge(LinkedList* ll, int begin1, int end1, int begin2, int end2)
{
    int size = end2 - begin1 + 1;
    int temp[size];
    int pos1 = begin1; //0
    int pos2 = begin2; //1
    for(int i = 0; i < size; i++)
    {
        //how do we ask if pos1 points to a legal place on the left half of the list?
        if(pos1 <= end1 && pos2 <= end2)
        {
            if(ll->get(pos1)->getPayload() < ll->get(pos2)->getPayload())
            {
                temp[i] = ll->get(pos1)->getPayload();
                pos1++;
            }
            else
            {
                temp[i] = ll->get(pos2)->getPayload();
                pos2++;
            }
        }
        else if(pos1 <= end1)
        {
            temp[i] = ll->get(pos1)->getPayload();
            pos1++;
        }
        else
        {
            temp[i] = ll->get(pos2)->getPayload();
            pos2++;
        }
    }
    
    //temp is filled up with our values in the correct order
    //we need to now transfer those value back over to ar overwriting
    //the old contents of ar with the contents of temp between begin1 and end2
    int tempPos = 0;
    for(int i = begin1; i <= end2; i++)
    {
        ll->get(i)->setPayload(temp[tempPos]);
        tempPos++;
    }
    //now ar is overwritten between begin1 and end2 with the values in order
    //and this call to merge and mergesort can end;
}

int LinkedList::removeFront()
{
    if(this->count > 0)
    {
        Node* front = this->head;
        int temp = front->getPayload();
        this->head = front->getNextNode();
        this->count--;

        if(this->head)
        {
            this->head->setPrevNode(NULL);
        }

        if(this->tail == front)
        {
            this->tail = NULL;
        }

        front->setNextNode(NULL);
        front->setPrevNode(NULL);
        delete(front);
        return temp;
    }
    return -1;
}

Node* LinkedList::get(int index)
{
    Node* node2Return = this->head;
    for(int i = 0; i < index; i++)
    {
        node2Return = node2Return->getNextNode();
    }
    return node2Return;
}

void LinkedList::swap(int index1, int index2)
{
    Node* smallerNode = this->get(index1);
    Node* largerNode = this->get(index2);
    int temp = smallerNode->getPayload();
    smallerNode->setPayload(largerNode->getPayload());
    largerNode->setPayload(temp);
}

void LinkedList::addEnd(int c)
{
    Node* n = new Node(c);
    if(this->count == 0)
    {
        this->head = n;
        this->tail = n;
    }
    else
    {
        n->setPrevNode(this->tail);
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::getCount()
{
    return this->count;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        currNode->display();
        currNode = currNode->getNextNode();
    }
    cout << endl;
    // this->head->display();
    // this->tail->display();
}
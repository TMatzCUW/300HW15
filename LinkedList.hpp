#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int count;
        Node* get(int index);

    public:
        LinkedList();
        void addEnd(int c);
        int removeFront();
        void display();
        int getCount();
        void swap(int index1, int index2);
        void mergeSort(LinkedList* ll, int begin, int end);
        void merge(LinkedList* ll, int begin1, int end1, int begin2, int end2);
};
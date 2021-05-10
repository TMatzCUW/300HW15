#include <iostream>
#include <string>
#include <stdlib.h>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, char** argv)
{
    //[4, 2, 1, 6, 0, 3]
    //[0, 1, 2, 3, 4, 5]
    LinkedList* ll = new LinkedList();
    ll->addEnd(4);
    ll->addEnd(2);
    ll->addEnd(1);
    ll->addEnd(6);
    ll->addEnd(0);
    ll->addEnd(3);
    ll->display();
    ll->mergeSort(ll, 0, ll->getCount()-1);
    ll->display();
    return 0;
}
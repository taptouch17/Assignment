//
//  Queue.cpp
//  Assignment
//
//  Created by Graeme Stoute on 11/11/2017.
//

#include "Queue.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions
#include <string>

using namespace std;

class Queue::Node //self-referential Node class
{
public:
    char data = ' ';
    Node* link = nullptr;
    //link is a data member which is a pointer
    //to an object of the same type (i.e. Node)
    
};//end Node class definition (can only be seen by the List class)

Queue::~Queue(){
    
    while(num_elements > 0)
        dequeue();
    
}

int Queue::size()
{
    return num_elements;
}

void Queue::enqueue(auto k)
{
    
    Node* newPtr = new Node;
    Node* tmpPtr = frontPtr;
    tmpPtr->data = k;
    
    if (frontPtr == NULL) {
        frontPtr = tmpPtr;
    }
    else {
        rearPtr->link = tmpPtr;
    }
    rearPtr = tmpPtr;
    rearPtr->link = frontPtr;
    
    
    
    
    
}

void Queue::dequeue()
{
    
    Node*newPtr = frontPtr;
    if(num_elements == 0 || frontPtr == NULL){
        
        throw out_of_range("Queue::dequeue() Empty Queue");
        
    }
    char c;
    if (frontPtr == rearPtr) {
        c = frontPtr->data;
        free(frontPtr);
        frontPtr = NULL;
        rearPtr = NULL;
        frontPtr = rearPtr = nullptr;
    }
    else {
        Node*tmp = frontPtr;
        c = tmp->data;
        frontPtr = frontPtr->link;
        rearPtr->link = frontPtr;
        free(tmp);
        
    }
    
}



void Queue::clear()
{
    
    while(size() != 0)
    {
        dequeue();
    }
    
}

char Queue::front()
{
    if(num_elements == 0){
        
        throw out_of_range("Queue::front() Empty Queue");
        
    }
    
    Node* printPtr = nullptr;
    
    printPtr = frontPtr;
    return printPtr->data;
    
}

char Queue::displayQueue() {
    Node*tmp = frontPtr;
    cout << "\n Elements in this queue are: ";
    
    while (tmp -> link != frontPtr) {
        cout << tmp->data << endl;
        tmp = tmp -> link;
        return tmp->data;
    }
    cout << tmp->data;
    return tmp->data;
}


bool Queue::isEmpty()
{
    
    bool empty = false;
    
    if(num_elements == 0){
        
        empty = true;
        
    }
    
    return empty;
    
}

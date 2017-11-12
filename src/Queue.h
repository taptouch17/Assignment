//
//  Queue.hpp
//  Assignment
//
//  Created by Graeme Stoute on 11/11/2017.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

using namespace std;

class Queue
{
private:
    
    class Node;
    
    Node* frontPtr = nullptr;
    Node* rearPtr;
    int num_elements = 0;
    
public:
    
    ~Queue(); //d'tor
    
    int size(); //tells you the number of items in the ADT
    
    void enqueue(auto); //inserts item at the back of queue
    
    void dequeue(); //removes an item from the front of the queue
    
    bool isEmpty(); //checks to see if ADT is empty
    
    char front(); //tells us the element at the front of the list without removing it
    
    void clear(); //makes the ADT empty
    
    char displayQueue(); // Displays items in queue
    
    
};


#endif /* Queue_hpp */

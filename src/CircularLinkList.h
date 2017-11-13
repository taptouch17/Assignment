//
//  Queue.hpp
//  Assignment
//
//  Created by Jelani on 11/11/2017.
//

#ifndef CircularLinkList_h
#define CircularLinkList_h

#include <stdio.h>

using namespace std;

class CircularList
{
private:
    
    class Node;
    Node *rear, *front;
    int num_elements = 0;
    
    
public:
    
    void createANode(int value);
    void addAtFront(int value);
    char atFront();
    char atBack();
    void deleteElement(int value);
    char displayList();
    void addAtBack(int value, int position);
    void deleteEnd();
    
    
    CircularList() {
        front = NULL;
    }
    
   // ~CircularList(); //d'tor
    
    int size(); //tells you the number of items in the ADT
    
    /*
    void enqueue(int k); //inserts item at the back of queue
    
    void dequeue(); //removes an item from the front of the queue
    
    bool isEmpty(); //checks to see if ADT is empty
    
    int front(); //tells us the element at the front of the list without removing it
    
    void clear(); //makes the ADT empty
    
    int displayQueue(); // Displays items in queue
    
    */
};


#endif /* Queue_hpp */

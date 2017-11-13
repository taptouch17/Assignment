//
//  Queue.hpp
//  Queue
//
//  Created by Jelani on 13/11/2017.
//  Copyright © 2017 Tap. TOUCH. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include "CircularLinkList.h"


class Queue {
private:
    CircularList List;
    
public:
    //~Queue();
    int size(); //tells you the number of items in the ADT
    
    void enqueue(char k); //inserts item at the back of queue
    
    void dequeue(char value); //removes an item from the front of the queue
    
    bool isEmpty(); //checks to see if ADT is empty
    
    char front(); //tells us the element at the front of the queue without removing it
    
    char back(); // tells us the element at the back of the queue without removing it
    
    void clear(); //makes the ADT empty
    
    int displayQueue(); // Displays items in queue
    
};

#endif /* Queue_hpp */

//
//  Queue.cpp
//  Queue
//
//  Created by Jelani on 13/11/2017.
//  Copyright © 2017 Tap. TOUCH. All rights reserved.
//

#include "Queue.h"
#include "CircularLinkList.h"

#include <stdio.h>
#include <iostream>

using namespace std;

int Queue::size() {
    
    cout << "The size of the Queeue is " << List.size() << endl;
    
    return List.size();
    
    
}

void Queue::enqueue(char theValue) {
    
    if (List.size() == 0) {
        List.createANode(theValue);
        return;
    }
    List.addAtBack(theValue, List.size());
}

void Queue::dequeue(char value) {
    List.deleteElement(value);
    
}

int Queue::displayQueue() {
    cout << "The Queue is " << endl;
    return List.displayList();
}

bool Queue::isEmpty() {
    if (size() != 0) {
        return false;
    }
    return true;
}

char Queue::front() {
    return List.atFront();
}

char Queue::back() {
    return List.atBack();
}
void Queue::clear() {
    while (List.size() > 0) {
        List.deleteEnd();
    }
}









//
//  Queue.cpp
//  Assignment
//
//  Created by Graeme Stoute on 11/11/2017.
//

#include "CircularLinkList.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions
#include <string>

using namespace std;


class CircularList::Node {
public:
    int data;
    Node *link;
};

char CircularList::atFront() {
    if(num_elements == 0){
        
        throw out_of_range("Queue::front() Empty Queue");
        
    }
    
    Node* printPtr = nullptr;
    
    printPtr = front;
    return printPtr->data;
}

char CircularList::atBack() {
    if(num_elements == 0){
        
        throw out_of_range("Queue::front() Empty Queue");
        
    }
    
    Node* printPtr = nullptr;
    
    printPtr = rear;
    return printPtr->data;
}

void CircularList::addAtBack(int value, int position) {
    if (front == NULL) {
        throw out_of_range("Create List first");
        return;
    }
    
    Node *tmp;
    rear = front->link;
    for (int i = 0; i < position - 1; i++) {
        rear = rear->link;
        if (rear == front->link) {
            throw out_of_range("They are less than the items prescribed in list.");
            return;
        }
        
    }
    tmp = new Node;
    tmp->link = front->link;
    tmp->data = value;
    front->link = tmp;
    num_elements++;
    if (rear == front) {
        front = tmp;
        
    }
    
}
void CircularList::addAtFront(int value) {
    if (front == NULL) {
        throw out_of_range("create the list first please");
        return;
    }
    Node* tmp;
    tmp = new Node;
    tmp->data = value;
    tmp->link = front->link;
    front->link = tmp;
    num_elements++;
    
}

void CircularList::createANode(int value) {
    Node *tmp;
    tmp = new Node;
    tmp->data = value;
    
    if (front == NULL) {
        front = tmp;
        tmp->link = front;
        
        
    }
    else {
        tmp->link = front->link;
        front->link = tmp;
        front = tmp;
        
    }
    num_elements++;
}

void CircularList::deleteEnd() {
    if (rear == NULL) {
        throw out_of_range("List is empty");
    }
    Node *tmp1 = rear, *tmp2 = nullptr;
    if (tmp1->link == front) {
        front = NULL;
        free(front);
        return;
    }
    
    if (tmp1->link == rear) {
        tmp1 = rear;
        rear = rear->link;
        free(tmp1);
        
    }
    else {
        while (tmp1->link != rear) {
            tmp2 = tmp1;
            tmp1 = tmp1->link;
        }
        tmp2 -> link = rear;

        //delete tmp1;
        
        free(tmp1);
    }
    num_elements--;
    
}

void CircularList::deleteElement(int value) {
    Node *tmp;
    front = rear->link;
    
    if (rear->link == rear && rear->data == value){
        tmp = rear;
        rear = NULL;
        free(tmp);
        num_elements--;
        return;
    }
    if (front->data == value) {
        tmp = front;
        rear->link = NULL;
        free(tmp);
        num_elements--;
        return;
    }
    while(front->link != rear) {
        if (front->link->data == value){
            tmp = front->link;
            front->link = tmp->link;
            free(tmp);
            num_elements--;
            return;
            
        }
        front = front->link;
    }
    if (front->link->data == value) {
        tmp = front->link;
        front->link = rear->link;
        free(tmp);
        rear = front;
        num_elements--;
    }
    throw out_of_range("Element not found in list");
}

char CircularList::displayList() {
    if (front == NULL) {
        throw out_of_range("LIST EMPTY");
        return 0;
    }
    rear = front->link;
    cout << "Circular link list: " << endl;
    while (front != rear) {
        cout << rear->data << "->";
        rear=rear->link;
    }
    cout << rear->data << endl;
    return rear->data;
}

int CircularList::size() {
    
    return num_elements;
}

    
    

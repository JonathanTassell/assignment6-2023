#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList{
    private:
        Node* head; 
        int linkLength; 
    
    public:
        LinkedList();
        LinkedList(int* array, int len); 
        ~LinkedList(); 


        void deleteFromFront(); 
        void printList(); 
        void insertPosition(int pos, int newNum); 

        bool deletePosition(int pos); 

        int get(int pos); 
        int search(int target); 

        Node* transverse(unsigned int index); 

}; 

#endif
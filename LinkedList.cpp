#include <iostream> 
#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr; 
}

LinkedList::LinkedList(int* array, int len){
    linkLength=len; 
    for(int i=0; i<len; i++){
        insertPosition(i, array[i]); 
    }
}

LinkedList::~LinkedList(){
    while(head != nullptr){
        deleteFromFront(); 
    }
}

void LinkedList::printList(){
    Node* currNode = head;

    for(int count=0; count<linkLength; count++){
        if(count == 0)
            std::cout << "[";

        std::cout << currNode->data; 

        if(count+1<linkLength)
            std::cout << " "; 
        else std::cout << "]";

        currNode = currNode->link; 
    }
    
}

Node* LinkedList::transverse(unsigned int index){
    unsigned int position = 0; 
    Node* currNode = head; 
    
    while(currNode != nullptr && position < index){
        currNode = currNode->link; 
        position++; 
    }
    return currNode; 
}

bool LinkedList::deletePosition(int pos){
    Node* deletedNode = transverse(pos-1);
    Node* postNode = transverse(pos); 

    //if deletedNode doesn't exist, don't delete it
    if(deletedNode!= nullptr){
        delete deletedNode; 
        linkLength--; 
        //if postNode exists, prevNode's link equal to postNode, if not then nullptr 
        if(postNode != nullptr){
            transverse(pos-2)->link = postNode; 
        }
        else transverse(pos-2)->link = nullptr; 

        return true; 
    }
    else return false; 
}

int LinkedList::get(int pos){
    return transverse(pos-1)->data; 
}

int LinkedList::search(int target){
    Node* currNode = head; 

    for(int position=0;position < linkLength-1; position++){
        if(currNode->data == target){
            return position; 
        }
        currNode = currNode->link; 
    }
    return -1; 
}


void LinkedList::insertPosition(int pos, int newNum){
    if(pos == 0){
        head = new Node(newNum, head); 
     
        return; 
    }

    Node *prevNode = transverse(pos-1); 

    if(prevNode == nullptr){
        return; 
    }

    Node *newNode = new Node(newNum, prevNode->link); 
    prevNode->link = newNode; 
  
}

void LinkedList::deleteFromFront() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->link;
    delete temp;
}
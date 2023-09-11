#include <iostream> 
#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr; 
}

LinkedList::LinkedList(int* array, int len){
    linkLength =0; 
    for(int i=0; i<len; i++){
        linkLength++; 
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
        std::cout << currNode->data << " "; 
        currNode = currNode->link; 
    }
    std::cout << std::endl; 

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
    return transverse(pos)->data; 
}

int LinkedList::search(int target){
    unsigned int position = 0; 
    Node* currNode = head; 

    while(currNode != nullptr){
        if(currNode->data == target){
            return position; 
        }
        currNode = currNode->link; 
        position++; 
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
    linkLength++; 
}

void LinkedList::deleteFromFront(){
    if(head == nullptr){
        return; 
    }
}
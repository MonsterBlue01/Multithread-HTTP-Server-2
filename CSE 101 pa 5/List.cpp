#include<iostream>
#include<string>
#include<stdexcept>

#include "List.h"

List::Node::Node(ListElement x){
    data = x;
    next = nullptr;
    prev = nullptr;
}

List::List(){
    frontDummy = nullptr;
    backDummy = nullptr;
    beforeCursor = nullptr;
    afterCursor = nullptr;
    pos_cursor = 0;
    num_elements = 0;
}

List::List(const List& Q){
    // make this an empty Queue
    frontDummy = nullptr;
    backDummy = nullptr;
    beforeCursor = nullptr;
    afterCursor = nullptr;
    pos_cursor = 0;
    num_elements = 0;

    // load elements of Q into this List
}

void List::moveFront() {
    this->afterCursor = this->frontDummy->next;
    this->beforeCursor = this->frontDummy;
}

ListElement List::front() const{
    return(frontDummy->next->data);
}
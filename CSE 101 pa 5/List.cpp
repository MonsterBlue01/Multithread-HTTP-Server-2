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
    frontDummy = new Node(INT32_MIN);
    backDummy = new Node(INT32_MAX);
    beforeCursor = frontDummy;
    afterCursor = backDummy;
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

List::~List(){
    frontDummy = new Node(INT32_MIN);
    backDummy = new Node(INT32_MAX);
    beforeCursor = nullptr;
    afterCursor = nullptr;
    pos_cursor = 0;
    num_elements = 0;
}

void List::moveFront() {
    this->afterCursor = this->frontDummy->next;
    this->beforeCursor = this->frontDummy;
}

ListElement List::front() const{
    return this->frontDummy->next->data;
}

ListElement List::back() const{
    return this->backDummy->prev->data;
}

void List::insertAfter(ListElement x){
    Node* N = new Node(x);
    if (this->afterCursor == this->backDummy) {
        this->afterCursor = N;
        this->backDummy->prev = N;
        N->next = this->afterCursor;
        N->prev = this->beforeCursor;
        this->beforeCursor->next = N;
        return;
    }

    this->afterCursor->next->prev = N;
    N->next = this->afterCursor->next;
    this->afterCursor = N;
    N->prev = this->beforeCursor;
    this->beforeCursor->next = N;

}

void List::insertBefore(ListElement x){
    Node* N = new Node(x);
    if (this->beforeCursor == this->frontDummy) {
        this->beforeCursor = N;
        this->backDummy->prev = N;
        N->next = this->backDummy;
        this->frontDummy->next = N;
        N->prev = this->frontDummy;
        return;
    }

    N->prev = this->beforeCursor;
    N->next = this->afterCursor;
    this->afterCursor->prev = N;
    this->beforeCursor->next = N;
    this->beforeCursor = N;

}
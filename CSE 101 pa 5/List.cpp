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
    frontDummy->prev = nullptr;
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    backDummy->next = nullptr;
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

int List::length() const{
    return this->num_elements;
}

void List::moveFront() {
    this->afterCursor = this->frontDummy->next;
    this->beforeCursor = this->frontDummy;
}

void List::moveBack() {
    this->afterCursor = this->backDummy;
    this->beforeCursor = this->backDummy->prev;
}

ListElement List::front() const{
    return this->frontDummy->next->data;
}

ListElement List::back() const{
    return this->backDummy->prev->data;
}

int List::position() const{
    int num = 0;
    Node *tmp = this->frontDummy->next;
    while (tmp != this->afterCursor) {
        num++;
        tmp = tmp->next;
    }
    return num;
}

void List::insertAfter(ListElement x){
    Node* N = new Node(x);
    N->next = this->afterCursor;
    N->prev = this->beforeCursor;
    this->beforeCursor->next = N;
    this->afterCursor->prev = N;
    this->afterCursor = N;
}

void List::insertBefore(ListElement x){
    Node* N = new Node(x);
    if (this->beforeCursor == this->frontDummy) {
        this->beforeCursor = N;
        this->backDummy->prev = N;
        N->next = this->backDummy;
        this->frontDummy->next = N;
        N->prev = this->frontDummy;
        this->num_elements++;
        return;
    }

    N->prev = this->beforeCursor;
    N->next = this->afterCursor;
    this->afterCursor->prev = N;
    this->beforeCursor->next = N;
    this->beforeCursor = N;
    this->num_elements++;
}

std::string List::to_string() const{
    Node* N = nullptr;
    std::string s = "(";

    for(N=this->frontDummy->next; N!=this->backDummy; N=N->next){
        if (N != this->backDummy->prev) {
            s += std::to_string(N->data)+", ";
        } else if (N == this->backDummy->prev)
        {
            s += std::to_string(N->data)+")";
        }
        
    }
    
    return s;
}

std::ostream& operator<< ( std::ostream& stream,  const List& Q ) {
    return stream << Q.List::to_string();
}
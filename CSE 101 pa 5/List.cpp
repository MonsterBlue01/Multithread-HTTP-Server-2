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
    this->afterCursor->prev = this->frontDummy;
    this->afterCursor->next = this->frontDummy->next->next;
    this->beforeCursor = this->frontDummy;
    this->beforeCursor->prev = nullptr;
    this->beforeCursor->next = this->frontDummy->next;
}

void List::moveBack() {
    this->afterCursor = this->backDummy;
    this->afterCursor->next = nullptr;
    this->afterCursor->prev = this->backDummy->prev;
    this->beforeCursor = this->backDummy->prev;
    this->beforeCursor->next = this->backDummy;
    this->beforeCursor->prev = this->backDummy->prev->prev;
}

ListElement List::moveNext() {
    if (this->afterCursor == backDummy) {
        std::cout << "Warning: You already reached the end." << std::endl;
        return 0;
    }
    this->beforeCursor = this->afterCursor;
    this->afterCursor = this->afterCursor->next;
    return this->beforeCursor->data;
}

ListElement List::movePrev() {
    if (this->afterCursor == frontDummy) {
        std::cout << "Warning: You already reached the head." << std::endl;
        return 0;
    }
    this->afterCursor = this->beforeCursor;
    this->beforeCursor = this->beforeCursor->prev;
    return this->afterCursor->data;
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
    this->num_elements++;
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

void List::eraseAfter(){
    this->beforeCursor->next = this->afterCursor->next;
    this->afterCursor->next->prev = this->beforeCursor;
    delete this->afterCursor;
    this->afterCursor = this->beforeCursor->next;
}

void List::eraseBefore(){
    this->beforeCursor->prev->next= this->afterCursor;
    this->afterCursor->prev = this->beforeCursor->prev;
    delete this->beforeCursor;
    this->beforeCursor = this->afterCursor->prev;
}

int List::findNext(ListElement x){
    for (;afterCursor != backDummy; moveNext()) {
        if (this->afterCursor->data == x) {
            moveNext();
            return this->position();
        }
    }

    return -1;
}

int List::findPrev(ListElement x) {
    for (;beforeCursor != frontDummy; movePrev()) {
        if (this->beforeCursor->data == x) {
            movePrev();
            return this->position();
        }
    }

    return -1;
}

void List::cleanup() {
    int pos = this->position();
    for (Node* N = this->frontDummy->next; N->next != this->backDummy; N = N->next) {
        int dup = 0;
        for (this->moveFront(); this->afterCursor != backDummy; this->moveNext()) {
            if (this->afterCursor->data == N->data) {
                dup += 1;
                if (dup > 1) {
                    this->eraseAfter();
                }
            }
        }
    }
    // std::cout << "The element after cursor: " << this->afterCursor->data << std::endl;
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

bool List::equals(const List& Q) const{
    bool eq = false;
    Node* N = nullptr;
    Node* M = nullptr;

    eq = (this->num_elements == Q.num_elements);
    N = this->frontDummy->next;
    M = Q.frontDummy->next;
    while( eq && N!=nullptr){
        eq = (N->data==M->data);
        N = N->next;
        M = M->next;
    }
    return eq;
}

std::ostream& operator<< ( std::ostream& stream,  const List& Q ) {
    return stream << Q.List::to_string();
}

bool operator== (const List& A, const List& B){
    return A.List::equals(B);
}
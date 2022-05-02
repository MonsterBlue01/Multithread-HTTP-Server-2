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

List::List(const List& L){
    // make this an empty Queue
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

    // load elements of Q into this List
    Node* N = L.frontDummy->next;
    while(N != L.backDummy){
        this->insertBefore(N->data);
        N = N->next;
    }

    int pos = L.position();
    moveFront();
    while (pos != 0) {
        if (afterCursor == backDummy) {
            break;
        }
        moveNext();
        pos--;
    }
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

void List::clear() {
    moveFront();
    while (frontDummy->next != backDummy) {
        eraseAfter();
    }
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
    if (afterCursor == backDummy){
        throw std::range_error("List: moveNext(): cursor at back");
    }
    this->beforeCursor = this->afterCursor;
    this->afterCursor = this->afterCursor->next;
    return this->beforeCursor->data;
}

ListElement List::movePrev() {
    if (position() == 0){
        throw std::range_error("List: movePrev(): cursor at front");
    }
    this->afterCursor = this->beforeCursor;
    this->beforeCursor = this->beforeCursor->prev;
    return this->afterCursor->data;
}

ListElement List::front() const{
    if (frontDummy->next == backDummy) {
        throw std::length_error("List: front(): empty list");
    }
    return this->frontDummy->next->data;
}

ListElement List::back() const{
    if (frontDummy->next == backDummy) {
        throw std::length_error("List: back(): empty list");
    }
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

ListElement List::peekNext() const{
    if (afterCursor == backDummy){
        throw std::range_error("List: peekNext(): cursor at back");
    }
    return afterCursor->data;
}

ListElement List::peekPrev() const{
    if (position() == 0){
        throw std::range_error("List: peekPrev(): cursor at front");
    }
    return beforeCursor->data;
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
    N->prev = beforeCursor;
    N->next = afterCursor;
    beforeCursor->next = N;
    afterCursor->prev = N;
    beforeCursor = N;
    num_elements++;
}

void List::setBefore(ListElement x) {
    if (position() == 0){
        throw std::range_error("List: setBefore(): cursor at front");
    }
    beforeCursor->data = x;
}

void List::setAfter(ListElement x) {
    if (afterCursor == backDummy){
        throw std::range_error("List: setAfter(): cursor at back");
    }
    afterCursor->data = x;
}

void List::eraseAfter(){
    if (afterCursor == backDummy){
        throw std::range_error("List: eraseAfter(): cursor at back");
    }
    beforeCursor->next = afterCursor->next;
    afterCursor->next->prev = beforeCursor;
    delete afterCursor;
    afterCursor = beforeCursor->next;
}

void List::eraseBefore(){
    if (position() == 0){
        throw std::range_error("List: eraseBefore(): cursor at front");
    }
    afterCursor->prev = beforeCursor->prev;
    beforeCursor->prev->next = afterCursor;
    delete beforeCursor;
    beforeCursor = afterCursor->prev;
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
    int pos = position();
    // std::cout << "The position: " << position() << std::endl;
    for (Node *N = frontDummy->next; N != backDummy->prev; N = N->next) {
        int exe = 0;
        for (moveFront(); beforeCursor != N; moveNext()) {
            if (afterCursor == backDummy) {
                exe = 1;
                break;
            }
        }
        if (exe == 1) {
            break;
        }
        for (; afterCursor != backDummy; moveNext()) {
            if (afterCursor->data == N->data) {
                eraseAfter();
                num_elements--;
                exe = 1;
                break;
            }
        }
    }

    moveFront();
    while (pos != 0) {
        if (afterCursor == backDummy) {
            break;
        }
        moveNext();
        pos--;
    }
}

List List::concat(const List& L) const{
    List K;
    Node* N = this->frontDummy->next;
    Node* M = L.frontDummy->next;
    while(N != this->backDummy){
        K.insertBefore(N->data);
        N = N->next;
    }
    while(M != L.backDummy){
        K.insertBefore(M->data);
        M = M->next;
    }
    K.moveFront();
    return K;
}

std::string List::to_string() const{
    Node* N = nullptr;
    std::string s = "(";

    if (frontDummy->next == backDummy) {
        return "()";
    }

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

bool List::equals(const List& L) const{
    bool eq = false;
    Node* N = nullptr;
    Node* M = nullptr;

    eq = (this->num_elements == L.num_elements);
    N = this->frontDummy->next;
    M = L.frontDummy->next;
    while(eq && N!=nullptr){
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

List& List::operator=(const List& L) {
    if ( this != &L ){
        List temp = L;

        // then swap the copy's fields with fields of this
        std::swap(frontDummy, temp.frontDummy);
        std::swap(backDummy, temp.backDummy);
        std::swap(beforeCursor, temp.beforeCursor);
        std::swap(afterCursor, temp.afterCursor);
        std::swap(pos_cursor, temp.pos_cursor);
        std::swap(num_elements, temp.num_elements);
    }

    // return this with the new data installed
    return *this;
}

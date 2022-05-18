#include "Dictionary.h"

typedef std::string keyType;
typedef int valType;

Dictionary::Node::Node(keyType k, valType v){
    this->key = k;
    this->left = nullptr;
    this->right = nullptr;
    this->val = v;
    this->parent = nullptr;
}

Dictionary::Dictionary(){
    this->nil = new Node("123AbC", INT32_MAX);
    this->root = nil;
    this->current = nil;
    this->num_pairs = 0;
}

Dictionary::Dictionary(const Dictionary& D) {
    this->nil = new Node("123AbC", INT32_MAX);
    this->root = nil;
    this->current = nil;
    this->num_pairs = 0;

    preOrderCopy(D.root, (*this));
}

Dictionary::~Dictionary(){
    this->nil = nullptr;
    this->root = nil;
    this->current = nullptr;
    this->num_pairs = 0;
}

void Dictionary::inOrderString(std::string& s, Node* R) const {
    std::string s1 = " : ";
    std::string s2 = "\n";
    if (R != nil) {
        inOrderString(s, R->left);
        if (R->key != "") {
            s = s + R->key + s1 + std::to_string(R->val) + s2;
        }
        inOrderString(s, R->right);
    }
}

void Dictionary::preOrderString(std::string& s, Node* R) const {
    std::string s1 = "\n";
    if (R != nil) {
        s = s + R->key + s1;
        preOrderString(s, R->right);
        preOrderString(s, R->left);
    }
}

void Dictionary::postOrderDelete(Node* R) {
    if (R != nil) {
        postOrderDelete(R->left);
        postOrderDelete(R->right);
        delete R;
    }
}

void Dictionary::preOrderCopy(Node* R, Dictionary &T) {
    if (R->key != "123AbC"){
        T.setValue(R->key, R->val);
        preOrderCopy(R->left, T);
        preOrderCopy(R->right, T);
    }
}

Dictionary::Node* Dictionary::search(Node* R, keyType k) const{
    if (R == nil or R->key == k) {
        return R;
    } else if (k < R->key) {
        return search(R->left, k);
    } else {
        return search(R->right, k);
    }
}

Dictionary::Node* Dictionary::findMin(Node* R) {
    while (R->left != nil){
        R = R->left;
    }
    return R;
}

Dictionary::Node* Dictionary::findMax(Node* R) {
    while (R->right != nil){
        R = R->right;
    }
    return R;
}

Dictionary::Node* Dictionary::findNext(Node* N) {
    if (N->right != nil) {
        return findMin(N->right);
    }
    Node* y = N->parent;
    while ((y != nil) && (N == y->right)) {
        N = y;
        y = y->parent;
    }
    return y;
}

Dictionary::Node* Dictionary::findPrev(Node* N) {
    if (N->left != nil) {
        return findMax(N->left);
    }
    Node* y = N->parent;
    while ((y != nil) && (N == y->left)) {
        N = y;
        y = y->parent;
    }
    return y;
}

int Dictionary::size() const{
    return num_pairs;
}

bool Dictionary::contains(keyType k) const{
    if (search(root, k) == nil) {
        return false;
    } else {
        return true;
    }
}

valType& Dictionary::getValue(keyType k) const {
    Node* tmp = search(root, k);
    return tmp->val;
}

bool Dictionary::hasCurrent() const {
    if (current == nil) {
        return false;
    } else {
        return true;
    }
}

keyType Dictionary::currentKey() const {
    if (hasCurrent() == false){
        throw std::logic_error("Dictionary: currentKey(): current undefined");
    }
    return current->key;
}

valType& Dictionary::currentVal() const {
    if (hasCurrent() == false){
        throw std::logic_error("Dictionary: currentVal(): current undefined");
    }
    return current->val;
}

void Dictionary::setValue(keyType k, valType v) {
    if (num_pairs != 0) {
        Node* tmp = search(root, k);
        if (tmp != nil) {
            tmp->val = v;
            return;
        }
    }

    Node* z = new Node(k, v);
    z->left = nil;
    z->right = nil;

    Node* y = nil;
    Node* x = root;
    while (x != nil) {
        y = x;
        // std::cout << "z->key: " << z->key << std::endl;
        // std::cout << "x->key: " << x->key << std::endl;
        if (z->key < x->key) {
            x = x->left;
        } else { 
            x = x->right;
        }
    }

    z->parent = y;
    if (y == nil) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    num_pairs++;
}

void Dictionary::clear() {
    postOrderDelete(root);
    root = nil;
    current = nil;
    num_pairs = 0;
}

void Dictionary::Transplant(Node* u, Node* v) {
    if (u->parent == nil) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    } 
        
    if (v != nil) {
        v->parent = u->parent;
    }
}

bool Dictionary::compare(Node* R, Node* r) {
    if ((R->key == "123AbC") && (r->key == "123AbC")) {
        return true;
    }

    if (((R->key == "123AbC") && (r->key != "123AbC")) || ((R->key != "123AbC") && (r->key == "123AbC"))) {
        return false;
    }

    if (R->key != r->key) {
        return false;
    }

    if (R->val != r->val) {
        return false;
    }

    if (compare(R->left, r->left) == false) {
        return false;
    }

    if (compare(R->right, r->right) == false) {
        return false;
    }

    return true;
}

void Dictionary::remove(keyType k){
    if (current->key == k) {
        current = nil;
    }
    Node* z = search(root, k);
    if (z->left == nil) {
        Transplant(z, z->right);
    } else if (z->right == nil) {
        Transplant(z, z->left);
    } else {
        Node *y = findMin(z->right);
        if (y->parent != z) {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    num_pairs--;
}

void Dictionary::begin() {
    if (root == nil) {
        return;
    }
    Node* tmp = findMin(root);
    current = tmp;
}

void Dictionary::end() {
    if (root == nil) {
        return;
    }
    Node* tmp = findMax(root);
    current = tmp;
}

void Dictionary::next() {
    Node* R = root;
    while (R->right != nil){
        R = R->right;
    }
    if (current->val == R->val) {
        current = nil;
        return;
    }
    current = findNext(current);
}

void Dictionary::prev() {
    Node* R = root;
    while (R->left != nil){
        R = R->left;
    }
    if (current->val == R->val) {
        current = nil;
        return;
    }
    current = findPrev(current);
}

std::string Dictionary::to_string() const{
    std::string s;
    inOrderString(s, root);
    return s;
}

std::string Dictionary::pre_string() const{
    std::string s;
    preOrderString(s, root);
    return s;
}

bool Dictionary::equals(const Dictionary& D) const{
    std::string a = this->to_string();
    std::string b = D.to_string();
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<< ( std::ostream& stream, Dictionary& D ) {
    return stream << D.Dictionary::to_string();
}

bool operator==( const Dictionary& A, const Dictionary& B ) {
    Dictionary C = A;
    return C.compare(A.root, B.root);
}

Dictionary& Dictionary::operator=( const Dictionary& D ) {
    if ( this != &D ){
        Dictionary temp = D;

        // then swap the copy's fields with fields of this
        std::swap(nil, temp.nil);
        std::swap(root, temp.root);
        std::swap(current, temp.current);
        std::swap(num_pairs, temp.num_pairs);
    }

    // return this with the new data installed
    return *this;
}
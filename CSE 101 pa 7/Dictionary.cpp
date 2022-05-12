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
    this->nil = new Node("dnE", INT32_MAX);
    this->root = nil;
    this->current = nullptr;
    this->num_pairs = 0;
}

Dictionary::~Dictionary(){
    this->nil = nullptr;
    this->root = nil;
    this->current = nullptr;
    this->num_pairs = 0;
}

void Dictionary::inOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        inOrderString(s, R->left);
        s += R->key;
        inOrderString(s, R->right);
    }
}

void Dictionary::preOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        s += R->key;
        preOrderString(s, R->left);
        preOrderString(s, R->right);
    }
}

void Dictionary::postOrderDelete(Node* R) {
    if (R != nil) {
        postOrderDelete(R->left);
        postOrderDelete(R->right);
        delete R;
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

void Dictionary::setValue(keyType k, valType v) {
    if (num_pairs != 0) {
        Node* tmp = search(root, k);
        if (tmp != nil) {
            tmp->key = k;
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

void Dictionary::remove(keyType k){
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
#include "Dictionary.h"

Dictionary::Node::Node(keyType k, valType v){
    key = k;
    val = v;
    color = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Dictionary::Dictionary(){
    nil = new Node("wRONg", INT32_MAX);
    root = nil;
    num_pairs = 0;
    current = nil;
}

Dictionary::Dictionary(const Dictionary& D){{
    
}
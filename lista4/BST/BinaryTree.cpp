#include "BinaryTree.h"

BinaryTree::BinaryTree(){
    this->root = new Node();
}

BinaryTree::BinaryTree(int& key){
    this->root = new Node();
    this->root->newNode(key, nullptr);
    std::cout << this->root->key;
}

BinaryTree::BinaryTree(std::vector<int>& key){
    this->root = new Node();
    this->root->newNode(key[0], nullptr);
    for (int i = 1; i < key.size(); i++){
        Node* node = new Node();
        node->key = key[i];
        insert(node);
    }
}

BinaryTree::~BinaryTree(){
    destroySubTree(this->root);
}

void BinaryTree::destroySubTree(Node *node){
    if(node != nullptr){
        destroySubTree(node->left);
        destroySubTree(node->right);
        delete node;
    }
}

int BinaryTree::height(){
    height(this->root);
}

int BinaryTree::height(Node* node){
    if (node == nullptr)
        return 0;
    int right_height = height(node->right);
    int left_height = height(node->left);
    if (left_height < right_height)
        return 1 + right_height;
    return 1 + left_height;
}

void BinaryTree::inOrder(){
    inOrder(this->root);
}

void BinaryTree::inOrder(Node* node){
    if(node != nullptr){
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }
}

void BinaryTree::insert(Node* node){
    Node* current_node = this->root;
    if (current_node == nullptr){
        current_node = node;
    }else{
        while (current_node != nullptr){
            if(node->key < current_node->key){
                if(current_node->left == nullptr){
                    current_node->left = node;
                    node->parent = current_node;
                    break;
                }
                current_node = current_node->left;
            }else{
                if(current_node->right == nullptr){
                    current_node->right = node;
                    node->parent = current_node;
                    break;
                }
                current_node = current_node->right;
            }
        }
    }
}

Node* BinaryTree::lowestLeaf(Node* node){
    if(node->left != nullptr)
        return lowestLeaf(node->left);
    return node;
}

void BinaryTree::postOrder(){
    postOrder(this->root);
}

void BinaryTree::postOrder(Node* node){
    if (node != nullptr){
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->key << " ";
    }
}

void BinaryTree::preOrder(){
    preOrder(this->root);
}

void BinaryTree::preOrder(Node* node){
    if(node != nullptr){
        std::cout << node->key << " ";
        int aux = node->key;
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinaryTree::removeNode(Node *node){
    // Case 1: Leaf node
    if(node->left == nullptr && node->right == nullptr){
        if(node != this->root){
            if (node->key < node->parent->key)
                node->parent->left = nullptr;
            else
                node->parent->right = nullptr;
        }
        else
            this->root = nullptr;
        delete node;
    }
    // Case 2: Just right child
    else if(node->left == nullptr && node->right != nullptr){
        node->key = node->right->key;
        node->right = nullptr;
    }
    // Case 3: Just left child
    else if(node->left != nullptr && node->right == nullptr){
        node->key = node->left->key;
        node->left = nullptr;
    }
    // Case 4: Both children
    else{
        Node** lowest_leaf = &node->right;
        while((*lowest_leaf)->left != nullptr)
            lowest_leaf = &(*lowest_leaf)->left;

        node->key = (*lowest_leaf)->key;
        Node* removed_node = (*lowest_leaf);
        *lowest_leaf = (*lowest_leaf)->right;

        delete (removed_node);
    }
}

Node *BinaryTree::search(int& key){
    Node *current_node = this->root;
    while (current_node != nullptr){
        if(key == current_node->key)
            return current_node;
        else if(key < current_node->key)
            current_node = current_node->left;
        else if(key > current_node->key)
            current_node = current_node->right;
    }
    return nullptr;
}
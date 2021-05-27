#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

typedef struct node
{
    int key;
    node *parent;
    node *left;
    node *right;

    void newNode(int k, struct node* parent)
    {
        this->key = k;
        this->parent = parent;
        this->left = nullptr;
        this->right = nullptr;
    }
} Node;

class BinaryTree {
public:
    BinaryTree();
    BinaryTree(int& key);
    BinaryTree(std::vector<int>& key);
    ~BinaryTree();
    void destroySubTree(Node *node);
    int height();
    void inOrder();
    void insert(Node* node);
    Node* lowestLeaf(Node* node);
    void postOrder();
    void preOrder();
    void removeNode(Node *node);
    Node *search(int& key);

private:
    Node *root;
    int height(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
};

#endif //BINARYTREE_H
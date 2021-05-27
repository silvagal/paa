#include "BinaryTree.h"
#include "Teste.h"

int main() {
    std::vector<int> instances = {52, 22, 85, 8, 43, 81, 96, 11, 26, 69, 74};
    auto bt = new BinaryTree(instances);
    Node* n;
    Node* a;
    int s = 52;
    n = bt->search(s);

    std::cout << "\nLeft of " << n->key << ": " << n->left->key;
    std::cout << "\nRight of " << n->key << ": " << n->right->key;

    std::cout << "\n\nHeight: " << bt->height();
    std::cout << "\n\nPre order: ";
    bt->preOrder();
    std::cout << std::endl;
    std::cout << "In order: ";
    bt->inOrder();
    std::cout << std::endl;
    std::cout << "Post order: ";
    bt->postOrder();
    std::cout << std::endl;

    s = 81;
    std::cout << "\nRemoving the key " << s << std::endl;
    a = bt->search(s);
    bt->removeNode(a);

    std::cout << "\n\nPre order: ";
    bt->preOrder();
    std::cout << std::endl;
    std::cout << "In order: ";
    bt->inOrder();
    std::cout << std::endl;
    std::cout << "Post order: ";
    bt->postOrder();
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;

    tree.insertNode("uANq6eH7");
    tree.insertNode("gwlXSBJv");
    tree.insertNode("i6QN2GdS");
    tree.insertNode("9nuGJ2CE");
    tree.insertNode("AvqfjP0z");

    cout << "BST records (inorder):" << endl;
    tree.displayInOrder();

    cout << "\nSearching for uANq6eH7: ";
    cout << (tree.searchNode("uANq6eH7") ? "Found" : "Not found") << endl;

    cout << "Searching for TEST1234: ";
    cout << (tree.searchNode("TEST1234") ? "Found" : "Not found") << endl;

    cout << "\nRemoving gwlXSBJv..." << endl;
    tree.remove("gwlXSBJv");

    cout << "Searching after removal: ";
    cout << (tree.searchNode("gwlXSBJv") ? "Found" : "Not found") << endl;

    cout << "\nBST after removal:" << endl;
    tree.displayInOrder();

    return 0;
}

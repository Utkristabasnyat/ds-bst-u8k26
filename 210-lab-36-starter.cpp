
#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");
    string code;
    int count = 0;

    if (!inputFile) {
        cout << "Error: Could not open codes.txt" << endl;
        return 1;
    }

    while (inputFile >> code) {
        tree.insertNode(code);
        count++;
    }

    inputFile.close();

    cout << "Successfully loaded " << count << " codes into the BST." << endl;
    cout << "\nBST records (inorder traversal):" << endl;

    tree.displayInOrder();

    return 0;
}

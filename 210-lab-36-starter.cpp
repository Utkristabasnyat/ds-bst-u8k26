
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");
    string code;
    int count = 0;
    int choice = 0;

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

    do {
        cout << "\n===== Binary Search Tree Menu =====" << endl;
        cout << "1. Add a record" << endl;
        cout << "2. Delete a record" << endl;
        cout << "3. Search for a record" << endl;
        cout << "4. Modify a record" << endl;
        cout << "5. Display all records" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 6." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "Enter code to add: ";
                cin >> code;

                if (tree.searchNode(code)) {
                    cout << "Record already exists." << endl;
                } else {
                    tree.insertNode(code);
                    count++;
                    cout << "Record added successfully." << endl;
                }
                break;
            }

            case 2: {
                cout << "Enter code to delete: ";
                cin >> code;

                if (tree.searchNode(code)) {
                    tree.remove(code);
                    count--;
                    cout << "Record deleted successfully." << endl;
                } else {
                    cout << "Record not found." << endl;
                }
                break;
            }

            case 3: {
                cout << "Enter code to search: ";
                cin >> code;

                if (tree.searchNode(code)) {
                    cout << "Record found." << endl;
                } else {
                    cout << "Record not found." << endl;
                }
                break;
            }

            case 4: {
                string oldCode;
                string newCode;

                cout << "Enter code to modify: ";
                cin >> oldCode;

                if (!tree.searchNode(oldCode)) {
                    cout << "Record not found." << endl;
                } else {
                    cout << "Enter new code: ";
                    cin >> newCode;

                    if (oldCode == newCode) {
                        cout << "No changes made." << endl;
                    } else if (tree.searchNode(newCode)) {
                        cout << "New code already exists." << endl;
                    } else {
                        tree.remove(oldCode);
                        tree.insertNode(newCode);
                        cout << "Record modified successfully." << endl;
                    }
                }
                break;
            }

            case 5: {
                cout << "\nBST records (inorder traversal):" << endl;
                tree.displayInOrder();
                cout << "Total records: " << count << endl;
                break;
            }

            case 6: {
                cout << "Exiting program." << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please select 1 to 6." << endl;
                break;
            }
        }

    } while (choice != 6);

    return 0;
}

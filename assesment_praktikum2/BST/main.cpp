#include <iostream>
#include "bst.h"
int main() {
    createTree();

    root = insertNode(root, "Rizkina Azizah", 60, "Basic");
    insertNode(root, "Hakan Ismail", 50, "Bronze");
    insertNode(root, "Olivia Saevali", 65, "Silver");
    insertNode(root, "Felix Pedrosa", 47, "Gold");
    insertNode(root, "Gamel Al Ghifari", 56, "Platinum");
    insertNode(root, "Hanif Al Faiz", 70, "Basic");
    insertNode(root, "Mutiara Fauziah", 52, "Bronze");
    insertNode(root, "Davi Ilyas", 68, "Silver");
    insertNode(root, "Abdad Mubarok", 81, "Gold");

    cout << "=== Traversal InOrder ===\n";
    inOrder(root);
    cout << endl << endl;

    mostLeft();
    mostRight();
    cout << endl;

    searchByBeratBadan(70);

    return 0;
}
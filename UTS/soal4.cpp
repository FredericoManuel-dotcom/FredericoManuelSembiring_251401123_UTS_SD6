#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* buatNode(int x) {
    return new Node{x, nullptr, nullptr};
}

Node* insert(Node* root, int x) {
    if (root == nullptr) return buatNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node* cariMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* cariMax(Node* root) {
    while (root->right != nullptr) root = root->right;
    return root;
}

void hapusTree(Node* root) {
    if (root == nullptr) return;
    hapusTree(root->left);
    hapusTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int x;

    cout << "Masukan: ";
    while (cin >> x && x != 0) {
        root = insert(root, x);
    }

    if (root == nullptr) {
        cout << "Tree kosong." << endl;
        return 0;
    }

    cout << "In-Order       : ";
    inOrder(root);
    cout << endl;
    cout << "Nilai terkecil : " << cariMin(root)->data << endl;
    cout << "Nilai terbesar : " << cariMax(root)->data << endl;

    hapusTree(root);
    return 0;
}
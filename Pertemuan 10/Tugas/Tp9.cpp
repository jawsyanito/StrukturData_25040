#include <iostream>
using namespace std;

// Struktur node binary tree
struct TreeNode {
    int nilai;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        nilai = x;
        left = NULL;
        right = NULL;
    }
};

// Fungsi mencari nilai minimum
int minimum(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

// Fungsi mencari kedalaman pakai rekursi
int minKedalaman(TreeNode* root) {

    // Jika tree kosong
    if (root == NULL) {
        return 0;
    }

    // Jika node daun
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Jika child kiri kosong
    if (root->left == NULL) {
        return minKedalaman(root->right) + 1;
    }

    // Jika child kanan kosong
    if (root->right == NULL) {
        return minKedalaman(root->left) + 1;
    }

    // Ambil depth terkecil
    return minimum(minKedalaman(root->left), minKedalaman(root->right)) + 1;
}

int main() {

    // Membuat binary tree
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Menampilkan hasil
    cout << "Batas Kedalaman : " << minKedalaman(root);

    return 0;
}
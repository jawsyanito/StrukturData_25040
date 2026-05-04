#include <iostream>
#include <string>

using namespace std;

// Definisi struktur Node
struct Node {
    char label;
    Node *right, *left, *parent;
};

// Variabel Global
Node *root, *nodeBaru, *cur, *temp;
bool cari;

// Fungsi untuk mengecek apakah Tree kosong
bool emptyTree() {
    if (root == NULL) {
        return true;
    } else {
        return false;
    }
}

// Fungsi untuk membuat Root
void createTree(char label) {
    if (root != NULL) {
        cout << "Tree sudah dibuat" << endl;
    } else {
        root = new Node();
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << label << " Berhasil menjadi root" << endl;
    }
}

// Fungsi untuk menambah Node baru (Anak Kiri atau Kanan)
Node *Insert(char label, Node *node, string child) {
    if (emptyTree()) {
        cout << "Tree Masih kosong, Tolong dibuat lah!!" << endl;
        return NULL;
    } else {
        if (child == "left") {
            if (node->left != NULL) {
                cout << "Anak bagian kiri dari node " << node->label << " sudah ada isinya!!" << endl;
                return NULL;
            } else {
                nodeBaru = new Node();
                nodeBaru->label = label;
                nodeBaru->left = NULL;
                nodeBaru->right = NULL;
                nodeBaru->parent = node;
                node->left = nodeBaru;
                cout << "Label " << label << " Berhasil dibuat di anak kiri dari node " << node->label << endl;
            }
        } else if (child == "right") {
            if (node->right != NULL) {
                cout << "Anak bagian kanan dari node " << node->label << " sudah ada isinya!!" << endl;
                return NULL;
            } else {
                nodeBaru = new Node();
                nodeBaru->label = label;
                nodeBaru->left = NULL;
                nodeBaru->right = NULL;
                nodeBaru->parent = node;
                node->right = nodeBaru;
                cout << "Label " << label << " Berhasil dibuat di anak kanan dari node " << node->label << endl;
            }
        }
    }
    return nodeBaru;
}

// Fungsi untuk memperbarui isi Label
void updateLabel(char label, Node *node) {
    if (emptyTree()) {
        cout << "Buat Tree Terlebih Dahulu\n";
    } else {
        if (!node) {
            cout << "Tidak ada Node ini atau masih kosong" << endl;
        } else {
            cout << "Label Sebelumnya = " << node->label << "\n";
            node->label = label;
            cout << "Label Setelahnya = " << node->label << "\n";
        }
    }
}

// Fungsi untuk melihat isi Label
void retriveLabel(Node *node) {
    if (!node) {
        cout << "Tidak ada Node ini atau masih kosong" << endl;
    } else {
        cout << "Label dari Node ini adalah = " << node->label << "\n";
    }
}

// Fungsi Pencarian (Recursive Search)
void nyari(Node *node, char label) {
    if (!node) {
        return;
    }
    cout << node->label << " ";
    if (label == node->label) {
        cout << "\nData ditemukan!!\n";
        cari = true;
        return;
    } else {
        if (cari) return;
        nyari(node->left, label);
        if (cari) return;
        nyari(node->right, label);
    }
}

// Fungsi Menghapus Sub-tree
void deletesub(Node *node) {
    if (node != NULL) {
        if (node != root && node == node->parent->left) {
            node->parent->left = NULL;
        }
        if (node != root && node == node->parent->right) {
            node->parent->right = NULL;
        }
        
        deletesub(node->left);
        deletesub(node->right);

        if (node == root) {
            root = NULL;
            delete node;
        } else {
            delete node;
        }
    }
}

// Alias untuk fungsi menghapus tree secara keseluruhan
void cleartree(Node *node) {
    deletesub(node);
}

// Traversal: PreOrder
void preorder(Node *node) {
    if (!node) {
        return;
    } else {
        cout << node->label << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Traversal: PostOrder
void postorder(Node *node) {
    if (!node) {
        return;
    } else {
        postorder(node->left);
        postorder(node->right);
        cout << node->label << " ";
    }
}

// Traversal: InOrder
void inorder(Node *node) {
    if (!node) {
        return;
    } else {
        inorder(node->left);
        cout << node->label << " ";
        inorder(node->right);
    }
}

// Fungsi Utama
int main() {
    Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeZ;
    
    cout << "Membuat Tree \n";
    createTree('A');
    
    nodeB = Insert('B', root, "left");
    nodeC = Insert('C', root, "right");
    nodeZ = Insert('Z', root, "left"); // Ini akan gagal karena sudah ada 'B'
    
    nodeD = Insert('D', nodeB, "left");
    nodeE = Insert('E', nodeB, "right");
    
    nodeF = Insert('F', nodeC, "right");
    nodeG = Insert('G', nodeC, "left");

    cout << "\nMembaca secara PostOrder\n";
    postorder(root);
    
    cout << "\nMembaca secara InOrder\n";
    inorder(root);
    
    cout << "\nMembaca secara PreOrder\n"; // Note: di gambar tertulis PostOrder lagi, saya sesuaikan ke PreOrder
    preorder(root);

    cari = false;
    cout << "\n\nCari B = "; 
    nyari(root, 'B');

    updateLabel('Z', nodeB);
    retriveLabel(nodeG);
    
    cout << "\nMenghapus Sub-tree G...\n";
    deletesub(nodeG);
    preorder(root);
    
    cout << "\n\nMenghapus seluruh Tree (root)...\n";
    deletesub(root);
    preorder(root);
    
    cout << "\nStatus Empty Tree: " << emptyTree() << endl;

    return 0;
}
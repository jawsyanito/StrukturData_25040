#include <iostream>
// <conio.h> dan <windows.h> dihapus agar aman di semua jenis terminal/IDE

using namespace std;

#define MAX 999
int graph[MAX][MAX];
int n;
char simpul1 = 'A';
char simpul2 = 'A';

// Fungsi untuk menjeda layar tanpa conio.h
void tekanEnter() {
    cout << "\nTekan ENTER untuk kembali ke menu utama...";
    cin.ignore(999, '\n'); // Membersihkan sisa input sebelumnya
    cin.get();             // Menunggu user menekan Enter
}

void addedge(int n) {
    cout << endl;
    int i, j;
    simpul1 = 'A';
    cout << "Beri Nilai 1 jika edge di kedua simpul terhubung dan 0 untuk tidak" << endl << endl;
    for (i = 0; i < n; i++) {
        cout << "Simpul " << simpul1++ << " Terhubung dengan" << endl;
        simpul2 = 'A'; 
        for (j = 0; j < n; j++) {
            cout << "simpul " << simpul2++ << " : ";
            cin >> graph[i][j];
        }
    }
}

void cetakgraph(int n) {
    cout << "\n--- Cetak Adjacency Matriks ---" << endl << endl;
    int i, j;
    cout << "  ";
    simpul1 = 'A';

    for (i = 0; i < n; i++) {
        cout << simpul1++ << " ";
    }
    cout << endl;

    simpul1 = 'A';
    for (i = 0; i < n; i++) {
        cout << simpul1++ << " ";
        for (j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void searchpath(char x, char y) {
    char source = toupper(x) - 65;
    char destination = toupper(y) - 65;
    
    if(source < 0 || source >= n || destination < 0 || destination >= n) {
        cout << "Simpul asal atau tujuan tidak valid!" << endl;
        return;
    }

    int visited[MAX] = {0};
    int dist[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = MAX;
        parent[i] = -1;
    }

    dist[source] = 0;
    visited[source] = 1;
    parent[source] = -1;

    int queue[MAX];
    int front = 0;
    int rear = 0;

    queue[rear++] = source;

    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue[rear++] = v;
            }
        }
    }

    if (!visited[destination]) {
        cout << "Tidak ada jalur dari " << (char)toupper(x) << " ke " << (char)toupper(y) << endl;
    } else {
        cout << "Jarak terpendek dari " << (char)toupper(x) << " ke " << (char)toupper(y) << " adalah " << dist[destination] << endl;
        cout << "Jalur terpendek adalah: ";
        
        int path[MAX];
        int count = 0;
        int u = destination;
        
        while (u != -1) {
            path[count++] = u;
            u = parent[u];
        }
        
        for(int i = count - 1; i >= 0; i--) {
            cout << (char)(path[i] + 65);
            if(i > 0) cout << " -> ";
        }
        cout << endl;
    }
}

void deleteEdge(char x, char y) {
    int i = toupper(x) - 65;
    int j = toupper(y) - 65;
    
    if(i >= 0 && i < n && j >= 0 && j < n) {
        graph[i][j] = 0;
        graph[j][i] = 0;
        cout << "Garis antara Simpul " << (char)toupper(x) << " dan " << (char)toupper(y) << " Berhasil terhapus!\n";
    } else {
        cout << "Simpul tidak valid!" << endl;
    }
}

void deleteVertex(char z) {
    int v = toupper(z) - 65;
    if (v < 0 || v >= n) {
        cout << "Simpul Tidak ada." << endl;
        return;
    }

    for (int i = v; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            graph[j][i] = graph[j][i + 1];
        }
    }

    for (int i = v; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = graph[i + 1][j];
        }
    }

    n--;
    cout << "Simpul " << (char)toupper(z) << " Berhasil Terhapus." << endl;
}

int main() {
    char x, y;
    int pil;

    while (true) {
        // Pemisah visual untuk menggantikan fungsi hapus layar (cls)
        cout << "\n\n===========================" << endl;
        cout << "====== Adjency Matrik =====" << endl;
        cout << "===========================" << endl;
        cout << "1. Tambah simpul dan Sisi" << endl;
        cout << "2. Cetak Graph" << endl;
        cout << "3. Cari Jalur" << endl;
        cout << "4. Hapus Simpul" << endl;
        cout << "5. Hapus Sisi" << endl;
        cout << "6. Keluar program" << endl;
        cout << "\nMasukkan Pilihan : ";
        cin >> pil;

        if (pil == 1) {
            cout << "\nMasukkan jumlah n: ";
            cin >> n;
            addedge(n);
            cout << "\nSimpul berhasil dibuat.";
            tekanEnter();
        } 
        else if (pil == 2) {
            cetakgraph(n);
            tekanEnter();
        } 
        else if (pil == 3) {
            cout << "\n--- Mencari Jalur Terpendek --- \n";
            cout << "Masukkan node asal = ";
            cin >> x;
            cout << "Masukkan node tujuan = ";
            cin >> y;
            searchpath(x, y);
            tekanEnter();
        } 
        else if (pil == 4) {
            cetakgraph(n);
            cout << "\nMenghapus Simpul = ";
            cin >> x;
            deleteVertex(x);
            tekanEnter();
        } 
        else if (pil == 5) {
            cetakgraph(n);
            cout << "\nMenghapus garis antara simpul ";
            cin >> x;
            cout << "Dengan simpul ";
            cin >> y;
            deleteEdge(x, y);
            tekanEnter();
        } 
        else if (pil == 6) {
            cout << "\nTerima kasih telah menggunakan program ini!\n";
            break; 
        } 
        else {
            cout << "\nInput yang anda masukkan salah.";
            // Mengatasi jika user tidak sengaja memasukkan huruf pada pilihan angka
            cin.clear();
            tekanEnter();
        }
    }
    return 0;
}
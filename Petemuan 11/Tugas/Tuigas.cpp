#include <iostream>
using namespace std;

const int MAX = 10;

//Jumlah titik / desa
int n = 4;

//Matriks sesuai soal (Jarak antar desa)
int jarakDesa[MAX][MAX] = {
    {0, 4, 1, 3},
    {4, 0, 2, 1},
    {1, 2, 0, 5},
    {3, 1, 5, 0}
};

// Status desa (dikunjungi atau belum)
bool diKunjungi[MAX];

// Menyimpan jalur terbaik
int bestPath[MAX + 1];
int tempPath[MAX + 1];

// Nilai awal minimum jarak
int jarakMinimal;

// Fungsi TSP (Traveling Salesman Problem) pakai rekursif
void tsp(int current, int start, int count, int jarakTotal) {
 
    // Jika semua node sudah dikunjungi
    if (count == n) {

        jarakTotal += jarakDesa[current][start];
        tempPath[count] = start;

        // Cek jarak minimalnya
        if (jarakTotal < jarakMinimal) {
            jarakMinimal = jarakTotal;

            // Simpan jalur terbaik
            for (int i = 0; i <= n; i++) {
                bestPath[i] = tempPath[i];
            }
        }
        return;
    }

    // Mengunjungi node lain
    for (int i = 0; i < n; i++) {

        if (!diKunjungi[i] && jarakDesa[current][i] != 0) {

            diKunjungi[i] = true;
            tempPath[count] = i;

            tsp(i, start, count + 1,
                jarakTotal + jarakDesa[current][i]);

            diKunjungi[i] = false;
        }
    }
}

int main() {
    int start;
    cout << "Jarak antar desa : \n";
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << jarakDesa[i][j] << "\t";
        }
        cout << endl;
    }

    //Titik awal tukang pos
    cout << "\nMasukkan titik awal (1-4): ";
    cin >> start;
    start--;

    diKunjungi[start] = true;
    tempPath[0] = start;

    tsp(start, start, 1, 0);

    cout << "\nJalur Terpendek : \n";

    for (int i = 0; i <= n; i++) {

        cout << bestPath[i] + 1;

        if (i != n) {
            cout << " ---> ";
        }
    }

    cout << "\n\nJarak terpendek : " << jarakMinimal;

    return 0;
}
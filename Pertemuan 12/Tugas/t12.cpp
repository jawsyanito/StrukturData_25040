#include <iostream>
#include <string>

using namespace std;

int main() {
    // Array sesuai soal
    string hewan[] = {"zebra", "ayam", "sapi", "kambing"};
    int n = 4;

    // Menampilkan array awal
    cout << "Array awal : ";
    for (int i = 0; i < n; i++) {
        cout << hewan[i] << " ";
    }
    cout << endl;

    // Selection Sort Descending
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            // Membandingkan string
            if (hewan[j] > hewan[maxIndex]) {
                maxIndex = j;
            }
        }

        // Tukar posisi
        string temp = hewan[i];
        hewan[i] = hewan[maxIndex];
        hewan[maxIndex] = temp;
    }

    // Menampilkan hasil sorting
    cout << "\nArray sesudah di sort (Descending) : ";
    for (int i = 0; i < n; i++) {
        cout << hewan[i] << " ";
    }

    return 0;
}
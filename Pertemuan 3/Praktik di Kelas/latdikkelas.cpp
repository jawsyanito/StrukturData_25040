#include <iostream>
using namespace std;
int main() {
	int data[2][2];

// Proses Input (Memasukkan nilai ke loker)
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			cout << "Masukkan angka untuk baris " << i << " kolom " << j << ": ";
			cin >> data[i][j];
		}
	}

// Proses Output (Menampilkan isi loker)
	cout << "\nIsi Array 2D:\n";
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j<2; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl; // Pindah baris
	}
}
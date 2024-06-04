#include <iostream>
#include <vector>
using namespace std;

// Definisi struct untuk menyimpan data
struct Data {
    int value;
};

// Fungsi untuk menukar dua elemen
void swap(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk melakukan Bubble Sort pada array dari Data
void bubbleSort(Data *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j].value > arr[j+1].value) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Fungsi untuk mencetak array
void printArray(Data *arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i].value << " ";
    }
    cout << endl;
}

int main() {
    system("CLS");

    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    
    Data *arr = new Data[n]; //digunakan untuk mendeklarasikan dan mengalokasikan memori secara dinamis untuk sebuah array berisi n elemen bertipe Data.
    cout << "Masukkan nilai-nilai elemen array:\n";
    for(int i = 0; i < n; i++) {
        cout << "Elemen " << i + 1 << ": ";
        cin >> arr[i].value;
    }
    
    cout << "Array sebelum sorting: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    
    cout << "Array setelah sorting: ";
    printArray(arr, n);

    system("\nPause");


    // Contoh penggunaan vector dari struct Data
    system("CLS");

    cout << "Masukkan jumlah elemen vektor: ";
    cin >> n;

    Data *arr2 = new Data[n];
    cout << "Masukkan nilai-nilai elemen vector:\n";
    for(int i = 0; i < n; i++) {
        cout << "Elemen " << i + 1 << ": ";
        cin >> arr2[i].value;
    }

    vector<Data> vec(arr2, arr2 + n); //menyalin elemen-elemen dari array arr2 sebanyak n elemen ke dalam vector vec.

    cout << "Vector sebelum sorting: ";
    for (Data &d : vec) { // iterasi melalui setiap elemen d dalam vec, di mana d adalah referensi ke elemen-elemen tersebut.
        cout << d.value << " "; 
    }
    cout << endl;

    bubbleSort(vec.data(), vec.size());

    cout << "Vector setelah sorting: ";
    for (Data& d : vec) { 
        cout << d.value << " ";
    }
    cout << endl;


    return 0;
}
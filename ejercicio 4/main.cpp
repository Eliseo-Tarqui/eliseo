#include <iostream>
using namespace std;

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++) {
        if (arr[j] < pivote) {
            i++;
            intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[alto]); 
    return i + 1;
}

void quicksort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto); 

        quicksort(arr, bajo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

int main() {
    int archivos[] = {850, 230, 690, 540, 310};
    int n = sizeof(archivos) / sizeof(archivos[0]);

    quicksort(archivos, 0, n - 1);

    cout << "Tamaños de archivos ordenados en orden ascendente: ";
    for (int i = 0; i < n; i++) {
        cout << archivos[i] << " ";
    }
    cout << endl;

    return 0;
}


#include <iostream>
using namespace std;

void fusionar(double arr[], int inicio, int mitad, int fin) {
    int n1 = mitad - inicio + 1;
    int n2 = fin - mitad;

    double izquierda[n1], derecha[n2];

    for (int i = 0; i < n1; i++) {
        izquierda[i] = arr[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        derecha[j] = arr[mitad + 1 + j];
    }

    int i = 0, j = 0;
    int k = inicio;
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        } else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}


void mergesort(double arr[], int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;

        mergesort(arr, inicio, mitad);
        mergesort(arr, mitad + 1, fin);

        fusionar(arr, inicio, mitad, fin);
    }
}

int main() {
    double tiempos[] = {30.5, 22.3, 45.6, 15.2, 28.4};
    int n = sizeof(tiempos) / sizeof(tiempos[0]);

    mergesort(tiempos, 0, n - 1);

    cout << "Tiempos de ejecución ordenados en orden ascendente: ";
    for (int i = 0; i < n; i++) {
        cout << tiempos[i] << " ";
    }
    cout << endl;

    return 0;
}


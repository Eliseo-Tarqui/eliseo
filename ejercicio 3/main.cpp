#include <iostream>
using namespace std;

int main() {
    int clics[] = {250, 120, 300, 95, 210};
    int n = sizeof(clics) / sizeof(clics[0]);

    for (int i = 1; i < n; i++) {
        int key = clics[i]; 
        int j = i - 1;

        while (j >= 0 && clics[j] > key) {
            clics[j + 1] = clics[j];
            j--;
        }
        
        clics[j + 1] = key;
    }

    cout << "Cantidad de clics ordenados en orden ascendente: ";
    for (int i = 0; i < n; i++) {
        cout << clics[i] << " ";
    }
    cout << endl;

    return 0;
}



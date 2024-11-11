#include <iostream>
using namespace std;

int main() {
    int tiempos[] = {125, 90, 150, 105, 80};
    int n = sizeof(tiempos) / sizeof(tiempos[0]);
    int intercambios = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tiempos[j] > tiempos[j + 1]) {
                int temp = tiempos[j];
                tiempos[j] = tiempos[j + 1];
                tiempos[j + 1] = temp;
                intercambios++;
            }
        }
    }

    cout << "Tiempos de respuesta ordenados en orden ascendente: ";
    for (int i = 0; i < n; i++) {
        cout << tiempos[i] << " ";
    }
    cout << endl;

    cout << "Número total de intercambios: " << intercambios << endl;

    return 0;
}


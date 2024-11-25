#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime> 

using namespace std;

// Función para leer números desde un
vector<int> leerNumerosDesdeArchivo(const string& nombreArchivo) {
    vector<int> numeros;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return numeros;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int numero;
        while (ss >> numero) {
            numeros.push_back(numero);
        }
    }
    archivo.close();
    return numeros;
}

// Función de búsqueda lineal
int busquedaLineal(const vector<int>& numeros, int objetivo) {
    for (size_t i = 0; i < numeros.size(); i++) {
        if (numeros[i] == objetivo) {
            return i; // Retorna el índice donde se encuentra el número
        }
    }
    return -1; // Retorna -1 si no se encuentra el número
}

// Función para simular búsqueda lineal en un conjunto de datos grande
int busquedaLinealSimulada(size_t tamanio, int objetivo, int& pasos) {
    pasos = 0; // Inicializar el contador de pasos
    for (size_t i = 0; i < tamanio; i++) {
        pasos++; // Incrementar pasos en cada iteración
        if (i == objetivo) {
            return i; // Retorna el índice donde se encuentra el número
        }
    }
    return -1; // Retorna -1 si no se encuentra el número
}

int main() {
    // Parte 1: Búsqueda lineal en números desde un archivo
    const string nombreArchivo = "numeros_aleatorios.txt";
    vector<int> numeros = leerNumerosDesdeArchivo(nombreArchivo);

    if (!numeros.empty()) {
        cout << "Archivo '" << nombreArchivo << "' leído correctamente. Total de números: " << numeros.size() << endl;

        int objetivo;
        cout << "Ingrese el número que desea buscar: ";
        cin >> objetivo;

        clock_t inicio = clock();
        int indice = busquedaLineal(numeros, objetivo);
        clock_t fin = clock();

        double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

        if (indice != -1) {
            cout << "Número encontrado en el índice " << indice << "." << endl;
        } else {
            cout << "Número no encontrado." << endl;
        }
        cout << "Tiempo de búsqueda: " << tiempo << " segundos." << endl;
    } else {
        cerr << "Error: No se encontraron números en el archivo o el archivo no existe." << endl;
    }

    // Parte 2: Simulación de búsqueda lineal
    vector<size_t> tamanios = {
        100, 1000, 10000, 100000, 1000000,
        10000000, 100000000, 1000000000
    };

    for (size_t tamanio : tamanios) {
        int objetivo = tamanio - 1; // Último elemento para probar el peor caso
        int pasos = 0;

        clock_t inicio = clock();
        int indice = busquedaLinealSimulada(tamanio, objetivo, pasos);
        clock_t fin = clock();

        double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

        cout << "Tamaño del conjunto: " << tamanio << endl;
        cout << "Número buscado: " << objetivo << endl;
        cout << "Número encontrado en el índice " << indice << "." << endl;
        cout << "Pasos realizados: " << pasos << endl;
        cout << "Tiempo de búsqueda: " << tiempo << " segundos." << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}

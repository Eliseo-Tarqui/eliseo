#include <fstream> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream> 

using namespace std;

int main() {
	
    ifstream inputFile("numeros_aleatorios.txt");
    if (!inputFile) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    cout << "Contenido del archivo:" << endl;
    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close();

    srand(time(NULL));

    clock_t start = clock();

    cout << "Ingrese un número del archivo para calcular su tiempo: ";
    int user_input;
    cin >> user_input;

    const int NUM_RANDOMS = 1000000; 
    int sum = 0;

    clock_t min_time = LONG_MAX;
    clock_t max_time = 0; 
    int min_rand = 0; 
    int max_rand = 0; 
    bool found = false;

    for (int i = 0; i < NUM_RANDOMS; ++i) {
        clock_t num_start = clock();
        int random_num = rand();
        sum += random_num;
        clock_t num_end = clock(); 
        
        clock_t time_taken = num_end - num_start; 
        
        if (time_taken < min_time) {
            min_time = time_taken;
            min_rand = random_num; 
        }
        
        if (time_taken > max_time) {
            max_time = time_taken;
            max_rand = random_num; 
        }

        if (random_num == user_input && !found) {
            cout << "El número " << user_input << " se encontró en el archivo." << endl;
            cout << "Tiempo para generar el número " << user_input << ": " << time_taken << " milisegundos" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "El número " << user_input << " no se encontró en el archivo." << endl;
    }

    clock_t end = clock();

    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Tiempo de ejecucion total: " << elapsed_time << " segundos." << endl;
    cout << "El número que tomo menos tiempo fue: " << min_rand << " con un tiempo de: " << min_time << " milisegundos" << endl;
    cout << "El número que tomo más tiempo fue: " << max_rand << " con un tiempo de: " << max_time << " milisegundos" << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nombre;  
    string codigo; 
    Node* next;         

    Node(string n, string c) : nombre(n), codigo(c), next(nullptr) {}
};

class LinkedList {
private:
    Node* head; 

public:
    LinkedList() : head(nullptr) {}

    void enqueue(string nombre, string codigo) {
        Node* newNode = new Node(nombre, codigo);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) { 
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void dequeue() {
        if (head == nullptr) { 
            cout << "No hay alumnos en la fila para matricularse." << endl;
            return;
        }
        Node* temp = head; 
        head = head->next; 
        cout << "Matriculando a: " << temp->nombre << " (Código: " << temp->codigo << ")" << endl;
        delete temp; 
    }

    void display() const {
        if (head == nullptr) {
            cout << "No hay alumnos en la fila para matricularse." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << "Nombre: " << current->nombre << ", Código: " << current->codigo << endl;
            current = current->next;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList fila;

    fila.enqueue("Ana Pérez", "20241001");
    fila.enqueue("Carlos López", "20241002");
    fila.enqueue("María Gómez", "20241003");

    cout << "Alumnos en la fila para matricularse:" << endl;
    fila.display();

    cout << "\nMatriculando al primer alumno:" << endl;
    fila.dequeue();

    cout << "\nAlumnos restantes en la fila para matricularse:" << endl;
    fila.display();

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> 


using namespace std;

struct Player {
    int id;
    string name;
    int score;
    Player* next;
};

Player* createNode(int id, string name, int score) {
    Player* newNode = new Player();
    newNode->id = id;
    newNode->name = name;
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Player*& head, int id, string name, int score) {
    Player* newNode = createNode(id, name, score);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Player* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

double calculateAverage(Player* head) {
    double sum = 0;
    int count = 0;
    Player* temp = head;
    while (temp != NULL) {
        sum += temp->score;
        count++;
        temp = temp->next;
    }
    return (count == 0) ? 0 : sum / count;
}

Player* findHighestScore(Player* head) {
    Player* highest = head;
    Player* temp = head;
    while (temp != NULL) {
        if (temp->score > highest->score) {
            highest = temp;
        }
        temp = temp->next;
    }
    return highest;
}

Player* findLowestScore(Player* head) {
    Player* lowest = head;
    Player* temp = head;
    while (temp != NULL) {
        if (temp->score < lowest->score) {
            lowest = temp;
        }
        temp = temp->next;
    }
    return lowest;
}

void removeBelowAverage(Player*& head, double average) {
    Player* temp = head;
    Player* prev = NULL;
    while (temp != NULL) {
        if (temp->score < average) {
            if (prev != NULL) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            Player* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    Player* head = NULL;
    ifstream inputFile("large_players.txt");
    string line;

    while (getline(inputFile, line)) {
        int id, score;
        string name;
        size_t firstSpace = line.find(' ');
        size_t lastSpace = line.rfind(' ');

        id = atoi(line.substr(0, firstSpace).c_str());
        name = line.substr(firstSpace + 1, lastSpace - firstSpace - 1);
        score = atoi(line.substr(lastSpace + 1).c_str());

        appendNode(head, id, name, score);
    }
    inputFile.close();

    double average = calculateAverage(head);
    cout << "Puntuación Promedio: " << average << endl;

    Player* highest = findHighestScore(head);
    Player* lowest = findLowestScore(head);

    cout << "Mayor Puntuacion: PlayerID=" << highest->id << ", PlayerName=" << highest->name
         << ", Score=" << highest->score << endl;
    cout << "Menor Puntuación: PlayerID=" << lowest->id << ", PlayerName=" << lowest->name
         << ", Score=" << lowest->score << endl;

    clock_t start = clock();
    removeBelowAverage(head, average);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo para eliminar jugadores por debajo del promedio: " << elapsed << " segundos" << endl;

    return 0;
}

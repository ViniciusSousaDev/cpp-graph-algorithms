#include <iostream>
using namespace std;

#define MAX 100

int matriz[MAX][MAX];
int vertices;

void inicializar() {
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            matriz[i][j] = 0;
        }
    }
}

void adicionarAresta(int v1, int v2) {
    matriz[v1][v2] = 1;
    matriz[v2][v1] = 1; // grafo não direcionado
}

void mostrarMatriz() {
    cout << "\nMatriz de Adjacencia:\n";

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    cout << "Numero de vertices: ";
    cin >> vertices;

    inicializar();

    int arestas;
    cout << "Numero de arestas: ";
    cin >> arestas;

    for(int i = 0; i < arestas; i++) {
        int v1, v2;

        cout << "Aresta " << i+1 << " (v1 v2): ";
        cin >> v1 >> v2;

        adicionarAresta(v1, v2);
    }

    mostrarMatriz();

    return 0;
}
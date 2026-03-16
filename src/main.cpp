#include <iostream>
#include <queue>

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
    matriz[v2][v1] = 1;
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

void BFS(int inicio) {

    bool visitado[MAX] = {false};
    queue<int> fila;

    visitado[inicio] = true;
    fila.push(inicio);

    cout << "\nBFS: ";

    while(!fila.empty()) {

        int atual = fila.front();
        fila.pop();

        cout << atual << " ";

        for(int i = 0; i < vertices; i++) {
            if(matriz[atual][i] == 1 && !visitado[i]) {
                visitado[i] = true;
                fila.push(i);
            }
        }
    }

    cout << endl;
}

void DFS(int v, bool visitado[]) {

    visitado[v] = true;
    cout << v << " ";

    for(int i = 0; i < vertices; i++) {
        if(matriz[v][i] == 1 && !visitado[i]) {
            DFS(i, visitado);
        }
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

    int inicio;

    cout << "\nVertice inicial para BFS e DFS: ";
    cin >> inicio;

    BFS(inicio);

    bool visitado[MAX] = {false};

    cout << "\nDFS: ";
    DFS(inicio, visitado);

    cout << endl;

    return 0;
}
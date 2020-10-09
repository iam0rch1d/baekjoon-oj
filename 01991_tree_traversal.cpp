#include <cstring>
#include <iostream>

using namespace std;

char adjacentVerticesOf[26][2];

void dfsPreorder(char currentVertex) {
    cout << currentVertex;

    for (char adjacentVertex : adjacentVerticesOf[currentVertex - 'A']) {
        if (adjacentVertex != '.') {
            dfsPreorder(adjacentVertex);
        }
    }
}

void dfsInorder(char currentVertex) {
    if (adjacentVerticesOf[currentVertex - 'A'][0] != '.') {
        dfsInorder(adjacentVerticesOf[currentVertex - 'A'][0]);
    }

    cout << currentVertex;

    if (adjacentVerticesOf[currentVertex - 'A'][1] != '.') {
        dfsInorder(adjacentVerticesOf[currentVertex - 'A'][1]);
    }
}

void dfsPostorder(char currentVertex) {
    for (char adjacentVertex : adjacentVerticesOf[currentVertex - 'A']) {
        if (adjacentVertex != '.') {
            dfsPostorder(adjacentVertex);
        }
    }

    cout << currentVertex;
}

int main() {
    int numVertex;

    cin >> numVertex;

    for (int i = 0; i < numVertex; i++) {
        char currentVertex;

        cin >> currentVertex >> adjacentVerticesOf[currentVertex - 'A'][0] >> adjacentVerticesOf[currentVertex - 'A'][1];
    }

    dfsPreorder('A');

    cout << '\n';

    dfsInorder('A');

    cout << '\n';

    dfsPostorder('A');

    cout << '\n';

    return 0;
}

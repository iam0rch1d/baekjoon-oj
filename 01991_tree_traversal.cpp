#include <cstring>
#include <iostream>

using namespace std;

char adjacentVerticesOf[26][2];

void dfsTreePreorder(char currentVertex) {
    cout << currentVertex;

    for (char adjacentVertex : adjacentVerticesOf[currentVertex - 'A']) {
        if (adjacentVertex != '.') {
            dfsTreePreorder(adjacentVertex);
        }
    }
}

void dfsTreeInorder(char currentVertex) {
    if (adjacentVerticesOf[currentVertex - 'A'][0] != '.') {
        dfsTreeInorder(adjacentVerticesOf[currentVertex - 'A'][0]);
    }

    cout << currentVertex;

    if (adjacentVerticesOf[currentVertex - 'A'][1] != '.') {
        dfsTreeInorder(adjacentVerticesOf[currentVertex - 'A'][1]);
    }
}

void dfsTreePostorder(char currentVertex) {
    for (char adjacentVertex : adjacentVerticesOf[currentVertex - 'A']) {
        if (adjacentVertex != '.') {
            dfsTreePostorder(adjacentVertex);
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

    dfsTreePreorder('A');

    cout << '\n';

    dfsTreeInorder('A');

    cout << '\n';

    dfsTreePostorder('A');

    cout << '\n';

    return 0;
}

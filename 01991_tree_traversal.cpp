#include <cstring>
#include <iostream>

using namespace std;

char childVertices[26][2];

void dfsPreorder(char currentVertex) {
    cout << currentVertex;

    for (char childVertex : childVertices[currentVertex - 'A']) {
        if (childVertex != '.') {
            dfsPreorder(childVertex);
        }
    }
}

void dfsInorder(char currentVertex) {
    if (childVertices[currentVertex - 'A'][0] != '.') {
        dfsInorder(childVertices[currentVertex - 'A'][0]);
    }

    cout << currentVertex;

    if (childVertices[currentVertex - 'A'][1] != '.') {
        dfsInorder(childVertices[currentVertex - 'A'][1]);
    }
}

void dfsPostorder(char currentVertex) {
    for (char childVertex : childVertices[currentVertex - 'A']) {
        if (childVertex != '.') {
            dfsPostorder(childVertex);
        }
    }

    cout << currentVertex;
}

int main() {
    int numVertex;

    cin >> numVertex;

    for (int i = 0; i < numVertex; i++) {
        char currentVertex;

        cin >> currentVertex >> childVertices[currentVertex - 'A'][0] >> childVertices[currentVertex - 'A'][1];
    }

    dfsPreorder('A');

    cout << '\n';

    dfsInorder('A');

    cout << '\n';

    dfsPostorder('A');

    cout << '\n';

    return 0;
}

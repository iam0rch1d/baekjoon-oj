#include <cstring>
#include <iostream>

using namespace std;

char childVerticesOf[26][2];

void printPreorder(char currentVertex) {
    cout << currentVertex;

    for (char childVertex : childVerticesOf[currentVertex - 'A']) {
        if (childVertex != '.') printPreorder(childVertex);
    }
}

void printInorder(char currentVertex) {
    if (childVerticesOf[currentVertex - 'A'][0] != '.') printInorder(childVerticesOf[currentVertex - 'A'][0]);

    cout << currentVertex;

    if (childVerticesOf[currentVertex - 'A'][1] != '.') printInorder(childVerticesOf[currentVertex - 'A'][1]);

}

void printPostorder(char currentVertex) {
    for (char childVertex : childVerticesOf[currentVertex - 'A']) {
        if (childVertex != '.') printPostorder(childVertex);
    }

    cout << currentVertex;
}

int main() {
    int numVertex;

    cin >> numVertex;

    for (int i = 0; i < numVertex; i++) {
        char currentVertex;

        cin >> currentVertex >> childVerticesOf[currentVertex - 'A'][0] >> childVerticesOf[currentVertex - 'A'][1];
    }

    printPreorder('A');

    cout << '\n';

    printInorder('A');

    cout << '\n';

    printPostorder('A');

    cout << '\n';

    return 0;
}

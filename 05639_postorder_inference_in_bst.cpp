#include <iostream>
#include <vector>

using namespace std;

typedef struct Vertex {
    int key {};
    Vertex *leftChildVertex = nullptr;
    Vertex *rightChildVertex = nullptr;
} Vertex;

int insertedVertexCount;
Vertex *root;

void insertVertex(int key) {
    auto *vertex = new Vertex{key};

    if (insertedVertexCount == 0) {
        root = vertex;
    } else {
        Vertex *parent = root;

        while (true) {
            if (key >= parent->key) {
                if (parent->rightChildVertex == nullptr) {
                    parent->rightChildVertex = vertex;

                    break;
                }

                parent = parent->rightChildVertex;
            } else {
                if (parent->leftChildVertex == nullptr) {
                    parent->leftChildVertex = vertex;

                    break;
                }

                parent = parent->leftChildVertex;
            }
        }
    }

    insertedVertexCount++;
}

void dfsPostorder(Vertex *current) {
    if (current) {
        dfsPostorder(current->leftChildVertex);
        dfsPostorder(current->rightChildVertex);

        cout << current->key << '\n';
    }
}

int main() {
    int key;

    while (cin >> key) {
        insertVertex(key);
    }

    dfsPostorder(root);

    return 0;
}

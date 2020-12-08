#include <iostream>

using namespace std;

struct Vertex {
    int value{};
    Vertex *leftChild = nullptr;
    Vertex *rightChild = nullptr;
};

void dfsPostorder(Vertex *current) {
    if (current) {
        dfsPostorder(current->leftChild);
        dfsPostorder(current->rightChild);

        cout << current->value << '\n';
    }
}

int main() {
    int value;
    Vertex *root = nullptr;

    while (cin >> value) {
        if (!root) root = new Vertex{value};
        else {
            Vertex *current = root;

            while (true) {
                if (value > current->value) {
                    if (!current->rightChild) {
                        current->rightChild = new Vertex{value};

                        break;
                    }

                    current = current->rightChild;
                } else {
                    if (!current->leftChild) {
                        current->leftChild = new Vertex{value};

                        break;
                    }

                    current = current->leftChild;
                }
            }
        }
    }

    dfsPostorder(root);

    return 0;
}

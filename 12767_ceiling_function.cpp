#include <iostream>
#include <set>

using namespace std;

struct Vertex {
    int value{};
    Vertex *leftChild = nullptr;
    Vertex *rightChild = nullptr;
};

string dfsPreorder(Vertex *root) {
    string preorder = "V";

    if (root->leftChild) preorder += 'L' + dfsPreorder(root->leftChild) + 'l';

    if (root->rightChild) preorder += 'R' + dfsPreorder(root->rightChild) + 'r';

    return preorder += 'v';
}

void bstRemove(Vertex *root) {
    if (root->leftChild) bstRemove(root->leftChild);

    if (root->rightChild) bstRemove(root->rightChild);

    delete root;
}

int main() {
    int n;
    int k;
    set<string> preorders;

    cin >> n >> k;

    while (n--) {
        int rootValue;

        cin >> rootValue;

        auto *root = new Vertex{rootValue};

        for (int i = 1; i < k; i++) {
            int value;
            auto *current = root;

            cin >> value;

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

        preorders.insert(dfsPreorder(root));
        bstRemove(root);
    }

    cout << preorders.size() << '\n';

    return 0;
}

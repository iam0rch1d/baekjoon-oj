#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int parents[100001];

void dfsTree(int currentNode) {
    for (int nextNode : tree[currentNode]) {
        if (nextNode != parents[currentNode]) {
            parents[nextNode] = currentNode;

            dfsTree(nextNode);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numNode;

    cin >> numNode;

    for (int i = 0; i < numNode - 1; i++) {
        int fromNode;
        int toNode;

        cin >> fromNode >> toNode;

        tree[fromNode].push_back(toNode);
        tree[toNode].push_back(fromNode);
    }

    dfsTree(1);

    for (int i = 2; i <= numNode; i++) {
        cout << parents[i] << "\n";
    }

    return 0;
}

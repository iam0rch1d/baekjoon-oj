#include <iostream>
#include <vector>

using namespace std;

int childVerticesOf[10001][2];
bool hasParent[10001];
vector<int> ordersAt[10001];
int order;
int maxDepth;

void dfsInorder(int vertex, int depth) {
    if (childVerticesOf[vertex][0] != -1) dfsInorder(childVerticesOf[vertex][0], depth + 1);

    ordersAt[depth].push_back(++order);
    maxDepth = max(maxDepth, depth);

    if (childVerticesOf[vertex][1] != -1) dfsInorder(childVerticesOf[vertex][1], depth + 1);
}

int main() {
    int n;
    int rootVertex = 0;
    int depthWithMaxBreadth = 0;
    int maxBreadth = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int vertex;

        cin >> vertex >> childVerticesOf[vertex][0] >> childVerticesOf[vertex][1];

        if (childVerticesOf[vertex][0] != -1) hasParent[childVerticesOf[vertex][0]] = true;

        if (childVerticesOf[vertex][1] != -1) hasParent[childVerticesOf[vertex][1]] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!hasParent[i]) {
            rootVertex = i;

            break;
        }
    }

    dfsInorder(rootVertex, 1);

    for (int i = 1; i <= maxDepth; i++) {
        if (maxBreadth < ordersAt[i].back() - ordersAt[i][0] + 1) {
            depthWithMaxBreadth = i;
            maxBreadth = ordersAt[i].back() - ordersAt[i][0] + 1;
        }
    }

    cout << depthWithMaxBreadth << ' ' << maxBreadth << '\n';

    return 0;
}

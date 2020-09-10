#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int inorderTraversal[100001];
int inorderIndexOf[100001];
int postorderTraversal[100001];

void dfsPreorder(pair<int, int> inorderInterval, pair<int, int> postorderInterval) {
    if (inorderInterval.first >= inorderInterval.second || postorderInterval.first >= postorderInterval.second) return;

    int rootVertex = postorderTraversal[postorderInterval.second - 1];
    int inorderRootIndex = inorderIndexOf[rootVertex];
    int leftSubtreeSize = inorderRootIndex - inorderInterval.first;

    cout << rootVertex << " ";

    dfsPreorder({inorderInterval.first, inorderRootIndex},
                {postorderInterval.first, postorderInterval.first + leftSubtreeSize});
    dfsPreorder({inorderRootIndex + 1, inorderInterval.second},
                {postorderInterval.first + leftSubtreeSize, postorderInterval.second - 1});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numVertex;

    cin >> numVertex;

    for (int i = 0; i < numVertex; i++) {
        cin >> inorderTraversal[i];

        inorderIndexOf[inorderTraversal[i]] = i;
    }

    for (int i = 0; i < numVertex; i++) {
        cin >> postorderTraversal[i];
    }

    dfsPreorder({0, numVertex}, {0, numVertex});

    cout << "\n";

    return 0;
}

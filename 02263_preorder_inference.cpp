#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int inorder[100000];
int inorderIndices[100000];
int postorder[100000];

void dncPreorder(int inorderLeft, int inorderRight, int postorderLeft, int postorderRight) {
    if (inorderLeft > inorderRight || postorderLeft > postorderRight) return;

    int rootVertex = postorder[postorderRight];
    int rootInorderIndex = inorderIndices[rootVertex];
    int leftSubtreeSize = rootInorderIndex - inorderLeft;

    cout << rootVertex << ' ';

    dncPreorder(inorderLeft, rootInorderIndex - 1, postorderLeft, postorderLeft + leftSubtreeSize - 1);
    dncPreorder(rootInorderIndex + 1, inorderRight, postorderLeft + leftSubtreeSize, postorderRight - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];

        inorderIndices[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    dncPreorder(0, n - 1, 0, n - 1);

    cout << '\n';

    return 0;
}

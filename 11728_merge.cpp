#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vector<int> mergedArray(n + m);

    for (int &element : mergedArray) {
        cin >> element;
    }

    sort(mergedArray.begin(), mergedArray.end());

    for (int element : mergedArray) {
        cout << element << ' ';
    }

    cout << '\n';

    return 0;
}

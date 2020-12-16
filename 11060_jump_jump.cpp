#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void chmin(T &m, T q) {
    m = min(m, q);
}

#define INF 987654321

int main() {
    int n;

    cin >> n;

    vector<int> a(n);
    vector<int> minJumpCountCache(n, INF);

    for (int &ai : a) {
        cin >> ai;
    }

    minJumpCountCache[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            if (i + j >= n) break;

            chmin(minJumpCountCache[i + j], minJumpCountCache[i] + 1);
        }
    }

    cout << (minJumpCountCache[n - 1] == INF ? -1 : minJumpCountCache[n - 1]) << '\n';

    return 0;
}

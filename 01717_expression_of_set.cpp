#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_UF_SIZE 1000001

int parents[MAX_UF_SIZE];
int ranks[MAX_UF_SIZE];

int ufFind(int x) {
    return x == parents[x] ? x : (parents[x] = ufFind(parents[x]));
}

void ufUnion(int x, int y) {
    x = ufFind(x);
    y = ufFind(y);

    if (x == y) return;

    if (ranks[x] < ranks[y]) swap(x, y);

    parents[y] = x;

    if (ranks[x] == ranks[y]) ranks[x] = ranks[y] + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    for_each(parents + 1, parents + n + 1, [](int &i) { static int n; i = ++n; });

    while (m--) {
        int query;
        int a;
        int b;

        cin >> query >> a >> b;

        if (!query) ufUnion(a, b);
        else cout << (ufFind(a) == ufFind(b) ? "YES\n" : "NO\n");
    }

    return 0;
}

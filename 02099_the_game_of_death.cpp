#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

typedef vvl Matrix;

Matrix operator*=(Matrix &a, Matrix &b) {
    int size = a.size();
    Matrix ret(size, vl(size, 0));

    REP(i, size) REP(j, size) REP(k, size) ret[i][j] += a[i][k] * b[k][j];

    return a = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;
    int m;

    cin >> n >> k >> m;

    Matrix adjacency(n, vl(n, 0));

    REP(i, n) {
        int x;
        int y;

        cin >> x >> y;

        --x;
        --y;

        adjacency[i][x] = 1;
        adjacency[i][y] = 1;
    }

    Matrix powerAdjacency(n, vl(n, 0));

    REP(i, n) powerAdjacency[i][i] = 1;

    while (k) {
        if (k % 2) powerAdjacency *= adjacency;

        adjacency *= adjacency;
        k /= 2;
    }

    while (m--) {
        int a;
        int b;

        cin >> a >> b;

        --a;
        --b;

        PRINTLN(powerAdjacency[a][b] ? "death" : "life");
    }

    return 0;
}

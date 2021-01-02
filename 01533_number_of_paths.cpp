#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000003
#define SPLITS 5

typedef vvl Matrix;

Matrix operator*=(Matrix &a, Matrix &b) {
    int size = a.size();
    Matrix ret(size, vl(size, 0));

    REP(i, size) REP(j, size) REP(k, size) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j] % MODULO) % MODULO;

    return a = ret;
}

int main() {
    int n;
    int s;
    int e;
    ll t;

    cin >> n >> s >> e >> t;

    Matrix adjacency(n * SPLITS, vl(n * SPLITS));

    REP(i, n * SPLITS - 1) {
        if (i % SPLITS == 4) continue;

        adjacency[i][i + 1] = 1;
    }

    auto mapVertexSplit = [&](int vertex, int time) {
        return vertex * SPLITS + time;
    };

    REP(i, n) {
        string temp;

        cin >> temp;

        REP(j, n) {
            int time = temp[j] - '0';

            // (i, time - 1) -> (j, 0)
            if (time) adjacency[mapVertexSplit(i, time - 1)][mapVertexSplit(j, 0)] = 1;
        }
    }

    Matrix powerAdjacency(n * SPLITS, vl(n * SPLITS));

    REP(i, n * SPLITS) powerAdjacency[i][i] = 1;

    while (t) {
        if (t % 2) powerAdjacency *= adjacency;

        adjacency *= adjacency;
        t /= 2;
    }

    --s;
    --e;

    PRINTLN(powerAdjacency[mapVertexSplit(s, 0)][mapVertexSplit(e, 0)]);

    return 0;
}

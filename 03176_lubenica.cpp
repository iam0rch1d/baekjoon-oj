#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvi = vector<vi>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define SIZE 100001
#define MAX_POWER 18

vpii edgesOf[SIZE];
int depths[SIZE];
int dpAncestor[SIZE][MAX_POWER];
int dpMinCost[SIZE][MAX_POWER];
int dpMaxCost[SIZE][MAX_POWER];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    REP(i, n - 1) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        edgesOf[a].emplace_back(b, c);
        edgesOf[b].emplace_back(a, c);
    }

    RESET(depths, -1);

    queue<int> bfsVertices;

    depths[1] = 0;

    bfsVertices.push(1);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (pii edge : edgesOf[currentVertex]) {
            if (depths[edge.F] == -1) {
                depths[edge.F] = depths[currentVertex] + 1;
                dpAncestor[edge.F][0] = currentVertex;  // Parent
                dpMinCost[edge.F][0] = edge.S;
                dpMaxCost[edge.F][0] = edge.S;

                bfsVertices.push(edge.F);
            }
        }
    }

    for (int j = 1; (1 << j) <= n; j++) {
        FOR_(i, 1, n) {
            if (dpAncestor[i][j - 1]) {
                dpAncestor[i][j] = dpAncestor[dpAncestor[i][j - 1]][j - 1];
                dpMinCost[i][j] = dpMinCost[i][j - 1];
                dpMaxCost[i][j] = dpMaxCost[i][j - 1];

                if (dpAncestor[dpAncestor[i][j - 1]][j - 1]) {
                    chmin(dpMinCost[i][j], dpMinCost[dpAncestor[i][j - 1]][j - 1]);
                    chmax(dpMaxCost[i][j], dpMaxCost[dpAncestor[i][j - 1]][j - 1]);
                }
            }
        }
    }

    auto lcaCost = [&](int u, int v) {
        pii ret{987654321, 0};  // (<Min-cost>, <Max-cost>)

        if (depths[u] < depths[v]) swap(u, v);

        int power = 0;

        while ((1 << power) <= depths[u]) power++;

        IFOR(i, 0, power) {
            if (depths[u] - (1 << i) >= depths[v]) {
                chmin(ret.F, dpMinCost[u][i]);
                chmax(ret.S, dpMaxCost[u][i]);

                u = dpAncestor[u][i];
            }
        }

        if (u == v) return ret;

        IFOR(i, 0, power) {
            if (dpAncestor[u][i] && dpAncestor[u][i] != dpAncestor[v][i]) {
                chmin(ret.F, min(dpMinCost[u][i], dpMinCost[v][i]));
                chmax(ret.S, max(dpMaxCost[u][i], dpMaxCost[v][i]));

                u = dpAncestor[u][i];
                v = dpAncestor[v][i];
            }
        }

        chmin(ret.F, min(dpMinCost[u][0], dpMinCost[v][0]));
        chmax(ret.S, max(dpMaxCost[u][0], dpMaxCost[v][0]));

        return ret;
    };

    int k;

    cin >> k;

    while (k--) {
        int d;
        int e;

        cin >> d >> e;

        pii ans = lcaCost(d, e);

        PRINT(ans.F);
        PRINTLN(ans.S);
    }

    return 0;
}

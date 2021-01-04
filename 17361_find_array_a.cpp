#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vi b(n);

    REP(i, n) cin >> b[i];

    // Topological sort
    vvi nextVerticesOf(n);
    vvi prevVerticesOf(n);
    vi indegrees(n, 0);

    while (m--) {
        int i;
        int j;

        cin >> i >> j;

        --i;
        --j;

        nextVerticesOf[i].push_back(j);
        prevVerticesOf[j].push_back(i);

        indegrees[j]++;
    }

    queue<int> bfsVertices;
    vi orders;

    REP(i, n) if (!indegrees[i]) bfsVertices.push(i);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        orders.push_back(currentVertex);
        bfsVertices.pop();

        for (int nextVertex : nextVerticesOf[currentVertex]) {
            if (--indegrees[nextVertex] == 0) bfsVertices.push(nextVertex);
        }
    }

    if (orders.size() != n) {
        PRINTLN(-1);

        return 0;
    }

    // Binary search of k
    int kLeft = 0;
    int kRight = n - 1;
    int k = n;
    auto cmp = [&](int k) {
        vi aTemp(n);

        IFOR(i, 0, n) {
            int vertex = orders[i];

            aTemp[vertex] = 1000000000;

            for (int nextVertex : nextVerticesOf[vertex]) {
                chmin(aTemp[vertex], aTemp[nextVertex] - 1);
            }

            if (vertex < k) {
                if (aTemp[vertex] < b[vertex]) return false;

                aTemp[vertex] = b[vertex];
            }

            if (aTemp[vertex] <= 0) return false;
        }

        REP(i, n) {
            if (aTemp[i] > b[i]) return true;

            if (aTemp[i] < b[i]) return false;
        }

        return true;
    };

    while (kLeft <= kRight) {
        int kMid = (kLeft + kRight) / 2;

        if (cmp(kMid)) {
            k = kMid;
            kLeft = kMid + 1;
        } else kRight = kMid - 1;
    }

    // Construct A
    vi a(n);

    FOR(i, 0, n) {
        int vertex = orders[i];

        a[vertex] = 1;

        for (int prevVertex : prevVerticesOf[vertex]) {
            chmax(a[vertex], a[prevVertex] + 1);
        }

        if (vertex < k) a[vertex] = b[vertex];
        else if (vertex == k) chmax(a[vertex], b[vertex] + 1);
    }

    REP(i, n) PRINT(a[i]);

    PRINTLN("");

    return 0;
}

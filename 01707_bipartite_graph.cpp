#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

vector<int> adjacentVerticesOf[20001];
int colors[20001];

bool dfs(int vertex, int color) {
    colors[vertex] = color;

    return none_of(ALL(adjacentVerticesOf[vertex]),
                   [&](int adjacentVertex) {
                       return (colors[adjacentVertex] == 0 && !dfs(adjacentVertex, 3 - color))
                              || (colors[adjacentVertex] == colors[vertex]);
                   });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    auto solve = []() {
        int v;
        int e;
        bool ans = true;

        cin >> v >> e;

        while (e--) {
            int x;
            int y;

            cin >> x >> y;

            adjacentVerticesOf[x].push_back(y);
            adjacentVerticesOf[y].push_back(x);
        }

        FOR_(i, 1, v) {
            if (colors[i] == 0 && !dfs(i, 1)) {
                ans = false;

                break;
            }
        }

        FOR_(i, 1, v) adjacentVerticesOf[i].clear();

        memset(colors, 0, sizeof(colors));

        return ans;
    };

    while (tc--) PRINTLN(solve() ? "YES" : "NO");

    return 0;
}

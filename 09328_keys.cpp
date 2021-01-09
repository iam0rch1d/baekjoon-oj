#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vstr = vector<string>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int tc;

    cin >> tc;

    auto solve = []() {
        int h;
        int w;

        cin >> h >> w;

        vstr a(h + 4);

        a[0] = string(w + 4, '*');
        a[1] = '*' + string(w + 2, '.') + '*';
        a[h + 2] = '*' + string(w + 2, '.') + '*';
        a[h + 3] = string(w + 4, '*');

        FOR_(i, 2, h + 1) {
            cin >> a[i];

            a[i] = "*." + a[i] + ".*";
        }

        string keys;
        map<char, bool> hasKey;

        REP(i, 26) hasKey[(char) ('a' + i)] = false;

        cin >> keys;

        if (keys != "0") {
            for (char key : keys) {
                hasKey[key] = true;
            }
        }

        vvb isVisited(h + 4, vb(w + 4, false));
        queue<pii> bfsVertices;
        map<char, queue<pii>> verticesInFrontOf;

        isVisited[1][1] = true;

        bfsVertices.emplace(1, 1);

        int ret = 0;

        while (!bfsVertices.empty()) {
            int y;
            int x;

            tie(y, x) = bfsVertices.front();

            bfsVertices.pop();

            REP(i, 4) {
                int ny = y + "1201"[i] - '1';
                int nx = x + "0112"[i] - '1';

                if (isVisited[ny][nx] || a[ny][nx] == '*') continue;

                if (a[ny][nx] == '.') {  // Empty space
                    isVisited[ny][nx] = true;

                    bfsVertices.emplace(ny, nx);
                } else if (a[ny][nx] == '$') {  // Money
                    isVisited[ny][nx] = true;
                    ret++;

                    bfsVertices.emplace(ny, nx);
                } else if (a[ny][nx] >= 'A' && a[ny][nx] <= 'Z') {  // Door
                    if (hasKey[(char) (a[ny][nx] - 'A' + 'a')]) {
                        isVisited[ny][nx] = true;

                        bfsVertices.emplace(ny, nx);
                    } else verticesInFrontOf[a[ny][nx]].emplace(y, x);
                } else if (a[ny][nx] >= 'a' && a[ny][nx] <= 'z') {  // Key
                    isVisited[ny][nx] = true;
                    hasKey[a[ny][nx]] = true;

                    char door = (char) (a[ny][nx] - 'a' + 'A');

                    while (!verticesInFrontOf[door].empty()) {
                        bfsVertices.push(verticesInFrontOf[door].front());
                        verticesInFrontOf[door].pop();
                    }

                    bfsVertices.emplace(ny, nx);
                }
            }
        }

        return ret;
    };

    while (tc--) PRINTLN(solve());

    return 0;
}

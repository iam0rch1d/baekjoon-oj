#include <iostream>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[4000];
bool isAdjacent[4000][4000];
int degrees[4000];

int main() {
    int n;
    int m;
    int minTotalRelations = 8001;

    cin >> n >> m;

    while (m--) {
        int a;
        int b;

        cin >> a >> b;

        a--;
        b--;

        adjacentVerticesOf[a].push_back(b);
        adjacentVerticesOf[b].push_back(a);
        isAdjacent[a][b] = true;
        isAdjacent[b][a] = true;
        degrees[a]++;
        degrees[b]++;
    }

    for (int a = 0; a < n - 2; a++) {
        for (int b : adjacentVerticesOf[a]) {
            if (b < a) continue;

            for (int c : adjacentVerticesOf[b]) {
                if (c < b || !isAdjacent[c][a]) continue;

                minTotalRelations = min(minTotalRelations, degrees[a] + degrees[b] + degrees[c] - 6);
            }
        }
    }

    cout << (minTotalRelations == 8001 ? -1 : minTotalRelations) << '\n';

    return 0;
}

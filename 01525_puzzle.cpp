#include <iostream>
#include <map>
#include <queue>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int numbers[9];
    int startVertex = 0;

    for (int number : numbers) {
        cin >> number;

        startVertex = startVertex * 10 + (number ? number : 9);
    }

    map<int, int> distances;
    queue<int> bfsVertices;

    distances[startVertex] = 0;

    bfsVertices.push(startVertex);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        if (currentVertex == 123456789) {
            PRINTLN(distances[currentVertex]);

            return 0;
        }

        string currentVertexString = to_string(currentVertex);
        int empty = currentVertexString.find('9');
        int y = empty / 3;
        int x = empty % 3;

        bfsVertices.pop();

        REP(i, 4) {
            string adjacentVertexString(currentVertexString);
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue;

            swap(adjacentVertexString[empty], adjacentVertexString[ny * 3 + nx]);

            int adjacentVertex = stoi(adjacentVertexString);

            if (!distances.count(adjacentVertex)) {
                distances[adjacentVertex] = distances[currentVertex] + 1;

                bfsVertices.push(adjacentVertex);
            }
        }
    }

    PRINTLN(-1);

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int timeCount[100001];

int main() {
    int source;
    int destination;
    queue<int> bfsQueue;

    cin >> source >> destination;

    timeCount[source] = 1;

    bfsQueue.push(source);

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        int adjacents[3] = {current + 1, current - 1, 2 * current};

        if (current == destination) {
            cout << timeCount[current] - 1 << '\n';

            return 0;
        }

        bfsQueue.pop();

        for (int adjacent : adjacents) {
            if (adjacent >= 0 && adjacent <= 100000 && !timeCount[adjacent]) {
                timeCount[adjacent] = timeCount[current] + 1;

                bfsQueue.push(adjacent);
            }
        }
    }
}

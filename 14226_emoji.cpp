#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int cache[1001][1001];

int main() {
    int s;
    queue<pair<int, int>> bfsEmojis;  // .first = <current emoji>, .second = <emoji on clipboard>

    memset(cache, -1, sizeof(cache));

    cin >> s;

    cache[1][0] = 0;

    bfsEmojis.push({1, 0});

    while (!bfsEmojis.empty()) {
        pair<int, int> currentEmoji = bfsEmojis.front();

        if (currentEmoji.first == s) {
            cout << cache[currentEmoji.first][currentEmoji.second] << '\n';

            return 0;
        }

        bfsEmojis.pop();

        pair<int, int> adjacentEmojis[] = {{currentEmoji.first,                       currentEmoji.first},
                                           {currentEmoji.first + currentEmoji.second, currentEmoji.second},
                                           {currentEmoji.first - 1,                   currentEmoji.second}};

        for (auto adjacentEmoji : adjacentEmojis) {
            if (adjacentEmoji.first < 0
                || adjacentEmoji.first > 1000
                || adjacentEmoji.second < 0
                || adjacentEmoji.second > 1000
                || cache[adjacentEmoji.first][adjacentEmoji.second] != -1) {
                continue;
            }

            cache[adjacentEmoji.first][adjacentEmoji.second] = cache[currentEmoji.first][currentEmoji.second] + 1;

            bfsEmojis.push(adjacentEmoji);
        }
    }
}

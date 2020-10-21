#include <cstring>
#include <iostream>
#include <queue>

#define UNMEMOIZED -1

using namespace std;

int timeCache[1001][1001];

int main() {
    int s;
    queue<pair<int, int>> bfsEmojis;  // .first = <current emoji>, .second = <emoji on clipboard>

    memset(timeCache, UNMEMOIZED, sizeof(timeCache));

    cin >> s;

    timeCache[1][0] = 0;

    bfsEmojis.push({1, 0});

    while (!bfsEmojis.empty()) {
        pair<int, int> currentEmoji = bfsEmojis.front();

        if (currentEmoji.first == s) {
            cout << timeCache[currentEmoji.first][currentEmoji.second] << '\n';

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
                || timeCache[adjacentEmoji.first][adjacentEmoji.second] != UNMEMOIZED) {
                continue;
            }

            timeCache[adjacentEmoji.first][adjacentEmoji.second] = timeCache[currentEmoji.first][currentEmoji.second]
                                                                   + 1;

            bfsEmojis.push(adjacentEmoji);
        }
    }
}

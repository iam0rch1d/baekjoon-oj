#include <iostream>
#include <stack>

using namespace std;

bool isExploded[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    string explosion;
    int sSize;
    int explosionSize;
    stack<pair<int, int>> explosionPieces;
    bool hasLeft = false;

    cin >> s >> explosion;

    sSize = s.size();
    explosionSize = explosion.size();

    if (explosionSize == 1) {
        for (int i = 0; i < sSize; i++) {
            if (s[i] == explosion[0]) isExploded[i] = true;
        }
    } else {
        for (int i = 0; i < sSize; i++) {
            if (s[i] == explosion[0]) explosionPieces.emplace(i, 0);
            else if (!explosionPieces.empty() && s[i] == explosion[explosionPieces.top().second + 1]) {
                explosionPieces.emplace(i, explosionPieces.top().second + 1);

                if (explosionPieces.top().second == explosionSize - 1) {
                    for (int j = 0; j < explosionSize; j++) {
                        isExploded[explosionPieces.top().first] = true;

                        explosionPieces.pop();
                    }
                }
            } else {
                while (!explosionPieces.empty()) {
                    explosionPieces.pop();
                }
            }
        }
    }

    for (int i = 0; i < sSize; i++) {
        if (!isExploded[i]) {
            hasLeft = true;

            cout << s[i];
        }
    }

    cout << (hasLeft ? "" : "FRULA") << '\n';

    return 0;
}

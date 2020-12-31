#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

int main() {
    int tc;

    cin >> tc;

    auto mapMbti = [&](string &mbti) {
        int ret = 0;

        REP(i, 4) ret |= (mbti[i] == "ESTJ"[i]) << i;

        return ret;
    };

    while (tc--) {
        int n;

        cin >> n;

        vi mbtiCounts(16, 0);

        REP(i, n) {
            string mbti;

            cin >> mbti;

            mbtiCounts[mapMbti(mbti)]++;
        }

        int ans = 1234;

        REP(i, 16) {
            if (!mbtiCounts[i]) continue;

            mbtiCounts[i]--;

            REP(j, 16) {
                if (!mbtiCounts[j]) continue;

                mbtiCounts[j]--;

                REP(k, 16) {
                    if (!mbtiCounts[k]) continue;

                    chmin(ans, __builtin_popcount(i ^ j) + __builtin_popcount(j ^ k) + __builtin_popcount(k ^ i));
                }

                mbtiCounts[j]++;
            }

            mbtiCounts[i]++;
        }

        PRINTLN(ans);
    }

    return 0;
}

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        int k;
        multiset<int> q;

        cin >> k;

        while (k--) {
            char instruction;
            int argument;

            cin >> instruction >> argument;

            if (instruction == 'I') q.insert(argument);
            else if (!q.empty()) {
                if (argument == 1) {
                    auto head = q.end();

                    q.erase(--head);
                } else q.erase(q.begin());
            }
        }

        if (q.empty()) cout << "EMPTY\n";
        else {
            auto head = q.end();

            cout << *(--head) << ' ' << *q.begin() << '\n';
        }
    }

    return 0;
}

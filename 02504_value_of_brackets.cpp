#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    string s;

    cin >> s;

    int n = s.size();
    stack<char> brackets;
    ll ans = 0;
    ll temp = 1;

    FOR(i, 0, n) {
        if (s[i] == '(') {
            temp *= 2;

            brackets.push('(');
        } else if (s[i] == '[') {
            temp *= 3;

            brackets.push('[');
        } else if (s[i] == ')') {
            if (brackets.empty() || brackets.top() == '[') {
                PRINTLN(0);

                return 0;
            }

            if (s[i - 1] == '(') ans += temp;

            brackets.pop();

            temp /= 2;
        } else if (s[i] == ']') {
            if (brackets.empty() || brackets.top() == '(') {
                PRINTLN(0);

                return 0;
            }

            if (s[i - 1] == '[') ans += temp;

            brackets.pop();

            temp /= 3;
        }
    }

    PRINTLN(brackets.empty() ? ans : 0);

    return 0;
}

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string a;
    string b;
    string c;
    int size;
    int carry = 0;

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() > b.size()) {
        size = a.size();
        b += string(size - b.size(), '0');
    } else {
        size = b.size();
        a += string(size - a.size(), '0');
    }

    for (int i = 0; i < size; i++) {
        c.push_back(((a[i] - '0' + b[i] - '0' + carry) % 10) + '0');
        carry = (a[i] - '0' + b[i] - '0' + carry) >= 10;
    }

    if (carry) c += '1';

    reverse(c.begin(), c.end());

    cout << c << '\n';

    return 0;
}

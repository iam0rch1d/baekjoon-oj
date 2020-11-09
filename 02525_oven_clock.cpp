#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int c;

    cin >> a >> b >> c;
    cout << (a + ((b + c) / 60)) % 24 << ' ' << (b + c) % 60 << '\n';

    return 0;
}

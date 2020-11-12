#include <iostream>
#include <tuple>

using namespace std;

pair<long long, long long> dncPoint(string &code, int index, long long sy, long long sx, long long size) {
    if (size == 1) return {sy, sx};

    if (code[index] == '1') return dncPoint(code, index + 1, sy, sx + size / 2, size / 2);
    else if (code[index] == '2') return dncPoint(code, index + 1, sy, sx, size / 2);
    else if (code[index] == '3') return dncPoint(code, index + 1, sy + size / 2, sx, size / 2);
    else if (code[index] == '4') return dncPoint(code, index + 1, sy + size / 2, sx + size / 2, size / 2);

    return {0, 0};
}

string dncCode(long long sy, long long sx, long long size, long long y, long long x) {
    if (size == 1) return "";

    unsigned quadrantIndex = ((y >= sy + size / 2) << 1u) + (x >= sx + size / 2);
    long long dy = (y >= sy + size / 2) * size / 2;
    long long dx = (x >= sx + size / 2) * size / 2;

    return "2134"[quadrantIndex] + dncCode(sy + dy, sx + dx, size / 2, y, x);
}

int main() {
    long long powerOf2[51] = {1};
    int d;
    string code;
    long long dx;
    long long dy;
    long long size;
    long long y;
    long long x;

    for (int i = 1; i <= 50; i++) {
        powerOf2[i] = powerOf2[i - 1] * 2;
    }

    cin >> d >> code >> dx >> dy;

    size = powerOf2[d];
    tie(y, x) = dncPoint(code, 0, 0, 0, size);
    y -= dy;
    x += dx;

    cout << (y >= 0 && y < size && x >= 0 && x < size ? dncCode(0, 0, size, y, x) : "-1") << '\n';

    return 0;
}

#include <algorithm>
#include <complex>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void computeFft(vector<complex<double>> &x, bool inverse) {
    unsigned int xSize = x.size();

    for (unsigned int i = 1, j = 0; i < xSize; i++) {
        unsigned int bitmask = xSize >> 1u;

        while (!((j ^= bitmask) & bitmask)) {
            bitmask >>= 1u;
        }

        if (i < j) swap(x[i], x[j]);
    }

    for (unsigned int i = 1; i < xSize; i <<= 1u) {
        double f = inverse ? M_PI / i : -M_PI / i;
        complex<double> omega(cos(f), sin(f));

        for (unsigned int j = 0; j < xSize; j += (i << 1u)) {
            complex<double> theta(1, 0);

            for (int k = 0; k < i; k++) {
                complex<double> alpha = x[j + k];
                complex<double> beta = x[i + j + k] * theta;
                x[j + k] = alpha + beta;
                x[i + j + k] = alpha - beta;
                theta *= omega;
            }
        }
    }

    if (inverse) {
        for (complex<double> &i : x) {
            i /= xSize;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char buffer = '0';
    vector<complex<double>> a;
    vector<complex<double>> b;
    int carry = 0;
    vector<int> multiplication;
    int multiplicationSize;

    while (buffer >= '0' && buffer <= '9') {
        buffer = (char) getchar();

        a.emplace_back(buffer - '0', 0);
    }

    a.pop_back();

    buffer = '0';

    while (buffer >= '0' && buffer <= '9') {
        buffer = (char) getchar();

        b.emplace_back(buffer - '0', 0);
    }

    b.pop_back();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    unsigned int fftSize = 1u;

    while (fftSize < a.size() + 1 || fftSize < b.size()) fftSize <<= 1u;

    fftSize <<= 1u;

    a.resize(fftSize);
    b.resize(fftSize);
    computeFft(a, false);
    computeFft(b, false);

    for (unsigned int j = 0; j < fftSize; j++) {
        a[j] *= b[j];
    }

    computeFft(a, true);

    for (int j = 0; j < fftSize; j++) {
        int temp = (int) round(a[j].real()) + carry;

        multiplication.push_back(temp % 10);
        carry = temp / 10;
    }

    while (carry > 0) {
        multiplication.push_back(carry % 10);
        carry /= 10;
    }

    int j;

    multiplicationSize = multiplication.size();

    for (j = multiplicationSize - 1; j >= 0 && multiplication[j] == 0; j--);

    if (j < 0) puts("0");
    else {
        while (j >= 0) {
            putchar(multiplication[j--] + '0');
        }

        puts("");
    }

    return 0;
}

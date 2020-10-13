#include <iostream>

using namespace std;

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int a;
        int b;

        scanf("%d,%d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}

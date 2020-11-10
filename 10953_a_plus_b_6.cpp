#include <iostream>

using namespace std;

int main() {
    int testcases;

    cin >> testcases;

    while (testcases--) {
        int a;
        int b;

        scanf("%d,%d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}

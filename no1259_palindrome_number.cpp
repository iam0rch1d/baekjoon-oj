#include <iostream>

using namespace std;

int main() {
    string number;

    while (true) {
        bool isPalindrome = true;

        cin >> number;

        if (number == "0") return 0;

        for (int i = 0; i < number.size() / 2; i++) {
            if (number[i] != number[number.size() - i - 1]) {
                isPalindrome = false;

                break;
            }
        }

        cout << (isPalindrome ? "yes" : "no") << endl;
    }
}

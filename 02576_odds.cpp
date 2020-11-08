#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> odds;
    int oddSum = 0;

    for (int i = 0; i < 7; i++) {
        int number;

        cin >> number;

        if (number % 2) {
            odds.push_back(number);

            oddSum += number;
        }
    }

    if (odds.empty()) cout << "-1\n";
    else cout << oddSum << '\n' << *min_element(odds.begin(), odds.end()) << '\n';

    return 0;
}

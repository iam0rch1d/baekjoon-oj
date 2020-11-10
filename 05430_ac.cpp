#include <iostream>
#include <deque>

using namespace std;

int main() {
    int testcases;

    cin >> testcases;

    while (testcases--) {
        string functions;
        int arraySize;
        string arrayString;
        string::iterator function;
        int element = 0;
        deque<int> array;
        bool shouldPopBack = false;
        bool hasError = false;

        cin >> functions >> arraySize >> arrayString;

        function = functions.begin();

        for (int i = 1; i < arrayString.size() - 1; i++) {
            if (arrayString.at(i) >= '0' && arrayString.at(i) <= '9') {
                element *= 10;
                element += arrayString.at(i) - '0';
            }

            if (arrayString.at(i) < '0' || arrayString.at(i) > '9' || i == arrayString.size() - 2) {
                array.push_back(element);

                element = 0;
            }
        }

        while (*function != '\0') {
            if (*function == 'R') shouldPopBack = !shouldPopBack;
            else if (array.empty()) {
                hasError = true;

                break;
            } else if (shouldPopBack) array.pop_back();
            else array.pop_front();

            function++;
        }

        if (hasError) {
            cout << "error" << '\n';

            continue;
        }

        cout << "[";

        if (shouldPopBack) {
            while (!array.empty()) {
                cout << array.back();

                array.pop_back();

                if (!array.empty()) cout << ",";
            }
        } else {
            while (!array.empty()) {
                cout << array.front();

                array.pop_front();

                if (!array.empty()) cout << ",";
            }
        }

        cout << "]" << '\n';
    }

    return 0;
}

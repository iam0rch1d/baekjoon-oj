#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main() {
    int dequeSize;
    int numToPop;
    deque<int> numbers;
    queue<int> toPopNumbers;
    int numRotation = 0;
    int distanceForward = 0;
    int distanceBackward = 0;

    cin >> dequeSize >> numToPop;

    for (int i = 1; i <= dequeSize; i++) {
        numbers.push_back(i);
    }

    while (numToPop-- > 0) {
        int toPopNumber;

        cin >> toPopNumber;

        toPopNumbers.push(toPopNumber);
    }

    while (!toPopNumbers.empty()) {
        int current = numbers.front();

        numbers.pop_front();

        if (current == toPopNumbers.front()) {
            toPopNumbers.pop();

            numRotation += min(distanceForward, distanceBackward);
            distanceForward = 0;
            distanceBackward = 0;
        } else {
            numbers.push_front(current);

            while (numbers.front() != toPopNumbers.front()) {
                int temp = numbers.front();

                numbers.pop_front();
                numbers.push_back(temp);

                distanceForward++;
            }

            while (numbers.front() != current) {
                int temp = numbers.front();

                numbers.pop_front();
                numbers.push_back(temp);

                distanceBackward++;
            }

            while (numbers.front() != toPopNumbers.front()) {
                int temp = numbers.front();

                numbers.pop_front();
                numbers.push_back(temp);
            }
        }
    }

    cout << numRotation << endl;

    return 0;
}

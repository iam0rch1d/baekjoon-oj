#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    cin >> n;

    while (n-- > 0) {
        int number;

        cin >> number;

        if (maxHeap.size() > minHeap.size()) minHeap.push(number);
        else maxHeap.push(number);

        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int maxHeapTop = maxHeap.top();
            int minHeapTop = minHeap.top();

            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minHeapTop);
            minHeap.push(maxHeapTop);
        }

        cout << maxHeap.top() << '\n';
    }

    return 0;
}

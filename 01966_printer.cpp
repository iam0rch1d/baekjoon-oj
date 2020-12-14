#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int documentNo;
    int priority;
} Document;

bool operator<(Document i, Document j) {
    return i.priority < j.priority;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int numDocument;
        int queryDocumentNo;
        queue<Document> printer;
        priority_queue<int> priorities;
        int sequenceNo = 0;

        cin >> numDocument >> queryDocumentNo;


        for (int i = 0; i < numDocument; i++) {
            int tempPriority;

            cin >> tempPriority;

            printer.push({i, tempPriority});
            priorities.push(tempPriority);
        }

        while (!printer.empty()) {
            Document current = printer.front();

            printer.pop();

            if (current.priority == priorities.top()) {
                sequenceNo++;

                priorities.pop();

                if (current.documentNo == queryDocumentNo) {
                    cout << sequenceNo << '\n';

                    break;
                }
            } else printer.push(current);
        }
    }

    return 0;
}

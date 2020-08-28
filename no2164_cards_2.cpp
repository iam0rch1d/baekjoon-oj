#include <iostream>
#include <queue>

using namespace std;

int main() {
    int numCard;
    queue<int> deck;

    cin >> numCard;

    for (int i = 1; i <= numCard; i++) {
        deck.push(i);
    }

    while (deck.size() > 1) {
        deck.pop();
        deck.push(deck.front());
        deck.pop();
    }

    cout << deck.front() << endl;

    return 0;
}

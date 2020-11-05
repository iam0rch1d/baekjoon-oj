#include <iostream>

using namespace std;

int main() {
    int maxPassengers = 0;
    int passengers = 0;

    for (int i = 0; i < 4; i++) {
        int getoffs;
        int rides;
        
        cin >> getoffs >> rides;

        passengers += rides - getoffs;
        maxPassengers = max(maxPassengers, passengers);
    }

    cout << maxPassengers << '\n';

    return 0;
}

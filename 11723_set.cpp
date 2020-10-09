#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numInstruction;
    unsigned bitset = 0;

    cin >> numInstruction;

    while (numInstruction-- > 0) {
        string instruction;
        unsigned target;

        cin >> instruction;

        if (instruction == "add") {
            cin >> target;

            bitset |= (1u << --target);
        } else if (instruction == "remove") {
            cin >> target;

            bitset &= ~(1u << --target);
        } else if (instruction == "check") {
            cin >> target;
            cout << "01"[(bitset & (1u << --target)) != 0] << '\n';
        } else if (instruction == "toggle") {
            cin >> target;

            bitset ^= (1u << --target);
        } else if (instruction == "all") bitset = (1u << 20u) - 1;
        else if (instruction == "empty") bitset = 0;
    }

    return 0;
}

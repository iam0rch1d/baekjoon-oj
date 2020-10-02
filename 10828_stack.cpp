#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numInstruction;
    vector<int> stack;

    cin >> numInstruction;

    while (numInstruction-- > 0) {
        string instruction;

        cin >> instruction;

        if (instruction == "push") {
            int target;

            cin >> target;

            stack.push_back(target);
        } else if (instruction == "pop"){
            cout << (stack.empty() ? -1 : stack[stack.size() - 1]) << '\n';

            if (!stack.empty()) stack.pop_back();
        } else if (instruction == "size") cout << stack.size() << '\n';
        else if (instruction == "empty") cout << (stack.empty() ? 1 : 0) << '\n';
        else if (instruction == "top") cout << (stack.empty() ? -1 : stack[stack.size() - 1]) << '\n';
    }

    return 0;
}

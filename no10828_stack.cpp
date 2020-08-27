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
            cout << (stack.empty() ? -1 : stack[stack.size() - 1]) << endl;

            if (!stack.empty()) stack.pop_back();
        } else if (instruction == "size") cout << stack.size() << endl;
        else if (instruction == "empty") cout << (stack.empty() ? 1 : 0) << endl;
        else if (instruction == "top") cout << (stack.empty() ? -1 : stack[stack.size() - 1]) << endl;
    }

    return 0;
}

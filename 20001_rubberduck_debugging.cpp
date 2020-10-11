#include <iostream>

using namespace std;

int main() {
    string instruction;
    int problemStack = 0;

    while (true) {
        getline(cin, instruction);

        if (instruction == "고무오리 디버깅 끝") break;

        if (instruction == "고무오리" && problemStack > 0) problemStack--;
        else if (instruction == "고무오리" && problemStack <= 0) problemStack += 2;
        else if (instruction == "문제") problemStack++;
    }

    cout << (problemStack == 0 ? "고무오리야 사랑해\n" : "힝구\n");

    return 0;
}

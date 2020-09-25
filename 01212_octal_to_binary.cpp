#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string octal;
    string binary;
    int binaryStartingIndex = 0;

    cin >> octal;

    if (octal == "0") {
        cout << "0\n";

        return 0;
    }

    for (char octalChar : octal) {
        switch (octalChar) {
            case '0': {
                binary += "000";

                break;
            }
            case '1': {
                binary += "001";

                break;
            }
            case '2': {
                binary += "010";

                break;
            }
            case '3': {
                binary += "011";

                break;
            }
            case '4': {
                binary += "100";

                break;
            }
            case '5': {
                binary += "101";

                break;
            }
            case '6': {
                binary += "110";

                break;
            }
            case '7': {
                binary += "111";

                break;
            }
            default: {}
        }
    }

    while (binary[binaryStartingIndex] == '0') {
        binaryStartingIndex++;
    }

    cout << binary.substr(binaryStartingIndex) << '\n';

    return 0;
}

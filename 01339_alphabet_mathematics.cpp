#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<char> alphabets;
int alphabetsSize;
int indexCache[256];
int values[10];

int mapAlphabet(char alphabet) {
    int &index = indexCache[alphabet];

    if (index) return index;

    for (int i = 0; i < alphabetsSize; i++) {
        if (alphabets[i] == alphabet) return index = i;
    }

    return -1;
}

int main() {
    int n;
    int maxSum = 0;

    cin >> n;

    vector<string> words(n);

    for (string &word : words) {
        cin >> word;

        for (char alphabet : word) {
            alphabets.push_back(alphabet);
        }
    }

    sort(alphabets.begin(), alphabets.end());
    alphabets.erase(unique(alphabets.begin(), alphabets.end()), alphabets.end());

    alphabetsSize = alphabets.size();

    for (int i = 0; i < alphabetsSize; i++) {
        values[i] = 9 - i;
    }

    while (true) {
        int sum = 0;

        for (string &word : words) {
            int wordValue = 0;

            for (char &alphabet : word) {
                wordValue = wordValue * 10 + values[mapAlphabet(alphabet)];
            }

            sum += wordValue;
        }

        maxSum = max(maxSum, sum);

        if (!prev_permutation(values, values + alphabets.size())) break;
    }

    cout << maxSum << '\n';

    return 0;
}

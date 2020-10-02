#include <iostream>
#include <map>

using namespace std;

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int numClothing;
        string clothingName;
        string clothingType;
        map<string, int> map;
        int combinationCount = 1;

        cin >> numClothing;

        for (int clothesNo = 0; clothesNo < numClothing; clothesNo++) {
            cin >> clothingName >> clothingType;

            if (map.find(clothingType) == map.end()) map.insert(make_pair(clothingType, 1));
            else map[clothingType]++;
        }

        for (const auto &item : map) {
            combinationCount *= item.second + 1;
        }

        cout << --combinationCount << '\n';
    }

    return 0;
}

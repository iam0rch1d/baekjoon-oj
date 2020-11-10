#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    vector<tuple<string, int, int, int>> students(n);

    for (auto &student : students) {
        string name;
        int korean;
        int english;
        int mathematics;

        cin >> name >> korean >> english >> mathematics;

        student = {name, korean, english, mathematics};
    }

    sort(students.begin(), students.end(), [](auto i, auto j) {
        auto[iName, iKorean, iEnglish, iMathematics] = i;
        auto[jName, jKorean, jEnglish, jMathematics] = j;

        return iKorean > jKorean
        || iKorean == jKorean && iEnglish < jEnglish
        || iKorean == jKorean && iEnglish == jEnglish && iMathematics > jMathematics
        || iKorean == jKorean && iEnglish == jEnglish && iMathematics == jMathematics && iName < jName;
    });

    for (auto student : students) {
        cout << get<0>(student) << '\n';
    }

    return 0;
}

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

    vector<tuple<int, int, int, string>> students(n);

    for (auto &student : students) {
        string name;
        int korean;
        int english;
        int mathematics;

        cin >> name >> korean >> english >> mathematics;

        student = {-korean, english, -mathematics, name};
    }

    sort(students.begin(), students.end());

    for (auto student : students) {
        cout << get<3>(student) << '\n';
    }

    return 0;
}

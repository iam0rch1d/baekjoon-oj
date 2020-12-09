#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        int childDepths[26]{};
        bool isTerminal{};

        Node() {
            for (int &childDepth : childDepths) {
                childDepth = -1;
            }
        }
    };

    vector<Node> nodes;
    int maxDepth{};
    int rootDepth{newNode()};

    int newNode() {
        Node node;

        nodes.push_back(node);

        return maxDepth++;
    }

    void add(int depth, string &s, int i) {
        if (i == s.size()) {
            nodes[depth].isTerminal = true;

            return;
        }

        int childNo = s[i] - 'a';

        if (nodes[depth].childDepths[childNo] == -1) nodes[depth].childDepths[childNo] = newNode();

        add(nodes[depth].childDepths[childNo], s, i + 1);
    }

    void add(string &s) {
        add(rootDepth, s, 0);
    }

    bool find(int depth, string &s, int i) {
        if (depth == -1) return false;

        if (i == s.size()) return nodes[depth].isTerminal;

        return find(nodes[depth].childDepths[s[i] - 'a'], s, i + 1);
    }

    bool find(string &s) {
        return find(rootDepth, s, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;
    Trie trie;
    int findCount = 0;

    cin >> n >> m;

    while (n--) {
        string s;

        cin >> s;

        trie.add(s);
    }

    while (m--) {
        string s;

        cin >> s;

        findCount += trie.find(s);
    }

    cout << findCount << '\n';

    return 0;
}

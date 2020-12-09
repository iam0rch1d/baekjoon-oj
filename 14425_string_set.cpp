#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        int children[26]{};
        bool isTerminal{};

        Node() {
            for (int &child : children) {
                child = -1;
            }
        }
    };

    vector<Node> nodes;
    int maxDepth{};
    int root{newNode()};

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

        if (nodes[depth].children[childNo] == -1) nodes[depth].children[childNo] = newNode();

        add(nodes[depth].children[childNo], s, i + 1);
    }

    void add(string &s) {
        add(root, s, 0);
    }

    bool find(int depth, string &s, int i) {
        if (depth == -1) return false;

        if (i == s.size()) return nodes[depth].isTerminal;

        return find(nodes[depth].children[s[i] - 'a'], s, i + 1);
    }

    bool find(string &s) {
        return find(root, s, 0);
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

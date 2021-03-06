#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        int childNodes[26]{};
        bool isTerminal{};

        Node() {
            for (int &childNode : childNodes) {
                childNode = -1;
            }
        }
    };

    vector<Node> nodes;
    int backNode{};
    int rootNode{newNode()};

    int newNode() {
        Node node;

        nodes.push_back(node);

        return backNode++;
    }

    void add(int node, string &s, int i) {
        if (i == s.size()) {
            nodes[node].isTerminal = true;

            return;
        }

        int child = s[i] - 'a';

        if (nodes[node].childNodes[child] == -1) nodes[node].childNodes[child] = newNode();

        add(nodes[node].childNodes[child], s, i + 1);
    }

    void add(string &s) {
        add(rootNode, s, 0);
    }

    bool find(int node, string &s, int i) {
        if (node == -1) return false;

        if (i == s.size()) return nodes[node].isTerminal;

        return find(nodes[node].childNodes[s[i] - 'a'], s, i + 1);
    }

    bool find(string &s) {
        return find(rootNode, s, 0);
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

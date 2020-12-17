#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        bool isTerminal{};
        int childNodes[10]{};

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

        int child = s[i] - '0';

        if (nodes[node].childNodes[child] == -1) nodes[node].childNodes[child] = newNode();

        add(nodes[node].childNodes[child], s, i + 1);
    }

    void add(string &s) {
        add(rootNode, s, 0);
    }

    bool query() {
        for (auto node : nodes) {
            if (node.isTerminal) {
                for (int childNode : node.childNodes) {
                    if (childNode != -1) return false;
                }
            }
        }

        return true;
    }
};

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        Trie trie;

        cin >> n;

        while (n--) {
            string s;

            cin >> s;

            trie.add(s);
        }

        cout << (trie.query() ? "YES\n" : "NO\n");
    }

    return 0;
}

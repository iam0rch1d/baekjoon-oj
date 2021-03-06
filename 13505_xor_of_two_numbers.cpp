#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        int childNodes[2]{-1, -1};
        bool isTerminal{};
    };

    vector<Node> nodes;
    int backNode{};
    int rootNode{newNode()};

    int newNode() {
        Node node;

        nodes.push_back(node);

        return backNode++;
    }

    void add(int node, unsigned x, int i) {
        if (i == -1) {
            nodes[node].isTerminal = true;

            return;
        }

        unsigned xi = (x >> i) & 1u;

        if (nodes[node].childNodes[xi] == -1) nodes[node].childNodes[xi] = newNode();

        add(nodes[node].childNodes[xi], x, i - 1);
    }

    void add(unsigned x) {
        add(rootNode, x, 31);
    }

    unsigned query(int node, unsigned x, int i) {
        if (i == -1) return 0;

        unsigned child = !((x >> i) & 1u);

        if (nodes[node].childNodes[child] == -1) child = !child;

        return (child << i) | query(nodes[node].childNodes[child], x, i - 1);
    }

    unsigned query(unsigned x) {
        return query(rootNode, x, 31);
    }
};

int main() {
    int n;
    Trie trie;
    unsigned maxXor;

    cin >> n;

    while (n--) {
        unsigned a;

        cin >> a;

        trie.add(a);

        maxXor = max(maxXor, a ^ trie.query(a));
    }

    cout << maxXor << '\n';

    return 0;
}

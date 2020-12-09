#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        int children[2]{-1, -1};
        bool isTerminal{};
    };

    vector<Node> nodes;
    int root{newNode()};

    int newNode() {
        Node node;

        nodes.push_back(node);

        return (int) nodes.size() - 1;
    }

    unsigned query(int depth, unsigned x, int i) {
        if (i == -1) return 0;

        unsigned child = !((x >> i) & 1u);

        if (nodes[depth].children[child] == -1) child = !child;

        return (child << i) | query(nodes[depth].children[child], x, i - 1);
    }

    unsigned query(unsigned x) {
        return query(root, x, 31);
    }

    void add(int depth, unsigned x, int i) {
        if (i == -1) {
            nodes[depth].isTerminal = true;

            return;
        }

        unsigned xi = (x >> i) & 1u;

        if (nodes[depth].children[xi] == -1) nodes[depth].children[xi] = newNode();

        add(nodes[depth].children[xi], x, i - 1);
    }

    void add(unsigned x) {
        add(root, x, 31);
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

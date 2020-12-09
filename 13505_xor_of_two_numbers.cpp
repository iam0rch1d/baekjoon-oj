#include <iostream>
#include <vector>

using namespace std;

struct Trie {
    struct Node {
        int children[2]{-1, -1};
        bool isTerminal{false};
    };

    vector<Node> trie;
    int root{newNode()};

    int newNode() {
        Node node;

        trie.push_back(node);

        return (int) trie.size() - 1;
    }

    unsigned query(int depth, unsigned x, int i) {
        if (i == -1) return 0;

        unsigned child = !((x >> i) & 1u);

        if (trie[depth].children[child] == -1) child = !child;

        return (child << i) | query(trie[depth].children[child], x, i - 1);
    }

    unsigned query(unsigned x) {
        return query(root, x, 31);
    }

    void add(int depth, unsigned x, int i) {
        if (i == -1) {
            trie[depth].isTerminal = true;

            return;
        }

        unsigned xi = (x >> i) & 1u;

        if (trie[depth].children[xi] == -1) trie[depth].children[xi] = newNode();

        add(trie[depth].children[xi], x, i - 1);
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

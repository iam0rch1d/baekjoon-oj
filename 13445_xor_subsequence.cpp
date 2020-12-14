#include <iostream>
#include <vector>

using namespace std;

unsigned k;

struct Trie {
    struct Node {
        int childNodes[2]{-1, -1};
        int childCount[2]{};
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

        unsigned child = (x >> i) & 1u;

        if (nodes[node].childNodes[child] == -1) nodes[node].childNodes[child] = newNode();

        nodes[node].childCount[child]++;

        add(nodes[node].childNodes[child], x, i - 1);
    }

    void add(unsigned x) {
        add(rootNode, x, 31);
    }

    int query(int node, unsigned x, int i) {
        if (i == -1) return 0;

        int ret = 0;
        unsigned child = (x >> i) & 1u;

        if ((k >> i) & 1u) {
            ret += nodes[node].childCount[child];
            child = !child;
        }

        if (nodes[node].childNodes[child] == -1) return ret;

        ret += query(nodes[node].childNodes[child], x, i - 1);

        return ret;
    }

    int query(unsigned x) {
        return query(rootNode, x, 31);
    }
};

int main() {
    int n;
    Trie trie;
    unsigned partialXorSum = 0;
    long long ans = 0;

    cin >> n >> k;

    trie.add(partialXorSum);

    while (n--) {
        int a;

        cin >> a;

        partialXorSum ^= a;

        ans += trie.query(partialXorSum);

        trie.add(partialXorSum);
    }

    cout << ans << '\n';

    return 0;
}

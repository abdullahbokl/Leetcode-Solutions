class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node) return nullptr;
        unordered_map<Node *, Node *> mp;
        queue<Node *> q;
        q.push(node);
        mp[node] = new Node(node->val);
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            for (auto &i: cur->neighbors) {
                if (!mp.count(i)) {
                    mp[i] = new Node(i->val);
                    q.push(i);
                }
                mp[cur]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];
    }
};
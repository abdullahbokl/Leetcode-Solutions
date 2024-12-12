class Solution {
private:
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;

    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        dfs(root->left);

        if (prev and root->val < prev->val) {
            second = root;
            if (first) return;
            else first = prev;
        }


        prev = root;
        dfs(root->right);
    }

public:
    void recoverTree(TreeNode *root) {
        dfs(root);
        swap(first->val, second->val);
    }
};

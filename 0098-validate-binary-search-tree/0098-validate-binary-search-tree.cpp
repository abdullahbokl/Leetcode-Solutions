class Solution {
private:
    bool dfs(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {

        if (root == nullptr) return true;
        if (minNode && minNode->val >= root->val) return false;
        if (maxNode && maxNode->val <= root->val) return false;

        return dfs(root->left, minNode, root) && dfs(root->right, root, maxNode);
    }

public:
    bool isValidBST(TreeNode *root) {
        return dfs(root, nullptr, nullptr);
    }
};
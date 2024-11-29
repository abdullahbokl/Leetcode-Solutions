class Solution {
private:
    vector<int> res;

    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        res.emplace_back(root->val);
        inorder(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        inorder(root);
        return res;
    }
};

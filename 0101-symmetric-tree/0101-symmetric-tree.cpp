class Solution {
public:
    bool checkTree(TreeNode *left, TreeNode *right) {
        if (left == nullptr and right == nullptr) {
            return true;
        }

        if (left == nullptr || right == nullptr) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }

        return checkTree(left->left, right->right) && checkTree(left->right, right->left);

    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        return checkTree(root->left, root->right);

    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> st;

        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.emplace(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ans.emplace_back(root->val);
            root = root->right;
        }

        return ans;
    }
};
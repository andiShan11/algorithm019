class Solution{
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            stack<TreeNode*> stk;
            TreeNode *p = root, *prev = nullptr;
            vector<int> ans;
            while (p || !stk.empty()) {
                while (p) {
                    // ① 前序遍历
                    // ans.push_back(p->val);
                    stk.push(p);
                    p = p->left;
                }
                p = stk.top();
                if (!p->right || p->right != prev) ans.push_back(p->val);

                if (p->right && p->right != prev) p = p->right;
                else {
                    // ③ 后序遍历
                    stk.pop();
                    prev = p;
                    p = nullptr;
                }
            }
            return ans;
        }
};

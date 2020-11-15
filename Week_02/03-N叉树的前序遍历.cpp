class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int>ans;
        helper(ans, root);
        return ans;
    }
    void helper(vector<int>&ans, Node*root){
        if(root){
            ans.push_back(root->val);
            for(auto r:root->children){
                helper(ans, r);
            }
        }
    }
};

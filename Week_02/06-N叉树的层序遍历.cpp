class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return{};
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>vec;
            for(int i=0;i<size;i++){
                auto tmp=q.front();
                vec.push_back(tmp->val);
                q.pop();
                for(auto x:tmp->children){
                    q.push(x);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

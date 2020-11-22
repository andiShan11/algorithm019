## [二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

在左子树上查找两个节点的最近公共祖先，如果找不着，即返回 `NULL`, 说明这两个节点 **必定都在右子树上。** 但凡还有一个节点在左子树上【假设为 `p`】，我们必定能到达递归的边界条件，然后返回该节点 `p`。右子树同理。

所以当左右子树递归结果都不为 `NULL` 时，root必定是最近公共祖先了。

## [从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

递归的构建左右子树

## [组合](https://leetcode-cn.com/problems/combinations/)

同子集的解题思路非常相似

```cpp
// 组合
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
        if(cur==n+2) return;
        if (t.size() == k) {
            ans.push_back(t);
            return;
        }
        if(t.size()<k){
            t.push_back(cur);
            dfs(cur + 1, n, k);
        }
        t.pop_back();
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};


//子集
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
```

## [全排列](https://leetcode-cn.com/problems/permutations/)

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<vector<int>>ans;
        vector<bool>vis(nums.size(),false);
        vector<int>target(nums.size());
        dfs(ans,nums, 0,target,vis);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>& nums, int index, vector<int>target,vector<bool>vis){
        if(index==nums.size()) ans.push_back(target);
        else{
            for(int i=0;i<nums.size();i++){
                if(vis[i]) continue;
                vis[i]=true;
                target[index]=nums[i];
                dfs(ans, nums,index+1,target,vis);
                vis[i]=false;
            }
        }
    }
};
```

这种解法是一种非常暴力的递归。

暴力枚举结果中每一位的可取的每个值。

`index` 表示枚举到哪一位了；

`dfs` 中的循环枚举 `target[index]` 可取的值

所以我们需要 `vis[]` 表示哪一位已经在前面被取过，同时该数组还是全局变量，所以需要回溯。

## [全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<vector<int>>ans;
        vector<bool>vis(nums.size(),false);
        vector<int>target(nums.size());
        sort(nums.begin(), nums.end());
        dfs(ans,nums, 0,target,vis);
        return ans;
    }
    void dfs(vector<vector<int>>&ans, vector<int>& nums, int index, vector<int>target,vector<bool>vis){
        if(index==nums.size()) ans.push_back(target);
        else{
            for(int i=0;i<nums.size();i++){
                if(vis[i]) continue;
                if(i > 0 && !vis[i-1] && nums[i-1] == nums[i])continue;
                vis[i]=true;
                target[index]=nums[i];
                dfs(ans, nums,index+1,target,vis);
                vis[i]=false;
            }
        }
    }
};
```

在上一题的基础上，对原数组排序，然后在枚举每一位可取的值时，我们需要枚举位 `index` 可取的值 `nums[i]` 没有被取过，也就是加了 `if(i > 0 && !vis[i-1] && nums[i-1] == nums[i])continue;`
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int>UFS(M.size(),0);
        for(int i = 0;i<M.size();i++)
        {
            UFS[i] = i;
        }
        for(int i=0;i<M.size();i++)
            for(int j =0;j<i;j++)
            {
                if(M[i][j]==1)
                Union(UFS,i,j);
            }
        int circle = 0;
        for(int i=0;i<UFS.size();i++)
        {
            if(UFS[i] == i) circle++;
        }
        return circle;
    }
    int  Find(vector<int>&a,int x)
    {
        int fx = a[x];
        if(x!=fx)
        {
            fx = Find(a,a[x]);
        }
        return fx;
    }
    void Union(vector<int>&a,int x,int y)
    {
        int fx = Find(a,x);
        int fy = Find(a,y);
        if(fx!=fy)
        a[fx] = fy;
    }
};

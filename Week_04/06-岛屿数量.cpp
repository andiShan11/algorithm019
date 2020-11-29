class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int ans=0,m=grid.size(),n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    DFS(grid,vis,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>&vis,int i,int j,int m,int n){
        vis[i][j]=true;
        for(int index=0;index<4;index++){
            int x=i+dx[index], y=j+dy[index];
            if(x>=0&&x<m&&y>=0&&y<n&&!vis[x][y]&&grid[x][y]=='1'){
                DFS(grid,vis,x,y,m,n);
            }
        }
    }
};

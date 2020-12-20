class Solution {
public:
    unordered_map<int,int>parent;
    unordered_map<int,int>cnt;
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int m=board.size(), n=board[0].size();
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='Q';
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                board[i][n-1]='Q';
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                board[0][j]='Q';
            }
            if(board[m-1][j]=='O'){
                q.push({m-1,j});
                board[m-1][j]='Q';
            }
        }
        // cout<<q.size()<<endl;
        while(!q.empty()){
            pair<int, int>one=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=one.first+dx[i];
                int y=one.second+dy[i];
                if(x>=0&&x<m&&y>=0&&y<n&&board[x][y]=='O'){
                    q.push({x,y});
                    board[x][y]='Q';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Q') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};

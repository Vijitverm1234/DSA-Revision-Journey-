class Solution {
  public:
     void dfs(vector<vector<char>> grid, vector<vector<int>>&vis,int row,int col){
         vis[row][col]=1;
          int dx[]={-1,0,1,0};
          int dy[]={0,1,0,-1};
          int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nr=row+dx[i];
            int nc=col+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='O'){
                vis[nr][nc]=1;
                dfs(grid,vis,nr,nc);
            }
        }
          
     }
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]=='O'){
                dfs(grid,vis,0,i);
            }
             if(!vis[n-1][i] && grid[n-1][i]=='O'){
                dfs(grid,vis,n-1,i);
            }
        }
         for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='O'){
                dfs(grid,vis,i,0);
            }
             if(!vis[i][m-1] && grid[i][m-1]=='O'){
                dfs(grid,vis,i,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
       
    }
};

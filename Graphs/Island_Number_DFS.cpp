class Solution {
public:
    void dfs(vector<vector<int>>&vis,vector<vector<char>> grid,int row,int col){
         int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dx[i];
            int nc=col+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(vis,grid,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                   count++;
                   dfs(vis,grid,i,j);
                }
            }
        }
        return count;
    }
};

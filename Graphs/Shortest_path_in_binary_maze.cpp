

// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> mat, int x, int y) {
        // Validate input: check bounds and start/target cell validity
        if (n <= 0 || m <= 0 || x < 0 || x >= n || y < 0 || y >= m || mat[0][0] == 0 || mat[x][y] == 0) {
            return -1;
        }
        
        // Initialize distance matrix with a large value
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        
        // Start BFS from (0,0) with distance 0
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        
        // Direction arrays for up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int distance = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            // If target is reached, return the distance
            if (r == x && c == y) {
                return distance;
            }
            
            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Check if the new cell is valid and has a shorter distance
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1 && distance + 1 < dist[nr][nc]) {
                    dist[nr][nc] = distance + 1;
                    q.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        
        // If target is not reached, return -1
        return -1;
    }
};
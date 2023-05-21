
class Solution {
  private:
    void DFS(int srcx, int srcy, int i, int j, vector<vector<int>>& grid, vector<vector<bool>>&visited,vector<pair<int, int>>& curr_path, vector<vector<int>>& distance ){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0){
            return;
        }
        visited[i][j] = true;
        curr_path.push_back({i - srcx, j - srcy});
        for(auto d: distance){
            DFS(srcx, srcy, i + d[0], j + d[1], grid, visited, curr_path, distance);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>>visited(r, vector<bool>(c, false));
        set<vector<pair<int, int>>>set;
        vector<vector<int>>distance = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0 ; i < r; i++){
            for(int j = 0 ; j < c; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>>curr_path;
                    DFS(i, j, i, j, grid, visited, curr_path, distance);
                    set.emplace(curr_path);
                }
            }
        }
        return set.size();
    }
};

//Reference
//Just thought how brilliant this DFS code is
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //m = gridSize, if setting n = m is true return grid[0].size(), if false return 0  set islands= 0;
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        //go through all values inside 2d vector, if value is 1 ++islands and execute eraseIslands function
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    //function for erasing near 1s if 1 was found
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        //Base Case
        //i < 0 : if param i is 0, i == m : if param i == grid.size(), j < 0 : if param j is 0, j == n : if param j == grid[0].size()
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
            return;
        
        //General Case
        //Make grid[i][j] = 1 to 0, do the same for connected island lands(horizontal/vertical 1 values) to count it as one island
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

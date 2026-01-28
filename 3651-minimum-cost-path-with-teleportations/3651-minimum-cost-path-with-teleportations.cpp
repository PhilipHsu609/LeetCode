class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        // 1. Data Compression / Coordinate Mapping
        // Grid values can be large, but we only care about the values that actually exist.
        // Let's find unique values to build our suffix array efficiently.
        set<int> unique_vals;
        for(auto& row : grid) for(int x : row) unique_vals.insert(x);
        vector<int> vals(unique_vals.begin(), unique_vals.end());
        
        // Map real values to indices 0..V
        auto get_idx = [&](int val) {
            return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
        };
        int max_v_idx = vals.size();

        const long long INF = 1e18; // Use safely large number
        vector<vector<long long>> dp(m, vector<long long>(n, INF));
        
        // Base Case: Cost is 0 at start (before moving)
        dp[0][0] = 0;

        // We run k+1 phases of walking.
        // After each walk, we perform one batch of teleportations.
        for (int step = 0; step <= k; ++step) {
            
            // --- PHASE 1: WALK (Right & Down) ---
            // Propagate costs within the grid for the current "teleport level"
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    // Try coming from top
                    if (i > 0 && dp[i-1][j] != INF) 
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                    // Try coming from left
                    if (j > 0 && dp[i][j-1] != INF) 
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
                }
            }

            // If we've finished k rounds of teleporting, we stop after the final walk.
            if (step == k) break;

            // --- PHASE 2: TELEPORT ---
            // 1. Find min cost for each value index
            vector<long long> val_min_cost(max_v_idx, INF);
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if (dp[i][j] != INF) {
                        int idx = get_idx(grid[i][j]);
                        val_min_cost[idx] = min(val_min_cost[idx], dp[i][j]);
                    }
                }
            }

            // 2. Compute Suffix Minimums
            // We want best cost from any source with value >= current
            long long current_suffix = INF;
            for (int v = max_v_idx - 1; v >= 0; --v) {
                current_suffix = min(current_suffix, val_min_cost[v]);
                val_min_cost[v] = current_suffix; // Reuse array for suffix min
            }

            // 3. Apply Teleport (Zero Cost)
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    int idx = get_idx(grid[i][j]);
                    if (val_min_cost[idx] != INF) {
                        dp[i][j] = min(dp[i][j], val_min_cost[idx]);
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};
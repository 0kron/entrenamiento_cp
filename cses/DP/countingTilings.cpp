// --- SOLUTION DESCRIPTION (Tiling an N x M Grid with Dominoes) ---
// This is solved using Profile Dynamic Programming (DP).
// 1. State Definition: DP[mask] stores the number of ways to fill the grid up to the current column, 
//    where 'mask' represents the boundary (or 'profile') between the current column (i) and the next (i+1).
// 2. Boundary Mask: A 1 in the mask means a horizontal 1x2 tile placed in column 'i' protrudes into column 'i+1'.
//    A 0 means the corresponding cell in column 'i+1' is empty.
// 3. Transitions: The 'generateNextTile' function pre-calculates all valid ways to fill the current column, 
//    transforming the previous column's boundary state (prev) into the current column's boundary state (next). 
//    A transition is valid only if the column can be filled entirely with 1x2 and 2x1 tiles.

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll MOD = 1e9 + 7;
    // Key: The mask of the NEXT column's boundary (the result mask).
    // Value: A vector of all *previous* column boundary masks (the starting mask) that can transition to this 'next' mask.
    map<int, vector<int>> prevTiles;
    
    ll solve(int n, int m) {
        // If n is too large, the bitmask (2^n) is too big for memory/time.
        if (n > 10) return 0;

        // --- 1. PRE-CALCULATE ALL VALID COLUMN TRANSITIONS ---
        int limit = 1 << n; // 2^n total possible masks
        for (int tile = 0; tile < limit; tile++){
            // For every possible previous mask ('tile'), calculate all possible next masks.
            // Starts checking from row 0, aiming for a 'next' mask initialized to 0.
            generateNextTile(0, n, tile, 0);
        }

        // --- 2. BUILD THE DP TABLE (Column by Column) ---
        // prevRow[mask]: # ways to fill the grid up to the current column, ending with 'mask' boundary.
        vector<ll> prevRow(limit, 0);
        vector<ll> dp(limit, 0);
        
        // Base Case (Column 0): Only one way to start with a fully empty boundary (mask 0).
        prevRow[0] = 1; 

        // Iterate across the M columns of the grid
        for (int col = 0; col < m; col++){
            // Reset the current DP row for the new column
            fill(dp.begin(), dp.end(), 0); 
            
            // Iterate over every possible *new* boundary state (tile)
            for (int tile = 0; tile < limit; tile++){
                
                // DP Transition: Iterate over all possible *previous* boundary states
                // that are known to transition to the current 'tile' state.
                for(auto prevTile: prevTiles[tile]){
                    // dp[current_mask] += prevRow[compatible_previous_mask]
                    dp[tile] = (dp[tile] + prevRow[prevTile]) % MOD;
                }
            }
            // The current DP row becomes the previous row for the next column
            swap(dp, prevRow);
        }
        
        // The final answer is the number of ways to complete the grid (m columns)
        // such that the final boundary is fully empty (mask 0).
        return prevRow[0];
    }
    
    // Recursive function to find valid transitions between column boundaries.
    // idx: current row being processed (0 to n-1)
    // n: number of rows
    // prev: the previous column's boundary mask (1 means cell is covered by a tile coming from the left)
    // next: the mask being constructed for the current column's boundary (1 means a new tile goes to the right)
    void generateNextTile(int idx, int n, int prev, int next){
        // Base Case: Entire column has been processed (all n rows checked)
        if (idx == n) {
            // Found a valid transition pair: store the relationship
            prevTiles[next].push_back(prev);
            return;
        }

        // --- CORE LOGIC: Check availability for the current cell (idx) ---
        
        // If the current cell is ALREADY FILLED by a tile protruding from the previous column:
        if ((prev & (1 << idx)) != 0) {
            // The cell is covered. We do nothing to the current column's tiling ('next'),
            // and move to the next row (idx + 1).
            generateNextTile(idx + 1, n, prev, next);
            return;
        }
        
        // --- Cell is FREE in 'prev': Try the two tiling options ---
        
        // OPTION 1: Place a VERTICAL 2x1 tile in the current column (idx and idx+1)
        // Check if the tile fits vertically (must be within bounds AND the next cell must also be free in 'prev')
        if (idx < n - 1 && (prev & (1 << (idx + 1))) == 0){
            // This 2x1 tile is contained entirely within the current column.
            // It does not affect the next boundary ('next'), so we move two rows down (idx + 2).
            generateNextTile(idx + 2, n, prev, next);
        }
        
        // OPTION 2: Place a HORIZONTAL 1x2 tile at the current row (idx)
        // This tile fills the current cell and PROTRUDES into the next column.
        // We set the corresponding bit in the 'next' mask to indicate this protrusion.
        // Note: The cell must be FREE in 'prev' to allow the horizontal tile to start here.
        generateNextTile(idx + 1, n, prev, next | (1 << idx));
    }
};


int main(){
    // read input
    int n, m;
    // n = rows, m = columns
    cin >> n >> m;

    // use solver
    Solution solver;
    cout << solver.solve(n, m) << endl;

    return 0;
}


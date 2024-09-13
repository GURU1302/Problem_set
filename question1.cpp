#include<bits/stdc++.h>
using namespace std;

int MinimumCost(int rows, int cols, const vector<vector<int>>& matrix) {
    vector<int> flattened;
    vector<vector<int>> transposed(cols, vector<int>(rows));
    
    // Lambda for transposing and flattening
    auto transposeAndFlatten = [&]() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed[j][i] = matrix[i][j];
                flattened.push_back(matrix[i][j]);
            }
        }
    };
    transposeAndFlatten();
    
    // Lambda for sorting
    auto sortArrays = [&]() {
        for (auto& row : transposed) {
            sort(row.begin(), row.end());
        }
        sort(flattened.begin(), flattened.end());
    };
    sortArrays();
    
    // Lambda for finding minimum difference
    auto findMinDifference = [&]() -> int {
        int minDifference = numeric_limits<int>::max();
        
        for (int i = 0; i < flattened.size(); ++i) {
            if (i > 0 && flattened[i] == flattened[i-1]) continue;
            
            int currentMax = flattened[i];
            int currentMin = numeric_limits<int>::max();
            bool valid = true;
            
            for (const auto& row : transposed) {
                auto it = upper_bound(row.begin(), row.end(), currentMax);
                if (it == row.begin()) {
                    valid = false;
                    break;
                }
                currentMin = min(currentMin, *(--it));
            }
            
            if (valid) {
                minDifference = min(minDifference, currentMax - currentMin);
            }
        }
        
        return minDifference;
    };
    
    return findMinDifference();
}

int main(){
    int rows;
    int cols;
    cin>>rows>>cols;
    vector<vector<int>> grid(rows,vector<int>(cols));
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int x;cin>>x;
            grid[i][j] = x;
        }
    }
    
    cout<<MinimumCost(rows,cols,grid)<<endl;
}
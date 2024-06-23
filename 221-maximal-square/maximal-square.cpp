class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        
        vector<int> height(cols, 0);
        int maxSquareArea = 0;
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }
            
            stack<int> indices;
            indices.push(-1);
            vector<int> nextSmaller(cols, 0);
            
            for (int i = cols - 1; i >= 0; --i) {
                while (indices.top() != -1 && height[i] <= height[indices.top()]) {
                    indices.pop();
                }
                nextSmaller[i] = (indices.top() == -1) ? cols : indices.top();
                indices.push(i);
            }
            
            indices = stack<int>();
            indices.push(-1);
            vector<int> prevSmaller(cols, 0);
            
            for (int i = 0; i < cols; ++i) {
                while (indices.top() != -1 && height[i] <= height[indices.top()]) {
                    indices.pop();
                }
                prevSmaller[i] = indices.top();
                indices.push(i);
            }
            
            for (int i = 0; i < cols; ++i) {
                int sideLength = min(height[i], nextSmaller[i] - prevSmaller[i] - 1);
                maxSquareArea = max(maxSquareArea, sideLength * sideLength);
            }
        }
        
        return maxSquareArea;
    }
};
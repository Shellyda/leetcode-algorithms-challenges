#include <vector>
using std::vector;

class NumMatrix
{
public:
    vector<vector<int>> sumMatrix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int COLS = matrix[0].size(), ROWS = matrix.size();
        sumMatrix = vector<vector<int>>(ROWS + 1, vector<int>(COLS + 1, 0));

        for (int r = 0; r < ROWS; r++)
        {
            int rowSum = 0;
            for (int c = 0; c < COLS; c++)
            {
                rowSum += matrix[r][c];
                int above = sumMatrix[r][c + 1];
                sumMatrix[r + 1][c + 1] = rowSum + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        row1++;
        col1++;
        row2++;
        col2++;
        int bottomRight = sumMatrix[row2][col2];
        int above = sumMatrix[row1 - 1][col2];
        int left = sumMatrix[row2][col1 - 1];
        int topLeft = sumMatrix[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
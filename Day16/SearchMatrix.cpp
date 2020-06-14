/**
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
#include<iostream>
#include<vector>
using namespace std;
//UDING STAIR CASE SEARCH
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if( row == 0 ) return false;
    int col = matrix[0].size();

    if(matrix[0][0] > target || target > matrix[row-1][col-1]) return false;
    int sr = 0;
    int ec = col-1;
    while( sr<= row-1 && ec >= 0 )
    {
        int current = matrix[sr][ec];
        if(current > target)
            ec--;
        else if(current < target)
            sr++;
        else
            return true;
    }
    return false;
}

int main(void)
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};

    cout<<" Search Matrix : "<< searchMatrix(matrix,11)<<endl;
    return -1;
}
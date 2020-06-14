/**
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 */

#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    // int row = matrix.size();
    // if( row == 0 )return;
    // int col = matrix[0].size();
    // bool firstRowZero = false;
    // bool firstColZero = false;
    // for( int i = 0; i < col; i++)
    // {
    //     if( matrix[0][i] == 0)
    //         firstRowZero = true;
    // }
    // for( int i = 0; i < row; i++)
    // {
    //     if( matrix[i][0] == 0)
    //         firstColZero = true;
    // }

    // //USing top row & col to store zeros
    // for( int i = 1; i < row; i++)
    //     for( int j = 1; j < col; j++)
    //     {
    //         if(matrix[i][j] == 0)
    //         {
    //             matrix[i][0] = matrix[0][j] = 0;
    //         }
    //     }
    // //Using store zero from top row & col to update matrix data
    // for( int i = 1; i < row; i++)
    //     for( int j = 1; j < col; j++)
    //     {
    //         if(matrix[i][0] == 0 || matrix[0][j] == 0)
    //         {
    //             matrix[i][j] = 0;
    //         }
    //     } 
    // //update zero in top row
    // if(firstRowZero)
    // {
    //     for( int i = 0; i < col; i++)
    //         matrix[0][i]  = 0;
    // }
    // //update zero in top col
    // if(firstColZero)
    // {
    //     for( int i = 0; i < row; i++)
    //         matrix[i][0]  = 0;
    // }
    int m = matrix.size();
        int n = matrix[0].size();
        unsigned long long  horZero = 0, verZero = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    
                    verZero = verZero | 1ULL << i;
                    horZero = horZero | 1ULL << j;
                    
                }
            }
        }
        cout<<verZero<<" : "<<horZero<<endl;
        for (int i = 0; i < m; i++) {
            if ((verZero >> i) & 1ULL) {
                for (int j = 0;j < n; j++) matrix[i][j] = 0;
            }
        }   
        
        for (int i = 0; i < n; i++) {
            if ((horZero >> i) & 1ULL) {
                for (int j = 0;j < m; j++) matrix[j][i] = 0;
            }
        } 
}

int main(void)
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    cout<<" SET ZEROS Output: "<<endl;
    for(auto row:matrix)
    {    for(auto col:row)
            cout<<col<<" ";
        cout<<endl;
    }
    return 0;
}
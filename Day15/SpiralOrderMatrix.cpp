#include<iostream>
#include<vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    int rows = matrix.size();
    int col = 0;
    vector<int> res;
    if( rows < 0  ) return res;
    col = matrix[0].size();

    int count = 0;
    int sr = 0, er = rows-1;
    int sc = 0, ec = col-1;
   
    while( sr <= er && sc <= ec)
    {
        //print top data
        for( int i = sc; i <= ec ; i++)
            res.push_back(matrix[sr][i]);
        sr++;
        
        if( res.size() >= rows*col)break; 

        //print right data
        for( int i = sr; i <= er ; i++)
            res.push_back(matrix[i][ec]);
        ec--;
        
        if( res.size() >= rows*col)break;

         //print bottom data
        for( int i = ec; i >= sc ; i--)
            res.push_back(matrix[er][i]);
        er--;
        
        if( res.size() >= rows*col)break;
        //print right data
        for( int i = er; i >= sr ; i--)
            res.push_back(matrix[i][sc]);
        sc++;
        
        if( res.size() >= rows*col)break;
        
    }
    return res;
}

int main(void)
{
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int>res = spiralOrder(matrix);
    for(auto val:res)
    {
        cout<<val<<" ";
    }

    vector<vector<int>> matrixs[3][3];
    cout<<endl;
    return 0;
}
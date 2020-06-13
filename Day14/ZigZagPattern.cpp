/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"    
 */

#include<iostream>
using namespace std;

string convert(string s, int numRows) {
    
    int row = 0, i = 0, e = numRows-1, step = 0;     
    if(e <= 0) return s;

    string *data = new string[e];
    while(s[i])
    {
        if( row == 0 )step = 1;
        else if ( row == e )step =-1;
        
        data[row] += s[i];
        row+=step;
        i++;
    }
 
    string res;
    for(int i = 0; i<=e ;i++)
    {
        //cout<<data[i]<<endl;
        res+=data[i];
    }
    return res;
}

int main(void)
{
    string data("PAYPALISHIRING");
    cout<<"ZigZagPattern :"<<convert(data,1)<<endl;
    cout<<"ZigZagPattern :"<<convert(data,2)<<endl;
    cout<<"ZigZagPattern :"<<convert(data,3)<<endl;
    cout<<"ZigZagPattern :"<<convert(data,4)<<endl;
    return 0;
}
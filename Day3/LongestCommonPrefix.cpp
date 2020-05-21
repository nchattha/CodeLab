//program to find the longest common prefix in all the string
// On mismatch return empty string
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string findLongestCommonPrefix(const vector<string> &p_VDataStr)
{
    string result =" ";
    if(p_VDataStr.empty()) return result;
    //Assume firsdt string to compare with rest of string
    string pivot = p_VDataStr[0];
    for( int col = 0 ; col < pivot.length(); col++)
    {
        for( int row = 1 ; row < p_VDataStr.size() ; row++)
        {
            cout<<pivot[col]<<" != "<<p_VDataStr[row][col]<<endl;
            if( pivot[col] !=  p_VDataStr[row][col])
            {
                return result;
            }
        }
        result += pivot[col]; 
    }
    return result;
}

int main(void)
{
    vector<string>dataStr;
    dataStr.push_back("tom");
    dataStr.push_back("tommy");
    dataStr.push_back("tomb");
    dataStr.push_back("too");
    cout<<"Longest Common Prefix : "<<findLongestCommonPrefix(dataStr)<<endl;
    
    
    
    return 0;
}
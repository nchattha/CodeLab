/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/

#include<iostream>
#include<stack>
using namespace std; 

bool backspaceCompare(string S, string T) {
    int i,j;
    stack<char>first;
    stack<char>second;
    for (i =0 ; i < S.length() ; i++)
    {
        if(S[i] =='#')
        {    if (!first.empty())
                first.pop();
        }
        else
            first.push(S[i]);
    }

    for (j =0 ; j < T.length() ; j++)
    {
        if(T[j] =='#')
        {    if (!second.empty())
                second.pop();
        }
        else
            second.push(T[j]);
    }
    
    if(first.size() != second.size())
        return false;
    else
    {
        while(!first.empty())
        {
            if( first.top() != second.top())
                return false;
             first.pop();
             second.pop();   
        }
    }
    

    return true;   
}

int main(void)
{
    cout<<backspaceCompare("aa#c", "ac")<<endl;
    return 0;
}
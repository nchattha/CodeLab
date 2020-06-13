/**
 * Reverse the Word in the string
 */
#include<iostream>
#include<stack>

using namespace std;

void reverse(string &str, int start, int end)
{
    while( start < end)
    {
        str[start] += str[end];
        str[end] =  str[start] -  str[end];
        str[start] -= str[end];
        start++;
        end--;
    }
}


string reverseStr(string data)
{
    string res;
    if( data.empty()) return res;

    int beginP = 0;
    for( int i = 0; i < data.length() ; i++)
    {
        if(data[i] == ' ')
        { 
            reverse(data,beginP,i-1);
            beginP =  i+1;
        }
        else if( i == data.size()-1)
        {
           reverse(data,beginP,i);
           break;
        }
    }
    cout<<data<<endl;
    reverse(data,0,data.length()-1);

    cout<<"\n"<<data<<endl;

    for ( int i = 0 ; i < data.length() ;  )
    {
        if(data[i] == ' ')
        {
            while(data[i] == ' ')i++;
            if( i < data.length() && 
                !res.empty() && 
                data[i] != ' ')res += ' ';
        }
        else
        {
            res += data[i];
            i++;
        }
        
    }
    return res;
}

int main(void)
{
    string data("the sky is blue ");
    cout<<"Reverse string: "<<reverseStr(data)<<endl;

    return 0;
}
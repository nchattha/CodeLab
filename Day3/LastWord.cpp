//Program for finding the last word and return the count of it
#include<iostream>
#include<ctype.h>
using namespace std;


int coutLastWordInStr(string str)
{
    int count, index = 0;
    int lastWordStartIndex = 0;
    if(!str.empty())
    {
        for(; index < str.length(); )
        {
            if(str[index] == ' ')
            {
                while(str[index] == ' ' && index < str.length() )index++;
                if( index >= str.length())
                {
                    break;
                }
                else
                {
                    lastWordStartIndex = count = 0;
                }
            }
            else
            {
                if( lastWordStartIndex == 0 && index > 0 ) lastWordStartIndex = index;
                count++;
                index++;
            }
            
        }
    }
    else
    {
        cout<<"Input string is empty"<<endl;
    }
    if( count != 0 )
        cout<<"Last Word is: "<<str.substr(lastWordStartIndex,count)<<endl;
    return count;
} 

int main(void)
{
    string strExp(""); //variable to get input from input stream
    int count = 0 ;
    cout<<"Enter the String : ";
    getline(cin, strExp);
    count = coutLastWordInStr(strExp);
    cout<<"Length of Last Word : "<<count<<endl;
    
    return 0;
}
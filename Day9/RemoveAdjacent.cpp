/**
 * Program to remove the adjacent value depending upon the K i.e( how mnay adjacent values needed to be deleted)
 */
#include<iostream>
#include<stack>
using namespace std;
string removeAdjacent(string data, int kCount)
{
    string result;
    stack<pair<char,int>>filterData;
    for( char ch:data)
    {
        if(filterData.empty() || filterData.top().first != ch)
        {
            filterData.push(pair<char,int>(ch,1));//Bydefault count is set to 1
            cout<<"\n"<<ch<<":"<<1;
        }
        else
        {//top is equal to current element
            filterData.top().second++;
            cout<<"\n"<<filterData.top().first<<":"<<filterData.top().second;
            if(filterData.top().second == kCount)
                filterData.pop();
        }
    }

    while(!filterData.empty())
    {
        for(int i = 0; i < filterData.top().second; i++)
            result+=filterData.top().first;

        filterData.pop();
    }
  
    reverse(result.begin(),result.end());
    return result;
}


int main(void)
{
    string data("deeedbbcccbdaa");
    cout<<removeAdjacent(data,3)<<endl;
    
    return 0;
}
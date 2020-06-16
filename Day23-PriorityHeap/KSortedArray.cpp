#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

void kSortedArray(int *data, int n,int k)
{
    priority_queue<int> pq;
    
    if(n < k ) return;
 
    for( int i = 0; i< k ; i++)
    {
        pq.push(data[i]);
    }

    int s = 0;
    for( int i = k; i < n ; i++)
    {
        data[s] = pq.top();
        pq.pop();
        s++;
        pq.push(data[i]);
    }

    while( !pq.empty() )
    {
        data[s] = pq.top();
        pq.pop();
    }
}

int main(void)
{
    int input[] = {10,12,6,7,9};
    int n = sizeof(input)/sizeof(int);

    kSortedArray(input,n,2);
    for( int i = 0 ; i<n ; i++ )
        cout<<input[i]<<" ,";
    cout<<endl;

    unordered

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void swapData(int &a, int &b)
{
    a +=b;
    b = a - b;
    a -= b;
}

void selectionSort(vector<int>&data)
{
    if(data.size() == 0) return;
    
    for( int i = 0; i < data.size()-1 ; i++)
    {
        if( i+1 < data.size())
        {
            int smallValueIndex = i;
            for( int j = i+1; j < data.size() ; j++)
            {
              if(data[i] > data[j])
                smallValueIndex = j;
            }
            if( smallValueIndex != i)
            swapData(data[i],data[smallValueIndex]);
            cout<<data[i]<<" : "<<data[smallValueIndex]<<endl;
        }
    }
}

int main(void)
{
    vector<int> data= {6,3,2,4,5,9,1,8,6};
    for( auto val:data)
    {
        cout<<val<<" ,";
    }
    cout<<endl;
    selectionSort(data);
    for( auto val:data)
    {
        cout<<val<<" ,";
    }
    cout<<endl;
    return 0;
}
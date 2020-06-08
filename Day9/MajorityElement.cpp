#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>&num)
{
    int result =-1;
    if(num.size() == 0 ) return result;
    else if(num.size() == 1) return num.at(0);
    else
    {
        //BruteForce
        int majorityNo = num.size()/2;    
        int resultCount = 0;
        // for( int i = 0 ; i < num.size(); i++)
        // {
        //     int count = 0;
        //     for( int j = 0 ; j < num.size(); j++)
        //     {
        //         if( num[i] == num[j])
        //         {
        //             count++;
        //         }
        //     }    
        //     cout<<num[i]<<" : "<<count<<endl;
        //     if( count > majorityNo)
        //     {
        //         if(resultCount < count)
        //         {
        //             result = num[i];
        //             resultCount = count;
        //         }
        //     }
        // }
        //hashmap store the coun into the map as key value pair
        //sort the vector
        // sort(num.begin(),num.end());
        
        // for ( int i=0 ; i <num.size() ;)
        // {
        //     int count = 0;
        //     for( int j=0; j<num.size(); j++ )
        //     {
        //         if( num[i] == num[j])
        //             count++;
        //     }
        //     cout<<num[i]<<" : "<<count<<endl;
        //     if( count > majorityNo)
        //     {
        //         if(resultCount < count)
        //         {
        //             result = num[i];
        //             resultCount = count;
        //         }
        //     }
        //     i += count;
        // }
        //Moore Voting Algorithm
        result = num.at(0);
        resultCount = 1; 
        for ( int i=1 ; i <num.size() ;i++)
        {
            if( result == num[i] )
            {
                resultCount++;
            }
            else
            {
                resultCount--;
                if(resultCount == 0)
                {
                    resultCount = 1;
                    result = num[i];
                }
            }
            
        }
        //Checking the assumption that majority number exist
        int count = 0;
        for ( int i=0 ; i <num.size() ;i++)
        {
            if( result == num[i])
                count++;
        }
        if( count <= majorityNo ) return-1 ;
    }
    
    return  result;
}


int main(void)
{
    vector<int>data;
    data.push_back(3);
    data.push_back(2);
    data.push_back(3);
    data.push_back(2);
    data.push_back(3);
    data.push_back(3);
    
    cout<<"Majority Element: "<<majorityElement(data)<<endl;
    return 0;
}
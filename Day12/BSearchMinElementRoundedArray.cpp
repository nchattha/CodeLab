/**
 * Modified Binary Search : Find Minimum Element in Sorted Rotated Array
 */
#include<iostream>
#include<vector>
using namespace std;

int findMinimumElement(int arr[],int e)
{
    int s = 0;
    if( arr[0] == '\0') return -1;

    while( s <= e)
    {
        int mid = (s+e)/2;
        
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
        {    
            return arr[mid];

        }
        else if ( arr[e] > arr[mid] )
        {
            e = mid-1;
        }
        else if( arr[s] > arr[mid])
        {
            s= mid+1;
        }
    }
    return -1;
}

 int findMin(vector<int>& nums) {
       int s = 0;
        int e = nums.size()-1;
        if( nums.empty() ) return -1;

    while( s <= e)
    {
        int mid = (s+e)/2;
        int next = (mid+1)%nums.size();
        int prev = (mid-1+nums.size())%nums.size();
        if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
        {    
            return nums[mid];
        }
        else if ( nums[e] >= nums[mid] )
        {
            e = mid-1;
        }
        else if( nums[mid] >= nums[s])
        {
            s= mid+1;
        }
    }
    return -1; 
}

int main()
{
   
   
    vector<int> data {3,4,5,2};
    cout<<findMin(data)<<endl;
    return 0;
}

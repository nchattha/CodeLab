/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has 
the largest sum and return its sum.
Input: [-2,1,-3,4,-1,2,1,-5,4],s
Output: 6   Explanation: [4,-1,2,1] has the largest sum = 6.*/
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int result = -37627;
    if( nums.size() ==1) return nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(result < sum)
            result = sum;
        
        if(sum < 0)
        {   sum = 0;
            if(result < nums[i])
                result = nums[i]; 
        }
    }
    return result;
}
int main(void)
{
    vector<int> number;
    number.push_back(-2);
    number.push_back(1);
    number.push_back(-3);
    number.push_back(4);
    number.push_back(-1);
    number.push_back(2);
    number.push_back(1);
    number.push_back(-5);
    number.push_back(4);
    cout<<"MAx Subarray sum : "<<maxSubArray(number)<<endl;
    return 0;
}
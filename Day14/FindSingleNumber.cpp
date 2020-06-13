/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 */
#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int val:nums){
        res ^=val;
    }
    return res;
}

int main(void)
{
    vector<int>data = {1,1,3,2,3};
    cout<<"Single Number in data: "<<singleNumber(data)<<endl;
    return 0;
}
/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/
#include<iostream>
#include<vector>
using namespace std;
bool canJump(vector<int>& nums) {
    int end = nums.size();
    int goodIndex = end-1;

    for( int i = end-2 ; i>=0 ; i-- )
    {
        if( i + nums[i] == goodIndex) 
            goodIndex = i;

    }

    if( goodIndex == 0 )return true;
    return false;
}

int numberJump(vector<int>& nums)
{
    int stairsLeft = 0;
    int currentLadder = 0;
    int jump =-1;
    if(nums.size() == 0) return jump;

    currentLadder = stairsLeft = nums[0];
    jump = 1;
    for( int index = 1; index <= nums.size()-1; index++ )
    {
        if( index + nums[index] > currentLadder)
            currentLadder = index + nums[index];
        
        stairsLeft--;

        if( stairsLeft == 0)
        {
            jump++;
            stairsLeft = currentLadder-1;
            if(stairsLeft <= 0 )
            {
                jump = -1;
                break;
            }
        }
    }

    return jump;
}

int main(void)
{
    vector<int>data{2,3,1,1,4};
    cout<<"can jump: "<<canJump(data)<<endl;
    return 0;
}

/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of 
the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note: You must do this in-place without making a copy of the array. Minimize the total number of operations.
Hint #1  
    In-place means we should not be allocating any space for extra array. But we are allowed to modify the existing array. 
    However, as a first step, try coming up with a solution that makes use of additional space. For this problem as well, 
    first apply the idea discussed using an additional array and the in-place solution will pop up eventually.
Hint #2  
    A two-pointer approach could be helpful here. The idea would be to have one pointer for iterating the array and another 
    pointer that just works on the non-zero elements of the array.
*/

#include <iostream>
#include <vector>
using namespace std;

void swapData(int &left, int &right)
{
    left += right;
    right = left - right;
    left -= right;
}

void moveZeroes(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        cout << "Empty Data" << endl;
        return;
    }

    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i + 1;
            //find the next valid number
            while ( j < nums.size() && nums[j] == 0)
                j++;
            //Neep to swap value for Zero value index with Non-zero value index
            if (j < nums.size())
            {
                swap(nums[i], nums[j]);
            }
            else
            {
                break;
            }
        }
    }
}
int main(void)
{
    vector<int> number;
    number.push_back(0);
    // number.push_back(0);
    // number.push_back(0);
    // number.push_back(2);
    // number.push_back(0);
    // number.push_back(-3);
    // number.push_back(4);
    // number.push_back(0);
    // number.push_back(2);
    // number.push_back(1);
    // number.push_back(-5);
    // number.push_back(4);

    cout << "Input Data :";
    for (int num : number)
    {
        cout << num << "\t";
    }
    moveZeroes(number);
    cout << "\n Filtered Data :";
    for (int num : number)
    {
        cout << num << "\t";
    }
    cout << endl;
    return 0;
}
// LEETCODE Problem:
//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory.
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int index = 0, result = 0;
    int j = 0;
    bool match = false;
    if (nums.empty())
        return result;

    //sort the vector
    sort(nums.begin(),nums.end(),[](const int x,const int y)->bool{
       return x < y;     
    });

    
    //starting while loop from the 2nd element
    while (index < nums.size())
    {
        j = index + 1;    
        while(j < nums.size() && nums[index] == nums[j])j++;

        if( index+1 == j)
         return nums[index];
        else
        {
          if( j < nums.size())   
            index = j;
        }
         
        cout<<"\n"<<index<<" - "<<j<<endl;
    }
    return result;
}

int main(void)
{
    vector<int> data;
    data.push_back(2);
    data.push_back(2);
    data.push_back(1);
    cout << "single number in data: " << singleNumber(data) << endl;

    data.clear();
    data.push_back(4);
    data.push_back(2);
    data.push_back(1);
    data.push_back(2);
    data.push_back(1);
    cout << "single number in data: " << singleNumber(data) << endl;

    data.clear();
    cout << "single number in data: " << singleNumber(data) << endl;

    data.clear();
    data.push_back(1);
    data.push_back(3);
    data.push_back(1);
    data.push_back(-1);
    data.push_back(3);
    cout << "single number in data: " << singleNumber(data) << endl;
    

    return 0;
}

//Write an algorithm to determine if a number n is "happy".
//A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum of the squares of its digits,
// and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle 
// which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
// Return True if n is a happy number, and False if not.

#include <iostream>
#include <math.h>
#include<vector>

using namespace std;
bool isHappy(int n) {
    int sum = 0;
    vector<int>regSum;
    // Return false if number is zero
    if( n == 0 ) return false;
    //Return true if number is One
    else if( pow(n,2) == 1 ) return true;
    //loop to iterate the number untill we get happy number i.e. sum is equal to one
    do    
    {
        sum = 0; 
        //loop to sum up the sqaure of each digit in the number
        while( n > 0)
        {
            sum += pow(n%10,2);
            n = n/10;
        }
        //Happy number condition
        if( sum == 1) return true;
        //If calucaltes Sum alreay been registered previously, the number is not happy 
        else if(find(regSum.begin(),regSum.end(),sum) != regSum.end()) return false;
        //registerd the sum for checking the future number
        regSum.push_back(sum);
        //upadte the the number with recent calculate sum
        n = sum;
        
    }while( sum != 1);

    //By default - It's not happy number
    return false;    
}

int main(void)
{
    int number = 47;
    cout<<"Number "<<number<<" is happy : "<<(isHappy(number)?"Yes":"No")<<endl;
    return 0;
}
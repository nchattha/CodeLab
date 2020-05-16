/*
 File contains the implementation of the function pointer. 
 Also, depict the working of Templates
*/
#include <iostream>
#include <vector>
 
using namespace std;
// function for finding to Odd Number
template <class type>
bool isNumberOdd( type val)
{
    return (((int)val % 2)!= 0);
}
// function for finding to Even Number
template <class type>
bool isNumberEven( type val)
{
    return (((int)val % 2) == 0);
}
// function for count the number as per the criteria
template <class iterator, class type>
int count_function(iterator start, iterator end, bool (*cirteria)(type))
{
    int count = 0; 
    for(;start != end; ++start)
    {
        if(cirteria(*start))
            count++;
    }
    return count;
}
//Staring point
int main(void)
{
    vector<int> dataI;
    dataI.push_back(2);
    dataI.push_back(5);
    dataI.push_back(3);
    dataI.push_back(6);
    dataI.push_back(7);
    dataI.push_back(4);
    dataI.push_back(8);
    dataI.push_back(9);
    dataI.push_back(14);
    vector<float> dataF;
    dataF.push_back(2.0);
    dataF.push_back(5.0);
    dataF.push_back(3.0);
    dataF.push_back(6.0);
    dataF.push_back(7.0);
    dataF.push_back(4.0);
    dataF.push_back(8.0);
    dataF.push_back(9.0);
    dataF.push_back(14.0);
    cout << "Function Pointer as per C" << endl;
    cout <<" Even number count in Vector Int :"<< count_function(dataI.begin(),dataI.end(),(isNumberEven<int>))<<endl;
    cout <<" Even number count in Vector Float:"<< count_function(dataF.begin(),dataF.end(),(isNumberEven<float>))<<endl;
    cout <<" Odd number count in Vector Int :"<< count_function(dataI.begin(),dataI.end(),(isNumberOdd<int>))<<endl;
    cout <<" Odd number count in Vector Float:"<< count_function(dataF.begin(),dataF.end(),(isNumberOdd<float>))<<endl;

    return 0;
}
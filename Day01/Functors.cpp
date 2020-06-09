/*
 File contains the implementation of the functors. 
 Also, depict the working of Templates
*/
#include <iostream>
#include <vector>
 
using namespace std;
////////////////////////////////////////////
//Implement functors to do range calculation
class BaseFunctor
{
    protected: 
            int startRange, endRange;
            bool isRange;
    public:        
            virtual bool operator()(int) = 0;
};
// Child classes to inherit & implement the BaseFunctor
template <class type>
class EvenFunctor : public BaseFunctor
{
    public:
            EvenFunctor()
            {
                isRange = false;
            }
            EvenFunctor(int pStartRange, int pEndRange)
            {
                startRange = pStartRange;
                endRange = pEndRange;
                isRange = true;
            }
            //overiding the function for checking EVEN number
            bool operator()(type pValue)
            {
                if( !isRange)
                {//If range not applied, do the even check directly
                    return (((int)pValue % 2) == 0);
                }
                else 
                {// check within the range and also the number is even or not 
                    if( pValue >= startRange &&
                    pValue <= endRange )
                    return (((int)pValue % 2) == 0);
                }
                return false;
            }
};
///////////////////////////////////////////
// function for count the number as per the criteria
template <class iterator, class type>
int count_function(iterator start, iterator end, type cirteria)
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

    EvenFunctor <int>objEven;
    EvenFunctor <int>objEvenRange(2,5);

    cout << "Function Pointer as per C" << endl;
    cout <<" Even number count in Vector Int Without Range:"<< count_function(dataI.begin(),dataI.end(),objEven)<<endl;
    cout <<" Even number count in Vector Int With Range:"<< count_function(dataF.begin(),dataF.end(),objEvenRange)<<endl;

    return 0;
}
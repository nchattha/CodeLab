/** File contain multiple recusrion example using PMI(Principle of mathematical Induction)
 */
#include<iostream>
#include<math.h>
using namespace std;

int countDigits(int number)
{
    if( number == 0) return 0;
    return countDigits(number/10)+1;
}

int calcPower(int number, int power)
{
    if(power == 0) return 1;
    return calcPower(number,power-1)*number;
}

void printNumberSeriesDESC(int number)
{
    if(number == 0) return ;
    cout<<number<<endl;
    printNumberSeriesDESC(number-1);
}

void printNumberSeriesASC(int number)
{
    if(number == 0) return ;
    printNumberSeriesASC(number-1);
    cout<<number<<endl;
}
int sumOfDigits(int number)
{
    if( number == 0) return number;
    return sumOfDigits(number/10)+number%10;
} 

int multiplication(int lValue, int rValue)
{
    if( rValue == 0 ) return 0;
    return multiplication(lValue,rValue-1)+lValue;
}
int countZero(int number)
{
    if( number == 0 ) return 0;
    int smallAns = countZero(number/10);

    if(number%10 == 0)
    {
        return ++smallAns;
    }
    return smallAns;
}

double geometricSum(int number, int power)
{
    if(power == 0 )return 1.0f;
    return geometricSum(number,power-1)+(1.0/pow(number,power));
    
}
int main(void)
{
    cout<<"Count Digits: "<<countDigits(1562)<<endl;
    cout<<"Power Digits: "<<calcPower(2,3)<<endl;
    cout<<"Print DESC Number: "<<endl;
    printNumberSeriesDESC(4);
    cout<<"Print ASC Number: "<<endl;
    printNumberSeriesASC(5);
    cout<<"Sum Digits: "<<sumOfDigits(4332)<<endl;
    cout<<"Multiplication: "<<multiplication(4,4)<<endl;
    cout<<"Count Zero: "<<countZero(1204050)<<endl;
    cout<<"Geometric Sum: "<<geometricSum(3,2)<<endl;
    return 0;
}
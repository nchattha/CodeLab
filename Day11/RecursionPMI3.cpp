#include<iostream>
using namespace std;

 void removeConsecutiveDuplicates(char data[])
 {
    if( data == NULL ||
    data[0] == '\0' ||
    data[1] == '\0') return ;

    if( data[0] == data[1])
    {
        int i = 0;
        while(data[i] != '\0' )
        {
            data[i] = data[i+1];
            i++;
        }
        cout<<i<<endl;
        return removeConsecutiveDuplicates(data);
    }
    else
    {
        return removeConsecutiveDuplicates( data+1);
    }
}

void printSubsequenceOfArray(string input, string output)
{
    if( input.length() == 0) {
       cout<<output<<endl;
    }
    else
    {
        printSubsequenceOfArray(input.substr(1),output);//exclude
        printSubsequenceOfArray(input.substr(1),output+input[0]);//include
    }    
}

int convertStringToInteger(char data[], int size)
{
    if( size == 0 ) return 0;
    return convertStringToInteger(data,size-1)*10 + (data[size-1]-'0');
}

void swap(char &lValue, char &rValue)
{
    char temp = rValue;
    rValue = lValue;
    lValue = temp;
}
void permutation(char data[], int i)
{
    if(data[i] == '\0')
    {   cout<<data<<endl; 
        return;
    }
    else
    {
        for( int j = i; data[j] != '\0' ; j++)
        {
            swap(data[i],data[j]);
            permutation(data,i+1);
            swap(data[i],data[j]);
        }
    }
}

int staircaseProblem(int steps)
{
    if( steps == 0 || steps == 1) 
    {
        return 1;
    }
    if( steps<0) return 0;
    return staircaseProblem(steps-1) + staircaseProblem(steps-2) + staircaseProblem(steps-3);
}

int towerOfHanoi(int n)
{
    if( n == 0 ) return 0;
    return  towerOfHanoi(n-1)+1+towerOfHanoi(n-1);
}

void printTowerOfHanoi(int n, char source, char dest, char helper)
{
    if( n == 0 ) return;
    
    printTowerOfHanoi(n-1,source,helper,dest);
    cout<<"Moving Disk "<<n<<" from "<<source<<" -> "<<dest<<endl;
     printTowerOfHanoi(n-1, helper, dest, source);
}

int main(void)
{
    char data[]("aabb");
    removeConsecutiveDuplicates(data);
    cout<<"Removig consecutive diplicates: "<<data<<endl;
    string input="abc";
    string output="";
    cout<<"Print Subsequence Of Array: "<<output<<endl;
    printSubsequenceOfArray(input,output);
    char data1[]("12345");
    cout<<"Convert String To Int: "<<convertStringToInteger(data1,5)<<endl;
    char data2[]("abcd");
    cout<<"Permutaiton for Data :"<<endl; 
    permutation(data2,0);
    cout<<"Stair case problem: "<<staircaseProblem(4)<<endl;
    cout<<"Tower Of Hanoi: "<<towerOfHanoi(3)<<endl;
    printTowerOfHanoi(3,'A','C','B');
    return 0;
}
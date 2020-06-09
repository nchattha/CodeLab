#include<iostream>
using namespace std;
//check array is sorted
bool isArraySorted(int arr[], int size)
{
    if( size == 0 || size == 1) return true;
    if(arr[size-2] > arr[size-1]) return false;
    return isArraySorted(arr,size-1);
}

int sumOfArray(int arr[],int size)
{
    if( size == 0 )return 0;
    return sumOfArray(arr,size-1)+arr[size-1];
}

bool checkElementPresent(int arr[],int n, int ele)
{
    if( n == 0 ) return false;
    //checking from first
    // if(arr[0] == ele ) return true;
    // return checkElementPresent(arr+1,n-1,ele);
    //checking from end
    if(arr[n-1] == ele ) return true;
    return checkElementPresent(arr,n-1,ele);
}

int firstIndexOfElement(int arr[],int n, int ele ,int index)
{
    if ( n == 0 || index == n) return -1;
    if( arr[index] == ele ) return index+1;
    return firstIndexOfElement(arr,n,ele,index+1);
}

int lastIndexOfElement(int arr[],int n, int ele ,int index)
{
    if ( n == 0 || index == 0) return -1;
    if( arr[index-1] == ele ) return index;
    return lastIndexOfElement(arr,n,ele,index-1);
}

void printAllPositionOfElement(int arr[],int n, int ele ,int index)
{
    if ( n == 0 || index == n) return;
    if( arr[index] == ele ) cout<<index+1<<endl;
    return printAllPositionOfElement(arr,n,ele,index+1);
}

void countOccurenceOfElement(int arr[],int n, int ele ,int &count)
{
    if ( n == 0 ) return;
    if( arr[n-1] == ele ) ++count;
    return countOccurenceOfElement(arr,n-1,ele,count);
}

int storeAllOccurenceOfElement(int arr[],int n, int ele ,int output[], int j)
{
    if ( n == 0 ) return 0;
    if( arr[n-1] == ele )
    {
        output[j] = n;
        return 1 + storeAllOccurenceOfElement(arr,n-1,ele,output,j+1);
    }
    else
        return 0 + storeAllOccurenceOfElement(arr,n-1,ele,output,j);
}
bool palindrome(string data,int sIndex, int eIndex)
{
    if( sIndex > eIndex) return true;
    if( data[sIndex] == data[eIndex-1]) return palindrome(data, ++sIndex, --eIndex);
    return false;
}

int main(void)
{
    int data[] = {1,2,3,4,5};
    cout<<"Array Sorted: "<<isArraySorted(data,5)<<endl;
    cout<<"Sum Of Array: "<<sumOfArray(data,5)<<endl;
    cout<<"Check Element: "<<checkElementPresent(data,5,2)<<endl;
    int data1[] = {1,3,3,4,5};
    cout<<"First Index of Element: "<<firstIndexOfElement(data1,5,3,0)<<endl;
    cout<<"Last Index of Element: "<<lastIndexOfElement(data1,5,3,5)<<endl;
    cout<<"Print All Pos of Element: "<<endl;
    printAllPositionOfElement(data1,5,3,0);
    int count = 0;
    countOccurenceOfElement(data1,5,3,count);
    cout<<"Count Occurence of All Element: "<<count<<endl;
    int arr[5];
    count = storeAllOccurenceOfElement(data1,5,3,arr,0);
    cout<<"Print Occurence of All Element: "<<count<<endl;
    for(int i = count-1; i >= 0 ; i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Palindrome : "<<palindrome("abcba",0,5)<<endl;
    return 0;
}
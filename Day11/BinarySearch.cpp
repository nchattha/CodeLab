#include<iostream>
using namespace std;

bool bSearchWithRec(int a[], int s, int e, int ele)
{
    if( s>= e) return false;

    int mid = (e-s)/2;
    if( a[mid] > ele)
        return bSearchWithRec( a, mid+1, e, ele);
    else if( a[mid] < ele)
        return bSearchWithRec( a, s, mid, ele);
    else
        return true;
}

int bSearchWithoutRec(int a[], int e, int ele)
{
    int s = 0, mid = 0;
    
    while(s <= e)
    {
        mid = s+ ((e-s)/2);
        if( a[mid] > ele)
            e = mid-1;
        else if( a[mid] < ele)
            s = mid+1;
        else 
            return mid;   
    }
    return -1;
}


int main(void)
{
    int a[] = {1,2,3,4,5};
    cout<<"Search : "<<bSearchWithRec(a,0,4,3)<<endl;
    cout<<"Search : "<<bSearchWithoutRec(a,4,4)<<endl;
    return 0;
}
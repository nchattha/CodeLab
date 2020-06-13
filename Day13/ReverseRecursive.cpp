#include<iostream>
#include<vector>
using namespace std;

void swap(char &lValue, char &rValue)
    {
        cout<<"L: "<<lValue<<"R: "<<rValue<<endl;
        int temp = rValue;
        rValue = lValue ;
        lValue = temp;
    }
    
    void reverseString(vector<char>& s, int i)
    {
        int e = s.size()-1;
        if( e == 0 || i > (e/2)) return;
        
        swap(s[i],s[e-i]);    

        reverseString(s, ++i);
    }
    
    void reverseString(vector<char>& s) {
        reverseString(s,0);
    }

int main(void)
{
    vector<char>data = {'h','e','l','l','o'};
    reverseString(data);
    for(char d:data)
    cout<<d<<" ";
    cout<<endl;
    return 0;
}
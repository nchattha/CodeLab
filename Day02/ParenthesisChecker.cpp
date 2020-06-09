#include<stack>
#include<iostream>
#include<exception>

using namespace std;
bool checkLatestRegisteredExpr(char pCheckValue, char pRegisteredValue)
{
     bool valid = false; 
    switch(pCheckValue)
    {
        case ')' : valid = (pRegisteredValue == '(');
        break;
        case ']' : valid = (pRegisteredValue == '[');
        break;
        case '}' : valid = (pRegisteredValue == '{');
        break;
        default: valid = false;
    }
    return valid;
}

bool isValidExpr(string pStr)
{
    stack<char> charExpr;
    int chIndex = 0;
    bool valid = true; 
    while(chIndex < pStr.size())
    {   //Skip the numbers. Only look for the Parenthesis   
        if(pStr[chIndex] == '[' || 
            pStr[chIndex] == '(' ||
            pStr[chIndex] == '{' )
        {
            charExpr.push(pStr[chIndex]);
        }
        else if(pStr[chIndex] == ']' || 
            pStr[chIndex] == ')' ||
            pStr[chIndex] == '}' )
        {
            //Invalid Case: First occurence is the closing Brackets
            if(charExpr.empty()){
                //Means the equation have incorrect parenthesis 
                cout<<"ERROR: Equation Started with Wrong parenthesis - InValid Expression"<<endl;
                valid = false;
                break;      
            }
            //Invalid Case: Check for the exp w.r.t latest registererd value in stack
            else if(!checkLatestRegisteredExpr(pStr[chIndex],charExpr.top()))
            {
                //Means the equation have incorrect parenthesis 
                cout<<"ERROR: Wrong parenthesis ended - expected "<<charExpr.top()<<" paranthesis - InValid Expression"<<endl;
                valid = false;
                break;
            }
            //Valid Case: exp matched w.r.t latest registererd value in stack
            else
            {
                //Need to remove it from stack
                charExpr.pop();
            }
        }
        ++chIndex;
    }

    //Invalid Case: registered stack still have unclosed parenthesis
    if( !charExpr.empty() ) 
    {
        string errorStr("");
        while(!charExpr.empty()){
            errorStr += charExpr.top();
            charExpr.pop();
            if( charExpr.empty())
                errorStr += " , ";
        }
        valid = false;
        cout<<"Error: "<<errorStr<<" Parenthesis not ended - InValid Expression"<<endl;
    }
    //return the validity of the equation
    return valid;
}
int main(void)
{
    string str = "(}(A+ (b*c) +[a+S])";
    if(isValidExpr(str))
        cout<<"Valid Expression"<<endl;
    
    return 0;
}
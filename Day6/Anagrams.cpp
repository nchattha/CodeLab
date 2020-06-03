/*Given an array of strings, group anagrams together.

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
All inputs will be in lowercase.
The order of your output does not matter. */
#include <iostream>
#include <vector>
using namespace std;

void swapData(string &left, string &right)
{
  string temp;
  temp = right;
  right = left;
  left = temp;
}

//comparator function for the std::sort
bool compStr(const char left, const char right)
{
  return left<right;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  vector<vector<string>> result;
  string leftValue;
  //sort the streing by the character
  //Reason - to compare and collect the anagrams
  vector<string>dataStr(strs);
  for( int i = 0; i < dataStr.size() ; i++)
    sort(dataStr[i].begin(),dataStr[i].end(),compStr);
  //traverse the original string and used for geneerating result
  //use the sorted string to compare 
  for (int index = 0; index < strs.size(); index++)
  {
    vector<string> data;
    data.push_back(strs[index]);
    leftValue = dataStr[index];
    for (int j = index + 1; j < strs.size(); j++)
    {
      if (leftValue == dataStr[j] )
      {
        data.push_back(strs[j]);
        index++;
        swapData(strs[index], strs[j]);
        swapData(dataStr[index], dataStr[j]);
      }
    }
    result.push_back(data);
  }
  return result;
}


int main(void)
{
  vector<string> data;
  data.push_back("eat");
  data.push_back("tea");
  data.push_back("tan");
  data.push_back("ate");
  data.push_back("nat");
  data.push_back("bat");
  data.push_back("cab");
  data.push_back("tin");
  data.push_back("pew");
  data.push_back("duh");
  data.push_back("may");
  data.push_back("ill");
  data.push_back("buy");
  data.push_back("bar");
  data.push_back("max");
  data.push_back("doc");

  cout << "Input Data :";
  for (auto num : data)
    cout << num << "\t";
  cout<<endl;

  vector<vector<string>> result = groupAnagrams(data);
  cout << "\nOutput : "<<result.size()<<endl;
  for (auto row : result)
    for (auto cell : row)
      cout << cell << "\t";
    cout << endl;
  return 0;
}
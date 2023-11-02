#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int flags[10];
vector<string> ans;

void setFlags()
{
    for(int i=0; i<10; i++)
        flags[i] = 0;
}

void retPer(string str, string temp, int len, int ind)
{
    if(ind == len)
    {
        ans.push_back(temp);
        return;
    }

    for(int i=0; i<len; i++)
    {
        if(flags[i] == 0)
        {
            //string temp1 = temp;
            temp = temp + str[i];
            flags[i] = 1;

            retPer(str, temp, len, ind+1);

            temp.pop_back();
            flags[i] = 0;
        }
    }
}

int main()
{
    string str = "ABC";
    int len = str.length();

    retPer(str, "", len, 0);

    for(auto i=ans.begin(); i!=ans.end(); i++)
    {
        cout<<*i<<endl;
    }

    return 0;
}
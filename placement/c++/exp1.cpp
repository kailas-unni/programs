#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string abc = "10#20#31#";
    string ans = "";
    int num;
    char ch;
    for(int i=0; i<abc.length();i++)
    {
        if(abc[i+2]=='#')
        {
            num = 0;
            num = int(abc[i]-'0');
            num = num*10 + int(abc[i+1]-'0') - 1;
            cout<<"Num : "<<num<<endl;
            ch = char(num) + 'a';
            i=i+2;
        }
        else
        {
            ch = char(int(abc[i]-'0') - 1) + 'a';
        }
        cout<<ch<<endl;
        ans = ans+ch;
    }
    cout<<ans;
    return 0;
}
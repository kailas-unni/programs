#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void findAll(vector<int> inpp, vector<string> arr, set<set<string>> &ans, vector<int> &flags, vector<int> &temp, set<string> &tempans)
{

    int check = 0;
    for(int i=0; i<26; i++)
    {
        if(inpp[i] != temp[i])
        {
            check=1;
            break;
        }
    }
    if(check == 0)
    {
        ans.insert(tempans);
        for(auto i=tempans.begin(); i!=tempans.end(); i++)
        {
            cout<<*i<<", ";
        }
        cout<<endl;
    }

    vector<int> temp1(26,0);
    for(int i=0; i<arr.size(); i++)
    {
        if(flags[i] == 0)
        {
            temp1 = temp;
            flags[i] = 1;
            for(int j=0; j<arr[i].size(); j++)
            {
                temp[arr[i][j]-97]++;  
            }

            check = 0;
            for(int j=0; j<26; j++)
            {
                if(inpp[j] == 0 && temp[j] != 0)
                {
                    temp = temp1;
                    check = 1;
                    break;
                }
            }
            if(check == 0)
            {
                tempans.insert(arr[i]);
                for(int k=0; k<26; k++)
                {
                    if(temp[k]!=0)
                        cout<<char('a'+k)<<" : "<<temp[k]<<", ";   
                }
                cout<<endl;
                findAll(inpp, arr, ans, flags, temp, tempans);
                flags[i] = 0;
                temp = temp1;
                for(int k=0; k<26; k++)
                {
                    if(temp[k]!=0)
                        cout<<char('a'+k)<<" : "<<temp[k]<<", ";   
                }
                cout<<endl;
                tempans.erase(arr[i]);
                // for(auto m = tempans.begin(); m!=tempans.end(); m++)
                // {
                //     if(*m == arr[i])
                //     {
                //         tempans.erase(m);
                //         break;
                //     }
                // }
            }
        }
    }
}

int main()
{
    // string inp = "abcz";
    string inp = "abinsn";
    vector<string> arr;
    set<set<string>> ans;
    arr.push_back("abs");
    arr.push_back("inn");
    arr.push_back("krnof");
    arr.push_back("nfo");
    arr.push_back("kr");
    arr.push_back("in");
    arr.push_back("n");


    vector<int> inpp(26,0);
    vector<int> temp(26,0);
    vector<int> flags(arr.size(), 0);
    set<string> tempans;

    for(int i=0; i<inp.size(); i++)
    {
        inpp[inp[i]-97]++;   
    }

    findAll(inpp, arr, ans, flags, temp, tempans);

    // for(int i=0; i<26; i++)
    // {
    //     cout<<char('a'+i)<<" : "<<inpp[i]<<endl;   
    // }

    for(auto const &i:ans)
    {
        for(auto const &j:i)
        {
            cout<<j<<", ";
        }
        cout<<endl;
    }

    // for(int i=0; i<ans.size(); i++)
    // {
    //     for(int j=0; j<ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j]<<", ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
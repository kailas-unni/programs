#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> removedup(vector<int> arr, int size)
{
    unordered_map<int,bool> seen;
    vector<int> ans;
    for(int i=0; i<size; i++)
    {
        if(seen.count(arr[i])>0)
            continue;
        seen[arr[i]] = true;
        ans.push_back(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,2,4,3,1,5,2,3,6};
    vector<int> ans = removedup(arr, 10);
    for(auto i=ans.begin(); i!=ans.end(); i++)
    {
        cout<<*i<<"  ";
    }
    return 0;
}
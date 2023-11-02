//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    string rev(string str)
    {
        for(int i=0; i<str.length()/2; i++)
        {
            swap(str[i], str[i-str.length()-1]);
        }
        return str;
    }
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans = "";
        int i=0;
        while(ans[i]!=NULL)
        {
            int j=i;
            string temp="";
            while(ans[j]!='.' || ans[j]!=NULL)
            {
                temp = temp+ans[j];
                j++;
            }
            ans = temp + ans;
            if(ans[j] == NULL)
                ans = "." + ans;
            i=j;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
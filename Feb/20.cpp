/*
Author : Ashish Kumar
Date : 20/02/2024
Problem : Word Break
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/word-break1352/1
*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings
class Solution
{
public:
bool help(string A,vector<string> &B,int index){
        if(index==A.length())return true;
        string temp="";
        bool a = false;
        for(int i=index;i<A.length();i++){
            temp+=A[i];
            for(int j=0;j<B.size();j++){
                if(B[j]==temp){
                    a = a|help(A,B,i+1);
                    break;
                }
            }
        }
        return a;
    }
    int wordBreak(int index , string A, vector<string> &B) {
        //code here
        return help(A,B,0);
    }
};
//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends

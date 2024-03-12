/*

Author : Ashish Kumar
Date : 12/03/2024
Problem : Generalised Fibonacci numbers
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/generalised-fibonacci-numbers1820/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        vector<vector<long long>> transition(3, vector<long long>(3, 0));
        transition[0][1] = b;
        transition[1][0] = 1;
        transition[1][1] = a;
        transition[2][1] = 1;
        transition[2][2] = 1;

        vector<long long> state = {1, 1, c};

        transition = matPow(transition, n - 1, m);
        state = prod(state, transition, m);
        return state[0];
    }

private:
    vector<vector<long long>> matPow(vector<vector<long long>>& m1, long long powl, long long mod) {
        vector<vector<long long>> res;
        while (powl > 0) {
            if (powl & 1) {
                if (res.empty()) {
                    res = m1;
                }
                else {
                    res = prod(res, m1, mod);
                }
            }
            powl >>= 1;
            if (powl > 0) {
                m1 = prod(m1, m1, mod);
            }
        }
        return res;
    }

    vector<vector<long long>> prod(vector<vector<long long>>& m1, vector<vector<long long>>& m2, long long mod) {
        int n = m1.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long temp = 0;
                for (int k = 0; k < n; k++) {
                    temp = (temp + ((m1[i][k] * m2[k][j]) % mod)) % mod;
                }
                res[i][j] = temp;
            }
        }
        return res;
    }

    vector<long long> prod(vector<long long>& v, vector<vector<long long>>& m, long long mod) {
        int n = v.size();
        vector<long long> res(n, 0);
        for (int i = 0; i < n; i++) {
            long long temp = 0;
            for (int k = 0; k < n; k++) {
                temp = (temp + ((v[k] * m[k][i]) % mod)) % mod;
            }
            res[i] = temp;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends

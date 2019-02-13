#include "pch.h" 
#include <iostream> 
using namespace std; 
  
#define printf 
  
const int MAX_M = 10000; 
  
  
int dp[MAX_M + 1]; 
  
int n, m; 
  
const int MAX_N = 5000; 
int P[MAX_N+1]; 
int C[MAX_N+1]; 
  
int max(int a, int b) 
{ 
    return a > b ? a : b; 
} 
  
int recur(int money) 
{ 
    printf("[recur] money:%d\n", money); 
  
    int & memo = dp[money]; 
    if (memo) 
    { 
        printf("return dp[%d]:%d by memoization\n", money, dp[money]); 
        return memo; 
    } 
  
    for (int i=0; i < n; ++i) 
    { 
        if (money - P[i] >= 0) 
            memo = max(memo, recur(money - P[i]) + C[i]); 
    } 
  
    printf("store dp[%d]:%d\n", money, dp[money]); 
  
    return memo; 
} 
  
  
int dploop() 
{ 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = P[i]; j <= m; j++) 
        { 
            printf("max(dp[%d]:%d, dp[%d - P[%d]:%d]:%d + C[%d]:%d\n", 
                j,dp[j],j,i,P[i],dp[j-P[j]],i,C[j]); 
  
            dp[j] = max(dp[j], dp[j - P[j]] + C[j]);             
            printf("store dp[%d]:%d\n", j, dp[j]); 
        } 
    } 
    printf("return dp[%d]:%d\n", m, dp[m]); 
    return dp[m]; 
} 
  
int main() 
{ 
    FILE* file; 
    freopen_s(&file, "input.txt", "r", stdin); 
  
    while (true) 
    { 
        cin >> n; 
        double dm; 
        cin >> dm; 
        m = dm * 100; 
  
        //cout << n << "," << m << endl; 
  
        if (n == 0) 
        { 
            break; 
        } 
  
        for (int i = 0; i < n; i++) 
        { 
            cin >> C[i];             
  
            double tmp; 
            cin >> tmp; 
            P[i] = tmp * 100; 
  
            printf("C[%d]:%d,P[%d]:%d\n", i, C[i], i, P[i]); 
        } 
  
        for (int i = 0; i < MAX_M + 1; i++) 
            dp[i] = 0; 
  
        //cout << recur(m) << endl; 
        cout << dploop() << endl; 
                 
    } 
     
    fclose(file); 
} 

// lotto2.cpp : This file contains the 'main' function. Program execution begins and ends there. 
// 
  
#include "pch.h" 
#include <iostream> 
using namespace std; 
  
int n, m; 
const int MAX_N = 10; 
const int MAX_M = 2000; 
  
int dp[MAX_N][MAX_M]; 
  
#define printf 
  
int getMaxWithCount(int count) 
{ 
    printf("[getMaxWithCount] count:%d ", count); 
  
    int ret = m; 
    for (int i = 0; i < n - count; i++) 
    { 
        ret /= 2; 
    } 
  
    printf("return %d\n", ret); 
  
    return ret; 
} 
  
int recur(int count, int prevNum) 
{ 
    printf("[recur] count:%d, prevNum:%d\n", count, prevNum); 
  
    if (count == n) 
        return 1; 
  
    int & memo = dp[count][prevNum]; 
  
    if (memo) 
    { 
        printf("return memo:%d with dp[%d][%d]\n", memo, count, prevNum); 
        return memo; 
    } 
  
    for (int i = prevNum * 2; i <= getMaxWithCount(count+1); i++) 
    { 
        memo += recur(count + 1, i); 
    } 
  
    printf("store dp[%d][%d]:%d\n", count, prevNum, dp[count][prevNum]); 
  
    return memo; 
} 
  
  
int main() 
{ 
    FILE* file; 
    freopen_s(&file, "input.txt", "r", stdin); 
  
    int T; 
    cin >> T; 
    for (int tc = 1; tc <= T; tc++) 
    { 
        cin >> n >> m; 
         
        for (int i = 0; i < MAX_N; ++i) 
            for (int j = 0; j < MAX_M; ++j) 
                dp[i][j] = 0; 
  
        int sum = 0; 
        for (int i = 0; i < getMaxWithCount(1); i++) 
        { 
            sum += recur(1, i+1); 
        } 
        cout << sum << endl; 
    } 
  
    fclose(file); 
} 

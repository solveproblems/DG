// TSP2.cpp : This file contains the 'main' function. Program execution begins and ends there. 
// 
  
#include "pch.h" 
#include <iostream> 
using namespace std; 
  
int N; 
const int MAX_N = 16; 
  
int W[MAX_N][MAX_N]; 
int dp[MAX_N][1<<MAX_N]; 
  
const int MAX_DIST = MAX_N * MAX_N * 1000000; 
  
//#define printf 
  
int min(int a, int b) 
{ 
    return a < b ? a : b; 
} 
  
int TSP(int cur, int visit, int distance) 
{ 
    printf("[TSP] cur:%d,visit:%d,distance:%d\n", cur, visit, distance); 
  
    //if (visit == 1 << N - 1) 
    if (visit == (1 << N) - 1) 
    { 
        printf("visited all & return distance:%d + W[%d][0]:%d\n", distance, cur, W[cur][0]); 
        if (W[cur][0]) 
        { 
            //return distance + W[cur][0]; 
            return W[cur][0]; 
        } 
        else 
        { 
            return MAX_DIST; 
        } 
    } 
  
    int & memo = dp[cur][visit]; 
    if (memo) 
    { 
        printf("return dp[cur:%d][visit:%d]:%d by memoization\n", 
            cur, visit, dp[cur][visit]); 
  
        return memo; 
    } 
  
    //int MIN = MAX_DIST; 
    memo = MAX_DIST; 
  
    for (int i = 1; i < N; ++i) 
    { 
        if (!(visit & (1 << i)) && W[cur][i]) 
        { 
            //MIN = min(TSP(i, visit | (1 << i), distance + W[cur][i]), MIN); 
            //memo = min(TSP(i, visit | (1 << i), distance + W[cur][i]), memo); 
            memo = min(TSP(i, visit | (1 << i), distance + W[cur][i])+W[cur][i], memo); 
        } 
    } 
  
    //return memo = MIN; 
    return memo; 
} 
  
  
int main() 
{ 
    FILE* file; 
    freopen_s(&file, "input.txt", "r", stdin); 
  
    cin >> N; 
    for (int i = 0; i < N; ++i) 
    { 
        for (int j = 0; j < N; ++j) 
        { 
            cin >> W[i][j]; 
        } 
    } 
  
    cout << TSP(0, 1, 0); 
  
    fclose(file); 
} 

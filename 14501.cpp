// leaving company.cpp : This file contains the 'main' function. Program execution begins and ends there. 
// 
  
#include "pch.h" 
#include <iostream> 
using namespace std; 
  
int N; 
const int MAX_N = 15; 
struct Consult 
{ 
    int date; 
    int T; 
    int P; 
  
    int getEnd() { return date + T -1;  } 
  
} schedule[MAX_N]; 
  
  
#define printf 
  
void display_Consult(Consult & c) 
{ 
    printf("date:%d,T:%d,P:%d,End:%d\n", c.date, c.T, c.P, c.getEnd()); 
} 
  
void display_schedule() 
{ 
    for (int i = 0; i < N; i++) 
    { 
        printf("[idx:%d] ", i); 
        display_Consult(schedule[i]); 
    } 
} 
  
void qsort(int start, int end) 
{ 
    //printf("[qsort] start:%d, end:%d\n", start, end); 
  
    if (start >= end) return; 
  
    int Key = start; 
    int L = start+1; 
    int R = end; 
  
    while (L <= R) 
    {         
        while (L <= end && 
            (schedule[L].getEnd() < schedule[Key].getEnd() || 
            (schedule[L].getEnd() == schedule[Key].getEnd() && schedule[L].P <= schedule[Key].P))) 
                L++; 
  
        // do not include start(R>=start+1) which is the key value 
        while (R >= start+1 &&  
            (schedule[R].getEnd() > schedule[Key].getEnd() || 
            (schedule[R].getEnd() == schedule[Key].getEnd() && schedule[R].P >= schedule[Key].P)))             
                R--; 
  
        if (L <= R) 
        { 
            Consult tmp = schedule[L]; 
            schedule[L] = schedule[R]; 
            schedule[R] = tmp; 
        } 
        else 
        {// L & R crossed, exchange Key & R 
            Consult tmp = schedule[R]; 
            schedule[R] = schedule[Key]; 
            schedule[Key] = tmp; 
        } 
    } 
     
    qsort(start, R - 1); 
    qsort(R + 1, end); 
} 
  
int dp[MAX_N]; 
  
int max(int a, int b) 
{ 
    return a > b ? a : b; 
} 
  
int previous(int idx) 
{ 
    for (int i = idx-1; i >= 0; --i) 
    { 
        if (schedule[i].getEnd() < schedule[idx].date) 
        { 
            return i; 
        } 
    } 
  
    return -1; 
} 
  
int solve() 
{ 
    dp[0] = schedule[0].getEnd() < N + 1 ? schedule[0].P : 0; 
    int i = 0; 
    for (i = 1; i < N; ++i) 
    { 
        int prev = previous(i); 
        printf("prev:%d\n", prev); 
                 
        if (schedule[i].getEnd() < N+1) 
        { 
            dp[i] = max(dp[i - 1], prev == -1 ? schedule[i].P : dp[previous(i)] + schedule[i].P); 
            printf("dp[%d]:%d = max(dp[%d]:%d,prev:%d,schedule[%d].P:%d\n", 
                i, dp[i], i - 1, dp[i - 1], prev, i, schedule[i].P); 
        } 
        else 
        { 
            dp[i] = dp[i - 1]; 
        } 
    } 
  
    printf("return dp[%d]:%d\n", i-1, dp[i-1]); 
    return dp[i-1]; 
} 
  
int main() 
{ 
    FILE* file; 
    freopen_s(&file, "input3.txt", "r", stdin); 
  
    cin >> N; 
    for (int i = 0; i < N; ++i) 
    {         
        cin >> schedule[i].T >> schedule[i].P; 
        schedule[i].date = i + 1; 
    } 
  
    display_schedule(); 
    qsort(0, N - 1); 
    printf("after sorting\n"); 
    display_schedule(); 
    cout << solve(); 
    fclose(file); 
} 

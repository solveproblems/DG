#include "pch.h" 
#include <iostream> 
using namespace std; 
  
int N, M; 
const int MAX_SIZE = 301; 
  
int m[MAX_SIZE][MAX_SIZE]; 
int d[MAX_SIZE][MAX_SIZE]; 
  
int max(int a, int b) 
{ 
    return a > b ? a : b; 
} 
  
int main() 
{ 
    FILE* file; 
    freopen_s(&file, "input.txt", "r", stdin); 
  
    cin >> N >> M; 
     
    for (int i = 1; i <= N; ++i) 
    { 
        for (int j = 1; j <= M; ++j) 
        { 
            cin >> m[i][j]; 
        } 
    } 
  
    d[0][0] = 0; 
    for (int i = 1; i < M; ++i) 
    { 
        d[0][i] = m[0][i]; 
    } 
     
    for (int i = 1; i <= N; ++i) 
    { 
        for (int j = 1; j <= M; ++j) 
        { 
            d[i][j] = max(d[i-1][j],d[i][j-1]) + m[i][j]; 
        } 
    } 
  
    cout << d[N][M] << endl; 
  
    fclose(file); 
} 

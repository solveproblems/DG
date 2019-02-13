#include <iostream>  
#include <algorithm>  
using namespace std; 
  
long int d[25][25]; 
int n, m, k; 
  
int main() 
{ 
    cin >> n >> m >> k; 
  
    for (int i = 1; i <= 20; i++) 
        d[1][i] = 1, d[i][1] = 1; 
  
    for (int i = 2; i <= 20; i++) { 
        for (int j = 2; j <= 20; j++) { 
            d[i][j] = d[i - 1][j] + d[i][j - 1]; 
        } 
    } 
    if (k == 0) 
        cout << d[n][m] << '\n'; 
    else { 
        int kx = (k % m == 0) ? m : k % m; 
        int ky = (k - 1) / m + 1; 
        //printf("kx:%d,ky:%d\n", kx, ky); 
         
        cout << d[ky][kx] * d[n - ky + 1][m - kx + 1] << '\n'; 
    } 
    return 0; 
} 

#include "pch.h" 
#include <iostream> 
using namespace std; 
  
const int MAX_N = 100; 
int N; 
  
int m[MAX_N][MAX_N]; 
bool v[MAX_N][MAX_N]; 
  
//int section_cnt; 
  
struct DIR { int dx, dy; } dir[4] ={{-1,0}, {1, 0}, {0, -1}, {0,1}}; 
  
#define printf 
  
void clear_visit() 
{ 
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j) 
            v[i][j] = 0; 
} 
void display_v() 
{ 
    printf("[display_v]\n"); 
    for(int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            printf("%d", v[i][j]); 
        } 
        printf("\n"); 
    } 
} 
bool isRange(int x, int y) 
{ 
    if (x >= 0 && x < N && y >= 0 && y < N) 
    { 
        return true; 
    } 
    else 
        return false; 
} 
  
  
bool isRG(int a, int b) 
{ 
    printf("[isRG] %c(%d),%c(%d)\n", a,a, b,b); 
  
    if ((a == 'R' && b == 'G') || (a == 'G' && b == 'R')) 
    { 
        printf("return true\n"); 
        return true; 
    } 
  
    printf("return false\n"); 
    return false; 
} 
  
  
  
void dfs(int x, int y, bool color_weak) 
{ 
    printf("[dfs] x:%d,y:%d,color_weak:%d\n", x, y,color_weak); 
  
    v[y][x] = true; 
  
    for (int i = 0; i < 4; ++i) 
    { 
        int nx = x + dir[i].dx; 
        int ny = y + dir[i].dy; 
                 
        if (isRange(nx,ny) && !v[ny][nx] &&  
            (m[y][x] == m[ny][nx] || 
            (color_weak ? isRG(m[y][x],m[ny][nx]) : false))) 
  
        {// search same color block             
            dfs(nx, ny, color_weak); 
        } 
    } 
  
    //display_v(); 
  
    //for (int i = 0; i < 4; ++i) 
    //{ 
    //    int nx = x + dir[i].dx; 
    //    int ny = y + dir[i].dy; 
    //    if (isRange(nx,ny) && !v[ny][nx]) 
    //    {// search newe color block 
    //        section_cnt++; 
    //        dfs(nx, ny, color_weak); 
    //    } 
    //} 
} 
  
int getSectionCount(bool color_weak) 
{ 
    int section_cnt = 0; 
    for (int i = 0; i < N; ++i) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            if (!v[i][j]) 
            { 
                dfs(j, i, color_weak); 
                section_cnt++; 
            } 
        } 
    } 
    return section_cnt; 
} 
  
int main() 
{ 
    FILE* file; 
    freopen_s(&file, "input.txt", "r", stdin); 
  
    cin >> N; 
    for (int i = 0; i < N; ++i) 
    { 
        char input[MAX_N + 1]; 
        cin >> input; 
        for (int j = 0; j < N; ++j) 
        { 
            m[i][j] = input[j]; 
            printf("%c", m[i][j]); 
        } 
        printf("\n"); 
    } 
  
     
    int count1 = getSectionCount(false); 
    clear_visit(); 
    int count2 = getSectionCount(true); 
     
    cout << count1 << " " << count2 << endl; 
  
    fclose(file); 
  
    return 0; 
} 

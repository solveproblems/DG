#include "pch.h" 
#include <iostream> 
using namespace std; 
  
const int MAX_N = 8; 
int v[MAX_N + 1][MAX_N + 1]; 
  
struct Data { int x, y, dist; }; 
Data q[MAX_N*MAX_N+1]; 
int front,rear; 
  
//struct POS { int x, y; } moves[8] = { (1,-2),(2,-1),(2,1),(1,2),(-1,2),(-2,1),(-2,-1),(-1,-2) }; 
struct POS { int x, y; } moves[8] = { {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2} }; 
  
#define printf 
  
void clear() 
{ 
    for (int i = 0; i < MAX_N + 1; ++i) 
        for (int j = 0; j < MAX_N + 1; ++j) 
            v[i][j] = 0; 
  
    front = rear = 0; 
  
} 
bool isRange(int x, int y) 
{ 
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8) 
        return true; 
  
    return false; 
} 
  
int bfs(int sx,int sy,int tx, int ty) 
{ 
    printf("[bfs] sx:%d,sy:%d,tx:%d,ty:%d\n", sx, sy, tx, ty); 
  
    if (sx == tx && sy == ty) 
        return 0; 
  
    q[rear++] = { sx,sy,0 }; 
    v[sy][sx] = true; 
  
    while (true) 
    { 
        Data k = q[front++]; 
        printf("k.x:%d,k.y:%d,k.dist:%d\n", k.x, k.y, k.dist); 
  
        for (int i = 0; i < 8; ++i) 
        { 
            int nx = k.x + moves[i].x; 
            int ny = k.y + moves[i].y; 
            int dist = k.dist + 1; 
  
            printf("moves[%d].x:%d,y:%d\n", i, moves[i].x, moves[i].y); 
            printf("nx:%d,ny:%d,dist:%d\n", nx, ny, dist); 
  
            if (isRange(nx, ny)) 
            { 
                if (nx == tx && ny == ty) 
                    return dist; 
                else if(!v[ny][nx]) 
                { 
                    v[ny][nx] = true; 
                    q[rear++] = { nx,ny,dist }; 
                } 
            }             
        } 
  
        //break; // debug 
    } 
  
    return -1;     
} 
  
int main() 
{ 
    FILE* file; 
    freopen_s(&file, "input.txt", "r", stdin); 
  
    char from[3], to[3];     
    //for (int i = 0; i < 8; i++) 
    while(1) 
    { 
        cin >> from >> to; 
        if (!from[0]) break; 
  
        int sx = from[0] - 'a' + 1; 
        int sy = from[1] - '0'; 
  
        int tx = to[0] - 'a' + 1; 
        int ty = to[1] - '0'; 
  
        clear(); 
  
        int dist = bfs(sx, sy, tx, ty); 
  
  
        //prt("To get from %s to %s takes %d knight moves.\n", from, to, dist);         
        cout << "To get from " << from << " to " << to << " takes " << dist << " kinght moves." << endl; 
  
        //break;//debug 
    } 
  
    fclose(file); 
  
    return 0; 
} 

#include "grid.h"
unsigned long long grid::numOfWays(void){
        result = 0;
        arr = new int*[n+1];
// Insert source code here...
        for(int i=0; i<=n; i++) {
                arr[i] = new int[n+1];
                for(int j=0; j<=n; j++){
                        arr[i][j] = 0;
                }
        }
        recurPath(0,0);
        for(int i=0; i<=n; i++)         delete [] arr[i];
        delete [] arr;
        return result;
}
unsigned long long grid::recurPath(int x, int y){
        if(x==n && y==n)        result += 1;
        else{
                arr[x][y] = 1;
                for(int i=0; i<4; i++){
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        if(nx < 0 || ny < 0 || nx > n || ny > n)        continue;
                        if(arr[nx][ny] == 0){
                                arr[nx][ny] = 1;
                                recurPath(nx, ny);
                                arr[nx][ny] = 0;
                        }
                }
        }

        return result;
}



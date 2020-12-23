#ifndef __GRID_H__
#define __GIRD_H__

class grid{
private:
        int n;
        unsigned long long result;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        int **arr;
// Declare additional variables or functions here if you need...

public:
        grid(int n){
                this->n = n;
                this->result = 0;
        }
        unsigned long long numOfWays(void);
        unsigned long long recurPath(int x, int y);
};

#endif



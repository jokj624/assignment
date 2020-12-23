#include <iostream>
#include "closest.h"
using namespace std;

int main(void){
        int i=0;
//      int x[20] = {1, 3, 1, 0, 0, 0, 1, 1, 0, 0, 2, 0, 2, 3, 0, 2, 1, 3, 3, 0};
//      int y[20] = {3, 2, 2, 2, 0, 1, 2, 3, 3, 2, 2, 0, 1, 0, 1, 1, 1, 2, 3, 3} ;
        //int x[4] = {10, 4, 3, 8};
        //int y[4] = {9, 2, 1, 30};

        int x[5] = {0, 5, 11, 0,23 };
        int y[5] = {1, 3, 1, 6, 1};
        closest *clo = new closest();
        point *p = new point[5];
        for(i=0;i<5;i++){
                (p+i)->x = x[i];
                (p+i)->y = y[i];
        }
        clo->setPoints(p, 5);
        cout<<"Minimum distance: "<<clo->getMinDist()<<endl;

        delete clo, p;
        return 0;
}


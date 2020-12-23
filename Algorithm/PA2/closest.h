#ifndef __CLOSEST_H__
#define __CLOSEST_H__

#include "point.h"

class closest{
private:
        point* pnt;
        int num;
        double ans = 1.79E+308;
        void quickSort(int p, int r);
        int  partition(int p, int r);
        double getDist(int i, int j);
        void minSubDist(int l, int r);
        double min(double x, double y);
        // If you need more member variables or member functions, declare here...

public:
        closest();
        ~closest();

        void setPoints(point* p, int n);
        double getMinDist(void);
};

#endif



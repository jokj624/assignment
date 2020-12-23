#include <cmath>
#include "closest.h"

#if 0

DO NOT MODIFY closest(void), ~closest(void), and setPoints(point* p, int n)!

#endif

closest::closest(void){
        this->pnt = NULL;
        this->num = 0;
        return;
}

closest::~closest(void){
        if(this->pnt)   delete this->pnt;
        return;
}

void closest::setPoints(point* p, int n){
        int i=0;
        if(this->pnt)   delete this->pnt;
        this->pnt = new point[n];
        this->num = n;
        for(i=0;i<n;i++)        this->pnt[i] = p[i];
        return;
}

double closest::getMinDist(void){
        //Input source code here...
        quickSort(0, this->num-1);
        minSubDist(0, this->num-1);
        return this->ans;
}
void closest::quickSort(int p, int r){
        int q;
        if(p<r){
                q = partition(p,r);
                quickSort(p, q-1);
                quickSort(q+1, r);
        }
}
int closest::partition(int p, int r){
        int idx = p-1;
        point temp;
        for(int i = p; i<r; i++){
                if(pnt[i].x < pnt[r].x){
                        temp = pnt[++idx];
                        pnt[idx] = pnt[i];
                        pnt[i] = temp;
                }

        }
        temp = pnt[idx+1];
        pnt[idx+1] = pnt[r];
        pnt[r] = temp;
        return idx+1;
}
double closest::getDist(int i, int j){
        double tempx = pow((pnt[i].x - pnt[j].x),2);
        double tempy = pow((pnt[i].y - pnt[j].y),2);
        return  sqrt((tempx+tempy));
}
double closest::min(double x, double y){
        return x > y ? y : x;
}
void closest::minSubDist(int l, int r){
        if(l==r){
                ans = 1.79E+308;
                return;
        }
        int mid = (l+r)>>1;
        if((r-l+1)<=3){
                double d2 = getDist(l, r);
                if((r-l+1)==2){
                        ans = min(ans,d2);
                        return;
                }
                else if((r-l+1) == 3){
                        double d1 = getDist(l, mid);
                        double d3 = getDist(mid, r);
                        ans = min(min(ans,d1), min(d2, d3));
                        return;
                }
        }

        minSubDist(l, mid);
        double m1 = ans;
        minSubDist(mid+1, r);
        double m2 = ans;
        double temp_dist = 0.0;

        ans  = min(m1, m2);
        if(ans == 0.0)  return;
        for(int i=l; i<=r; i++){
                temp_dist = abs(pnt[i].x - pnt[mid].x);
                if(temp_dist <= ans){
                        for(int j=i+1; j<r; j++){
                                if(abs(pnt[i].y - pnt[j].y) <= temp_dist){
                                        ans = min(ans, getDist(i,j));
                                }
                                else    break;
                        }

                }
                else    break;
        }
}


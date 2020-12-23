#include <iostream>
#include "inv.h"

#define MODE 0

using namespace std;
inv::inv(){
        this->array = NULL;
        this->size = 0;
        this->cnt = 0;
}
inv::~inv(){
        if(this->array) delete this->array;
        return;
}
void inv::reset(int *a, int s){
        int i=0;
        if(this->array) delete this->array;

        this->array = new int[s];
        this->size = s;
        for(i=0;i<s;i++)        *(this->array+i) = *(a+i);
        return;
}
void inv::printArray(void){
        int i = 0;
        for(i=0;i<size;i++)     cout<<*(this->array+i)<<" ";
        cout<<endl;
}
int inv::numOfInv(void){
        //Input source code here...
        this->cnt = 0;
        mergeSort(0, size-1);
        return cnt;
}
void inv::mergeSort(int p, int r){
        int q=0;
        if(p<r){
                q = (int)((p+r)/2);
                mergeSort(p, q);
                mergeSort(q+1, r);
                merge(p,q,r);
        }
}
void inv::merge(int p,int q,int r){
        int n1 = q-p+1;
        int n2 = r-q;
        int L[n1], R[n2];

        for(int i=0; i<n1; i++){
                L[i] = *(this->array+(i+p));
        }
        for(int i=0; i<n2; i++){
                R[i] = *(this->array+(q+i+1));
        }
        L[n1] = 2147483646;     R[n2] = 2147483646;
        int x=0, y=0;
        while(x<n1||y<n2){
                if(L[x] <= R[y]){
                        *(this->array+(p+x+y)) = L[x];
                        x+=1;
                }
                else{
                        *(this->array+(p+x+y)) = R[y];
                        this->cnt += (n1-x);
                        y+=1;
                }
        }
}


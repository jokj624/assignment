#ifndef __INV_H__
#define __INV_H__

class inv{
private:
        int* array;
        int size;
// If you need more attributes or methods, declare here...
        int cnt;
        void mergeSort(int p, int r);
        void merge(int p, int q, int r);

public:
        inv(void);
        ~inv();
        void reset(int* a, int s);
        void printArray(void);
        int numOfInv(void);
};

#endif


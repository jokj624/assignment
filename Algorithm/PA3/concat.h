
#ifndef __CONCAT_H__
#define __CONCAT_H__

#include "pri.h"

class concat{
private:
        int num;
        int count;
        pri **pa;
        pri **newPA;

        int findMAX();
        void countingSort(int k);
// You can declare more member variables and member functions here..


public:
        concat(void);
        concat(int* priority, char **words, int n);
        ~concat(void);

        char* concatenate(void);
};

#endif



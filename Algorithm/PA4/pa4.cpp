#include <iostream>
#include "maxSum.h"

using namespace std;

int main(void){
        int i=0;
        int money[7] = {23, 10, 5, 3, 11, 32, 9};
        maxSum* ms = new maxSum(7, money);

        cout<<"Maximum = "<<ms->max()<<endl;

        if(ms)  delete ms;
        return 0;
}



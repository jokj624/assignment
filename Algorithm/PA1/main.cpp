
#include <iostream>
#include "inv.h"

using namespace std;
int main(void){
        inv *inversion = new inv();
        int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        inversion->reset(arr, 10);
        cout<<"Number of Inversions: "<<inversion->numOfInv()<<endl;
        delete inversion;
        return 0;
}


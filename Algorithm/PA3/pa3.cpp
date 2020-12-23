#include <iostream>
#include <cstring>
#include "concat.h"
using namespace std;

/*const char *testSet[] = {"Hello", "World", "interesting", "algorithm", "Sookmyung", "Women\'s", "University", "a", "a", "I", "am", "boy", "are", "you", "girl"};
int priority[15] = {11, 10, 9, 0, 0, 4, 1, 8, 2, 1, 1, 8, 6, 4, 2};
*/


int priority[10] = {3, 2, 2, 3, 1, 3, 1, 0, 3, 3};
const char *testSet[] = {"RXV", "RZEQG", "PH", "H", "Y", "SAOZMX", "LWUXVVTM", "QIMP", "EYA",
        "FUARVT"};
int main(void){
        int  i=0;
        char **word = new char*[10];
        char *result = 0;

        for(i=0;i<10;i++){
                word[i] = new char[strlen(testSet[i])+1];
                strcpy(word[i], testSet[i]);
        }

        concat *con = new concat(priority, word, 10);
        cout<<(result = con->concatenate())<<endl;

        for(i=0;i<10;i++)       delete[] *(word+i);
        delete[] word;
        delete con;
        delete[] result;
        return 0;
}



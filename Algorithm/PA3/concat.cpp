
#include <iostream>
#include <cstring>
#include "concat.h"
using namespace std;

concat::concat(void){
        this->num = 0;
        this->pa = 0;
        return;
}

concat::concat(int* priority, char **words, int n){
        int i=0;
        this->num = n;
        this->pa = new pri* [n];
        for(i=0;i<n;i++)        this->pa[i] = new pri(priority[i], words[i]);
        return;
}

concat::~concat(void){
        if(this->pa){
                int i=0, n = this->num;
                for(i=0;i<n;i++)        if(this->pa[i])         delete this->pa[i];
                delete[] this->pa;
        }
        return;
}

char* concat::concatenate(void){
        char *result = 0;
        this->count = 0;
        this->newPA = 0;
        this->newPA = new pri* [this->num];
        for(int i=0; i<this->num; i++)          this->newPA[i] = new pri(0,0);
        int a = findMAX();
        countingSort(a);
        result = new char[this->count+this->num];
        for(int i=0; i<this->count+this->num; i++){
                result[i] = 0;
        }
        int idx=0, j=0;
// Insert source code here...
        for(int i=0; i<this->num; i++){
                j=0;
                while(this->newPA[i]->word[j] != '\0'){
                        result[idx++] = this->newPA[i]->word[j++];
                }
                if(i<this->num-1) {
                        result[idx++] = ' ';
                }
        }
        delete[] this->newPA;
        return result;
}

int concat::findMAX(){
        int max_num = 0;
        char* hipen=new char[1];
        strcpy(hipen, "-");
        for(int i=0; i<this->num; i++){
                if(pa[i]->pr > max_num)         max_num = pa[i]->pr;
                this->count += strlen(pa[i]->word);
                if(i<this->num/2)       pa[i] = new pri(pa[i]->pr, hipen);
        }
        delete hipen;
        return max_num;
}
void concat::countingSort(int k){
        int countPA[k+1];
        for(int i=0; i<=k; i++){
                countPA[i] = 0;
        }
        for(int i=0; i<this->num; i++){
                countPA[pa[i]->pr] = countPA[pa[i]->pr] + 1;
        }
        for(int i=1; i<=k; i++){
                countPA[i] = countPA[i] + countPA[i-1];
        }
        for(int i=this->num-1; i>=0; i--){
                countPA[pa[i]->pr] = countPA[pa[i]->pr]-1;
                newPA[countPA[pa[i]->pr]] = pa[i];
        }
        return;
}


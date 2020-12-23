
#include <cstring>
#include <iostream>
#include "pri.h"
using namespace std;

pri::pri(){
        this->pr = 0x7FFFFFFF;
        this->word = 0;
        return;
}

pri::pri(int p, char *w){
        this->word = 0;
        this->setPair(p, w);
        return;
}

pri::~pri(){
        if(this->word)  delete[] this->word;
        return;
}

void pri::operator= (pri& pair){
        this->pr = pair.pr;
        if(pair.word){
                this->word = new char[strlen(pair.word)+1];
                strcpy(this->word, pair.word);
        }
        else    this->word = 0;
        return;
}

void pri::setPair(int p, char* w){
        if(this->word)  delete[] this->word;
        this->pr = p;
        if(w){
                this->word = new char[strlen(w)+1];
                strcpy(this->word, w);
        }
        else{
                this->word = 0;
        }
}

void pri::printPair(void){
        cout<<"["<<this->pr<<", "<<this->word<<"]\n";
        return;
}


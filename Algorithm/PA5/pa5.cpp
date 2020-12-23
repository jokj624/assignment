#include <iostream>
#include "grid.h"

using namespace std;
int main(int argc, char* argv[]){
        grid* G = NULL;
        if(argc == 1){
                cout<<"Error..\nUsage: ./run [number]"<<endl;
                return 0;
        }
        G = new grid(atoi(argv[1]));
        cout<<G->numOfWays()<<" patterns"<<endl;
        delete G;
        return 0;
}



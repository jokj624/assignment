
#include "point.h"

point::point(void){
        this->x = this->y = 0.0;
        return;
}

point::point(const point& p){
        this->x = p.x;
        this->y = p.y;
}



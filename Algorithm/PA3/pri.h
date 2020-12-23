
#ifndef __PRI_H__
#define __PRI_H__

class pri{
public:
        int pr;
        char *word;

        pri();
        pri(int p, char* w);
        ~pri();

        void operator= (pri &pair);
        void setPair(int p, char* w);
        void printPair(void);
};

#endif


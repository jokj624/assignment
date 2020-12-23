
#include "maxSum.h"
// DO NOT modify constuctor and distructor...
maxSum::maxSum(int n, int* m){
        int i=0;
        if(!m)  return;

        num = n;
        money = new int[n];

        for(i=0;i<n;i++){
                money[i] = m[i];
        }
        return;
}

maxSum::~maxSum(){
        if(money){
                delete[] money;
        }
        return;
}

int maxSum::max(void){
        int r=0;
// Insert source code here...
        dp = new int[num];
        for(int i=0; i<num; i++){
                dp[i] = -1;
        }
        dp[0] = money[0];
        dp[1] = money[0]+money[1];
        r = moneySelect(num-1);
        delete[] dp;
        return r;
}
int maxSum::maxCheck(int a, int b){
        if(a >= b)      return a;
        else    return b;
}
int maxSum::moneySelect(int x){
        if(x<0) return 0;
        int q = 0;
        if(dp[x] >= 0)  return q=dp[x];
        else{
                q = maxCheck(moneySelect(x-2), moneySelect(x-3)+money[x-1]) + money[x];
                q = maxCheck(moneySelect(x-1), q);
        }
        dp[x] = q;
        return q;
}


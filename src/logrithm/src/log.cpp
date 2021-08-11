#include<log.h>

double log(int a){
    int out=0;
    while((a%10)>1){
        a/=10;out+=1;
    }
    return out;
}
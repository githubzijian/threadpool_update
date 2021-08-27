//
// Created by pc on 2021/8/27.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "threadpool.h"


void *myworker(void *arg){
    int ret = 0;
    for(int i = 0; i < 10000000; i ++){
        ret ++;
    }
    //sleep(1);
    //printf("thread id is %ld, the result is %d\n", pthread_self(),  ret);
}

int main(){

    threadpool *pool = createThreadPool(2,6,50000);

    for(int i = 0; i < 100000; i ++){
        poolTaskAppend(pool, myworker, NULL);
    }
    printf("添加队列结束\n");
    sleep(10);
    printf("hello\n");
    for(int i = 0; i < 100000; i ++){
        poolTaskAppend(pool, myworker, NULL);
    }
    sleep(10000);

    return 0;
}
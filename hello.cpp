#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int num = 0;
pthread_t t1, t2;


void *task1(void *argc)
{
    printf("this is my fast tid %ld",pthread_self());
   int num = 5;
    while(--num)
    {
        sleep(1);
    }
    pthread_cancel(t2);
}

void *task2(void *argc)
{
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    while (1)
    {
       printf("i am task2 ___-----------");
       sleep(1);
    }
    return 0;


}

int main()
{
    pthread_t tid1,tid2;
    if((pthread_create(&tid1,NULL,task1,NULL))!=0)
    {
        printf("pthread create error!");
        exit(EXIT_FAILURE);

    }

    if((pthread_create(&tid2,NULL,task2,NULL))!=0)
    {
        printf("pthread create error!");
        exit(EXIT_FAILURE);

    }
    printf("this is main thread %ld,%ld",tid1,tid2);
    //  while(1)
    //  {cd ..
    //     printf("i am process，num = %d\n",num++);
    //     sleep(1);

    //  }
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
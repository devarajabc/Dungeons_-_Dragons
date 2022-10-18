#include<stdio.h>

unsigned int order(unsigned int n,int d)
{
    unsigned int no_head=0;
    unsigned int no_till=0;
    unsigned int byte_n=0;
    if(d==1)
    {
        return n>>3*8;
    }
    else {
        no_till = n >> (5 - d) * 8;//去尾
        no_head = n ^ (no_till << (5 - d) * 8);//去頭
        byte_n = no_head >> (4 - d) * 8;
        return byte_n;
    }
}
int main(void)
{
    int n=0;
    int d1=0;
    int d2=0;
    int d3=0;
    int d4=0;
    unsigned int temp=0;
    scanf("%d",&n);
    scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
    /*Xor the (d1)th byte of N with the (d2)th byte of N
      and store the result at the 1st byte of temp.*/
    temp=(order(n,d1)^ order(n,d2))<<8*3;//
    //printf(">>%x\n",temp);
    temp=temp^((order(n,d2)& order(n,d3))<<8*2);//合併就用靈的部分來xor
    //printf(">>%x\n",temp);
    temp=temp^((order(n,d3)| order(n,d1))<<8);
    //printf(">>%x\n",temp);
    temp=temp^order(~order(n,d4),4);
    printf(">>%x\n",temp);

    //step 6;
    int rotate=d1 + d2 + d3 + d4;
    //printf("rotate=%d",rotate);
    unsigned int A=temp>>rotate;
    //printf("A=%x\n",A);
    unsigned int B=temp<<(32-rotate);
    //printf("B=%x\n",B);
    temp=(A|B);
    //printf(">>%x\n",temp);
//問題1.若<<超過的部分會怎樣？？ ans 不見
//問題二，為何不能這樣rotate 要用unsigned
unsigned int mask =0xffff;
unsigned int upper=0;
unsigned int lower=0;
upper=temp>>2*8;
//printf("upper=%x\n",upper);
lower=temp&(mask);
//printf("lower=%x\n",lower);
printf("%d\n",upper^lower);














    return 0;
}
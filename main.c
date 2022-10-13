#include<stdio.h>

int main (void) {
    int d1,d2,d3,d4,d5,d6;
    //do
    //{
        scanf("%d %d %d %d %d %d",&d1,&d2,&d3,&d4,&d5,&d6);
    //}
    //while(d1<1||d1>6||d2<1||d2>6||d3<1||d3>6||d4<1||d4>6||d5<1||d5>6||d6<1||d6>6);
    if(d1+d2+d3<=10)//the player attacks
    {
        if(d4==d5&&d5==d6)
        {
            printf("Player attacks: Critical Hit\n");
        }
        else if(d4+d5>=d6)
        {
             printf("Player attacks: Normal Hit\n");
        }
        else
        {
             printf("Player attacks: Miss\n");
        
        }
    }
    else//the dragon attacks.
    {
        if(d4==d5||d4==d6||d5==d6)
        {
            printf("Dragon attacks: Miss\n");
        }
        else if(d4+d5!=d6)
        {
            printf("Dragon attacks: Normal Hit\n");
        }
        else
        {
            printf("Dragon attacks: Critical Hit\n");
        }
    }
    return 0;
}

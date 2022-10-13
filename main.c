#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main () {
    int hp_player=100;
    int hp_dragon=100;
    int d[5]={};
    while(hp_player>0&&hp_dragon>0)
    {
        for(int i=0;i<6;i++)//get the array
        {
            scanf("%d",&d[i]);
        }
        if((d[0]+d[1]+d[2])%2!=0)//If the sum is odd, the player attacks
        {
            if(d[3]<d[4]&&d[4]<d[5])//If the score of d4, d5 and d6 are in ascending order,
            {
                hp_dragon-=25;
            }// a critical hit.
            else if(d[3]%2==d[4]%2||d[4]%2==d[5]%2)
            {
                hp_dragon-=5;
            }
        }
        else//Otherwise, the dragon attacks.
        {
            //critical
            if(abs(d[3]-d[4])>d[5])
            {
                hp_player-=15;
            }
            else if(d[3]+d[4]!=d[5])
            {
                hp_player-=5;
            }

        }
    }

    if(hp_player>hp_dragon)
    {
        printf("Player wins\n");
    }
    else
    {
        printf("Dragon wins\n");
    }



    return 0;
}

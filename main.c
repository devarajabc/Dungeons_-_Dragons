#include<stdio.h>
int main(void)
{
    unsigned long long NUMBER_1 = 0x38E38E38E38E3800LLU;
    unsigned long long NUMBER_2 = 0x2AAAAAAAAAAAAAAALLU;
    unsigned long long NUMBER_3 = 0x1C71C71C71C71C71LLU;
    int d=0;
    unsigned long long temp=0;
  /*(d1 * NUMBER_1 + d2 * NUMBER_2 + d3 * NUMBER_3) mod 0x7CE66C50E2840000LLU*/
  /*(a + b) % c = ((a % c) + (b % c)) % c */
  for(int i=0;i<4;i++)
  {
      if(i<3) {
          scanf("%d", &d);
      }
      switch (i) {
          case 0:
              temp+=(d * NUMBER_1)%0x7CE66C50E2840000LLU; break;//累加
          case 1:
              temp+=(d * NUMBER_2)%0x7CE66C50E2840000LLU; break;//累加
          case 2:
              temp+=(d * NUMBER_3)%0x7CE66C50E2840000LLU; break;
          case 3:
              printf("%llu\n",temp%0x7CE66C50E2840000LLU);break;
          default:
              break;
                }

  }
    return 0;
}
#include<stdio.h> 
int main() 
{ 
      int k, upto, all = 0, x, counter_s = 0, TQ; 
      int WT = 0, TAT = 0, AT[10], BT[10], t[10]; 
      float avg_WT, avg_TAT;
      printf("\nEnter all Number of Processes:\t"); 
      scanf("%d", &upto); 
      x = upto; 
      for(k = 0; k < upto; k++) 
      {
            printf("\nEnter Details of Process[%d]\n", k + 1);
            printf("Arrival Time:\t");
            scanf("%d", &AT[k]);
            printf("Burst Time:\t");
            scanf("%d", &BT[k]); 
            t[k] = BT[k];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &TQ); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(all = 0, k = 0; x != 0;) 
      { 
            if(t[k] <= TQ && t[k] > 0) 
            { 
                  all = all + t[k]; 
                  t[k] = 0; 
                  counter_s = 1; 
            } 
            else if(t[k] > 0) 
            { 
                  t[k] = t[k] - TQ; 
                  all = all + TQ; 
            } 
            if(t[k] == 0 && counter_s == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", k + 1, BT[k], all - AT[k], all - AT[k] - BT[k]);
                  WT = WT + all - AT[k] - BT[k]; 
                  TAT = TAT + all - AT[k]; 
                  counter_s = 0; 
            } 
            if(k == upto - 1) 
            {
                  k = 0; 
            }
            else if(AT[k + 1] <= all) 
            {
                  k++;
            }
            else 
            {
                  k = 0;
            }
      } 
      avg_WT = WT * 1.0 / upto;
      avg_TAT = TAT * 1.0 / upto;
      printf("\n\nAverage Waiting Time:\t%f", avg_WT); 
      printf("\nAvg Turnaround Time:\t%f\n", avg_TAT); 
      return 0; 
}

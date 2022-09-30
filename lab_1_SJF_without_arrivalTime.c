#include <stdio.h>
int main()
{
     int i, c[10], w[10], t[10], n, j, temp, process[10], temp1;
     printf("\n Enter the processor number : ");
     scanf("%d", &n);

     for (i = 0; i < n; i++)
     {
          printf("\n CPU time for P%d : ", i + 1);
          scanf("%d", &c[i]);
          process[i] = i + 1;
     }
     for (i = 0; i < n - 1; i++)
     {
          for (j = i + 1; j < n; j++)
          {
               if (c[i] > c[j])
               {
                    temp = c[i];
                    c[i] = c[j];
                    c[j] = temp;

                    temp1 = process[i];
                    process[i] = process[j];
                    process[j] = temp1;
               }
          }
     }
     w[0] = 0;
     for (i = 1; i < n; i++)
     {
          w[i] = w[i - 1] + c[i - 1];
     }
     for (i = 0; i < n; i++)
     {
          t[i] = w[i] + c[i];
     }
     printf(" \nProcess         CPUtime        Waitingtime        Turnaroundtime");
     printf("\n\n");
     for (i = 0; i < n; i++)
     {
          printf(" P%d               %d               %d                  %d\n", process[i], c[i], w[i], t[i]);
     }
}

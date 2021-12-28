#include <stdio.h>
#include<stdlib.h>
void fcfs();
void sjf();
void priority();
void rr();
void main()
{
  int choice;
  do{
      printf("\n");
      printf("Menu driven program\n");
      printf("1.FCFS\n");
      printf("2.SJF\n");
      printf("3.Prioity\n");
      printf("4.Round Robin\n");
      printf("5.Exit\n");
      printf("Enter Option\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1: fcfs();
          break;
          case 2: sjf();
          break;
          case 3: priority();
          break;
          case 4: rr();
          break;
          case 5: exit(0);
          break;
          default: printf("Invalid Option");
          break;
         
      }
     
     
  }while(choice!=5);
   
}
 
 
  void fcfs()
  {
       int p[30], bt[30], n, tat[30], wt[30], tot_wt=0, tot_tat=0, a_tat=0, a_wt=0,count=0;
   printf("Enter the number of processes ");
   scanf("%d",&n);
   printf("Enter the burst time ");
   for(int i=0;i<n;i++)
   {
     scanf("%d",&bt[i]);
     p[i]=i;
     
   }
    printf("Process\tBurst time\n");
    for(int i=0;i<n;i++)
    {
      printf("Process [%d]\t%d\n",i,bt[i]);
     
    }
     for(int i=0;i<n;i++)
     {
       if(i==0)
       {
         tat[i]=bt[i];
       }
        else
        {
        tat[i]=tat[i-1]+bt[i];
        tot_tat=tot_tat+tat[i];
        }
        }
        wt[0]=0;
      for(int i=1;i<n;i++)
     
       {
         
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
        }
       
 printf("Process\tBurst time\tTurn Around Time\tWaiting Time\n");
       for(int i=0;i<n;i++)
    {
      printf(" Process[%d]\t%d\t\t%d\t\t%d\n",i,bt[i],tat[i],wt[i]);
     
     }
        printf("Total turn around time %d\n ",tot_tat);
        printf("Total waiting time %d\n ",tot_wt);
        a_tat=tot_tat/n;
        a_wt=tot_wt/n;
       
        printf("Average turn around time %d\n ",a_tat);
        printf("Average waiting time %d\n ",a_wt);
       
        printf("Gantt chart\n");
        for(int i=0;i<n;i++)
        {
            printf("\tP%d\t",i);
        }
        printf("\n%d\t\t",count);
        for(int i=0;i<n;i++)
        {
            count=count+bt[i];
            printf("%d\t\t",count);
        }
 }
 
 
  void sjf()
  {
      int p[30],bt[30],n,tat[30],wt[30],tot_wt=0,tot_tat=0,a_tat=0,a_wt=0,temp=0,count=0;
   printf("Enter the number of processes ");
   scanf("%d",&n);
   printf("Enter the burst time ");
   for(int i=0;i<n;i++)
   {
     scanf("%d",&bt[i]);
     p[i]=i;
     
    }
   
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        if(bt[i]>bt[j])
        {
       
        temp=bt[i];
        bt[i]=bt[j];
        bt[j]=temp;
       
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
          }
     } }  
   
    printf("Process\tBurst time\n");
    for(int i=0;i<n;i++)
    {
      printf("Process [%d]\t%d\n",i,bt[i]);
     
     }
     
     for(int i=0;i<n;i++)
     {
       if(i==0)
       {
         tat[i]=bt[i];
         }
        else
        {
        tat[i]=tat[i-1]+bt[i];
        tot_tat=tot_tat+tat[i];
        }
        }
        wt[0]=0;
      for(int i=1;i<n;i++)
     
       {
         
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
        }
       
  printf("Process\tBurst time\tTurn Around Time\tWaiting Time\n");
       for(int i=0;i<n;i++)
    {
      printf(" Process[%d]\t%d\t\t%d\t\t%d\n",i,bt[i],tat[i],wt[i]);
     
     }
        printf("Total turn around time %d\n ",tot_tat);
        printf("Total waiting time %d\n ",tot_wt);
        a_tat=tot_tat/n;
        a_wt=tot_wt/n;
       
        printf("Average turn around time %d\n ",a_tat);
        printf("Average waiting time %d\n ",a_wt);

      printf("Gantt chart\n");
        for(int i=0;i<n;i++)
        {
            printf("\tP%d\t",p[i]);
        }
        printf("\n%d\t\t",count);
        for(int i=0;i<n;i++)
        {
            count=count+bt[i];
            printf("%d\t\t",count);
        }

  }
 
  void priority()
  {

   int n, tot_wt=0, tot_tat=0,temp=0,pos,count=0,temp1=0,temp2=0;
   float a=0,a_wt=0,a_tat=0;

   printf("Enter the number of processes ");
   scanf("%d",&n);
   int p[n], bt[n], tat[n], wt[n],pr[n];
   for(int i=0;i<n;i++){
        p[i]=i;
     printf("\nEnter Burst Time of P%d\t",i);
     scanf("%d",&bt[i]);
     printf("\nEnter priority of P%d",i);
     scanf("%d",&pr[i]);}

    for(int i=0;i<n;i++)

    {

      for(int j=0;j<n;j++)

      {

        if(pr[i]<pr[j])

        {
        temp=pr[i];
        pr[i]=pr[j];
        pr[j]=temp;
       
        temp1=bt[i];

        bt[i]=bt[j];

        bt[j]=temp1;

       

        temp2=p[i];

        p[i]=p[j];

        p[j]=temp2;

          }

     }  }  

    for(int i=0;i<n;i++)
    {
     wt[0]=0;
     if(i!=0)
     {
        wt[i]=wt[i-1]+bt[i-1];
        a_wt=a_wt+wt[i];
        tat[i]=wt[i]+bt[i];
        a_tat=a_tat+tat[i];
     }
     else
     {
         tat[i]=bt[i];
         a_tat=a_tat+tat[i];
     }
    }
   
    printf("Process\tBurst time\tTurn Around Time\tWaiting Time\tPriority\n");
        for(int i=0;i<n;i++)
        {
            printf(" Process[%d]\t%d\t\t",p[i],bt[i]);
            printf("%d\t\t%d\t\t%d\n",tat[i],wt[i],pr[i]);
        }
         printf("Average turn around time %f\n ",a_tat/n);
         printf("Average waiting time %f\n ",a_wt/n);


   
       
        printf("Gantt chart\n");
        for(int i=0;i<n;i++)
        {
            printf("\tP%d\t",p[i]);
        }
        printf("\n%d\t\t",count);
        for(int i=0;i<n;i++)
        {
            count=count+bt[i];
            printf("%d\t\t",count);
            a=count;
        }
 
  }
 
  void rr()
  {
       int n, total = 0, counter = 0, time_quantum,check=0;
       int wt[10], tat[10], bt[10],rem[10];
       float a_wt, a_tat;
       printf("\nEnter Total Number of Processes: ");
       scanf("%d", &n);
       printf("\nEnter Time Quantum:\t");
      scanf("%d", &time_quantum);
      for(int i = 0; i <n; i++)

      {

        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Burst Time:\t");
        scanf("%d", &bt[i]);
        rem[i] = bt[i];

      }
      printf("Gantt chart\n");
        while(check<n)
        {
            for(int i=0;i<n;i++)
            if(rem[i]>time_quantum)
            {
                printf("\tP%d\t",i);
                total=total+time_quantum;
                rem[i]=rem[i]-time_quantum;
            }
            else if(rem[i]==0)
            {
               
            }
            else
            {
                printf("\tP%d\t",i);
                total=total+rem[i];
                tat[i]=total;
                wt[i]=total - bt[i];
                a_wt=a_wt+wt[i];
                a_tat=a_tat+tat[i];
                rem[i]=0;
                check++;
           }

      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(int i = 0;i<=0;i++)
      {
          printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\n", i + 1, bt[i], total, total - bt[i]);
      }
      printf("Average turn around time %f\n ",a_tat/n);
        printf("Average waiting time %f\n ",a_wt/n);
 }
  }

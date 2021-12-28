#include <stdio.h>
#include<stdlib.h>
void fifo();
void lru();
void lfu();
void main()
{
  int choice;
  do{
      printf("\n");
      printf("Menu driven program\n");
      printf("1.FIFO\n");
      printf("2.LRU\n");
      printf("3.LFU\n");
      printf("4.Exit\n");
      printf("Enter Option\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1: fifo();
          break;
          case 2: lru();
          break;
          case 3: lfu();
          break;
          case 4: exit(0);
          break;
          default: printf("Invalid Option");
          break;
         
      }
     
     
  }while(choice!=4);
   
}

void fifo()
{
    int i,j,n,a[50],frame[10],no,k,avail,count=0;
    printf("\n enter the number of pages:\n");
    scanf("%d",&n);
    printf("\n enter the page number:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("\n enter the number of frames:\n");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    frame[i]=-1;
    j=0;
    printf("\tref string\t page frmaes\n");
    for(i=1;i<=n;i++)
 {
    printf("%d\t\t",a[i]);
    avail=0;
    for(k=0;k<no;k++)
    if(frame[k]==a[i])
     avail=1;
     if(avail==0)
     { 
         frame[j]=a[i];
       j=(j+1)%no;
        count++;
     for(k=0;k<no;k++)
        printf("%d\t",frame[k]);
     }
    printf("\n");
 }
   printf("page fault is %d",count);
   getch();

}

void lru()
{

int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20];
printf("Enter no of pages:");
scanf("%d",&n);
printf("Enter the reference string:");
for(i=0;i<n;i++)
            scanf("%d",&p[i]);
printf("Enter no of frames:");
scanf("%d",&f);
q[k]=p[k];
printf("\n\t%d\n",q[k]);
c++;
k++;
for(i=1;i<n;i++)
            {
                        c1=0;
                        for(j=0;j<f;j++)
                        {
                                    if(p[i]!=q[j])
                                    c1++;
                        }
                        if(c1==f)
                        {
                                    c++;
                                    if(k<f)
                                    {
                                                q[k]=p[i];
                                                k++;
                                                for(j=0;j<k;j++)
                                                printf("\t%d",q[j]);
                                                printf("\n");
                                    }
                                    else
                                    {
                                                for(r=0;r<f;r++)
                                                {
                                                            c2[r]=0;
                                                            for(j=i-1;j<n;j--)
                                                            {
                                                            if(q[r]!=p[j])
                                                            c2[r]++;
                                                            else
                                                            break;
                                                }
                                    }
                                    for(r=0;r<f;r++)
                                     b[r]=c2[r];
                                    for(r=0;r<f;r++)
                                    {
                                                for(j=r;j<f;j++)
                                                {
                                                            if(b[r]<b[j])
                                                            {
                                                                        t=b[r];
                                                                        b[r]=b[j];
                                                                        b[j]=t;
                                                            }
                                                }
                                    }
                                    for(r=0;r<f;r++)
                                    {
                                                if(c2[r]==b[0])
                                                q[r]=p[i];
                                                printf("\t%d",q[r]);
                                    }
                                    printf("\n");
                        }
            }
}
printf("\nThe no of page faults is %d",c);
}

void lfu()
{
     
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
    printf("Enter page reference string: ");
    
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        flag3 =0;
        
            for(j = 0; j < no_of_frames; ++j){
            temp[j] = -1;
            
            for(k = i + 1; k < no_of_pages; ++k){
            if(frames[j] == pages[k]){
            temp[j] = k;
            break;
            }
            }
            }
            
            for(j = 0; j < no_of_frames; ++j){
            if(temp[j] == -1){
            pos = j;
            flag3 = 1;
            break;
            }
            }
            
            if(flag3 ==0){
            max = temp[0];
            pos = 0;
            
            for(j = 1; j < no_of_frames; ++j){
            if(temp[j] > max){
            max = temp[j];
            pos = j;
            }
            }             
            }

frames[pos] = pages[i];
faults++;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);

   
}

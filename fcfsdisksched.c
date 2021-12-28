#include<stdio.h>
void main(){
	int head=0,max,st=0,n;
	printf("Enter the maximum value of requests");
	scanf("%d",&max);
	printf("Enter the number of requests");
	scanf("%d",&n);
	printf("Enter the position of head");
	scanf("%d",&head);
	int req[n];
	printf("Enter the requests");
	for(int i=0;i<n;i++){
		scanf("%d",&req[i]);
		if(head>req[i]){
			st=st+(head-req[i]);
		}else{
			st=st+(req[i]-head);
		}
		head=req[i];
	}
	printf("Total Seek Time is: %d",st);
}

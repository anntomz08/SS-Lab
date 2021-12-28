#include<stdio.h>
void main(){
	int head,max,st,n=0,temp=0,prev,pos=0,min1=0,max1=0,a=0,head2;
	printf("Enter the maximum value of requests");
	scanf("%d",&max);
	printf("Enter the number of requests");
	scanf("%d",&n);
	printf("Enter the position of head");
	scanf("%d",&head);
	head2=head;
	printf("Enter the previous position of head");
	scanf("%d",&prev);
	int req[n];
	printf("Enter the requests");
	for(int k=0;k<n;k++){
		scanf("%d",&req[k]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(req[i]<req[j]){
				temp=req[i];
				req[i]=req[j];
				req[j]=temp;
			}
	}}
	for(int k=0;k<n;k++){
		if(head>req[k])
			pos++;
	}
	min1=req[0];
	max1=req[n-1];
	if(prev<head){
		goto loop1;
		}
	else if(prev>head){
		goto loop2;
		}
	
	loop1: {
	st=0;
	for(int i=pos;i<n;i++){
			st=st+(req[i]-head);
			head=req[i];
			if(i==n-1){
			st=st+(max1-min1);
			head=min1;
			for(int m=1;m<pos;m++){
				st=st+(req[m]-head);
				head=req[m];
			}}
	}		
	printf("Total Seek Time is: %d",st);
	goto end;
	}
	loop2: {
	st=0;
	for(int i=pos-1;i>0;i--){
			st=st+(head-req[i]);
			head=req[i];	
			if(i==1){
			st=st+(max1-min1);
			head=max1;
			for(int m=n-1;m>=pos;m--){
			st=st+(head-req[m]);
			head=req[m];
			}}
	}
	printf("Total Seek Time is: %d",st);
	goto end;
	}
	end:{}
}

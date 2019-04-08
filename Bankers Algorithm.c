#include<stdio.h>
const int Resources=3; 
const int Processes=5;

int main() 
{ 	int instance[Resources];
	printf("Enter the available instances of resource A,B AND C= ");
	for(int i=0;i<3;i++){
		scanf("%d",&instance[i]);
	}
	int Allocation[Processes][Resources];
	printf("-----------------\n");
	printf("Allocation Matrix\n");
	for(int i=0;i<Processes;i++){
		for(int j=0;j<Resources;j++){
			scanf("%d",&Allocation[i][j]);
		}
	}
	printf("----------------\n");
	printf("Maximum table\n");
	int Maximum[Processes][Resources];
	for(int i=0;i<Processes;i++){
		for(int j=0;j<Resources;j++){
			scanf("%d",&Maximum[i][j]);
		}
	}
	int Available[Resources];
    for(int i=0;i<Resources;i++){
    	int sum=0;
		for(int j=0;j<Processes;j++){
    		sum+=Allocation[j][i];
		}
		instance[i]-=sum;
		
		Available[i]=instance[i];
	}
	printf("Available instances are= \n");
	for(int i=0;i<Resources;i++){
		printf("%d ",Available[i]);
	}
	printf("\n");
	int Need[Processes][Resources];
	// this will calculate Needed numer of resources of all processes
	for (int i = 0 ; i < Processes ; i++){
		for (int j = 0 ; j < Resources ; j++){
			Need[i][j] = Maximum[i][j] - Allocation[i][j];
		}
	}
	bool finished[Processes];
	for(int i=0;i<Processes;i++){
		finished[i]=0;
	}
	
	
	printf("Need Matrix----\n");
	for(int i=0;i<Processes;i++){
		for(int j=0;j<Resources;j++){
			printf("%d ",Need[i][j]);
		}
		printf("\n");
	}
	
	int countSeq=0;
	int safeSeq[Processes];
	int j=0;
	int i=0;
	int countt=0;
	bool flag2=true;
	while(i<Processes){
		bool flag=true;
		for(int j=0;j<Resources;j++){
			if(Available[j]<Need[i][j]){
				flag=false;
				break;
			}
		}
		if(flag==true && finished[i]==0){
			
			for(int j=0;j<Resources;j++){
				Available[j]-=Need[i][j];
			}
			for(int j=0;j<Resources;j++){
				Available[j]+=Maximum[i][j];
			}
			
			safeSeq[j]=i;
			j++;
			countSeq++;
			finished[i]=1;
			i++;
			if(i==Processes){
				i=0;
			}
			countt++;
		}
		else{
			i++;
			if(i==Processes){
				i=0;
			}
			countt++;
		}
		
		if(countt==(2*Processes)){
			for(int i=0;i<Processes;i++){
				if(finished[i]!=1){
					flag2=false;
					break;
				}
			}
			if(flag2==false){
				printf("System is not in safe state \n");
				break;
			}	
			else{
				break;
			}
		}
	}
	
	if(flag2){
		printf("System is in safe state. \n");
		for(int i=0;i<Processes;i++){
			printf("%d ",safeSeq[i]);
		}
	}
	
    return 0; 
} 



#include<stdio.h>
#include<windows.h>
struct job{
	int processId;
	int arrivalTime;
	int burstTime;
	int compTime;
	int remTime;
}faculty[100], student[100], mergeQueue[100];

int n, fc=0, sc=0, mc=0;
int quanta;

void roundRobin(){

	//time = complete[0].atime is used for initializing the time with the first arrived process's arrival time
    int time = mergeQueue[0].arrivalTime, cc=0, i, j, check;

    //while the total time is less than 120 minutes and
    //all the processes are not processes we'll run the loop
	while(time!=120 && cc!=mc){
    //iterate through the processes
		for(i=0; i<mc; i++){
		    //when arrival time is less than the starting time
            if(mergeQueue[i].arrivalTime<=time ){
            //when burst time is grater than time quantum
			if(mergeQueue[i].remTime > quanta){
				time += quanta;
				mergeQueue[i].remTime -= quanta;
			}
            //when burst time is less than time quantum
			else if(mergeQueue[i].remTime <=quanta && mergeQueue[i].remTime!=0){
				time += mergeQueue[i].remTime;
				mergeQueue[i].remTime =0;
				mergeQueue[i].compTime= time;
				cc++;
			}
            }
            //if arrival time is greater than the present time
            else{
                check=0;
                for(j=0;j<i;j++)
                {
                    //to check if any process above is yet to be completed
                    //if not then present time is set to arrival time of this process
                    if((mergeQueue[j].arrivalTime<mergeQueue[i].arrivalTime) && (mergeQueue[j].remTime!=0))
                    {
                        check++;
                        break;
                    }
                }
                //if no process is present to execute int the current time
                //we increase the present time to the closest process's arrival time
                if(check==0)
                {
                    time=mergeQueue[i].arrivalTime;
                }
                continue;
            }
		}
	}
	//if  time limit exceeds then issue a warning because Sudesh can run the system
	//from 10am to 12pm only
	if(time>120)
        {
            printf("\nTime limit exceeded! Results will still show.\n");
        }
}

void merger(){
	int isc=0, ifc= 0, min, flag;
	if( fc!=0  && sc!=0){
		while(isc<sc && ifc<fc){
			if(faculty[ifc].arrivalTime == student[isc].arrivalTime){
				mergeQueue[mc] = faculty[ifc];
				mc++;
				ifc++;
				mergeQueue[mc]= student[isc];
				mc++;
				isc++;
			}
			else if(faculty[ifc].arrivalTime < student[isc].arrivalTime){
				mergeQueue[mc]= faculty[ifc];
				mc++;
				ifc++;
			}
			else if(faculty[ifc].arrivalTime > student[isc].arrivalTime){
				mergeQueue[mc]= student[isc];
				mc++;
				isc++;
			}
			else;
		}
		if(mc != (fc+sc)){
			if(fc!=ifc){
				while(ifc!=fc){
					mergeQueue[mc]= faculty[ifc];
					mc++;
					ifc++;
				}
			}
			else if(sc!=isc){
				while(isc!=sc){
					mergeQueue[mc]= student[isc];
					mc++;
					isc++;
				}
			}
		}
	}
	else if(fc==0){
		while(isc!=sc){
			mergeQueue[mc]= student[isc];
			mc++;
			isc++;
		}
	}
	else if(sc==0){
		while(ifc!=fc){
			mergeQueue[mc]= faculty[ifc];
			mc++;
			ifc++;
		}
	}
	else {
		printf("\n No valid Jobs available\n");
	}
}

void printer(){
	int i=0, total=0, sum=0;
	double avg;
	printf("\nSummary for the Execution\n");
	printf("----------------------------\n\n");
	printf("\nQuery ID\tArrival Time\tRessolving Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i; i<mc; i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		mergeQueue[i].processId, (mergeQueue[i].arrivalTime+1000), mergeQueue[i].burstTime, (mergeQueue[i].compTime+1000), (mergeQueue[i].compTime-mergeQueue[i].arrivalTime), ((mergeQueue[i].compTime-mergeQueue[i].arrivalTime)- mergeQueue[i].burstTime));
		total= mergeQueue[i].compTime;
		sum+= (mergeQueue[i].compTime-mergeQueue[i].arrivalTime);
	}
	avg = sum/mc;
	printf("\n\nTotal time Spent for all queries: %d", total);
	printf("\nAverage query time: %lf", avg);
	printf("\nProcess Execution Complete");
}

void input(){
	int map,  i, t;
	printf("-------------------------------\n");
	printf("Enter total no of queries: "); scanf("%d", &n);
	if(n==0) { printf("\n No queries\n"); }
	else{
		printf("\nEnter Quanta for each Process: "); scanf("%d", &quanta);
		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++){
			printf("\nJob Type (1/2): "); scanf("%d", &map);
			if(map==1){
				printf("Query Id: "); scanf("%d", &faculty[fc].processId);
				printf("Arrival Time: "); scanf("%d", &t);
				if(t<1000 || t>1200){

					printf("\nEnter Correct time");
					input();
				}
				else{faculty[fc].arrivalTime= t-1000;}
				printf("Resolving Time: "); scanf("%d", &faculty[fc].burstTime);	 faculty[fc].remTime= faculty[fc].burstTime;
				fc++;
			} else{
				printf("Query Id: "); scanf("%d", &student[sc].processId);
				printf("Arrival Time: "); scanf("%d", &t);
				if(t<1000 || t>1200){
					printf("\nEnter Correct time\n");
					input();
				}
				else {student[sc].arrivalTime= t-1000; }
				printf("Resolving Time: "); scanf("%d", &student[sc].burstTime);	 student[sc].remTime= student[sc].burstTime;
				sc++;
			}
		}
	}
}

void inst(){
	printf("\nWelcome, please follow these instruction for proper functioning of the program"
			"\n**>Enter time in 2400 hours format. example for 10:30 am enter 1030"
			"\n**>Enter Query arrival times in ascending order, i.e., in real time arrival manner\n"
			"\nAll Time units are in minutes. \n\n"
			);
}

 main(){
 	inst();
	input();
	merger();
	roundRobin();
	printer();
}

#include<bits/stdc++.h>
using namespace std;
const int R=3; 
const int P=5;

#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
vector<bool> finish(P);
int main() 
{ 
	boost;
	
    vector<vector<int>> Allocation{{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; 
  
  	vector<vector<int>> Maximum{{7, 5, 3}, {3, 2, 2},{9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
                     
    vector<int> Processes{0, 1, 2, 3, 4}; 
  
    vector<int> Available{3, 3, 2}; 
    vector<vector<int>> Need(P,vector<int>(R));
	
	// this will calculate Needed numer of resources of all processes
	for (int i = 0 ; i < P ; i++){
		for (int j = 0 ; j < R ; j++){
			Need[i][j] = Maximum[i][j] - Allocation[i][j];
		}
	}
	
	 
  	// it will store safe sequence
    vector<int> safeSeq(P); 
  	
    vector<int> work(R); 
    for (int i = 0; i < R ; i++){
        work[i] = Available[i]; 
  	}
	  	
    int count = 0; 
    
	while (count < P) 
    { 
        bool found = false; 
        for (int p = 0; p < P; p++) 
        { 
            if (finish[p] == 0) 
            { 
                int j; 
                for (j = 0; j < R; j++) 
                    if (Need[p][j] > work[j]) 
                        break; 
  
                if (j == R) 
                { 
                    for (int k = 0 ; k < R ; k++) 
                        work[k] += Allocation[p][k]; 
  
                    safeSeq[count++] = p; 
  
                    finish[p] = 1; 
  
                    found = true; 
                } 
            } 
        } 
  
        if (found == false) 
        { 
            cout<<"System is not in safe state\n"; 
        } 
    } 
  
    cout<<"System is in safe state.\n";
	cout<<"Safe sequence is--------- \n";
	 
    for (int i = 0; i < P ; i++){
		cout<<safeSeq[i]<<"\n"; 
  	}  	
    return 0; 
} 



#include<iostream>
#include<queue>
using namespace std;

void turnaround_waiting(int* finish, int* burst_time, int* arrival_time, int n){
	int waiting_time[15], turnaround_time[15];
	cout<<"Process   Waiting time   Turnaround time\n";
	for(int i = 0; i < n; i++){
		waiting_time[i] = finish[i] - arrival_time[i] - burst_time[i];
		turnaround_time[i] = waiting_time[i] + burst_time[i];
		cout<<i<<"\t\t"<<waiting_time[i]<<"\t\t"<<turnaround_time[i]<<endl;
		
	}
};


void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
};

void bubble_sort(int* arrival_time, int* burst_time, int* program_id, int n){
	int flag,temp,i ,j;
	for(i = 0; i < (n-1); i++){
		flag = 0;
		for(j = 0; j < (n-i-1); j++)
			if(arrival_time[j] > arrival_time[j+1]){
				swap(&arrival_time[j], &arrival_time[j+1]);
				swap(&burst_time[j], &burst_time[j+1]);
				swap(&program_id[j], &program_id[j+1]);
				flag = 1;
			}
			if(flag == 0)
				break;
	}
};


int main(){
	int arrival_time[15], burst_time[15], finish_time[15], program_id[15],job[100], arrival2[15], burst2[15];
	int i,j,n,time,index = 0,flag,temp;
	
	cout<<"Enter the number of jobs"<<endl;
	cin>>n;
	cout<<"Enter the arrival time and burst time"<<endl;
	for(i = 0; i < n; i++){
		cin >> arrival_time[i];
		cin >> burst_time[i];
		program_id[i] = i;
		arrival2[i] = arrival_time[i];
		burst2[i] = burst_time[i];
	}

	cout<<"\nJob with burst time and arrival time are\n";
	for(i = 0; i< n; i++)
		cout<<(i)<<"\t"<<arrival_time[i]<<"\t"<<burst_time[i]<<"\n";

	bubble_sort(arrival_time,burst_time,program_id,n);


	time = 0;
	while(burst_time[n - 1] != 0){
		if(arrival_time[index] <= time){
			while(burst_time[index] != 0){
				job[time] = program_id[index];
				burst_time[index] = burst_time[index] - 1;
				time ++;
			}
			finish_time[program_id[index]] = time;
			index++;
		}
		else{
			job[time] = -1;
			time++;
		}
	}
	cout<<"\nGantt Chart\n";
	for(i = 0; i < time; i++)
		cout<<job[i]<<"   ";
	cout<<endl<<endl;
	turnaround_waiting(finish_time,burst2,arrival2,n);

}

import java.util.Scanner;


public class sjf{
	
	public static void turnaround_waiting(int finish[], int burst_time[], int arrival_time[], int n){
		int i;
		int[] waiting_time = new int[15];
		int[] turnaround_time = new int[15];
		System.out.println("Process   Waiting time   Turnaround time");
		for(i = 0; i < n; i++){
			waiting_time[i] = finish[i] - arrival_time[i] - burst_time[i];
			turnaround_time[i] = waiting_time[i] + burst_time[i];
			System.out.println(i+"\t\t"+waiting_time[i]+"\t\t"+turnaround_time[i]);
		
		}
	};


	public static void bubble_sort(int arrival_time[], int burst_time[], int program[], int n){
		int flag,temp,i ,j;
		for(i = 0; i < (n-1); i++){
			flag = 0;
			for(j = 0; j < (n-i-1); j++)
				if(burst_time[j] > burst_time[j+1]){

					temp = arrival_time[j];
					arrival_time[j] = arrival_time[j+1];
					arrival_time[j+1] = temp;

					temp = burst_time[j];
					burst_time[j] = burst_time[j+1];
					burst_time[j+1] = temp;
				
					temp = program[j];
					program[j] = program[j+1];
					program[j+1] = temp;
					flag = 1;
				}
				if(flag == 0)
					break;
		}
	};
	
	public static void preemptive(int burst[], int arrival[],int burst2[], int arrival2[],int n){

		int i, small, index, flag, time;
		int[] finish_time = new int[15];
		int[] job = new int[100];
		time = 0;
		index = 0;
		while(true){
			small = 400;
			flag = 0;
			for(i = 0; i < n; i++){
				if (burst[i] < small && arrival[i] <= time && burst[i] != 0){
					small = burst[i];
					index = i;
				}
				if (burst[i] != 0)
					flag = 1;
			}
			if (flag == 0)
				break;
			if(small != 400){
				job[time] = index;
				burst[index] = burst[index] - 1;
			}
			else
				job[time] = -1;
		
			time++;
			if(burst[index] == 0)
				finish_time[index] = time;
		}
		System.out.println("SJF Preemptive Result\n");
		for(i = 0; i < time; i++)
			System.out.print(job[i]+"   ");
		System.out.print("\n");
		turnaround_waiting(finish_time,burst2,arrival2,n);
	};


	public static void nonpreemptive(int burst[], int arrival[],int burst2[], int arrival2[], int program[], int n){
		
		int i, small, index, flag, time;
		int[] finish_time = new int[15];
		int[] job = new int[100];
		time = 0;
		index = 0;
		while(true){
			small = 400;
			flag = 0;
			for(i = 0; i < n; i++){
				if (burst[i] < small && arrival[i] <= time && burst[i] != 0){
					small = burst[i];
					index = i;
				}
				if (burst[i] != 0)
					flag = 1;
			}
			if (flag == 0)
				break;

			while(burst[index] != 0 && small != 400){
				job[time] = index;
				burst[index] = burst[index] - 1;
				time++;
			}
			if(small == 400)
				job[time++] = -1;
		
			if(burst[index] == 0)
				finish_time[index] = time;
		}
		System.out.println("SJF Non-Preemptive Result\n");
		for(i = 0; i < time; i++)
			System.out.print(job[i]+"   ");
		System.out.print("\n");
		turnaround_waiting(finish_time,burst2,arrival2,n);

	};

	

	public static void main(String[] args){

		int i,n;

		int[] burst = new int[15];
		int[] arrival = new int[15];
		int[] burst2 = new int[15];
		int[] arrival2 = new int[15];
		int[] burst3 = new int[15];
		int[] arrival3 = new int[15];
		int[] program = new int[15];

		Scanner take = new Scanner(System.in);
		System.out.println("Enter the number of jobs");
		n = take.nextInt();
		System.out.println("Enter the arrival time and burst time of each job");
		for(i = 0; i< n; i++){
			arrival[i] = take.nextInt();
			burst[i] = take.nextInt();
			burst2[i] = burst[i];
			arrival2[i] = arrival[i];
			arrival3[i] = arrival[i];
			burst3[i] = burst[i];
			program[i] = i;
		}
	
		System.out.println("Job with burst time and arrival time are");
		for(i = 0; i< n; i++)
			System.out.println(i + "\t" + arrival[i] + "\t" + burst[i]);

		preemptive(burst, arrival, burst2, arrival2, n);
		nonpreemptive(burst2, arrival2, burst3, arrival3, program, n);
	};
};


#include"bits/stdc++.h"

using namespace std;

struct Process {
	int pid;
	int bt;
	int priority;
};





void display_result(vector<Process> proc, int wt[]) {
	int n = proc.size();
	int tat[n];
	double total_wt = 0, total_tat = 0;

	for (int i = 0; i < n; i++)
		tat[i] = proc[i].bt + wt[i];

	cout << "\n Process \t" << "Burst time\t"
	     << "Waiting time\t" << "Turn around time\n";

	for (int i = 0; i < n; i++) {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << "\t" << proc[i].pid << "\t\t\t"
		     << proc[i].bt << "\t\t\t" << wt[i]
		     << "\t\t\t\t\t" << tat[i] << endl;
	}

	cout << "\nAverage waiting time = " << total_wt / n;
	cout << "\nAverage turn around time = " << total_tat / n << endl;
}






void display_result(vector<Process> processes) {
	int wt[processes.size()];
	wt[0] = 0;
	for (int i = 1; i < processes.size(); i++)
		wt[i] = processes[i - 1].bt + wt[i - 1];
	display_result(processes, wt);
}





void fcfs(vector<Process> processes) {
	cout << "\n---------------First Come First Serve---------------\n";
	display_result(processes);
}






void sjf(vector<Process> processes) {
	cout << "\n---------------Shortest Job First---------------\n";

	sort(processes.begin(), processes.end(), [](Process a, Process b) {
		return a.bt < b.bt;
	});

	display_result(processes);
}





void non_pp(vector<Process> processes) {
	cout << "\n---------------Non-preemptive priority---------------\n";

	sort(processes.begin(), processes.end(), [](Process a, Process b) {
		return a.priority < b.priority;
	});

	display_result(processes);
}





void round_robin(vector<Process> processes, int quantum) {
	cout << "\n---------------Round Robin---------------\n";

	int n = processes.size();
	int rem_bt[n], wt[n];
	for (int i = 0; i < n; i++)
		rem_bt[i] = processes[i].bt;

	int t = 0, count = n;

	while (count) {
		for (int i = 0; i < n; i++) {
			if (rem_bt[i] > 0) {
				if (rem_bt[i] > quantum) {
					t += quantum;
					rem_bt[i] -= quantum;
				} else {
					t = t + rem_bt[i];
					wt[i] = t - processes[i].bt;
					rem_bt[i] = 0;
					count--;
				}
			}
		}
	}
	display_result(processes, wt);
}






int main() {
	vector<Process> processes = {
		{1, 10, 3},
		{2, 1,  1},
		{3, 2,  3},
		{4, 1,  4},
		{5, 5,  2}
	};

	fcfs(processes);
	sjf(processes);
	non_pp(processes);
	round_robin(processes, 1);
}
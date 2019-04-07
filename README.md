#CSE316 Assignment

#Personal Info
Name: Yatharth Verma
Section: K17SM
Roll-No: 59
Group: 2

This Simulation Based Assignment contains two Questions.

Ques. 1. Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty. Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.

Ques. 2. There are 5 processes and 3 resource types, resource A with 10 instances, B with 5 instances and C with 7 instances. Consider following and write a c code to find whether the system is in safe state or not?


| Available     | Processes     | Allocation  |   Max     |
| ------------- |				| :----------:| --------: |
| A  B  C       | :-----------: | A   B   C	  | A   B   C |
| 3  3  2       | P0            | 0	  1	  0	  |	7	5	3 |
|               | P1            | 2	  0	  0	  |	3	2	2 |
|               | P2            | 3	  0	  2	  |	9	0	2 |
|               | P3            | 2	  1	  1	  |	2	2	2 |
|               | P4            | 0	  0	  2	  |	4	3	3 |

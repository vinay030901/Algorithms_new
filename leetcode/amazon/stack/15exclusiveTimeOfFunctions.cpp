/*
On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends,
its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed.
\Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.



Example 1:


Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
Example 2:

Input: n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
Output: [8]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls itself again.
Function 0 (2nd recursive call) starts at the beginning of time 6 and executes for 1 unit of time.
Function 0 (initial call) resumes execution at the beginning of time 7 and executes for 1 unit of time.
So function 0 spends 2 + 4 + 1 + 1 = 8 units of total time executing.
Example 3:

Input: n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
Output: [7,1]
Explanation:
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls function 1.
Function 1 starts at the beginning of time 6, executes 1 unit of time, and ends at the end of time 6.
Function 0 resumes execution at the beginning of time 6 and executes for 2 units of time.
So function 0 spends 2 + 4 + 1 = 7 units of total time executing, and function 1 spends 1 unit of total time executing.


Constraints:

1 <= n <= 100
1 <= logs.length <= 500
0 <= function_id < n
0 <= timestamp <= 109
No two start events will happen at the same timestamp.
No two end events will happen at the same timestamp.
Each function has an "end" log for each "start" log.*/
#include <bits/stdc++.h>
using namespace std;
struct Log
{
    int id;
    string work;
    int time;
};
/* this questions is somewhat confusing but after thinking for sometime we can find the approach to solve the question

there could be couple of cases here in this questions:
but before we know that this question will use stack

so we will first traverse the logs: and also have a struct with stack

1. if we have a start: then we need to put that into the stack, this means another process has started
2. if we get an end: means we need to stop a process, so we will take a log from the stack, which should be a start
and we will add the difference between the value to the answer vector
Another important aspect to know is that we can have element whose process has already started but got stopped by the one 
we are ending now, in that case will check if there is a start at the top of the stack, if there is
we will decrease the value of time difference from it, so that, when we will add the difference later,
the time taken by element between it will not get added, therefore we are decreasing that value from it earlier*/
vector<int> exclusiveTime(int n, vector<string> &logs)
{
    vector<int> ans(n, 0);
    stack<Log> s;
    for (string str : logs)
    {
        stringstream ss(str);
        string id1, work1, time1;
        // use of stringstream to split a string in cpp
        getline(ss, id1, ':');
        getline(ss, work1, ':');
        getline(ss, time1, ':');
        Log log = {stoi(id1), work1, stoi(time1)};
        if (log.work == "start")
            s.push(log);
        else
        {
            int time_added = log.time - s.top().time + 1;
            ans[log.id] += time_added;
            s.pop();
            if (!s.empty())
            {
                ans[s.top().id] -= time_added;
            }
        }
    }
    return ans;
}
int main()
{
}
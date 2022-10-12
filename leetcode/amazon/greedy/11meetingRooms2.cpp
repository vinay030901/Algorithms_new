/*
Description
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.)

(0,8),(8,10) is not conflict at 8

Example
Example1

Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)
Example2

Input: intervals = [(2,7)]
Output: 1
Explanation:
Only need one meeting room
*/
#include <bits/stdc++.h>
using namespace std;
struct Interval{
    int start,end;
};
static bool compare(Interval &a, Interval &b){
    return a.start < b.start;
}
int minMeetingRooms(vector<Interval> &train)
{
    int n=train.size();
    vector<int>arr(n),dep(n);
    for(int i=0;i<n;i++)
    {
        arr.push_back(train[i].start);
        dep.push_back(train[i].end);
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int mx=1,platform=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]){
           platform++;
           i++; 
        }
        else if(arr[i]<dep[j]){
            platform--;
            j++;
        }
        if(platform>mx) mx=platform;
    }
    return mx;
}
int main()
{
}
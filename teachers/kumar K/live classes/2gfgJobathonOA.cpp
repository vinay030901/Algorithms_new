/*
In a game of Geekland there are there are N (N>1) robots standing in a straight line each one holding a gun and having some health. At time t = 0, all the robots start firing bullets from their gun at a rate of one bullet per second towards their right. Bullets are designed in such a way that they can travel any distance in one second.

You are also given a power array, power[i] denotes the power of each bullet of ith robot. Basically, if any robot j is hit by ith robot then j's power decreases by power[i]. If health of any robot becomes less than one then that robot dies and vanishes from that point and the next robot (if present) becomes the neighbour the of previous robot.

Given health and power of bullets of each robot, you need to tell minimum time in which N-1 robots will die (obviously the first robot will never die).

Example 1:

Input:
N = 3
health = {1,2,1}
power = {2,1,3}
Output:
1
Explanation:
At t = 0, all the robots fire one bullet from their gun.
At t = 1, robot 2 and 3 die as their health become less than 1.
So after 1 second N-1(3-1=2) robots die.
Example 2:

Input:
N = 4
health = {4,5,2,6}
power = {1,3,2,3}
Output:
5
Explanation:
At t = 0, all the robots fire one bullet from their gun.
At t = 1, robot 3 dies and health of robot 2 and 4 become 4 each(5-1 and 6-2). Robot 1 2 and 4 fire a bullet now.
At t = 2, robot 4 gets hit by robot 2 and it's health becomes 1 (4-3). Robot 2 gets hit by robot 1 and it's health becomes 3 (4-1).
At t = 3, robot 4 dies as it's health fall below 1 after getting hit by robot 2. And health of robot 2 becomes 2 (3-1).
At t = 4, health of robot 2 becomes 1 (2-1).
At t = 5, robot 2 also dies after getting hit by robot 1.
So after 5 seconds N-1(4-1=3) robots die.*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<string>> arr = {{"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};
    for (int i = 0; i < arr.size(); i++)
    {
    }
}
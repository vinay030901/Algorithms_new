/*
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), 
the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. 
Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the 
third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.*/
/*


The logic is just to make sure that the event timing should clash with each other.
Example 
	30............40  (start is 30 and end is 40)
			35.............50 (s is 35 and e is 50)
			Clearly they will coincide
	s     s1    e       e1
	
	They will not coincide of e>s1 
	Or in reverse we can say they coincide if max(s,s1)<min(e,e2);

for myCalender 1: 



   MyCalendar() {}
    bool book(int start, int end) {
        for(auto &[s,e]:arr){
            if(max(s,start)<min(e,end)) return 0;
        }
        arr.push_back({start,end});
        return 1;
    }


	*/



#include<bits/stdc++.h>
using namespace std;
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    vector<pair<int,int>>single;
    vector<pair<int,int>>double_;
    // here we used a simple condition that
    // we have two vectors, single and double, if the time occured for once, then we put it in single and if it occurs twice
    // we put it in double

    bool book(int start, int end) {
        for(auto &[s,e]:double_)
        // so we check if that time has occured twice and return false, if it is
       {
           if(max(s,start)<min(e,end)) return false;
       }

       // checking if time zone has occured once, if it is, then put it in double and also put it in single if it is single 
       // because that might be a different range
       // so at last we return true whether it was single or not
       for(auto &[s,e]:single)
       {
           if(max(s,start)<min(e,end))
           {
           double_.push_back({max(s,start),min(e,end)});
           }
       } 
        single.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 **/

//given collection of intervals, merge all overlapping intervals
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int>> intervals{{1,3},{2,6},{8,10},{8,9},{9,11},{15,18},{2,4},{16,17}};
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> newIntervals;
    for(auto i=0;i<intervals.size();i++)
        {
            cout << intervals[i].first <<" "<<intervals[i].second <<"\n";
        }
    for(int i=0;i<=8;i++)
    {
        if(intervals[i].second>intervals[i+1].first)
        {
            intervals[i+1].first = intervals[i].first;
            intervals[i+1].second = max(intervals[i].second, intervals[i+1].second);
        }
        else
            newIntervals.push_back(make_pair(intervals[i].first,intervals[i].second));
        
    }
    cout<<"the overlapped intervals are: ";
    for(int i=0;i<newIntervals.size();i++)
        {
            cout << newIntervals[i].first <<" "<<newIntervals[i].second <<"\n";
        }

    /*leetcode 
    int ind=0;
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(intervals[ind][1]>=intervals[i][0])
            {
                intervals[ind][1]=max(intervals[ind][1],intervals[i][1]);
            }
            else
            {
                ind++;
                intervals[ind]=intervals[i];
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<=ind;i++)
        {
            ans.push_back(intervals[i]);
        }
        return ans;*/
}
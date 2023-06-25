#include <bits/stdc++.h>
using namespace std;
int timeToMinutes(string time)
{
    int hours, minutes;
    string meridian;

    stringstream ss(time);
    ss >> hours;
    ss.ignore(1, ':');
    ss >> minutes;
    ss >> meridian;

    if (meridian == "pm" && hours != 12)
    {
        hours += 12;
    }
    else if (meridian == "am" && hours == 12)
    {
        hours = 0;
    }

    return hours * 60 + minutes;
}
int calculateTimeDifference(string timeRange)
{
    size_t dashPos = timeRange.find('-');
    string time1 = timeRange.substr(0, dashPos);
    string time2 = timeRange.substr(dashPos + 1);

    int minutes1 = timeToMinutes(time1);
    int minutes2 = timeToMinutes(time2);

    if (minutes2 < minutes1)
    {
        minutes2 += 24 * 60; // Add 24 hours if transitioning to the next day
    }

    return minutes2 - minutes1;
}
// string fun(int arr[], int n)
// {
//     int a = arr[0];
//     string str = "";
//     for (int i = a; i < n; i++)
//         str += to_string(arr[i]);
//     for (int i = 0; i < a; i++)
//         str += to_string(arr[i]);
//     return str;
// }
int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    // cout << fun(arr, n) << endl;
    string str;
    cin >> str;
    cout << calculateTimeDifference(str);
}
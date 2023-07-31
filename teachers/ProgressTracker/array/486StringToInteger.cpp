#include <bits/stdc++.h>
using namespace std;
int myAtoi(string str)
{
    int i = 0, n = str.length(), sign = 1;
    while (i < n && str[i] == ' ')
        i++;
    if (i < n && (str[i] == '-' || str[i] == '+'))
        sign = 1 - 2 * (str[i++] == '-');
    int num = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        num = num * 10 + (str[i++] - '0');
    }
    return sign * num;
}
int main()
{
}
/*
Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].



Example 1:

Input: n = 3
Output: 3
Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.*/
/*
o make the problem much much more easier, I divide the problem into 3 parts:

calculate how many digits the number has.
calculate what the number is.
find out which digit in the number is we wanted.
You can find the relative code part in the code section.
Here is an example to help you to understand my code:

Example:

Input: 250

After step 1, you will find that the 250th digit must belong to a 3-digit number, since 19 can only provide 9 digits and 1099 can only provide 180 digits. Here, n = 250 - 9 - 90 * 2 = 61, and digits = 3.

In step 2, we will find the target number, which named as number in my code. From step 1, the n becomes to 61, which means "the 61st digit in 3-digit number is the digit we are looking for ." Easily, we know the 61st digit in 3-digit number belongs to number = 100 + 61 / 3 = 100 + 20 = 120. index is the index of the target digit in number. If index equals to 0, it means the target digit is the last digit of number.

Step 3, from step 2, we know index = n % digits = 61 % 3 = 1, which means the target digit is the 1st digit in number. Then, return 1.*/
#include <bits/stdc++.h>
using namespace std;
int findNthDigit(int n)
{
    if (n <= 9)
        return n;
    long base = 9, digits = 1;
    while (n - base * digits > 0)
    {
        n -= base * digits;
        base *= 10;
        digits++;
    }
    int index = (n - 1) % digits, offset = (n - 1) / digits;
    long start = pow(10, digits - 1);
    return to_string(start + offset)[index] - '0';
}
int main()
{

    return 0;
}
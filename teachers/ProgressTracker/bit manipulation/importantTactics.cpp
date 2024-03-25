/*1. Compute XOR from 1 to n (direct method):
The  problem can be solved based on the following observations:

Say x = n%4. The XOR value depends on the value if x. If

poster
×
x = 0, then the answer is n.
x = 1, then answer is 1.
x = 2, then answer is n+1.
x = 3, then answer is 0.
Below is the implementation of the above approach.


Learn Data Structures & Algorithms with GeeksforGeeks
Time Complexity: O(1)
Auxiliary Space: O(1)

Refer Compute XOR from 1 to n for details.

2. Count of numbers (x) smaller than or equal to n such that n+x = n^x:
The count of such numbers x can be counted using the following mathematical trick. 

The count = pow(2, count of zero bits).


Learn Data Structures & Algorithms with GeeksforGeeks
Output
1

Refer Equal Sum and XOR for details.

Time complexity: O(log n)

Auxiliary Space: O(1)

3. How to know if a number is a power of 2?
This can be solved based on the following fact:

If a number N is a power of 2, then the bitwise AND of N and N-1 will be 0. But this will not work if N is 0. So just check these two conditions, if any of these two conditions is true.

Refer check if a number is power of two for details.

Below is the implementation of the above approach.


//  Function to check if x is power of 2
bool isPowerOfTwo(int x)
{
     // First x in the below expression is
     // for  the case when x is 0 
     return x && (!(x & (x - 1)));
}
Learn Data Structures & Algorithms with GeeksforGeeks
Time Complexity: O(1)
Auxiliary Space: O(1)

4. Find XOR of all subsets of a set
We can do it in O(1) time. The answer is always 0 if the given set has more than one element. For sets with a single element, the answer is the value of the single element. 

Refer XOR of the XOR’s of all subsets for details.

5. Find the number of leading, trailing zeroes and number of 1’s
We can quickly find the number of leading, trailing zeroes and number of 1’s in a binary code of an integer in C++ using GCC. 

It can be done by using inbuilt functions i.e.

Number of leading zeroes: __builtin_clz(x)
Number of trailing zeroes : __builtin_ctz(x)
Number of 1-bits: __builtin_popcount(x) 

Refer GCC inbuilt functions for details.

6. Convert binary code directly into an integer in C++

// Conversion into Binary code
 
#include <iostream>
using namespace std;
 
int main()
{
    auto number = 0b011;
    cout << number;
    return 0;
}
Learn Data Structures & Algorithms with GeeksforGeeks
Output
3

Time Complexity: O(1)
Auxiliary Space: O(1)

7. The Quickest way to swap two numbers:
Two numbers can be swapped easily using the following bitwise operations:

a ^= b;
b ^= a; 
a ^= b;


#include <iostream>
using namespace std;
 
int main()
{
    int a = 5;
      int b = 7;
      cout<<"Before Swapping, a = "<<a<<" "<<"b = "<<b<<endl;
    a ^= b;
    b ^= a;
    a ^= b;
      cout<<"After Swapping, a = "<<a<<" "<<"b = "<<b<<endl;
    return 0;
}
 
// This code is contributed by akashish__
Learn Data Structures & Algorithms with GeeksforGeeks
Output
Before Swapping, a = 5 b = 7
After Swapping, a = 7 b = 5

Time Complexity: O(1)
Auxiliary Space: O(1)

Refer swap two numbers for more details.  

8. Finding the most significant set bit (MSB):
We can find the most significant set bit in O(1) time for a fixed size integer. For example below code is for 32-bit integer.  


int setBitNumber(int n)
{
    // Below steps set bits after
    // MSB (including MSB)
 
    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;
 
    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;
 
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
 
    // Increment n by 1 so that
    // there is only one set bit
    // which is just before original
    // MSB. n now becomes 1000000000
    n = n + 1;
 
    // Return original MSB after shifting.
    // n now becomes 100000000
    return (n >> 1);
}
Learn Data Structures & Algorithms with GeeksforGeeks
Time Complexity: O(1)
Auxiliary Space: O(1)

Refer Find most significant set bit of a number for details. 

9. Check if a number has bits in an alternate pattern
We can quickly check if bits in a number are in an alternate pattern (like 101010). 

Compute bitwise XOR (XOR denoted using ^) of n and (n >> 1). If n has an alternate pattern, then n ^ (n >> 1) operation will produce a number having all bits set.

Below is the implementation of the above approach.


// function to check if all the bits
// are set or not in the binary
// representation of 'n'
static bool allBitsAreSet(int n)
{
    // if true, then all bits are set
    if (((n + 1) & n) == 0)
        return true;
 
    // else all bits are not set
    return false;
}
 
// Function to check if a number
// has bits in alternate pattern
bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);
 
    // To check if all bits are set in 'num'
    return allBitsAreSet(num);
}
Learn Data Structures & Algorithms with GeeksforGeeks
Time Complexity: O(1)
Auxiliary Space: O(1)*/
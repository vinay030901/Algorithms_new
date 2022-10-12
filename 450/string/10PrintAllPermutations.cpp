/*
A permutation also called an “arrangement number” or “order,” is a rearrangement of the elements of an
ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation.


Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB*/
#include <bits/stdc++.h>
using namespace std;

/* this function take 3 parameters, string, starting index and ending index*/
void permutation(string str, int l, int r)
{
    if (l == r) // if both l and r are equal, we will return. l keep increasing when we go deep into recursion
    {
        cout << "answer: " << str << " " << endl;
        ;
        return;
    }
    else
    {
        for (int i = l; i <= r; i++) // we start the loop from l
        // we swap the value and then permute, when we print the value and return, swap again and then new
        // value is printed
        {
            swap(str[l], str[i]);
            cout << "swapped " << str[l] << " with " << str[i] << " with l: " << l << " and i:" << i << endl;
            cout << "permutation called with l=" << l + 1 << " and i:" << i << endl;
            permutation(str, l + 1, r);
            cout << "returned from permutation with l=" << l << " and i:" << i << endl;
            swap(str[l], str[i]);
            cout << "swapped " << str[l] << " with " << str[i] << " with l: " << l << " and i:" << i << endl;
        }
    }
}
int main()
{
    string str = "112";
    int n = str.length();

    // the first solution is just using stl function, we can use next_permutation to find all the permutations
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << str[i];
        }
        cout << " ";
    } while (next_permutation(str.begin(), str.end())); // next permutation is a function which give us a boolean
    // value that if next permutation is possible, and if it is, it permute it
    // this function give us the lexicographically ordered next permutation

    // using backtracking
    cout << endl;
    permutation(str, 0, n - 1);
}
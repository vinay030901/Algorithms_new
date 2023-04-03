/*
Given a text txt[0..n-1] and a pattern pat[0..m-1] where n is the length of the text and m is the length of the pattern, write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m. 
Examples: 

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12

first of all we will learn, how boyer mooore work, we will create the bad match table for the text

Boyer Moore is a combination of the following two approaches. 
1) Bad Character Heuristic 
2) Good Suffix Heuristic 

Bad Character Heuristic

The idea of bad character heuristic is simple. The character of the text which doesn’t match with the current 
character of the pattern is called the Bad Character. Upon mismatch, we shift the pattern until – 
1) The mismatch becomes a match
2) Pattern P moves past the mismatched character.\

Case 1 – Mismatch become match 
We will lookup the position of the last occurrence of the mismatched character in the pattern, 
and if the mismatched character exists in the pattern, then we’ll shift the pattern such that it 
becomes aligned to the mismatched character in the text T.

ex G C A A T G C C
   T A T G T G
here if we look g,t,g match from behind, but a and t didn't match, so we will align our string such that 
the a which is present in the string, will be aligned to the A which is mismatched.

G C A A T G C C
    T A T G T G

Case 2 – Pattern move past the mismatch character 
We’ll lookup the position of last occurrence of mismatching character in pattern and if character does not exist 
we will shift pattern past the mismatching character. 

G C A A T G C C
    T A T G T G
 here c and g doesn't match so we will move the whole string past the g
*/

#include<bits/stdc++.h>
using namespace std;
#define no_of_chars 256
void badtable(string str,int size,int badchar[no_of_chars])
{
    int i;
    for(int i=0;i<no_of_chars;i++)
    badchar[i]=-1;

    for(int i=0;i<size;i++)
    badchar[(int)str[i]]=i;
}

void search(string txt,string pat)
{
    int m=pat.size();
    int n=txt.size();
    int badchar[no_of_chars];
    badtable(pat,m,badchar);

    int s=0;
    while(s<=(n-m))
    {
        int j=m-1;
        while(j>=0 && pat[j]==txt[j+s])
        j--;
        if(j<0)
        {
            cout<<"pattern found at: "<<s<<endl;
            s+=(s+m)<n?m-badchar[txt[s-m]]:1;

        }
        else
        {
            s+max(1,j-badchar[txt[s+j]]);
        }
    }
}
int main()
{
    string txt= "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}
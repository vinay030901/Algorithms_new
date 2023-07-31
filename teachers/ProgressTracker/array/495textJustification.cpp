#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // https://leetcode.com/problems/text-justification/discuss/1987109/JavaC%2B%2BPythonJavaScriptKotlinSwiftO(n)timeBEATS-99.97-MEMORYSPEED-0ms-APRIL-2022
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int totalwords = words.size() - 1;
        for (int begin = 0, morewords = 0; begin <= totalwords; begin = morewords)
        {
            string currentBlock(maxWidth, ' ');
            /*our first block size*/
            currentBlock.replace(0, words[begin].size(), words[begin]);
            int remainingspace = maxWidth - words[begin].size();
            for (morewords = begin + 1; morewords <= totalwords && words[morewords].length() < remainingspace; morewords++)
            {
                remainingspace -= words[morewords].length() + 1;
            }
            int wordJoints = morewords - begin - 1;
            if (wordJoints)
            {
                int space = 1, unevenspace = 0;
                if (morewords <= totalwords)
                {
                    space += remainingspace / wordJoints;
                    unevenspace = remainingspace % wordJoints;
                }
                for (int i = begin + 1, index = words[begin].size(); i < morewords; i++)
                {
                    index += space + (unevenspace-- > 0);
                    currentBlock.replace(index, words[i].size(), words[i]);
                    index += words[i].size();
                }
            }
            result.push_back(currentBlock);
        }
        return result;
    }
};
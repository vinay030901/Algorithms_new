/*
Given a 2D grid of characters and a word, find all occurrences of the given word in the grid. A word can be matched in 
all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form).
The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically Down and 4 Diagonal directions.
Example: 

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0
Explanation: 'GEEKS' can be found as prefix of
1st 2 rows and suffix of first row

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "EEE"

Output: pattern found at 0, 2
        pattern found at 0, 10
        pattern found at 2, 2
        pattern found at 2, 12
Explanation: EEE can be found in first row 
twice at index 2 and index 10
and in second row at 2 and 12*/
#include <bits/stdc++.h>
using namespace std;
// these two arrays are to specify the direction of the matrix
int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
bool SearchWord(char *grid, int row, int col, string word, int R, int C)
{
    // we will check for the first character first and if it is equal, we will move on
    if (*(grid + C * row + col) != word[0])
    // if check if the first character is equal or not
        return false;

    int n = word.length();

    // so we are traversing for every direction here
    for (int dir = 0; dir<8; dir++)
    {
        // rd is used for the row index and cd is used for column index we are on while searching
        int k, rd = row + x[dir], cd = col + y[dir];
        for (k = 1; k < n; k++) // we will start searching from the first value, we can't start from first value even if 
        // we want to start from there
        {
            if (rd >= R || rd < 0 || cd >= C || cd < 0) // if we go out of index range while searching, then break
                break;
            if (*(grid + rd * C + cd) != word[k]) // the character doesn't match, we will stop
                break;
            rd += x[dir];
            cd += y[dir];
        }
        if (k == n) // if the word is matched, this means that value of k is equal to the length of the string, so return true
            return true;
    }
    return false; // return false by default
}
void gridSearch(char *grid, int row, int col, string word)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (SearchWord(grid, i, j, word, row, col))
                cout << "string found at index: " << i << " " << j << endl;
        }
}
int main()
{
    // here we need to search the word in given matrix, so we are using a character matrix for the process
    // in the process we used a direction array to specify the direction of ours

    // word only matches when the word in equal in that direction, this isn't the case that half of the string matches
    // in right and direction and the next direction continues in upper direction
    int R = 3, C = 13;
    char grid[R][C] = {"GKPSRFORGEEKS", "GEEKSQUIZGEEKP", "IDEQAPRACTICE"};

    string word = "GEEKS";
    gridSearch((char *)grid, R, C, word);
}
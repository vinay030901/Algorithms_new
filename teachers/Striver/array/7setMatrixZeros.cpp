/*given an m*n matric=x, if any element in it is zero, set its row and column with zero*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int col0 = 1;
    vector<vector<int>> matrix{{0, 3, 4, 0}, {1, 2, 3, 4}, {4, 5, 6, 7}};
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 1; j--)
        {

            //         if (matrix[i][0] == 0 || matrix[0][j] == 0)
            //             matrix[i][j] = 0;
            //     }
            //     if (col0 == 0)
            //         matrix[i][0] = 0;
            // }
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        for (int k = 0; k < row; k++)
                        {
                            if (matrix[k][j] != 0)
                            {
                                matrix[k][j] = -1;
                            }
                        }
                        for (int k = 0; k < col; k++)
                        {
                            if (matrix[i][k] != 0)
                            {
                                matrix[i][k] = -1;
                            }
                        }
                    }
                }
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                    if (matrix[i][j] == 0 || matrix[i][j] == -1)
                        cout << "0 ";
                    else
                        cout << matrix[i][j] << " ";
                cout << endl;
            }
            // for (int i = 0; i < row; i++)
            // {
            //     for (int j = 0; j < col; j++)
            //         cout << matrix[i][j] << " ";
            //     cout << endl;
            // }
        }

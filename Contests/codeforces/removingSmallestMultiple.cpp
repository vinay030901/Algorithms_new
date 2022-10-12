#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 5)
            cout << "-1\n";
        else
        {
            if (n % 2 == 0)
            {
                int i = 1, j = n / 2 + 1;
                for (int k = 0; k < n / 2; k++)
                {
                    cout << i << " " << j << " ";
                    i++;
                    j++;
                }
                cout << "\n";
            }
            else
            {
                int i = 1, j = n / 2 + 2;
                for (int k = 0; k < n / 2; k++)
                {
                    cout << i << " " << j << " ";
                    i++;
                    j++;
                }
                cout << i << endl;
            }
        }
    }
    return 0;
}

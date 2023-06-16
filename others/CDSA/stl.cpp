#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
int main()
{
    // vector
    vector<int> v1;
    vector<int> v2(10);
    // size, value
    vector<int> v3(10, 2);
    for (int i = 0; i < 10; i++)
        cout << v3[i] << " ";

    // value push or add
    v1.push_back(10);
    cout << "\n"
         << v1[0];

    cout << "\nsizes: " << v1.size() << " " << v2.size() << " " << v3.size() << endl;
    v1.push_back(2);
    cout << v1.front() << " " << v1.back() << endl;
    cout << v1.at(0);

    v1.push_back(3);
    sort(v1.begin(), v1.end());
    cout << "\n";
    for (auto it : v1)
        cout << it << " ";
    cout << *min_element(v1.begin() + 1, v1.end()) << endl;
    cout << *max_element(v1.begin(), v1.end()) << endl;
    v1.pop_back();
    cout << endl;
    for (auto it : v1)
        cout << it << " ";
    v1.clear();
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << endl;
}
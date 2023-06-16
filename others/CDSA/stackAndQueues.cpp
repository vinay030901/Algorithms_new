#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    if (st.empty() == true)
        cout << "stack is empty";
    else
        cout << "stack is not empty\n";
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(50);
    cout << q.front() << endl;
    queue<int> q2 = q;
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << "\n"
         << q2.size() << " " << q.size() << endl;
}
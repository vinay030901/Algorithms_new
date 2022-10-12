/*You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once. 

Example 1:
https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.*/
#include <bits/stdc++.h>
using namespace std;
/*so this is an interesting from all means
we need three data structures to solve this question: map, set and stack
a map will be used as an adjacency list while set will be the second part of the map, we can use vector but we will neet to
sort all the values after that

it looks simple first as we just need to go to every element and then take the first value in that, that is, set, and make it
current, we will do the same for the current city to, but the problem arises when we take a wrong route, or we can't go any further
that's why we use the stack,

what we do is when we will keep pushing elements in the stack whenever we move further, but when a condition arise when we can't move further
we pop the stack and put it in our answer and remove from set, that is we will reach there at last Now

so we will get our answer in reverse order, then we will reverse the ans vector and return*/
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    unordered_map<string, multiset<string>> adj;
    for (int i = 0; i < tickets.size(); i++)
        adj[tickets[i][0]].insert(tickets[i][1]);
    vector<string> ans;
    stack<string> st;
    st.push("JFK");
    while (!st.empty())
    {
        string src = st.top();
        if (adj[src].size() == 0)
        {
            ans.push_back(src);
            st.pop();
        }
        else
        {
            auto dst = adj[src].begin();
            st.push(*dst);
            adj[src].erase(dst);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/*instead of using stack, we can use recursion or dfs for our process
so the process is same as above but here we are calling recursion here*/
unordered_map<string, multiset<string>> adj;
void dfs(vector<string> &ans, string src)
{
    while (!adj[src].empty())
    {
        string dst = *adj[src].begin();
        adj[src].erase(adj[src].begin());
        dfs(ans, dst);
    }
    ans.push_back(src); // when the src is empty
}
vector<string> findItinerary(vector<vector<string>> &tickets)
{

    for (int i = 0; i < tickets.size(); i++)
        adj[tickets[i][0]].insert(tickets[i][1]);
    vector<string> ans;
    dfs(ans, "JFK");
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
}
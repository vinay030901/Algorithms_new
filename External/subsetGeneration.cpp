// write the power set 
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define int long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define print(v) for(int i=0;i<(int)v.size();i++) cout<<v[i]<<" ";
const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

vector<vector<int>>v;
void generate(vector<int>&subset,int i,vector<int>&nums)
{   
    // here we are either taking the integer in our subset or not taking it, we are doing this with every element
    // whenever we take that integer we need to undo that step too, so this step is called the backtrackling step here
    if(i==nums.size()) 
    {
        v.push_back(subset);
        return;
    }

    // here we are not taking the element and just moving on
    generate(subset,i+1,nums);

    // but here we pushed the element into the subset
    subset.push_back(nums[i]);
    generate(subset,i+1,nums);
    // this is the backtracking step and therefore undo the changes when we reach the end of the tree
    subset.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>subset;
    generate(subset,0,nums);
    return v;
}
void solve()
{
    vector<int>nums={1,2,3,4};
    vector<vector<int>>ans=subsets(nums);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
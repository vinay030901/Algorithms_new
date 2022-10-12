#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--){
  string miss;
  int k;
  cin>>miss;
  cin>>k;
  int n=miss.length();
  set<char>set;
  for(int i=0;i<n;i++){
    set.insert(miss[i]);
  }
  bool ansfound=false;
    string str=miss;
    int f=0; 
    for(int i=0;i<n-k;i++)
    {
      char c=str[i];
      if(str[i+k]=='?' || str[i+k]==c)
        str[i+k]=c;
      else if(c=='?')
      {
        if(str[i+k]=='?')
        {
          char ch='a';
          /*for(int j=0;j<26;j++)
          {
            if(set.find(ch)==set.end())
            {*/
              str[i]='a';
              str[i+k]=ch;
              /*set.insert(ch);
              break;
            }
            else{
              ch++;
            }*/
          
        }
        else{
          str[i]=str[i+k];
        }
      }
      else{
        f=1;
      } 
      if(f==1)
      break;
    }
  
  int q=0;
  for(int i=0;i<n-k; i++)
  
    if(str[i]!=str[i+k] || (str[i]<)
      q=1;
  if(q==0)
  {
    ansfound=true;
    cout<<str<<endl;
  }
  if(ansfound==false) cout<<"-1\n";
}
  return 0;
}
/*#include <bits/stdc++.h>
using namespace std;



int main() {
  int t;
  for (cin >> t; t > 0; t--) {
    string s;
    cin >> s;
    int k, n = (int) s.size();
    cin >> k;

    vector<vector<int>> cnt(k, vector<int>(27));

    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        cnt[i % k][26]++;
      } else {
        cnt[i % k][s[i] - 'a']++;
      }
    }
    bool ok = 1;
    string ans(k, '?');
    for (int i = 0; i < k; i++) {
      bool hasq = cnt[i][26] > 0;
      int firstAlphabet = -1, cA = 0;
      for (int j = 25; j >= 0; j--) {
        if (cnt[i][j] > 0) {
          firstAlphabet = j;
          cA++;
        }
      }
      if (cA > 1) ok = 0;
      else if (cA == 1) {
        ans[i] = firstAlphabet + 'a';
      } else {
        ans[i] = 'a';
      }
    }

    if (!ok) {
      cout << "-1\n";
      continue;
    }

    for (int i = 0; i < n; i++) {
      assert(ans[i % k] != '?');
      cout << ans[i % k];
    }
    cout << '\n';
  }
  return 0;
}*/
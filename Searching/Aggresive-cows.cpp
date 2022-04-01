#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
const ld Pi = 3.141592653;
const ll mod = 1e9 + 9;
#define hihi ll t;cin>>t;while(t--)
vector <ll> primes;
ll modoinv(ll a, ll m)
{ll m0 = m; ll y = 0, x = 1; if (m == 1) {return 0;} while (a > 1) {ll t, q = a / m; m = a % m, a = t; t = y; y = x - q * y; x = t;} if (x < 0) {x += m0;} return x;}
class Graph
{
  map<ll , vector<ll>> ma;
public:
  void addedge(ll n, ll m)
  {
    ma[n].pb(m);
    ma[m].pb(n);
  }
};
class Node
{
public:
  char data;
  unordered_map<char, Node*> children;
  bool terminal;
  Node(char d)
  {
    data = d;
    terminal = false;
  }
};
class Trie
{
public:
  Node* root;
  ll cnt;
  Trie()
  {
    root = new Node('\0');
    cnt = 0;
  }
  void insert(char *w)
  {
    Node* temp = root;
    for (ll i = 0; w[i] != '\0'; i++)
    {
      char ch = w[i];
      if (temp->children.count(ch))
      {
        temp = temp->children[ch];
      }
      else
      {
        Node* n = new Node(ch);
        temp->children[ch] = n;
        temp = n;
      }
    }
    temp->terminal = true;
  }
 
  bool find(string w)
  {
    Node* temp = root;
    for (ll i = 0; w[i] != '\0'; i++)
    {
      char ch = w[i];
      if (temp->children.count(ch) == 0)
        return false;
      else
      {
        temp = temp->children[ch];
      }
    }
    return temp->terminal;
  }
};
vector<ll> primeFactors(ll n)
{
  vector<ll> ans;
  ll cur = 1;
  ans.pb(1);
  while (n % 2 == 0)
  {
    cur = cur * 2;
    ans.pb(cur);
    n = n / 2;
  }
  for (ll i = 3; i * i <= (n); i = i + 2)
  {
    while (n % i == 0)
    {
      cur = cur * i;
      ans.pb(cur);
      n = n / i;
    }
  }
  if (n > 2)
    ans.pb(cur * n);
  return ans;
}
void sieve(ll p)
{
  vector <bool> mark(p, 1);
  for (ll i = 3; i < p; i += 2)
  {
    if (mark[i] == 1)
    {
      for (ll j = i * i ; j < p ; j += 2 * i)
      {
        mark[j] = 0;
      }
    }
  }
  primes.pb(2);
  for (ll i = 3; i < p; i += 2)
  {
    if (mark[i])
      primes.pb(i);
  }
}
ll mod_exp(ll x, ll n, ll m)
{
  if (n == 0)
    return 1 % m;
  ll a = mod_exp(x, n / 2, m);
  if (n % 2 == 0)
    return (a * a) % m;
  else
    return (x * a * a) % m;
}
bool isPrime(ll n)
{
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0)
      return 0;
  return 1;
}
 
int gcd(int x, int y) {
    if (x < y) {
        return gcd(y, x);
    }
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}
bool check(int a[],int n,int m,int no)
{
    int s=1;
    int temp=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]-temp>=no)
        {
            s+=1;
            temp=a[i];
        }
    }
    return s>=m;
}
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
     int n,c;
     cin>>n>>c;
     int a[n];
     int ans;
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }
     sort(a,a+n);
     int s=0,e=a[n-1]-a[0];
     while(s<=e)
     {
         int mid=s+(e-s)/2;
         if(check(a,n,c,mid))
         {
             ans=mid;
             s=mid+1;
         }
         else
         {
             e=mid-1;
         }
     }
     cout<<ans;
     cout<<endl;
 }
 
  return 0;
}

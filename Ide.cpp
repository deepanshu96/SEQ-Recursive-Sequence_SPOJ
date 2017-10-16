/*
        ________________
       /.,------------,.\
      ///  .=^^^^^^^\__|\\
      \\\   `------.   .//
       `\\`--...._  `;//'
         `\\.-,___;.//'
           `\\-..-//'
             `\\//'
               ""
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, b, sizeof a)
#define FOR(i, j, k, in) for ( i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for ( i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF LONG_MAX
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000000
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
typedef pair<int, int> pii;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
//variables
ll k;
ll b[20],c[20];
ll b2[20][1];
ll c2[20][20];
ll c3[20][20];
ll N;
//func
void mul(ll a[20][20],ll b[20][20])
{
 ll r[20][20];
 
 ll i,j,g;
 FOR(i,0,k,1)
    {
     FOR(j,0,k,1)
        {
         r[i][j]=0;
         FOR(g,0,k,1)
            {
                r[i][j] = (r[i][j]+ a[i][g]*b[g][j])%MOD;
            }
        }
    }
 memcpy(a,r,sizeof r);
}
void mul2(ll a[20][20],ll b[20][1])
{
 ll r;
 
 ll i,j,g;
 FOR(i,0,k,1)
    {
     FOR(j,0,1,1)
        {
         r=0;
         FOR(g,0,k,1)
            {
                r= ( r + a[i][g]*b[g][j])%MOD;
            }
        }
    }
 cout<<r%MOD<<endl;
}
void pwr(ll n)
{
 
 if(n<=1)    
    {
     return ;
    }
 else if(n==2)
    {
     mul(c2,c2);
     return ;
    }
 
 if(n%2==0)
    {
     pwr(n/2);
     mul(c2,c2);
     return ;
    }
 else
    {
     pwr(n/2);
     mul(c2,c2);
     mul(c2,c3);
     return ;
    }
 return;
}
//main

int main()
{
 ll i,j;
 int t;
 cin>>t;
 while(t--)
 {
   cin>>k;
   FOR(i,0,k,1)
    cin>>b[i];
   FOR(i,0,k,1)
    cin>>c[i];
   cin>>N;
   if(N<=k)
   {
     cout<<b[N-1]<<endl;
     continue ;
   }
   FOR(i,0,k,1)
    b2[i][0]=b[i];
   FOR(i,0,k-1,1)
    {
     c2[i][i+1]=1;
    }
   FOR(i,0,k,1)
    c2[k-1][i]=c[k-1-i];
 
  
  memcpy(c3,c2,sizeof c2);
  /*   
  FOR(i,0,k,1)
    {
     FOR(j,0,k,1)
        cout<<c3[i][j]<<" "; 
     cout<<endl;
    }    
   */
  pwr(N-k);
  /*FOR(i,0,k,1)
    {
     FOR(j,0,k,1)
        cout<<c2[i][j]<<" "; 
     cout<<endl;
    }*/ 
  mul2(c2,b2);  
  MEM(c2,0);
  MEM(c,0);
  MEM(b,0);
  MEM(b2,0);
  /*FOR(i,0,k,1)
    {
     FOR(j,0,k,1)
        cout<<c2[i][j]<<" "; 
     cout<<endl;
    }*/ 
 }
  return 0;    
}
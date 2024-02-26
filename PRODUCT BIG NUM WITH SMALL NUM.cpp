#include <iostream>
#include <cmath>
#include <string>

#define ll long long
#define ull unsigned long long
using namespace std;
int ans[1000];
int main ()
{
   string a;
   cin >>a;
   int b;
   cin >>b;

   if (b ==0) cout <<0;
   else
   {
      int r =0;
      for (int i =a.size()-1; i >=0; i--)
      {
         int value =(a[i]-'0')*b +r;
         if (value >9)
         {
            ans[i] =value%10;
            r =value/10;
         }
         else
         {
            ans[i] =value;
            r =0;
         }
      }
      ans[0] +=10*r;
      for (int i =0; i <a.size(); i++)
         cout <<ans[i];
   }
   return 0;
}

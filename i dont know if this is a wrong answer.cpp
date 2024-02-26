#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findRadius(vector<int> houses, vector<int> heaters)
{
   sort(houses.begin(), houses.end());
   sort(heaters.begin(), heaters.end());
   int hou = houses.size();
   int hea = heaters.size();
   if (hea == 1)
      return max(abs(heaters[0] - houses[0]),abs(heaters[0] - houses[hou-1]));
   else
   {
      int r = 0;
      for (int i = 0; i < hou; i ++)
      {
         vector<int>::iterator found;
         //find house in array of heater
         found = lower_bound(heaters.begin(), heaters.end(), houses[i]);
         int pos = found - heaters.begin();
         //always house[i]<heater[pos]

         if (pos == 0){
            if (houses[i] < heaters[pos] - r)
               r += heaters[pos] - r - houses[i];
         }
         else if (pos == hea){
            if (heaters[pos - 1] + r < houses[i])
               r += houses[i] - heaters[pos - 1] - r;
         }//2 outside house
         else
            if (heaters[pos-1]+r < houses[i] && houses[i] < heaters[pos]-r)
               r += min(houses[i]-heaters[pos-1]-r, heaters[pos]-r-houses[i]);

      }
      return r;
   }
}
int main()
{
   int a[]={1,2,4,5,6,7};
   vector<int> houses(a,a+6);
   int b[]={1,4};
   vector<int> heaters(b,b+2);

   cout << findRadius(houses,heaters);
   return 0;
}

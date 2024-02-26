#include <iostream>
#include <fstream>
using namespace std;
int getMoney (int * houses, char * path)
{
   ifstream file(path);
   int money, count = 0;
   while (file >> money)
   //danh so kieu C++
      houses[count ++] = money;
   return count;
}
int rob(int * houses, int numOfHouses)
{
   int ans = 0;
   int * F;
   F = new int[numOfHouses];
   //-------------------
   if (numOfHouses >= 3)
   {
      F[numOfHouses - 1] = houses[numOfHouses - 1];
      F[numOfHouses - 2] = houses[numOfHouses - 2];
      F[numOfHouses - 3] = houses[numOfHouses - 3] + houses[numOfHouses - 1];
      for (int i = numOfHouses - 4 ; i >= 0 ; i--)
      {
         if (F[i + 2] >= F[i + 3])
            F[i] = houses[i] + F[i + 2];
         else F[i] = houses[i] + F[i + 3];
      }

      if (F[0] >= F[1])
         ans = F[0];
      else ans = F[1];
   } else
      if (numOfHouses == 1) ans = houses[0];
         else if (houses[0] >= houses[1]) ans = houses[0];
            else ans = houses[1];

   //-------------------
   return ans;
}

int main()
{
   int house[300];
   char path[] = "input.txt";
   int home_Amount = getMoney(house, path);
   cout << rob(house, home_Amount)<<endl;
   //cout << house[0];
   return 0;
}

#include <iostream>
using namespace std;
template <typename T>
void sort(T arr[], int n)
{
   int min = 0;
   for (int i = 0; i < n - 1; i++)
   {
      min = i;
      for (int j = i + 1; j < n; j++)
      {
         if (arr[i] > arr[j])
         {
            min = j;
         }
      }
      T temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
   }
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}
int main()
{
   int ch, n;
   do
   {

      cout << "\n\nMenu" << endl;
      cout << "1.sorting of int array" << endl;
      cout << "2.sorting of float array" << endl;
      cout << "3.exit" << endl;
      cout << "Enter Your Choice:";
      cin >> ch;
      cout << "Enter Size of array";
      cin >> n;
      int arr[n];
      float arr2[n];
      if (ch == 1)
      {
         for (int i = 0; i < n; i++)
         {
            cin >> arr[i];
         }

         sort<int>(arr, n);
      }
      else if (ch == 2)
      {
         for (int i = 0; i < n; i++)
         {
            cin >> arr2[i];
         }
         sort<float>(arr2, n);
      }
      else
      {
         cout << "Exiting..";
         break;
      }

   } while (ch != 3);
   return 0;
}

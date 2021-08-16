#include<iostream>
#include <fstream>
#include<math.h>
using namespace std;
int comparisions = 0;
int jumpSearch(int[], int, int );
int jumpS(int[], int, int );
int main(){
    int n, total, key;
    cout<<"All user entered inputs are stored in file input3.txt"<<endl;
    cout<<"All outputs are displayed on screen"<<endl;
    cout<<"Enter no of test cases"<<endl;
    cin>>n;
 ofstream f1("input3.txt");
     if (f1.is_open())
  {
f1<<n<<endl;

    for(int i=0; i<n; i++){
        cout<<"ENTER DETAILS OF TEST CASE "<<i+1<<endl;
        cout<<"Enter size of array";
        cin>>total;
        int arr[total];
        cout<<"Enter array elements in sorted order";
        for(int j=0; j<total; j++){
            cin>>arr[j];
        }
        cout<<"Enter key element to search:";
        cin>>key;

        f1<<total<<endl;
        for(int k=0; k<total; k++)
                       f1<<arr[k]<<" ";


      f1<<endl<<key<<endl;
    }
 }
  else cout << "Unable to open file";
  f1.close();
  ifstream f2("input3.txt");
  if (!f2.is_open()) {
        cerr << "Could not open the file - '"<< endl;
        return EXIT_FAILURE;
    }
            int ele,search1;
            f2>>n;
            for(int i=1;i<=n;i++)    {
            f2>>ele;
            int j,arr[ele];
            for(j = 0;j< ele;j++)
                f2>>arr[j];
            f2>>search1;
            comparisions = 0;
    int loc;
    if((loc = jumpS(arr, ele,search1,)) >= 0)
      cout << "Present "<<comparisions<<endl;
   else
    cout<< "Not Present "<<comparisions<<endl;

    }
 f2.close();
}
int jumpS(int arr[], int n, int x)
{
    int jump = sqrt(n);
    int prev = 0;
    while (arr[min(jump, n)-1] < x)
    { comparisions = comparisions+1;
        prev = jump;
        jump += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while (arr[prev] < x)
    { comparisions = comparisions+1;
        prev++;
         if (prev == min(jump, n))
            return -1;
    }
     if (arr[prev] == x)
        return prev;
    return -1;
}

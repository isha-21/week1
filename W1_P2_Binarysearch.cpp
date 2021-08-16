#include<iostream>
#include <fstream>
using namespace std;
int comparisions = 0;
int binarySearch(int[], int , int, int);
int main(){
    int n, total, key;
    cout<<"All user entered inputs are stored in file input1.txt"<<endl;
    cout<<"All outputs are displayed on screen"<<endl;
    cout<<"Enter no of test cases"<<endl;
    cin>>n;
 ofstream f1("input2.txt");
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
  ifstream f2("input2.txt");
  if (!f2.is_open()) {
        cerr << "Could not open the file - '"<< endl;
        return EXIT_FAILURE;
    }


    comparisions=0;
                    f2>>n;
              for(int i=1;i<=n;i++)    {
            int ele,search1;
            f2>>ele;
            int j,arr[ele];
            for(j = 0;j< ele;j++)
                f2>>arr[j];
            f2>>search1;
            comparisions = 0;
                    int loc = binarySearch (arr, 0, ele-1, search1);
   if(loc == -1){
      cout<< "Not Present "<<comparisions<<endl;
   }else{
          cout<< "Present "<<comparisions<<endl;
   }
    }
 f2.close();
}
int binarySearch(int arr[], int l, int h, int num) {
   if (l <= h) {
      int mid = (l + h)/2;
      comparisions = comparisions + 1;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binarySearch(arr, l, mid-1, num);
      if (arr[mid] < num)
         return binarySearch(arr, mid+1, h, num);
   }
   return -1;
}

#include<iostream>
#include <fstream>
using namespace std;

int main(){
    int n, total, key;
    cout<<"All user entered inputs are stored in file input1.txt"<<endl;
    cout<<"All outputs are displayed on screen"<<endl;
    cout<<"Enter no of test cases"<<endl;
    cin>>n;
 ofstream f1("input1.txt");
     if (f1.is_open())
  {
f1<<n<<endl;

    for(int i=0; i<n; i++){
        cout<<"ENTER DETAILS OF TEST CASE "<<i+1<<endl;
        cout<<"Enter size of array";
        cin>>total;
        int arr[total];
        cout<<"Enter array elements";
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
  ifstream f2("input1.txt");
  if (!f2.is_open()) {
        cerr << "Could not open the file - '"<< endl;
        return EXIT_FAILURE;
    }


    int found = 0,comparisions = 0;
                    f2>>n;
              for(int i=1;i<=n;i++)    {
            int ele,search1;
            f2>>ele;
           // cout<<"ELE = "<<ele;
            int j,arr[ele];
            for(j = 0;j< ele;j++)
                f2>>arr[j];
            f2>>search1;
            comparisions = 0;
            found = 0;
            for(j = 0;j< ele;j++)
            {   // cout<<"ele = "<<ele<<"   n="<<n<<"  i = "<<i<<"  j = "<<j<<"search1 = "<<search1<<"arr[j]"<<arr[j]<<endl;
                comparisions = comparisions + 1;
                if (arr[j] == search1) {   found = 1;
                    cout<<"Present "<<comparisions<<endl;
                    break;
                }
            }
            if ( found == 0 )
                cout<<"Not Present "<<comparisions<<endl;
       }
        return EXIT_FAILURE;
    f2.close();
 }

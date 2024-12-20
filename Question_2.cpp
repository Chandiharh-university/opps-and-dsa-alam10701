//Implementation by array

#include<iostream>
using namespace std;

int main() {
    
    
    int n;
    cin>>n;
    
    int arr[n];
    cout<<"Enter The Elements Of Array: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    cout<<endl;
    
    cout<<"Elements Of Array Are: "<<endl;
    
    for(int i = 3; i < n; i++) {
        cout<<"\nIndex is: "<<i<<" Element Is: "<<arr[i]<<" ";
    }
    
    return 0;
    
}


//Implementation by vector

#include<iostream>
#include<vector>
using namespace std;

int main() {
    
    
    vector<int> kool;
    int n;
    cin>>n;
    kool.push_back(n);
    while(n != 0) {
    cin>>n;
    if(n == 0) {
        break;
    }
    kool.push_back(n);
    
    
    }
    
    for(int i =0; i< kool.size(); i++) {
        cout<<kool[i]<<" ";
    }
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < 3; i++) {
        cin>>arr[i];
    }
    
    cout<<endl;
    
    for(int i = 0; i < n; i++) {
        cout<<"Element Is: "<<arr[i]<<" Address Is: "<<&arr[i]<<endl;
    }
    return 0;
}
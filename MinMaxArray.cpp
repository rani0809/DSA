#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n,key;
    cin>>n;
   int arr[1000];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=INT_MIN;
    int smallest=INT_MAX;
   
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
        largest=arr[i];
        }
       if
        (arr[i]<smallest){
            smallest=arr[i];
        }
    }
    cout<<"largest "<<largest<<endl;
    cout<<"smallest "<<smallest<<endl;

    return 0;
}
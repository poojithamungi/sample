// // it is having the time complexity of O(1)
// // accessing of an eleements in an array by using indexing
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5]={1,2,3,4,5};
//     cout<<arr[2]<<endl;
//     cout<<arr[0];
    
// }
// // it is used for tuyhe time complexity of O(n)
// by using for loop to accessing the elements in an array
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5]={1,2,3,4,5};
//     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
//         cout<<arr[i]<<" ";
//     }
    
// }
// // it is having the time complexity of O(logn)
// // it is using the /2
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,4,7,89};
//     int target=7;
//     int low=0,high=5;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid]==target){
//             cout<<"the target"<<" "<<target<<"is found at index"<<" "<<mid<<endl;
//             break;
//         }
//         else if(arr[mid]<target){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
// }
// // this algorithm is having the time complexity of O(nlog n)
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//     vector<int>v={1,2,4,6,8,0,5,3,7};
//     cout<<"before sorting:"<<endl;
//     for(auto i:v){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     sort(v.begin(),v.end());
//     cout<<"after sorting:"<<endl;
//     for(auto i:v){
//     cout<<i<<" ";
//     }
// }
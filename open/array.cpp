#include<iostream>

#include<vector>

#include<algorithm>

Using namespace std;

Void reversearray(vector<int>&arr)

{

Int left=0,right=arr.size()-1;

While(left<right)

{

Swap(arr[left++],arr[right--]);

}

}

Int main(){

Vector<int> arr={1,2,3,4,5};

Cout<<"before reversing array is:";

For(int num:arr)

{

Cout<<num<<” ”;

}

Cout<<endl;

Reversearray(arr);

Cout<<”reversed array is:”;

For(int num:arr)

{

Cout<<num<<” ”;

}

Cout<<endl;

Return 0;

}
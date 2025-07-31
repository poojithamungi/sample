#include<iostream>
using namespace std;
int main(){
    int *ptr=(int*)calloc(3,sizeof(int));
    
    if(ptr==nullptr){
        cout<<"memory not allocated"<<endl;
    }
    ptr[0]=10;
    ptr[1]=20;
    ptr[2]=30;
    ptr=(int*)realloc(ptr,5*sizeof(int));
    if(ptr==nullptr){
        cout<<"memory not reallocated"<<endl;
    }
    ptr[3]=40;
    ptr[4]=50;
    for(int i=0;i<5;i++){
        cout<<ptr[i]<<endl;
    }
    free(ptr);
    return 0;

}
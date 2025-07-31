// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//     vector<int>v={1,2,3,4,5};
//     vector<int>v1={6,7,8,9,10};
//     vector<int>merged(v.size()+v1.size());
//     merge(v.begin(),v.end(),v1.begin(),v1.end(),merged.begin());
//     for(auto i:merged){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     vector<int>v2={1,3,6,2,7,10};
//     vector<int>inplacemerged;
//     inplace_merge(v2.begin(),v2.begin()+3,v2.end());
//     for(auto i:v2){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     vector<int>v3={1,2,3,4,5};
//     vector<int>v4={6,7,8,9,9,10};
//     vector<int>union1(v3.size()+v4.size());
//     auto it=set_union(v3.begin(),v3.end(),v4.begin(),v4.end(),union1.begin());
//     union1.resize(it-union1.begin());
//     for(auto i:union1){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     vector<int>v5={1,2,3,4,5};
//     vector<int>v6={1,2,6,7,8,9,9,10};
//     vector<int>intersect(v5.size()+v6.size());
//     auto it1=set_intersection(v5.begin(),v5.end(),v6.begin(),v6.end(),intersect.begin());
//     intersect.resize(it1-intersect.begin());
//     for(auto i:intersect){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     // minelement and maxelement are the pointers not a noramal functions
//     auto minelement=min_element(v6.begin(),v6.end());
//     cout<<*minelement<<" ";
//     cout<<endl;
//     auto maxelement=max_element(v6.begin(),v6.end());
//     cout<<*maxelement<<" ";
//     cout<<endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> heap = {10, 20, 30, 5, 15};

    // 1. Convert to heap
    make_heap(heap.begin(), heap.end());
    cout << "After make_heap: ";
    for (int i : heap) cout << i << " ";
    cout << endl;

    // 2. Add a new element
    heap.push_back(99);
    push_heap(heap.begin(), heap.end());
    cout << "After push_heap(99): ";
    for (int i : heap) cout << i << " ";
    cout << endl;

    // 3. Remove the max (top) element
    pop_heap(heap.begin(), heap.end()); // puts max at end
    cout << "After pop_heap (before removing): ";
    for (int i : heap) cout << i << " ";
    cout << endl;
    heap.pop_back(); // now actually remove it
    cout << "After pop_back(): ";
    for (int i : heap) cout << i << " ";
    cout << endl;

    // 4. Check if it's a heap
    cout << "Is heap? " << (is_heap(heap.begin(), heap.end()) ? "Yes" : "No") << endl;

    // 5. Sort the heap
    sort_heap(heap.begin(), heap.end());
    cout << "After sort_heap: ";
    for (int i : heap) cout << i << " ";
    cout << endl;

    return 0;
}

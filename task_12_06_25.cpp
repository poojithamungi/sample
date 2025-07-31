#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> camera_versions = {101, 102, 103, 104};
    vector<int> radar_versions = {101, 102, 105, 107, 103};
    vector<int> update_server_versions = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};

    // 1. Find common firmware versions supported by all sensors (intersection)
    vector<int> common_versions(min(camera_versions.size(), radar_versions.size()));
    auto it = set_intersection(camera_versions.begin(), camera_versions.end(),
                               update_server_versions.begin(), update_server_versions.end(),
                               common_versions.begin());
    common_versions.resize(it - common_versions.begin());

    cout << "compatible across all sensors are: ";
    for (auto x : common_versions) {
        cout << x << " ";
    }
    cout << endl;

    // 2. Merge camera and radar versions using std::merge
    vector<int> merged(camera_versions.size() + radar_versions.size());
    cout << "merges sensors firmware versions: ";
    merge(camera_versions.begin(), camera_versions.end(),
          radar_versions.begin(), radar_versions.end(),
          merged.begin());
    for (auto i : merged) {
        cout << i << " ";
    }
    cout << endl;

    // 3. Use inplace_merge with the vector named 'inplace_merge' (as requested)
    vector<int> inplace_merged;  // start empty vector
    inplace_merged.reserve(camera_versions.size() + radar_versions.size());

    // Insert camera versions
    inplace_merged.insert(inplace_merged.end(), camera_versions.begin(), camera_versions.end());
    // Insert radar versions
    inplace_merged.insert(inplace_merged.end(), radar_versions.begin(), radar_versions.end());

    // Now inplace_merge the two consecutive sorted ranges inside 'inplace_merge' vector
    inplace_merge(inplace_merged.begin(), inplace_merged.begin() + camera_versions.size(), inplace_merged.end());

    cout << "inplace merged sensors firmware versions: ";
    for (auto i : inplace_merged) {
        cout << i << " ";
    }
    cout<<endl;
    vector<int> union_versions(camera_versions.size() + update_server_versions.size());  // max size
    auto it_union = set_union(camera_versions.begin(), camera_versions.end(),
                              update_server_versions.begin(), update_server_versions.end(),
                              union_versions.begin());
    union_versions.resize(it_union - union_versions.begin());

    cout <<"performing set_union operations: ";
    for (auto x : union_versions) {
        cout << x << " ";
    }
    cout << endl;
    //vector<int>oldest(update_server_versions.size());
    auto min=min_element(update_server_versions.begin(),update_server_versions.end());
    auto max=max_element(update_server_versions.begin(),update_server_versions.end());
    cout<<"oldest_version is:";
    if(min!=update_server_versions.end()){
        cout<<*min;
        
    }
    cout<<endl;
    cout<<"latest version is:";
    if(max!=update_server_versions.end()){
        cout<<*max;
        
    }
    return 0;
}

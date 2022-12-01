//sort the array based on freq also maintain the order

#include<bits/stdc++.h>
using namespace std;


//custom sort Compare function
bool compareEle(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if(p1.second.second != p2.second.second)  //if they have diff freq
    return p1.second.second > p2.second.second;   //if p1 has high freq then p2 then it will go to the front of the array.
    else  //if they have same freq.
    return p1.second.first < p2.second.first;  //if p1 has low index then p2 then it will go to the front of the array.
}


//this fucntion shows us how to use pair with vectors, custom sort and maps.
vector<int> sortBasedOnFreq(int arr[], int n) {
    
    //first we need to create a freq table Like ele --> (eleIndex, Its Frequency)
    //note: pair always goes like make_pair(x,y), pair.first, pair.second.
    unordered_map<int, pair<int, int>> m;
    for(int i=0;i<n;i++) {
        if(m.find(arr[i]) != m.end()) {   //If found.
            m[arr[i]].second++;  //m[arr[i]] --> gives us the value part i.e pair, and paris.second take the second ele of that pair.
        } else {
            m[arr[i]] = make_pair(i, 1);  //putting new pair in the map.
        }
    }
    
    //now we have the freq map, lets create a vector from the map of same structure.
    vector<pair<int, pair<int, int>>> v;
    unordered_map<int, pair<int, int>>::iterator it;
    for(it= m.begin(); it!=m.end(); it++) {
        v.push_back(make_pair(it->first,it->second));   //this will push {ele, {index, freq}} format in the vector.
    }
    
    //v--> {{ele, {index, freq}} , {ele, {index, freq}}, {ele, {index, freq}}}
    
    //now we have the vector so let sort it with custom sort.
    sort(v.begin(), v.end(), compareEle);
    
    //now we have sorted the array now lets append the element in order in the resp.
    vector<int> resp;
    for(auto pt:v) {
        int count = pt.second.second;
        while(count--)
        resp.push_back(pt.first);
    }
    return resp;
}

int main() {
    
    //very very important to understand...
    //Sort the arr based on the freq. (maintain order of the ele.)
    int arr[] = {2,5, 2, 8, 5, 6, 8, 8};
    int n = sizeof(arr)/sizeof(int);
    
    vector<int> v = sortBasedOnFreq(arr, n);
    
    for(auto i:v) {
        cout<<i<<" ";
    }
    
    return 0;
}
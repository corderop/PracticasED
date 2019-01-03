#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> a;

    a.push_back(3);
    a.push_back(4);

    a.erase(a.begin()+(a.size()-1));

    for(int i=0; i<a.size(); i++){
        cout<<a[i];
    }
}
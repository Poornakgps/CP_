#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<int, int> nearest_multiples(int num) {
    return {round(num / 5.0) * 5, round(num / 10.0) * 10};
}

bool canMakeSum(const vector<int>& arr, int k) {
    int pref[32]={};
    for(int i=0; i<n; i++){
        for(int bit = 31; bit>=0; bit--){
            if((bit>>1) & arr[i]){
                pref[bit]++;
                break;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=31; i++){
        ans += (pref[i]*(pref[i]-1))/2
    }
    cout<<ans<<endl;
}

int main() {
    vector<int> arr = {1, 6, 4, 6, 7};
    int k = 22;
    cout << (canMakeSum(arr, k) ? "Yes" : "No") << endl;
    return 0;
}

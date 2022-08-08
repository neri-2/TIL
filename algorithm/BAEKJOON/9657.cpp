#include <iostream>
#include <vector>
#include <algorithm>

// #9657번 돌 게임 3

using namespace std;

int main(void){
    int n;
    vector<int> dp;
    cin >> n;
    dp.push_back(1);
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);

    for(int i = 4; i < n; i++){
        if(min({dp[i-1], dp[i-3], dp[i-4]}) == 1)
            dp.push_back(0);
        else
            dp.push_back(1);
    }

    if(dp[n-1])
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
    return 0;
}
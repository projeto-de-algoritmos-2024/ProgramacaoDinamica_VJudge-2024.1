#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) {

    int firstBuy = INT_MIN; 
    int firstSell = 0;         
    int secondBuy = INT_MIN;   
    int secondSell = 0;        

    for (int price : prices) {
        firstBuy = max(firstBuy, -price);             
        firstSell = max(firstSell, firstBuy + price);  
        secondBuy = max(secondBuy, firstSell - price); 
        secondSell = max(secondSell, secondBuy + price); 
    }
    return secondSell; 
}

int main() {
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Maximum Profit: " << maxProfit(prices1) << endl; // Saída esperada: 6

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Maximum Profit: " << maxProfit(prices2) << endl; // Saída esperada: 4

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Maximum Profit: " << maxProfit(prices3) << endl; // Saída esperada: 0

    return 0;
}

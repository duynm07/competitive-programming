/**
 * @file 1175-PrimeArrangements.cpp
 * @author Duy M. Nguyen (duy.nm.1998@gmail.com)
 * @brief https://leetcode.com/problems/prime-arrangements/description/
 * @date 23:09 12/04/23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    const long long MOD = 1000000007;

    long long numPrimeArrangements(long long n) {

        // Sàng nguyên tố
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i])
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
        }

        // Đếm số số nguyên tố trong khoảng từ 1 đến n
        long long count = 0;
        for (long long i = 0; i <= n; i++) {
            if (isPrime[i])
                count++;
        }

        // Tính kết quả
        long long result = 1;
        for (long long i = 1; i <= count; i++) {
            result = (result * i) % MOD;
        }
        for (long long i = 1; i <= n - count; i++) {
            result = (result * i) % MOD;
        }

        return result;
    }
};

int main() {
    Solution solution = Solution();

    int output = solution.numPrimeArrangements(100);
    cout << output << endl;
}
//
//  multiply.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
using namespace std;

long long A, B, C, k;

long long multiply(long long b) {
    if (b == 0) return 1;
    if (b == 1) return A % C;

    k = multiply(b / 2) % C;
    if (b % 2 == 0)
        return k * k % C;
    return k * k % C * A % C;
}

int main() {

    cin >> A >> B >> C;

    cout << multiply(B);

    return 0;
}

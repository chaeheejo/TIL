#include <iostream>
#include <map>
using namespace std;

int main() {

    map<int, int> m;
    m.insert({ 4,10 });
    m.insert({ 90, 7 });

    //수정 가능
    m[90] = 9;
    //key가 이미 존재하면 무시
    m.insert({ 10,3 });

    //key에 대해서만 확인
    if (m.find(5) != m.end()) {
        cout << "exist\n";
    }

    //순회
    for (auto it = m.begin(); it != m.end(); it++) {
        pair<int, int> p = *it;
        int key = p.first;
        int value = p.second;
        cout << key << ' ' << value << '\n';
    }

    return 0;
}

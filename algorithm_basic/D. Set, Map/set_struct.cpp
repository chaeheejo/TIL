#include <iostream>
#include <set>
using namespace std;

struct Coord {
    int row;
    int col;

    bool operator<(const Coord right) const {
        //struct에서 활용되는 모든 변수에 대해서 비교 기준을 세워줘야 함
        if (row < right.row) return true;
        if (row > right.row) return false;

        if (col > right.col) return true; //col은 큰 게 우선
        if (col < right.col) return false;
        return false;
    }
};

int main() {

    set<Coord> s;
    s.insert({ 0,1 });
    s.insert({ 1,2 });

    return 0;
}

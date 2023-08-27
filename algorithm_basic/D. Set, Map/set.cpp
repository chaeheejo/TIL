#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(7);

    //set은 정렬이 자동으로 되어 들어감
    //1-3-5-7 순
    auto it_start = s.lower_bound(1); //1 이상이 시작하는 위치 - 어디부터 되는지
    auto it_end = s.upper_bound(5); //5 초과가 시작하는 위치 - 어디까지 되는지

    //find로는 특정 데이터가 없을 경우, 오류가 나지만
    //lower_bound, upper_bound로는 특정 구간에 있는 원소를 찾을 수 있음

    for (auto it = it_start; it != it_end; it++) {
        cout << *it << ' ';
    }

    //없는 수를 지워라 - 무시
    s.erase(9);

    //iterator 이동
    auto it = s.begin();
    it = next(it, 2); //현재 위치에서 두 칸 뒤로 - 앞에서부터 세번째 데이터

    it = prev(it, 1); //현재 위치에서 한 칸 앞으로 - 앞에서부터 두번째 데이터

    return 0;
}

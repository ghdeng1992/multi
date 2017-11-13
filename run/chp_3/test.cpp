#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    stack<int> sta;
    for (int i = 0; i < 10; i++) {
        sta.push(i);
    }

    int num;
    sta.pop(num);
    cout << num << endl;
    return 0;
}
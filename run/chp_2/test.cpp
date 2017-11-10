#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>


//using std::cout ;
using namespace std;

void func() {
    for (int i = 0; i < 10; i++) {
        cout << "a";
    }
}

int main(){
    vector<int> num;
    for (int i = 0; i < 10; i++){
        num.push_back(i);
    }

    cout << accumulate(num.begin(), num.end(), 0) << endl;

    // std::thread t(func);
    // cout << t.get_id() << std::endl;

    // t.join();
    // // t.join();
     
    // int thread_nums = std::thread::hardware_concurrency();
    // cout << thread_nums << std::endl;


    // std::thread tt;
    // cout << tt.get_id() << std::endl;    

    // cout << std::this_thread::get_id() << std::endl;
  
    return 0;
}

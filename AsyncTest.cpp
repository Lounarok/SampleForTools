//https://godbolt.org/z/x456394eq
#include <iostream> 
#include <vector>
#include <fmt/core.h>
#include <string>
#include <future>
static int a = 0;
void datalogger(std::string s1){
    std::cout << s1 << '\n';
}

int main()  
{
    std::string s1{"s1"};
    std::string s2{"s2"};
    std::vector<std::future<void>> v;

    for(int i = 0; i < 10; i++){
        auto f1 = std::async(std::launch::async, [=](){
            datalogger(std::to_string(i));
        });
        v.push_back(std::move(f1));
    }
    for(int i =0; i < 1000000; i++){
        a+=i;
    }
    std::cout << "finished\n";

    return 0; 
}  

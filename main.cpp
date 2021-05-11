#include <iostream>
#include "test.hpp"

void bar(const foo& test_foo){
    std::cout << test_foo.product() << std::endl;
}

int main(){
    foo test_foo{5,6};
    bar(test_foo);
    std::cout << "hello world" << std::endl;
}
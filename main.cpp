#include <iostream>
//#include "include/test.hpp"

class foo{
    public:
        foo():_x{0},_y{0}{};
        foo(const double x, const double y):_x{x},_y{y}{};
        double product() const;
    private:
        double _x;
        double _y;
};

double foo::product() const{
    return _x*_y;
}

void bar(const foo& test_foo){
    std::cout << test_foo.product() << std::endl;
}

int main(){
    foo test_foo{5,6};
    bar(test_foo);
    std::cout << "hello world" << std::endl;
}
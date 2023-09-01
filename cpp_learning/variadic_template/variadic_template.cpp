#include "variadic_template.hpp"
int main(int argc, char* argv[]) {
    print(7.5, 7.5);
    print(7.5, "hello", 42);

    MyTuple tuple_a = MyTuple<int, float, int>(1, 2.0, 3);
    
    std::cout<<"Tuple:"<<tuple_a.head()<<std::endl;
    std::cout<<"Tuple:"<<tuple_a.tail().head()<<std::endl;
    std::cout<<"Tuple:"<<tuple_a.tail().tail().head()<<std::endl;

}
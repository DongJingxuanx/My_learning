#include<iostream>
#include<vector>
#ifndef _VARIADIC_TREMPLATE
#define _VARIADIC_TREMPLATE
void print() {
    std::cout<<"specialization!"<<std::endl;
}

template<typename T, typename... Types>
void print(const T& t1, const Types&... t_many) {
    std::cout << t1 <<std::endl;
    print(t_many...);
}

template<typename... Types>
void print(const Types&... t_many) {
    std::cout <<"generalization!"<<std::endl;
}

//regualar template

//variadic template
//template<>class MyTuple<> {};
template<typename... Tail>
class MyTuple;

template<> class MyTuple<> {};

template<typename Head, typename... Tail>
class MyTuple<Head, Tail...>: private MyTuple<Tail...>{
public:
    typedef MyTuple<Tail...> inherited;
    MyTuple() {};
    MyTuple(const Head& vhead, const Tail&... vtail) {
        head_ = vhead;
        tail_ = inherited(vtail...); 
    }

    Head head() const {return head_;}
    inherited tail() const {return tail_;}
protected:
Head head_;
inherited tail_;
};






#endif
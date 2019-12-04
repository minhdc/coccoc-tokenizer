#include "hello.hpp"

Hello::Hello(string userName){
    this -> userName = userName;
}

string Hello::getUserName(){
    return this -> userName;
}
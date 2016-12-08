#include "GSTestClass.hh"
#include <iostream>
using namespace std;

GSTestClass::GSTestClass(int argc, char*argv[]){
}    
GSTestClass::GSTestClass(const GSTestClass &obj){
}
GSTestClass::~GSTestClass(){
}
void GSTestClass::TestMethod(){
  cout << "test output" << endl;
}



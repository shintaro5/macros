#ifndef _GSTestClass_hh_
#define _GSTestClass_hh_
    
class GSTestClass{
public:
  GSTestClass(int argc, char*argv[]);
  GSTestClass(const GSTestClass &obj);
  virtual ~GSTestClass();
  void TestMethod();
private:
};
#endif

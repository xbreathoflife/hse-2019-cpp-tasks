#ifndef TEST_H_
#define TEST_H_

#include <iostream>

#define DO_CHECK(EXPR) Test::check(EXPR, __func__, __FILE__, __LINE__)

class Test {
protected:
    static int failedNum;
    static int totalNum;
    static void check(bool expr, const char *func, const char  *filename, size_t lineNum); 

public:
    static bool showFinalResult();
    virtual void runAllTests() = 0;

};

#endif /* TEST_H_ */
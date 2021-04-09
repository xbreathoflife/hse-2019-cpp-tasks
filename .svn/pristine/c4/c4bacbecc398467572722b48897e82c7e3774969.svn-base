#include <iostream>
#include "Test.h"

int Test::totalNum = 0;
int Test::failedNum = 0;

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
    totalNum++;
    if (!expr) {
        std::cout << "Error!!!\nFunction: " << func << "\nFilename: " << filename <<
            "\nLine number: " << lineNum << "\n\n";
        failedNum++;
    } 
}

bool Test::showFinalResult() {
    std::cout << "Number of tests: " << totalNum << "\n";
    std::cout << "Number of failed tests: " << failedNum << "\n";

    if (failedNum > 0)
        return false;
    return true;
}

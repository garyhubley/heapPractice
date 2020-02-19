#include "tests/utilities.h"

static int testCount = 0;
static int testsPassed = 0;

void printTestDescription(std::ostream &out, const std::string &desc) {
    out << "Test " << ++testCount << ": " << std::endl;
    out << "   " << desc << std::endl;
}

void printTestResult(std::ostream &out, Result result) {
    out << "   Test ";
    if (result == Result::PASS) {
        testsPassed++;
        out << "PASSED";
    } else {
        out << "FAILED";
    }
    out << std::endl << std::endl;
}

void printTestSummary(std::ostream &out) {
    out << std::endl
        << "Summary: \n    " << testsPassed << "/" << testCount
        << " tests passed." << std::endl
        << std::endl;
}

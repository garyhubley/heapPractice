#pragma once
#include <ostream>
#include <string>

enum Result { FAIL, PASS };

void printTestDescription(std::ostream &out, const std::string &desc);
void printTestResult(std::ostream &out, Result result);
void printTestSummary(std::ostream &out);


#include <cstdlib>
#include <ctime>
#include "heap/heap.h"
#include "tests/utilities.h"

#pragma warning(disable : 6386)

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == std::string("-v")) {
        Heap::printVersion(std::cout);
        return 0;
    }

    std::srand(std::time(nullptr));

    int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    printTestDescription(std::cout, "Testing constructor from c-array");
    Heap hp(arr, 11);
    printTestResult(std::cout, static_cast<Result>(hp.isEmpty() == false));

    printTestDescription(std::cout, "Testing insert() and find()");
    hp.Insert(72);
    printTestResult(std::cout, static_cast<Result>(hp.Find(72) == true));

    printTestDescription(std::cout, "Testing Print()");
    std::cout << "   ";
    hp.Print(std::cout);
    printTestResult(std::cout, Result::PASS);

    printTestDescription(std::cout, "Testing default constructor");
    Heap hp2;
    printTestResult(std::cout, static_cast<Result>(hp2.isEmpty() == true));

    printTestDescription(std::cout, "Testing DeleteMax()");
    hp.DeleteMax();
    printTestResult(std::cout, static_cast<Result>(hp.Find(100) == false));

    printTestDescription(std::cout, "Testing ExtractMax()");
    printTestResult(std::cout, static_cast<Result>(hp.ExtractMax() == 90 &&
                                                   hp.Size() == 10));

    printTestDescription(std::cout, "Testing Insert()");
    int hp2Size = 30;

    for (int i = 0; i < hp2Size; i++) {
        hp2.Insert(std::rand() % 1000);
    }
    std::cout << "   ";
    printTestResult(std::cout, static_cast<Result>(hp2.Size() == hp2Size));

    printTestDescription(std::cout, "Testing Merge() and assignment operator");
    Heap hp3 = hp2.Merge(hp);

    printTestResult(std::cout,
                    static_cast<Result>(hp3.Size() == hp.Size() + hp2Size));

    printTestSummary(std::cout);
    std::cin.get();
}

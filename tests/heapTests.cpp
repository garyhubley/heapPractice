#include "Heap.h"
#include <cstdlib>
#include <ctime>

#pragma warning( disable : 6386 )

int main() {
	std::srand(std::time(nullptr));

	int arr[] = { 0,10,20,30,40,50,60,70,80,90,100 };
	Heap hp(arr, 11);
	hp.Insert(72);
	hp.Print(std::cout);
	Heap hp2;
	
	if (hp2.isEmpty())
		std::cout << "hp2 is empty" << std::endl;

	hp.DeleteMax();
	hp.Print(std::cout);

	std::cout << hp.ExtractMax() << std::endl;
	std::cout << "\nhp: ";
	hp.Print(std::cout);

	for (int i = 0; i < 30; i++) {
		hp2.Insert(std::rand());
	}

	std::cout << "\nhp2: ";
	
	hp2.Print(std::cout);
	
	std::cout << "\nhp3: ";
	Heap hp3 = hp2.Merge(hp);
	
	hp3.Print(std::cout);

	std::cout << hp.Size();

	std::cin.get();
}
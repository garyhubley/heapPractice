#pragma once
#include <iostream> 

enum class HeapType { MIN, MAX };
class Heap
{
private:
	int *_data = nullptr;
	unsigned _size = 0;
	unsigned _capacity = 0;
	HeapType _type = HeapType::MAX;

	// updating a key within a max - or min - heap, respectively
	void IncreaseKey();

	// delete an arbitrary node(followed by moving last node and sifting to maintain heap)
	void Delete(unsigned node);

	void Heapify();

	// move a node up in the tree, as long as needed; used to restore heap condition after insertion.Called "sift" 
	// because node moves up the tree until it reaches the correct level, as in a sieve.
	void SiftUp(unsigned node);

	// move a node down in the tree, similar to sift - up; used to restore heap condition after deletion or replacement.
	void SiftDown(unsigned node);

	unsigned GetLeftChild(unsigned node);
	unsigned GetRightChild(unsigned node);
	void Swap(unsigned node1, unsigned node2);

public:
	// create an empty heap
	Heap();

	// create a heap out of given array of elements
	Heap(int arr[], int sz);

	// copy constructor
	Heap(const Heap &orig);

	// destructor
	~Heap();

	Heap &operator=(const Heap &rhs);

	// find a maximum item of a max - heap, or a minimum item of a min - heap, respectively(a.k.a.peek)
	int FindMax();

	// adding a new key to the heap(a.k.a., push[4])
	void Insert(int value);

	// returns the node of maximum value from a max heap[or minimum value from a min heap] after removing it from 
	// the heap(a.k.a., pop[5])
	int ExtractMax();

	// removing the root node of a max heap[or min heap], respectively
	void DeleteMax();

	// pop root and push a new key.More efficient than pop followed by push, since only need to balance once, not 
	// twice, and appropriate for fixed - size heaps.[6]
	int Replace(int value);

	// joining two heaps to form a valid new heap containing all the elements of both, preserving the original heaps.
	Heap Merge(const Heap &other);
	
	// return the number of items in the heap.
	int Size();

	// return true if the heap is empty, false otherwise.
	bool isEmpty();

	std::ostream &Print(std::ostream &out);

};

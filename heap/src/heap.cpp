#include "heap/heap.h"
#include <limits>

#pragma warning(disable : 6386)

inline unsigned GetParent(unsigned node) {
    int x = (node - 1) / 2;
    return (static_cast<int>(node) - 1) / 2;
}

Heap::Heap() {}

Heap::~Heap() {
    if (_data != nullptr) {
        delete[] _data;
    }
}

Heap::Heap(int arr[], int sz) : _size(sz), _capacity(2 * sz) {
    _data = new int[_capacity]();

    for (unsigned i = 0; i < _size; i++) {
        _data[i] = arr[i];
    }

    Heapify();
}

Heap::Heap(const Heap &orig) : _size(orig._size), _capacity(orig._capacity) {
    _data = new int[_capacity];

    for (unsigned i = 0; i < _size; i++) {
        _data[i] = orig._data[i];
    }
}

void Heap::IncreaseKey() {}

void Heap::Delete(unsigned node) {
    _size--;
    _data[node] = _data[_size];
    _data[_size] = 0;
    SiftDown(node);
}

void Heap::Heapify() {
    int parent = static_cast<int>(GetParent(_size - 1));
    while (parent >= 0) {
        SiftDown(parent--);
    }
}

void Heap::SiftUp(unsigned node) {
    unsigned parent;

    while ((parent = GetParent(node)) != 0) {
        if (_data[parent] > _data[node]) {
            return;
        }

        // swap
        Swap(parent, node);
        node = parent;
    }
}

void Heap::SiftDown(unsigned node) {
    unsigned leftChild, rightChild;
    while ((leftChild = GetLeftChild(node)) < _size) {
        // has at least one child.
        unsigned greatestChild;

        greatestChild = leftChild;

        if ((rightChild = GetRightChild(node)) < _size &&
            _data[rightChild] > _data[leftChild]) {
            greatestChild = rightChild;
        }

        if (_data[node] > _data[greatestChild]) {
            // can't sift down any further.
            return;
        }

        Swap(node, greatestChild);
        node = greatestChild;
    }
}

unsigned Heap::GetLeftChild(unsigned node) { return node * 2 + 1; }

unsigned Heap::GetRightChild(unsigned node) { return node * 2 + 2; }

void Heap::Swap(unsigned node1, unsigned node2) {
    int temp = _data[node1];
    _data[node1] = _data[node2];
    _data[node2] = temp;
}

Heap &Heap::operator=(const Heap &rhs) {
    if (this == &rhs) return *this;
    _size = rhs._size;
    _capacity = rhs._capacity;
    if (_data != nullptr) {
        delete[] _data;
    }
    _data = new int[_capacity];

    for (unsigned i = 0; i < _size; i++) {
        _data[i] = rhs._data[i];
    }

    return *this;
}

bool Heap::Find(int value) {
    for (int i = 0; i < _size; ++i) {
        if (_data[i] == value) {
            return true;
        }
    }
    return false;
}

int Heap::FindMax() {
    if (_data == nullptr) {
        return std::numeric_limits<int>::max();
    }

    return _data[0];
}

void Heap::Insert(int value) {
    if (_size == _capacity) {
        // memory is full
        _capacity = (_capacity == 0) ? 2 : _capacity * 2;
        int *temp = _data;
        _data = new int[_capacity];

        for (unsigned i = 0; i < _size; i++) {
            _data[i] = temp[i];
        }
        delete[] temp;
    }

    _data[_size] = value;

    // sort
    SiftUp(_size);

    _size++;
}

int Heap::ExtractMax() {
    if (isEmpty()) {
        return 0;
    }
    int ret = _data[0];
    Delete(0);

    return ret;
}

void Heap::DeleteMax() {
    if (isEmpty()) {
        return;
    }
    Delete(0);
}

int Heap::Replace(int value) {
    if (isEmpty()) {
        return 0;
    }
    int ret = _data[0];  // pop

    _data[0] = value;
    SiftDown(0);

    return ret;
}

Heap Heap::Merge(const Heap &other) {
    Heap ret;
    ret._size = _size + other._size;
    ret._capacity = ret._size * 2;
    ret._data = new int[ret._capacity];

    unsigned i;

    // copy first heap
    for (i = 0; i < _size; i++) {
        ret._data[i] = _data[i];
    }

    // copy second heap
    for (unsigned j = 0; j < other._size; i++, j++) {
        ret._data[i] = other._data[j];
    }

    ret.Heapify();

    return ret;
}

int Heap::Size() { return _size; }

bool Heap::isEmpty() { return _size == 0; }

std::ostream &Heap::Print(std::ostream &out) {
    for (unsigned i = 0; i < _size; i++) {
        out << _data[i] << " ";
    }
    out << std::endl;
    return out;
}

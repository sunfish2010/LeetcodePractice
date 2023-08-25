#include "trees/bst.hh"

#include <map>
#include <iostream>
using namespace std;

int main() {
    // Setting up test cases.
    BinarySearchTree<int, int> bst;
    for(int i = 0; i < 10; ++i){
        bst[i] = i + 10;
        std::cout << "key: " << i << ", value: " << bst[i] << std::endl; 
    }

    bst.erase(5);
    assert(!bst.contains(5));

}
#include "hashtable/sc_hash.hh"

#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    // Setting up test cases.
    // unordered_map<int, int> expected;
    // for(int i = 0; i < 10;++i){
    //     expected[i] = i;
    // }

    SeparateChainingHashTable<int, int> hash_table;
    for(int i = 0; i < 10; ++i){
        hash_table[i] = i + 10;
        std::cout << "key: " << i << ", value: " << hash_table[i] << std::endl; 
    }

    hash_table.erase(5);
    assert(!hash_table.contains(5));

}
#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdlib.h>

template<typename Key, typename Value>
class HashTable{
    public:
    size_t size() const{
        return num_elements_;
    }

    virtual Value& operator[] (const Key& key) = 0;


    virtual bool contains(const Key& key) const = 0;

    // virtual void erase(const Key& key) const = 0;

    protected:
    size_t num_elements_;
};

#endif
//
// Created by asem on 17.01.18.
//

#ifndef OWNALLOCATOR_SMALLALLOCATOR_H
#define OWNALLOCATOR_SMALLALLOCATOR_H

#include <cstdio>
#include <string.h>
const int MULT_COEF = 1; // firstly we trying allocate block with size MULT_COEF * requestedSize

class SmallAllocator {
    struct BlockDescriptor {
        bool is_free;
        unsigned int block_size;
        unsigned int requested;
    };
private:
    char Memory[1024*1024];
    BlockDescriptor *lastDescr;
    BlockDescriptor* findBlock(unsigned int requstedSize);
    bool tryDefragmentate(BlockDescriptor *start);
public:
    void walkD() const; // for testing!!!
    SmallAllocator();
    void *Alloc(unsigned int requestedSize);
    void *ReAlloc(void *Pointer, unsigned int Size);
    void Free(void *Pointer);
};

#endif //OWNALLOCATOR_SMALLALLOCATOR_H

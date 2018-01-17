//
// Created by asem on 17.01.18.
//

#include "SmallAllocator.h"

void SmallAllocator::walkD() const {
    const BlockDescriptor *curD = reinterpret_cast<const BlockDescriptor*>(&Memory);
    int i = 0;
    int fullSize = 0;
    while(curD <= lastDescr) {
        printf("#%d size: %u status: %s\n",++i,curD->block_size,curD->is_free?"free":"busy");
        fullSize += curD->block_size;
        curD = static_cast<const BlockDescriptor*>(curD->block_size + static_cast<const void*>(curD));
    }
    if(sizeof(Memory) == fullSize) printf("\x1b[32m[ OK ] Full memory size: %u Real memory size: %u\x1b[0m\n",fullSize, sizeof(Memory)*
                                                                                                                        sizeof(char));
    else printf("\x1b[31m[ ERROR ] Full memory size: %u Real memory size: %u\x1b[0m\n",fullSize, sizeof(Memory)*sizeof(char));
    if(lastDescr != reinterpret_cast<const BlockDescriptor*>(&Memory)) {
        printf("\x1b[31m[ MAYBE ERROR ] lastDecriptor doesn't placed at the memory start. Maybe not all memory free\x1b[0m\n");
    } else printf("\x1b[32m[ MAYBE OK ] lastDecriptor placed at the memory start\x1b[0m\n");
} // for testing!!!

SmallAllocator::SmallAllocator() {
    BlockDescriptor *firstDescriptor = reinterpret_cast<BlockDescriptor*>(&Memory);
    lastDescr = firstDescriptor;
    firstDescriptor->block_size = sizeof(Memory)* sizeof(char);
    firstDescriptor->is_free = true;
}

void *SmallAllocator::Alloc(unsigned int requestedSize) {
    unsigned int allocatedSize = requestedSize; // size which we really allocated. usually MULT_COEF*requested
    allocatedSize *= MULT_COEF;
    BlockDescriptor *curBlockD = findBlock(allocatedSize);
    if(!curBlockD) {
        if(tryDefragmentate(reinterpret_cast<BlockDescriptor*>(&Memory))) {
            curBlockD = findBlock(allocatedSize);
        }
        if(!curBlockD) {
            allocatedSize /= MULT_COEF;
            curBlockD = findBlock(allocatedSize);
        }
    }
    if(!curBlockD) return nullptr;
    if(curBlockD == lastDescr) {
        BlockDescriptor *newLastD = static_cast<BlockDescriptor*>(allocatedSize + static_cast<void*>(curBlockD) + sizeof(BlockDescriptor));
        newLastD->block_size = curBlockD->block_size - allocatedSize - sizeof(BlockDescriptor);
        newLastD->is_free = true;
        curBlockD->block_size = allocatedSize + sizeof(BlockDescriptor);
        lastDescr = newLastD;
    }
    curBlockD->is_free = false;
    curBlockD->requested = requestedSize;
    return static_cast<void*>(curBlockD) + sizeof(BlockDescriptor);
}

void *SmallAllocator::ReAlloc(void *Pointer, unsigned int Size) {
    BlockDescriptor* curD = static_cast<BlockDescriptor*>(Pointer - sizeof(BlockDescriptor));
    // trying to expand current block
    tryDefragmentate(curD);
    if(curD->block_size - sizeof(BlockDescriptor) >= Size) {
        curD->requested = Size;
        return static_cast<void*>(curD) + sizeof(BlockDescriptor);
    }
    BlockDescriptor* newD = static_cast<BlockDescriptor*>(Alloc(Size) - sizeof(BlockDescriptor));
    if(!newD && tryDefragmentate(reinterpret_cast<BlockDescriptor*>(&Memory))) return nullptr;
    if(!newD) newD = static_cast<BlockDescriptor*>(Alloc(Size) - sizeof(BlockDescriptor));
    if(!newD) return nullptr;
    // if memory founded
    newD->is_free = false;
    // copying data
    memcpy(static_cast<void*>(newD) + sizeof(BlockDescriptor),Pointer,curD->requested);
    curD->is_free = true;
    tryDefragmentate(curD);
    return static_cast<void*>(newD) + sizeof(BlockDescriptor);
}

void SmallAllocator::Free(void *Pointer) {
    BlockDescriptor *curD = static_cast<BlockDescriptor*>(Pointer - sizeof(BlockDescriptor));
    curD->is_free = true;
    tryDefragmentate(curD);
    tryDefragmentate(reinterpret_cast<BlockDescriptor*>(&Memory));
}

SmallAllocator::BlockDescriptor* SmallAllocator::findBlock(unsigned int requstedSize) {
    BlockDescriptor *curDescr = reinterpret_cast<BlockDescriptor*>(&Memory);
    while(curDescr <= lastDescr) { // searching block with size (Size*MULT_COEF)
        if(curDescr->is_free && curDescr->block_size >= requstedSize + 2*sizeof(BlockDescriptor)) return curDescr;
        curDescr = static_cast<BlockDescriptor*>(curDescr->block_size + static_cast<void*>(curDescr));
    }
    return nullptr;
}

bool SmallAllocator::tryDefragmentate(SmallAllocator::BlockDescriptor *start) {
    bool success = false;
    // trying to concatenate with next block
    BlockDescriptor *nextD = static_cast<BlockDescriptor*>(static_cast<void*>(start) + start->block_size);
    while(nextD <= lastDescr && nextD->is_free) {
        success = true;
        start->block_size += nextD->block_size;
        if(nextD == lastDescr) lastDescr = start;
        nextD = static_cast<BlockDescriptor*>(static_cast<void*>(nextD) + nextD->block_size);
    }
    return success;
}
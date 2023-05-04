#ifndef POWERPC_VIRTUAL_STORAGE_MODEL_H
#define POWERPC_VIRTUAL_STORAGE_MODEL_H

// VirtualAddressSpace
// must be larger than the EffectiveAddressSpace
//
// NOTE Harvard Style Cache Model
// NOTE CombinedCacheModel

typedef struct PpeMemoryEntity {
} PpeMemoryEntity;

typedef struct PpeSegmentLookasideBuffer {
} PpeSegmentLookasideBuffer;

typedef struct PpePageTable {
} PpePageTable;

typedef struct PpeTranslationLookasideBuffer {
} PpeTranslationLookasideBuffer;

// The cache management instructions allow programs to perform the following
// functions: Invalidate the copy of storage in an instruction cache block
// (icbi) Provide a hint that the program will probably soon access a specified
// data cache block (dcbt, dcbtst) Set the contents of a data cache block to
// zeros (dcbz) Copy the contents of a modified data cache block to main storage
// (dcbst) Copy the contents of a modified data cache block to main storage and
// make the copy of the block in the data cache invalid (dcbf)

const int *invalidate_cache_block_instruction();
const int *access_specified_data_cache_block(PpeSegmentLookasideBuffer *dcbt,
                                             PpeSegmentLookasideBuffer *dcbtst);
const int *set_data_cache_block_to_zero(PpeSegmentLookasideBuffer *dcbz);
const int *copy_modified_data_cache_block(PpeSegmentLookasideBuffer *dcbf);
const int *
invalidate_modified_data_cache_block(PpeSegmentLookasideBuffer *dcbf);

// NOTE functions to-do:
// Bring a range of effective addresses into the SL1 (sdcrt and sdcrtst)
// Write zeros to the contents of a range of effective addresses (sdcrz)
// Store the modified contents of a range of effective addresses (sdcrst)
// Store the modified contents of a range of effective addresses and invalidate
// the block (sdcrf)

#endif // POWERPC_VIRTUAL_STORAGE_MODEL_H

#pragma once

#define ONE_BLOCK_SIZE_BYTES    64
#define ONE_BLOCK_SIZE_UINTS    16
#define BLOCK_EXPEND_SIZE_UINTS 80

#define SHA1_HASH_LENGTH_BYTES  20
#define SHA1_HASH_LENGTH_UINTS  5

typedef unsigned int uint;
typedef uint* Block;
typedef uint ExpendBlock[BLOCK_EXPEND_SIZE_UINTS];

const uint H[5] = 
{
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476,
    0xC3D2E1F0
};

uint* sha1(char* message, uint msize_bytes);

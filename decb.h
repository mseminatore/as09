#ifndef __DECB_H
#define __DECB_H

#include <stdint.h>

#if defined(_WIN32) || defined(__GNUC__)
#   define BYTE_SWAP(data) (((data) >> 8) & 0x00FF) | (((data) << 8) & 0xFF00)

#ifndef ntohs
#   define ntohs(s) BYTE_SWAP(s)
#endif

#ifndef htons
#   define htons(s) BYTE_SWAP(s)
#endif

#endif

//
#pragma pack(push, 1)
typedef struct
{
    uint8_t zeros;
    uint16_t length;
    uint16_t start;
} BinFileHeader;

//
typedef struct
{
    uint8_t ones;
    uint16_t zeros;
    uint16_t exec;
} BinFileTail;
#pragma pack(pop)

#endif  // __DECB_H


#ifndef LABA1_2SEM_RINGINFO_H
#define LABA1_2SEM_RINGINFO_H
#include <stddef.h>
#include "my_int.h"
#include "my_complex.h"

typedef struct RingInfo{
    void * (*define)(void *);
    void * (*input)();
    void * (*copy)(void *);
    void  (*output)(void *);
    int  (*compare)(void *, void *);
    void * (*sum)(void *, void *);
    void * (*multi)(void *, void *);
    void * (*subtract)(void *, void *);
    void (*free_struct)(void *);
    size_t size;
}RingInfo;


struct RingInfo* CreateRing(void * (*define)(void *),
                            void * (*input)(),
                            void * (*copy)(void *),
                            void  (*output)(void *),
                            int  (*compare)(void *, void *),
                            void * (*sum)(void *, void *),
                            void * (*multi)(void *, void *),
                            void *(*subtract)(void *, void *),
                            void (*free_struct)(void *),
                            size_t size);


void free_ring(RingInfo *ring);

#endif //LABA1_2SEM_RINGINFO_H

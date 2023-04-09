#include "types.h"
#include "param.h"

// MLFQ scheduler context
struct mlfq
{
    uint quantum[NPROC];
    struct proc *queue[NMLFQ][NPROC]; // proc의 주소값 저장하는 mlfq

    struct proc **iterstate[NMLFQ]; // 보류
};

enum mlfqstate
{
    MLFQ_SUCCESS = 0,
    MLFQ_FULL_QUEUE = 1,
    MLFQ_NEXT = 2,
    MLFQ_KEEP = 3,
};
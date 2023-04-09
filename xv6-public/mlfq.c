#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"
#include "mlfq.h"

// Initialize MLFQ scheduler

void mlfq_init(struct mlfq *this)
{
    struct proc **iter = &this->queue[0][0];

    static const uint quantum[] = {4, 6, 8};

    for (int i = 0; i < NMLFQ; i++)
    {
        this->quantum[i] = quantum[i]; // time quantum 담음
        for (int j = 0; j < NMLFQ; j++, iter++)
        {
            *iter = 0; // 완전 초기화
        }
        this->iterstate[i] = this->queue[i]; // 보류
    }
}

// Add process to MLFQ scheduler
int mlfq_add(struct mlfq *this, struct proc *p, int level)
{
    struct proc **iter;

    for (iter = this->queue[level]; iter != &this->queue[level][NPROC]; iter++)
    {
        if (*iter == 0)
            goto found;
    }

    return MLFQ_FULL_QUEUE;

found:
    *iter = p;

    p->mlfq.level = level;
    p->mlfq.index = iter - this->queue[level];

    return MLFQ_SUCCESS;
}

void mlfq_delte(struct mlfq *this, struct proc *p)
{
    this->queue[p->mlfq.level][p->mlfq.index] = 0;
}

void mlfq_scheduler(struct mlfq *this, struct spinlock *lock)
{
    int keep, idx;

    struct proc *p = 0;
    struct cpu *c = mycpu();
    c->proc = 0;

    idx = 0;
    keep = MLFQ_NEXT;

    for (;;)
    {
        // Enable interrupts on this processor.
        sti();

        acquire(lock);
    }
}
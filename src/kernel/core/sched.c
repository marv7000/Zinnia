#include <zinnia/status.h>
#include <kernel/mem.h>
#include <kernel/percpu.h>
#include <kernel/print.h>
#include <kernel/sched.h>
#include <bits/irq.h>
#include <stdatomic.h>

static void idle_func(void* arg) {
    while (1) {
        irq_wait();
    }
}

void sched_init() {
    struct sched_percpu* sched = &percpu_get()->sched;

    struct task* idle_task;
    task_create(idle_func, nullptr, &idle_task);

    sched->current = idle_task;
    sched->idle_task = idle_task;

    kprintf("Scheduler initialized\n");
}

void sched_reschedule(struct sched_percpu* sched) {
    kprintf("Rescheduling!\n");
}

void sched_yield(struct sched_percpu* sched) {
    kprintf("Rescheduling!\n");
}

zn_status_t task_create(task_fn_t entry, void* arg, struct task** out) {
    if (!out)
        return ZN_ERR_INVALID;

    struct task* new_task = mem_alloc(sizeof(struct task), 0);
    if (!new_task)
        return ZN_ERR_NO_MEMORY;

    static size_t last_tid = 0;
    new_task->id = atomic_fetch_add(&last_tid, 1);

    *out = new_task;
    return ZN_OK;
}

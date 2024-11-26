#ifndef CXT_SWITCH_H
#define CXT_SWITCH_H

#include <stdint.h>

typedef struct Task {
	const char* name;
	uint64_t* stack;
	uint64_t* context;
	void (*entry_point)(void);
} Task;

typedef struct TaskManager {
	Task* tasks[1024];
    int current_task_id;
	int task_count;
} TaskManager;

void sys_taskmgr(Task* manager);
void sys_taskcreate(TaskManager* manager, const char* name, void (*entry_point)(void));
void sys_taskswitch(TaskManager* manager);
void sys_inittaskcontext(Task* task);
void sys_resume(Task* task);

#endif

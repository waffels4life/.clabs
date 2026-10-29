#include <stdio.h>

// +---------------------------+
// |          Stack            |  Local variables, function calls
// +---------------------------+
// |            ↓              |
// |                           |
// |            ↑              |
// +---------------------------+
// |           Heap            |  Dynamic memory (malloc)
// +---------------------------+
// |      Data Segment         |  Global and static variables
// +---------------------------+
// |      Text / Code Segment  |  Program instructions
// +---------------------------+

// Represents the possible states of a process.
typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

//       +-------+
//       | READY |
//       +-------+
//           |
//           | CPU assigned
//           v
//       +---------+
// +---->| RUNNING |----+
// |     +---------+    |
// |         |          |
// |         | Waiting  | Finished
// |         v          v
// |     +---------+  +------------+
// |     | WAITING |  | TERMINATED |
// |     +---------+  +------------+
// |         |
// +---------+
//   Event completed

// Represents a simplified Process Control Block (PCB).
typedef struct {
    int pid;                 // Process ID
    ProcessState state;      // Current process state
    unsigned int program_counter;
    int priority;            // Scheduling priority
} Process;

// Converts a process state into a readable string.
const char *get_state_name(ProcessState state) {
    switch (state) {
        case READY:      return "READY";
        case RUNNING:    return "RUNNING";
        case WAITING:    return "WAITING";
        case TERMINATED: return "TERMINATED";
        default:         return "UNKNOWN";
    }
}

// Displays the process information.
void print_process(const Process *process) {
    printf("PID: %d\n", process->pid);
    printf("State: %s\n", get_state_name(process->state));
    printf("Program Counter: %u\n", process->program_counter);
    printf("Priority: %d\n", process->priority);
    printf("------------------------\n");
}

int demonstrate_process(void) {
    // Create a process with initial values.
    Process process = {
        .pid = 1001,
        .state = READY,
        .program_counter = 0,
        .priority = 5
    };

    // The process is ready to execute.
    print_process(&process);

    // The scheduler gives the process CPU time.
    process.state = RUNNING;
    process.program_counter++;
    print_process(&process);

    // The process finishes its execution.
    process.state = TERMINATED;
    print_process(&process);

    return 0;
}

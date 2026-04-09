#include <stdio.h>
#include <stdlib.h>

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define GREY "\033[0;37m"

int *processes;
int n;
int coordinator;

// Function to display processes
void displayProcesses() {
    printf("\nActive Processes:\n");
    for (int i = 0; i < n; i++) {
        if (processes[i] == 1)
            printf("Process %d (Alive)\n", i + 1);
        else
            printf(RED "Process %d (Dead)\n" RESET, i + 1);
    }
    printf(GREEN "\nCurrent Coordinator: Process %d\n" RESET, coordinator);
}

// Election function
void election(int initiator) {
    printf(YELLOW "\nProcess %d -> Initiating Election...\n" RESET, initiator);

    int newCoordinator = initiator;

    for (int i = initiator; i < n; i++) {
        if (processes[i] == 1) {
            printf(YELLOW "Process %d -> sends ELECTION to Process %d\n" RESET, initiator, i + 1);
            printf(GREY "[INTERNAL] Process %d responds OK to Process %d\n" RESET, i + 1, initiator);
            newCoordinator = i + 1;
        }
    }

    coordinator = newCoordinator;

    printf(GREEN "\nProcess %d becomes NEW COORDINATOR\n" RESET, coordinator);

    // Inform all
    for (int i = 0; i < n; i++) {
        if (processes[i] == 1 && (i + 1) != coordinator) {
            printf(GREY "[INTERNAL] Coordinator %d informs Process %d\n" RESET, coordinator, i + 1);
        }
    }
}

// Simulate failure
void failProcess() {
    int pid;
    printf("\nEnter process ID to fail: ");
    scanf("%d", &pid);

    if (pid < 1 || pid > n) {
        printf(RED "Invalid Process ID!\n" RESET);
        return;
    }

    processes[pid - 1] = 0;

    printf(RED "\nProcess %d has FAILED!\n" RESET, pid);

    if (pid == coordinator) {
        printf(YELLOW "\nCoordinator failed! Starting election...\n" RESET);

        // Find lowest alive process to start election
        for (int i = 0; i < n; i++) {
            if (processes[i] == 1) {
                election(i + 1);
                break;
            }
        }
    } else {
        printf(GREY "[INTERNAL] Coordinator still alive. No election needed.\n" RESET);
    }
}

// Start election manually
void startElection() {
    int initiator;

    printf("\nEnter process ID to start election: ");
    scanf("%d", &initiator);

    if (initiator < 1 || initiator > n || processes[initiator - 1] == 0) {
        printf(RED "Invalid or Dead Process!\n" RESET);
        return;
    }

    election(initiator);
}

int main() {
    int choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    processes = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        processes[i] = 1;
    }

    coordinator = n; // highest ID initially

    printf(GREEN "\nInitial Coordinator is Process %d\n" RESET, coordinator);

    while (1) {
        displayProcesses();

        printf("\nMenu:\n");
        printf("1. Fail Process\n");
        printf("2. Start Election\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                failProcess();
                break;

            case 2:
                startElection();
                break;

            case 3:
                printf(GREEN "\nExiting...\n" RESET);
                free(processes);
                exit(0);

            default:
                printf(RED "Invalid choice!\n" RESET);
        }
    }

    return 0;
}
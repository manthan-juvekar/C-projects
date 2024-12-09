#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BAR_LENGTH 20
#define TOTAL_TASKS 10

typedef struct {
  int taskId;
  int completion;
  int incrementRate;
} ProgressTask;

void display_progress(const ProgressTask *task);
void clear_console();

int main() {
  ProgressTask taskList[TOTAL_TASKS];
  srand((unsigned)time(NULL));

  // Initialize tasks
  for (int i = 0; i < TOTAL_TASKS; i++) {
    taskList[i].taskId = i + 1;
    taskList[i].completion = 0;
    taskList[i].incrementRate = rand() % 5 + 1; // Random progress rate between 1 and 5
  }

  int allTasksDone = 0;
  while (!allTasksDone) {
    allTasksDone = 1;
    clear_console();

    for (int i = 0; i < TOTAL_TASKS; i++) {
      taskList[i].completion += taskList[i].incrementRate;

      if (taskList[i].completion >= 100) {
        taskList[i].completion = 100; // Cap progress at 100%
      } else {
        allTasksDone = 0; // If any task is incomplete, continue the loop
      }

      display_progress(&taskList[i]);
    }

    usleep(500000); // Sleep for 500 milliseconds (0.5 seconds)
  }

  printf("All tasks are complete!\n");
  return 0;
}

void clear_console() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void display_progress(const ProgressTask *task) {
  int completedBars = (task->completion * BAR_LENGTH) / 100;

  printf("Task %d: [", task->taskId);
  for (int i = 0; i < BAR_LENGTH; i++) {
    if (i < completedBars) {
      printf("#");
    } else {
      printf(" ");
    }
  }
  printf("] %d%%\n", task->completion);
}

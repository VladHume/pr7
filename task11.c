#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef enum { RUNNING, PAUSED, CANCELED, DONE } state_t;

typedef struct {
    int id;
    state_t state;
} Job;

int main(void) {
    Job jobs[MAX];
    for (int i = 0; i < MAX; i++) {
        jobs[i].id = i + 1;
        jobs[i].state = RUNNING;
    }

    char cmd;
    int jid;
    while (1) {
        printf("\nНаявні задачі:\n");
        for (int i = 0; i < MAX; i++) {
            printf("Job %d: ", jobs[i].id);
            switch (jobs[i].state) {
                case RUNNING: printf("RUNNING\n"); break;
                case PAUSED:  printf("PAUSED\n"); break;
                case CANCELED:printf("CANCELED\n"); break;
                case DONE:    printf("DONE\n"); break;
            }
        }

        printf("\nКоманди: p ID(паузa), r ID(відновити), c ID(відмінити), q(вихід)\n> ");
        if (!(scanf(" %c", &cmd))) break;
        if (cmd == 'q') break;
        scanf("%d", &jid);
        if (jid < 1 || jid > MAX) continue;
        Job *j = &jobs[jid-1];

        switch (cmd) {
            case 'p': if (j->state == RUNNING) j->state = PAUSED; break;
            case 'r': if (j->state == PAUSED) j->state = RUNNING; break;
            case 'c': if (j->state == RUNNING || j->state == PAUSED) j->state = CANCELED; break;
        }
    }

    return EXIT_SUCCESS;
}

#include <iostream>
#include "stdio.h"
#include <cstring>
#include "assert.h"

#define MAXTEAMS 1024
#define MAXTEAMSIZE 1024
#define MAXELEMENTS 1000000

FILE *input;
int kase = 0;
int numteams;
int team[MAXELEMENTS];
int teampos[MAXTEAMS];
int teamsize[MAXTEAMS];
int queue[MAXTEAMS][MAXTEAMSIZE];
int queuehead[MAXTEAMS];
int queuetail[MAXTEAMS];
int head, tail;
int read_case() 
{
    int i, j, n, elem;

    fscanf(input, "%d", &numteams);
    if (numteams==0) return 0;
    for (int i = 0; i < numteams; i++)
    {
        fscanf(input, "%d", &n);
        for (int j = 0; j < n; j++)
        {
            fscanf(input, "%d", &elem);
            team[elem] = i;
        }
    }
    return 1;
}

void enqueue (int element)
{
    int t, pos;
    t = team[element];
    if (teamsize[t]==0)
    {
        queue[tail][0] = element;
        queuehead[tail] = 0;
        queuetail[tail] = 1;
        teampos[t] = tail;
        teamsize[t] = 1;
        tail = (tail + 1) % MAXTEAMS;
    }
    else
    {
        pos = teampos[t];
        queue[pos][queuetail[pos]] = element;
        queuetail[pos] = (queuetail[pos] + 1) % MAXTEAMSIZE;
        teamsize[t]++;
    }
}

int dequeue() {
    int element = queue[head][queuehead[head]];
    int t = team[element];
    queuehead[head] = (queuehead[head] + 1) % MAXTEAMSIZE;
    teamsize[t]--;
    if (teamsize[t] == 0)
        head = (head + 1) % MAXTEAMS;
    return element;
}

void solve_case() {
    char cmd[30];
    int element, t;
    printf("Scenario #%d\n", ++kase);
    head = tail = 0;
    for (t = 0; t < numteams; t++)
        teamsize[t] = 0;
    while (1)
    {
        fscanf(input, "%s", cmd);
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            fscanf(input, "%d", &element);
            enqueue(element);
        }
        else if (strcmp(cmd, "DEQUEUE") == 0)
        {
            printf("%d\n", dequeue());
        }
        else if (strcmp(cmd, "STOP") == 0)
        {
            printf("\n");
            return;
        }
    }
}

int main()
{
    input = fopen("input.txt", "r");
    while (read_case()) solve_case();
    fclose(input);
    return 0;
}
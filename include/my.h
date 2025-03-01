/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h BOOTCAMP
*/


#ifndef MY_H_
    #define MY_H_

typedef struct node_s {
    char *command;
    char *value;
    int id;
    struct node_s *next;
} node_t;

typedef struct champion_s {
    char *name;
    char *comment;
    struct node *next;
} champion_t;

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <unistd.h>
    #include <signal.h>
    #include <stdint.h>
    #include <fcntl.h>
    #include <sys/wait.h>
    #include <limits.h>

int main(int argc, char **argv);
champion_t *parse_file(char *filename);
int error_handling(int argc, char **argv);
int error_champion_handling(FILE *file, champion_t *champion);
champion_t *create_champions(char *filename);
#endif /* !MY_H_ */

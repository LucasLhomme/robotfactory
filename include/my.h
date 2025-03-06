/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h BOOTCAMP
*/
#include <stdint.h>
#include <stdio.h>
#ifndef MY_H_
    #define MY_H_

/*Struct*/
typedef struct command_s {
    char *command;
    int (*command_name)(char *command, char *argument);
} command_t;

typedef struct node_s {
    char *command;
    char *value;
    int id;
    struct node_s *next;
} node_t;

typedef struct champion_s {
    char *name;
    char *comment;
    uint32_t prog_size;
    struct node *next;
} champion_t;

/*Function*/
int main(int argc, char **argv);
champion_t *parse_file(char *filename);
int error_handling(int argc, char **argv);
int error_name_handling(char **tab);
int error_champion_handling(FILE *file, champion_t *champion);
champion_t *create_champions(char *filename);
void add_command(node_t **head, char *command, char *value, int id);
char *get_comment(FILE *file);
char *my_get_name(FILE *file);
void get_command_list(FILE *file, champion_t *champion);
int create_cor(champion_t *champ);
int write_header(FILE *new_file, champion_t *champ);
int write_instruction_code(FILE *new_file, uint8_t instruction_code);
int write_coding_byte(FILE *new_file, int param1_type,
    int param2_type, int param3_type);
int write_parameters(FILE *new_file, char *param1,
    char *param2, char *param3);
uint8_t create_coding_byte(int param1_type, int param2_type, int param3_type);
uint32_t my_revbyte_32(uint32_t value);
/*Parameters*/
int command_live(char *command, char *argument);
int command_ld(char *command, char *argument);
int command_st(char *command, char *argument);
int command_add(char *command, char *argument);
int command_sub(char *command, char *argument);
int command_and(char *command, char *argument);
int command_or(char *command, char *argument);
int command_xor(char *command, char *argument);
int command_zjmp(char *command, char *argument);
int command_ldi(char *command, char *argument);
int command_sti(char *command, char *argument);
int command_fork(char *command, char *argument);
int command_lld(char *command, char *argument);
int command_lldi(char *command, char *argument);
int command_lfork(char *command, char *argument);
int command_aff(char *command, char *argument);
int error_name_handling(char **tab);
#endif /* !MY_H_ */

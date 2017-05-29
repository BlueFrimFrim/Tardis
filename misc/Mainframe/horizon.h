#ifndef HORIZON_H
#define HORIZON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------------------------------
// Constants.
#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

//--------------------------------------------------------------------------
// Data types.

//-------------------------------------------------------------------------
// Variables.

//-------------------------------------------------------------------------
// Function prototypes.

/* horizon_automata.c */
int lsh_cd(char **args);
int lsh_num_builtins();
int lsh_exit(char **args);
int lsh_launch(char **args);
int lsh_execute(char **args);
void lsh_loop(void);

char *lsh_read_line(void);
char **lsh_split_line(char *line);

/* tardis.c */
int lsh_tardis(char **args);
void bitWrite(void);

/* automata.c */
int lsh_automataHelp(char **args);

#endif

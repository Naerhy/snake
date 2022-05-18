#ifndef LIBNY_H

#define LIBNY_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

typedef struct s_ny_list
{
	void* content;
	struct s_ny_list* next;
} t_ny_list;

// ny_free.c:
void ny_free_double_ptr(void** ptr);

// ny_get_next_line:
char *ny_get_next_line(int fd, int *error_status);

// ny_list.c:
t_ny_list* ny_list_new(void* content);
void ny_list_prepend(t_ny_list** list, t_ny_list* new);
void ny_list_append(t_ny_list** list, t_ny_list* new);
void ny_list_delete(t_ny_list* node, void (*delete)(void*));
void ny_list_clear(t_ny_list* list, void (*delete)(void*));
t_ny_list* ny_list_nth(t_ny_list* list, int position);
t_ny_list* ny_list_last(t_ny_list* list);
int ny_list_size(t_ny_list* list);

// ny_number.c;
long ny_atoi(char const* str);
char* ny_itoa(long nb);

// ny_output.c:
void ny_wrstr(int fd, char const* str);
void ny_wrstr_nl(int fd, char const* str);

// ny_split.c:
char** ny_split(char const* str, char delimiter);

// ny_string.c:
char* ny_strcat(char* dest, char const* src, int length);
char* ny_strcpy(char* dest, char const* src, int length);
int ny_strlen(char const* str);
char* ny_strdup(char const* src, int length);
char* ny_strjoin(char const* str1, char const* str2);
char* ny_strjoin_var(int nb_str, ...);

#endif

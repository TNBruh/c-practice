#ifndef MAIN_H
#define MAIN_H

typedef struct {
    FILE *p_file;
    int line_count;
    int wpl_count;
} FileMap;
FileMap read_input(char* file_name);
char **read_lines(FileMap *p_filemap);

#endif

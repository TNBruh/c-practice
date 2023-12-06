#ifndef MAIN_H
#define MAIN_H

struct FileMap read_input(char* file_name);
struct FileMap {
    FILE *p_file;
    int line_count;
    int wpl_count;
};
char **read_lines(struct FileMap *p_filemap);

#endif

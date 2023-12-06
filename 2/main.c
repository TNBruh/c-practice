// std
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// amogus
#include "main.h"

typedef struct FileMap FileMap;

// start
void main() {
    FileMap file_map = read_input("test.txt");

    printf("%d\n", file_map.line_count);
    printf("%d\n", file_map.wpl_count);

    char **lines = read_lines(&file_map);
    fclose(file_map.p_file);
}


FileMap read_input(char* file_name) {
    FILE *p_file = fopen(file_name, "r");
    if (NULL == p_file) { exit(1); }

    int line_count = 0;
    int word_count = 0;
    while (1) {
        int c = fgetc(p_file);

        if (line_count == 0) {
            word_count++;
        }

        if (c == '\n') {
            line_count++;
        } else if (c == EOF) {
            line_count++; break;
        }
    }

    FileMap file_map;
    file_map.p_file = p_file;
    file_map.line_count = line_count;
    file_map.wpl_count = word_count + 1; //now includes \0
    fseek(file_map.p_file, 0, SEEK_SET);

    return file_map;
}


char **read_lines(FileMap *p_filemap) {
    char **lines = malloc(sizeof(char*) * p_filemap->line_count);
    for (int i = 0; i < p_filemap->line_count; i++) { //iter over line
        //read
        char *line = malloc(sizeof(char) * (p_filemap->wpl_count));
        char *amogus = fgets(line, p_filemap->wpl_count, p_filemap->p_file); //automatically includes \0

        //write
        *(lines + i * sizeof(char*)) = line;
        // printf("%d %s", strlen(*(lines + i * sizeof(char*))), *(lines + i * sizeof(char*)));
    }

    return lines;
}
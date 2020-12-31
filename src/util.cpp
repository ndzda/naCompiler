#ifndef NDCUTIL
#define NDCUTIL

#include <cstdio>
#include <cstdlib>

void inline info(const char *s)
{
    printf("info: %s\n", s);
}

void inline debug(const char *s)
{
    printf("debug: %s\n", s);
}

void inline error(const char *s)
{
    printf("error: %s\n", s);
}

long readBFile(const char *path, unsigned char **s)
{
    FILE *file;

    if (fopen_s(&file, path, "r"))
        return -1;

    fseek(file, 0, SEEK_END);

    long fileSize = ftell(file);
    *s = (unsigned char *)malloc(fileSize + 1);

    rewind(file);

    fread(*s, sizeof(char), fileSize, file);

    *((*s) + fileSize) = 0;

    if (fclose(file) == 0)
        return fileSize;
    else
        return -1L;
}

#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char));
        content = strcat(content, buffer);
    }

    return content;
}

int main()
{
    FILE * fp = fopen("exercice4.txt", "r");
    char * file_content;
    user hugues;
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);
    sscanf(file_content, "Prénom : %ms\nNom : %ms\nAge: %d ans", &hugues.first_name, &hugues.last_name, &hugues.age);
    printf("First Name: %s\nLast Name: %s\nAge: %d\n", hugues.first_name, hugues.last_name, hugues.age);

    free(file_content);
    free(hugues.first_name);
    free(hugues.last_name);
    fclose(fp);
    exit(0);
}
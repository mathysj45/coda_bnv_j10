#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    FILE *fp = fopen("exercice2.txt", "w+");
    char * file_content;
    char change[] = "Frêre Jacques, frêre Jacques,\n dormez vous ?, dormez vous ?";

    if (fp == NULL)
    {
        printf("Le fichier exercice2.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);
    
    fprintf(fp, "%s\n", change);
    printf("%s", file_content);

    fclose(fp);
    return 0;
}
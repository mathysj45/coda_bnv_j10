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

int count_lines(char *str)
{
    int i = 0;
    int lines = 0;

    while(str[i] != '\0')
    {
        if(str[i] == '\n')
        {
            lines++;
        }

        i++;
    }

    return lines + 1;
}

void display_tab(char **tab)
{
    int i = 0;

    while(tab[i] != NULL)
    {
        printf("%s\n", tab[i]);
        i++;
    }
}

int main()
{
    //1. Ouvrir le fichier
    FILE *fp = fopen("exercice3.txt", "r");
    char * file_content;
    char **tab;
    int lines;
    char * line;
    int i = 0;

    if (fp == NULL)
    {
        printf("Le fichier exercice3.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    //2. Récupérer le contenu du fichier dans un `char *`
    file_content = get_file(fp);

    //3. Compter le nombre de lignes du fichier
    lines = count_lines(file_content);

    //4. Allouer la mémoire pour le double tableau `char **` et ses lignes
    tab = malloc((lines + 1) * sizeof(*tab)); // <= le double tableau
    tab[lines] = NULL;

    line = strtok(file_content, "\n");
    while(line != NULL)
    {
        tab[i] = malloc((strlen(line) + 1) * sizeof(char)); // <= chacune des lignes

        //5. Remplir le double tableau avec le contenu du fichier
        tab[i] = strcpy(tab[i], line);

        i++;
        line = strtok(NULL, "\n");
    }

    //6. Afficher le double tableau
    display_tab(tab);

    //7. Libérer la mémoire allouée
    i = 0;
    while(i < lines)
    {
        free(tab[i]);
        i++;
    }
    free(tab);

    //8. Fermer le fichier
    fclose(fp);
    return 0;
}
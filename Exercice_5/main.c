#include <stdlib.h>
#include <stdio.h>

int main()
{
    char **tab = malloc(3 * sizeof(*tab));
	int i = 0;
	tab[0] = "Goodnight\n";
	tab[1] = "And thanks !\n";
	tab[2] = "For all the fish!\n";

	FILE *fp = fopen("exercice5.txt", "w+");

    if (fp == NULL)
    {
        printf("Le fichier exercice5.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    while(i < 3)
    {
    	fprintf(fp, "%s", tab[i]);
    	i++;
    }

    fclose(fp);
    return 0;
}

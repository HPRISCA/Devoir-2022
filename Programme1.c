#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Format : %s <parameter1><parameter2>\n", argv[0]);
        return 1;
    }
    FILE *fich1, *fich2;
    int ret;
    fich1 = fopen(argv[1], "r");
    if (fich1 == NULL)
    {
        printf("Error, can't open %s\n", argv[1]);
        exit(1);
    }

    fich2 = fopen(argv[2], "w");
    if (fich2 == NULL)
    {
        fclose(fich1);
        printf("Error, can't open %s\n", argv[2]);
        exit(2);
    }
    else
    {
        int fiche_char = 0;
        while (1)
        {
            fiche_char = fgetc(fich1);
            fputc(fiche_char, fich2);
            // printf("%c", fiche_char);
            if (fiche_char == EOF)
                break;
        }
    }
    printf("La copie reussie.\n");

    fclose(fich1);
    fclose(fich2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "md5.h"
#include <string.h>

int main(int argc, char *argv[])
{


char data1[512];
char data2[512];
char buf[1024];
unsigned char *md5_1=NULL;
unsigned char *md5_2=NULL;
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

    fclose(fich1);
    fclose(fich2);

md5_1= MD5File(argv[1], data1);
md5_2= MD5File(argv[2], data2);
if (strcmp(md5_1, md5_2)==0) {
    fprintf(stderr, "La copie reussie\n");

  } else {
    fprintf(stderr, "%s: different de  %s\n", md5_1, md5_2);

  }

    return 0;
}

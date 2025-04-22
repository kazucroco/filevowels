#include <stdio.h>
#include <ctype.h>

int main(int argc, char ** argv)
{
    if(argc < 2)
    {
        puts("no file");
        return -1;
    }

    FILE * file = fopen(argv[1], "r");
    FILE * outfile = fopen("outfile.txt", "w");
    char currentChar;

    while((currentChar = fgetc(file)) != EOF)
    {
        switch(toupper(currentChar))
        {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                printf("%c", currentChar);
                fputc(currentChar, outfile);
                break;
            default:
                break;
        }
    }
    fputc('\n', outfile);
    fclose(file);
    fclose(outfile);
    puts("");
}
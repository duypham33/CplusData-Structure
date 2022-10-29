#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
int i,j;
void delay()
{

    for(i=0; i<1000; i++)
        for(j=0; j<3000; j++)
        {}
}
void delay1()
{
    for(i=0; i<100000; i++)
        for(j=0; j<3000; j++)
        {}
}
void change()
{system("COLOR 9");

        delay1();
        system("COLOR C");
        delay1();
        system("COLOR 5");
        delay1();
        system("COLOR E");
        delay1();
}
int main(void)
{
    char *locale = setlocale(LC_ALL, "");
    FILE *in = fopen("Diwali.txt", "r");
    wint_t c;
    system("COLOR E");
    while ((c = fgetwc(in)) != WEOF)
        {   if(c!=' ')
            delay();

            putwchar(c);
        }
    fclose(in);
    while(1)
    {
        change();
    }
    getch();
}


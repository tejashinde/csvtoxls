#include<stdarg.h>
#include<stdio.h>

void customPRINT(char *,...); 				//Our printf function
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.


int main()
{
	customPRINT("%s%s%s","Tejas","Shinde","Love");

	return 0;
}


void customPRINT(char* format,...)
{
	char *traverse;
	unsigned int i;
	char *s;

	//Module 1: Initializing customPRINT's arguments
	va_list arg;
	va_start(arg, format);

	for(traverse = format; *traverse != '\0'; traverse++)
	{
		while( *traverse != '%' )
		{
			putchar(*traverse);
			traverse++;
		}

		traverse++;

		//Module 2: Fetching and executing arguments
		switch(*traverse)
		{
			case 'c' : i = va_arg(arg,int);		//Fetch char argument
						putchar(i);
						break;

			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						if(i<0)
						{
							i = -i;
							putchar('-');
						}
						puts(convert(i,10));
						break;

			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
						puts(convert(i,8));
						break;

			case 's': s = va_arg(arg,char *); //Fetch string
            // for (int i = 0; s[i] != '\0' ; ++i)
            // {
            //     putchar('-');
            // }
            // puts("\n");
						// puts("\n");
						puts("-------------------");
            puts("\t");
            puts(s);
						puts("-------------------");
            // putchar('|');
            // for (int i = 0; s[i] != '\0' ; ++i)
            // {
            //     putchar('-');
            // }
						break;

			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						puts(convert(i,16));
						break;
		}
	}

	//Module 3: Closing argument list to necessary clean-up
	va_end(arg);
}

char *convert(unsigned int num, int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);

	return(ptr);
}

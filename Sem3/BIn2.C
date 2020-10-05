#include<stdio.h>
#include<string.h>
int bin2dec(char *s)
{
	int r=0;
	for(;*s;r=(r<<1)|(*s++-'0'));
	return r;
}
 main()
{
	char bin[80];
	int dec;
	while(strcmp(bin,"0"))
	{
		printf("\n Enter a binary number (just 0 to EXIT): ");
		gets(bin);
		dec=bin2dec(bin);
		if(dec)
			printf("\nDecimal = %d Hexadecimal = 0x%04X Octal = 0%o\n",dec,dec,dec);
	}
}

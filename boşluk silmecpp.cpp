#include <stdio.h>
#define MAX 256

int main()
{
	char cumle[MAX];
	int j, k;
	printf("Bir cumle giriniz");
	gets(cumle);
	j=0;
	while(cumle[j] != '\0')
	{
		if(cumle [j]==32 && (cumle[j+1] == '\0' || j==0))
			for(k=j; cumle[k] != '\0'; k++)
				cumle[k] = cumle[k+1];
		else j++;		
	}
	printf("yeni cumle :\n");
	puts (cumle);
}

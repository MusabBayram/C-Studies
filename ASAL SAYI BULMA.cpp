#include <stdio.h>

main()
{
	int a, z;
scanf("%d", &a);
	for(int i=2; i<a; i++)
			{
				if(a%i==0)
				z++;
			}
			if(z==0)
				printf("asal");
			else 
				printf("asal degil");
			}

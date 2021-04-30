#include<stdio.h>
int bolenlertoplami(int sayi);
int mukemmelKontrol(int sayi);
int arkadasSayiGoruntule(int limit);


main()
{
	for(int i = 1; i<10000; i++)
	{
	if(mukemmelKontrol(i)==1)
		printf("%d\n", i)	
	}
	int sayi;
	bolenlertoplami(sayi);
	mukemmelKontrol(sayi);
	arkadasSayiGoruntule(10000);
	if (metindeAra())
}
int bolenlertoplami(int sayi)
{
	int toplam=0;
	printf("Bir sayi giriniz: ");
	scanf("%d", &sayi);
	for(int i=1; i<sayi; i++)
		if(sayi%i==0)
			toplam+=i;
	return toplam;

}

int mukemmelKontrol(int sayi)
{
	return bolenlertoplami(sayi) == sayi ? 1: 0;
}

void arkadasSayiGoruntule(int limit)
{
	printf("\n__Arkadas sayilar__\n");
	int b;
	
	for(int i=1; i<limit; i++)
	{
		b=bolenlerToplami(i)==j;
		/*for(int j=1; j<limit; j++)
		{
			if(b==j && bolenlerToplami(j)==i)
				printf("%d ve %d\n", i,j);
		}*/
		if(bolenlerToplami(b)==i)
			if(i>b)
				printf("%d ve %d\n0, i, j");
	}
}



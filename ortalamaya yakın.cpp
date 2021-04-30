#include <stdio.h>


main()
{
	int a[10]={2, 3, 5, 7, 8, 9, 34, 78, 79, 90};
	float ort=0.0;
	float toplam=0;
	float fark[10];
	for(int i=0; i<10; i++)
		toplam += a[i];
	ort = toplam/10;
	printf("ortalama :%5.2f", ort);
	for(int i=0; i<10; i++)
	{
		if(a[i]<ort)
			fark[i] = ort - a[i];
		else
			fark[i] = a[i] - ort;	
	}
	
	float kucuk=fark[0];
	for(int i=0; i<10; i++)
	{
		if(fark[i]>fark[i+1])
			kucuk=fark[i+1];
	}
	printf(" en kucuk fark :%3.1f", kucuk);		 
}


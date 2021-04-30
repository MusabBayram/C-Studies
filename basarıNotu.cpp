#include <stdio.h>

void giris(int no[], int notu[], int N);
float ortalama(int notu[], int N);
void goruntule(int no[], int notu[], int N);

main()
{

int N;
int OgrNo[BUFSIZ], BNotu[BUFSIZ];
float ort;

printf("Ogrenci sayisini giriniz: ");
scanf("%d", &N);

giris(OgrNo, BNotu, N);
ort = ortalama(BNotu, N);
goruntule(OgrNo, BNotu, N);


printf("Not ortalamasi: %5.2f\n", ort);

}

void giris(int no[], int notu[], int N)
{
int i;
for (i=0; i<N; i++)
{
 printf("Ogrenci no gir: ");
scanf("%d", &no[i]);
printf("%d numarali ogrencinin notunu gir : ", no[i]);
scanf("%d", &notu[i]);
}
}


void goruntule(int no[], int notu[], int N)
{
	int ek;
printf("Ogrenci#\tNotu\n");
for (int i=0; i<N; i++)
{
	int j;
	j=i+1;
	if(notu[i]<notu[j])
	{
		ek=notu[i];
}
}
printf("\n%8d en kucuk not\n", ek);
}
float ortalama(int notu[], int N)
{

float t;
int i;
t = 0;

for (i=0; i<N; i++)
t = t + notu[i];
float ort = t / N;

return ort;
}







#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>


int enbuyuk(int pul_1, int pul_2, int pul_3);
int enkucuk(int pul_1, int pul_2, int pul_3);
int ortanca(int pul_1, int pul_2, int pul_3);
main()
{
	//tan�mlama k�sm�
	int pul_1, pul_2, pul_3, z=0, Kural_1, toplam, Kural_2, Kural_3;
	char a;
	
	//Kullan�c� i�in a��klay�c� anlat�m
	printf("Oyunun Kurallari:\n");
	printf("Oyunda 3 pul cekeceksiniz\n");
	printf("Kural 1: Cekilen pullarin toplami 150'den kucuk ise kazanirsiniz.\n");
	printf("Kural 2: Cekilen pullarin toplami asal sayi ise kazanirsiniz.\n");
	printf("Kural 3: En buyuk degerli pul ile en kucuk degerli pul arasindaki fark ortanca degerli puldan buyuk ise kazanirsiniz.\n");	
	getch();
	
	//Kullan�c� tekrar oynamak istedi�inde program�n cal�smas�n� sa�layan do while d�ng�s�
	do
	{
	//Rastgele pullar� bilgisayara tutturma
	//ilk pulu tutturuyorum once bilgisayara
	srand(time(NULL));
	pul_1=1+rand()%99;
	//sonra 2. pulu tutturuyorum 
	do
	{
		pul_2=1+rand()%99; //hocam bu k�s�mda srand(time(NULL)) kullanmad�m bilerek kullan�nca pul_1 ve pul_2 aras�nda 3 say� farkla al�yordu...
	}
	//2. pulun 1. pul ile birbirine e�it olmad���ndan emin olmak i�in..
	while(pul_1==pul_2);
	do
	{
		pul_3=1+rand()%99;  //hocam bu k�s�mda srand(time(NULL)) kullanmad�m bilerek kullan�nca pul_1 ve pul_2 aras�nda 3 say� farkla al�yordu...
	}
	//3. pulun 1. ve 2. pullara e�it olmad���ndan emin olmak i�in..
	while(pul_1==pul_3 && pul_2==pul_3);
	
	//Bilgisayardan rastgele ald���m�z pullar� yazd�rma
	printf("\n1.pul = %2d\n", pul_1);
	printf("2.pul = %2d\n", pul_2);
	printf("3.pul = %2d\n", pul_3);
	
	//Pull toplam�n� bulma
	toplam= pul_1+pul_2+pul_3;
	
	//Toplam�n asall�g�na g�re z ye de�er atama
	for(int i=2; i<toplam; i++)
		{
			if(toplam%i==0)
				z++;
		}
	//Kurallar� kontrol etme ve yazd�rma
	if(toplam<150)
	{
		printf("Tebrikler kazandiniz... :) (1. Kural)");
	}
	else if(z==0)
	{
			printf("Tebrikler kazandiniz... :) (2. Kural)");
	}
	else if(enbuyuk(pul_1,pul_2,pul_3)-enkucuk(pul_1,pul_2,pul_3)>ortanca(pul_1,pul_2,pul_3))
	{
			printf("Tebrikler kazandiniz... :) (3. Kural)");		
	}
	else
			printf("Uzgunum kaybettiniz... :(");

	printf("\nTekrar oynamak icin [e/E] ==> ");
	a=getche();
	printf("\n");
}
	while(a=='e' || a=='E');	//E�er kullan�c� e veya E komutu verirse tekrar d�nd�r�r

} 

//En b�y�k pulu bulma fonksiyonu
int enbuyuk(int pul_1, int pul_2, int pul_3)
{
	int eb=0;
	if(pul_1>pul_2 && pul_1>pul_3)
	eb=pul_1;
	
	else if(pul_2>pul_1 && pul_2>pul_3)
	eb=pul_2;
	
	else
	eb=pul_3;
	
	return eb;
}

//En k���k pulu bulma fonksiyonu
int enkucuk(int pul_1, int pul_2, int pul_3)
{
	int ek=0;
	if(pul_1<pul_2 && pul_1<pul_3)
	ek=pul_1;
	
	else if(pul_2<pul_1 && pul_2<pul_3)
	ek=pul_2;
	
	else
	ek=pul_3;
	
	return ek;
}

//Ortanca pulu bulma fonksiyonu
int ortanca(int pul_1, int pul_2, int pul_3)
{
	int ort=0;
	if(pul_1<pul_2 && pul_1>pul_3)
	ort=pul_1;
	
	else if(pul_1<pul_3 && pul_1>pul_2)
	ort=pul_1;
	
	else if(pul_2<pul_1 && pul_2>pul_3)
	ort=pul_2;
	
	else if(pul_2<pul_3 && pul_2>pul_1)
	ort=pul_2;
	
	else
	ort=pul_3;
	
	return ort;
}

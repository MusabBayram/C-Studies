#include <stdio.h>
#include <time.h>

main()
{
	int sayi, adim, a;
	printf("hos geldiniz.. Oyuna baslamak icin herhangi bir tusa basiniz:");
	getche();
	printf("Bakalim tuttugum sayiyi kac adimda bulucaksin..");
	
	strand(time(NULL));
	sayi=1+rand()%99;
	
	do
	{
	printf("bir tahminde bulununuz...");
	scanf("%d", &a);
	}
	while(a==sayi)
	printf("tebrikler")
}

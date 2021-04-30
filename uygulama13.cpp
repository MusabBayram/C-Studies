#include <stdio.h>
int kuvvet(int, int); /* fonksiyon ön bildirimi */
main()
{ int t, u;
printf("Taban sayiyi giriniz: ");
scanf("%d", &t);
printf("Us degeri giriniz: ");
scanf("%d", &u);
printf("Sonuc: %d\n", kuvvet(t, u));
}
int kuvvet(int t, int u)
{
	if(u == 1)
		return t;
	return t * kuvvet(t, u-1);
}

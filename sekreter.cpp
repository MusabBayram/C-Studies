#include <stdio.h>
#include <conio.h>
#include <string.h>
struct tip
{ 
	char ad[15];
	char soyad[15];
	char evNo[12];
	char cepNo[12];
	char isNo[12];
	char mail[50];
	char dogum[15];
	char mah[15];
	char sk[10];
	char apNo[5];
	char il[10];
	char ilce[10];
};

struct tip kisi;
struct tip kisiler[BUFSIZ];
void ekle();
void goruntule();
void guncelleme ();
void sil();
void arama();
FILE *dd;


main()
{
	
	char m;
	do
	{
		
		int  d;
		printf("\nKisi Ekle(1)  Goruntule(2)  Guncelle(3)  Sil(4)  Ara(5)\n");
		scanf("%d", &d);
		switch(d)
		{
			case 1:
				ekle();
				break;
			case 2:
				goruntule();
				break;
			case 3:
				guncelleme ();
				break;
			case 4:
				sil();
				break;
			case 5:
				arama();
				break;
		}
		
		printf("\nTekrar islem yapmak istiyormusunuz? (e-E)\n");
		m =_getch();
	}
	while(m=='e' || m=='E');
	
}

void ekle()
{

	if((dd=fopen("rehber.txt", "a+")) == NULL)
		printf("Surucu bulunamadi.\n");
	else
	{
		printf("\nAd :");						scanf("%s",   kisi.ad);			fprintf(dd,"%s\t\t",  	kisi.ad);
		printf("Soyad :");						scanf("%s",   kisi.soyad);		fprintf(dd,"%s\t\t", 	kisi.soyad);
		printf("Ev Tel :");						scanf("%s",   kisi.evNo);		fprintf(dd,"%s\t\t", 	kisi.evNo);
		printf("Cep Tel :");					scanf("%s",   kisi.cepNo);		fprintf(dd,"%s\t\t", 	kisi.cepNo);
		printf("Is Tel :");						scanf("%s",   kisi.isNo);		fprintf(dd,"%s\t\t", 	kisi.isNo);
		printf("E-posta :");					scanf("%s",   kisi.mail);		fprintf(dd,"%s\t\t", 	kisi.mail);	
		printf("Dogum (gun/ay/yil) :");			scanf("%s",   kisi.dogum);		fprintf(dd,"%s\t",	    kisi.dogum);
		printf("Adres (mah.) :");				scanf("%s",   kisi.mah);		fprintf(dd,"%s\t",  	kisi.mah);
		printf("Adres (sk.) :");				scanf("%s",   kisi.sk);			fprintf(dd,"%s\t", 		kisi.sk);
		printf("Apartman No :");				scanf("%s",   kisi.apNo);		fprintf(dd,"%s\t", 		kisi.apNo);
		printf("Adres (il) :");					scanf("%s",   kisi.il);			fprintf(dd,"%s\t",		kisi.il);
		printf("Adres (ilce) :");				scanf("%s",   kisi.ilce);		fprintf(dd,"%s\n", 		kisi.ilce);
		fclose(dd);
	}
}


void goruntule()
{
	if((dd=fopen("rehber.txt", "r")) == NULL)
		printf("Surucu bulunamadi.\n");
	else
	{
int a=0;
		while(!feof(dd))
		{ 
			printf("%d. kayit\n",a+1);
			fscanf(dd, "%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
			printf("%s%s%s%s%s%s%s%s%s%s%s%s\n", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
		a++;	
		}
		fclose(dd);
	}	
}

void guncelleme ()
{
	FILE *dd,*fp;
    fp=fopen("r.txt", "w");
	if((dd=fopen("rehber.txt", "r+")) == NULL)
		printf("Dosya bulunamadi.\n");
	else
	{
	char g[50],yeniad[15], yeniSoyad[15], yeniEvno[12], yeniCepno[12], yeniSno[12], yeniMail[50], yeniDogum[15], yeniMah[15], yeniSk[10], yeniApno[5], yenil[10], yenilce[10];
	int x;
		printf("guncellemek istediginiz kisinin cep numarasini giriniz:");
		scanf("%s",g);
	while(!feof(dd))
		{
			fscanf(dd, "%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
			if(strcmp(g,kisi.cepNo)==0)
			{
				printf("Bu kisinin hangi bilgisini guncellemek istersiniz?\n");
				printf("Ad(1), Soyad(2), EvNo(3), CepNo(4), Isno(5), E-posta(6), Dogum Tar.(7), Mah.(8), Sk.(9), ApNo(10), Il(11), Ilce(12), Geri(13)\n");
				scanf("%d", &x);
				
				switch(x)
				{
					case 1:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni adi giriniz:");
						scanf("%s",yeniad);
						memcpy(kisi.ad,yeniad,15);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 2:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni soyadi giriniz:");
						scanf("%s",yeniSoyad);
						memcpy(kisi.soyad,yeniSoyad,15);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 3:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni ev numarasini giriniz:");
						scanf("%s",yeniEvno);
						memcpy(kisi.evNo,yeniEvno,12);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}	
					break;	
				case 4:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni cep numarasini giriniz:");
						scanf("%s",yeniCepno);
						memcpy(kisi.cepNo,yeniCepno,12);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}	
					break;
				case 5:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni is numarasini giriniz:");
						scanf("%s",yeniSno);
						memcpy(kisi.isNo,yeniSno,12);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 6:	
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni E-postasini giriniz:");
						scanf("%s",yeniMail);
						memcpy(kisi.mail,yeniMail,50);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 7:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni dogum tarihini giriniz:");
						scanf("%s",yeniDogum);
						memcpy(kisi.dogum,yeniDogum,15);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 8:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni mahalle ismini giriniz:");
						scanf("%s",yeniMah);
						memcpy(kisi.mah,yeniMah,15);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 9:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni sokak ismini giriniz:");
						scanf("%s",yeniSk);
						memcpy(kisi.sk,yeniSk,10);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 10:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni apartman numarasini giriniz:");
						scanf("%s",yeniApno);
						memcpy(kisi.apNo,yeniApno,5);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 11:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni ili giriniz:");
						scanf("%s",yenil);
						memcpy(kisi.il,yenil,10);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
					break;
				case 12:
					{
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
						printf("yeni ilce giriniz:");
						scanf("%s",yenilce);
						memcpy(kisi.ilce,yenilce,10);
						printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
					}
				}
			}
	fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);

		
		}
	}
	fclose(dd);
	fclose(fp);
	remove("rehber.txt");
	rename("r.txt","rehber.txt");
}
void sil()
{
	
	FILE *dd,*fp;
    fp=fopen("r.txt", "w");
	if((dd=fopen("rehber.txt", "r+")) == NULL)
		printf("Dosya bulunamadi.\n");
	else
	{
		int v=0;

	//char g[50],yeniad[15], yeniSoyad[15], yeniEvno[12], yeniCepno[12], yeniSno[12], yeniMail[50], yeniDogum[15], yeniMah[15], yeniSk[10], yeniApno[5], yenil[10], yenilce[10];;
	int x,kisiNo;
		printf("silmek istediginiz kisinin no giriniz:");
		scanf("%d",kisiNo);
	while(!feof(dd))
		{
		fscanf(dd, "%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
			
			printf("asdasdasd");
			if(v==kisiNo)
			{ 
			v++;
			}
		 	strcpy(kisiler[v].ad,kisi.ad);
			strcpy(kisiler[v].soyad,kisi.soyad);
			strcpy(kisiler[v].evNo,kisi.evNo);
			strcpy(kisiler[v].cepNo,kisi.cepNo);
			strcpy(kisiler[v].isNo,kisi.isNo);
			strcpy(kisiler[v].mail,kisi.mail);
			strcpy(kisiler[v].dogum,kisi.dogum);
			strcpy(kisiler[v].mah,kisi.mah);
			strcpy(kisiler[v].sk,kisi.sk);
			strcpy(kisiler[v].apNo,kisi.apNo);
			strcpy(kisiler[v].il,kisi.il);
			strcpy(kisiler[v].ilce,kisi.ilce);
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", kisiler[v].ad, kisiler[v].soyad, kisiler[v].evNo, kisiler[v].cepNo, kisiler[v].isNo, kisiler[v].mail, kisiler[v].dogum, kisiler[v].mah, kisiler[v].sk, kisiler[v].apNo, kisiler[v].il, kisiler[v].ilce);
			v++;	

		}
	}
	fclose(dd);
	fclose(fp);
	remove("rehber.txt");
	rename("r.txt","rehber.txt");
			
}
void arama()
{
		if((dd=fopen("rehber.txt", "r+")) == NULL)
		printf("Dosya bulunamadi.\n");
	else
	{
	char g[12];
	printf("Aramak istediginiz kisinin cep telefon numarasini giriniz\n");
	scanf("%s",g);
	while(!feof(dd))
		{
			fscanf(dd, "%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
			if(strcmp(g,kisi.cepNo)==0)
				printf("%s%s%s%s%s%s%s%s%s%s%s%s", kisi.ad, kisi.soyad, kisi.evNo, kisi.cepNo, kisi.isNo, kisi.mail, kisi.dogum, kisi.mah, kisi.sk, kisi.apNo, kisi.il, kisi.ilce);
		}
	
	}
	fclose(dd);
}

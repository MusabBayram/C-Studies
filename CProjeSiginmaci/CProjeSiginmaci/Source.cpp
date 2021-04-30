#include <stdio.h>
#include <conio.h>
#include <system_error>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <io.h>
struct siginmaci
{
	char  siginmaciNo[20];
	char ad[20];
	char soyad[20];
	char dogumYeri[20];
	char cinsiyet[20];
	char uyruk[20];
	char meslek[20];
	char egitimDurum[20];
	char tel[20];
	char dogumTarihi[20];
	char yerlsehir[20];
	char geldSehir[20];
	char gelisTarihi[20];
	char ePosta[20];

};
struct kullanici
{
	
	char TcNo[20];
	char ad[20];
	char soyAd[20];
	char tel[20];
	char adres[20];
	
	char sifre[20];
	char yetkiTuru[20];


};
struct kontrol
{
	char TcNo[20];
	char siginmaciNo[20];

}kntrl;


void adminMenu();
void siginmaciMemurMenu();
void kullaniciArama();
void kullaniciEkleme();
void kullaniciGoruntuleme();
void kullaniciGuncelleme();
void kullaniciSilme();
void kullaniciSifreDegistir();
void siginmaciArama();
void siginmaciEkleme();
void siginmaciGoruntuleme();
void siginmaciGuncellme();
void siginmaciSilme();
void kullaniciMenu();

struct siginmaci sgnmc;
struct kullanici kllnc;
void main()
{
	int count=0; 
	char secim[10];
	char adminAd[30]="admin",admGiris[30];///kullanýcý adý ve sifresi elle girildi
	char sifre[20]="223015",sifre2[20];	

	for (;;)
	{
		system("CLS");
		system("color ");
			
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
		printf("\t\t\t\1\1\1\=>\tANA MENU\t\<=\1\1\1\n");
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");		
		printf("\ Sisteme giris icin belirtilen islemlerden birini seciniz:\n\n");

		printf("Programa giris yapmak icin======> 1'i  seciniz:\n");		
		printf("Cikis yapmak icin ==============> 0'i  seciniz:\n\n\n");		
		scanf("%s",secim);
		if (strcmp(secim,"1")==0)
		{
			for(;;)
			{
				system("CLS");
				char sec[10];


				printf("\n==>ADMIN GIRISI ICIN HERHANGI BIR TUSA;\n==>ANA MENUYE DONMEK ICIN SIFIR{0}'A BASINIZ...\n\n");
				printf("\t\tSECIMINIZ:\t");
				scanf("%s",sec);
				if (strcmp(sec,"0")==0)
				{
					break;
				}
				system("CLS");
				printf("\nAdmin kullanici adini giriniz:\n");
				scanf("%s",admGiris);			
				printf("Admin sifresi giriniz:\n");			
				scanf("%s",sifre2);
				
				if(strcmp(sifre2,sifre)==0 && strcmp(admGiris,adminAd)==0)
				{

					adminMenu();
				} 
				
				else
				{
					FILE *dd;
					if((dd=fopen("kullaniciler.txt","r"))!=NULL)
					{
						while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
						{
							
							if(strcmp(kllnc .TcNo ,admGiris )==0 && strcmp(kllnc .sifre ,sifre2)==0)
							{
								if(strcmp(kllnc .yetkiTuru,"admin")==0 )
								{
									count++;
									adminMenu();
								}
								else if(strcmp(kllnc .yetkiTuru,"siginmacimemuru")==0 )
								{
									count++;
									siginmaciMemurMenu();
								}
								else if(strcmp(kllnc .yetkiTuru,"kullanici")==0 )
								{
									count++;
									kullaniciMenu();
								}

							}

						}
					}
					fclose (dd);
					if(count==0)
					{
						char sec[10];
						system("CLS");
						printf("kullanici adi veya sifre yanlis...\n");
						printf("==>tekrar giris yapmak icin herhangi bir tusa;\n==> ana menuye donmek icin 0 a basiniz...\n\nSeciminiz:");
						scanf("%s",sec);
						if (strcmp(sec,"0")==0)
						{
							break;
						}
						else  
						{
							continue;
						}
					}

				}

			}
		}
		


		

		else if (strcmp(secim,"0")==0)
		{
			break;

		}
		else 
			printf("belirtilen degerlerden birini giriniz::");

	}


}
/////////////////////////////////////////////////////////////////////////////////////////////
void kullaniciEkleme()
{
	
	for(;;)
	{

		system ("CLS");
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
		printf("\t\t   \1\1\1\=>KULLANICI EKLEME SAYFASI\t\<=\1\1\1\n");
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");		
        printf("\n\3\3kullanici ekleme sayfasi\3\3\n\n");
		for(;;)
		{
			int count=0;
			int count2=0;
			try
			{
				
				system("CLS");
				
				printf("\nKullanici TC sini giriniz :");///herkesin tc nosu farkli olmalý
				scanf("%s",kllnc.TcNo);
				for(int i=0;i<20;i++)
				{
					if(isalpha(kllnc.TcNo[i]))//girilen tc no da harf olup olmadýðýný kontrol eder;
					{
						count++;
					}
					
				}
				if(count>0)
					{
						system("CLS");
						printf("Tc numarasinda yalnizca rakam bulunmalidir..");
						count=0;
						getch();

					}
				else
				{
					FILE*dd=fopen("kullaniciler.txt","r");///tc no kontrolu
					while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kntrl.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
		
					{
			
							if(strcmp(kntrl.TcNo,kllnc.TcNo)==0)
							{
								count2++;
								system("CLS");
								printf("Girilen Tc No sistemde kayitlidir...");
								getch();
								break;
							}
							else
							{
								continue;
							}
			
					}
					if(count2==0)
					{
						break;
					}
					
				}
				
			}catch(char e)
			{
				system("CLS");
				printf("Tc numarasinda yalnizca rakam bulunmalidir..");
				getch();
				
			}
		}
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nKullanici adini giriniz :");
				scanf("%s",kllnc.ad);
				for(int i=0;i<20;i++)
				{
					if(isdigit(kllnc.ad[i]))//girilen ad da rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}
					
				}
				if(count>0)
					{
						system("CLS");
						printf("Isim alanýnda numerik karakter kullanýlamaz...");
						getch();
					}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Isim alanýnda numerik karakter kullanýlamaz...");
				getch();
			}
		}
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nKullanici soyadini giriniz :");
				scanf("%s",kllnc.soyAd );
				for(int i=0;i<20;i++)
				{
					if(isdigit(kllnc.soyAd[i]))//girilen soyad da rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}
					
				}
				if(count>0)
					{
						system("CLS");
						printf("Soyisim alaninda numerik karakter kullanýlamaz...");
						getch();
					}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Soyisim alaninda numerik karakter kullanilamaz...");
				getch();
			}
		}
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nKullanici telefonunu giriniz :");
				scanf("%s",kllnc.tel );
				for(int i=0;i<20;i++)
				{
					if(isalpha(kllnc.tel[i]))//girilen tel de harf olup olmadýðýný kontrol eder;
					{
						count++;
					}
					
				}
				if(count>0)
					{
						system("CLS");
						printf("Telefon alanýnda alfabetik karakter kullanýlamaz...");
						getch();
					}
				else
				{
					break;
				}

				
			}catch(int e)
				{
					
				}
		}
		
		system("CLS");
		printf("\nKullanici adresini giriniz :");
		scanf("%s",kllnc.adres );
		system("CLS");
		printf("\nKullanici sifresini giriniz :");
		scanf("%s",kllnc.sifre );
		for(;;)
		{
			system("CLS");
		printf("\nKullanici yetki turunu giriniz :");
		scanf("%s",kllnc.yetkiTuru);
			if(strcmp(kllnc.yetkiTuru,"admin")==0 ||strcmp(kllnc.yetkiTuru,"siginmacimemuru")==0 ||strcmp(kllnc.yetkiTuru,"kullanici")==0)
			{
				break;				
			}
			else
			{
				system("CLS");
				printf("Lutfen sadece 'admin','kullanici' ve 'siginmacimemuru' kelimelerini kullanin");
				getch();				
			}
			
		}
		FILE *dd;
		if((dd=fopen("kullaniciler.txt","r"))==NULL)
		{
			system ("CLS");
			fclose(dd);
			printf("Kayit yapilacak Dosya bulunamadi...");
			getch();
		}
		else
		{
			fclose(dd);
			char secim[10];
			dd=fopen("kullaniciler.txt","a");
			fprintf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
			system ("CLS");
			printf("\nKayit islemi basari ile gerçeklestirildi...");
			fclose (dd);
			getch();
			system ("CLS");
			printf("\n==>Kayit islemine devam etmek için herhangi bir tusa basiniz.\n");
			printf("\n==>Ana menuye dönmek icin 0 a basiniz.\n");
			printf("seciminiz:");
			scanf("%s",secim);
			if(strcmp(secim,"0")==0)
			{
				break;
			}
		}
		fclose (dd);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void kullaniciSilme()
{
	system("CLS");
	printf ("\2\2\2\2\2\SILME MENUSU\2\2\2\2\2\2\n\n\n");
	int count=0;
	char ara[20];
	char cevap[20];
	FILE *dd=fopen ("kullaniciler.txt","r");
	FILE*dd1=fopen("kullaniciler1.txt","w");
	
	printf("Silinecek Kullanicinin TC sini giriniz :");
	scanf("%s",ara);
	while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
	{
		if(strcmp(ara,kllnc.TcNo)==0)
		{
			count++;
			continue;
		}
		else
		{
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
		}

	}
	fclose(dd);
	fclose(dd1);
	FILE*dd2=fopen("kullaniciler1.txt","r");
	FILE *dd3=fopen ("kullaniciler.txt","w");
	while(fscanf(dd2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
	{
      fprintf(dd3,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
	
	}
	fclose(dd2);
	fclose(dd3);
	if(count>0)
	{
		system("CLS");
		printf ("Silme islemi basarili bir sekilde gerceklestirildi...");
	}
	else
	{
		system("CLS");
		printf("Silinecek kayit bulunamadi");
	}
	
	

	getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////
void kullaniciGuncelleme()
{
	system("CLS");
	printf ("\2\2\2\2\2\GUNCELLEME MENUSU\2\2\2\2\2\2\n\n\n");
	int count=0;
	char ara[20];
	char cevap[20];
	FILE *dd=fopen ("kullaniciler.txt","r");
	FILE*dd1=fopen("kullaniciler1.txt","w");
	
	printf("Guncellenecek Kullanicinin TC sini giriniz :");
	scanf("%s",ara);
	while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
	{
		if(strcmp(ara,kllnc.TcNo)==0)
		{
			count++;
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nKullanici adini giriniz :");
					scanf("%s",kllnc.ad);
					for(int i=0;i<20;i++)
					{
						if(isdigit(kllnc.ad[i]))//girilen tc no da harf olup olmadýðýný kontrol eder;
						{
							count++;
						}
					
					}
					if(count>0)
						{
							system("CLS");
							printf("Isim alanýnda numerik karakter kullanýlamaz...");
							getch();
						}
					else
					{
						break;
					}

					break;
				}catch(int e)
				{
					system("CLS");
					printf("Isim alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nKullanici soyadini giriniz :");
				scanf("%s",kllnc.soyAd );
				for(int i=0;i<20;i++)
				{
					if(isdigit(kllnc.soyAd[i]))//girilen soyad da rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}
					
				}
				if(count>0)
					{
						system("CLS");
						printf("Soyisim alaninda numerik karakter kullanýlamaz...");
						getch();

					}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Soyisim alaninda numerik karakter kullanýlamaz...");
				getch();
			}
		}
			for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nKullanici telefonunu giriniz :");
				scanf("%s",kllnc.tel );
				for(int i=0;i<20;i++)
				{
					if(isalpha(kllnc.tel[i]))//girilen telde harf olup olmadýðýný kontrol eder;
					{
						count++;
					}
					
				}
				if(count>0)
					{
						system("CLS");
						printf("Telefon alanýnda alfabetik karakter kullanýlamaz...");
						getch();

					}
				else
				{
					break;
				}

				//break;
			}catch(int e)
			{
				
			}
		}
			system("CLS");
			printf("\nKullanicinin adresini giriniz :");
			scanf("%s",kllnc.adres);
			system("CLS");
			printf("\nKullanicinin sifresini giriniz :");
			scanf("%s",kllnc.sifre);
			for(;;)
		{
			system("CLS");
		printf("\nKullanici yetki turunu giriniz :");
		scanf("%s",kllnc.yetkiTuru);
			if(strcmp(kllnc.yetkiTuru,"admin")==0 ||strcmp(kllnc.yetkiTuru,"siginmacimemuru")==0 ||strcmp(kllnc.yetkiTuru,"kullanici")==0)
			{
				break;
			}
			else
			{system("CLS");
				printf("Lutfen sadece 'admin','kullanici' ve 'siginmacimemuru' kelimelerini kullanin");
				getch();
				
			}
		}
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
		}
		else
		{
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
		}

	}
	fclose(dd);
	fclose(dd1);
	FILE*dd2=fopen("kullaniciler1.txt","r");
	FILE *dd3=fopen ("kullaniciler.txt","w");
	while(fscanf(dd2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
	{
      fprintf(dd3,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
	
	}
	fclose(dd2);
	fclose(dd3);
	if(count>0)
	{
		system("CLS");
		printf ("Guncelleme islemi basarili bir sekilde gerceklestirildi...");
		getch();
	}
	else
	{
		system("CLS");
		printf("Guncellenecek kayit bulunamadi");
		getch();
	}
	
	

	getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////
void kullaniciArama()
{
	char tc[20];
	
	for(;;)
	{          printf("\n\n\1\1\1\1\4ARAMA\4\1\1\1\1");
				int count=0;
				char c[20];
				system("CLS");
				printf("\nkullanici TC si ile arama yapmak icin ===>1 i seciniz:");
				printf("\ncikis yapmak icin =========>0 i seciniz:\nseciminiz:");
				scanf("%s",c);
				if(strcmp(c,"0")==0)
				{
				break;
				}
				else
				{
					printf("\nkullanici tc si giriniz:");
				scanf("%s",tc);			
				
				
					FILE *dd;
					if((dd=fopen("kullaniciler.txt","r"))!=NULL)
					{
						while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
						{
							
							if(strcmp(kllnc.TcNo ,tc )==0)
							{
									count++;
									printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru);	
									getch();
							}
						
						}
						
					}
					fclose (dd);
					
					if(count==0)
					{
						char sec[10];
						system("CLS");
						printf("Boyle bir kisi bulunmamaktadir...\n");
						printf("==>tekrar arama yapmak icin herhangi bir tusa;\n==> ana menuye donmek icin 0 a basiniz...\n\nSeciminiz:");
						scanf("%s",sec);
						if (strcmp(sec,"0")==0)
						{
							break;
						}
						else  
						{
							continue;
						}
					}
	}
}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void kullaniciGoruntuleme()
{
	FILE *dd;
	dd=fopen("kullaniciler.txt","r");
	system ("CLS");
	printf ("\t\t\2\2\2\2\2\2GORUNTULEME MENUSU\2\2\2\2\2\2\n\n\n");
	if(dd!=NULL)
	{
		while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
		
		{
			
				printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru);	

			
		}
	}
	
	else
	{
		printf("Dosya bulunamadi...");
	}
	
	fclose (dd);
	getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////
void kullaniciSifreDegistir()
{
	system("CLS");
	printf ("\2\2\2\2\2\SIFRE DEGISTIRME MENUSU\2\2\2\2\2\2\n\n\n");
	int count=0;
	char ara[20];
	char cevap[20];
	FILE *dd=fopen ("kullaniciler.txt","r");
	FILE*dd1=fopen("kullaniciler1.txt","w");
	
	printf("Sifresi degistirilecek Kullanicinin TC sini giriniz :");
	scanf("%s",ara);
	while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
	{
		if(strcmp(ara,kllnc.TcNo)==0)
		{
			count++;
			printf("Yeni sifreyi giriniz : ");
			scanf("%s",kllnc.sifre);
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);

		}
		else
		{
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
		}

	}
	fclose(dd);
	fclose(dd1);
	FILE*dd2=fopen("kullaniciler1.txt","r");
	FILE *dd3=fopen ("kullaniciler.txt","w");
	while(fscanf(dd2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc.TcNo,kllnc .ad ,kllnc.soyAd,kllnc.tel,kllnc.adres,kllnc.sifre,kllnc.yetkiTuru)!=EOF)
	{
      fprintf(dd3,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kllnc .TcNo,kllnc .ad ,kllnc .soyAd ,kllnc .tel ,kllnc .adres ,kllnc.sifre ,kllnc .yetkiTuru);
	
	}
	fclose(dd2);
	fclose(dd3);
	if(count>0)
	{
		system("CLS");
		printf ("Sifre degistirme islemi basarili bir sekilde gerceklestirildi...");
	}
	else
	{
		system("CLS");
		printf("Duzenlenecek kayit bulunamadi");
	}
	
	

	getch();
}
//////////////////  SIGINMACI  ///////////////////////

void siginmaciEkleme()
{
	
	for(;;)
	{

		system ("CLS");
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
		printf("\t\t   \1\1\1\=>SIGINMACI EKLEME SAYFASI\t\<=\1\1\1\n");
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");		
		printf("\n\3\3\3Siginmaci ekleme sayfasi\3\3\3\n\n");
		for(;;)
		{
			int count=0;
			int count2=0;
			try
			{

				//system("CLS");

				printf("\nSiginmaci no sunu giriniz :");
				scanf("%s",sgnmc .siginmaciNo);
				for(int i=0;i<20;i++)
				{
					if(isalpha(sgnmc.siginmaciNo[i]))//girilen siginmaci no da harf olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Siginmaci no da yalnizca rakam bulunmalidir..");
					getch();

				}
				else
				{
					FILE*dd=fopen("siginmacilar.txt","r");
					while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",kntrl.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)

					{

						if(strcmp(kntrl.siginmaciNo,sgnmc.siginmaciNo)==0)
						{
							count2++;
							system("CLS");
							printf("Girilen siginmaci no sistemde kayitlidir...");
							break;
							getch();
						}
					
					}
					if(count2==0)
					{
						break;
					}
				}
				
			}
			catch(char e)
			{
				system("CLS");
				printf("Siginmaci no da yalnizca rakam bulunmalidir..");
				getch();

			}
		}
///---------------------------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci adini giriniz :");
				scanf("%s",sgnmc.ad);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.ad[i]))//girilen isimde rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Isim alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Isim alanýnda numerik karakter kullanýlamaz...");
				getch();
			}
		}
		///----------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci soyAdini giriniz :");
				scanf("%s",sgnmc.soyad);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.soyad[i]))//girilen soyisimde rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("SoyIsim alaninda numerik karakter kullanilamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("SoyIsim alaninda numerik karakter kullanilamaz...");
				getch();
			}
		}
		///----------------------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci dogum yerini giriniz :");
				scanf("%s",sgnmc .dogumYeri );
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.dogumYeri[i]))//girilen dogum yerinde rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("dogum yeri alaninda numerik karakter kullanilamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Dogum yeri alaninda numerik karakter kullanilamaz...");
				getch();
			}
		}
		///--------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci dogum tarihi giriniz :");
				scanf("%s",sgnmc.dogumTarihi );
				for(int i=0;i<20;i++)
				{
					if(isalpha(sgnmc.dogumTarihi[i]))//girilen dogum tarihinde harf olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Dogum tarihi alaninda alfabetik karakter kullanilamaz...");
					getch();
				}
				else
				{
					break;
				}

				//break;
			}
			catch(int e)
			{

			}
		}


		///-----
		for(;;)
		{
			system("CLS");
			printf("\nSiginmaci cinsiyeti giriniz :");
			scanf("%s",sgnmc.cinsiyet);
			if(strcmp(sgnmc .cinsiyet,"kadin")==0 ||strcmp(sgnmc.cinsiyet,"kadýn")==0 ||strcmp(sgnmc.cinsiyet,"erkek")==0)
			{
				break;

			}
			else
			{
				system("CLS");
				printf("Lutfen sadece 'kadin'--'erkek' kelimelerini kullanin");
				getch();


			}

		}
		////----

		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci uyrugunu giriniz :");
				scanf("%s",sgnmc.uyruk);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.uyruk[i]))//girilen meslek rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Uyruk alaninda numerik karakter kullanilamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Uyruk alaninda numerik karakter kullanilamaz...");
				getch();
			}
		}

		///----------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci meslegini giriniz :");
				scanf("%s",sgnmc.meslek);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.meslek[i]))//girilen meslek rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Meslek alaninda numerik karakter kullanilamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Meslek alaninda numerik karakter kullanilamaz...");
				getch();
			}
		}
		///-----------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmacinin egitim durumunu giriniz :");
				scanf("%s",sgnmc .egitimDurum );
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.egitimDurum[i]))//girilen egitim durumunda rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Egitim durumu alaninda numerik karakter kullanýlamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Egitim durumu alaninda numerik karakter kullanýlamaz...");
				getch();
			}
		}
		///------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci telefonunu giriniz :");
				scanf("%s",sgnmc.tel );
				for(int i=0;i<20;i++)
				{
					if(isalpha(sgnmc.tel[i]))//girilen tel no da harf olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Telefon alanýnda alfabetik karakter kullanýlamaz...");
					getch();
				}
				else
				{
					break;
				}

				///break;
			}catch(int e)
			{

			}
		}
		/////---------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmacinin yerlestirildigi sehiri giriniz :");
				scanf("%s",sgnmc.yerlsehir);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.yerlsehir[i]))//girilen sehirde olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Yerlestirildigi sehir alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Yerlestirildigi sehir alanýnda numerik karakter kullanýlamaz...");
				getch();
			}
		}
		///-----------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmacinin geldigi sehiri giriniz :");
				scanf("%s",sgnmc.geldSehir);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.geldSehir[i]))//girilen sehirde rakam olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Siginmacini geldigi sehir alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Siginmacini geldigi sehir alanýnda numerik karakter kullanýlamaz...");
				getch();
			}
		}
		///--------
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmacinin gelmis oldugu tarihi giriniz :");
				scanf("%s",sgnmc.gelisTarihi );
				for(int i=0;i<20;i++)
				{
					if(isalpha(sgnmc.gelisTarihi[i]))//girilen tel no da harf olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("gelmis oldugu tarih alaninda alfabetik karakter kullanilamaz...");
					getch();
				}
				else
				{
					break;
				}

				///break;
			}catch(int e)
			{

			}
		}

		////----
		for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci  ePostasini giriniz :");
				scanf("%s",sgnmc.ePosta);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.ePosta[i]))//girilen isimde rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("ePosta alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("ePosta alanýnda numerik karakter kullanýlamaz...");
				getch();
			}
		}
		////-----------------------------------------------

			FILE *dd;
		if((dd=fopen("siginmacilar.txt","r"))==NULL)
		{
			system ("CLS");
			fclose(dd);
			printf("Kayit yapilacak Dosya bulunamadi...");
			getch();
			fclose(dd);
		}
		else
		{
			
			char secim[10];
			dd=fopen("siginmacilar.txt","a");
			fprintf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
			system ("CLS");
			printf("\nKayit islemi basari ile gerçeklestirildi...");
			fclose (dd);
			getch();
			system ("CLS");
			printf("\n==>Kayit islemine devam etmek için herhangi bir tusa basiniz.\n");
			printf("\n==>Ana menuye dönmek icin 0 a basiniz.\n");
			printf("seciminiz:");
			scanf("%s",secim);
			if(strcmp(secim,"0")==0)
			{
				break;
			}
		}

	}

}
/////////////////////////////////////////////////////////////////////////////////////////////
void siginmaciSilme()
{
	system("CLS");
	printf ("\2\2\2\2\2\SILME MENUSU\2\2\2\2\2\2\n\n\n");
	int count=0;
	char ara[20];
	char cevap[20];
	FILE *dd=fopen ("siginmacilar.txt","r");
	FILE*dd1=fopen("siginmacilar1.txt","w");
	
	printf("Silinecek siginmacinin numarasini giriniz :");
	scanf("%s",ara);
	while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
	{
		if(strcmp(ara,sgnmc.siginmaciNo)==0)
		{
			count++;
			continue;
		}
		else
		{
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
		}

	}
	fclose(dd);
	fclose(dd1);
	FILE*dd2=fopen("siginmacilar1.txt","r");
	FILE *dd3=fopen ("siginmacilar.txt","w");
	while(fscanf(dd2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",kntrl.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
	{
      fprintf(dd3,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",kntrl.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
	
	}
	fclose(dd2);
	fclose(dd3);
	if(count>0)
	{
		system("CLS");
		printf ("Silme islemi basarili bir sekilde gerceklestirildi...");
	}
	else
	{
		system("CLS");
		printf("Silinecek kayit bulunamadi");
	}
	
	

	getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////
void siginmaciGuncellme()
{
	system("CLS");
	printf ("\t\t\2\2\2\2\2\GUNCELLEME MENUSU\2\2\2\2\2\2\n\n\n");
	int count=0;
	int count2=0;
	char ara[20];
	char cevap[20];
	FILE *dd=fopen ("siginmacilar.txt","r");
	FILE*dd1=fopen("siginmacilar1.txt","w");
	
	printf("Guncellenecek Siginmacinin siginmaci numarasini giriniz :");
	scanf("%s",ara);
	while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
	{
		if(strcmp(ara,sgnmc.siginmaciNo)==0)
		{

			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmaci adini giriniz :");
					scanf("%s",sgnmc.ad);
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.ad[i]))//girilen isimde rakam olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Isim alaninda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("Isim alaninda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			///----------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmaci soyadini giriniz :");
					scanf("%s",sgnmc.soyad);
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.soyad[i]))//girilen soyad da rakam olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Soyisim alaninda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("Soyisim alaninda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			///----------------------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmaci dogum yerini giriniz :");
					scanf("%s",sgnmc .dogumYeri );
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.dogumYeri[i]))//girilen dogum yerinde rakam olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("dogum yeri alaninda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("Dogum yeri alaninda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			///--------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmaci dogum tarihi giriniz :");
					scanf("%s",sgnmc.dogumTarihi );
					for(int i=0;i<20;i++)
					{
						if(isalpha(sgnmc.dogumTarihi[i]))//girilen dogum tarihinde harf olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Dogum tarihi alanýnda alfabetik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}

					break;
				}catch(int e)
				{

				}
			}


			///-----
			for(;;)
			{
				system("CLS");
				printf("\nSiginmaci cinsiyeti giriniz :");
				scanf("%s",sgnmc.cinsiyet);
				if(strcmp(sgnmc .cinsiyet,"kadin")==0 ||strcmp(sgnmc.cinsiyet,"kadýn")==0 ||strcmp(sgnmc.cinsiyet,"erkek")==0)
				{
					break;

				}
				else
				{
					system("CLS");
					printf("Lutfen sadece 'kadin'--'erkek' kelimelerini kullanin");
					getch();


				}

			}
			///----------
			for(;;)
		{
			int count=0;
			try
			{
				system("CLS");
				printf("\nSiginmaci uyrugunu giriniz :");
				scanf("%s",sgnmc.uyruk);
				for(int i=0;i<20;i++)
				{
					if(isdigit(sgnmc.uyruk[i]))//girilen meslek rakam olup olmadýðýný kontrol eder;
					{
						count++;
					}

				}
				if(count>0)
				{
					system("CLS");
					printf("Uyruk alaninda numerik karakter kullanilamaz...");
					getch();
				}
				else
				{
					break;
				}


			}catch(int e)
			{
				system("CLS");
				printf("Uyruk alaninda numerik karakter kullanilamaz...");
				getch();
			}
		}
			///----------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmacinin meslegini giriniz :");
					scanf("%s",sgnmc .meslek );
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.meslek[i]))//girilen mesleginde rakam olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Siginmacini meslegi alaninda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("Siginmaci meslegi alaninda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			///-----------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmacinin egitim durumunu giriniz :");
					scanf("%s",sgnmc .egitimDurum );
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.egitimDurum[i]))//girilen egitim durumunda rakam olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Egitim durumu alaninda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("Egitim durumu alaninda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			///------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmaci telefonunu giriniz :");
					scanf("%s",sgnmc.tel );
					for(int i=0;i<20;i++)
					{
						if(isalpha(sgnmc.tel[i]))//girilen tel no da harf olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Telefon alanýnda alfabetik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}

					break;
				}catch(int e)
				{

				}
			}
			/////---------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmacinin yerlestirildigi sehiri giriniz :");
					scanf("%s",sgnmc.yerlsehir);
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.yerlsehir[i]))//girilen sehirde olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Yerlestirildigi sehir alanýnda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("Yerlestirildigi sehir alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			///-----------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmacinin geldigi sehiri giriniz :");
					scanf("%s",sgnmc.geldSehir);
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.geldSehir[i]))//girilen sehirde rakam olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Siginmacini geldigi sehir alanýnda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("Siginmacini geldigi sehir alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
			}
			///--------
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmaci gelmis oldugu tarihi giriniz :");
					scanf("%s",sgnmc.gelisTarihi );
					for(int i=0;i<20;i++)
					{
						if(isalpha(sgnmc.gelisTarihi[i]))//girilen dogum tarihinde harf olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("Siginmacinin gelis tarihi alanýnda alfabetik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}

					break;
				}catch(int e)
				{

				}
			}

			////----
			for(;;)
			{
				int count=0;
				try
				{
					system("CLS");
					printf("\nSiginmaci  ePostasini giriniz :");
					scanf("%s",sgnmc.ePosta);
					for(int i=0;i<20;i++)
					{
						if(isdigit(sgnmc.ePosta[i]))//girilen isimde rakam olup olmadýðýný kontrol eder;
						{
							count++;
						}

					}
					if(count>0)
					{
						system("CLS");
						printf("ePosta alanýnda numerik karakter kullanýlamaz...");
						getch();
					}
					else
					{
						break;
					}


				}catch(int e)
				{
					system("CLS");
					printf("ePosta alanýnda numerik karakter kullanýlamaz...");
					getch();
				}
			}


			count2++;
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);

		}
		else
		{
			fprintf(dd1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
		}

	}
	fclose(dd);
	fclose(dd1);
	FILE*dd2=fopen("siginmacilar1.txt","r");
	FILE *dd3=fopen ("siginmacilar.txt","w");
	while(fscanf(dd2,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
	{
      fprintf(dd3,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
	
	}
	fclose(dd2);
	fclose(dd3);
	if(count2>0)
	{
		system("CLS");
		printf ("Guncelleme islemi basarili bir sekilde gerceklestirildi...");
		getch();
	}
	else
	{
		system("CLS");
		printf("Guncellenecek kayit bulunamadi");
		getch();
	}
	
	

	getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////
void siginmaciArama()
{
	for(;;)
	{   
		char secim[10];
		system("CLS");
		printf ("\2\2\2\2\2\2ARAMA MENUSU\2\2\2\2\2\2\n\n\n");

		printf("\nSiginmacinin geldigi sehre gore arama icin          ===>1 e basiniz.");
		printf("\nSiginmacinin yerlestirildigi sehre gore arama icin  ===>2 ye basiniz.");
		printf("\nSiginmacinin meslegine gore arama icin              ===>3 e basiniz.");
		printf("\nAna menuya donmek icin                              ===>0 a basiniz.");
		printf("\n\n\nSeciminiz :");
		scanf("%s",secim);

		if(strcmp(secim,"1")==0)
		{
			char kontrol[20];
			int count=0;
				system("CLS");
				printf("Siginmacinin geldigi sehri giriniz:\n");
				scanf("%s",kontrol);			
				
				
					FILE *dd;
					if((dd=fopen("siginmacilar.txt","r"))!=NULL)
					{

						while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
						{
							
							if(strcmp(sgnmc.geldSehir ,kontrol )==0)
							{
									count++;
									printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",kntrl.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
									
							}
						}

						if(count>0)
						{
								printf("Aranilan kriterle eslesen %d kayit bulunmaktadir",count);
								getch();
						}

					}
					fclose (dd);
					if(count==0)
					{
						system("CLS");
						printf("aradiginiz kriterle eslesen kayit bulunmamaktadir...");
					}
			getch();
		}
		else if(strcmp(secim,"2")==0)
		{

			char kontrol[20];
			int count=0;
				system("CLS");
				printf("Siginmacinin yerlestirildigi sehri giriniz:\n");
				scanf("%s",kontrol);			
				
				
					FILE *dd;
					if((dd=fopen("siginmacilar.txt","r"))!=NULL)
					{

						while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
						{
							
							if(strcmp(sgnmc.yerlsehir ,kontrol )==0)
							{
									count++;
									printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",kntrl.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
									
							}
						}

						if(count>0)
						{
								printf("\n\nAranilan kriterle eslesen %d kayit bulunmaktadir",count);
								getch();
						}

					}
					fclose (dd);
					if(count==0)
					{
						system("CLS");
						printf("aradiginiz kriterle eslesen kayit bulunmamaktadir...");
					}
			getch();
		}
		else if(strcmp(secim,"3")==0)
		{
			char kontrol[20];
			int count=0;
				system("CLS");
				printf("Siginmacinin meslegini giriniz:\n");
				scanf("%s",kontrol);			
				
				
					FILE *dd;
					if((dd=fopen("siginmacilar.txt","r"))!=NULL)
					{

						while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
						{
							
							if(strcmp(sgnmc.meslek ,kontrol )==0)
							{
									count++;
									printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",kntrl.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);
									
							}
						}

						if(count>0)
						{
								printf("\n\nAranilan kriterle eslesen %d kayit bulunmaktadir",count);
								getch();
						}

					}
					fclose (dd);
					if(count==0)
					{
						system("CLS");
						printf("aradiginiz kriterle eslesen kayit bulunmamaktadir...");
					}
			getch();
		}
		else if(strcmp(secim,"0")==0)
		{
			break;
		}
		else
		{
			printf("Lutfen tanimli degerleri kullaniniz...");
			getch();
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////       
void siginmaciGoruntuleme()
{
	FILE *dd;
	dd=fopen("siginmacilar.txt","r");
	system ("CLS");
	printf ("\2\2\2\2\2\2GORUNTULEME MENUSU\2\2\2\2\2\2\n\n\n");
	if(dd!=NULL)
	{
		while(fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta)!=EOF)
		{

			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",sgnmc.siginmaciNo ,sgnmc.ad,sgnmc.soyad,sgnmc.dogumYeri,sgnmc.dogumTarihi,sgnmc.cinsiyet,sgnmc.uyruk,sgnmc.meslek,sgnmc.egitimDurum,sgnmc.tel,sgnmc.yerlsehir,sgnmc.geldSehir,sgnmc.gelisTarihi,sgnmc.ePosta);


		}
	}
	
	else
	{
		printf("Dosya bulunamadi...");
	}
	
	fclose (dd);
	getch();
}

////////////Menuler///////////////////

void adminMenu()
{
	 	
	for(;;)
	{  
		system("CLS");
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
		printf("\t\t\t\1\1\1\=>\tADMIN ANA MENU\t\<=\1\1\1\n");
		printf("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");		
		printf("\n Sisteme giris icin belirtilen islemlerden birini seciniz:\n\n");	

		printf("Kullanici islemleri icin 1 i seçiniz:\n");
		printf("Siginmaci islemleri icin 2 i seçiniz:\n");
		printf("Cikis icin 0 giriniz:\n");

		char secim[10];


		printf("Luften seciminizi giriniz:\n");
		scanf ("%s",secim);
		if(strcmp(secim,"1")==0)//////////////////////////////////////////////////////kullanýcý islemleri
		{

			for(;;)
			{
				system("CLS");
			printf("Kullanici eklemek icin            => 1'i giriniz:\n");
			printf("Kullanici goruntuleme icin        => 2'yi giriniz:\n");			
			printf("Kullanici silmek icin             => 3'u giriniz:\n");
			printf("Kullanici guncellemek icin        => 4'u giriniz:\n");
			printf("Kullanici aramak icin             => 5'i giriniz:\n");
			printf("Kullanici sifre degistirmek icin  => 6'yi giriniz:\n");
			printf("Cikis icin                        => 0 i giriniz:\n");

			char secim1[10];
			scanf("%s",secim1);
			if (strcmp(secim1,"1")==0)
			{
				kullaniciEkleme();
			}
			else if (strcmp(secim1,"2")==0)
			{
				kullaniciGoruntuleme();				
			}
			else if (strcmp(secim1,"3")==0)
			{
				kullaniciSilme();
			}
			else if (strcmp(secim1,"4")==0)
			{
				kullaniciGuncelleme();
			}
			else if (strcmp(secim1,"5")==0)
			{
				kullaniciArama();
			}
			else if (strcmp(secim1,"6")==0)
			{
				kullaniciSifreDegistir();
			}
			else if (strcmp(secim1,"0")==0)
			{
				
				break ;
			}
			else{
				printf("Lütfen tanimli secim giriniz...\n");
				getch();
			}
		  }
		}

		//////////////////////////////////////////////////////// SIGINMACI ÝSLEMLERÝ
		else if(strcmp(secim,"2")==0)
		{
			system("CLS");
			printf("\nSiginmaci eklemek icin    => 1'i giriniz:\t");
			printf("\nSiginmaci goruntuleme icin=> 2'i giriniz:\t");			
			printf("\nSiginmaci silmek icin     => 3'u giriniz:\t");
			printf("\nSiginmaci guncellemek icin=> 4'u giriniz:\t");
			printf("\nSiginmaci aramak icin     => 5'u giriniz:\t");
			printf("\nCikis icin => 0 i giriniz:\t");
			char secim1[10];
			scanf("%s",secim1);

			if (strcmp(secim1,"1")==0)
			{
				siginmaciEkleme();
			}
			else if (strcmp(secim1,"2")==0)
			{
				siginmaciGoruntuleme();				
			}
			else if (strcmp(secim1,"3")==0)
			{
				siginmaciSilme();
			}
			else if (strcmp(secim1,"4")==0)
			{
				siginmaciGuncellme();
			}
			else if (strcmp(secim1,"5")==0)
			{
				siginmaciArama();
			}
			else if (strcmp(secim1,"0")==0)
			{
				break ;
			}
			else
				{printf("Lutfen tanimli secim giriniz...");
			getch();
			}

		}
		//////////////////////////////////////////////////////////////////////////////////////////
		else if (strcmp(secim,"0")==0)
		{
			break;
		}

		else

			printf("Lutfen tanimli secim giriniz...");
		getch();

	}
}
/////////////////////////////////////////////////////////////////////////////
void kullaniciMenu()
{
	for(;;)

	{
		system("CLS");
		printf("Kullanici goruntulemek icin    =>1 i seciniz:\n");
		printf("Kullanici sifre degistirme icin=>2 i seciniz:\n");
		printf("Siginmaci goruntulemek icin    =>3 u seciniz:\n");
		printf("Cikis yapmak icin  => 0 i seciniz:\n");
		char secim[10];
		scanf("%s",secim);
		if (strcmp(secim,"1")==0)
		{
			kullaniciGoruntuleme();
		}
		else if (strcmp(secim,"2")==0)
		{
			kullaniciSifreDegistir();

		}
		else if (strcmp(secim,"3")==0)
		{
			siginmaciGoruntuleme();
		}
		else if (strcmp(secim,"0")==0)
		{
			break;
		}
		else 

		{
			printf("\nLütfen tanýmlý secim giriniz...\n");

		}
	}




}
////////////////////////////////////////////////////////////////////////////////
void siginmaciMemurMenu()
{
	for (;;)
	{
		system("CLS");
		printf("Kullanici goruntuleme icin=> 1'i giriniz:\n");
		printf("Siginmaci goruntuleme icin=> 2'i giriniz:\n");
		printf("Siginmaci eklemek icin    => 3'i giriniz:\n");
		printf("Siginmaci silmek icin     => 4'u giriniz:\n");
		printf("Siginmaci guncellemek icin=> 5'u giriniz:\n");
		printf("Siginmaci aramak icin     => 6'u giriniz:\n");
		printf("Cikis icin => 0 i giriniz:\n");
		char secim1[10];
		scanf("%s",secim1);

		if (strcmp(secim1,"1")==0)
		{
			kullaniciGoruntuleme();
		}
		else if (strcmp(secim1,"2")==0)
		{
			siginmaciGoruntuleme();

		}
		else if (strcmp(secim1,"3")==0)
		{siginmaciEkleme();

		}
		else if (strcmp(secim1,"4")==0)
		{
			siginmaciSilme();

		}
		else if (strcmp(secim1,"5")==0)
		{siginmaciGuncellme();

		}
		else if(strcmp(secim1,"6")==0)
		{
			siginmaciArama();
		}
		else if (strcmp(secim1,"0")==0)
		{
			break ;
		}
		else
			printf("Lutfen tanimli secim giriniz...");



	}

}
/////////////////////////////////////////////////////////////////////////////////



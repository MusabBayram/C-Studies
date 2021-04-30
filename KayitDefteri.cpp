#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>

void menu();
void ekle();
void goruntule();
void arama();
void Sil(char ad[20]);
void guncelle(char ad[20]);

char cevap, isim[30];//cevap deðiþkeni kullanýcadan iþlem devamýný almak icin kullanýlmýþtýr.isim deðiþkeni sil ve guncelleiçin kullanýldý 

struct bilgiler
{
	char ad[20];
	char soyad[20];
	char eposta[50];
	char evtel[12];
	char ceptel[12];
	char istel[12];
	char dogumtarihi[12];
	char mahalle[50];
	char il[20];
	char ilce[20];	
	int sokakno;
}bilgi;

main()
{
	int islem,cikis=0;
	while(cikis==0)
	{
		menu();
		scanf("%d",&islem);
		switch(islem)
		{
			case 1:
			{
				ekle();
				break;
			}
			case 2:
			{
				goruntule();
				break;
			}
				case 3:
				{
					printf("Guncellenicek ismi giriniz:");
					_flushall();
					gets(isim);
					guncelle(isim);
					break;
				}
				case 4:
				{
					printf("Silinecek kayit adi ? :");
					_flushall();
					gets(isim);
					Sil(isim);
					break;
				}
				case 5:
				{
					arama();
					break;
				}
				case 6:
				{
					cikis=1;
					break;
				}
				default:
					printf("\n");
					printf("Yanlis secim yaptiniz.");
		}
	}
}

void menu()
{
	printf("YAPMAK ISTEDIGINIZ ISLEMIN RAKAMINI GIRINIZ: \n");
	printf("1-KISI EKLE\n");
	printf("2-GORUNTULE\n");
	printf("3-GUNCELLE\n");
	printf("4-SIL\n");
	printf("5-ARAMA(ad,soyad,adres,dogum tarihi vb.)\n");
	printf("6-PROGRAMI SONLANDIR\n");
}

void ekle()
{
	FILE *dd;
	dd=fopen("D:\\rehber.txt","a");
		if(dd==NULL)
			printf("Surucu bulunamadi.\n");
			else
			{
				printf("Kisinin adini giriniz: \n");
				scanf("%s", &bilgi.ad);
				fprintf(dd,"%s\n",bilgi.ad);
				printf("\n");
				printf("%s'nin soyadini giriniz: \n",bilgi.ad);
				scanf("%s", &bilgi.soyad);
				fprintf(dd,"%s\n",bilgi.soyad);
				printf("\n");
				printf("%s'nin dogum tarihini giriniz: \n",bilgi.ad);
				scanf("%s",&bilgi.dogumtarihi);
				fprintf(dd,"%s\n",bilgi.dogumtarihi);
				printf("\n");
				printf("%s'nin epostasini giriniz: \n", bilgi.ad);
				scanf("%s", &bilgi.eposta);
				fprintf(dd,"%s\n",bilgi.eposta);
				printf("\n");
				printf("%s'nin ev telefonunu giriniz: \n", bilgi.ad);
				scanf("%s",&bilgi.evtel);
				fprintf(dd,"%s\n",bilgi.evtel);
				printf("\n");
				printf("%s'nin cep telefonunu giriniz: \n",bilgi.ad);
				scanf("%s",&bilgi.ceptel);		
				fprintf(dd,"%s\n",bilgi.ceptel);
				printf("\n");
				printf("%s'nin is telefonunu giriniz: \n",bilgi.ad);
				scanf("%s",&bilgi.istel);
				fprintf(dd,"%s\n",bilgi.istel);
				printf("\n");
				printf("**%s'nin adres bilgileri** \n",bilgi.ad);
				printf("%s hangi ilde yasamaktadir? \n",bilgi.ad);
				scanf("%s",&bilgi.il);
				fprintf(dd,"%s\n",bilgi.il);
				printf("\n");
				printf("%s'in hangi ilcesinde ikamet etmekte?\n ", bilgi.il);
				scanf("%s", &bilgi.ilce);
				fprintf(dd,"%s\n",bilgi.ilce);
				printf("\n");
				printf("%s'nin hangi mahallesinde oturmakta?\n ", bilgi.ilce);
				scanf("%s", &bilgi.mahalle);
				fprintf(dd,"%s\n",bilgi.mahalle);
				printf("\n");
				printf("%s'in hangi sokaginda oturmaktadir?\n", bilgi.mahalle);
				scanf("%d",&bilgi.sokakno);
				fprintf(dd,"%d\n",bilgi.sokakno);
				printf("\n");
			}
		fclose(dd);
}


void goruntule()
{
	printf("REHBER GORUNTULENIYOR...\n\n\n");
	FILE *dd;
	dd=fopen("D:\\rehber.txt","r");
	int c;	
	printf("\n**==================**\n\n");
	while(!feof(dd))
	{
		c=getc(dd);
		putchar(c);
	}
	printf("\n**==================**\n\n");
		fclose(dd);
}

void arama()
{
	int x;
	FILE *dd;
	dd=fopen("D:\\rehber.txt","r");
	if(dd==NULL)
	printf("Surucu bulunamadi.\n");
	else
	{
		printf("\nARAMA YAPMAK ISTEDIGINIZ TURU SECINIZ: \n");
		printf("1-AD \n");
		printf("2-SOYAD\n");
		printf("3-DOGUM TARIHI\n");
		printf("4-E-POSTA\n");
		printf("5-EV TELEFONU\n");
		printf("6-CEP TELEFONU\n");
		printf("7-IS TELEFONU\n");
		printf("8-IL\n");
		printf("9-ILCE\n");
		printf("10-MAHALLE\n");
		printf("11-SOKAK\n");
		int a;
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			{
				rewind(dd);
					printf("Aramak istediginiz ismi giriniz:\n");
					scanf("%s",x);
					printf("Isim araniyor...\n\n");
					sleep(1);
				while (!feof(dd))
				{
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);				
					
					if(strcmp(x,&bilgi.ad)==0)
					{
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI: %s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n\n",bilgi.sokakno);
					
					}
				}
				break;
			}
			case 2:
			{
				while (fscanf(dd, "%s", &bilgi.soyad) != EOF)
				{
					printf("Aramak istediginiz soyadi giriniz:\n");
					scanf("%s",&bilgi.soyad);
					printf("Soyad araniyor...\n\n");				
					sleep(1);
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
			case 3:
			{
				while (fscanf(dd, "%s", &bilgi.dogumtarihi) != EOF)
				{
					printf("Aramak istediginiz dogum tarihini giriniz:\n");
					scanf("%s",&bilgi.dogumtarihi);
					printf("Dogum tarihi araniyor...\n\n");
					sleep(1);
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
			case 4:
			{
				while (fscanf(dd, "%s", &bilgi.eposta) != EOF)
				{
					printf("Aramak istediginiz e-postayi giriniz:\n");
					scanf("%s",&bilgi.eposta);
					printf("E-posta araniyor...\n\n");
					sleep(1);
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
			case 5:
			{
				while (fscanf(dd, "%s", &bilgi.evtel) != EOF)
				{
					printf("Aramak istediginiz ev telefonunu giriniz:\n");
					scanf("%s",&bilgi.evtel);
					printf("Ev telefonu araniyor...\n\n");
					sleep(1);
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}	
				break;
			}
			case 6:
			{
				while (fscanf(dd, "%s", &bilgi.ceptel) != EOF)
				{
					printf("Aramak istediginiz cep telefonunu giriniz:\n");
					scanf("%s",&bilgi.ceptel);
					printf("Cep telefonu araniyor...\n\n");
					sleep(1);
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);		
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}	
				break;
			}
			case 7:
			{
				while (fscanf(dd, "%s", &bilgi.istel) != EOF)
				{
					printf("Aramak istediginiz is telefonunu giriniz:\n");
					scanf("%s",&bilgi.istel);
					printf("Is telefonu araniyor...\n\n");
					sleep(1);	
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
			case 8:
			{
				while (fscanf(dd, "%s", &bilgi.il) != EOF)
				{
					printf("Aramak istediginiz ili giriniz:\n");
					scanf("%s",&bilgi.il);
					printf("Il araniyor...\n\n");
					sleep(1);
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
			case 9: 
			{
				while (fscanf(dd, "%s", &bilgi.ilce) != EOF)
				{
					printf("Aramak istediginiz ilceyi giriniz:\n");
					scanf("%s",&bilgi.ilce);
					printf("Ilce araniyor...\n\n");
					sleep(1);	
					fscanf(dd,"%s%s%s%s%s%s%s%s%s%s%d",&bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno);
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
			case 10:
			{
				while (	fscanf(dd,"%s",&bilgi.mahalle) != EOF)
				{
					printf("Aramak istediginiz mahalleyi giriniz:\n");
					scanf("%s",&bilgi.mahalle);
					printf("Mahalle araniyor...\n\n");
					sleep(1);
					fscanf(dd, "%s %s %s %s %s %s %s %s %s %s %d", &bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno );
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
			case 11:
			{
				while (fscanf(dd, "%s", &bilgi.sokakno) != EOF)
				{
					printf("Aramak istediginiz sokak numarasini giriniz:\n");
					scanf("%d",&bilgi.sokakno);			
					printf("Sokak numarasi araniyor...\n\n");
					sleep(1);
					fscanf(dd, "%s %s %s %s %s %s %s %s %s %s %d", &bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno );
					printf("\tADI: %s\n",bilgi.ad);
					printf("\tSOYADI%s\n",bilgi.soyad);
					printf("\tDOGUM TARIHI: %s\n",bilgi.dogumtarihi);
					printf("\tE-POSTASI: %s\n",bilgi.eposta);
					printf("\tEV TELEFONU: %s\n",bilgi.evtel);
					printf("\tCEP TELEFONU: %s\n",bilgi.ceptel);
					printf("\tIS TELEFONU: %s\n",bilgi.istel);
					printf("\tIL: %s\n",bilgi.il);
					printf("\tILCE: %s\n",bilgi.ilce);
					printf("\tMAHALLE: %s\n",bilgi.mahalle);
					printf("\tSOKAK NO: %d\n",bilgi.sokakno);
					break;
				}
				break;
			}
		}
	}
		fclose(dd);
}




void Sil(char ad[20])
{

	system("cls");
	FILE *dd, *yeni;
	int a = 0;
	dd = fopen("D:\\rehber.txt", "r");//okuma modunda açýldý
	yeni = fopen("D:\\Rehber1.txt", "w");//yazma modunda açýldý
	if (dd == NULL)
	{
		printf("Suan rehberinizde hicbir kisi ekli degil!");
	}
	else
	{
		rewind(dd);
		rewind(yeni);
		printf("\n%s Kisisini silmek istiyormusunuz! (E)-(H)\n", isim);//kiþi  uyarýldý
		cevap = _getch();
		if (cevap == 'E' || cevap == 'e')
		{
			while (!feof(dd))//dosya sonuna kadar okutuldu ve dosyaptr dosyadan bilgiler alýndý
			{
				fscanf(dd, "%s %s %s %s %s %s %s %s %s %s %d", &bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno );
				if (!strcmp(bilgi.ad, isim))//Dosyadaki tüm adlarý tarar ve girilen isim ile eþitse bu kýsýma girer ve bu kiþi hariç diðer kiþileri yeni dosyaya yazar böylece kiþi silinmiþ olur.
				{
					printf("\nSilinen Kisi Bilgileri\n");
					printf("------------------------\n");
					printf("Ad:\t%s\nSoyad:  %s\nDogum tarihi: %s\ne-posta:  %s\nEvTel:  %s\nCepTel: %s\n IsTel:  %s\nIl: %s\n  Ilce: %s\n  mahalle: %s\n   sokakno:%d\n", bilgi.dogumtarihi ,bilgi.eposta ,bilgi.evtel ,bilgi.ceptel ,bilgi.istel,bilgi.il,bilgi.ilce,bilgi.mahalle, bilgi.sokakno);
					printf("\nKisi silindi...");
					a = 1;
				}
				else//bu kýsýmada kiþi yoksa girer böylece tüm dosyaptr bilgiler deðiþtirilmeden yeni metin belgesine yazdýrýlmýþ olur
					fprintf(yeni, "%s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %d\t  \n", bilgi.ad, bilgi.soyad,bilgi.dogumtarihi ,bilgi.eposta ,bilgi.evtel ,bilgi.ceptel ,bilgi.istel,bilgi.il,bilgi.ilce,bilgi.mahalle, bilgi.sokakno );
			}
			_fcloseall();//Tüm dosyalar kapatýldý
			remove("rehber.txt");//Rehber.txt dosyasý silindi	
			rename("Rehber1.txt", "rehber.txt");//Yeni açýlan Rehber1 dosyasý Rehber olarak yeniden adlandýrýldý
			if (a == 0)
				printf("\nBu kisi rehberde kayitli degil!\n");
		}
	}
}


void guncelle(char ad[20])
{
	FILE *dd, *yeni;
	int k = 0;//Kiþinin rehberde olup olmadýðý sorgulanmak amacý ile tanýmlandý
	system("cls");
	dd = fopen("D:\\rehber.txt", "r");//2 dosya açýlmasýnýn sebebi güncellenicek ad hariç diyer bilgiler temp bir dosyaya 
	yeni = fopen("D:\\Rehber1.txt", "w");//yazdýrýlýr.  
	if (dd == NULL)
	{
		printf("Suan rehberinizde hicbir kisi ekli degil!");
	}
	else
	{
		rewind(dd);//dosya imlecini dosya baþýna alýr
		rewind(yeni);
		while (!feof(dd))//dosya sonuna kadar tarama yapar
		{
				fscanf(dd, "%s %s %s %s %s %s %s %s %s %s %d", &bilgi.ad, &bilgi.soyad,&bilgi.dogumtarihi ,&bilgi.eposta ,&bilgi.evtel ,&bilgi.ceptel ,&bilgi.istel,&bilgi.il,&bilgi.ilce,&bilgi.mahalle, &bilgi.sokakno );
			if (strcmp(bilgi.ad, ad) == 0)
			{
				k = 1;
				printf("\nGuncellenen Kisi Bilgileri\n");
				printf("-------------------------\n");
				printf("\tAd: ");
				scanf("%s", bilgi.ad);
				printf("\tSoyad: ");
				scanf("%s", bilgi.soyad);	
				printf("\tDogum tarihi: ");
				scanf("%s", &bilgi.dogumtarihi);
				printf("\tE-posta: ");
				scanf("%s", &bilgi.eposta);	
				printf("\tEv Tel No: ");
				scanf("%s", &bilgi.evtel);
				printf("\tCep Tel No: ");
				scanf("%s", &bilgi.ceptel);
				printf("\tIs Tel No: ");
				scanf("%s", &bilgi.istel);	
				printf("\tIl: ");
				scanf("%s", &bilgi.il);
				printf("\tIlce: ");
				scanf("%s", &bilgi.ilce);
				printf("\tMahalle: ");
				scanf("%s", &bilgi.mahalle);
				printf("\tSokak No: ");
				scanf("%d", &bilgi.sokakno);
				printf("\nKisi guncellendi.\n\n");
				fprintf(yeni, "%s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %d\t  \n", bilgi.ad, bilgi.soyad,bilgi.dogumtarihi ,bilgi.eposta ,bilgi.evtel ,bilgi.ceptel ,bilgi.istel,bilgi.il,bilgi.ilce,bilgi.mahalle, bilgi.sokakno );
			}//Güncellenicek kiþi dosyada tespit edilmiþse yeni bilgiler alýnýr ve dosyaya yazdýrýlýr eðer kiþi dosyada yok ise o dosyaptr bilgiler olduðu gibi yeni dosyaya yazdýrýlýr.	
			else
				fprintf(yeni, "%s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %d\t  \n", bilgi.ad, bilgi.soyad,bilgi.dogumtarihi ,bilgi.eposta ,bilgi.evtel ,bilgi.ceptel ,bilgi.istel,bilgi.il,bilgi.ilce,bilgi.mahalle, bilgi.sokakno );
		}
		_fcloseall();//tüm dosyalarý kapatýr
		remove("D:\\rehber.txt");//Ýlk txt dosyaysý silinir
		rename("D:\\Rehber1.txt", "D:\\rehber.txt");//yeni txt dosyasýnýn adý deðiþtirilir ve ilk txt dosyasýnýn adý yapýlýr.
		if (k == 0)
			printf("Bu kisi rehberde kayitli degildir...\n");
	}
}

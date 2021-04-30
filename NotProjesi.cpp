#include <stdio.h>
#include <math.h>

int N;		//N öðrenci sayýsýný genel olarak tanýmladým.
// öðrenci sýralamalarda falan sorun yasamamak için öðrenci bilgilerini struct olarak aldým
struct ogrenci{
	int no;
	int notu;
};
//burda fonksiyonlarý tanýmladým
struct ogrenci ogr[BUFSIZ];
void giris();
float ortalama();
void goruntule();
float CanOrtalama();
int otele();
void NoSiralama();
void NotSiralama();
void YatayHis();
void DikeyHis();
float standartS();


main()
{ 
	//tanýmlar:
	int  fark;
	int OgrNo[BUFSIZ], BNotu[BUFSIZ];
	float ort, ortiki;
	printf("Ogrenci sayisini giriniz: ");
	scanf("%d", &N);
	
	giris();				//öðrencilerin bilgilerini aldýðýmýz kýsým
	ort = ortalama();		//genel ortalamayý burda alýyoruz
	goruntule();			//ilk verilen bilgilerle görüntülediðimiz kýsým
	ortiki = CanOrtalama();	//CanOrtalama notu 20 nin üzerindeki öðrencilerin not ortalamasýný alan fonksiyon
	NoSiralama(); 			//öðrencileri numaralarýna göre sýralayan kýsým
	printf("-----------------------------------------------------");
	printf("\nOgrenci no ya gore siralanan notlar\n");
	printf("-----------------------------------------------------");
	goruntule();		//öðrenci numarasýna göre sýralandýktan sonraki görüntüleme
	if(ortiki<50)		//CanOrtalama eðer 50 nin altýndaysa altýndaki iþlemleri yapar
	{
	otele();			//bu öteleme CanOrtalamanýn 50 nin ne kadar altýndaysa o kadar 30 notunun üzerindeki öðrencilere ekler
	printf("-----------------------------------------------------");
	printf("\n otelenme ile notlar:\n");
	printf("-----------------------------------------------------\n");
	goruntule();		//yeni ötelenmiþ notlarla gösterilen kýsým
	}
	NotSiralama(); 		//öðrencileri notlarýna göre sýlayan kýsým
	printf("-----------------------------------------------------");
	printf("\n ogrenci notuna gore siralanmis notlar:\n");
	printf("-----------------------------------------------------\n");
	goruntule();		//öðrencilerin notlarýna göre sýralandýktan sonraki görüntüleme
	printf("Not ortalamasi: %5.2f\n", ort);
	printf("Notu 20 nin uzerindeki ogrencilerin not ortalamasi: %5.2f\n", ortiki);
	standartS();		//standart sapma fonksiyonunu cagýrdýgým kýsým
	printf("standart sapma:%5.2f", standartS());
	YatayHis();		//yatay histogram fonksiyonunu çaðýrdýðým kýsým
	DikeyHis();		//dikey histogramý çaðýrdýkðým kýsým
	
}
//öðrencilerin bilgilerinin alýndýðý fonksiyon
void giris()
{
	int i;
	for (i=0; i<N; i++)
	{ 
		printf("Ogrenci no gir: ");
		scanf("%d", &ogr[i].no);
		printf("%d numarali ogrencinin basari notunu gir : ", ogr[i].no);
		scanf("%d", &ogr[i].notu);
	}
}
//verileri kullanýcýya gösteren fonksiyon
void goruntule()
{
	printf("\nOgrenci#\tNotu\n");
	for (int i=0; i<N; i++)
		printf("%8d\t%3d\n", ogr[i].no, ogr[i].notu);
}
//genel ortalamanýn alýndýðý fonksiyon
float ortalama()
{
	float t;
	int i;
	t = 0;
	for (i=0; i<N; i++)
		t = t + ogr[i].notu;
	float ort = t / N;
	
	return ort;
}
//notu 20 nin üstünde olan öðrencilerin notlarýnýn ortalamasýný hesaplayan fonksiyon
float CanOrtalama()
{
	float t, ortiki;
	int i, z=0;
	t = 0;
	for(i=0; i<N; i++)
	{
		if(ogr[i].notu>=20)
		{
			z++;
			t = t + ogr[i].notu;	
		}
	}
	ortiki = t / z;
	return ortiki;
}
//istenilen ötelemeyi yapan fonksiyon
int otele()
{
	int fark=0;
		float t, ortiki;
	int i, z=0;
	t = 0;
	for(i=0; i<N; i++)
	{
		if(ogr[i].notu>=20)
		{
			z++;
			t = t + ogr[i].notu;
		
		}
	}
	ortiki = t / z;
		fark = 50 - ortiki;
		for(int i=0; i<N; i++)
			if(ogr[i].notu>=30)
				ogr[i].notu = ogr[i].notu + fark;
	
}
//öðrenci numarasýna göre sýralama
void NoSiralama()
{
     int temp_no,temp_not;
     int i, j;
 
     for (i=1; i<N; i++)
     {
         for (j=0; j<N-i; j++)
         {
             if(ogr[j].no > ogr[j+1].no)
             {
                    temp_no = ogr[j].no;
                    temp_not=ogr[j].notu;
                    ogr[j].no = ogr[j+1].no;
                    ogr[j].notu=ogr[j+1].notu;
                    ogr[j+1].no = temp_no;
                    ogr[j+1].notu=temp_not;
             }
         }
     }
}
//ogrenci notuna göre sýralama
void NotSiralama()
{
     int temp_not,temp_no;
     int i, j;
 
     for (i=1; i<N; i++)
     {
         for (j=0; j<N-i; j++)
         {
             if(ogr[j].notu > ogr[j+1].notu)
             {
                        temp_not = ogr[j].notu;
                        temp_no=ogr[j].no;
                        ogr[j].notu = ogr[j+1].notu;
                        ogr[j].no = ogr[j+1].no;
                        ogr[j+1].notu = temp_not;
                        ogr[j+1].no = temp_no;
             }
         }
     }
}

//Yatay histogram
void YatayHis()
{
	int sayac[10],max=0;
	for(int i=0;i<10;i++){
		sayac[i]=0;
	}
	printf("\n\n\tYatay Histogram\n");
	printf("\n\tA1|");
	//bu sayac bize histogramdaki yýldýzlarýn sayýsýna göre kaç stun ilerlediðini belirtmede yardýmcý oluyor
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=90){
		printf(" *");
		sayac[0]++;
		}
	
	printf("\n\tA2|");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=80 && ogr[i].notu<90){
		printf(" *");
		sayac[1]++;
		}
	
	printf("\n\tB1|");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=75 && ogr[i].notu<80){
		printf(" *");
		sayac[2]++;
		}
	
	printf("\n\tB2|");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=70 && ogr[i].notu<75){
		printf(" *");
		sayac[3]++;
		}
		
	printf("\n\tC1|");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=65 && ogr[i].notu<70){
		printf(" *");
		sayac[4]++;
		}
		
	printf("\n\tC2|");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=60 && ogr[i].notu<65){
		printf(" *");
		sayac[5]++;
		}
		
	printf("\n\tD1|");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=55 && ogr[i].notu<60){
		printf(" *");
		sayac[6]++;
		}
		
	printf("\n\tD2|");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=50 && ogr[i].notu<55){
		printf(" *");
		sayac[7]++;
		}
		
	printf("\n\tE |");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=40 && ogr[i].notu<50){
		printf(" *");
		sayac[8]++;
		}
		
	printf("\n\tF |");
	for(int i=0; i<N; i++)
		if (ogr[i].notu>=0 && ogr[i].notu<40){
		printf(" *");
		sayac[9]++;
		}
		for(int i=0;i<10;i++){
			if(sayac[i] >= max){
				max=sayac[i];
			}
		}
	printf("\n\t    ");
	for(int i=0;i<max;i++){
		printf("%d ",i+1);
	}
}
//Dikey histogram
void DikeyHis()
{
	printf("\n\n\tDikey Histogram\n");
	int  A1=0,A2=0,B1=0,B2=0,C1=0,C2=0,D1=0,D2=0,E=0,F=0, max=0;
	for(int i=0; i<N; i++)		//bu ksýýmda ilk önce hangi not aralýðýnda kaç kiþi oldugu hesaplanýyor
	{
		if (ogr[i].notu>=90)
			A1++;
		if (ogr[i].notu>=80 && ogr[i].notu<90)
			A2++;
		if (ogr[i].notu>=75 && ogr[i].notu<80)
			B1++;
		if (ogr[i].notu>=70 && ogr[i].notu<75)
			B2++;
		if (ogr[i].notu>=65 && ogr[i].notu<70)
			C1++;
		if (ogr[i].notu>=60 && ogr[i].notu<65)
			C2++;
		if (ogr[i].notu>=55 && ogr[i].notu<60)
			D1++;
		if (ogr[i].notu>=50 && ogr[i].notu<55)
			D2++;
		if (ogr[i].notu>=40 && ogr[i].notu<50)
			E++;
		if (ogr[i].notu>=0 && ogr[i].notu<40)
			F++;
	}
	//bu kýsým hangi nottan en fazla alýndýgýný buluyor sonrasýnda bunu histogramda sayý iler belirtilen kýsýmý oluþturmak için kullandým
	if(A1>max)
		max=A1;
	if(A2>max)
		max=A2;
	if(B1>max)
		max=B1;
	if(B2>max)
		max=B2;
	if(C1>max)
		max=C1;
	if(C2>max)
		max=C2;
	if(D1>max)
		max=D1;
	if(D2>max)
		max=D2;
	if(E>max)
		max=E;
	if(F>max)
		max=F;
	for(int i=max; i>0; i--)
	{
		printf("\n\t%d", i);
		if(A1==i)
		{
			printf(" **");
			A1--;
		}
		else
			printf("   ");
			
		if(A2==i)
		{
			printf(" **");
			A2--;
		}
		else
			printf("   ");
			
		if(B1==i)
		{
			printf(" **");
			B1--;
		}
		else
			printf("   ");
			
		if(B2==i)
		{
			printf(" **");
			B2--;
		}
		else
			printf("   ");
			
		if(C1==i)
		{
			printf(" **");
			C1--;
		}
		else
			printf("   ");
			
		if(C2==i)
		{
			printf(" **");
			C2--;
		}
		else
			printf("   ");
			
		if(D1==i)
		{
			printf(" **");
			D1--;
		}
		else
			printf("   ");
			
		if(D2==i)
		{
			printf(" **");
			D2--;
		}
		else
			printf("   ");
	
		if(E==i)
		{
			printf(" **");
			E--;
		}
		else
			printf("   ");	
			
		if(F==i)
		{
			printf(" **");
			F--;
		}
		else
			printf("   ");
		printf("|");
	}
	printf("\n\t+-------------------------------\n");
	printf("   \t  A1 A2 B1 B2 C1 C2 D1 D2 E  F ");

}

//Standtart sapma
float standartS()
{	
	float sonuc=0.0, ort;
	ort = ortalama();
	for(int i=1; i<N; i++)
	{
		sonuc+= pow((ort-ogr[i].notu),2.0);
	}
	sonuc = sqrt(sonuc/(N-1));
	return sonuc;
}

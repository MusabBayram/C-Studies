#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 100

struct list_type {
    char adi[10];
    char soyadi[10];
    char sehir[12];
    char telefon[11];
} list[SIZE];

int menu(void);
void init_list(void);
void enter(void);
void arama(void);
void iptal(void);
void display(void);
void save(void);
void load(void);

main() 
{
    char choice;
    init_list();

    for(;;) {
    choice = menu();
        switch(choice) {
            case 'i':iptal();break;
            case 'a':arama();break;
            case 'g':enter();break;
            case 'l':display();break;
            case 's':save();break;
            case 'c':load();break;
            case 'q':exit(0);
        }
    }
}

void init_list(void) {
    register int t;
    for(t=0; t<SIZE; t++)
        *list[t].adi = '\0';
}

void enter(void) {
    register int i;
    for(i=0; i<SIZE; i++)
        if (!*list[i].adi) 
            break;
        if (i==SIZE){
            printf("Liste dolu\n");
            return;
        }
    system("CLS");
    printf("Adiniz.....:");
    gets(list[i].adi);
    printf("Soyadi.....:");
    gets(list[i].soyadi);
    printf("Sehir......:");
    gets(list[i].sehir);
    printf("Telefon....:");
    gets(list[i].telefon);
}

void arama(void) {
    char ara[10];
    FILE *fp;
    register int t;
    int a;
    system("CLS");
    printf("\n Aradiginiz Kisinin Adini Giriniz:");
    gets(ara);
    for(t=0;t<SIZE;t++) {
        if (strstr(list[t].adi,ara)) {
            system("CLS");
            printf("\n Adi=%s",list[t].adi);
            printf("\n Soyadi=%s",list[t].soyadi);
            printf("\n Sehir=%s",list[t].sehir);
            printf("\n Telefon=%s",list[t].telefon);
            getch();
        a=1;
        }
    }
    if (a!=1) {
        printf("\n Aradiginiz Kayit Yok");
        getch();
    }
}

void iptal(void) {
    char ara[10];
    register int t;
    int a;
    system("CLS");
    printf("Sileceginiz Kisinin Adini Girin:");
    gets(ara);

    for(t=0;t<SIZE;t++) {
        if(strstr(list[t].adi,ara)) {
            a=1;
            *list[t].adi='\0';
            *list[t].soyadi='\0';
            *list[t].sehir='\0';
            *list[t].telefon='\0';
        }
    }
    if (a!=1) 
        printf("\n Sileceginiz Kayit Bulunamadi");
}

void display(void) {
    register int t;
    for(t=0;t<SIZE;t++) {
        if (*list[t].adi) {
            system("CLS");
            printf("%s \n",list[t].adi);
            printf("%s \n",list[t].soyadi);
            printf("%s \n",list[t].sehir);
            printf("%s \n",list[t].telefon);}}
            getch();
        }
void save(void) {
    FILE *fp;
    register int i;
    if((fp=fopen("maillist","wb"))==NULL) {
        printf("\n dosya acilamiyor\n");
        return;
    }
    for(i=0; i<SIZE; i++)
        if(*list[i].adi)
        if (fwrite(&list[i],sizeof(struct list_type),1,fp) != 1)
            printf("yazma hatasi!\n");
}
void load(void) {
    FILE *fp;register int i;
    if ((fp=fopen("maillist","rb")) == NULL) {
        printf("dosya acilamiyor!\n");
        return;
    }
    init_list();
    for (i=0;i<SIZE;i++)
        if(fread(&list[i],sizeof(struct list_type),1,fp) != 1) {
            if (feof(fp)) return;
            printf("dosya okuma hatasi!\n");}
}

int menu(void) {
    char s[80]; 
    do {
        //textcolor(14);
        //textbackground(1);
        system("CLS");
        gotoxy(23,5);printf("TELEFON DEFTERI");
        gotoxy(25,6);printf("(G)iris\n");
        gotoxy(25,7);printf("(L)istele\n");
        gotoxy(25,8);printf("(C)agir\n");
        gotoxy(25,9);printf("(S)akla\n");
        gotoxy(25,10);printf("(A)rama\n");
        gotoxy(25,11);printf("(I)ptal\n");
        gotoxy(25,12);printf("(C)ikis\n");
        gotoxy(23,13);printf("Seciminiz.:");
        gets(s);
    } while(!strchr("GLCSAIQ",toupper(*s)));
    return(*s);
}

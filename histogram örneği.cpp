#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


main()
{
		char x[20];
		scanf("%s", &x);
		printf("%s ismini girdiniz..", x);
       int zar[20],zar1[6]={0}, max=0;
       srand(time(NULL));
      
       //gelen zarlarý 20 lik diziye attým.
       //1-6 arasý gelen deðerleri 1 eksiðinin indisine gelecek þekilde yeni diziye attým
       for (int i=0; i<20; i++)
       {
             zar[i]=1+rand()%6;
             zar1[zar[i]-1]++;         
       }
      
       //hangi sayýdan kaç tane olduðunu zar1 dizisinden biliyorduk
       //max hangisinden olduðunu buluyoruz þimdide.
       for (int i=0; i<6; i++)
       {
            
           if(max<zar1[i])
                    max=zar1[i];
            
       }
    //çizdirme1
       for(int i=max; i>0; i--)
       {
             printf("\n%d ", i);
             for(int a=0; a<6; a++)
             {
                    if(zar1[a]>=i)
                           printf("**  ");
                    else
                           printf("--  ");

             }
            
       }
       printf("\n-----------------------------\n   1   2   3   4   5   6......Zarlar\n\n");
       //çizdirme2....
       for(int i=0; i<6; i++)
       {
             printf("\n%d.zar| ", i+1);       
             for(int a=0; a<max; a++)
             {
                   
                    if(zar1[i]<=a)
                           printf("--  ");
                    else
                           printf("**  ");

             }
            
       }printf("\n----------------------------\n        ");
       for(int i=0; i<max; i++)
       printf("%d   ",i+1);
      
}


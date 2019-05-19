#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Cihan Çifci 172802019
  Alparslan ÇAY 172802005*/
int main()
{

    int boyut;
    printf("Dizinin boyutunu girin :");
    scanf("%d",&boyut);
    int liste[boyut];
    int i;
    int j;
    float aritmetik_ortalama = 0, geometrik_ortalama=1 , toplam =0;
    for(i=0;i<boyut;i++)
    {
        int sayi;
        printf("%d . elemaný girin : ",i+1);
        scanf("%d",&sayi);
        liste[i] = sayi;
        toplam += liste[i];
    }
    int count = boyut,  temp =0;
    for (i=0;i<boyut-1;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(liste[j]>liste[j+1])
            {
                temp = liste[j];
                liste[j] = liste[j+1];
                liste[j+1]=temp;
            }
        }
        count--;

    }

    aritmetik_ortalama = toplam/boyut;
    printf("\nAritmetik Ortalama = %f ", aritmetik_ortalama);

    int tekrarlanma_sayisi = 0;
    int en_fazla_tekrarlanma = 0;
    int mod = -1;
    for (i=0;i<boyut-1;i++)
    {
        tekrarlanma_sayisi=0;

        for(j=0;j<boyut-1;j++)
        {
            if(liste[i]==liste[j])
            {
               tekrarlanma_sayisi++;
            }
        }

        if (tekrarlanma_sayisi > en_fazla_tekrarlanma)
            {
                en_fazla_tekrarlanma = tekrarlanma_sayisi;
                mod = liste[i];
            }


    }

    printf("\nMOD:%d",mod);
    //Medyan için:
    if (boyut%2==0)
        {
            double medyan=0;
            medyan = (liste[(boyut/2)-1] + liste[boyut/2])/2;

            printf("\nMedyan:%lf",medyan);
        }

    else
        {
            printf("\nMedyan:%lf",liste[(boyut/2)-1]);
        }


        for (i=0;i<boyut;i++)
            {
                geometrik_ortalama*=liste[i];
            }
            double derece = 100 / boyut;
            derece = derece/100;


        printf("\nGeometrik Ortalama: %f",pow(geometrik_ortalama,derece));

        double standart_sapma = 0;

        for (i=0;i<boyut;i++)
            {
               double deger = (liste[i]-aritmetik_ortalama)*(liste[i]-aritmetik_ortalama);
               standart_sapma+=deger;
            }

            printf("\nVaryans:%lf",standart_sapma/(boyut-1));

            standart_sapma = sqrt(standart_sapma/(boyut-1));

            printf("\nStandart sapma:%lf",standart_sapma);


    return 0;
}

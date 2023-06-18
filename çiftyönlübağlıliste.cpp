#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Dugum 
{
    int veri;
    struct Dugum* onceki;
    struct Dugum* sonraki;
};

int ElemanEkle(struct Dugum** ilk, int sayi)
 {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
   
    if (yeniDugum == NULL) 
    {
    	return 0;
	}
	
	yeniDugum->veri = sayi;
    yeniDugum->onceki = NULL;
    yeniDugum->sonraki = NULL;

    if (*ilk == NULL) 
	{
        *ilk = yeniDugum;
        return 1;
    }

    struct Dugum* suanki = *ilk;
    while (suanki->sonraki != NULL) 
	{
        suanki = suanki->sonraki;
    }
    suanki->sonraki = yeniDugum;
    yeniDugum->onceki = suanki;

    return 1;
}

void degistir(struct Dugum** ilk) 
{
    if (*ilk == NULL || (*ilk)->sonraki == NULL) 
	return;

    struct Dugum* ilkDugum = *ilk;
    struct Dugum* sonDugum = *ilk;

    while (sonDugum->sonraki != NULL)
	 {
        sonDugum = sonDugum->sonraki;
    }

    while (ilkDugum != sonDugum && ilkDugum->onceki != sonDugum) 
	{
        if (ilkDugum->veri < sonDugum->veri) 
		{
            int temp = ilkDugum->veri;
            ilkDugum->veri = sonDugum->veri;
            sonDugum->veri = temp;
        }

        ilkDugum = ilkDugum->sonraki;
        sonDugum = sonDugum->onceki;
    }
}

void yazdir(struct Dugum* ilk) 
{
    while (ilk != NULL) 
	{
        printf("%d ", ilk->veri);
        ilk = ilk->sonraki;
    }
    printf("\n");
}

int main() 
{
    struct Dugum* ilk = NULL;
    int n, i;
    srand(time(NULL));

    printf("Kac sayi istersiniz: ");
    scanf("%d", &n);

      do 
	  {
        int sayi;
        sayi = rand() % 51;
        if (!ElemanEkle(&ilk, sayi)) 
		{
            printf("sayi eklenemiyor \n");
            return 1;
        }
        i++;
    } while (i < n);

    printf("listenin ilk hali : ");
    yazdir(ilk);

    degistir(&ilk);

    printf("Listenin son hali: ");
    yazdir(ilk);

    return 0;
}

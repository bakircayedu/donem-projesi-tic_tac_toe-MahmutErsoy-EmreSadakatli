#include <stdio.h>
#include <stdlib.h>

void oyun_tahtasi(void);
int kazanan_kontrolu(void);

int a[3][3] = {0};

struct kayit
{
	char isim1[100];
	char isim2[100];
	int yas1;
	int yas2;
};
struct kayit oyuncu;

int main()
{
  printf("*********TicTacToe Oyununa Hosgeldiniz Iyi Oyunlar********* \n\n");
   printf("------------------------------------------------------------------------------------------\n\n");

   printf("1.Oyuncu Adi Soyadi:");
	gets(oyuncu.isim1);

	printf("2.Oyuncu Adi Soyadi:");
	gets(oyuncu.isim2);

	printf("1.Oyuncu Yasi:");
	scanf("%d",&oyuncu.yas1);

	printf("2.Oyuncu Yasi:");
	scanf("%d",&oyuncu.yas2);

	printf("\n\n1.Oyuncu Adi:");
	puts(oyuncu.isim1);
	printf("1.Oyuncu Yasi:%d\n",oyuncu.yas1);

	printf("2.Oyuncu Adi:");
	puts(oyuncu.isim2);
	printf("2.Oyuncu Yasi:%d\n\n\n",oyuncu.yas2);

   int oyuncu, secim, i, j;
   int sonuc;

   oyuncu = 1;
   while ((sonuc = kazanan_kontrolu()) == 0) {
      oyun_tahtasi();
      printf("Oyuncu: %d, Seciminizi Giriniz: [%d-%d]",oyuncu, 1, 3*3);
      do {
         scanf("%d", &secim);
         while (getchar() != '\n')
            ;
         j = secim % 3 - 1;
         i = (secim - j) / 3;
         if (secim > 3* 3 || secim <= 0 || a[i][j] != 0) {
            printf("Gecersiz Secim, Oyuncu %d Tekrar Dene: ", oyuncu);
            continue;
         }
         else {
            a[i][j] = oyuncu;
            break;
         }
      } while(1);
        oyuncu = (oyuncu == 1) ? 2 : 1;
   }
   oyun_tahtasi();
   if (sonuc == -1)
      printf("Oyun Bitmistir, Kazanan Yok.");
   else
      printf("Kazanan Oyuncu %d", sonuc);

   return 0;
}
void oyun_tahtasi()
{
   int i, j;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++)
         if (a[i][j] == 0)
            printf(" . ");
         else if (a[i][j] == 1)
            printf(" O ");
         else
            printf(" X ");
      putchar('\n');
   }
}
int kazanan_kontrolu(void)
{
   int i, j, k;
   int count;

   for (k = 1; k < 3; k++) {
      for (i = 0; i < 3; i++) {
         for (j = 0; j < 3; j++)
            if (a[i][j] != k)
               break;
         if (j == 3)
            return k;
      }
      for (j = 0; j < 3; j++) {
         for (i = 0; i < 3; i++)
            if (a[i][j] != k)
               break;
         if (i == 3)
            return k;
      }
      for (i = 0; i <3; i++)
         if (a[i][i] != k)
            break;
      if (i == 3)
         return k;

      for (i = 0, j = 2; i < 3; i++, j--)
         if (a[i][j] != k)
            break;
      if (i == 3)
         return k;
   }
   count = 0;
   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
         if(a[i][j] != 0)
            count++;
   if (count == 3 * 3)
      return -1;
   return 0;
}

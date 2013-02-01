/*
 ============================================================================
 Name        : HANOI KULELERI
 Author      : Oğuzhan Saltık
 Version     : v1.002
 Copyright   : Copyright ©
 Description : HANOI KULELERI
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 *
 */
int powerxy(int sayi, int us) {

	int i, sonuc = 1;

	for (i = 0; i < us; i++)
		sonuc *= sayi;

	return sonuc;
}

/**
 *
 */
int tek_cift_bak(int disk_say, int hamle_sayisi) {

	int k;

	if (disk_say % 2 == 1)
		k = hamle_sayisi;
	else
		k = hamle_sayisi + 1;

	return k;
}

/**
 *
 */
void disk_degistir(int disk_say, int hamle_sayisi, int dizi_disk[hamle_sayisi],
		int parametre, int alan_kule[hamle_sayisi],
		int veren_kule[hamle_sayisi]) {

	int sayac_bir, sayac_iki;
	for (sayac_bir = 1; sayac_bir <= disk_say; sayac_bir++) {
		for (sayac_iki = 0; sayac_iki <= hamle_sayisi - 1; sayac_iki++) {
			//
			if (sayac_iki % powerxy(2, sayac_bir)
					== powerxy(2, sayac_bir - 1)) {
				dizi_disk[sayac_iki] = sayac_bir;
				//
				if (dizi_disk[sayac_iki] == sayac_bir) {
					if (sayac_bir % 2 == 1) {
						parametre++;
						alan_kule[sayac_iki] = (parametre % 3) + 1;
						veren_kule[sayac_iki] = ((parametre + 1) % 3) + 1;
					} else {
						parametre--;
						alan_kule[sayac_iki] = ((parametre - 1) % 3) + 1;
						veren_kule[sayac_iki] = ((parametre - 2) % 3) + 1;
					}
				}
			}
		}
	}
}

int main() {

	int disk_say = 0;

	printf("Disk sayisini giriniz:");
	scanf("%d", &disk_say);

	int hamle_sayisi = powerxy(2, disk_say);

	/*
	 struct oyun {

	 int disk[hamle_sayisi];
	 int kule[hamle_sayisi];

	 } dizi,alan, veren;
	 */

	int veren_kule[hamle_sayisi], alan_kule[hamle_sayisi];
	int dizi_disk[hamle_sayisi];

	int parametre = tek_cift_bak(disk_say, hamle_sayisi);

	disk_degistir(disk_say, hamle_sayisi, dizi_disk, parametre, veren_kule,
			alan_kule);

	int sayac;
	for (sayac = 1; sayac < hamle_sayisi; sayac++) {

		printf("%d.Hamlede %d.Disk %d. kuleden %d. kuleye aktarildi\n", sayac,
				dizi_disk[sayac], veren_kule[sayac], alan_kule[sayac]);
	}
	printf("\nsayac		disk_dizisi	veren_kule	alan_kule\n");
	for (sayac = 1; sayac < hamle_sayisi; ++sayac) {

		printf("%d\t\t%d\t\t%d\t\t%d", sayac, dizi_disk[sayac], veren_kule[sayac],
				alan_kule[sayac]);
		printf("\n");

	}
	return 0;
}

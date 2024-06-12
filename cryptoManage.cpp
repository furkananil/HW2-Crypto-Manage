/****************************************************************************
**							SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:ÖDEV-2
**				ÖĞRENCİ ADI...............:FURKAN ANIL ÖZDEMİR
**				ÖĞRENCİ NUMARASI.:B231210063
**				DERS GRUBU…………:PROGRAMLAMAYA GİRİŞ A-GRUBU
****************************************************************************/
#include <iostream>
#include <cmath>
#include <string>
#include <locale.h>
#include <windows.h>
using namespace std;

int tarihGun = 1;
int tarihAy = 1;
int tarihYil = 2024;
float genelfurkanCoinDegeri = 1.0;
float ozelfurkanCoinDegeri = 1.0;

class Hesap {

public:
	int genelHesap[10];//EN FAZLA 10 GENEL HESAP AÇILABİLİR
	int ozelHesap[10];//EN FAZLA 10 ÖZEL HESAP AÇILABİLİR

	float genelHesapMiktar[10];
	int genelHesapNo[10];

	float ozelHesapMiktar[10];
	int ozelHesapNo[10];

	void al();
	void sat();
	void bakiye();
	void kar();

	void genelHesapAc(float);
	void ozelHesapAc(float);
};

int furkanCoinSayisi;
int hesapNumarasi;
string hangiHesap;

void Hesap::genelHesapAc(float miktar) {

	//GENEL HESAP AÇMAK İÇİN HESABA YÜKLENECEK FURKANCOIN MIKTARINI ALAN VE BUNU BIR DİZİ İÇİNDE SAKLAYAN DÖNGÜ
	for (int i = 0; i <= 9; i++) {
		cout << "GENEL HESABA YÜKLENECEK MİKTARI GİRİNİZ;" << endl;
		cout << "/////////ANLIK OLARAK 1 FURKANCOIN = " << genelfurkanCoinDegeri << endl;
		cin >> miktar;

		genelHesapMiktar[i] = miktar;
		genelHesapNo[i] = i + 1;
		cout << i + 1 << " HESAP NO'LU GENEL HESABINIZ AÇILIYOR..." << endl << endl;
		cout << i + 1 << ". GENEL HESAP OLUŞTURULUYOR LÜTFEN BEKLEYİNİZ...." << endl;
		cout << i + 1 << ". GENEL HESAP BAŞARIYLA OLUŞTURULDU. " << endl << endl;

		char ch3;
		cout << "BAŞKA BİR GENEL HESAP AÇMAK İSTİYOR MUSUNUZ?(e/h)" << endl;
		cin >> ch3;

		//sonuc h veya H olursa KIRILIR
		if (ch3 == 'h' || ch3 == 'H') {
			break;
		}
		//OLMAZ İSE yeni i+1. hesabı açmak için tekrar soru sorar
		else {
			continue;
		}
	}
}

void Hesap::ozelHesapAc(float miktar) {

	//ÖZEL HESAP AÇMAK İÇİN HESABA YÜKLENECEK FURKANCOIN MIKTARINI ALAN VE BUNU BIR DİZİ İÇİNDE SAKLAYAN DÖNGÜ
	for (int j = 0; j <= 9; j++) {
		cout << "OZEL HESABA YÜKLENECEK MİKTARI GİRİNİZ;" << endl;
		cout << "/////////ANLIK OLARAK 1 FURKANCOIN = " << ozelfurkanCoinDegeri << endl;
		cin >> miktar;

		ozelHesapMiktar[j] = miktar;
		ozelHesapNo[j] = j + 1;

		cout << j + 1 << " HESAP NO'LU OZEL HESABINIZ AÇILIYOR..." << endl << endl;
		cout << j + 1 << ". OZEL HESAP OLUŞTURULUYOR LÜTFEN BEKLEYİNİZ...." << endl;
		cout << j + 1 << ". OZEL HESAP BAŞARIYLA OLUŞTURULDU. " << endl << endl;

		char ch3;
		cout << "BAŞKA BİR OZEL HESAP AÇMAK İSTİYOR MUSUNUZ?(e/h)" << endl;
		cin >> ch3;

		//sonuc h veya H olursa KIRILIR
		if (ch3 == 'h' || ch3 == 'H') {
			break;
		}
		//OLMAZ İSE yeni i+1. hesabı açmak için tekrar soru sorar
		else {
			continue;
		}
	}
}

void Hesap::al() {

	float genelHesapTLAl;
	float ozelHesapTLAl;

	//KULLANICININ ISTEDIGI HESABA YÜKLEME YAPMASI İÇİN HESAP NO VE HESAP TÜRÜ SORAN VE ONA GÖRE İŞLEM YAPAN DÖNGÜ
	for (int j = 0; j <= 9; j++) {


		cout << "HANGI HESABA YUKLEME YAPMAK ISTERSINIZ?(ORN;1.OZEL HESAP ICIN:1 O veya 1 o//1.GENEL HESAP ICIN:1 G veya 1 g) yaziniz...;" << endl;
		cout << "not;lutfen hesap numarası daha düşük bir hesaba yükleme yapmadan bir sonraki hesaba yükleme yapmayınız.." << endl;
		cin >> hesapNumarasi >> hangiHesap;

		//GENEL HESABA AİT .KULLANICININ GİRDİĞİ HESAP NO VE TÜRÜNE GÖRE SORGU YAPAN VE DİZİ ELEMANINI EKLENECEK COIN KADAR ARTIRAN KOŞUL İFADESİ
		if ((hesapNumarasi == j + 1 && hangiHesap == "g") || (hesapNumarasi == j + 1 && hangiHesap == "G")) {

			cout << j + 1 << ".  GENEL Hesaba kac TL yuklenecek giriniz;" << endl;
			cout << "ANLIK OLARAK 1 FURKANCOIN = " << genelfurkanCoinDegeri << endl;
			cin >> genelHesapTLAl;
			cout << genelHesapTLAl << " TL ile alinan FURKANCOIN SAYISI; " << genelHesapTLAl / genelfurkanCoinDegeri << endl;

			genelHesapMiktar[j] += genelHesapTLAl / genelfurkanCoinDegeri;

			cout << j + 1 << ". GENEL Hesaba " << genelHesapTLAl / genelfurkanCoinDegeri << " adet FURKANCOIN basariyla yuklenmistir;" << endl;

		}


		else {

			//ÖZEL HESABA AİT.KULLANICININ GİRDİĞİ HESAP NO VE TÜRÜNE GÖRE SORGU YAPAN VE DİZİ ELEMANINI EKLENECEK COIN KADAR ARTIRAN KOŞUL İFADESİ
			while (true) {

				if ((hesapNumarasi == j + 1 && hangiHesap == "o") || (hesapNumarasi == j + 1 && hangiHesap == "O")) {

					cout << j + 1 << ". OZEL Hesaba yuklenecek FURKANCOIN sayisini giriniz;" << endl;
					cout << "ANLIK OLARAK 1 FURKANCOIN = " << ozelfurkanCoinDegeri << endl;
					cin >> ozelHesapTLAl;
					cout << ozelHesapTLAl << " TL ile alinan FURKANCOIN SAYISI; " << ozelHesapTLAl / ozelfurkanCoinDegeri << endl;

					genelHesapMiktar[j] += ozelHesapTLAl / ozelfurkanCoinDegeri;

					cout << j + 1 << ". GENEL Hesaba " << ozelHesapTLAl / ozelfurkanCoinDegeri << " adet FURKANCOIN basariyla yuklenmistir;" << endl;
					break;
				}
				else {
					//YUKARDAKILER ÇALIŞMAZ ISE FOR DONGUSUNE j++ ile TEKRAR GİR
					continue;
				}
			}
		}
		char ch4;
		cout << "BAŞKA BİR YUKLEME YAPMAK ISTIOR MUSUNUZ?(e/h)" << endl;
		cin >> ch4;
		//sonuc h veya H olursa KIRILIR
		if (ch4 == 'h' || ch4 == 'H') {
			break;
		}
		else {
			continue;
		}
	}
}


void Hesap::sat() {

	float genelHesapKriptoSat;
	float ozelHesapKriptoSat;

	////KULLANICININ ISTEDIGI HESAPTAN ÇEKİM YAPMASI İÇİN HESAP NO VE HESAP TÜRÜ SORAN VE ONA GÖRE İŞLEM YAPAN DÖNGÜ
	for (int j = 0; j <= 9; j++) {

		cout << "HANGI HESAPTAN KRIPTO CEKIMI YAPMAK ISTERSINIZ?(ORN;1.OZEL HESAP ICIN:1 O veya 1 o//1.GENEL HESAP ICIN:1 G veya 1 g) yaziniz...;" << endl;
		cout << "not;lutfen hesap numarası daha düşük bir hesaptan çekim yapmadan bir sonraki hesaptan çekim yapmayınız.." << endl;
		cin >> hesapNumarasi >> hangiHesap;

		//GENEL HESABA AİT .KULLANICININ GİRDİĞİ HESAP NO VE TÜRÜNE GÖRE SORGU YAPAN VE DİZİ ELEMANINI ÇIKARILCAK COIN KADAR AZALTAN,
		//DAHA SONRA BU COIN IFADESINI MEVCUD TL DEĞERİNE GÖRE YANSITIP HESAPTAN ÇEKİLMESİNİ SAĞLAYAN KOŞUL İFADESİ
		if ((hesapNumarasi == j + 1 && hangiHesap == "g") || (hesapNumarasi == j + 1 && hangiHesap == "G")) {

			cout << "ANLIK OLARAK 1 FURKANCOIN = " << genelfurkanCoinDegeri << endl;
			cout << "ANLIK OLACAK HESABINIZIN YAKLASIK TL DEGERI" << genelHesapMiktar[j] * genelfurkanCoinDegeri << endl;
			cout << "HESABINIZDAKI FURKANCOIN MIKTARI ;" << genelHesapMiktar[j] << endl;
			cout << j + 1 << ".  GENEL Hesaptan Kac FURKANCOIN cekilecek giriniz;" << endl;
			cin >> genelHesapKriptoSat;
			cout << "HESABINIZDAN " << genelHesapKriptoSat << " Adet FURKANCOIN; " << genelfurkanCoinDegeri * genelHesapKriptoSat << " TL YE CEVIRILIP HESABINIZDAN CEKILMISTIR" << endl;
			genelHesapMiktar[j] -= genelHesapKriptoSat;
			break;
		}

		else {
			char ch7;

			//ÖZEL HESABA AİT .KULLANICININ GİRDİĞİ HESAP NO VE TÜRÜNE GÖRE SORGU YAPAN VE DİZİ ELEMANINI ÇIKARILCAK COIN KADAR AZALTAN,
			//DAHA SONRA BU COIN IFADESINI MEVCUD TL DEĞERİNE GÖRE YANSITIP HESAPTAN ÇEKİLMESİNİ SAĞLAYAN KOŞUL İFADESİ
			while (true) {
				if ((hesapNumarasi == j + 1 && hangiHesap == "o") || (hesapNumarasi == j + 1 && hangiHesap == "O")) {
					cout << "ANLIK OLARAK 1 FURKANCOIN = " << ozelfurkanCoinDegeri << endl;
					cout << "ANLIK OLACAK HESABINIZIN YAKLASIK TL DEGERI" << ozelHesapMiktar[j] * ozelfurkanCoinDegeri << endl;
					cout << "HESABINIZDAKI FURKANCOIN MIKTARI; " << ozelHesapMiktar[j] << endl;
					cout << j + 1 << ".  OZEL Hesaptan Kac FURKANCOIN cekilecek giriniz;" << endl;
					cin >> ozelHesapKriptoSat;
					cout << "HESABINIZDAN " << ozelHesapKriptoSat << " Adet FURKANCOIN; " << ozelfurkanCoinDegeri * ozelHesapKriptoSat << " TL YE CEVIRILIP HESABINIZDAN CEKILMISTIR" << endl;
					ozelHesapMiktar[j] -= ozelHesapKriptoSat;
					break;
				}
				else {
					continue;
				}
			}
		}
		char ch4;
		cout << "BAŞKA BİR YUKLEME YAPMAK ISTIOR MUSUNUZ?(e/h)" << endl;
		cin >> ch4;

		if (ch4 == 'h' || ch4 == 'H') {
			break;
		}
		else {
			continue;
		}
	}
}


void Hesap::kar() {
	int gunFarki = tarihGun - 1;
	int ayFarki = tarihAy - 1;
	int yilFarki = tarihYil - 2024;
	int randomGun1, randomGun2, randomGun3;
	//PROGRAM TARIHIYLE DEĞİŞTİRİLEN TARİH ARASINDAKİ FARKA GÖRE  

	//GENEL HESAPTA GÜN FARKINA GÖRE günlük % 1 artış sağlar, 15 günde bir %5 düşüş sağlar. 
	for (int j = 1; j <= gunFarki; j++) {
		genelfurkanCoinDegeri = genelfurkanCoinDegeri + genelfurkanCoinDegeri * 0.01;
		if (j % 15 == 0) {
			genelfurkanCoinDegeri = genelfurkanCoinDegeri - genelfurkanCoinDegeri * 0.05;
		}
	}
	//GENEL HESAPTA AY FARKINA GÖRE günlük % 1 artış sağlar, 15 günde bir %5 düşüş sağlar. 
	for (int j = 1; j <= 30 * ayFarki; j++) {
		genelfurkanCoinDegeri = genelfurkanCoinDegeri + genelfurkanCoinDegeri * 0.01;
		if (j % 15 == 0) {
			genelfurkanCoinDegeri = genelfurkanCoinDegeri - genelfurkanCoinDegeri * 0.05;
		}
	}
	//GENEL HESAPTA YIL FARKINA GÖRE günlük % 1 artış sağlar, 15 günde bir %5 düşüş sağlar. 
	for (int j = 1; j <= 360 * yilFarki; j++) {
		genelfurkanCoinDegeri = genelfurkanCoinDegeri + genelfurkanCoinDegeri * 0.01;
		if (j % 15 == 0) {
			genelfurkanCoinDegeri = genelfurkanCoinDegeri - genelfurkanCoinDegeri * 0.05;
		}
	}


	srand(time(NULL));
	//Özel hesap günlük % 5 artış sağlar.Ancak her bir aylık süreçte rasgele 3 günde, günlük % 10 düşüş sağlar.
	//HER DÖNÜŞTE RASGELE 3 GÜN SEÇİLİR VE 
	for (int i = 0; i < 10; i++) {
		randomGun1 = rand() % 29 + 1;
		randomGun2 = rand() % 29 + 1;
		randomGun3 = rand() % 29 + 1;

		if (ozelHesapMiktar[i] == -858993460 || ozelHesapNo[i] == -858993460) {
			continue;
		}
		else {
			for (int k = 0; k < gunFarki; k++) {
				ozelfurkanCoinDegeri = ozelfurkanCoinDegeri + ozelfurkanCoinDegeri * 0.05;
				if (k == randomGun1 || k == randomGun2 || k == randomGun3) {
					ozelfurkanCoinDegeri = ozelfurkanCoinDegeri - ozelfurkanCoinDegeri * 0.1;
				}
			}
			for (int k = 0; k < 30 * ayFarki; k++) {
				ozelfurkanCoinDegeri = ozelfurkanCoinDegeri + ozelfurkanCoinDegeri * 0.05;
				if (k % 30 == 0) {
					randomGun1 = rand() % 29 + 1;
					randomGun2 = rand() % 29 + 1;
					randomGun3 = rand() % 29 + 1;
				}
				if (k % randomGun1 == 0 || k % randomGun2 == 0 || k % randomGun3 == 0) {
					ozelfurkanCoinDegeri = ozelfurkanCoinDegeri - ozelfurkanCoinDegeri * 0.1;
				}
			}
			for (int k = 0; k < 360 * yilFarki; k++) {
				ozelfurkanCoinDegeri = ozelfurkanCoinDegeri + ozelfurkanCoinDegeri * 0.05;
				if (k % 30 == 0) {
					randomGun1 = rand() % 29 + 1;
					randomGun2 = rand() % 29 + 1;
					randomGun3 = rand() % 29 + 1;
				}
				if (k % randomGun1 == 0 || k % randomGun2 == 0 || k % randomGun3 == 0) {
					ozelfurkanCoinDegeri = ozelfurkanCoinDegeri - ozelfurkanCoinDegeri * 0.1;
				}
			}
		}
	}
	cout << tarihGun << " " << tarihAy << " " << tarihYil << " tarih itibariyle FURKANCOIN DEGERI;" << endl;
	cout << "GENEL HESAP ICIN DEGERI ;" << genelfurkanCoinDegeri << endl;
	cout << "OZEL HESAP ICIN DEGERI ;" << ozelfurkanCoinDegeri << endl;
}


void Hesap::bakiye() {
	//GENEL HESAPLARI YAZDIRMA
	//EĞER DİZİNİN ELEMANI BOŞ İSE CONTİNUE DEĞİLSE YAZDIR
	for (int i = 0; i < 10; i++) {

		if (genelHesapMiktar[i] == -858993460 || genelHesapNo[i] == -858993460) {
			continue;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << genelHesapNo[i] << ". GENEL HESAP BILGILERI" << endl << endl;
			cout << "BAKİYE;" << genelHesapMiktar[i] << " FURKANCOIN" << endl;
			cout << "HESABIN YAKLASIK TL DEGERI ;" << genelHesapMiktar[i] * genelfurkanCoinDegeri << endl;
			cout << "-----------------------------------" << endl << endl;
		}
	}
	//OZEL HESAPLARI YAZDIRMA
	//EĞER DİZİNİN ELEMANI BOŞ İSE CONTİNUE DEĞİLSE YAZDIR
	for (int j = 0; j < 10; j++) {

		if (ozelHesapMiktar[j] == -858993460 || ozelHesapNo[j] == -858993460) {
			continue;
		}
		else {
			cout << "-----------------------------------" << endl;
			cout << ozelHesapNo[j] << ". OZEL HESAP BILGILERI" << endl << endl;
			cout << "BAKİYE;" << ozelHesapMiktar[j] << " FURKANCOIN" << endl;
			cout << "HESABIN YAKLASIK TL DEGERI ; " << ozelHesapMiktar[j] * ozelfurkanCoinDegeri << endl;
			cout << "-----------------------------------" << endl << endl;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Turkish");

	Hesap hesapIslemleri;
	int hesapNo = 1;
	int miktar;

	cout << "-------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "FURKANCOIN KRIPTO PARA YÖNETİM PANELİNE HOŞGELDİNİZ..." << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "EN FAZLA 10 AR ADET GENEL VE ÖZEL HESAP AÇILABİLİR" << endl;
	cout << "-------------------------------------------------------" << endl << endl;
	cout << "LUTFEN YAPMAK ISTEDIĞINIZ İŞLEMİ SEÇİNİZ;" << endl << endl;

	int islem;
	char ch2;
	//ANA MENUYE DÖNMEYİ SAĞLAYAN DOWHİLE İFADESİ
	do {
		//1-6 ARASINDAKİ SAYILARIN DIŞINA ÇIKMAMAYI SAĞLAYAN DOWHİLE İFADESİ
		do {
			cout << "1-GENEL HESAP AÇ,,," << endl;
			cout << "2-ÖZEL HESAP AÇ,,," << endl;
			cout << "3-EKLE(SATIN AL),,," << endl;
			cout << "4-ÇEK(PARA ÇEK),,," << endl;
			cout << "5-TARİH,,," << endl;
			cout << "6-HESAPLARI LİSTELE,,," << endl;

			cin >> islem;
			//SEÇİLEN SAYIYA GÖRE YUKARIDAKI İŞLEMLERDEN BİRİNİ GERÇEKLEŞTİREN SWİTCH CASE İFADESİ
			switch (islem) {
			case 1:
				hesapIslemleri.genelHesapAc(0);
				break;
			case 2:
				hesapIslemleri.ozelHesapAc(0);
				break;
			case 3:
				hesapIslemleri.al();
				break;
			case 4:
				hesapIslemleri.sat();
				break;
			case 5:
				char ch5;
				char ch6;
				//SISTEM TARIHINI GUNCELLEMEK ISTER MISINIZ sorusunu cevaba göre tekrarlayan dowhile ifadesi
				do {
					cout << "GECERLI SISTEM TARIHI ; " << tarihGun << " " << tarihAy << " " << tarihYil << endl;
					cout << "TARIHI GUNCELLEMEK ISTER MISINIZ(e/h);" << endl;
					cin >> ch6;
					if (!(ch6 == 'H' || ch6 == 'h')) {

						cout << "LUTFEN TARIHI (gg aa yy) SEKLINDE GIRINIZ:" << endl;
						cin >> tarihGun >> tarihAy >> tarihYil;

						//GUN 30DAN BUYUK VEYA 0DAN KUCUK VEYA AY 12DEN BUYUK VEYA 0DAN KUCUK VEYA YIL 2024TEN KUCUK OLURSA SORUYU TEKRAR SORAN IFADE
						while ((tarihGun > 30 || tarihGun < 0) || (tarihAy > 12 || tarihAy < 0) || (tarihYil < 2024)) {

							cout << "GECERSIZ TARIH GIRILDI LUTFEN TEKRAR DENEYINIZ..." << endl;
							cout << "LUTFEN TARIHI (gg aa yy) SEKLINDE GIRINIZ:" << endl;
							cin >> tarihGun >> tarihAy >> tarihYil;
						}
						cout << "GECERLI SISTEM TARIHI;" << tarihGun << " " << tarihAy << " " << tarihYil << endl;
						cout << "SISTEM TARIHINI GUNCELLEMEK ISTER MISINIZ(e/h);" << endl;
						cin >> ch5;
					}
				} while (!(ch5 == 'h' || ch5 == 'H'));
				hesapIslemleri.kar();
				break;
			case 6:
				hesapIslemleri.bakiye();
				break;
			default:
				cout << "////LUTFEN 1-6 ARASI SAYI GİRİNİZ..." << endl << endl << endl;
			}
		} while (islem < 1 || islem>6);

		cout << "----------------------------------------";
		cout << "ANA MENUYE DONMEK ISTIYOR MUSUNUZ?(e/h)";
		cout << "----------------------------------------";

		cin >> ch2;
	} while (!(ch2 == 'h' || ch2 == 'H'));

	return 0;
}



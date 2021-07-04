/****************************************************************************
**					            SAKARYA ÜNİVERSİTESİ					   **
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ			   **
**				            BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ				   **
**				               PROGRAMLAMAYA GİRİŞİ DERSİ				   **
**																		   **
**				       ÖDEV NUMARASI....:PROJE							   **
**			     	   ÖĞRENCİ ADI......:ECE NUR ARSLAN					   **
**				       ÖĞRENCİ NUMARASI.:B171210061						   **
**				       DERS GRUBU.......:1 Öğretim B Grubu				   **
****************************************************************************/

#include <Windows.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<fstream>
#include <chrono>
#include <ctime>  

using namespace std;

struct okuyucu //Okuyucu bilgileri için yapı tanımlanması.
{
	int uyeNo;
	string ad;
	string soyad;
	string tcNo;
	string telNo;
	string dogumTarihi;
	string gorev;
	int maxKitap;

};

struct kitap //Kitap bilgileri için yapı tanımlanması.
{
	int isbn;
	string kitapAd;
	string yazarAd;
	string yazarSoyad;
	string konu;
	string tur;
	int sayfaSayisi;

};

struct kullanici //Sisteme giris yapan kullanicilar icin yapi
{
	string username;
	string parola;

};

struct oduncVerilen //Odunc verilen dokumanlar icin yapi
{
	int isbn;
	string tcNo;
	string almaTarihi;
	string iadeTarihi;
};


//Kullanilan fonksiyonlarin prototoipi tanımlandi
void OkuyucuEkle();
void KitapEkle();
bool KayitKontrol(int,string);
void OkuyucuDuzenle();
void KitapDuzenle();
void OkuyucuSil();
void KitapSil();
void KullaniciEkle();
bool KullaniciVarMi(string,string);
void KitapOduncAl();
void OkuyucuKitaplariListele();
void KitapIade();
bool SifreDogruMu(string,string);
void UserLog(string, time_t);
void IdIleOduncSil(int);
string TcBul(int);


int main()
{
	setlocale(LC_ALL, "Turkish");
	string kullaniciAdi;
	
	int secim;

	do {
		//99  yani cikis islemi secilene kadar dönen bir dongu

		system("cls");

		cout << "SISTEME GIRIS YAPIN VEYA UYELIK OLUSTURUN" << endl;
		cout << endl << "1. Giris Yap" << endl;
		cout << "2. Uye Ol" << endl;
		cout << "99. ÇIKIŞ" << endl << endl;
		cout << "SEÇİMİNİZ: "; cin >> secim; cout << endl;

		system("cls");

		switch (secim)	//Kullanicinin secimine gore fonksiyonlari gerceklestiren switch case yapisi 
		{

		case 1:
		{
			//Kullanici sisteme giris yap'i sectiginde calisan case
			kullanici kullanici;

			cout << "Kullanici adi: "; cin >> kullanici.username;

			//Girilen kullanici adinin var olup olmadigini kontrol edip yoksa hata mesaji bastiran if yapisi
			if (!KullaniciVarMi(kullanici.username, "kullanicilar.txt")) {
				cout << "Kullanici bulunamadi.";
				system("pause");
				break;
			}

			cout << "Parola       : "; cin >> kullanici.parola;

			//Girilen sifrenin dogrulugunu kontrol eden if yapisi
			if (SifreDogruMu(kullanici.username,kullanici.parola))
			{
				kullaniciAdi = kullanici.username;
				time_t start_time = time(NULL);

				int secim1;
				//Girilen sifre ve kullanici adi dogruysa sisteme giris yapilan secimlerin alinip islendigi do while
				do
				{
					system("cls");
					cout << "1. Okuyucu Kaydi" << endl;
					cout << "2. Okuyucu Kaydı Güncelleme" << endl;
					cout << "3. Okuyucu Silme " << endl;
					cout << "4. Okuyucu Uzerindeki Kitaplar Listesi" << endl;
					cout << "5. Okuyucu Kitap Odunc Alma " << endl;
					cout << "6. Okuyucu Kitap Geri Döndürme" << endl;
					cout << "7. Kitap Ekleme" << endl;
					cout << "8. Kitap Silme " << endl;
					cout << "9. Kitap Düzeltme" << endl;
					cout << "99. CIKIS" << endl << endl;
					cout << "SECIMINIZ: "; cin >> secim1; cout << endl;

					//Kullanicidan alinan secimlere gore ilgili fonksiyonlari gerceklestiren switch case yapisi
					switch (secim1)
					{
					case 1:  system("cls"); OkuyucuEkle(); system("pause"); break;
					case 2:  system("cls"); OkuyucuDuzenle(); system("pause"); break;
					case 3:  system("cls"); OkuyucuSil(); system("pause");  break;
					case 4:  system("cls"); OkuyucuKitaplariListele(); system("pause"); break;
					case 5:  system("cls"); KitapOduncAl(); system("pause"); break;
					case 6:  system("cls"); KitapIade(); system("pause"); break;
					case 7:  system("cls"); KitapEkle(); system("pause"); break;
					case 8:  system("cls"); KitapSil(); system("pause"); break;
					case 9:  system("cls"); KitapDuzenle(); system("pause"); break;

					case 99: 
						
						UserLog(kullaniciAdi,start_time);
						system("Pause");
						break;
					default: system("cls"); cout << "HATALI SEÇİM.ANA MENUYE GECMEK ICIN LUTFEN BIR TUSA BASINIZ." << endl; system("pause");    break;
					}

				} while (secim1!=99);	//99 girilmedigi surece donen do dongusu
				
			}

			//Beklenmeyen bir girdi girilmesi durumunda gosterilecek mesaj
			else {
				system("cls");
				cout << "Hatali kullanici adi sifre girisi yaptiniz." << endl;
				system("Pause");
			}

		}break;

		case 2: {
			//Kullanici uye olmayi sectiginde calisacak fonksiyon
			KullaniciEkle();
		}break;

		case 99: system("Pause"); break;

		default:
			cout << "HATALI SECIM. ANA MENUYE GECMEK ICIN LUTFEN BIR TUSA BASINIZ." << endl;   system("pause");  break;
		}

	} while (!(secim == 99));

	system("PAUSE");

	return 0;
}



void OkuyucuEkle()  //Okuyucular dosyasına veri ekleyen fonksiyon.
{
	ofstream okuyucuDosyaYaz;
	okuyucu okuyucu;
	okuyucuDosyaYaz.open("okuyucu.txt", ios::app);

	cout << "Okuyucu Uye No          :";
	cin >> okuyucu.uyeNo;

	//Eklenecek okuyucunun uye numarasi ile kayit yapilip yapilmadigi kontrolu
	if (KayitKontrol(okuyucu.uyeNo, "okuyucu.txt") == 1) {

		cout << "Girdiginiz uye numarasi ile zaten bir kayit yapilmis.";
		system("Pause");

	}
	else {

		cout << "Okuyucu Adi             :";
		cin >> okuyucu.ad;
		cout << "Okuyucu Soyadi          :";
		cin >> okuyucu.soyad;
		cout << "Okuyucu TC No           :";
		cin >> okuyucu.tcNo;
		cout << "Okuyucu Telefon Numarasi:";
		cin >> okuyucu.telNo;
		cout << "Okuyucu Dogum Tarihi    :";
		cin >> okuyucu.dogumTarihi;
		cout << "Okuyucu Görevi          :";
		cin >> okuyucu.gorev;
		cout << "Alabilecegi Kitap Sayisi:";
		cin >> okuyucu.maxKitap;

		okuyucuDosyaYaz << okuyucu.uyeNo << "\t" << okuyucu.ad << "\t" << okuyucu.soyad << "\t" << okuyucu.tcNo << "\t" << okuyucu.telNo << "\t" << okuyucu.dogumTarihi << "\t" << okuyucu.gorev << "\t" << okuyucu.maxKitap << "\n";
	}

		okuyucuDosyaYaz.close();

}

void KitapEkle()  //Kitaplar dosyasına veri ekleyen fonksiyon.
{
	ofstream kitapDosyaYaz;
	kitap kitap;
	kitapDosyaYaz.open("kitaplar.txt", ios::app);

	cout << "Kitap ISBN No  :";
	cin >> kitap.isbn;

	//Kaydedilecek kitabin isbn numarasinin kullanilip kullanilmadigi kontrolu
	if (KayitKontrol(kitap.isbn, "kitaplar.txt") == 1) {

		cout << "Girdiginiz ISBN numarasi ile zaten bir kayit yapilmis.";
	}
	else {

		cout << "Kitap Adi   :";
		cin >> kitap.kitapAd;
		cout << "Yazar Adi   :";
		cin >> kitap.yazarAd;
		cout << "Yazar Soyadi:";
		cin >> kitap.yazarSoyad;
		cout << "Kitap Konusu:";
		cin >> kitap.konu;
		cout << "Kitap türü  :";
		cin >> kitap.tur;
		cout << "Sayfa Sayısı:";
		cin >> kitap.sayfaSayisi;
		
		kitapDosyaYaz << kitap.isbn << "\t" << kitap.kitapAd << "\t" << kitap.yazarAd << "\t" << kitap.yazarSoyad << "\t" << kitap.konu << "\t" << kitap.tur << "\t" << kitap.sayfaSayisi << "\n";
	}

	kitapDosyaYaz.close();

}

bool KayitKontrol(int id , string file) // Gelen ID nin gelen file içerisinde bulunup bulunmadığını donduren fonksiyon.
{
	bool kontrol = 0; // gelen dosyada var olup olmama durumu
	ifstream dosyaoku;
	dosyaoku.open(file);
	int okunanID;
	string line;

	//Dosya satir satir okundugu surece calisan dongu
	while (getline(dosyaoku, line) )
	{
		//dosyaoku >> okunanID;
		int i = 0;
		string okunan;

		//Okunacak degerin sonuna gelinene kadar kelimeyi harf harf alan while dongusu
		while (line[i] != '\t')
		{
			okunan += line[i];
			i++;
		}

		okunanID = stoi(okunan);	

		//Istenen ID bulununca kontrolu donduren if 
		if (okunanID == id)
		{
			kontrol = 1;
			return kontrol;
		}
	}
	
	return kontrol;
}

void OkuyucuDuzenle() // Programdaki hasta kaydının düzenlenmesini sağlayan fonksiyon oluşturuldu.
{

	okuyucu okuyucu;
	int alinanUyeNo;
	cout << "Duzenlemek istediginiz okuyucunun üye numarasını girin:";
	cin >> alinanUyeNo;


	if (KayitKontrol(alinanUyeNo, "okuyucu.txt") == 0) // Kayıt kontrol fonksiyonu çağırılarak kisi kaydinin olup olmadigi sorgulandi.
	{
		cout << "Boyle bir uye numarasi bulunamadi!\n\a";
	}
	else
	{
		ifstream dosyaoku;
		ifstream iDosyaOku;
		ofstream dosyayaz;
		dosyaoku.open("okuyucu.txt");
		iDosyaOku.open("okuyucu.txt");
		dosyayaz.open("okuyucu_duzenle.txt", ios::app);
		string line;

		//Dosyadan okunacak satir oldugu surece donen dongu
		while (getline(iDosyaOku, line))
		{
			dosyaoku >> okuyucu.uyeNo >> okuyucu.ad >> okuyucu.soyad >> okuyucu.tcNo >> okuyucu.telNo >> okuyucu.dogumTarihi >> okuyucu.gorev >> okuyucu.maxKitap;
			
			//Eger alinan uye no'ya sahip kullanicinin satirindaysak calisir
			if (okuyucu.uyeNo == alinanUyeNo)
			{
				cout << "Okuyucu Uye No          :" << okuyucu.uyeNo << "\nOkuyucu Adi             :" << okuyucu.ad << "\nOkuyucu Soyadi          :" << okuyucu.soyad << "\nOkuyucu TC No           :" << okuyucu.tcNo << "\nOkuyucu Telefon Numarasi:" << okuyucu.telNo << "\nOkuyucu Dogum Tarihi    :" << okuyucu.dogumTarihi << "\nOkuyucu Görevi          :" << okuyucu.gorev << "\nAlabilecegi Kitap Sayisi:" << okuyucu.maxKitap << "\n\nYeni bilgiler;\n";
				cout << "Okuyucu Uye No          :"; cin >> okuyucu.uyeNo;
				cout << "Okuyucu Adi             :"; cin >> okuyucu.ad;
				cout << "Okuyucu Soyadi          :"; cin >> okuyucu.soyad;
				cout << "Okuyucu TC No           :"; cin >> okuyucu.tcNo;
				cout << "Okuyucu Telefon Numarasi:"; cin >> okuyucu.telNo;
				cout << "Okuyucu Dogum Tarihi    :"; cin >> okuyucu.dogumTarihi;
				cout << "Okuyucu Görevi          :"; cin >> okuyucu.gorev;
				cout << "Alabilecegi Kitap Sayisi:"; cin >> okuyucu.maxKitap;

				dosyayaz << okuyucu.uyeNo << "\t" << okuyucu.ad << "\t" << okuyucu.soyad << "\t" << okuyucu.tcNo << "\t" << okuyucu.telNo << "\t" << okuyucu.dogumTarihi << "\t" << okuyucu.gorev << "\t" << okuyucu.maxKitap << "\n";
			}
			else
			{
				dosyayaz << okuyucu.uyeNo << "\t" << okuyucu.ad << "\t" << okuyucu.soyad << "\t" << okuyucu.tcNo << "\t" << okuyucu.telNo << "\t" << okuyucu.dogumTarihi << "\t" << okuyucu.gorev << "\t" << okuyucu.maxKitap << "\n";
			}

		}
		dosyaoku.close();
		dosyayaz.close();
		iDosyaOku.close();

		remove("okuyucu.txt");
		rename("okuyucu_duzenle.txt", "okuyucu.txt");
		cout << "Okuyucu bilgileri guncellendi!\n";
		
	}
}

void KitapDuzenle() //Kitap kaydinin duzenlenmesini saglayan fonksiyon olusturuldu.
{
	kitap kitap;
	int alinanIsbn;
	cout << "Duzenlemek istediginiz kitabın ISBN numarasını girin:";
	cin >> alinanIsbn;


	if (KayitKontrol(alinanIsbn, "kitaplar.txt") == 0) // Kayıt kontrol fonksiyonu kitap kaydinin olup olmadigi sorgulandi.
	{
		cout << "Boyle bir ISBN numarasi bulunamadi!\n\a";
	}
	else
	{
		ifstream dosyaoku;
		ifstream idosyaoku;
		ofstream dosyayaz;
		dosyaoku.open("kitaplar.txt");
		idosyaoku.open("kitaplar.txt");
		dosyayaz.open("kitaplar_duzenle.txt", ios::app);
		string line;

		//Okunacak satir oldugu surece calisir
		while (getline(idosyaoku,line))
		{
			dosyaoku >> kitap.isbn >> kitap.kitapAd >> kitap.yazarAd >> kitap.yazarSoyad >> kitap.konu >> kitap.tur >> kitap.sayfaSayisi;

			//Eger o satirdaki isbn alinan isbn e esitse kontrolu
			if (kitap.isbn == alinanIsbn)
			{
				cout << "Kitap ISBN  :" << kitap.isbn << "\nKitap Adı   :" << kitap.kitapAd << "\nYazar Adı   :" << kitap.yazarAd << "\nYazar Soyadı:" << kitap.yazarSoyad << "\nKitap Konu  :" << kitap.konu << "\nKitap Tur   :" << kitap.tur << "\nSayfa Sayisi:" << kitap.sayfaSayisi << "\n\nYeni bilgiler;\n";
				cout << "Kitap Adı   :"; cin >> kitap.kitapAd;
				cout << "Yazar Adı   :"; cin >> kitap.yazarAd;
				cout << "Yazar Soyadı:"; cin >> kitap.yazarSoyad;
				cout << "Kitap Konu  :"; cin >> kitap.konu;
				cout << "Kitap Tur   :"; cin >> kitap.tur;
				cout << "Sayfa Sayisi:"; cin >> kitap.sayfaSayisi;
				

				//if (dosyaoku.eof())	break; // En son kaydın 2 kere okuyup yazılmaması için eklendi.
				dosyayaz << kitap.isbn << "\t" << kitap.kitapAd << "\t" << kitap.yazarAd << "\t" << kitap.yazarSoyad << "\t" << kitap.konu << "\t" << kitap.tur << "\t" << kitap.sayfaSayisi << "\n";
			}
			else
			{
				//if (dosyaoku.eof())	break; // En son kaydın 2 kere okuyup yazılmaması için eklendi.
				dosyayaz << kitap.isbn << "\t" << kitap.kitapAd << "\t" << kitap.yazarAd << "\t" << kitap.yazarSoyad << "\t" << kitap.konu << "\t" << kitap.tur << "\t" << kitap.sayfaSayisi << "\n";
			}

		}
		dosyaoku.close();
		dosyayaz.close();
		idosyaoku.close();

		remove("kitaplar.txt");
		rename("kitaplar_duzenle.txt", "kitaplar.txt");
		cout << "Kitap bilgileri guncellendi!\n";

	}
}

void OkuyucuSil() // Okuyucu kaydının silinmesini sağlayan fonksiyon oluşturuldu.
{

	okuyucu okuyucu;
	int alinanUyeNo;
	cout << "Silmek istediginiz okuyucunun üye numarasını girin:";
	cin >> alinanUyeNo;

	//Uye numarasina sahip okuyucu var mi kontrolu
	if (KayitKontrol(alinanUyeNo, "okuyucu.txt") == 0) // Kayıt kontrol fonksiyonu çağırılarak okuyucu kaydının olup olmadığı sorgulandı.
	{
		cout << "Boyle bir üye numarasi bulunamadi!\n\a";
	}
	else
	{
		ifstream dosyaoku;
		ifstream idosyaoku;
		ofstream dosyayaz;
		idosyaoku.open("okuyucu.txt");
		dosyaoku.open("okuyucu.txt");
		dosyayaz.open("okuyucu_sil.txt", ios::app);
		string line;

		//Okunacak satir oldugu surece calisan dongu
		while (getline(idosyaoku,line))
		{
			dosyaoku >> okuyucu.uyeNo >> okuyucu.ad >> okuyucu.soyad >> okuyucu.tcNo >> okuyucu.telNo >> okuyucu.dogumTarihi >> okuyucu.gorev >> okuyucu.maxKitap;
			
			//Silinecek okuyucu disindakileri temp txt ye yazmak icin kontrol
			if (okuyucu.uyeNo != alinanUyeNo)
			{
				dosyayaz << okuyucu.uyeNo << "\t" << okuyucu.ad << "\t" << okuyucu.soyad << "\t" << okuyucu.tcNo << "\t" << okuyucu.telNo << "\t" << okuyucu.dogumTarihi << "\t" << okuyucu.gorev << "\t" << okuyucu.maxKitap << "\n";
			}

			else {
				//Varsa kullanicinin oduncleri silinmeli
				IdIleOduncSil(okuyucu.uyeNo);
			}
		}

		dosyaoku.close();
		dosyayaz.close();
		idosyaoku.close();

		remove("okuyucu.txt");
		rename("okuyucu_sil.txt", "okuyucu.txt");
		cout << "Kayit silindi!\n";
	}
		
}

void KitapSil() //Kitap kaydının silinmesini saglayan fonksiyon olusturuldu.
{

	kitap kitap;
	int alinanIsbnNo;
	cout << "Silmek istediginiz kitabın ISBN numarasını girin:";
	cin >> alinanIsbnNo;

	//Silinecek kitabin ISBN numarasi ile var olup olmadigi kontrolu
	if (KayitKontrol(alinanIsbnNo, "kitaplar.txt") == 0) 
	{
		cout << "Boyle bir ISBN numarasi bulunamadi!\n\a";
	}
	else
	{

		ifstream dosyaoku;
		ifstream idosyaoku;
		ofstream dosyayaz;
		dosyaoku.open("kitaplar.txt");
		idosyaoku.open("kitaplar.txt");
		dosyayaz.open("kitaplar_sil.txt", ios::app);
		string line;

		//Dosya satir satir okundugu surece calisan dongu
		while (getline(idosyaoku,line))
		{
			dosyaoku >> kitap.isbn >> kitap.kitapAd >> kitap.yazarAd >> kitap.yazarSoyad >> kitap.konu >> kitap.tur >> kitap.sayfaSayisi;
			
			//Okunan ISBN alinan ISBN'e esit degilse calisir
			if (kitap.isbn != alinanIsbnNo)
			{
				dosyayaz << kitap.isbn << "\t" << kitap.kitapAd << "\t" << kitap.yazarAd << "\t" << kitap.yazarSoyad << "\t" << kitap.konu << "\t" << kitap.tur << "\t" << kitap.sayfaSayisi << "\n";
			}
		}

		dosyaoku.close();
		dosyayaz.close();
		idosyaoku.close();

		remove("kitaplar.txt");
		rename("kitaplar_sil.txt", "kitaplar.txt");
		cout << "Kayit silindi!\n";
	}

}

void KullaniciEkle() {	//Sisteme giris yapabilecek kullanicilarin eklendigi fonksiyon

	ofstream kullaniciDosyaYaz;
	kullanici kullanici;
	kullaniciDosyaYaz.open("kullanicilar.txt", ios::app);

	cout << "Kullanici Adi  :";
	cin >> kullanici.username;

	//Eklenecek kullanici adinin unique olmasini saglayan kontrol
	if (KullaniciVarMi(kullanici.username, "kullanicilar.txt") == 1) {

		cout << "Bu kullanici adi ile bir kullanici zaten var!\n\a";
	}
	else {

		cout << "Parola     :";
		cin >> kullanici.parola;

		kullaniciDosyaYaz << kullanici.username << "\t" << kullanici.parola << "\n";
	}

	kullaniciDosyaYaz.close();
}

bool KullaniciVarMi(string username, string file) { //Yalnizca sisteme giris icin kullanilan kullanici dogrulama fonksiyonu

	bool kontrol = 0; // gelen dosyada var olup olmama durumu
	ifstream dosyaoku;
	dosyaoku.open(file);
	string okunan;

	//Dosya okundugu surece calisir
	while (dosyaoku >> okunan)
	{
		//Parametre olarak gelen username in okunan satirdaki ile ayni olma durumu kontrolu
		if (okunan == username)
		{
			kontrol = 1;
		}
	}
	return kontrol;
}

void KitapOduncAl() { //Okuyucunun kitap odunc almasi icin fonksiyon

	oduncVerilen odunc;
	int uyeNo;

	cout << "Odunc alinacak kitabin ISBN numarasi : ";
	cin >> odunc.isbn;

	//Alinacak eserin isbn numarasi kitaplar.txt de var mi kontrolu
	if (KayitKontrol(odunc.isbn, "kitaplar.txt")==0)
	{
		cout << "Girilen ISBN numarasina sahip bir eser bulunamadi.";
		return;
	}

	//Eser baskasinda mi kontrolu
	if (KayitKontrol(odunc.isbn, "odunc.txt"))
	{
		cout << "Girilen ISBN numarasina sahip eser bir baskasi tarafindan odunc alinmistir.";
		return;
	}

	cout << "Eseri odunc alacak kullanicinin uye numarasi : ";
	cin >> uyeNo;

	//Eseri almak isteyen kullanicinin var olup olmadigi kontrolu
	if (KayitKontrol(uyeNo, "okuyucu.txt") == 0)
	{
		cout << "Girilen uye numarasina sahip bir kullanici bulunamadi.";
		return;
	}

	odunc.tcNo = TcBul(uyeNo);
	cout << "Kitabin alinma tarihi : ";
	cin >> odunc.almaTarihi;
	cout << "Kitabin iade tarihi   : ";
	cin >> odunc.iadeTarihi;

	ofstream dosyayaz;
	dosyayaz.open("odunc.txt", ios::app);
	dosyayaz << odunc.isbn << "\t" << odunc.tcNo << "\t" << odunc.almaTarihi << "\t" << odunc.iadeTarihi << "\n";

	dosyayaz.close();
	cout << "Kitap odunc alma tamamlandi\n";
}

void OkuyucuKitaplariListele() {	//Kullanicidaki kitaplari listeler

	int alinanUyeNo;
	cout << "Uzerindeki kitaplari listelemek istediginiz kullanicinin uye numarasi: ";
	cin >> alinanUyeNo;

	//Okuyucunun var olup olmama kontrolu
	if (KayitKontrol(alinanUyeNo, "okuyucu.txt")==0)
	{
		cout << "Girdiginiz uye numarasina sahip kullanici bulunamadi.";
		system("pause");
		return;
	}

	ifstream dosyaoku;
	ifstream idosyaoku;
	dosyaoku.open("odunc.txt");
	idosyaoku.open("odunc.txt");
	string line;
	oduncVerilen odunc;

	cout << "ISBN\t\t\t" << "Uye Numarasi\t\t" << "Alma Tarihi\t\t\t" << "Iade Tarihi\n";
	//Dosya satir satir okundukca calisan dongu
	while (getline(idosyaoku, line))
	{
		dosyaoku >> odunc.isbn >> odunc.tcNo >> odunc.almaTarihi >> odunc.iadeTarihi;
		
		//TC numarasi ayni ise kontrolu
		if (odunc.tcNo == TcBul(alinanUyeNo))
		{
			cout << odunc.isbn << "\t" << odunc.tcNo << "\t" << odunc.almaTarihi << "\t" << odunc.iadeTarihi << "\n";
		}
		
	}
	dosyaoku.close();

}

void IdIleOduncSil(int uyeNo) {

	oduncVerilen odunc;
	ifstream dosyaoku;
	ifstream idosyaoku;
	ofstream dosyayaz;
	dosyaoku.open("odunc.txt");
	idosyaoku.open("odunc.txt");
	dosyayaz.open("odunc_sil.txt", ios::app);
	string line;

	//Satir satir okundukca calisan dongu
	while (getline(idosyaoku, line))
	{
		dosyaoku >> odunc.isbn >> odunc.tcNo >> odunc.almaTarihi >> odunc.iadeTarihi;
		//TC Numarasi esit degilse temp dosyaya yazan esitse yazmayan kod blogu
		if (odunc.tcNo != TcBul(uyeNo))
		{
			dosyayaz << odunc.isbn << "\t" << odunc.tcNo << "\t" << odunc.almaTarihi << "\t" << odunc.iadeTarihi << "\n";
		}
	}

	dosyaoku.close();
	dosyayaz.close();
	idosyaoku.close();

	remove("odunc.txt");
	rename("odunc_sil.txt", "odunc.txt");
	cout << "Kayit silindi!\n";
	
}

void KitapIade() {

	int isbn;
	oduncVerilen odunc;
	int alinanUyeNo;

	cout << "Iade edecek kullanicinin uye numarasi : ";
	cin >> alinanUyeNo;

	//Girilen uye numarasina sahip kullanici var mi kontrolu
	if (KayitKontrol(alinanUyeNo , "okuyucu.txt") == 0) {
		cout << "Girilen uye numarasina sahip kullanici bulunamadi.";
		return;
	}

	cout << "Iade edecek eserin ISBN numarasi : ";
	cin >> isbn;

	//ISBN numarasina sahip eser var mi kontrolu
	if (KayitKontrol(isbn, "kitaplar.txt") == 0) {
		cout << "Girilen ISBN numarasina sahip eser bulunamadi.";
		return;
	}

	ifstream idosyaoku;
	ifstream dosyaoku;
	ofstream dosyayaz;
	dosyaoku.open("odunc.txt");
	idosyaoku.open("odunc.txt");
	dosyayaz.open("odunc_sil.txt", ios::app);
	string line;

	//Dosya satir satir okundukca calisan dongu
	while (getline(idosyaoku,line))
	{
		dosyaoku >> odunc.isbn >> odunc.tcNo >> odunc.almaTarihi >> odunc.iadeTarihi;

		//ISBN esit degilken calisir
		if (odunc.isbn != isbn)
		{
			dosyayaz << odunc.isbn << "\t" << odunc.tcNo << "\t" << odunc.almaTarihi << "\t" << odunc.iadeTarihi << "\n";
		}
	}

	dosyaoku.close();
	dosyayaz.close();
	idosyaoku.close();

	remove("odunc.txt");
	rename("odunc_sil.txt", "odunc.txt");
	cout << "Iade Tamamlandi!\n";

}

bool SifreDogruMu(string username, string parola) {

	//Kullanici adinin var olup olmadigini kontrol eder ilk olarak
	if (KullaniciVarMi(username, "kullanicilar.txt"))
	{
		kullanici kullanici;
		ifstream dosyaoku;
		dosyaoku.open("kullanicilar.txt");
			
		//Dosya okundugu surece calisir
		while (dosyaoku >> kullanici.username >> kullanici.parola)
		{
			if (username == kullanici.username)	//Username dogru mu 
			{
				if (parola == kullanici.parola) //Parola dogru mu
				{
					return true;
				}
			}
		}
		dosyaoku.close();
	}
	return false;
}

void UserLog(string kullaniciAdi, time_t dtStart) { //Sisteme giris yapan kullanicilarin giris cikis hareketlerini raporlar

	ofstream logDosyaYaz;
	time_t end_time = time(NULL);

	logDosyaYaz.open("loglar.txt", ios::app);

	char str[26];
	char end[26];
	ctime_s(str, sizeof str, &dtStart);
	ctime_s(end, sizeof end, &end_time);

	logDosyaYaz << kullaniciAdi << "\t" << str << "\t" << end << "\n";
	logDosyaYaz.close();
}

string TcBul(int uyeNo) {	//Uye numarasindan TC bulup donduren fonksiyon

	ifstream dosyaoku;
	ifstream idosyaoku;
	dosyaoku.open("okuyucu.txt");
	idosyaoku.open("okuyucu.txt");
	string line;
	okuyucu okuyucu;

	//Dosya satir satir okundukca calisan dongu
	while (getline(idosyaoku, line))
	{
		dosyaoku >> okuyucu.uyeNo >> okuyucu.ad >> okuyucu.soyad >> okuyucu.tcNo >> okuyucu.telNo >> okuyucu.dogumTarihi >> okuyucu.gorev >> okuyucu.maxKitap;
		if (okuyucu.uyeNo == uyeNo)
		{
			return okuyucu.tcNo;
		}
	}
	dosyaoku.close();
	return "";

}
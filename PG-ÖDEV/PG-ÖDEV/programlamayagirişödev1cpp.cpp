/******************************************************************************
*                                                                            **
**					SAKARYA ÜNÝVERSÝTESÝ                                     **  
**			BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                        ** 
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                           **
**				PROGRAMLAMAYA GÝRÝÞÝ DERSÝ                                   **
**                                                                           ** 
**				ÖDEV NUMARASI: 1                                             **
**				ÖÐRENCÝ ADI :SUDE NAZ ÇÝMEN                                  ** 
**				ÖÐRENCÝ NUMARASI.: G231210001                                **
**				DERS GRUBU: A                                                **
*******************************************************************************/




#include <iostream>
#include <time.h>
using namespace std;

struct Ogrenci {
    int id;
    string isim;
    string soyisim;
    int vize;
    int ksinav1;
    int ksinav2;
    int odev1;
    int odev2;
    float puan_notu;
    string harf_notu;
};

string harf_not_arr[] = { "AA","BA","BB","CB","CC","DC","DD","FD","FF"};


string get_Harf_Notu ( float puan_notu ) {
    if (puan_notu >= 90 && puan_notu <= 100) {
        return harf_not_arr[0];
    }
    else if (puan_notu >= 85 && puan_notu <= 89.99) {
        return harf_not_arr[1];
    }
    else if (puan_notu >= 80 && puan_notu <= 84.99) {
        return harf_not_arr[2];
    }
    else if (puan_notu >= 75 && puan_notu <= 79.99) {
        return harf_not_arr[3];
    }
    else if (puan_notu >= 65 && puan_notu <= 74.99) {
        return harf_not_arr[4];
    }
    else if (puan_notu >= 58 && puan_notu <= 64.99) {
        return harf_not_arr[5];
    }
    else if (puan_notu >= 50 && puan_notu <= 57.99) {
        return harf_not_arr[6];
    }
    else if (puan_notu >= 40 && puan_notu <= 49.99) {
        return harf_not_arr[7];
    }
    else if (puan_notu >= 0 && puan_notu <= 39.99) {
        return harf_not_arr[8];
    }
}

int main(){
    int ksinav_agirlik, vize_agirlik, odev_agirlik, puan_etkisi, yil_sonu_notu, ogrenci_sayisi, agirlik_toplam, say;
    string isim[20] = {"Ali","Ayse","Mehmet","Fatma","Ahmet","Cem","Cenk","Hamza","Burak","Onur","Sude","Ugur","Ozgu","Sinem","Ebrar","Esma","Bengisu","Ege","Oyku","Sena"};
    string soyisim[20] = { "Kaptan","Cimen","Uysal","Kara","Bayram","Kucuk","Alpay","Albay","Ugurlu","Ozen","Orhon","Ertas","Aktas","Kutlu","Karakurt","Dogandemir","Beylice","Cavdar","Vurdem","Celtik" };
    float toplam = 0.0, ort, std_sapma = 0.0, max_not, min_not ;

    //Degiskenler klavyeden aliniyor.
    cout << "\nKisa sinavlarin agirligini giriniz (%) : ";
    cin >> ksinav_agirlik  ;

    cout << "\nVizelerin agirligini giriniz (%) : ";
    cin >> vize_agirlik;

    cout << "\nOdevlerin agirligini giriniz (%) : ";
    cin >> odev_agirlik;

    agirlik_toplam = ksinav_agirlik + vize_agirlik + odev_agirlik;

    // yuzdelerin toplami kontrol ediliyor
    if (agirlik_toplam != 100) {
        cout << "\nAgirlik toplamlari 100 etmelidir  ";
        return 0;
    }

    cout << "\nYil ici puaninin gecme notuna etkisini giriniz (%) : ";
    cin >> puan_etkisi;

    cout << "\nSinifin ogrenci sayisini giriniz: " ;
    cin >> ogrenci_sayisi;


    // her calistirmada farkli random sayilar uretmesi icin eklendi.
    srand(time(0));

    // dizi boyutu sabit olmadigi icin bu sekilde bir cozum bulundu 
    Ogrenci* ogrenciler = new Ogrenci [ogrenci_sayisi];

    // ogrenci veri yapisinin ici dolduruluyor.
    for (int i = 0; i < ogrenci_sayisi; i++) {
        //cout << rand() % ogrenci_sayisi << "\n";
        ogrenciler[i].id = i + 1;
        ogrenciler[i].isim = isim[rand() % 20 ];
        ogrenciler[i].soyisim = soyisim[rand() % 20];
        if (i < ogrenci_sayisi * 0.2) {
            ogrenciler[i].vize = rand() % 20 + 80; //80-100 arasi
            ogrenciler[i].ksinav1 = rand() % 20 + 80;
            ogrenciler[i].ksinav2 = rand() % 20 + 80;
            ogrenciler[i].odev1 = rand() % 20 + 80;
            ogrenciler[i].odev2 = rand() % 20 + 80;
        } else if (i < ogrenci_sayisi * 0.7) { 
            ogrenciler[i].vize = rand() % 30 + 50; //50-80 arasi
            ogrenciler[i].ksinav1 = rand() % 30 + 50;
            ogrenciler[i].ksinav2 = rand() % 30 + 50;
            ogrenciler[i].odev1 = rand() % 30 + 50;
            ogrenciler[i].odev2 = rand() % 30 + 50;
        }
        else {
            ogrenciler[i].vize = rand() % 50; //0-50 arasi
            ogrenciler[i].ksinav1 = rand() % 50;
            ogrenciler[i].ksinav2 = rand() % 50;
            ogrenciler[i].odev1 = rand() % 50;
            ogrenciler[i].odev2 = rand() % 50;
        }
        ogrenciler[i].puan_notu = (vize_agirlik * ( ogrenciler[i].vize ) / 100) + (odev_agirlik * ( (ogrenciler[i].odev1 + ogrenciler[i].odev2) / 2  ) / 100) +
            (ksinav_agirlik * ( (ogrenciler[i].ksinav1 + ogrenciler[i].ksinav2) /2 ) / 100);
        //cout << "Puan notu : " << ogrenciler[i].puan_notu;
        ogrenciler[i].harf_notu = get_Harf_Notu(ogrenciler[i].puan_notu);
        cout << "\n" << ogrenciler[i].id << "-" << ogrenciler[i].isim << " " << ogrenciler[i].soyisim << " : " << ogrenciler[i].harf_notu;
        toplam += ogrenciler[i].puan_notu;
    }

    ort = toplam / ogrenci_sayisi; 

    max_not = ogrenciler[0].puan_notu; 
    min_not = ogrenciler[0].puan_notu;

    // hesaplamalar icin eklendi
    for (int i = 0; i < ogrenci_sayisi; i++) {
        std_sapma += pow(ogrenciler[i].puan_notu - ort, 2); 
        if (ogrenciler[i].puan_notu > max_not)
            max_not = ogrenciler[i].puan_notu;
        if (ogrenciler[i].puan_notu < min_not)
            min_not = ogrenciler[i].puan_notu;

    }

    std_sapma =sqrt (sqrt ( std_sapma / ogrenci_sayisi ));

    cout << "\n\n****************************************";
    cout << "\nSinif Ortalamasi : " << ort;
    cout << "\nSinif Standart Sapmasi : " << std_sapma;
    cout << "\nSinif En Yuksek Notu : " << max_not ; 
    cout << "\nSinif En Dusuk Notu : " << min_not; 

    cout << "\n";

    for (int y = 0; y < 9; y++) {
        say = 0;
        for (int i = 0; i < ogrenci_sayisi; i++)
            if (ogrenciler[i].harf_notu == harf_not_arr[y])
                say++;
        cout << "\n" << harf_not_arr[y] << " " << say << " - %" << ( 100 * say / ogrenci_sayisi );
    }
    cout << "\n****************************************\n";
    return 0;
}

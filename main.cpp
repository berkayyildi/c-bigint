#include <iostream>	//Std Lib
#include <fstream>	//File icin
#include <cmath>	//ABS icin

using namespace std;
#include "thinkbigger.h"

int main()
{

	ThinkBigger islemler = ThinkBigger();	//CARPIM FONKSIYONUNDA ELDE TAM 10 GIBI OLUNCA HATA VAR MI KONTROL ET
	
	islemler.createBigInt("input.txt");		//Metin Belgesinden okur
	
	//islemler.update(0, "2");				//Okunan sayiyi update eder update(update edilecek sayi index, yeni sayi)
	
	//islemler.update(1, "7");				//Okunan sayiyi update eder update(update edilecek sayi index, yeni sayi)
	
	islemler.run();							//İşlemleri Yapar
	
	islemler.save("outout.txt");			//Sonucu Txt ye kaydet
	
	return 0;
 
}


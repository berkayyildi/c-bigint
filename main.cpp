#include <iostream>	//Std Lib
#include <fstream>	//File icin
#include <cmath>	//ABS icin
using namespace std;
#include "thinkbigger.h"


int main()
{
	
ThinkBigger islemler = ThinkBigger();

islemler.createBigInt(islemler.tokens, islemler.sayilarim);

DoublyLinkedList <int> sonuc;
islemler.addBigInt(0,1,sonuc);	//ELDE TAM 10 OLDUGUNDA SIKINTI VAR MI??
cout << sonuc;	//BU FONSIYON SAYILARI BOZUYOR BI SEKILDE ONU ENGELLE DEGER OLARAK YOLLA YADA BI KOPYASINI OLUSTURUP ORDA ISLEM YAP

/*
DoublyLinkedList <int> sonuc2;
multiplyBigInt(*sayilarim[0],*sayilarim[1],sonuc2);	//CARPMAYI TOPLAMANIN n KEZ TEKRARLANısı YAPSAK?
cout << sonuc2;
*/
    return 0;
 
}


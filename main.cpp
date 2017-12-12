#include <iostream>	//Std Lib
#include <fstream>	//File icin
#include <cmath>	//ABS icin
using namespace std;
#include "thinkbigger.h"

int main()
{

ThinkBigger islemler = ThinkBigger();

//ILK CARPIMIN SONUCUNU BASIYOR 2. SI YOK ORTADA ???
for (int i=0 ; i < islemler.tokens.size() ; i++){
	if (islemler.tokens.nth_eleman(i) == '*'){
			cout << "islem: " << islemler.sayilarim[i][0] <<  islemler.tokens.nth_eleman(i) << islemler.sayilarim[i+1][0]  << endl;
			islemler.multiplyBigInt(i,i+1,i);	//(Sayı , Sayı, Save Pos.)
			cout << "Sonuc (Saved Position " << i << " ) :"  << islemler.sonuclar[i][0]  << endl;
	}
}
//Burada saved positionlardaki sayılar toplatılacak



/*
islemler.addBigInt(0,1,0);			// (Sayı , Sayı, Save Pos.)
cout << islemler.sonuclar[0][0];	//BU FONSIYON SAYILARI BOZUYOR BI SEKILDE ONU ENGELLE DEGER OLARAK YOLLA YADA BI KOPYASINI OLUSTURUP ORDA ISLEM YAP
*/


/*

islemler.multiplyBigInt(0,1,0);	//(Sayı , Sayı, Save Pos.)
cout << islemler.sonuclar[0][0];

cout << "\nislem tamamlandi";
*/

    return 0;
 
 
}


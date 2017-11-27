#include <iostream>	//Std Lib
#include <fstream>	//File icin
#include <cmath>	//ABS icin
using namespace std;
#include "thinkbigger.h"


int main()
{

ThinkBigger islemler = ThinkBigger();

cout << islemler.tokens;
/*
islemler.addBigInt(0,1,0);	//ELDE TAM 10 OLDUGUNDA SIKINTI VAR MI?? (Sayı , Sayı, Save Pos.)
cout << islemler.sonuclar[0][0];	//BU FONSIYON SAYILARI BOZUYOR BI SEKILDE ONU ENGELLE DEGER OLARAK YOLLA YADA BI KOPYASINI OLUSTURUP ORDA ISLEM YAP
*/

islemler.multiplyBigInt(0,1,0);	//(Sayı , Sayı, Save Pos.)
//cout << islemler.sonuclar[0][0];

cout << "\nislem tamamlandi";
    return 0;
 
}


#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#define MAX_NUM 5
#define MAX_LEN 50

template<class T>
class DLLNode {
public:
    DLLNode() {
        next = prev = 0;
    }
    DLLNode(const T& el, DLLNode<T> *n = 0, DLLNode<T> *p = 0) {
        info = el; next = n; prev = p;
    }
    T info;
    DLLNode<T> *next, *prev;
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head = tail = 0;
    }
    void addToDLLTail(const T&);
    T deleteFromDLLTail();
    ~DoublyLinkedList() {
        clear();
    }
    bool isEmpty() const {
        return head == 0;
    }
    DLLNode<T>* gettail()  {//TAIL DONDUREN FUNC
        return tail;
    }
    DLLNode<T>* gethead()  {//TAIL DONDUREN FUNC
        return head;
    }
    void clear();
    int size();				//SIZE VEREN FOKNSIYON
    T nth_eleman(int elem);	//SIRADAN YAZAN FONKSIYON
    void setToNull() {
        head = tail = 0;
    }
    void addToDLLHead(const T&);
    T deleteFromDLLHead();
    T& firstEl();
    T* find(const T&) const;
protected:
    DLLNode<T> *head, *tail;
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
        for (DLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next)
            //out << tmp->info << ' ';
            out << tmp->info;
        return out;
    }
};

template<class T>
int DoublyLinkedList<T>::size() {	//SIZE VEREN FONKSIYONUMUZ
    DLLNode<T> *tmp = head;
    int size = 0;
    for ( ; tmp != 0; tmp = tmp->next){	size++;	}
    return size;
}

template<class T>
T DoublyLinkedList<T>::nth_eleman(int elem) {	//n inci elemani veren (iterator gibi yapmak zor :( )
    
    DLLNode<T> *tmp = head;
   
    for (int i = 0 ; tmp != 0 && i<elem; tmp = tmp->next){i++;};
    return tmp->info;	//SON ELEMANI BASARKEN SIKINTI VAR MI BAK
    
}

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el) {
    if (head != 0) {
         head = new DLLNode<T>(el,head,0);
         head->next->prev = head;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el) {
    if (tail != 0) {
         tail = new DLLNode<T>(el,0,tail);
         tail->prev->next = tail;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead() {
    T el = head->info;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
         head = head->next;
         delete head->prev;
         head->prev = 0;
    }
    return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail() {
    T el = tail->info;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
         tail = tail->prev;
         delete tail->next;
         tail->next = 0;
    }
    return el;
}

template <class T>
T* DoublyLinkedList<T>::find(const T& el) const {
    DLLNode<T> *tmp = head;
    for ( ; tmp != 0 && !(tmp->info == el);  // overloaded ==
         tmp = tmp->next);
    if (tmp == 0)
         return 0;
    else return &tmp->info;
}

template<class T>
T& DoublyLinkedList<T>::firstEl() {
    return head->info;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    for (DLLNode<T> *tmp; head != 0; ) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}



//----------------------------------------------------------------------


class ThinkBigger {
public:

    //ThinkBigger() {	}	//Otomatik Çalıştırır
    void createBigInt(string s);
    void run();			
    void save(string s);
    void update(int sayino, string s);	//OVERLOADED KULLANICININ KULLANACAGI NORMALI PRIVATE DLL,DLL
    
private:
	DoublyLinkedList <char> tokens;							//Tokenleri depola char linked list (Once tokens yaratilmali)
	DoublyLinkedList <int> *sayilarim[MAX_NUM];				//Sayıları depolamak icin pointer array yarat
    DLLNode<int>* gettail(DoublyLinkedList <int> &dll)  {
        return dll.gettail();
    }
    DLLNode<int>* gethead(DoublyLinkedList <int> &dll)  {
        return dll.gethead();
    }
	void update(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2);
	void addBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2, DoublyLinkedList <int>  &save_dllist);
	void subBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2, DoublyLinkedList <int>  &save_dllist);
	void divBigInt		(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2);
	void multiplyBigInt	(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2);
};

void ThinkBigger::run(){		//Bitisik çarpma işlemlerini yap sonuclari bitisiklerin solundaki sayiya kaydet, Carpmada kullanilan diger sayilari 0 yap

	int now_multp_index = -1;					//Bitisik islemlerde sikinti ciktigi icin bitisiklerde soldakine yazdirmasi icin
	for (int i=0 ; i < tokens.size() ; i++){
		if (tokens.nth_eleman(i) == '*'){
			
				if (now_multp_index == -1 ) {now_multp_index = i;}
				multiplyBigInt(*sayilarim[now_multp_index],*sayilarim[i+1]);	//(Sayı , Sayı, Sonuclar Arrayi Save Index)
				sayilarim[i+1]->clear();										//Carpimda kullanilan sayilari sifirla
				sayilarim[i+1]->addToDLLHead(0);
		}else{
			now_multp_index = -1;
		}
					
	}
	
	
	
/*
	int now_div_index = -1;								//BOLME BURADA YAPICAK
	for (int i=0 ; i < tokens.size() ; i++){
		if (tokens.nth_eleman(i) == '/'){
			
				if (now_div_index == -1 ) {now_div_index = i;}
				divBigInt(*sayilarim[now_div_index],*sayilarim[i+1]);	//(Sayı , Sayı, Sonuclar Arrayi Save Index)
				sayilarim[i+1]->clear();										//Carpimda kullanilan sayilari sifirla
				sayilarim[i+1]->addToDLLHead(0);
		}else{
			now_div_index = -1;
		}
					
	}


		DoublyLinkedList <int> eksi_toplam;
		DoublyLinkedList <int> eksi_temp;

		for (int i=0 ; i < tokens.size() ; i++){
						
			if (tokens.nth_eleman(i) == '-'){

				addBigInt(eksi_toplam,*sayilarim[i+1],eksi_temp);
				sayilarim[i+1]->clear();	//Eksi olan sayilari sil
				update(eksi_toplam, eksi_temp );
				eksi_temp.clear();
					
			}
		}
*/



	DoublyLinkedList <int> toplam_sayilar_temp;

	//Burada 0 lar disinda kalan sayilar yani toplama lar yapilacak
	for (int i=0 ; i < tokens.size() ; i++){								//cout << "ZAA: "  << *sayilarim[i]  << endl;
			addBigInt(*sayilarim[0],*sayilarim[i+1],toplam_sayilar_temp);	//ilk 2 elemanı topla temp'e yaz
			update(*sayilarim[0], toplam_sayilar_temp );					//temp toplamı ilk elemana yaz
			toplam_sayilar_temp.clear();									//temp toplami temizle
	}
	
	
	
}

void ThinkBigger::save(string s){
	

	if (gethead(*sayilarim[0])->info == 0){	//Ilk eleman sifirsa ilk elemani sil
		sayilarim[0]->deleteFromDLLHead();
	}

	cout << "FINAL RESULT :" << *sayilarim[0] << endl; 	//Sonucu terminale yazs
	
	const char *cstr = s.c_str();	//freopen fonksiyonu parametre olarak char istiyor
	
	freopen(cstr,"w",stdout);		//istenen dosya isminde kayit yap
	
    cout << *sayilarim[0];			//Sonucu dosyaya yazdır
	
}

void ThinkBigger::addBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2, DoublyLinkedList <int>  &save_dllist){

	
	int fark = dll1.size()-dll2.size();
	int abs_fark = abs(dll1.size()-dll2.size());
	int elde = 0;
	int toplam;

	for (int i=0 ; i < abs_fark ; i++){					//KUCUK SAYININ SOL BOSLUGUNU 0 LA DOLDUR
		if (fark > 0){	dll2.addToDLLHead(0);	}	else {	dll1.addToDLLHead(0);	}
	}
	
	
	DLLNode<int> *tmp_tail_1 = gettail(dll1);
	DLLNode<int> *tmp_tail_2 = gettail(dll2);


	for (int i=0 ; i < dll1.size() ; i++){				//SIZE FARKETMEZ ZATEN ESIT LOOP ICINDE TOPLA

		toplam = tmp_tail_1->info + tmp_tail_2->info + elde;
		
		if (toplam >= 10){toplam = toplam - 10; elde =1;}else{elde = 0;}
		
		save_dllist.addToDLLHead(toplam);
		
		tmp_tail_1 = tmp_tail_1->prev;
		tmp_tail_2 = tmp_tail_2->prev;
		
	}

	if (elde == 1){	save_dllist.addToDLLHead(elde);	}	//ELDE VARSA DA EKLE SON OLARAK
	
	for (int i=0 ; i < abs_fark ; i++){					//EKLENEN 0 LARI TEMIZLE
		if (fark > 0){	dll2.deleteFromDLLHead();	}	else {	dll1.deleteFromDLLHead();	}
	}
	
}

/*
void ThinkBigger::subBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2, DoublyLinkedList <int>  &save_dllist){

	
	int fark = dll1.size()-dll2.size();
	int abs_fark = abs(dll1.size()-dll2.size());
	int elde = 0;
	int toplam;
	
	for (int i=0 ; i < abs_fark ; i++){					//KUCUK SAYININ SOL BOSLUGUNU 0 LA DOLDUR
		if (fark > 0){	dll2.addToDLLHead(0);	}	else {	dll1.addToDLLHead(0);	}
	}
	
   
	DLLNode<int> *tmp_tail_1 = gettail(dll1);
	DLLNode<int> *tmp_tail_2 = gettail(dll2);

	for (int i=0 ; i < dll1.size() ; i++){				//SIZE FARKETMEZ ZATEN ESIT LOOP ICINDE TOPLA

		
		toplam = tmp_tail_1->info - tmp_tail_2->info - elde;
		
		if (toplam < 0){toplam = toplam + 10; elde =1;}else{elde = 0;}
		
		save_dllist.addToDLLHead(toplam);
		
		
		tmp_tail_1 = tmp_tail_1->prev;
		tmp_tail_2 = tmp_tail_2->prev;
		
	}

	//if (elde == 1){	save_dllist.addToDLLHead(elde);	}	//ELDE VARSA DA EKLE SON OLARAK (Hep buyukten kucuk cikardigimizdan buna gerek yok heralde)

	//for (int i=0 ; i < abs_fark ; i++){					//EKLENEN 0 LARI TEMIZLE
	//	if (fark > 0){	dll2.deleteFromDLLHead();	}	else {	dll1.deleteFromDLLHead();	}
	//}
	
}

*/

void ThinkBigger::update(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2){	// dll 1 = dll2 yapar

	dll1.clear();
	
	DLLNode<int> *tmp_tail_2 = gettail(dll2);

	for (int i=0 ; i < dll2.size() ; i++){	//SIZE FARKETMEZ ZATEN ESIT

		dll1.addToDLLHead(tmp_tail_2->info);
		tmp_tail_2 = tmp_tail_2->prev;
	}

}


void ThinkBigger::update(int sayino, string s){	// dll 1 = string s yapar ==OVERLOADED OLAN

	unsigned int tokensize = tokens.size();	
	unsigned int usayino = sayino;
	if (usayino > tokensize || usayino < 0){cout << "Update Error\n"; return;}
	
	DoublyLinkedList<int> *sayimiz =  sayilarim[sayino];
	
	sayimiz->clear();
	
	unsigned int sizeim = s.size();	//Hata vermesin diye compiler once unsigned yap
	
	for (unsigned int i = sizeim-1 ; i < sizeim ; i--){
		sayimiz->addToDLLHead(s[i] - 48);
	}

}


void ThinkBigger::createBigInt(string s){
		
char temp_char;
int sayi_index = 0;										//sayi indexlerini saydir

sayilarim[sayi_index] = new DoublyLinkedList<int>();	//constructur i cagir donen mem adresini pointer array e kaydet ilk sayiyi dma ile olustur

ifstream fin;

const char *cstr = s.c_str();	//ifstream fonksiyonu parametre olarak char istiyor

fin.open(cstr, ios::in);

	while (!fin.eof() ) {
	
	fin.get(temp_char);		//cout << temp_char;

		if (temp_char == ' '){
			continue;
		}
		else if (temp_char == '\n'){
			break;
		}
		else if (temp_char == '*' || temp_char == '+'|| temp_char == '-' || temp_char == '/'){
			tokens.addToDLLTail(temp_char);
			sayi_index++;												//Sayi indexini arttir
			sayilarim[sayi_index] = new DoublyLinkedList<int>();		//constructur i cagir donen mem adresini pointer array e kaydet
		}
		else{
			sayilarim[sayi_index]->addToDLLTail(temp_char-48);			//olusan pointer array adresinden sayiyi bul ve ekle (char to int convert yap ayrica)
		}
	}

}




void ThinkBigger::multiplyBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2){

	DoublyLinkedList <int> *multiply_sum_cache[50*50*50];							//Carpim temp for sum
	
	DoublyLinkedList <int> temp_dll1;
	
	update(temp_dll1,dll1);

	int carpim = 0;
	int elde = 0;
	
	DLLNode<int> *tmp_tail_1 = gettail(temp_dll1);
	
	for (int i=0 ; i < temp_dll1.size() ; i++){	
		
		multiply_sum_cache[i] = new DoublyLinkedList<int>();
		for (int k=0 ; k < i ; k++){	multiply_sum_cache[i]->addToDLLHead(0); }	// 0 ekle i sayisi kadar ki toplarken bir sola kaymis gibi olsun
		
		DLLNode<int> *tmp_tail_2 = gettail(dll2);
		
		for (int j=0 ; j < dll2.size() ; j++){	

		
			carpim = (tmp_tail_2->info * tmp_tail_1->info) + elde;				//Elemanlari n2 for loopla carp eldeyi ekle hep
			elde = 0;					//Elde eklendi - Reset Elde 
			while (carpim > 10){		//10 dan kücük olana kadar 10 ar azalt eldeyi 1 arttir
				carpim -= 10; elde++;
			}
			
			multiply_sum_cache[i]->addToDLLHead(carpim);

			tmp_tail_2 = tmp_tail_2->prev;

		}
		
		tmp_tail_1 = tmp_tail_1->prev;
		
		multiply_sum_cache[i]->addToDLLHead(elde);								//Carpma toplam satiri bitimine eldeyi ekle

		elde = 0; carpim = 0; //Reset Elde & Carpim
	}


	//---------------------------------------------------------------------- (Burda Carpimin Cachesindeki sayialr toplanir)
	DoublyLinkedList <int> toplam_temp;
		
	for (int i=0; i < temp_dll1.size()-1; i++){								// temp_dll1 kadar yani alttaki sayinin basamak sayisi kadar toplama yapilacak

		addBigInt(*multiply_sum_cache[0],*multiply_sum_cache[i+1],toplam_temp);	//ilk 2 elemanı topla temp'e yaz
		
		update(*multiply_sum_cache[0], toplam_temp );								//temp toplamı ilk elemana yaz
		
		toplam_temp.clear();														//temp toplami temizle

	}

	update(dll1, *multiply_sum_cache[0] );						//Son olarak istenilen indexe cachedeki sayıyı geçir

	//cout << "Carpma Sonucumuz : " << *multiply_sum_cache[0] << endl;

	//----------------------------------------------------------------------


}
/*
void ThinkBigger::divBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2){

	DoublyLinkedList <int> *multiply_sum_cache[50*50*50];							//Carpim temp for sum
	
	DoublyLinkedList <int> temp_dll1;
	
	update(temp_dll1,dll1);

	int carpim = 0;
	int elde = 0;
	
	DLLNode<int> *tmp_tail_1 = gettail(temp_dll1);
	
	for (int i=0 ; i < temp_dll1.size() ; i++){	
		
		multiply_sum_cache[i] = new DoublyLinkedList<int>();
		for (int k=0 ; k < i ; k++){	multiply_sum_cache[i]->addToDLLHead(0); }	// 0 ekle i sayisi kadar ki toplarken bir sola kaymis gibi olsun
		
		DLLNode<int> *tmp_tail_2 = gettail(dll2);
		
		for (int j=0 ; j < dll2.size() ; j++){	

		
			carpim = (int(tmp_tail_1->info / tmp_tail_2->info)) + elde;				//Elemanlari n2 for loopla carp eldeyi ekle hep
			
			if (carpim < 1){ 
				
				carpim = (int(tmp_tail_1->info+10 / tmp_tail_2->info)) + elde;	
				
				elde = -10;
				
				}else{
			
			elde = +1;					//Elde eklendi - Reset Elde 
			
			}
			
			multiply_sum_cache[i]->addToDLLHead(carpim);

			tmp_tail_2 = tmp_tail_2->prev;

		}
		
		tmp_tail_1 = tmp_tail_1->prev;
		
		//multiply_sum_cache[i]->addToDLLHead(elde);								//Carpma toplam satiri bitimine eldeyi ekle

		elde = 0; carpim = 0; //Reset Elde & Carpim
	}


	//---------------------------------------------------------------------- (Burda Carpimin Cachesindeki sayialr toplanir)
	DoublyLinkedList <int> toplam_temp;
		
	for (int i=0; i < temp_dll1.size()-1; i++){								// temp_dll1 kadar yani alttaki sayinin basamak sayisi kadar toplama yapilacak

		addBigInt(*multiply_sum_cache[0],*multiply_sum_cache[i+1],toplam_temp);	//ilk 2 elemanı topla temp'e yaz
		
		update(*multiply_sum_cache[0], toplam_temp );								//temp toplamı ilk elemana yaz
		
		toplam_temp.clear();														//temp toplami temizle

	}

	update(dll1, *multiply_sum_cache[0] );						//Son olarak istenilen indexe cachedeki sayıyı geçir

	//cout << "Carpma Sonucumuz : " << *multiply_sum_cache[0] << endl;

	//----------------------------------------------------------------------


}
*/
#endif

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
    void clear();
    int size();			//SIZE VEREN FOKNSIYON
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
	
	DoublyLinkedList <char> tokens;							//Tokenleri depola char linked list
	DoublyLinkedList <int> *sayilarim[MAX_NUM];					//Sayıları depolamak icin pointer array yarat
	DoublyLinkedList <int> *sonuclar[MAX_NUM];					//Sonuclari pointer array yarat
	DoublyLinkedList <int> finalimiz;

    ThinkBigger() {
        createBigInt(tokens, sayilarim);	//oku
        run();								//calistir
        save();								//kaydet
    }
    void run();
    void save();
	void addBigInt(int num1,int num2, int save_index);
	void addBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2, DoublyLinkedList <int>  &save_dllist);	//Overload yapildi (Çarpma için kullanılan bu)
	void update(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2);
	void createBigInt(DoublyLinkedList <char> &tokens, DoublyLinkedList <int> *sayilarim[MAX_NUM]);
	void multiplyBigInt(int num1,int num2, int save_index);
};

void ThinkBigger::run(){

int carpim_Save_index = 0;

	//Çarpma işlemlerini yap index 0 dan carpim_Save_index e kadar sonuclar arraye kaydedildi, Carpmada kullanilan sayilari sonradan 0 yap
	for (int i=0 ; i < tokens.size() ; i++){
		if (tokens.nth_eleman(i) == '*'){
				//cout << "islem: " << sayilarim[i][0] <<  tokens.nth_eleman(i) << sayilarim[i+1][0]  << endl; //SON TEST ICIN
				multiplyBigInt(i,i+1,carpim_Save_index);	//(Sayı , Sayı, Save Pos.)
				
				//cout << "Sonuc Position " << carpim_Save_index << "):"  << sonuclar[carpim_Save_index][0]  << endl; //SON TEST ICIN
				carpim_Save_index++;		
				
				//cout << "Silinesi index " << i+1 << "):"  << sayilarim[i+1][0]  << endl;
				//update(sayilarim[i][0], sonuclar[carpim_Save_index][0]);
				
			
				sayilarim[i+1]->clear();
				sayilarim[i]->clear();
				sayilarim[i+1]->addToDLLHead(0);
				sayilarim[i]->addToDLLHead(0);
		}
	}


DoublyLinkedList <int> toplam_sayilar_temp;


	//Burada 0 lar disinda kalan sayilar yani toplama lar yapilacak
	for (int i=0 ; i < tokens.size() ; i++){	//cout << "ZAA: "  << sayilarim[i][0]  << endl;
		
			addBigInt(sayilarim[0][0],sayilarim[i+1][0],toplam_sayilar_temp);	//ilk 2 elemanı topla temp'e yaz
			update(sayilarim[0][0], toplam_sayilar_temp );						//temp toplamı ilk elemana yaz
			toplam_sayilar_temp.clear();										//temp toplami temizle

	}
	
	//cout << "YARI: " << sayilarim[0][0] << endl;

	//Burada sonuclar arrayi yani carpim sonuclari  toplanacak
	for (int i=0 ; i < carpim_Save_index-1 ; i++){	//cout << "ZAA: "  << sonuclar[i][0]  << endl;
		
			addBigInt(sonuclar[0][0],sonuclar[i+1][0],toplam_sayilar_temp);		//ilk 2 elemanı topla temp'e yaz
			update(sonuclar[0][0], toplam_sayilar_temp );						//temp toplamı ilk elemana yaz
			toplam_sayilar_temp.clear();										//temp toplami temizle
		
	}
	
	
	//cout << "DIGER YARI: " << sonuclar[0][0] << endl;
	
	
	addBigInt(sayilarim[0][0],sonuclar[0][0],finalimiz);	//ilk 2 elemanı topla temp'e yaz

	
}

void ThinkBigger::save(){
	
		
	cout << "FINAL RESULT :" << finalimiz << endl; 
	
	freopen("outout.txt","w",stdout);
	
    cout << finalimiz;
  

	
}

void ThinkBigger::addBigInt(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2, DoublyLinkedList <int>  &save_dllist){	//OVERLOADED OLAN FONKSIYON  (Çarpma için)


	
	int fark = dll1.size()-dll2.size();
	int abs_fark = abs(dll1.size()-dll2.size());
	int elde = 0;
	int toplam;
	
	for (int i=0 ; i < abs_fark ; i++){					//KUCUK SAYININ SOL BOSLUGUNU 0 LA DOLDUR
		if (fark > 0){	dll2.addToDLLHead(0);	}	else {	dll1.addToDLLHead(0);	}
	}

	for (int i=0 ; i < dll1.size() ; i++){				//SIZE FARKETMEZ ZATEN ESIT LOOP ICINDE TOPLA

		toplam = dll1.nth_eleman(dll1.size()-1-i) + dll2.nth_eleman(dll2.size()-1-i) + elde;
		
		if (toplam >= 10){toplam = toplam - 10; elde =1;}else{elde = 0;}
		
		save_dllist.addToDLLHead(toplam);
	}

	if (elde == 1){	save_dllist.addToDLLHead(elde);	}	//ELDE VARSA DA EKLE SON OLARAK
	
	for (int i=0 ; i < abs_fark ; i++){					//EKLENEN 0 LARI TEMIZLE
		if (fark > 0){	dll2.deleteFromDLLHead();	}	else {	dll1.deleteFromDLLHead();	}
	}

}

void ThinkBigger::update(DoublyLinkedList <int> &dll1, DoublyLinkedList <int> &dll2){	// dll 1 = dll2 yapar

	//cout << endl << "Eski 1: " << dll1 << "Eski 2: " << dll2 << endl;

	dll1.clear();

	for (int i=0 ; i < dll2.size() ; i++){	//SIZE FARKETMEZ ZATEN ESIT

		dll1.addToDLLHead(dll2.nth_eleman(dll2.size()-1-i));
	
	}
	
	//cout << endl << "Yeni 1: " << dll1 << "Yeni 2: " << dll2 << endl;
}


void ThinkBigger::createBigInt(DoublyLinkedList <char> &tokens, DoublyLinkedList <int> *sayilarim[MAX_NUM]){
		
char temp_char;
int sayi_index = 0;										//sayi indexlerini saydir

sayilarim[sayi_index] = new DoublyLinkedList<int>();	//constructur i cagir donen mem adresini pointer array e kaydet ilk sayiyi dma ile olustur

ifstream fin;
fin.open("input.txt", ios::in);

	while (!fin.eof() ) {
	
	fin.get(temp_char);		//cout << temp_char;

		if (temp_char == ' '){
			continue;
		}
		else if (temp_char == '\n'){
			break;
		}
		else if (temp_char == '*' || temp_char == '+'){
			tokens.addToDLLTail(temp_char);
			sayi_index++;												//Sayi indexini arttir
			sayilarim[sayi_index] = new DoublyLinkedList<int>();		//constructur i cagir donen mem adresini pointer array e kaydet
		}
		else{
			sayilarim[sayi_index]->addToDLLTail(temp_char-48);			//olusan pointer array adresinden sayiyi bul ve ekle (char to int convert yap ayrica)
		}
	}

}








void ThinkBigger::multiplyBigInt(int num1,int num2, int save_index){

	DoublyLinkedList <int> *multiply_sum_cache[MAX_LEN];					//Carpim temp for sum
	
	sonuclar[save_index] = new DoublyLinkedList<int>();

	int carpim = 0;
	int elde = 0;
	
	for (int i=0 ; i < sayilarim[num1]->size() ; i++){	
		
		multiply_sum_cache[i] = new DoublyLinkedList<int>();
		for (int k=0 ; k < i ; k++){	multiply_sum_cache[i]->addToDLLHead(0); }	// 0 ekle i sayisi kadar ki toplarken bir sola kaymis gibi olsun
		
		for (int j=0 ; j < sayilarim[num2]->size() ; j++){	
		
			carpim = (sayilarim[num1]->nth_eleman(sayilarim[num1]->size()-1-i)) * (sayilarim[num2]->nth_eleman(sayilarim[num2]->size()-1-j)) + elde;	//Elemanlari n2 for loopla carp eldeyi ekle hep
			elde = 0;					//Elde eklendi - Reset Elde 
			while (carpim > 10){		//10 dan kücük olana kadar 10 ar azalt eldeyi 1 arttir
				carpim -= 10; elde++;
			}
			
			multiply_sum_cache[i]->addToDLLHead(carpim);
			//cout << carpim <<"";
		}
		
		multiply_sum_cache[i]->addToDLLHead(elde);				//Carpma toplam satiri bitimine eldeyi ekle
		//cout << elde <<" \n";
		elde = 0; carpim = 0; //Reset Elde & Carpim
	}


//----------------------------------------------------------------------
DoublyLinkedList <int> toplam_temp;
	
for (int i=0; i < sayilarim[num1]->size()-1; i++){								// dll1 kadar yani alttaki sayinin basamak sayisi kadar toplama yapilacak
	//cout << multiply_sum_cache[i][0] << endl; 								//for debugging
	//cout << "loopcount : " << dll1.size() << endl;
	addBigInt(multiply_sum_cache[0][0],multiply_sum_cache[i+1][0],toplam_temp);	//ilk 2 elemanı topla temp'e yaz
	
	//cout << multiply_sum_cache[0][0] << " + " << multiply_sum_cache[i+1][0] << " = " << toplam_temp << endl;	//for debugging
	
	update(multiply_sum_cache[0][0], toplam_temp );								//temp toplamı ilk elemana yaz
	
	toplam_temp.clear();														//temp toplami temizle
	
	//cout << "Ilk eleman updated to " << multiply_sum_cache[0][0] << endl;		//for debugging

}

update(*sonuclar[save_index], multiply_sum_cache[0][0] );									//Son olarak istenilen indexe cachedeki sayıyı geçir

//cout << "Carpma Sonucumuz : " << multiply_sum_cache[0][0] << endl;

//addBigInt(toplam_temp,multiply_sum_cache[i+1][0],toplam_temp);	//ilk 2 elemanı topla
//----------------------------------------------------------------------

//update(multiply_sum_cache[0][0], multiply_sum_cache[1][0] );


}

#endif

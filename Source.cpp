/////////////////////////////////
///                           ///
///      AUTHOR:  B. S.       ///
///      TEL: 060685260       ///  
///                           ///
/////////////////////////////////


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <MMsystem.h>        // biblioteca pentru audio format .wav  ( in proprietati project ( Alt + F7 ), mergeti la Linker apoi input, apoi Additional Depend. dati edit si introduceti libraria winmm.lib )
#include <time.h>           // biblioteca pentru ora si data

using namespace std;

int i, n,k, j; //variabile globale

char meniu, aux,l,o,baza[30], cauta[50], cauta1[50];  //variabile globale

HANDLE f1; // culoare text
FILE *f;

HWND console = GetConsoleWindow(); // marimea consolei
RECT r;
 

void menu();
void completare();
void afisare();
void eticheta();
void autor();
void cautare();
void adaugare();
void calc_depozit();
void muzic();
void credite();
void gotoxy(int a, int b);
void modificare();
void removes();
void date_time();

typedef struct personal
{
	char nume[50];
	char prenume[50];
	int an_nastere;
	char serie_buletin[20];

	struct depozit
	{
		char num_dep[20];
		char rata_dep[10];
		int suma_dep;
		float rata_dob;
	}depo;
	struct carduri
	{
		char nume_card[30];
		char iban[50];
		long int suma_cont;
		char data_exp[15];
	}card;
	struct credit
	{
		char nume_care[30];
		float rata;
		long int suma_care;
		int term_care;
	}cred;
}clienti;

 clienti x[200];

void main()
{

	f1 = GetStdHandle(STD_OUTPUT_HANDLE);

	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 800, TRUE); 

	autor();

m: system("cls");

	menu();

	switch (meniu)
	{
	case '1': system("cls"); completare(); _getch(); goto m;

	case '2': system("cls"); afisare(); _getch(); goto m;

	case '3': system("cls"); cautare(); _getch(); goto m;

	case '4': system("cls"); adaugare(); _getch(); goto m;

	case '5': system("cls"); calc_depozit(); _getch(); goto m;

	case '6':  system("cls"); credite(); _getch(); goto m;

	case '7':  system("cls"); muzic(); _getch(); goto m;

	case '8': system("cls"); modificare(); _getch(); goto m;

	case '9': system("cls"); removes(); _getch(); goto m;

	case '0': system("cls");
	 gotoxy(3,20); printf(R"EOF(

     ,-----.     ,-------,--.    ,------.,--.    ,---.  ,-----,--. ,--,--------.,---.   
    '  .-.  '    `--.   /|  |    |  .--. |  |   /  O  \'  .--.|  | |  '--.  .--/  O  \  
    |  | |  |      /   / |  |    |  '--' |  |  |  .-.  |  |   |  | |  |  |  | |  .-.  | 
    '  '-'  '     /   `--|  |    |  | --'|  '--|  | |  '  '--''  '-'  '  |  | |  | |  | 
     `-----'     `-------`--'    `--'    `-----`--' `--'`-----'`-----'   `--' `--' `--'                                                       

		 )EOF");

		 _getch();
		exit(1); 

	default: goto m;

	}

	_getch();
}
void completare()
{
	char meniu1;
	SetConsoleTextAttribute(f1, 10);
	cout << "\n\t\t\t # ---> CREAREA BAZEI de DATE <--- # ";
	SetConsoleTextAttribute(f1, 13);
	cout << "\n\n\n\t\t\t Introduceti numarul de clienti: ";  cin >> n;
	system("cls");
	for (i = 0; i < n; i++)
	{
		SetConsoleTextAttribute(f1, 15);
		 cout << "\n Numele " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].nume;
		_strupr(x[i].nume);
		SetConsoleTextAttribute(f1, 15);
		cout << "\n Prenumele " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].prenume;
		_strupr(x[i].prenume);
		SetConsoleTextAttribute(f1, 15);
		cout << "\n Anul nasterii " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].an_nastere;
		SetConsoleTextAttribute(f1, 15);
		cout << "\n Seria Buletinului " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> ( x[i].serie_buletin);
		_strupr(x[i].serie_buletin);
		SetConsoleTextAttribute(f1, 10);
		m0:
		cout << "\n\t\t\t Doriti sa introduceti date bancare: Y/N ? "; l = _getch();
		system("cls");
		if (l == 'Y' || l == 'y')
		{
			SetConsoleTextAttribute(f1, 10);
			cout << "\n\n\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|                ---> DATE BANCARE <---                   |#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			SetConsoleTextAttribute(f1, 11);  cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|        1 -> DEPOZIT        |      3 -> CARDURI          |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|        2 -> CREDITE        |      4 -> Iesire           |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";

			meniu1=_getch();

			switch (meniu1)
			{
			case '1':
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Nume Depozit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.num_dep;
				_strupr(x[i].depo.num_dep);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Rata Depozit " << i + 1 << " client ( float / fix ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.rata_dep;
				_strupr(x[i].depo.rata_dep);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Rata Dobanzii " << i + 1 << " client ( % ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.rata_dob;
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Suma Depozit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.suma_dep;
				
			
				goto m0;
			}
			case '2':
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Nume Credit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin.ignore(100, '\n'); cin.getline(x[i].cred.nume_care, 50);
				_strupr(x[i].cred.nume_care);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Rata Credit " << i + 1 << " client ( % ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].cred.rata;
				_strupr(x[i].prenume);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Termin Credit " << i + 1 << " client ( ani ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].cred.term_care;
                SetConsoleTextAttribute(f1, 15);
				cout << "\n Suma Credit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].cred.suma_care;
				goto m0;
				
			}
			case '3':
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Nume Card " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin.ignore(130, '\n'); cin.getline(x[i].card.nume_card, 50);
				_strupr(x[i].card.nume_card);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n IBAN " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin.getline(x[i].card.iban, 50);
				_strupr(x[i].card.iban);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Data Expirari " << i + 1 << " client ( ex: 20/02/2016 ): "; SetConsoleTextAttribute(f1, 13);  cin >> (x[i].card.data_exp);
                SetConsoleTextAttribute(f1, 15);
				cout << "\n Suma pe cont " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].card.suma_cont;
				
				goto m0;
			}
			case '4': break;
			default: cout << "\n\n Ati tastat un buton necorespunzator 1"; goto m0;;
			}
			_getch();
			system("cls");
		}

	}

	f = fopen("BAZA_de_DATE.txt", "w+");
	for (i = 0; i < n; i++)
	{
		fwrite(&x[i], sizeof(x[i]), 1, f);
	}
	fclose(f);

}
void afisare()
{
	clienti aux;

	f = fopen("BAZA_de_DATE.txt", "r+");
	i = 0;
	while (fread(&x[i], sizeof(x[i]), 1, f) == 1)
	{
		i++;
	}
	n = i; fclose(f);

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(x[i].prenume, x[j].prenume)>0)
			{
				aux = x[i]; x[i] = x[j]; x[j] = aux;
			}
		}
	}
m1: system("cls");
	SetConsoleTextAttribute(f1, 10);
	cout << "\n\n\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|                # ---> BAZA DE DATE <--- #               |#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	SetConsoleTextAttribute(f1, 11);  cout << "\n\t\t|#|                            |                            |#|";
	cout << "\n\t\t|#|     1 -> DATE PERSONALE    |     2 -> DATE BANCARE      |#|";
	cout << "\n\t\t|#|                            |                            |#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|                     3 -> Iesire                         |#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	cout << "\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|\n\n";
	k = 0;
	meniu = _getch();

	switch (meniu)
	{
	case '1':
	{
		system("cls");
		eticheta();
		for (i = 0; i < n; i++)
		{
			k++;
			SetConsoleTextAttribute(f1, 15);
			printf("\n   |*| %2d  |%11s   |%11s   |   %8d      |     %10s   |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].serie_buletin);
			cout << "\n   |*|------------------------------------------------------------------------|*|";
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(f1, 15);
			cout << "\n   |*|      Nu exista nici o persoana in baza de date cu date personale !     |*|";
			cout << "\n   |*|------------------------------------------------------------------------|*|";
		}
		cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
		_getch(); goto m1;
	}
	case '2':
	{    system("cls");
		SetConsoleTextAttribute(f1, 10);
		cout << "\n\n\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
		cout << "\n\t\t|#|---------------------------------------------------------|#|";
		cout << "\n\t\t|#|                                                         |#|";
		cout << "\n\t\t|#|                ---> DATE BANCARE <---                   |#|";
		cout << "\n\t\t|#|                                                         |#|";
		cout << "\n\t\t|#|---------------------------------------------------------|#|";
		SetConsoleTextAttribute(f1, 11);  cout << "\n\t\t|#|                            |                            |#|";
		cout << "\n\t\t|#|      1 -> DATE DEPOZIT     |      3 -> DATE CARDURI     |#|";
		cout << "\n\t\t|#|                            |                            |#|";
		cout << "\n\t\t|#|---------------------------------------------------------|#|";
		cout << "\n\t\t|#|                            |                            |#|";
		cout << "\n\t\t|#|      2 -> DATE CREDITE     |      4 -> Iesire           |#|";
		cout << "\n\t\t|#|                            |                            |#|";
		cout << "\n\t\t|#|---------------------------------------------------------|#|";
		cout << "\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|\n\n";
		
		o = _getch();
		MoveWindow(console, r.left, r.top, 1300, 800, TRUE);
		if (o == '1')
		{
			system("cls");
			
			SetConsoleTextAttribute(f1, 10);
			cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
			cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
			cout << "\n   |*|                                                                                                                        |*|";
			cout << "\n   |*|                                       # --->  BAZA DE DATE DEPOZIT  <--- #                                             |*|";
			cout << "\n   |*|                                                                                                                        |*|";
			cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
			SetConsoleTextAttribute(f1, 14);
			cout << "\n   |*|     |              |              |                |                 |              |               |                  |*|";
			cout << "\n   |*| Nr. |    PRENUME   |     NUME     |  ANUL NASTERII |   NUME DEPOZIT  | RATA DEPOZIT | RATA DOBANZII |  SUMA DEPOZIT    |*|";
			cout << "\n   |*|     |              |              |                |                 |              |               |                  |*|";
			cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
			k = 0;
			for (i = 0; i < n; i++)
			{
				if (x[i].depo.suma_dep > 0)
				{
					k++;
					SetConsoleTextAttribute(f1, 15);
					printf("\n   |*| %2d  |%11s   |%11s   | %9d      | %12s    | %7s      |     %4.1f      | %10d       |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].depo.num_dep, x[i].depo.rata_dep, x[i].depo.rata_dob, x[i].depo.suma_dep);
					cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
				}
			}
			if (k == 0)
			{
				SetConsoleTextAttribute(f1, 15);
				cout << "\n   |*|                              Nu exista nici o persoana in baza de date cu date depozit !                               |*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
			}
			cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
			_getch(); goto m1;
		}
		else if (o == '2')
		{
			system("cls");
			SetConsoleTextAttribute(f1, 10);
			cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
			cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
			cout << "\n   |*|                                                                                                                                 |*|";
			cout << "\n   |*|                                       # --->  BAZA DE DATE CREDITE  <--- #                                                      |*|";
			cout << "\n   |*|                                                                                                                                 |*|";
			cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
			SetConsoleTextAttribute(f1, 14);
			cout << "\n   |*|     |              |              |                |                         |              |                 |                 |*|";
			cout << "\n   |*| Nr. |    PRENUME   |     NUME     |  ANUL NASTERII |       NUME CREDIT       | RATA CREDIT  |  TERMEN CREDIT  |  SUMA CREDIT    |*|";
			cout << "\n   |*|     |              |              |                |                         |              |                 |                 |*|";
			cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
			k = 0;
			for (i = 0; i < n; i++)
			{
				if (x[i].cred.suma_care > 0)
				{
					k++;
					SetConsoleTextAttribute(f1, 15);
					printf("\n   |*| %2d  |%11s   |%11s   | %9d      | %20s    |    %.1f      |     %6d ani  | %10d      |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].cred.nume_care, x[i].cred.rata, x[i].cred.term_care, x[i].cred.suma_care);
					cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
				}
			}
			if (k == 0)
			{
				SetConsoleTextAttribute(f1, 15);
				cout << "\n   |*|                                 Nu exista nici o persoana in baza de date cu date credit !                                      |*|";
				cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
			}
			cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
			_getch(); goto m1;
		}
		else if (o == '3')
		{
			system("cls");
			SetConsoleTextAttribute(f1, 10);
			cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
			cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
			cout << "\n   |*|                                                                                                                                                |*|";
			cout << "\n   |*|                                                  # --->  BAZA DE DATE CARDURI  <--- #                                                          |*|";
			cout << "\n   |*|                                                                                                                                                |*|";
			cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
			SetConsoleTextAttribute(f1, 14);
			cout << "\n   |*|     |              |              |                |                           |                           |                |                  |*|";
			cout << "\n   |*| Nr. |    PRENUME   |     NUME     |  ANUL NASTERII |         NUME CARD         |           IBAN            |  DATA EXPIRARI |  SUMA PE CARD    |*|";
			cout << "\n   |*|     |              |              |                |                           |                           |                |                  |*|";
			cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
			k = 0;
			for (i = 0; i < n; i++)
			{
				if (x[i].card.suma_cont > 0)
				{
					k++;
					SetConsoleTextAttribute(f1, 15);
					printf("\n   |*| %2d  |%11s   |%11s   | %9d      | %20s      |    %20s   |   %5s   | %10d       |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].card.nume_card, x[i].card.iban, x[i].card.data_exp, x[i].card.suma_cont);
					cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
				}
			}
			if (k == 0)
			{
				SetConsoleTextAttribute(f1, 15);
				cout << "\n   |*|                                     Nu exista nici o persoana in baza de date cu date card !                                                   |*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
			}
			cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
			_getch(); goto m1;
		}
		else if (o == '4')
		{
			MoveWindow(console, r.left, r.top, 800, 800, TRUE);
			break;
		}
		else
			cout << "\n\n Ati tastat un buton necorespunzator 1";
	}
	case '3': break;

	default: cout << "\n\n Ati tastat o tasta necorespunzatoare ! "; _getch(); goto m1;

	}
}
void eticheta()
{

	SetConsoleTextAttribute(f1, 10);
	cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	cout << "\n   |*|------------------------------------------------------------------------|*|";
	cout << "\n   |*|                                                                        |*|";
	cout << "\n   |*|                              BAZA DE DATE                              |*|";
	cout << "\n   |*|                                                                        |*|";
    cout << "\n   |*|------------------------------------------------------------------------|*|";
	SetConsoleTextAttribute(f1, 14);
	cout << "\n   |*|     |              |              |                 |                  |*|";
    cout << "\n   |*| Nr. |    PRENUME   |     NUME     |  ANUL NASTERII  |  SERIE BULETIN   |*|";
	cout << "\n   |*|     |              |              |                 |                  |*|";
    cout << "\n   |*|------------------------------------------------------------------------|*|";
	
}
void autor()
{
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);
	system("Color 0C");

	SetConsoleTextAttribute(f1, 9); cout << "\n\n\t\t\t ############"; SetConsoleTextAttribute(f1, 14); cout << "############"; SetConsoleTextAttribute(f1, 12); cout << "############";
	SetConsoleTextAttribute(f1, 9); cout << "\n\t\t\t ############"; SetConsoleTextAttribute(f1, 14); cout << "############"; SetConsoleTextAttribute(f1, 12); cout << "############";
	SetConsoleTextAttribute(f1, 9); cout << "\n\t\t\t ############"; SetConsoleTextAttribute(f1, 14); cout << "############"; SetConsoleTextAttribute(f1, 12); cout << "############";
	SetConsoleTextAttribute(f1, 9); cout << "\n\t\t\t ############"; SetConsoleTextAttribute(f1, 14); cout << "############"; SetConsoleTextAttribute(f1, 12); cout << "############";
	SetConsoleTextAttribute(f1, 9); cout << "\n\t\t\t ############"; SetConsoleTextAttribute(f1, 14); cout << "############"; SetConsoleTextAttribute(f1, 12); cout << "############";
	SetConsoleTextAttribute(f1, 9); cout << "\n\t\t\t ############"; SetConsoleTextAttribute(f1, 14); cout << "############"; SetConsoleTextAttribute(f1, 12); cout << "############";
	printf("\n\n\n\n"); printf(R"EOF(
              ______  __    __ ________ __    __  ______  _______  
             /      \/  |  /  /        /  |  /  |/      \/       \ 
            /$$$$$$  $$ |  $$ $$$$$$$$/$$ |  $$ /$$$$$$  $$$$$$$  |
            $$ |__$$ $$ |  $$ |  $$ |  $$ |__$$ $$ |  $$ $$ |__$$ |
            $$    $$ $$ |  $$ |  $$ |  $$    $$ $$ |  $$ $$    $$< 
            $$$$$$$$ $$ |  $$ |  $$ |  $$$$$$$$ $$ |  $$ $$$$$$$  |
            $$ |  $$ $$ \__$$ |  $$ |  $$ |  $$ $$ \__$$ $$ |  $$ |
            $$ |  $$ $$    $$/   $$ |  $$ |  $$ $$    $$/$$ |  $$ |
            $$/   $$/ $$$$$$/    $$/   $$/   $$/ $$$$$$/ $$/   $$/ 
		)EOF");
	printf("\n\n"); printf(R"EOF(
                        $$$$$$$\            $$$$$$\                 
                        $$  __$$\          $$  __$$\                
                        $$ |  $$ |         $$ /  \__|               
                        $$$$$$$\ |         \$$$$$$\                 
                        $$  __$$\           \____$$\                
                        $$ |  $$ |         $$\   $$ |               
                        $$$$$$$  $$\       \$$$$$$  $$\             
                        \_______/\__|       \______/\__|            

		)EOF");
	SetConsoleTextAttribute(f1, 10);
	printf("\n\n\t\t\t Press < ENTER > to continue...!");
	_getch();
	system("cls");
	MoveWindow(console, r.left, r.top, 800, 400, TRUE);
	SetConsoleTextAttribute(f1, 12);
	gotoxy(38,3); printf("### RECOMANDARI ###");
	SetConsoleTextAttribute(f1, 15);
	printf("\n\n\n * Daca deschideti pentru prima data aceasta programa !\n\n\n * Trebuie sa creati o BAZA de DATE ca programa sa functioneze conform cerintelor !\n\n\n * Daca identificati unele erori, anuntati-ma !");
	SetConsoleTextAttribute(f1, 10);
	cout << "\n\n\n\t\t Press < ENTER > to continue...!";
	_getch();
}
void menu()
{
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);
	system("COLOR 0A");

	SetConsoleTextAttribute(f1, 15);
	gotoxy(65, 0); date_time();      // functia ora si data

	SetConsoleTextAttribute(f1, 12);
	printf("\n\n"); printf(R"EOF(
                           (                    (   (                  (     
                      (    )\ )      (    (     )\ ))\ ) *   )   (     )\ )  
                    ( )\  (()/(      )\   )\   (()/(()/` )  /(   )\   (()/(  
                    )((_)  /(_))   (((_((((_)(  /(_)/(_)( )(_)((((_)(  /(_)) 
                   ((_)_  (_))     )\___)\ _ )\(_))(_))(_(_()) )\ _ )\(_))   
                    | _ ) / __|   ((/ __(_)_\(_| _ |_ _|_   _| (_)_\(_| |    
                    | _ \_\__ \_   | (__ / _ \ |  _/| |  | |    / _ \ | |__  
                    |___(_|___(_)   \___/_/ \_\|_| |___| |_|   /_/ \_\|____|                                                       
)EOF");
	
	
	SetConsoleTextAttribute(f1, 10);
	cout << "\n\n\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
	cout << "\n\t|#|------------------------------------------------------------------------|#|";
	cout << "\n\t|#|                                                                        |#|";
	cout << "\n\t|#|                       ---> B.S. CAPITAL SRL <---                       |#|";
	cout << "\n\t|#|                            ---> MENIU <---                             |#|";
	cout << "\n\t|#|------------------------------------------------------------------------|#|";
	SetConsoleTextAttribute(f1, 11); cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|     1 -> CREATI BAZA DE DATE       |    3 -> CAUTARE CLIENT            |#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|------------------------------------------------------------------------|#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|     2 -> AFISAREA BAZEI DE DATE    |    4 -> ADAUGARE CLIENT           |#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|------------------------------------------------------------------------|#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|     5 -> CALCULATOR DEPOZITE       |    6 -> CALCULATOR CREDITE        |#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|------------------------------------------------------------------------|#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|     7 -> RELAX MUSIC               |    8 -> MODIFICARE BAZEI DE DATE  |#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|------------------------------------------------------------------------|#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|     9 -> ELIMINAREA BAZEI DE DATE  |    0 -> IESIRE                    |#|";
	cout << "\n\t|#|                                    |                                   |#|";
	cout << "\n\t|#|------------------------------------------------------------------------|#|";
	cout << "\n\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
	
	SetConsoleTextAttribute(f1, 14);
	cout << "\n\n\n\t\t\t\t Optiunea dorita:  ";  cin >> meniu;

	
	system("cls");
}
void cautare()
{

	f = fopen("BAZA_de_DATE.txt", "r+");
	i = 0;
	while (fread(&x[i], sizeof(x[i]), 1, f) == 1)
	{
		i++;
	}
	n = i; fclose(f);
m2:
	system("cls");
	SetConsoleTextAttribute(f1, 10);
	cout << "\n\n\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|           # ---> CAUTARE in BAZA DE DATE <--- #         |#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	SetConsoleTextAttribute(f1, 11);  cout << "\n\t\t|#|                            |                            |#|";
	cout << "\n\t\t|#|     1 -> DATE PERSONALE    |     2 -> DATE BANCARE      |#|";
	cout << "\n\t\t|#|                            |                            |#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|                     3 -> Iesire                         |#|";
	cout << "\n\t\t|#|                                                         |#|";
	cout << "\n\t\t|#|---------------------------------------------------------|#|";
	cout << "\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|\n\n";

	meniu = _getch();

	switch (meniu)
	{
		case '1':
		{
			system("cls");
			SetConsoleTextAttribute(f1, 15);
			cout << "\n\n\n * Numele clientului:  "; SetConsoleTextAttribute(f1, 14);  cin >> cauta;
			_strupr(cauta);
			SetConsoleTextAttribute(f1, 15);
			cout << "\n\n * Prenumele clientului:  ";  SetConsoleTextAttribute(f1, 14);  cin >> cauta1;
			_strupr(cauta1);

			system("cls");

			eticheta();
			k = 0;
			for (i = 0; i < n; i++)
			{
				if (strcmp(x[i].nume, cauta) == 0 && strcmp(x[i].prenume, cauta1) == 0)
				{
					k++;
					SetConsoleTextAttribute(f1, 15);
					printf("\n   |*| %2d  |%11s   |%11s   |   %8d      |     %10s   |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].serie_buletin);
					cout << "\n   |*|------------------------------------------------------------------------|*|";
				}
				
			}
			if (k == 0)
			{
				SetConsoleTextAttribute(f1, 15);
				cout << "\n   |*|     Persoana cautata de dumnevoastra nu exista in baza de date !       |*|";
				cout << "\n   |*|------------------------------------------------------------------------|*|";
			}
			cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
			_getch(); goto m2;
		}
		case '2':
		{
			m1:
			system("cls");
			MoveWindow(console, r.left, r.top, 800, 800, TRUE);
			SetConsoleTextAttribute(f1, 10);
			cout << "\n\n\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|               ---> CAUTARE DATE BANCARE <---            |#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			SetConsoleTextAttribute(f1, 11);  cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|      1 -> DATE DEPOZIT     |      3 -> DATE CARDURI     |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|      2 -> DATE CREDITE     |      4 -> Iesire           |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|\n\n";

			o = _getch();
			MoveWindow(console, r.left, r.top, 1300, 800, TRUE);
			if (o == '1')
			{ system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n\n * Numele clientului:  "; SetConsoleTextAttribute(f1, 14);  cin >> cauta;
				_strupr(cauta);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n * Prenumele clientului:  ";  SetConsoleTextAttribute(f1, 14);  cin >> cauta1;
				_strupr(cauta1);

				system("cls");

				SetConsoleTextAttribute(f1, 10);
				cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
				cout << "\n   |*|                                                                                                                        |*|";
				cout << "\n   |*|                                       # --->  BAZA DE DATE DEPOZIT  <--- #                                             |*|";
				cout << "\n   |*|                                                                                                                        |*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
				SetConsoleTextAttribute(f1, 14);
				cout << "\n   |*|     |              |              |                |                 |              |               |                  |*|";
				cout << "\n   |*| Nr. |    PRENUME   |     NUME     |  ANUL NASTERII |   NUME DEPOZIT  | RATA DEPOZIT | RATA DOBANZII |  SUMA DEPOZIT    |*|";
				cout << "\n   |*|     |              |              |                |                 |              |               |                  |*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
				k = 0;
				for (i = 0; i < n; i++)
				{
					if (strcmp(x[i].nume, cauta) == 0 && strcmp(x[i].prenume, cauta1) == 0 && x[i].depo.suma_dep > 0)
					{
						k++;
						SetConsoleTextAttribute(f1, 15);
						printf("\n   |*| %2d  |%11s   |%11s   | %9d      | %12s    | %7s      |     %4.1f      | %10d       |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].depo.num_dep, x[i].depo.rata_dep, x[i].depo.rata_dob, x[i].depo.suma_dep);
						cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
					}
				}
				if (k==0)
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n   |*|                               Persoana cautata de dumnevoastra nu are un depozit !                                     |*|";
					cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------|*|";
				}
				cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
				_getch(); goto m1;
			}
			else if (o == '2')
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n\n * Numele clientului:  "; SetConsoleTextAttribute(f1, 14);  cin >> cauta;
				_strupr(cauta);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n * Prenumele clientului:  ";  SetConsoleTextAttribute(f1, 14);  cin >> cauta1;
				_strupr(cauta1);

				system("cls");
				SetConsoleTextAttribute(f1, 10);
				cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
				cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
				cout << "\n   |*|                                                                                                                                 |*|";
				cout << "\n   |*|                                       # --->  BAZA DE DATE CREDITE  <--- #                                                      |*|";
				cout << "\n   |*|                                                                                                                                 |*|";
				cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
				SetConsoleTextAttribute(f1, 14);
				cout << "\n   |*|     |              |              |                |                         |              |                 |                 |*|";
				cout << "\n   |*| Nr. |    PRENUME   |     NUME     |  ANUL NASTERII |       NUME CREDIT       | RATA CREDIT  |  TERMEN CREDIT  |  SUMA CREDIT    |*|";
				cout << "\n   |*|     |              |              |                |                         |              |                 |                 |*|";
				cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
				k = 0;
				for (i = 0; i < n; i++)
				{
					if (strcmp(x[i].nume, cauta) == 0 && strcmp(x[i].prenume, cauta1) == 0 && x[i].cred.suma_care>0)
					{
						k++;
						SetConsoleTextAttribute(f1, 15);
						printf("\n   |*| %2d  |%11s   |%11s   | %9d      | %20s    |    %.1f      |     %6d ani  | %10d      |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].cred.nume_care, x[i].cred.rata, x[i].cred.term_care, x[i].cred.suma_care);
						cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
					}
			    }
				if (k == 0)
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n   |*|                                 Persoana cautata de dumnevoastra nu are un Credit !                                             |*|";
					cout << "\n   |*|---------------------------------------------------------------------------------------------------------------------------------|*|";
				}
				cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
				_getch(); goto m1;
			}
			else if (o == '3')
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n\n * Numele clientului:  "; SetConsoleTextAttribute(f1, 14);  cin >> cauta;
				_strupr(cauta);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n * Prenumele clientului:  ";  SetConsoleTextAttribute(f1, 14);  cin >> cauta1;
				_strupr(cauta1);

				system("cls");
				SetConsoleTextAttribute(f1, 10);
				cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
				cout << "\n   |*|                                                                                                                                                |*|";
				cout << "\n   |*|                                                  # --->  BAZA DE DATE CARDURI  <--- #                                                          |*|";
				cout << "\n   |*|                                                                                                                                                |*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
				SetConsoleTextAttribute(f1, 14);
				cout << "\n   |*|     |              |              |                |                           |                           |                |                  |*|";
				cout << "\n   |*| Nr. |    PRENUME   |     NUME     |  ANUL NASTERII |         NUME CARD         |           IBAN            |  DATA EXPIRARI |  SUMA PE CARD    |*|";
				cout << "\n   |*|     |              |              |                |                           |                           |                |                  |*|";
				cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
				k = 0;
				for (i = 0; i < n; i++)
				{
					if (strcmp(x[i].nume, cauta) == 0 && strcmp(x[i].prenume, cauta1) == 0 && x[i].card.suma_cont>0)
					{
						k++;
						SetConsoleTextAttribute(f1, 15);
						printf("\n   |*| %2d  |%11s   |%11s   | %9d      | %20s      |    %20s   |   %5s   | %10d       |*|", i + 1, x[i].prenume, x[i].nume, x[i].an_nastere, x[i].card.nume_card, x[i].card.iban, x[i].card.data_exp, x[i].card.suma_cont);
						cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
					}
			    }
				if (k == 0)
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n   |*|                                          Persoana cautata de dumnevoastra nu are un Card !                                                     |*|";
					cout << "\n   |*|------------------------------------------------------------------------------------------------------------------------------------------------|*|";
				}
				cout << "\n   |*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
				_getch(); goto m1;
			}
			else if (o == '4')
			{
				MoveWindow(console, r.left, r.top, 800, 800, TRUE);
				goto m2;
			}
			else
				cout << "\n\n Ati tastat un buton necorespunzator !";
			_getch(); goto m1;
			case '3': break;

			default: cout << "\n\n Ati tastat o tasta necorespunzatoare ! "; _getch(); goto m1;
		}
	}
	
}

void adaugare()
{
	SetConsoleTextAttribute(f1, 10);
	cout << "\n\t\t # ---> ADAUGARE CLIENTULUI in BAZA de DATE <--- # ";
	SetConsoleTextAttribute(f1, 15);
	cout << "\n\n\n Cati clienti doriti sa adaugati: "; cin >> n;
	system("cls");
	for (i = 0; i < n; i++)
	{
		SetConsoleTextAttribute(f1, 15);
		 cout << "\n Numele " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].nume;
		_strupr(x[i].nume);
		SetConsoleTextAttribute(f1, 15);
		cout << "\n Prenumele " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].prenume;
		_strupr(x[i].prenume);
		SetConsoleTextAttribute(f1, 15);
		cout << "\n Anul nasterii " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].an_nastere;
		SetConsoleTextAttribute(f1, 15);
		cout << "\n Seria Buletinului " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].serie_buletin;
		_strupr(x[i].serie_buletin);
	m2:
		SetConsoleTextAttribute(f1, 10);
		cout << "\n\t\t\t Doriti sa introduceti date bancare: Y/N ? "; l = _getch();
		system("cls");
		if (l == 'Y' || l == 'y')
		{
			SetConsoleTextAttribute(f1, 10);
			cout << "\n\n\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|             ---> ADAUGARE DATE BANCARE <---             |#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			SetConsoleTextAttribute(f1, 11);  cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|        1 -> DEPOZIT        |      3 -> CARDURI          |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|        2 -> CREDITE        |      4 -> Iesire           |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";

			meniu = _getch();

			switch (meniu)
			{
			case '1':
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Nume Depozit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.num_dep;
				_strupr(x[i].depo.num_dep);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Rata Depozit " << i + 1 << " client ( float / fix ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.rata_dep;
				_strupr(x[i].depo.rata_dep);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Rata Dobanzii " << i + 1 << " client ( % ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.rata_dob;
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Suma Depozit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].depo.suma_dep;
				

				goto m2;
			}
			case '2':
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Nume Credit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin.ignore(100, '\n'); cin.getline(x[i].cred.nume_care, 50);
				_strupr(x[i].cred.nume_care);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Rata Credit " << i + 1 << " client ( % ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].cred.rata;
				_strupr(x[i].prenume);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Termin Credit " << i + 1 << " client ( ani ): "; SetConsoleTextAttribute(f1, 13); cin >> x[i].cred.term_care;
                SetConsoleTextAttribute(f1, 15);
				cout << "\n Suma Credit " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].cred.suma_care;
				goto m2;

			}
			case '3':
			{
				system("cls");
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Nume Card " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin.ignore(130, '\n'); cin.getline(x[i].card.nume_card, 50);
				_strupr(x[i].card.nume_card);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n IBAN " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin.getline(x[i].card.iban, 50);
				_strupr(x[i].card.iban);
				SetConsoleTextAttribute(f1, 15);
				cout << "\n Data Expirari " << i + 1 << " client ( ex: 20/02/2016 ): "; SetConsoleTextAttribute(f1, 13);  cin >> (x[i].card.data_exp);
                SetConsoleTextAttribute(f1, 15);
				cout << "\n Suma pe cont " << i + 1 << " client: "; SetConsoleTextAttribute(f1, 13); cin >> x[i].card.suma_cont;
				
				goto m2;
			}
			case '4': break;
			default: cout << "\n\n Ati tastat un buton necorespunzator !";
			}
			_getch();
			system("cls");
		}
	}
	f = fopen("BAZA_de_DATE.txt", "a+");
	for (i = 0; i < n; i++)
	{
		fwrite(&x[i], sizeof(x[i]), 1, f);
	}
	fclose(f);
}
void gotoxy(int a, int b)
{
	HANDLE hConsoleOutput;
	COORD ord;
	cout.flush();
	ord.X = a;
	ord.Y = b;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, ord);
}
void calc_depozit()
{
	float h,zi,suma,dob,cf;
	
repet: system("cls");
	SetConsoleTextAttribute(f1, 10);
	gotoxy(25, 1); cout << "-+- CALCULATOR DEPOZITE -+-";
	SetConsoleTextAttribute(f1, 15);
	gotoxy(4, 5); cout << " Suma Depusa : "; SetConsoleTextAttribute(f1, 14);  cin >> h;
	SetConsoleTextAttribute(f1, 15);
	gotoxy(4, 7); cout << " Rata Dobanzii ( % ): "; SetConsoleTextAttribute(f1, 14); cin >> dob;
	SetConsoleTextAttribute(f1, 15);
	gotoxy(4, 9); cout << " Numarul de zile ( pastrare depozit ): "; SetConsoleTextAttribute(f1, 14); cin >> zi;

	suma =( h*dob*zi)/(100 * 365); // formula de calcul depizit
	cf = h + suma;                // capital final
	system("cls");
	MoveWindow(console, r.left, r.top, 600, 400, TRUE);
	SetConsoleTextAttribute(f1, 15);
	gotoxy(10, 5); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	gotoxy(10, 6); cout << "|*|                                          |*|";
	gotoxy(10, 7); cout << "|*|"; SetConsoleTextAttribute(f1, 12); gotoxy(26, 7); cout << " ---> DOBANDA <--- "; SetConsoleTextAttribute(f1, 15); gotoxy(55, 7); cout << "|*|";
	gotoxy(10, 8); cout << "|*|                                          |*|";
	gotoxy(10, 9); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	gotoxy(10, 10); cout << "|*|                                          |*|";
	gotoxy(10, 11); cout << "|*|"; SetConsoleTextAttribute(f1, 10); gotoxy(33, 11); printf("%.2f ", suma); SetConsoleTextAttribute(f1, 15); gotoxy(55, 11); cout << "|*|";
	gotoxy(10, 12); cout << "|*|                                          |*|";
	gotoxy(10, 13); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	gotoxy(10, 14); cout << "|*|                                          |*|";
	gotoxy(10, 15); cout << "|*|"; SetConsoleTextAttribute(f1, 10); gotoxy(20,15); printf("CAPITAL FINAL = %.2f ", cf); SetConsoleTextAttribute(f1, 15); gotoxy(55, 15); cout << "|*|";
	gotoxy(10, 16); cout << "|*|                                          |*|";
	gotoxy(10, 17); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	SetConsoleTextAttribute(f1, 13);
	gotoxy(17, 20); cout << " Doriti sa repetati calculul? Y/N ";   l = _getch();
	if (l == 'y' || l == 'Y')
	{
		goto repet;
	}
}
void credite()
{
	float c;  //suma credit
	float d; // dobanda anuala
	//float rl; //rata lunara a dobanzii
	float pl; // plata lunara
	float nr;   // Termen

repet: system("cls");
	SetConsoleTextAttribute(f1, 10);
	gotoxy(25, 1); cout << "-+- CALCULATOR CREDITE -+-";
	SetConsoleTextAttribute(f1, 15);
	gotoxy(4, 5); cout << " -> Suma Creditului: "; SetConsoleTextAttribute(f1, 14);  cin >> c;
	SetConsoleTextAttribute(f1, 15);
	gotoxy(4, 7); cout << " -> Dobanda Anuala ( % ): "; SetConsoleTextAttribute(f1, 14); cin >> d;
	SetConsoleTextAttribute(f1, 15);
	gotoxy(4, 9); cout << " -> Perioada ( ani ): "; SetConsoleTextAttribute(f1, 14); cin >> nr;
	
	pl = c*d / 12 / 100 / (1 - 1 / (pow(1 + d / 12 / 100, nr * 12))); // formula rate lunare fixe

	system("cls");
	MoveWindow(console, r.left, r.top, 600, 400, TRUE);
	SetConsoleTextAttribute(f1, 15);
	gotoxy(10, 1); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	gotoxy(10, 2); cout << "|*|                                          |*|";
	gotoxy(10, 3); cout << "|*|"; SetConsoleTextAttribute(f1, 14); gotoxy(19, 3); cout << "--> * PLATI LUNARE EGALE * <--"; SetConsoleTextAttribute(f1, 15); gotoxy(55, 3); cout << "|*|";
	gotoxy(10, 4); cout << "|*|                                          |*|";
	gotoxy(10, 5); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	gotoxy(10, 6); cout << "|*|                                          |*|";
	gotoxy(10, 7); cout << "|*|"; SetConsoleTextAttribute(f1, 10); gotoxy(30, 7); printf(" %.2f ", pl); SetConsoleTextAttribute(f1, 15); gotoxy(55, 7); cout << "|*|";
	gotoxy(10, 8); cout << "|*|                                          |*|";
	gotoxy(10, 9); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	

	SetConsoleTextAttribute(f1, 13);
	gotoxy(17, 12); cout << " Doriti sa repetati calculul? Y/N ";   l = _getch();
	if (l == 'y' || l == 'Y')
	{
		goto repet;
	}
}
void muzic()
{
	MoveWindow(console, r.left, r.top, 600, 600, TRUE);
	SetConsoleTextAttribute(f1, 10);
	printf(R"EOF(
      ___           ___           ___                       ___     
     /__/\         /__/\         /  /\        ___          /  /\    
    |  |::\        \  \:\       /  /:/_      /  /\        /  /:/    
    |  |:|:\        \  \:\     /  /:/ /\    /  /:/       /  /:/     
  __|__|:|\:\   ___  \  \:\   /  /:/ /::\  /__/::\      /  /:/  ___ 
 /__/::::| \:\ /__/\  \__\:\ /__/:/ /:/\:\ \__\/\:\__  /__/:/  /  /\
 \  \:\~~\__\/ \  \:\ /  /:/ \  \:\/:/~/:/    \  \:\/\ \  \:\ /  /:/
  \  \:\        \  \:\  /:/   \  \::/ /:/      \__\::/  \  \:\  /:/ 
   \  \:\        \  \:\/:/     \__\/ /:/       /__/:/    \  \:\/:/  
    \  \:\        \  \::/        /__/:/        \__\/      \  \::/   
     \__\/         \__\/         \__\/                     \__\/    
		)EOF");
	SetConsoleTextAttribute(f1, 12);
	gotoxy(13, 15); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	gotoxy(13, 16); cout << "|*|                     |                    |*|";
	gotoxy(13, 17); cout << "|*|     1 -> Play       |     2 -> Stop      |*|";
	gotoxy(13, 18); cout << "|*|                     |                    |*|";
	gotoxy(13, 19); cout << "|*||*||*||*||*||*||*||*||*||*||*||*||*||*||*||*|";
	puts("\n\n"); o = _getch();

	if (o == '1')
	{
		MoveWindow(console, r.left, r.top, 500, 500, TRUE);
		system("cls"); 

		PlaySound(TEXT("music/test2.wav"), NULL, SND_LOOP | SND_ASYNC);
		
	}
	else if(o=='2')
	{
		MoveWindow(console, r.left, r.top, 500, 500, TRUE);
		system("cls"); 
		
		PlaySound(NULL, 0, 0);
	}
	gotoxy(10, 4); printf(R"EOF(
________________________________________¶____
¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________________________¶___
¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__________________¶¶____¶¶__
_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶____________¶¶______¶¶____¶¶_
_____¶¶¶¶¶¶¶______________¶¶¶¶_______¶_____¶¶
_____¶¶¶¶¶¶¶________¶¶¶¶_¶¶¶¶¶__¶____¶¶____¶¶
_____¶¶¶¶¶¶¶_______¶¶¶¶¶_¶¶¶¶¶___¶___¶¶____¶¶
_____¶¶¶¶¶¶¶_______¶¶¶¶¶_¶¶¶¶¶___¶¶__¶¶____¶¶
_____¶¶¶¶¶¶¶_______¶¶¶¶¶_¶¶¶¶¶___¶¶__¶¶____¶¶
_____¶¶¶¶¶¶¶_______¶¶¶¶¶_¶¶¶¶¶___¶¶__¶¶____¶¶
_____¶¶¶¶¶¶¶_______¶¶¶¶¶_¶¶¶¶¶__¶¶___¶¶____¶¶
_____¶¶¶¶¶¶¶_________¶¶¶_¶¶¶¶¶__¶____¶¶____¶¶
_____¶¶¶¶¶¶¶______________¶¶¶¶_______¶_____¶¶
_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶____________¶¶______¶_____¶¶_
¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__________________¶_____¶¶__
¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________________________¶___
________________________________________¶____
_____________________________________________
¶¶¶¶¶__¶¶¶¶¶_¶¶¶¶_¶¶¶¶__¶¶¶¶¶¶_¶¶¶¶¶¶__¶¶¶¶¶_
_¶¶¶¶__¶¶¶¶___¶¶___¶¶__¶¶¶_______¶¶___¶¶___¶¶
_¶¶_¶¶¶¶_¶¶___¶¶___¶¶___¶¶¶¶¶¶___¶¶___¶¶_____
_¶¶__¶¶__¶¶___¶¶___¶¶_______¶¶¶__¶¶___¶¶___¶¶
_¶¶__¶¶__¶¶___¶¶¶_¶¶¶__¶¶¶__¶¶¶__¶¶___¶¶¶__¶¶
¶¶¶¶_¶¶_¶¶¶¶___¶¶¶¶¶___¶¶¶¶¶¶¶_¶¶¶¶¶¶__¶¶¶¶¶_

		)EOF");
	
}

void modificare()
{

	long int pos;
	int i,nr,k=0;
	float nr1;
	char I[30];

m1:system("cls");
	SetConsoleTextAttribute(f1, 10);
	cout << "\n --> Pentru modificarea datelor introduceti Numele si Prenumele Clientului:";

	f = fopen("BAZA_de_DATE.txt", "r+"); i = 0;
	SetConsoleTextAttribute(f1, 15);
	printf("\n\n * Nume: "); SetConsoleTextAttribute(f1, 11); cin >> cauta;
	_strupr(cauta);
	SetConsoleTextAttribute(f1, 15);
	printf("\n * Prenume: "); SetConsoleTextAttribute(f1, 11); cin >> cauta1;
	_strupr(cauta1);

	fseek(f, 0, 0);

	while (fread(&(x[i]), sizeof(x[i]), 1, f) == 1)
	{

	if (strcmp(x[i].prenume, cauta1) == 0 && strcmp(x[i].nume, cauta) == 0)
		{
			k++;
			pos = ftell(f) - sizeof(x[i]);
			
		m2:
			system("cls");
			MoveWindow(console, r.left, r.top, 800, 800, TRUE);
			SetConsoleTextAttribute(f1, 10);
			cout << "\n\n\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|              ---> ACTUALIZAREA DATELOR  <---            |#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			SetConsoleTextAttribute(f1, 11);  cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|      1 -> DATE PERSONALE   |      2 -> DATE DEPOZIT     |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|      3 -> DATE CARDURI     |      4 -> DATE CREDITE     |#|";
			cout << "\n\t\t|#|                            |                            |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|                       5 -> IESIRE                       |#|";
			cout << "\n\t\t|#|                                                         |#|";
			cout << "\n\t\t|#|---------------------------------------------------------|#|";
			cout << "\n\t\t|#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#||#|\n\n";
			meniu = _getch();
			system("cls");
			switch (meniu)
			{
			case '1':
			{
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Nume Client: Y/N ?";  o = _getch();  
				if (o == 'y'|| o=='Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Numele: "; SetConsoleTextAttribute(f1, 13); cin >> I; _strupr(I);
					strcpy(x[i].nume, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Prenume Client: Y/N ?";  o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Prenumele: "; SetConsoleTextAttribute(f1, 13); cin >> I; _strupr(I);
					strcpy(x[i].prenume, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Anul de Nasterii: Y/N ?";  o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Anul de Nastere: "; SetConsoleTextAttribute(f1, 13); cin >> nr;
					x[i].an_nastere = nr;
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Seria Buletin: Y/N ?";  o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Seria Buletinului: "; SetConsoleTextAttribute(f1, 13); cin >> I; _strupr(I);
					strcpy(x[i].serie_buletin, I);
				}
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n\n\t\t\t Doriti sa modificati alte date ? Y/N "; o = _getch();
				if (o == 'y' || o == 'Y')
				{
					goto m2;
				}
				else
				{
					break;
				}
			}
			case '2':
			{
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Nume Depozit: Y/N ?"; 
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Nume Depozit: "; SetConsoleTextAttribute(f1, 13); cin>>I;
					_strupr(I); strcpy(x[i].depo.num_dep, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Rata Depozit ( float / fix ) : Y/N ?"; 
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Rata Depozit ( float / fix ) : "; SetConsoleTextAttribute(f1, 13); cin >> I;
					_strupr(I); strcpy(x[i].depo.rata_dep, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Rata Dobanzii ( % ) : Y/N ?"; 
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Rata Dobanzii ( % ) : "; SetConsoleTextAttribute(f1, 13); cin >> nr1;
					 x[i].depo.rata_dob = nr1;
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Suma Depozit: Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Suma Depozit: "; SetConsoleTextAttribute(f1, 13); cin >> nr;
					x[i].depo.suma_dep = nr;
				}
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n\n\t\t\t Doriti sa modificati alte date ? Y/N "; o = _getch();
				if (o == 'y' || o == 'Y')
				{
					goto m2;
				}
				else
				{
					break;
				}
			}
			case '3':
			{
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Nume Card: Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Nume Card: "; SetConsoleTextAttribute(f1, 13); cin.ignore(100, '\n'); cin.getline(I, 50);
					_strupr(I); strcpy(x[i].card.nume_card, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati IBAN: Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti IBAN: "; SetConsoleTextAttribute(f1, 13); cin.getline(I, 50);
					_strupr(I); strcpy(x[i].card.iban, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Data Expirari ( ex: 20/02/2016 ): Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Data Expirari ( ex: 20/02/2016 ): "; SetConsoleTextAttribute(f1, 13); cin >> I;
					strcpy(x[i].card.data_exp, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Suma pe cont: Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Suma Depozit: "; SetConsoleTextAttribute(f1, 13); cin >> nr;
					x[i].card.suma_cont = nr;
				}
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n\n\t\t\t Doriti sa modificati alte date ? Y/N "; o = _getch();
				if (o == 'y' || o == 'Y')
				{
					goto m2;
				}
				else
				{
					break;
				}
			}
			case '4':
			{
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Nume Credit: Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Nume Credit: "; SetConsoleTextAttribute(f1, 13); cin.ignore(100, '\n'); cin.getline(I, 50);
					_strupr(I); strcpy(x[i].cred.nume_care, I);
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Rata Credit ( % ): Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Rata Credit ( % ): "; SetConsoleTextAttribute(f1, 13); cin >> nr1;
					x[i].cred.rata = nr1; 
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Termin Credit ( ani ): Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Termin Credit ( ani ): "; SetConsoleTextAttribute(f1, 13); cin >> nr;
					x[i].cred.term_care = nr;
				}
				SetConsoleTextAttribute(f1, 12);
				cout << "\n\n * Modificati Suma Credit: Y/N ?";
				o = _getch();
				if (o == 'y' || o == 'Y')
				{
					SetConsoleTextAttribute(f1, 15);
					cout << "\n\n -> Introduceti Suma Credit: "; SetConsoleTextAttribute(f1, 13); cin >> nr;
					x[i].cred.suma_care = nr;
				}
				SetConsoleTextAttribute(f1, 15);
				cout << "\n\n\n\t\t\t Doriti sa modificati alte date ? Y/N "; o = _getch();
				if (o == 'y' || o == 'Y')
				{
					goto m2;
				}
				else
				{
					break;
				}
			case '5': break;
			}
			default: cout << "\n\n Ati tastat un buton necorespunzator !";		
			}

			fseek(f, pos, SEEK_SET);
			fwrite(&x[i], sizeof(x[i]), 1, f);
			fclose(f);
		}
		
	i++;
	}
	if (k == 0)	
	{
		SetConsoleTextAttribute(f1, 15);
		system("cls"); gotoxy(15, 10); cout << "Aceasta persoana nu exista in baza de date !";
		_getch();
	}
	system("cls");
	SetConsoleTextAttribute(f1, 15);
	cout << "\n\n\n\t\t Doriti sa modificati datele unui alt Client ? Y/N "; o = _getch();
	if (o == 'y' || o == 'Y')
	{
		goto m1;
	}
	
}
void removes()
{
	int status;
	SetConsoleTextAttribute(f1, 10);
	gotoxy(15, 1); cout << "-->-->--> ELIMINAREA BAZEI DE DATE <--<--<-- ";
m1:
	SetConsoleTextAttribute(f1, 15);
	cout << "\n\n\n * Introduceti numele fisierului: ";  SetConsoleTextAttribute(f1, 11); cin.ignore(100, '\n'); cin.getline(baza,30);

	status = remove(baza);

	if (status == 0)
	{
		SetConsoleTextAttribute(f1, 12);
		puts("\n\n"); cout << baza << " --> A fost sters cu succes !!! ";
	}
	else
	{
		SetConsoleTextAttribute(f1, 10);
		cout << "\n\n * Fisierul nu a putut fi gasit sau ati introdus numele gresit !!!";
	}
	SetConsoleTextAttribute(f1, 15);
	cout << "\n\n\n\t\t\t Doriti sa repetati ? Y/N "; o = _getch();
	if (o == 'y' || o == 'Y')
	{
		goto m1;
	}

}
void date_time()
{
	time_t current_time;
	char* c_time_string;

	/* Obtain current time. */
	current_time = time(NULL);

	if (current_time == ((time_t)-1))
	{
		(void)fprintf(stderr, "Failure to obtain the current time.\n");
		exit(EXIT_FAILURE);
	}

	/* Convert to local time format. */
	c_time_string = ctime(&current_time);

	if (c_time_string == NULL)
	{
		(void)fprintf(stderr, "Failure to convert the current time.\n");
		exit(EXIT_FAILURE);
	}

	/* Print to stdout. ctime() has already added a terminating newline character. */
	(void)printf("%s", c_time_string);
	//exit(EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // andrà ad aiutarmi nei filtri fix/
#include <errno.h>
#include <limits.h>

void menu ();
void moltiplica ();
void dividi ();
void ins_string();



int main () 

{
	//char scelta = {'\0'}; // errore?
	char scelta; // Fix
	
	menu ();
	scanf (" %c", &scelta); //fix
	//scanf ("%d", &scelta); //errore?
// inserire un uscita dal programma?
	switch (scelta)
	{
		case 'A':
		moltiplica();
		break;
		case 'B':
                dividi(); // non si può dividere per zero si blocca il programma
                break;
		case 'C':
                ins_string(); // non lo metterei nel mio programma, apre le porte a molti tipi d'attacco.
                break;

				case 'D':
                return 0;// esco dal programma
				
    default: main(); // Ritorno al main in caso di input errato.
	}
	

}


void menu ()
{
	printf ("Benvenuto, sono un assitente digitale, posso aiutarti a sbrigare alcuni compiti\n");
	printf ("Come posso aiutarti?\n");
	printf ("A >> Moltiplicare due numeri\nB >> Dividere due numeri\nC >> Inserire una stringa\nD >> Esci dal programma\n");// uscire dal programma

}


void moltiplica ()
{
	float  a,b = 0;  // short Int? Per le moltiplicazioni non è il massimo, sostituire con int o float o double
	printf ("\nInserisci il primo numero da moltiplicare:\n"); // solo numeri non caratteri
	scanf (" %f", &a);//si può  mettere float al posto di int per i numeri con la virgola
	printf ("\nInserisci il secondo numero da moltiplicare:\n"); // solo numeri non caratteri
	scanf (" %f", &b); // Perchè qua è stato messo %d? non era meglio mettere entrambi su f?
     

	 
 if(a >100 || a <1){
    printf ("\n-Inserisci il primo  numero compreso tra 1 e 100\n");  // controllo gli input inseriti dall'utente
    return moltiplica();

	} else if (b<1 || b>100){
    printf ("\nInserisci il primo  numero compreso tra 1 e 100\n");   // controllo gli input inseriti dall'utente
    return moltiplica();
 
	
	} else {
	float  prodotto = a * b; // short Int? Per le moltiplicazioni non è il massimo, sostituire con int o float o double
	printf ("\nIl prodotto tra %f e %f e': %f\n", a,b,prodotto); // il parametro a prima è dichiarato con f ora con d
	}




	main(); //Ritorno al inizio dopo l'operazione
	
}


void dividi ()
{
        int  a,b = 0; //float? double? int?
        printf ("\nInserisci il numeratore:\n"); // solo numeri non caratteri
        scanf ("%d", &a);
	printf ("\nInserisci il denumeratore:\n"); // si può  mettere float al posto di int per i numeri con la virgola
        scanf (" %d", &b);


 if(a == 0){
    printf ("\nNon puoi dividere per zero, riprova\n");  // controllo gli input inseriti dall'utente
    return dividi();

	} else if (a == 0){
      printf ("\nNon puoi dividere per zero, riprova\n");  // controllo gli input inseriti dall'utente
    return dividi();
 
 
	} else if (b == 0){
      printf ("\nNon puoi dividere per zero, riprova\n");  // controllo gli input inseriti dall'utente
    return dividi();
 
 	} else {

        int divisione = a / b; // non si può dividere per zero il programma si blocca tolgo il % che da il resto non fa la divisione
        printf ("\nLa divisione tra %d e %d e': %d\n", a,b,divisione);
	}

main(); //Ritorno al inizio dopo l'operazione

}





void ins_string () 
{
	char stringa[20];
        printf ("Inserisci la stringa:");
		scanf("%s", stringa);
while(strlen(stringa) > 20 || strlen(stringa) < 1) // controllo lunghezza e se viene inserito l'username
{
printf("\nErrore, stringa non inserita oppure ha superato il massimo dei caratteri consentiti(2) .");
printf("\n Riprova inserisci il tuo nome(Massimo 20 caratteri): ");
scanf("%s", stringa);
}
 printf ("\nLa mia stringa e' : %s\n", stringa);
		//stringa da stampare forse?
		//Bufferoverflow, fuzz testing?
		main(); //Ritorno al inizio dopo l'operazione
}

//dopo le operazioni si può tornare al menù principale?
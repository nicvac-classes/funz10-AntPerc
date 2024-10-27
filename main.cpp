#include <iostream>
using namespace std;

int main() {
    srand(time(0));   //Seed random number generator
    
    string c;
    int capacitaMax, personePresenti, numPersone;
    int livelloPuliziaPerc;

    personePresenti = 0;
    capacitaMax = resetPalestraCapacita(50);
    livelloPuliziaPerc = resetPalestraPulizia(rand() % 101);
    do {
        visualizzaStato(capacitaMax, personePresenti, livelloPuliziaPerc);
        c = leggiComando();
        if (c == "P") {
            livelloPuliziaPerc = pulisciPalestra(livelloPuliziaPerc);
        }
        if (c == "E") {
            cout << "Quante persone vuoi fare entrare?" << endl;
            cin >> numPersone;
            personePresenti = personePresenti + entraPersone(numPersone, capacitaMax, personePresenti);
        }
        if (c == "U") {
            cout << "Quante persone devono uscire?" << endl;
            cin >> numPersone;
            personePresenti = personePresenti - esciPersone(numPersone, personePresenti);
        }
        if (c == "A") {
            livelloPuliziaPerc = usaAttrezzi(livelloPuliziaPerc);
        }
        if (c == "R") {
            cout << "Inserisci la capacita massima: " << endl;
            cin >> capacitaMax;
            livelloPuliziaPerc = rand() % 101;
            capacitaMax = resetPalestraCapacita(capacitaMax);
            livelloPuliziaPerc = resetPalestraPulizia(livelloPuliziaPerc);
            numPersone = 0;
        }
    } while (c != "X");
    cout << "torna presto" << endl;
    return 0;
}

int entraPersone(int numPersone, int capacitaMax, int personePresenti) {
    int entrati;
    int postiLiberi;

    postiLiberi = capacitaMax - personePresenti;
    if (postiLiberi >= numPersone) {
        entrati = numPersone;
    } else {
        entrati = postiLiberi;
        cout << "Non c'è spazio nella palestra per tutte le persone che hai richiesto. Ne ho fatte entrare" << entrati << endl;
    }
    
    return entrati;
}

int esciPersone(int numPersone, int personePresenti) {
    int uscite;

    if (personePresenti >= numPersone) {
        uscite = numPersone;
    } else {
        uscite = personePresenti;
        cout << "Non ci sono abbastanza persone a sufficienza. Ne ho fatte uscire " << uscite << endl;
    }
    
    return uscite;
}

string leggiComando() {
    string c;

    do {
        cout << "[P]ulisci | [E]entra persone | [U]scita persone | [A]ttrezzi usati | [R]eset | [X]esci" << endl;
        cin >> c;
    } while (c != "P" && c != "E" && c != "U" && c != "A" && c != "R" && c != "X");
    
    return c;
}

double pulisciPalestra(double livelloPuliziaPerc) {
    livelloPuliziaPerc = livelloPuliziaPerc + 10;
    if (livelloPuliziaPerc > 100) {
        livelloPuliziaPerc = 100;
    }
    
    return livelloPuliziaPerc;
}

int resetPalestraCapacita(int capacitaMax) {
    if (capacitaMax > 80) {
        capacitaMax = 80;
        cout << "Valore troppo grande per capacita massima. Impostato a " << capacitaMax << endl;
    } else {
        if (capacitaMax < 10) {
            capacitaMax = 10;
            cout << "valore negativo per capacita massima. Impostato a " << capacitaMax << endl;
        }
    }
    
    return capacitaMax;
}

double resetPalestraPulizia(double pulizia) {
    if (pulizia > 100) {
        pulizia = 100;
        cout << "Valore pulizia troppo grande. Limitato a " << pulizia << endl;
    } else {
        if (pulizia < 0) {
            pulizia = 0;
            cout << "Pulizia negativa. Impostata a " << pulizia << endl;
        }
    }
    
    return pulizia;
}

double usaAttrezzi(double livelloPuliziaPerc) {
    livelloPuliziaPerc = livelloPuliziaPerc - (rand() % 50 + 1);
    if (livelloPuliziaPerc < 0) {
        livelloPuliziaPerc = 0;
    }
    
    return livelloPuliziaPerc;
}

void visualizzaStato(int capacitaMax, int personePresenti, int livelloPuliziaPerc) {
    cout << "Capacità della palestra: " << capacitaMax << "persone" << endl;
    cout << "Numero di persone entrate: " << personePresenti << endl;
    cout << "La pulizia della palestra: " << livelloPuliziaPerc << endl;
    cout << "Si possono far entrare in palestra " << capacitaMax - personePresenti << "persone" << endl;
}



   
 

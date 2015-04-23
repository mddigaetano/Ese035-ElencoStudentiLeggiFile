#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define N 2
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente alunni[N];
    int i; char NomeFile[MAX_STRLEN+1];
    int QuantiLetti;
    FILE *pfile;
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", NomeFile);
    
    // Codice per l'apertura del file e la lettura
    if(pfile=fopen(NomeFile,"rb")){
        QuantiLetti=fread(alunni, sizeof(studente), N, pfile);
        while(QuantiLetti){
            for(i=0;i<QuantiLetti;i++){
                // Codice per la stampa a schermo
                printf("\n%s; %s; %d; %s\n",alunni[i].nome, alunni[i].cognome, alunni[i].eta, alunni[i].classe);
            }
            QuantiLetti=fread(alunni, sizeof(studente), N, pfile);
        }
    }
    else{
        printf("Impossibile aprire il file");
    }
    
    return (EXIT_SUCCESS);
}
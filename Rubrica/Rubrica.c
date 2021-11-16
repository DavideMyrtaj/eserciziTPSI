#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char cognome[100];
    char numero[100];
} Persona;

void Scrivi(Persona lista[], int dim, char output[]);
void LeggiFile(char *argv[], Persona lista[], int *DIM)
{
    FILE *file;

    file = fopen(argv[1], "r");
    char parola[100];
    *DIM = 0;
    Persona persona;
    while ((fscanf(file, "%s %s %s", persona.nome, persona.cognome, persona.numero)) != EOF)
    {
        (*DIM)++;
        lista[(*DIM) - 1] = persona;
    }
    fclose(file);
}
void StampaLista(Persona lista[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        Persona persona = lista[i];
        printf("%s %s %s\n", persona.nome, persona.cognome, persona.numero);
    }
}
void AggiungiContatto(Persona lista[], int *dim, char output[])
{
    Persona Persona;
    printf("inserisci il nome\n");
    scanf("%s", Persona.nome);
    printf("inserisci il cognome\n");
    scanf("%s", Persona.cognome);
    printf("inserisci il numero\n");
    scanf("%s", Persona.numero);
    lista[*dim] = Persona;
    (*dim)++;
    printf("persona aggiunta correttamente\n");
    Scrivi(lista, *dim, output);
}
void Scrivi(Persona lista[], int dim, char output[])
{
    fclose(fopen(output, "w"));
    FILE *scrivi = fopen(output, "a");
    for (int i = 0; i < dim; i++)
    {
        Persona persona = lista[i];
        fprintf(scrivi, "%s %s %s\n", persona.nome, persona.cognome, persona.numero);
    }
    fclose(scrivi);
}
void EliminaContatto(Persona list[],int *dim, char output[]){
    char numero[100];
StampaLista(list,*dim);
printf("scrivi il numero della persona da cancellare\n");
scanf("%s",numero);
for (int i = 0; i < *dim; i++)
{
    Persona persona=list[i];
    if (strcmp(persona.numero,numero)==0)
    {
        for (int j = i; j < (*dim)-1; j++)
        {
            list[j]=list[j+1];

        }
        (*dim)--;
        Scrivi(list,*dim,output);
        printf("il contato è stato eliminato\n");
    }
    
}


}
int main(int argc, char *argv[])
{

    Persona lista[100];
    int DIM;
    char output[100];

    if (argc == 2)
    {

        strcpy(output, argv[1]);
    }
    else if (argc == 4)
    {

        strcpy(output, argv[3]);
    }
    else
    {
        printf("comando inserito errato\n");
        return 0;
    }

    LeggiFile(argv, lista, &DIM);
    int scelta;
    do
    {

        printf("\nsegli l'azione da eseguire:\n1) mostrare la rubrica a video\n2) aggiungere un contatto alla rubrica\n3) eliminare un contatto dalla rubrica dopo averlo ricercato con il suo numero di telefono\n");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            StampaLista(lista, DIM);
            break;
        case 2:
            AggiungiContatto(lista, &DIM, output);
            break;
        case 3:EliminaContatto(lista,&DIM,output);
            break;
        }
    } while (1);

    return 0;
}
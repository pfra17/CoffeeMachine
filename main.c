#include <stdio.h>
#include <stdlib.h>
//Logo für die Anzeige
void meinlogo()
{
    printf("#################################\n# Willkommen bei Premium Kaffee #\n#################################\n");
}
//Deklaration der Strukturvariablen
struct kaffee
{
    int nummer;
    char bezeichnung[30];
    double preis;
    int anzahl;
};

//Funktion2 zur Berechnung der Gesamtsumme
double ausgabegesamtsumme2 (struct kaffee *sort,int index)
{
    double summe;
    summe=(sort[0].anzahl * sort[0].preis) + (sort[1].anzahl * sort[1].preis)+(sort[2].anzahl * sort[2].preis)+(sort[3].anzahl * sort[3].preis);
    return summe;
    }

//Funktion1 zur Brechnung der Einzelsummen
double ausgabegesamtsumme (double wert1,int menge1)
{
    double summegesamt;
    summegesamt=wert1*menge1;
    return summegesamt;
}

double bezahlen(double zuZahlen)
{
    printf("Bezahlvorgang abbrechen mit 0!\n");
    printf("\nBei Bezahlung mit Karte benuetzen Sie bitte das Kartenlesegeraet\n");
    float einwurf, gezahlt = 0;
    do
    {
        printf("\nZu bezahlen: %.2f Sfr.", zuZahlen-gezahlt);
        printf("\nBitte werfen Sie ein Geldstueck ein: ");
        scanf("%f", &einwurf);
        if (einwurf==0)
        {
            break;
        }
        if (pruefeGeldStueck(einwurf))
        {
            gezahlt += einwurf;
        }
        else
        {
            printf("Ihr Geldstueck ist ungueltig!\n");
        }
        }while (gezahlt < zuZahlen);
        return gezahlt;
    }

int pruefeGeldStueck(double muenze)
{
    int cent = muenze * 100;
    switch(cent)
    {
        case 5:     return 1;
        case 10:    return 1;
        case 20:    return 1;
        case 50:    return 1;
        case 100:   return 1;
        case 200:   return 1;
        case 500:   return 1;
        default:    return 0;
    }
}
double retourgeld (double summand1, double summand2)
{
    double retoursumme;

    retoursumme=summand2-summand1;
    return retoursumme;
}
//Main (Hauptprogramm
int main()

{   //Deklaration der Strukturfelder 1-4 (bzw 0-3),der summe,index,posten,abschluss,anzahl
    //Aufruf von der Logo Funktion für die Anzeige
    //Vorbereitungen zur Übergabe an ein TXT_File
    FILE *fp;
    struct kaffee sorten[4] = {{1,"KaffeeCreme",2.90},{2,"Espresso",3.10},{3,"LatteMachiatto",4.50},{4,"Americano",4.00}};
    double summe,bezahlung,rueckgabe,gezahlt;
    int index,posten=0,abschluss,anzahl,schleife,delay_a,delay_b,delay_c;

    meinlogo();

    fp = fopen("Rechnung.txt","w");
    if(fp == NULL)
    {
        printf("Dateifehler\n");
    }

    //Begrüssung und Anzeige, do while Schleife: Falls abgebrochen wird, startet Anzeige neu,
    //If Bedingung 1: Aufnahme der Betsellung und èbergabe an die Funktion2,
    //If Bedingung 0: Bedanken und verabschieden.

    printf("\nGruezi, hier ist eine Auswahl unserer Produkte:\n");
    printf("1. Kaffee Creme: 2.90 Sfr.\n2. Espresso: 3.10 Sfr.\n3. Latte Machiatto: 4.50 Sfr.\n4. Americano: 4.00 Sfr.\n5.Abbrechen\n");

    do{
    printf ("Was moechten Sie gerne? (Zahl 1-5) \n");
    scanf("%d",&index);

    if (index==5)
    {
        printf("Schade vieleicht ein anderes mal. Einen schoenen Tag, bis bald bei Premium Kaffee\n");
    }
    if (index>0&&index<5);
    //do while Schleife zum einlesen beliebig vieler Posten
        posten=index-1;
        printf("Wieviele %s haetten sie gerne?\n",sorten[posten].bezeichnung);
        scanf("%d",&sorten[posten].anzahl);

        printf("Wollen sie noch ein Getraenk?: Ja=1 Nein=0\n");
        scanf("%d",&schleife);
        ausgabegesamtsumme2(sorten,3);
    }

    while (schleife==1);

        if (schleife==0)
        {
        //Abfrage ob Bestellung ausgeführt werden soll,
        //1: Bedanken und Rechnung drucken,übergabe der Werte an Funktion1 zur Einzelsummenberechnung für die Rechnung und Abfrage der Funktion2 für die Gesamtsumme aller Bestellungen.
        //0: Abbruch und bedanken
        printf("Wollen sie den Vorgang abschliessen? Ja=1 Nein=0\n");
        scanf("%d",&abschluss);
        }
        if (abschluss==0)
            {
                printf("\nDanke, vielleicht ein andermal.Einen schoenen Tag noch\n");
            }


        if(abschluss==1)
            {
                fprintf(fp,"##############Rechnung#############\n");
                fprintf(fp,"# Kaffee: %19.2lf Sfr #\n",ausgabegesamtsumme(sorten[0].preis,sorten[0].anzahl));
                fprintf(fp,"# Espresso: %17.2lf Sfr #\n",ausgabegesamtsumme(sorten[1].preis,sorten[1].anzahl));
                fprintf(fp,"# Latte Machiatto: %10.2lf Sfr #\n",ausgabegesamtsumme(sorten[2].preis,sorten[2].anzahl));
                fprintf(fp,"# Americano: %16.2lf Sfr #\n",ausgabegesamtsumme(sorten[3].preis,sorten[3].anzahl));
                fprintf(fp,"#                                 #\n");
                fprintf(fp,"# Gesamtpreis:%15.2lf Sfr #\n",ausgabegesamtsumme2(sorten,3));
                    summe = ausgabegesamtsumme2(sorten,3);
                    printf("Gesamtpreis: %.2f Sfr\n",summe);
                fprintf(fp,"###Vielen Dank für ihren Einkauf###\n");


                gezahlt=bezahlen(summe);

                rueckgabe=retourgeld(summe, gezahlt);
                //printf("Bitte bezahlen Sie... (Betrag eingeben):\n");
                //scanf("%lf",&bezahlung);


            if (gezahlt>=ausgabegesamtsumme2(sorten,3))
    {
                 for (delay_a=1; delay_a<= 4; delay_a++){                   //Simulation des Geldzählers
                        printf(".");
                        for (delay_b = 1; delay_b <= 32767; delay_b++){
                            for (delay_c = 1; delay_c <= 32767; delay_c++){}
                                }}

                printf("\nVielen Dank. Retourgeld: %.2f Sfr\n",rueckgabe);

                printf("Ihre Bestellung wird zubereitet.\n");
                        for (delay_a=1; delay_a<= 10; delay_a++){                   //Delay für Kaffeezubereitung
                            printf(".");
                            for (delay_b = 1; delay_b <= 32767; delay_b++){
                                for (delay_c = 1; delay_c <= 32767; delay_c++){}
                }}
            printf("\n\n******************Geniessen Sie Ihren Kaffee************************\n\n");
    }
    system("PAUSE");//Damit die .exe Datei sich nach Ablauf des Codes nicht sofort schliesst.
}
    return 0;
}

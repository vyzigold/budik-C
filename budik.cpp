#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SOUBOR "cas.txt"

//funkce
void hodiny(int);
void odpocet();
void buzeni();
int stopky();

void budik();

void aktualniCas();

void tri();
void dve();
void leva();
void prava();

void prvni(int);
void druhyTreti(int);
void ctvrty(int);
void patySesty(int);
void sedmy(int);

void vypis(int, int, int, int, int, int);


//promenne
char rozhodnuti;

unsigned char i = 219;                                 //Znak pro výpis
int hodina;                                            //Aktuální hodina
int minuta;                                            //Aktuální minuta
int sekunda;                                           //Aktuální sekunda
int celkemSekund;                                      //Systémový čas v sekundách

int budikHod;
int budikMin;

int kontrola = 0;

//diakritika
unsigned char aa = 160;
unsigned char AA = 181;
unsigned char ccc = 159;
unsigned char CCC = 172;
unsigned char ddd = 212;
unsigned char DDD = 210;
unsigned char ee = 130;
unsigned char EE = 144;
unsigned char eee = 216;
unsigned char ii = 161;
unsigned char II = 214;
unsigned char nnn = 229;
unsigned char NNN = 213;
unsigned char oo = 162;
unsigned char rrr = 253;
unsigned char RRR = 252;
unsigned char sss = 231;
unsigned char SSS = 230;
unsigned char ttt = 156;
unsigned char TTT = 155;
unsigned char uu = 163;
unsigned char UU = 233;
unsigned char uuu = 133;
unsigned char yy = 236;
unsigned char zzz = 167;
unsigned char ZZZ = 166;

FILE *souborStopky;

int main()
{
    system("cls");
    int chyba;
    do
    { 
        chyba=0;
        printf("\t\t%c%c%c%c%c   %c   %c  %c%c%c        %c\n",i,i,i,i,i,i,i,i,i,i,i);               //ahoj
        printf("\t\t%c   %c   %c   %c %c   %c       %c\n",i,i,i,i,i,i,i);
        printf("\t\t%c   %c %c %c   %c %c   %c %c     %c\n",i,i,i,i,i,i,i,i,i);
        printf("\t\t%c%c%c%c%c   %c%c%c%c%c %c   %c       %c\n",i,i,i,i,i,i,i,i,i,i,i,i,i);
        printf("\t\t%c   %c %c %c   %c %c   %c %c %c   %c\n",i,i,i,i,i,i,i,i,i,i);
        printf("\t\t%c   %c   %c   %c %c   %c   %c   %c\n",i,i,i,i,i,i,i,i);
        printf("\t\t%c   %c   %c   %c  %c%c%c     %c%c%c\n\n\n\n",i,i,i,i,i,i,i,i,i,i);
        printf("Hodiny                                           H\nBud%ck                                            B\nOdpo%cet                                          O\nStopky                                           S\n\n\nVyberte jednu z mo%cnost%c:",ii, ccc,zzz,ii);             //menu
        scanf("%c",&rozhodnuti);                                                                                      //zápis do menu
        if ((rozhodnuti == 'H') || (rozhodnuti == 'h'))                                                               //Porovnání výběru
                        hodiny(0);
        else if ((rozhodnuti == 'B') || (rozhodnuti == 'b'))
        {
                        budik();
                        hodiny(1);
        }
        else if ((rozhodnuti == 'O') || (rozhodnuti == 'o'))
                        odpocet();
        else if ((rozhodnuti == 'S') || (rozhodnuti == 's'))
        {
                        if (stopky()== -1)
                        {
                                       getchar();
                                       return -1;
                        }
        }
        else
        {
            printf("Chyba\n\n");                                                                                       //špatný výběr
            system("pause");
            getchar();
            system("cls");
            chyba++;
        }
    }
    while(chyba !=0);
    while(getchar()!='\n');
    getchar();
    return 0;
}

void budik()                                                                                  //f-ce pro nastavení času zvonění
{
     int znaky;
     do
     {
         znaky  = 0;
         system("cls");
         system("if not exist ano.txt vyber.bat");
         system("cls");
         printf("Zadejte hodinu upozorn%cn%c:",eee,ii);
         scanf("%d",&budikHod);
         while(getchar() != '\n')
                         znaky++;
         system("cls");
         printf("Zadejte minutu:");
         scanf("%d",&budikMin);
         while(getchar() != '\n')
                         znaky++;
         if(znaky != 0)
         {
                  printf("Chyba, pi%cte pros%cm pouze cel%c %c%csla\n\n",sss,ii,aa,ccc,ii);
                  system("pause");
         }
         system("cls");
     }
     while(znaky !=0);
}

void odpocet()                          //f-ce pro celý odpočet
{
     int znaky;
     
     int odp_minuta;
     int odp_hodina;
     int odp_sekunda=0;
     int zapis;
     int zapis_sekunda;
     int zbytekZHodiny;
     system("cls");
     system("if not exist ano.txt vyber.bat");
     do                                       //zadání zpoždění
     {
         znaky=0;
         system("cls");
         printf("Zadejte pros%cm v minut%cch po%cadovan%c zpo%cd%cn%c:",ii,aa,zzz,ee,zzz,eee,ii);
         scanf("%d", &zapis);
         while(getchar() != '\n')
                         znaky++;
         if(znaky != 0)
         {
                  printf("Chyba, pi%cte pros%cm pouze cel%c %c%csla\n\n",sss,ii,aa,ccc,ii);
                  system("pause");
         }
     }
     while(znaky !=0);
     
     aktualniCas();
     
     
     odp_hodina=zapis/60;                       //převod
     odp_minuta=zapis%60;
     
     int odp_sekund=zapis*60;
     int konec=celkemSekund+odp_sekund;
     
         int hodDes;
         int hodJed;
        
         int minDes;
         int minJed;
        
         int secDes;
         int secJed;
     int vynechat = 0;
    
     while((odp_hodina !=0)||(odp_minuta !=0)||(odp_sekunda!=0))
     {
         system("cls");
         if (odp_sekunda %10 == 0 && odp_sekunda != 0 || odp_sekunda==3 && (odp_hodina != 0 || odp_minuta != 0 || odp_sekunda > 15 ))
         {
                         aktualniCas();
                         odp_sekund= konec-celkemSekund;
                         odp_hodina= odp_sekund/3600;
                         odp_minuta= (odp_sekund%3600)/60;
                         odp_sekunda= odp_sekund%60;
         }
         if (odp_sekunda==0)                                    //odečtení 1 sekundy
         {
                            odp_minuta--;
                            odp_sekunda=59;
         }
         if ((odp_minuta==0)&&(odp_hodina!=0))
         {
                           odp_hodina--;
                           odp_minuta=59;
         }
         if (odp_hodina==-1)
                            odp_hodina=0;
         if (odp_minuta==-1)
                            odp_minuta=0;
         
         
         //Převod hodin
         hodDes = odp_hodina/10;
         hodJed = odp_hodina%10;
     
         //Převod minut
         minDes = odp_minuta/10;
         minJed = odp_minuta%10;
     
         //Převod sekund
         secDes = odp_sekunda/10;
         secJed = odp_sekunda%10;                             //Rozdělení čísel na číslice
         vypis(hodDes, hodJed, minDes, minJed, secDes, secJed);           //výpis
         
         system("ping localhost -n 2 >nul");           //zpoždění + odečtení 1s
         odp_sekunda--;
     }
     buzeni();
     system("cls");
     vypis(0, 0, 0, 0, 0, 0);
}

void hodiny(int rozhodovani)                                //Hlavní f-ce pro hodiny a budík
{
    aktualniCas();
    int hodDes;
    int hodJed;

    int minDes;
    int minJed;

    int secDes;
    int secJed;
    while(hodina!=50)                                      //Hlavní cyklus Hodin (nekonečný)
    {
                     system("cls");
                     
                     //P�evod hodin
                     hodDes = hodina/10;
                     hodJed = hodina%10;
     
                     //P�evod minut
                     minDes = minuta/10;
                     minJed = minuta%10;
     
                     //P�evod sekund
                     secDes = sekunda/10;
                     secJed = sekunda%10;                             //Rozdělení čísel na číslice
                     vypis(hodDes, hodJed, minDes, minJed, secDes, secJed);  //výpis
                     if (kontrola ==0)                             //výpis nastavení budíku
                     {
                             if (rozhodovani ==1)
                             {
                                            if((budikHod<10)&&(budikMin<10))
                                            {
                                                                            printf("\nBud%ck je nastaven na 0%d:0%d",ii,budikHod,budikMin);
                                            }
                                            else if (budikHod <10)
                                                 printf("\nBud%ck je nastaven na 0%d:%d",ii,budikHod,budikMin);
                                            else if (budikMin<10)
                                                 printf("\nBud%ck je nastaven na %d:0%d",ii,budikHod,budikMin);
                                            else
                                            printf("\nBud%ck je nastaven na %d:%d",ii,budikHod,budikMin);
                             }
                     }
                     system("ping localhost -n 2 >nul");                 //Zpoždění a přičtení 1s
                     sekunda++;
                     if ((sekunda==59)||(sekunda%10==0))
                     {
                                     aktualniCas();
                     }
                     if(sekunda==59)
                     {
                                    sekunda=0;
                                    minuta++;
                     }
                     if (kontrola ==0)
                     {
                             if (rozhodovani ==1)
                             {
                                            if(budikHod == hodina)
                                            {
                                                        if(budikMin == minuta)
                                                        {
                                                                    buzeni();                  //pustí zvuk
                                                                    kontrola++;                //Při inkrementaci vím, že buzení již proběhlo
                                                        }
                                            }
                             }
                     }
    }
}

int stopky()
{
     system("cls");
     system("start stopky.exe");
     int hodDes;
     int hodJed;
     int minDes;
     int minJed;
     int secDes;
     int secJed = 5;
     int secondsAktual;
     int kontrola;
     do
     {     
         system("ping localhost -n 3 >nul");
         secondsAktual = secJed;
         souborStopky = fopen ("cas.txt","rt");
         if (souborStopky == NULL)
         {
                          printf("Soubor %s se nepoda%cilo otev%c%ct",SOUBOR,rrr,rrr,ii);
                          getchar();
                          return -1;
         }
         while(kontrola=fscanf(souborStopky,"%d %d %d %d %d %d",&hodDes, &hodJed, &minDes, &minJed, &secDes, &secJed)==6);
         {
               system("cls");
               vypis(hodDes, hodJed, minDes, minJed, secDes, secJed);
         }
         if (fclose(souborStopky)==EOF)
         {
                          printf("Chybn%c uzav%cen%c souboru %s.\n",ee,rrr,ii,SOUBOR);
                          getchar();
                          return -1;
         }
//         printf("%d%d %d%d %d%d",hodDes, hodJed, minDes, minJed, secDes, secJed);
//         system("pause");
     }
     while(secondsAktual != secJed);
}


void aktualniCas()             //získá aktuální čas v sekundách a převede jej na minuty, hodiny a sekundy v proměnných sekunda, minuta, hodina
{
    time_t timer;
    struct tm y2k;
    double seconds;
    int cas;

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

    time(&timer);  /* get current time; same as: timer = time(NULL)  */

    seconds = difftime(timer,mktime(&y2k));
    int seccc;
    seccc=seconds;
    celkemSekund=seccc;
    int zbytSec;
    int zbytMin;
    int hod;
    
    zbytSec = seccc/60;
    sekunda = seccc%60;
    
    zbytMin = zbytSec/60;
    minuta = zbytSec%60;
    
    hodina = zbytMin%24;
}



void vypis(int hodDes, int hodJed, int minDes, int minJed, int secDes, int secJed)
{
     //První řádek
     printf("\t\t");
     prvni(hodDes);   //Hodina
     prvni(hodJed);
                   printf("  ");
     prvni(minDes);   //Minuta
     prvni(minJed);
                   printf("  ");
     prvni(secDes);   //Sekunda
     prvni(secJed);
                   printf("\n");
     
     //Druhý řádek
     printf("\t\t");
     druhyTreti(hodDes);   //Hodina
     druhyTreti(hodJed);
          printf("  ");
     druhyTreti(minDes);   //Minuta
     druhyTreti(minJed);
          printf("  ");
     druhyTreti(secDes);   //Sekunda
     druhyTreti(secJed);
          printf("\n");
     
     //Třetí řádek
     printf("\t\t");
     druhyTreti(hodDes);   //Hodina
     druhyTreti(hodJed);
          printf("%c ",i);
     druhyTreti(minDes);   //Minuta
     druhyTreti(minJed);
          printf("%c ",i);
     druhyTreti(secDes);   //Sekunda
     druhyTreti(secJed);
          printf("\n");
     
     //Čtvrtý řádek
     printf("\t\t");
     ctvrty(hodDes);   //Hodina
     ctvrty(hodJed);
          printf("  ");
     ctvrty(minDes);   //Minuta
     ctvrty(minJed);
          printf("  ");
     ctvrty(secDes);   //Sekunda
     ctvrty(secJed);
          printf("\n");
     
     //Pátý řádek
     printf("\t\t");
     patySesty(hodDes);   //Hodina
     patySesty(hodJed);
          printf("%c ",i);
     patySesty(minDes);   //Minuta
     patySesty(minJed);
          printf("%c ",i);
     patySesty(secDes);   //Sekunda
     patySesty(secJed);
          printf("\n");
     
     //Šestý řádek
     printf("\t\t");
     patySesty(hodDes);   //Hodina
     patySesty(hodJed);
          printf("  ");
     patySesty(minDes);   //Minuta
     patySesty(minJed);
          printf("  ");
     patySesty(secDes);   //Sekunda
     patySesty(secJed);
          printf("\n");
     
     //Sedmý řádek
     printf("\t\t");
     sedmy(hodDes);   //Hodina
     sedmy(hodJed);
          printf("  ");
     sedmy(minDes);   //Minuta
     sedmy(minJed);
          printf("  ");
     sedmy(secDes);   //Sekunda
     sedmy(secJed);
          printf("\n");
}


void prvni(int cislo)          //výpis prvního řádku
{
     switch (cislo)                                       
     {
            case 0:
                 tri();
                 break;
            case 1:
                 prava();
                 break;
            case 2:
                 tri();
                 break;
            case 3:
                 tri();
                 break;
            case 4:
                 dve();
                 break;
            case 5:
                 tri();
                 break;
            case 6:
                 tri();
                 break;
            case 7:
                 tri();
                 break;
            case 8:
                 tri();
                 break;
            case 9:
                 tri();
                 break;
            default:
                 printf("Chyba");
                 break;
     }
}

void druhyTreti(int cislo)      //výpis druhého a třetího řádku
{
     switch (cislo)                                       
     {
            case 0:
                 dve();
                 break;
            case 1:
                 prava();
                 break;
            case 2:
                 prava();
                 break;
            case 3:
                 prava();
                 break;
            case 4:
                 dve();
                 break;
            case 5:
                 leva();
                 break;
            case 6:
                 leva();
                 break;
            case 7:
                 prava();
                 break;
            case 8:
                 dve();
                 break;
            case 9:
                 dve();
                 break;
            default:
                 printf("Chyba");
                 break;
     }
}

void ctvrty(int cislo)                                    //výpis 4. řádku
{
     switch (cislo)                                       
     {
            case 0:
                 dve();
                 break;
            case 1:
                 prava();
                 break;
            case 2:
                 tri();
                 break;
            case 3:
                 tri();
                 break;
            case 4:
                 tri();
                 break;
            case 5:
                 tri();
                 break;
            case 6:
                 tri();
                 break;
            case 7:
                 prava();
                 break;
            case 8:
                 tri();
                 break;
            case 9:
                 tri();
                 break;
            default:
                 printf("Chyba");
                 break;
     }
}

void patySesty(int cislo)                                         //výpis 5., 6. řádku
{
     switch (cislo)                                       
     {
            case 0:
                 dve();
                 break;
            case 1:
                 prava();
                 break;
            case 2:
                 leva();
                 break;
            case 3:
                 prava();
                 break;
            case 4:
                 prava();
                 break;
            case 5:
                 prava();
                 break;
            case 6:
                 dve();
                 break;
            case 7:
                 prava();
                 break;
            case 8:
                 dve();
                 break;
            case 9:
                 prava();
                 break;
            default:
                 printf("Chyba");
                 break;
     }
}

void sedmy(int cislo)                                     //výpis 7. řádku
{
     switch (cislo)                                       
     {
            case 0:
                 tri();
                 break;
            case 1:
                 prava();
                 break;
            case 2:
                 tri();
                 break;
            case 3:
                 tri();
                 break;
            case 4:
                 prava();
                 break;
            case 5:
                 tri();
                 break;
            case 6:
                 tri();
                 break;
            case 7:
                 prava();
                 break;
            case 8:
                 tri();
                 break;
            case 9:
                 tri();
                 break;
            default:
                 printf("Chyba");
                 break;
     }
}


void tri()                                                //výpis plného vodorovného segmentu ooo
{
     printf(" %c%c%c  ",i,i,i);
}

void dve()                                               //výpis obou svislých segmentů o|o
{
     printf("%c   %c ",i,i);
}

void leva()                                             //výpis pouze levého segmentu o||
{
     printf("%c     ",i);
}

void prava()                                            //výpis pouze pravého segmentu ||o
{
     printf("    %c ",i);
}


void buzeni()                                           //spuštění zvuku
{
     system("aktual.mp3");
}




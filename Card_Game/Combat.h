#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <unistd.h>

using namespace std;

// Def joueur 1
int HP_J1 = 100;
int Shield_J1 = 30;
int Fournisseur_J1 = 1;
string Deck_J1[30];
int NB_Deck_J1 = 30;
string main_J1[100];
int init_deck = 0;
string tableau_J1[5];
int NB_Carte_J1 = 0;


// Def joueur 2
int HP_J2 = 100;
int Shield_J2 = 30;
int Fournisseur_J2 = 1;
string Deck_J2[30];
int NB_Deck_J2 = 30;
string tableau_J2[5];
int choix;
int NB_Carte_J2;


string carte[100];
int NB_Tour = 1;
int NB_Total_Carte = 5;

void menu();
void Tour_J1();
void Tour_J2();

void Card(){
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    int a = 0;
    int demande = 0;
    int demande2 = 0;
    char nom[20];
    int type;
    int prix;
    int puissance;
    int recource;
    int choix = 0;

    printf("Voici la liste des cartes:\n");
    for(int i=0; i<NB_Total_Carte; i++){
        cout << carte[i] << endl;
    }


    printf("\nQue voulez vous faire?\n");
    printf("1.Creer?\n");
    printf("2.Supprimer?\n");
    printf("3.Modifier\n");
    printf("4.Retour\n");
    scanf("%i", &demande);

    if(demande == 3){
        demande = 1;
        demande2 = 1;

    }
    if(demande == 1){

        choix = 0;
        if(demande2 == 1){
            printf("Qu'elle carte voulez vous modifier?\n");
            scanf("%i", &choix);

        }
        printf("Qu'elle est le nom de la carte?\n");

        scanf("%s", nom);


        printf("Qu'elle resource conssomme t'elle?\n");
        printf("1.Mana\n");
        scanf("%i", &recource);

        printf("Qu'elle est le coup de la carte?\n");
        scanf("%i", &prix);

        printf("Qu'affect elle?\n");
        printf("1.Vos fournisseur\n");
        printf("2.Leur vie\n");
        printf("3.Votre vie\n");
        printf("4.Votre bouclier\n");
        scanf("%i", &type);

        printf("Qu'elle puissance a la carte?\n");
        scanf("%i", &puissance);

        if(demande2 == 0){
            a = NB_Total_Carte;
        }else{
            a = choix - 1;
        }
        int b = 1;

        string converte[10] = {"1","2","3","4","5","6","7","8","9","10"};

        string str = converte[type-1];
        string str2 = converte[prix-1];
        string str4 = converte[puissance-1];

        string str3;
        if(recource == 1){
              str3 = "Mana";
        }

        carte[a] = "";
        carte[a] += str;
        carte[a] += ",";
        carte[a] += str;
        carte[a] += ",";
        carte[a] += str2;
        carte[a] += ",";
        carte[a] += nom;
        carte[a] += ",";
        carte[a] += str3;

        NB_Total_Carte++;

    }
    else if(demande == 2)
    {
        printf("Qu'elle carte voulez vous supprimer?\n");
        scanf("%i", &choix);
        a = choix - 1;

        carte[a] = "";


        printf("La carte a bien etait supprimer\n");
        NB_Total_Carte--;
    }

    string const nomFichier("C:/test.txt");
    ofstream monFlux(nomFichier.c_str());
    a = NB_Total_Carte;

    if(monFlux)
    {
        monFlux << carte[a] << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}

int verification(int v, int m){
    if(v >= 0 and v <= m){
        return 0;
    }
    else{
        printf("Ce que vous avez rentrer n'est pas dans les choix");
        return 1;
    }
}

void pioche_J1(){
    Deck_J1[NB_Carte_J1] = Deck_J1[NB_Deck_J1-1];
    Deck_J1[NB_Deck_J1-1] = "";
    NB_Deck_J1--;
}

void pioche_J2(){
    Deck_J2[NB_Carte_J2] = Deck_J2[NB_Deck_J2-1];
    Deck_J2[NB_Deck_J2-1] = "";
    NB_Deck_J2--;
}

void attaque_J1(){
    int i = 1;
    for(int o = 0; o < 7; o++){
        string affiche = Deck_J1[o];
        if(affiche[0] == '2'){
            cout << i << " - " << affiche << endl;
            i++;
        }
    }
    if(i == 1){
        printf("Vous n'avez aucune carte permettant d'attaquer.\n");
        Sleep(3000);
        Tour_J1();
    }
    else{
        printf("Quel carte voulez vous utiliser? \n - ");
        scanf("%i",&choix);
        int test = 1;
        for(int o = 0; o < 7; o++){
            string affiche = Deck_J1[o];
            if(affiche[0] == '2'){
                if(choix == test){
                    if(Shield_J2 > 0){
                        Shield_J2--;
                    }
                    else{
                        HP_J2--;
                    }
                    Deck_J1[o] = "";
                    NB_Carte_J1 = o;
                }
                test++;
            }
        }
    }
}

void attaque_J2(){
    int i = 1;
    for(int o = 0; o < 7; o++){
        string affiche = Deck_J2[o];
        if(affiche[0] == '2'){
            cout << i << " - " << affiche << endl;
            i++;
        }
    }
    if(i == 1){
        printf("Vous n'avez aucune carte permettant d'attaquer.\n");
        Sleep(3000);
        Tour_J2();
    }
    else{
        printf("Quel carte voulez vous utiliser? \n - ");
        scanf("%i",&choix);
        int test = 1;
        for(int o = 0; o < 7; o++){
            string affiche = Deck_J2[o];
            if(affiche[0] == '2'){
                if(choix == test){
                    if(Shield_J1 > 0){
                        Shield_J1--;
                    }
                    else{
                        HP_J1--;
                    }
                    NB_Carte_J2 = o;
                    Deck_J2[o] = "";
                }
                test++;
            }
        }
    }
}

void deffausse_J1(){
    for(int o = 0; o < 7; o++){
        string affiche = Deck_J1[o];
        int a = 6;
        string test;
        while(a < affiche.size()){

            char d = affiche[a];
            test += d;
            a++;
        }
        cout << o << " : " << test << endl;
    }
    printf("7 : Revenir ou vous etiez \nQuel carte voulez vous deffausser? \n - ");
    scanf("%i", &choix);
    if(verification(choix, 7) == 0){
        Deck_J1[choix] = "";
        NB_Carte_J1 = choix;
    }
}

void deffausse_J2(){
    for(int o = 0; o < 7; o++){
        string affiche = Deck_J2[o];
        int a = 6;
        string test;
        while(a < affiche.size()){

            char d = affiche[a];
            test += d;
            a++;
        }
        cout << o << " : " << test << endl;
    }
    printf("7 : Revenir ou vous etiez \nQuel carte voulez vous deffausser? \n - ");
    scanf("%i", &choix);
    if(verification(choix, 7) == 0){
        Deck_J2[choix] = "";
        NB_Carte_J2 = choix;
    }
}

void Tour_J1(){
    system("cls");

    printf("J1 \nTour : %d \n \n \n", NB_Tour);

    // info ennemie
    printf("HP ennemi :  %d \n", HP_J2);
    printf("Shield ennemi : %d\n",Shield_J2);
    printf("Fournisseur ennemi : %d \n" ,Fournisseur_J2);
    //printf("Carte ennemi poser :  \n");
    //for(int o = 0; o < 5; o++){
    //    cout << tableau_J2[o] << endl;
    //}
    //if(tableau_J2[0] != ""){
        printf("\n\n\n");
    //}

    // t'es info
    printf("Vos HP :  %d \n", HP_J1);
    printf("Votre shield : %d\n",Shield_J1);
    printf("Votre fournisseur : %d \n" ,Fournisseur_J1);
    //printf("Carte poser :  \n");
    printf("Carte en main : \n");
    for(int o = 0; o < 7; o++){
        string affiche = Deck_J1[o];
        int a = 6;
        string test;
        while(a < affiche.size()){

            char d = affiche[a];
            test += d;
            a++;
        }
        cout << " - " << test << endl;
    }
    printf("Deck : %d \n", NB_Deck_J1);
    printf("Que voulez vous faire? \n - 1 : Poser une carte \n - 2 : Attaquer \n - 3 : Defausse une carte \n - 4 : Retourner au menu \n -");
    scanf("%i",&choix);
    if (verification(choix, 4) == 0){
        switch(choix){
            case 1:
                system("cls");
                printf("Carte en main : \n");
                for(int o = 0; o < 7; o++){
                    string affiche = Deck_J1[o];
                    int a = 6;
                    string test;
                    while(a < affiche.size()){

                        char d = affiche[a];
                        test += d;
                        a++;
                    }
                    cout << o << " : " << test << endl;
                }
                printf("7 : Rien retourner au choix precedent \nQuel carte voulez vous jouer? \n -");
                scanf("%i", &choix);
                if(verification(choix, 7) == 0){
                    switch(choix){
                        case 0:{
                            string affiche = Deck_J1[0];
                            if(affiche[0] == '1'){
                                Fournisseur_J1++;
                                Deck_J1[0] = "";
                                NB_Carte_J1 = 0;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J1++;
                                Deck_J1[0] = "";
                                NB_Carte_J1 = 0;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J1++;
                                Deck_J1[0] = "";
                                NB_Carte_J1 = 0;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J1();
                                break;
                            }
                        }
                        case 1:{
                            string affiche = Deck_J1[1];
                            if(affiche[0] == '1'){
                                Fournisseur_J1++;
                                Deck_J1[1] = "";
                                NB_Carte_J1 = 1;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J1++;
                                Deck_J1[1] = "";
                                NB_Carte_J1 = 1;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J1++;
                                Deck_J1[1] = "";
                                NB_Carte_J1 = 1;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J1();
                                break;
                            }
                        }
                        case 2:{
                            string affiche = Deck_J1[2];
                            if(affiche[0] == '1'){
                                Fournisseur_J1++;
                                Deck_J1[2] = "";
                                NB_Carte_J1 = 2;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J1++;
                                Deck_J1[2] = "";
                                NB_Carte_J1 = 2;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J1++;
                                Deck_J1[2] = "";
                                NB_Carte_J1 = 2;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J1();
                                break;
                            }
                        }
                        case 3:{
                            string affiche = Deck_J1[3];
                            if(affiche[0] == '1'){
                                Fournisseur_J1++;
                                Deck_J1[3] = "";
                                NB_Carte_J1 = 3;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J1++;
                                Deck_J1[3] = "";
                                NB_Carte_J1 = 3;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J1++;
                                Deck_J1[3] = "";
                                NB_Carte_J1 = 3;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J1();
                                break;
                            }
                        }
                        case 4:{
                            string affiche = Deck_J1[4];
                            if(affiche[0] == '1'){
                                Fournisseur_J1++;
                                Deck_J1[4] = "";
                                NB_Carte_J1 = 4;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J1++;
                                Deck_J1[4] = "";
                                NB_Carte_J1 = 4;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J1++;
                                Deck_J1[4] = "";
                                NB_Carte_J1 = 4;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J1();
                                break;
                            }

                        }
                        case 5:{
                            string affiche = Deck_J1[5];
                            if(affiche[0] == '1'){
                                Fournisseur_J1++;
                                Deck_J1[5] = "";
                                NB_Carte_J1 = 5;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J1++;
                                Deck_J1[5] = "";
                                NB_Carte_J1 = 5;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J1++;
                                Deck_J1[5] = "";
                                NB_Carte_J1 = 5;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J1();
                                break;
                            }
                        }
                        case 6:{
                            string affiche = Deck_J1[6];
                            if(affiche[0] == '1'){
                                Fournisseur_J1++;
                                Deck_J1[6] = "";
                                NB_Carte_J1 = 6;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J1++;
                                Deck_J1[6] = "";
                                NB_Carte_J1 = 6;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J1++;
                                Deck_J1[6] = "";
                                NB_Carte_J1 = 6;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J1();
                                break;
                            }
                        }

                        case 7:
                            Tour_J1();
                            break;

                        default:
                            break;
                    }
                }
                break;
            case 2:
                attaque_J1();
                break;

            case 3:
                system("cls");
                deffausse_J1();
                break;

            case 4:
                menu();
                break;
        }
    }
    else{
        Tour_J1();
    }
}

void Tour_J2(){
    system("cls");

    printf("J2 \nTour : %d \n \n \n", NB_Tour);

    // info ennemie
    printf("HP ennemi :  %d \n", HP_J1);
    printf("Shield ennemi : %d\n",Shield_J1);
    printf("Fournisseur ennemi : %d \n" ,Fournisseur_J1);
    //printf("Carte ennemi poser :  \n");
    //for(int o = 0; o < 5; o++){
    //    cout << tableau_J2[o] << endl;
    //}
    //if(tableau_J2[0] != ""){
        printf("\n\n\n");
    //}

    // t'es info
    printf("Vos HP :  %d \n", HP_J2);
    printf("Votre shield : %d\n",Shield_J2);
    printf("Votre fournisseur : %d \n" ,Fournisseur_J2);
    //printf("Carte poser :  \n");
    printf("Carte en main : \n");
    for(int o = 0; o < 7; o++){
        string affiche = Deck_J2[o];
        int a = 6;
        string test;
        while(a < affiche.size()){

            char d = affiche[a];
            test += d;
            a++;
        }
        cout << " - " << test << endl;
    }
    printf("Deck : %d \n", NB_Deck_J2);
    printf("Que voulez vous faire? \n - 1 : Poser une carte \n - 2 : Attaquer \n - 3 : Defausse une carte \n - 4 : Retourner au menu \n -");
    scanf("%i",&choix);
    if (verification(choix, 4) == 0){
        switch(choix){
            case 1:
                system("cls");
                printf("Carte en main : \n");
                for(int o = 0; o < 7; o++){
                    string affiche = Deck_J2[o];
                    int a = 6;
                    string test;
                    while(a < affiche.size()){

                        char d = affiche[a];
                        test += d;
                        a++;
                    }
                    cout << o << " : " << test << endl;
                }
                printf("7 : Rien retourner au choix precedent \nQuel carte voulez vous jouer? \n -");
                scanf("%i", &choix);
                if(verification(choix, 7) == 0){
                    switch(choix){
                        case 0:{
                            string affiche = Deck_J2[0];
                            if(affiche[0] == '1'){
                                Fournisseur_J2++;
                                Deck_J2[0] = "";
                                NB_Carte_J2 = 0;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J2++;
                                Deck_J2[0] = "";
                                NB_Carte_J2 = 0;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J2++;
                                Deck_J2[0] = "";
                                NB_Carte_J2 = 0;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J2();
                                break;
                            }
                        }
                        case 1:{
                            string affiche = Deck_J2[1];
                            if(affiche[0] == '1'){
                                Fournisseur_J2++;
                                Deck_J2[1] = "";
                                NB_Carte_J2 = 1;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J2++;
                                Deck_J2[1] = "";
                                NB_Carte_J2 = 1;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J2++;
                                Deck_J2[1] = "";
                                NB_Carte_J2 = 1;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J2();
                                break;
                            }
                        }
                        case 2:{
                            string affiche = Deck_J2[2];
                            if(affiche[0] == '1'){
                                Fournisseur_J2++;
                                Deck_J2[2] = "";
                                NB_Carte_J2 = 2;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J2++;
                                Deck_J2[2] = "";
                                NB_Carte_J2 = 2;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J2++;
                                Deck_J2[2] = "";
                                NB_Carte_J2 = 2;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J2();
                                break;
                            }
                        }
                        case 3:{
                            string affiche = Deck_J2[3];
                            if(affiche[0] == '1'){
                                Fournisseur_J2++;
                                Deck_J2[3] = "";
                                NB_Carte_J2 = 3;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J2++;
                                Deck_J2[3] = "";
                                NB_Carte_J2 = 3;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J2++;
                                Deck_J2[3] = "";
                                NB_Carte_J2 = 3;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J2();
                                break;
                            }
                        }
                        case 4:{
                            string affiche = Deck_J2[4];
                            if(affiche[0] == '1'){
                                Fournisseur_J2++;
                                Deck_J2[4] = "";
                                NB_Carte_J2 = 4;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J2++;
                                Deck_J2[4] = "";
                                NB_Carte_J2 = 4;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J2++;
                                Deck_J2[4] = "";
                                NB_Carte_J2 = 4;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J2();
                                break;
                            }

                        }
                        case 5:{
                            string affiche = Deck_J2[5];
                            if(affiche[0] == '1'){
                                Fournisseur_J2++;
                                Deck_J2[5] = "";
                                NB_Carte_J2 = 5;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J2++;
                                Deck_J2[5] = "";
                                NB_Carte_J2 = 5;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J2++;
                                Deck_J2[5] = "";
                                NB_Carte_J2 = 5;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J2();
                                break;
                            }
                        }
                        case 6:{
                            string affiche = Deck_J2[6];
                            if(affiche[0] == '1'){
                                Fournisseur_J2++;
                                Deck_J2[6] = "";
                                NB_Carte_J2 = 6;
                                break;
                            }
                            else if(affiche[0] == '3'){
                                HP_J2++;
                                Deck_J2[6] = "";
                                NB_Carte_J2 = 6;
                                break;
                            }
                            else if(affiche[0] == '4'){
                                Shield_J2++;
                                Deck_J2[6] = "";
                                NB_Carte_J2 = 6;
                                break;
                            }
                            else{
                                printf("Cette carte a un effet inconnu");
                                Tour_J2();
                                break;
                            }
                        }

                        case 7:
                            Tour_J1();
                            break;

                        default:
                            break;
                    }
                }
                break;
            case 2:
                attaque_J2();
                break;
            case 3:
                system("cls");
                deffausse_J2();
                break;
            case 4:
                menu();
                break;
        }
    }
    else{
        Tour_J1();
    }
}

void Tour_IA(){

    int nb_random = rand() % 3;
    switch (nb_random){
        case 1:
            if(Shield_J1>0){
                Shield_J1--;
            }else{
                HP_J1--;
            }
            break;
        case 2:
            if(HP_J2 < 100){
                HP_J2++;
            }
            else{
                Shield_J2++;
            }
            break;
        case 3:
            Fournisseur_J2++;
            break;
    }



}

void Combat_J(){

    if(init_deck == 0){
        for(int i = 0 ; i < 30 ; i++){
            int nb_random = rand() % NB_Total_Carte;
            Deck_J1[i] = carte[nb_random];
        }
        for(int i = 0 ; i < 30 ; i++){
            int nb_random = rand() % NB_Total_Carte;
            Deck_J2[i] = carte[nb_random];
        }
        init_deck = 1;
    }
    while((HP_J1 || HP_J2) > 0) {
        Tour_J1();
        pioche_J1();
        Tour_J2();
        pioche_J2();
        NB_Tour++;
        if(Shield_J1>30){
            Shield_J1 = 30;
        }
        if(Shield_J2>30){
            Shield_J2 = 30;
        }
    }
}

void Combat_IA(){
    while((HP_J1 || HP_J2) > 0) {
        if(init_deck == 0){
        for(int i = 0 ; i < 30 ; i++){
            int nb_random = rand() % NB_Total_Carte;
            Deck_J1[i] = carte[nb_random];
        }
        for(int i = 0 ; i < 30 ; i++){
            int nb_random = rand() % NB_Total_Carte;
            Deck_J2[i] = carte[nb_random];
        }
        init_deck = 1;
    }
    while((HP_J1 || HP_J2) > 0) {
        Tour_J1();
        pioche_J1();
        Tour_IA();
        NB_Tour++;
        if(Shield_J1>30){
            Shield_J1 = 30;
        }
        if(Shield_J2>30){
            Shield_J2 = 30;
        }
    }
    }
}

void info(){

    system("cls");
    printf("Binvenue sur Card Game!!!\n");
    printf("Je vais vous presenter les regles du jeux\n");
    printf("Les joueur commence avec 7 cartes en main\n");
    printf("Au debut de chaque tour le joueur pioche une carte\n");
    printf("Il as ensuite 2 option sois il joue une carte sois il defauce une carte\n");
    printf("Et c'est ensuite au tour de l'adeverser\n");

    printf("\n\n\n\n");
    printf("Il est aussi possible de creer modifier ou supprimer les cartes du jeux \n");
    printf("1.Retour\n");
    scanf("%i",&choix);
    if(verification(choix,1) == 0){
        menu();
    }
    else{
        Sleep(3000);
        info();
    }
}

// partie recuperation des donnees
int recup_fichier(){


    int b = 0;
    int c = 0;
    string d;

    ifstream fichier("D:/Cours/Projet/Projet_Dev/Card_Game/Carte/test.txt");

    if(fichier)
    {
      //L'ouverture s'est bien passée, on peut donc lire

        string ligne; //Une variable pour stocker les lignes lues

        while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            //Et on l'affiche dans la console
            //Ou alors on fait quelque chose avec cette ligne
            //À vous de voir
            int a = 0;
            b = ligne.size();

            while(a < b){

                d = ligne[a];
                carte[c] += d;
                a++;
            }
            cout << carte[c] << endl;
            c++;
        }
    }
    else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

    return 0;

}

//parti du menu d'accueil
void menu(){
    system("cls");
    int a = 0;
    printf("Bienvenue dans le jeux!!!\n");
    printf("Que voulez faire.\n");
    printf("1.Jouer 1 VS 1\n");
    printf("2.Jouer 1 VS IA\n");
    printf("3.Carte\n");
    printf("4.Guide de jeux\n");
    printf("5.Quitter\n");

    scanf ("%i",&a);
    if (verification(a,6) == 0){
        switch (a) {

            case 1:
                Combat_J();
                break;
            case 2:
                Combat_IA();
                break;
            case 3:
                Card();
                menu();
                break;
            case 4:
                info();
                break;
            case 5:
                exit(0);
                break;
        }
    }
}
#endif // COMBAT_H_INCLUDED

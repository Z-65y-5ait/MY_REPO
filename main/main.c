#include <stdio.h>
#include <string.h>
#define CMAX 100



typedef struct SAdherent{
    int adh_Index;
    char adh_Nom[CMAX];
    int adh_NbEmprunts;
}Adherent;

typedef struct SLivre{
    int liv_Index;
    char liv_Titre[CMAX];
    char liv_Auteur[CMAX];
    int liv_Emprunteur;
}Livre;

void ft_print_adh(Adherent *adh){
    int i=0;
    int CMAX_1=sizeof(adh->adh_Nom);
    printf("enter the index_of_adherent:");
    scanf("%d",&adh->adh_Index);
    printf("enter the name of the index_of_adherent:");
    while (i<CMAX_1){
        scanf("%s",&adh->adh_Nom[i]);
        i++;
    }
    printf("enter the number of emprunts:");
    scanf("%d",&adh->adh_NbEmprunts);
}

void ft_print_liv(Livre *liv){
    int j=0;
    int k=0;
    int CMAX_2=sizeof(liv->liv_Auteur);
    int CMAX_3=sizeof(liv->liv_Titre);
    printf("enter index of the book:");
    scanf("%d",&liv->liv_Index);
    printf("enter the title");
    while (j<CMAX_2){
        scanf("%s",&liv->liv_Titre[j]);
        j++;
    }
    while (k<CMAX_3){
        scanf("%s",&liv->liv_Titre[k]);
        k++;
    }
    printf("enter the book emprunter:");
    scanf("%d",&liv->liv_Emprunteur);
}

void Ajout_adherent(Adherent *adh[],int *pborne,int taille,int Index_andherent,char *Nom,int NbEmprunts){
    if(*pborne<taille){
        adh[*pborne]->adh_Index=Index_andherent;
        strcpy(adh[*pborne]->adh_Nom,Nom);
        adh[*pborne]->adh_NbEmprunts=NbEmprunts;
        pborne++;
    }
    else{
        printf("no more places");
    }
}

void supprimer_adherent(Adherent *adh[],int *pborne,int taille,int Index_andherent){
    int found=0;
    while(*pborne<taille){
        if(adh[*pborne]->adh_Index==Index_andherent){
            found=1;
        }
        if(found==1){
            adh[*pborne]=adh[*pborne+1];
        }
        pborne++;
        taille--;
    }
}

void order_adherent(Adherent *adh[],int borne,int taille){
    int n;
    char temp;
    while(borne<taille-1){
        n=strcmp(adh[borne]->adh_Nom,adh[borne+1]->adh_Nom);
        if(n==0){
            borne++;
        } else if(n>0){
            temp=*adh[borne]->adh_Nom;
            *adh[borne]->adh_Nom=*adh[borne+1]->adh_Nom;
            *adh[borne+1]->adh_Nom=temp;
        }
        else{
            borne++;
        }
        borne++;
    }
    printf("%s",adh[borne]->adh_Nom);
}

void Ajout_livre(Livre *liv[],int *pborne,int taille,int Index_livre,int NbEmprunts,char *Auteur,char *Titre){
    if(*pborne<taille){
        liv[*pborne]->liv_Index=Index_livre;
        strcpy(liv[*pborne]->liv_Titre,Titre);
        strcpy(liv[*pborne]->liv_Auteur,Auteur);
        liv[*pborne]->liv_Emprunteur=NbEmprunts;
        pborne++;
    }
    else{
        printf("no more places for a book");
    }
}

void supprimer_livre(Livre *liv[],int *pborne,int taille,int Index_livre){
    int found=0;
    while(*pborne<taille){
        if(liv[*pborne]->liv_Index==Index_livre){
            found=1;
        }
        if(found==1){
            liv[*pborne]=liv[*pborne+1];
        }
        pborne++;
        taille--;
    }
}

void order_livre(Livre *liv[],int borne,int taille) {
    int n;
    char temp;
    while (borne < taille - 1) {
        n = strcmp(liv[borne]->liv_Titre, liv[borne + 1]->liv_Titre);
        if (n == 0) {
            borne++;
        } else if (n > 0) {
            temp = *liv[borne]->liv_Titre;
            *liv[borne]->liv_Titre = *liv[borne + 1]->liv_Titre;
            *liv[borne + 1]->liv_Titre = temp;
        } else {
            borne++;
        }
        borne++;
    }
    printf("%s",liv[borne]->liv_Titre);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
void Emprunter(Livre *liv[], Adherent *adh[], int borne, int taille){
    int found_1=liv[borne]->liv_Index;
    int found_2=adh[borne]->adh_Index;
    while (borne<taille){
        if(found_1 != '\0' && found_2 != '\0'){
            liv[borne]->liv_Emprunteur=adh[borne]->adh_Index;
            printf("l'adherent %d a emprunter le livre %d",adh[borne]->adh_Index,liv[borne]->liv_Index);
            liv[borne]->liv_Index=liv[borne+1]->liv_Index;
        }
        else{
            printf("livre introuvable");
        }
        borne++;
    }
}

#pragma clang diagnostic pop
void affichage_liv_Emp(Livre *liv[],Adherent *adh[],int borne,int taille){
    while(borne<taille){
        if(liv[borne]->liv_Index!='\0' && liv[borne]->liv_Emprunteur==adh[borne]->adh_Index){
            printf("les livres emprunter sont:%s",liv[borne]->liv_Titre);
        }
        borne++;
    }
}

void Rendre_liv(Livre *liv[],Adherent *adh[],int *pborne,int taille,int Index_livre){
    while(*pborne<taille){
        if(liv[*pborne]->liv_Index != '\0' && adh[*pborne]->adh_Index==liv[*pborne]->liv_Emprunteur){
            printf("le livre d'index %d est rendu avec success:%s",liv[*pborne]->liv_Index,liv[*pborne]->liv_Titre);
        }
        else{
            printf("le livre n'est pas emprunter");
        }
        pborne++;
    }
}

void affichage_Emp_liv(Livre *liv[],Adherent *adh[],int borne,int taille){
    while(borne<taille){
        if(liv[borne]->liv_Index!='\0' && liv[borne]->liv_Emprunteur==adh[borne]->adh_Index){
            printf("les livres emprunter sont:%s",adh[borne]->adh_Nom);
        }
        borne++;
    }
}

int main(void){
    Adherent *adh[CMAX];
    Livre *liv[CMAX];
    FILE *Aderent;
    FILE *Livre;
    int choice = 0;
    printf("\t \t MENU:\n");
    printf("(1) Gestion des adherents:\n");
    printf("\t * Ajouter,Modifier ou supprimer un adherent\n");
    printf("\t * Afficher la liste des adherents par ordre alphabetique\n");
    printf("(2) Gestion des livre:\n");
    printf("\t * Ajouter,Modifier ou supprimer un livre\n");
    printf("\t * Afficher la liste des livres par ordre alphabetique (titre)\n");
    printf("(3) Gestion des emprunts:\n");
    printf("\t * Emprunter un livre");
    printf("\t \t \t * Afficher la liste des livres empruntes\n");
    printf("\t * Rendre un livre");
    printf("\t \t \t * Afficher la liste des empruntes de livres\n");
    printf("(4) Quitter le programme\n");
    ft_print_adh(adh[CMAX]);
    ft_print_liv(liv[CMAX]);
    int Index_adherent=adh[CMAX]->adh_Index;
    char *Nom=adh[CMAX]->adh_Nom;
    int NbEmprunts=adh[CMAX]->adh_NbEmprunts;
    int Index_livre=liv[CMAX]->liv_Index;
    char *Auteur=liv[CMAX]->liv_Auteur;
    char *Titre=liv[CMAX]->liv_Titre;
    Aderent = fopen("Aderent", "w+");
    Livre = fopen("Livre", "w+");
    fprintf(Aderent, "%d %s %d", adh[CMAX]->adh_Index, adh[CMAX]->adh_Nom, adh[CMAX]->adh_NbEmprunts);
    fprintf(Livre, "%d %s %s %d", liv[CMAX]->liv_Index, liv[CMAX]->liv_Titre, liv[CMAX]->liv_Auteur,
            liv[CMAX]->liv_Emprunteur);
    if (choice == 1) {
        Ajout_adherent(adh,0,CMAX,Index_adherent,Nom,NbEmprunts);
        supprimer_adherent(adh,0,CMAX,Index_adherent);
        order_adherent(adh,0,CMAX);
    } else if (choice == 2) {
        Ajout_livre(liv,0,CMAX,Index_livre,NbEmprunts,Auteur,Titre);
        supprimer_livre(liv,0,CMAX,Index_livre);
        order_livre(liv,0,CMAX);
    } else if (choice == 3) {
        Emprunter(liv,adh,0,CMAX);
        affichage_liv_Emp(liv,adh,0,CMAX);
        Rendre_liv(liv,adh,0,CMAX,Index_livre);
        affichage_Emp_liv(liv,adh,0,CMAX);
    } else if (choice == 4) {
        return 0;
    } else {
        printf("please write a number btw 1 and 4");
    }
}





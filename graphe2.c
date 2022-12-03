#include<stdio.h>
#include<stdlib.h>
void initier_dimensions_matrice(int nbnoeuds, int nbaretes);
void remplir_matrice(int tab[][10],int nbnoeuds, int nbaretes);
int choisir_operations();
int gerer_noeuds(int tab[][10],int nbnoeuds);
void afficher_matrice(int tab[][10],int nbnoeuds);
void main()
{
    int matrice[10][10];
    int i, j, nbAretes,nbNoeuds,a,b;

    printf(" Entrez le nombre des noeuds (max 10): ");
    scanf("%d",&nbNoeuds);
    printf(" Entrez le nombre de aretes (max 10): ");
    scanf("%d",&nbAretes);
//  initier_dimensions_matrice(nbNoeuds, nbAretes);
  remplir_matrice(matrice,nbNoeuds,nbAretes);
  afficher_matrice(matrice, nbNoeuds);
  //choisir_operations(matrice);
//  nbNoeuds=gerer_noeuds(matrice,nbNoeuds);
  nbNoeuds=choisir_operations(matrice,nbNoeuds);
  afficher_matrice(matrice, nbNoeuds);
}

void initier_dimensions_matrice(int nbnoeuds, int nbaretes)
{
    printf(" Entrez le nombre des noeuds (max 10): ");
    scanf("%d",&nbnoeuds);
    printf(" Entrez le nombre de aretes (max 10): ");
    scanf("%d",&nbaretes);
}

void remplir_matrice(int tab[][10],int nbnoeuds, int nbaretes)
    {
    int i,j,a,b;
    printf(" Entrez les éléments de tableau : \n");
    for(i = 1; i <= 10; i++)
        for(j = 1; j <= 10; j++)
            tab[i][j]=0;
            
    for(i=0;i<nbaretes;i++)
        {
        printf("Entrez l'arete numero %d: ",i+1);
        printf("\n Entrez le noeud source: ");
        scanf("%d", &a);
        printf("Entrez le noeud destinataire: ");
        scanf("%d", &b);        
        printf("Entrez le poids de l'arete: ");
        scanf("%d", &tab[a][b]);        
        }
    }

int choisir_operations(int tab[][10],int nbnoeuds)
    {
    int i,j,a,b,nb,n;
    int choix=10,newchoix,newnbnoeuds=nbnoeuds;
    char choixx,newchoixx;
    while(choixx!='0')
        {     
        printf("\nchoisir l'option que vous desirez"); 
        printf("\n0- Sortir et afficher la matrice"); 
        printf("\na- Ajouter arete"); 
        printf("\nb- Modifier arete"); 
        printf("\nc- Supprimer arete"); 
        printf("\nd- Ajouter noeuds"); 
        printf("\ne- Supprimer noeuds"); 
        printf("\nEntrez votre choix :="); 
        scanf("%c", &newchoixx);
        printf("\nvotre choix est %d",newchoixx);
        choixx=newchoixx; 
        //printf("\nchoix est %d",choix);
        switch(choixx){
        case 'a':        
            printf("\n---->Ajout Arête<----"); 
            printf("\n Entrez le noeud source: ");
            scanf("%d", &a);
            printf("Entrez le noeud destinataire: ");
            scanf("%d", &b);        
            printf("Entrez le poids de l'arete: ");
            scanf("%d", &tab[a][b]);
            break;  
        case 'b':        
                printf("\n---->Modification Arête<----"); 
                printf("\n Entrez le noeud source: ");
                scanf("%d", &a);
                printf("Entrez le noeud destinataire: ");
                scanf("%d", &b);        
                printf("Entrez le poids de l'arete: ");
                scanf("%d", &tab[a][b]);
                break;        
        case 'c':        
                printf("\n---->Suppression Arête<----"); 
                printf("\n Entrez le noeud source: ");
                scanf("%d", &a);
                printf("Entrez le noeud destinataire: ");
                scanf("%d", &b);        
                tab[a][b]=0;        
        case 'd':        
            printf("\n---->Ajout Noeuds<----"); 
            printf("\n Entrez le nombre des noeuds à ajouter: ");
            scanf("%d", &nb);
            newnbnoeuds+=nb;
            //nbnoeuds+=a;
            break;  
        case 'e':        
                printf("\n---->Suppression Noeuds<----"); 
                printf("\n Entrez le noeud à supprimer: ");
                scanf("%d", &n);
                for(i=1;i<=nbnoeuds;i++)
                    {
                        tab[i][n]=0;
                        tab[n][i]=0;
                    }    
        }        
       }
       return(newnbnoeuds);
    }
/*int gerer_noeuds(int tab[][10],int nbnoeuds)
    {
    int i,j,a,b=nbnoeuds;
    int choix=10,newchoix;
    while(choix!=0)
        {     
        printf("\nchoisir l'option que vous desirez"); 
        printf("\n0- Sortir et afficher la matrice"); 
        printf("\n4- Ajouter noeuds"); 
        printf("\n5- Supprimer noeuds"); 
        printf("\nEntrez votre choix :="); 
        scanf("%d", &newchoix);
        printf("\nvotre choix est %d",newchoix);
        choix=newchoix; 
        //printf("\nchoix est %d",choix);
        switch(choix){
        case 4:        
            printf("\n---->Ajout Noeuds<----"); 
            printf("\n Entrez le nombre des noeuds à ajouter: ");
            scanf("%d", &a);
            b+=a;
            //nbnoeuds+=a;
            break;  
        case 5:        
                printf("\n---->Suppression Noeuds<----"); 
                printf("\n Entrez le noeud à supprimer: ");
                scanf("%d", &a);
                for(i=1;i<=nbnoeuds;i++)
                    {
                        tab[i][a]=0;
                        tab[a][i]=0;
                    }    
        }        
       }
    return (b);
    }
*/
void afficher_matrice(int tab[][10],int nbnoeuds)
    {
    int i,j,k;
    printf(" \n<=Affichage de matrice=> \n");
    for(k = 0; k <= nbnoeuds; k++)
        printf("----");
    printf("\n|\\\\|");
    for(i=1; i <= nbnoeuds; i++)
        printf("|%2d|",i);
    printf("\n");
    for(i=0; i <= nbnoeuds; i++)
        printf("|--|");
    for(i=1; i <= nbnoeuds; i++)
        {
    printf("\n");
        printf("|%2d|",i);
        for(j = 1; j <= nbnoeuds; j++)
            printf("|%2d|",tab[i][j]);
        printf("\n");
        for(k = 0; k <= nbnoeuds; k++)
            printf("|--|");
        }
    printf("\n");
    for(i = 0; i <= nbnoeuds; i++)
        printf("----");
    
    }
    


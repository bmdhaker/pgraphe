#include<stdio.h>
#include<stdlib.h>
void initier_dimensions_matrice(int nbnoeuds, int nbaretes);
void remplir_matrice(int tab[][10],int nbnoeuds, int nbaretes);
int choisir_operations();
int gerer_noeuds(int tab[][10],int nbnoeuds);
int calculer_degre(int tab[][10],int nbnoeuds);
int calculer_degre_noeuds(int tab[][10],int nbnoeuds, int noeud);
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
    int newchoix,newnbnoeuds=nbnoeuds;
    int choixx=10,newchoixx;
    printf("je suis dans choisir_operations");
    while(choixx!=0)
        {     
        printf("\nchoisir l'option que vous desirez"); 
        printf("\n0- Sortir et afficher la matrice"); 
        printf("\n100- Ajouter arete"); 
        printf("\n101- Modifier arete"); 
        printf("\n102- Supprimer arete"); 
        printf("\n103- Ajouter noeuds"); 
        printf("\n104- Supprimer noeuds"); 
        printf("\n105- Afficher degre du graphe"); 
        printf("\n106- Afficher degre d'un noeud"); 
        printf("\nEntrez votre choix :="); 
        scanf("%d", &newchoixx);
        printf("\nvotre choix est %d",newchoixx);
        choixx=newchoixx; 
        //printf("\nchoix est %d",choix);
        switch(choixx){
        case 100:        
            printf("\n---->Ajout Arête<----"); 
            printf("\n Entrez le noeud source: ");
            scanf("%d", &a);
            printf("Entrez le noeud destinataire: ");
            scanf("%d", &b);        
            printf("Entrez le poids de l'arete: ");
            scanf("%d", &tab[a][b]);
            break;  
        case 101:        
                printf("\n---->Modification Arête<----"); 
                printf("\n Entrez le noeud source: ");
                scanf("%d", &a);
                printf("Entrez le noeud destinataire: ");
                scanf("%d", &b);        
                printf("Entrez le poids de l'arete: ");
                scanf("%d", &tab[a][b]);
                break;        
        case 102:        
                printf("\n---->Suppression Arête<----"); 
                printf("\n Entrez le noeud source: ");
                scanf("%d", &a);
                printf("Entrez le noeud destinataire: ");
                scanf("%d", &b);        
                tab[a][b]=0;        
                break;        
        case 103:        
            printf("\n---->Ajout Noeuds<----"); 
            printf("\n Entrez le nombre des noeuds à ajouter: ");
            scanf("%d", &nb);
            newnbnoeuds+=nb;
            //nbnoeuds+=a;
            break;  
        case 104:        
                printf("\n---->Suppression Noeuds<----"); 
                printf("\n Entrez le noeud à supprimer: ");
                scanf("%d", &n);
                for(i=1;i<=nbnoeuds;i++)
                    {
                        tab[i][n]=0;
                        tab[n][i]=0;
                    }    
                break;        
        case 105:        
                printf("\n---->Degré Graphe<----"); 
                printf("\n le degré est: %d",calculer_degre(tab,nbnoeuds));
                break;        
        case 106:        
                printf("\n---->Degré d'un noeud<----"); 
                printf("\n Entrez le noeud: ");
                scanf("%d", &n);
                printf("\n le degré de %d est: %d",n,calculer_degre_noeuds(tab,nbnoeuds,n));
                break;        
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
int calculer_degre(int tab[][10],int nbnoeuds)
    {
    int i,j,degre=0;
    printf(" \n<=Affichage de degre=> \n");
    for(i=1; i <= nbnoeuds; i++)
        {
         for(j = 1; j <= nbnoeuds; j++)
            {
            if(tab[i][j]!=0)
                degre++;
            if(tab[j][i]!=0)
                degre++;
            }
        }
    return(degre);                 
    }
    
int calculer_degre_noeuds(int tab[][10],int nbnoeuds, int noeud)
    {
    int i,j,degre=0;
    for(i=1; i <= nbnoeuds; i++)
        {
            if(tab[i][noeud]!=0)
                degre++;
            if(tab[noeud][i]!=0)
                degre++;
        }
    return(degre);                 
    }
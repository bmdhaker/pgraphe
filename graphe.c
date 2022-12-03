#include <stdio.h>

void main()
{
  int matrice[10][10];
  int i, j, nbAretes,nbNoeuds,a,b;
  
  
  
   printf(" Entrez le nombre des noeuds (max 10): ");
   scanf("%d",&nbNoeuds);
   printf(" Entrez le nombre de aretes (max 10): ");
   scanf("%d",&nbAretes);
  printf(" Entrez les éléments de tableau : \n");
  
  for(i = 1; i <= 10; i++)
  {
    for(j = 1; j <= 10; j++)
    {
        matrice[i][j]=0;
    }
  }
  for(i=0;i<nbAretes;i++)
    {
    printf("Entrez le noeud source: ");
    scanf("%d", &a);
    printf("Entrez le noeud destinataire: ");
    scanf("%d", &b);        
    printf("Entrez le piods de l'arete: ");
    scanf("%d", &matrice[a][b]);        
    }
  printf(" Affichage de matrice = \n");
  for(i=1; i <= nbNoeuds; i++)
  {
    for(j = 1; j <= nbNoeuds; j++)
    {
      printf("%4d",matrice[i][j]);
    }
    printf("\n");
  }
}

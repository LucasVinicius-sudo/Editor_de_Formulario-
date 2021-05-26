#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  char palavra[200];
}necessario;

void mudar ()//Criou um novo Arquivo
{

  FILE *farq;
  char word[200];
  farq = fopen("newform.txt","w");
  for(int i = 0;i < 7;i++)
  {
    scanf("%s",word);
    fprintf(farq,"%s",word);
  }

  fclose(farq);
}
int mostrar(int i)//Printar o Arquivo txt
{


  FILE *fpointer;
  fpointer = fopen("formulario.txt","r");
  char singleline[200];


  while(!feof(fpointer))
  {
    fgets(singleline,70,fpointer);
    //printf("%s",singleline );
    //necessario

  }

  //printf("%d\n",i);
  fclose(fpointer);
  return(i);
}

void editar(int i )//Alocando o valor de cada linha num array de struct que tem uma instancia de String
{
  int n = mostrar(0);
  necessario func[n];
  FILE *fpointer;
  fpointer = fopen("formulario.txt","r");
  char singleline[200];


  while(!feof(fpointer))
  {
    fgets(singleline,70,fpointer);
    strcpy(func[i].palavra,singleline);
    //printf("%s\n",func[i].palavra);
    i = i + 1;
  }



  fclose(fpointer);
  return;
}

int main()
{

  editar(0);
  mudar();
   return 0;
   /*PASSAR ESSA FUNÇÃO PRO START.C E UTILIZAR ELA NUM SIGNAL_CONNECT*/
}

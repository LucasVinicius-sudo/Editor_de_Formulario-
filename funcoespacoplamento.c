#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  char palavra[200];
}necessario;

void mudar ()
{
  FILE *farq;
  farq = fopen("newform.txt","w");
}
int mostrar(int i)
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

void editar(int i )
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
    printf("%s\n",func[i].palavra);

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

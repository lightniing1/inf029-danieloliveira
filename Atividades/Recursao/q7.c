#include<stdio.h>

void reverte_array(int array[], int tamanho)
{
  if (tamanho > 1)
  {    

    int temp = array[0]; 
    array[0] = array[tamanho-1]; 
    array[tamanho-1] = temp;

    reverte_array(array+1, tamanho-2);

  }
}


int main(void) {

    int array[] = {5, 4, 3, 2, 1};
    int tamanho = sizeof(array)/sizeof(array[0]);
    
    for (int i = 0; i<tamanho; i++){
        printf("%d", array[i]);
    }

    printf("\n");

    reverte_array(array, tamanho);

    for (int i = 0; i<tamanho; i++){
        printf("%d", array[i]);
    }

    printf("\n");

    return 0;
}
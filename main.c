#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

int initArray(char Array[], int Length)
{
   int i;

   for (i = 0; i < Length-1; i++) 
     {
      printf("%i",i);
      Array[i] = ' ';
     }
   Array[Length - 1] = ' ';
}

void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
void bubbleSort(char arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);

}
  
int isUpperLower(char c){
    if (c >= 'A' && c<= 'Z')
        return 1;
    else if (c >= 'a' && c<= 'z')
        return 0;
    else
        return -1;
}

int balanceCheck(char *str){
    int i;
    int j;
    char strUpper[200];
    initArray(strUpper, strlen(strUpper));
    int upperIdx = 0;
    char strLower[200];
    initArray(strLower, strlen(strLower));

    int lowerIdx = 0;
    int diffBuf;
    int isUnique;
    for (i=0; i<strlen(str); i++){  //ilk seçim
        //str[i];
        isUnique=0;
        if(isUpperLower(str[i])==1){
          isUnique=1;

          for (j=i; j<strlen(str); j++){
            if (j != i){
              if(str[i]==str[j]){
                isUnique=0;
                break;
              }
            }
          }

          if((isUnique==1) && (j!= i)) {
            //printf("Lower'a ekle: %c\n", str[i]); //str[i] yi strLower a at
            strUpper[upperIdx]=str[i];
            upperIdx++;
            
          }
      
        }
        else if(isUpperLower(str[i])==0){
          isUnique=1;

          for (j=i; j<strlen(str); j++){
            if (j != i){
              if(str[i]==str[j]){
                isUnique=0;
                break;
              }
            }
          }

          if(isUnique==1 && (j!= i)) {
            //printf("Lower'a ekle: %c\n", str[i]); //str[i] yi strLower a at
            strLower[lowerIdx]=str[i];
            lowerIdx++;
            
          }
      
        }
      }
    
    strUpper[upperIdx] = '\0';
    strLower[lowerIdx] = '\0';

    bubbleSort(strUpper, strlen(strUpper));
    bubbleSort(strLower, strlen(strLower));

    printf("Upper letters: %s \n", strUpper);
    printf("Lower letters: %s \n", strLower);

    int isBalanced = 1;

    //printf("STRING LENGTHS: UPPER %d - LOWER %d\n", strlen(strUpper), strlen(strLower));
    if (strlen(strUpper) != strlen(strLower))
      isBalanced = 0;
    else {
      int i;
      for(i=0;i<strlen(strUpper);i++){
        if(strLower[i]-strUpper[i]!=32){
          isBalanced = 0;
          break;
        }
      }
    //isBalanced = 1;
    }

    if(isBalanced){
      printf("++++ BALANCED ++++ %s\n", str);
      return 1;
    }
    else {
      printf("---- NOT BALANCED ---- %s\n", str);
      return 0;
  }

    //printf("Size of upper letters: %d\n", strlen(strUpper));
    //printf("Size of lower letters: %d\n", strlen(strLower));
}



int main(int argc, char **argv)
{

    char *str = "BabcACD";

    printf("string: %s\n", str);

    int i,j,k;
    
    
    for (i=2; i<strlen(str)+1; i++){
        j = 0;
        char substr [i];
        for (j=0; j<strlen(str)-i+1; j++){
            memcpy(substr, &str[j], sizeof(substr));
            //for(k=0;k<sizeof(substr);k++)
            balanceCheck(substr);
            
            //printf("Substring: %s\n", substr);
            
        }
    }

    ////printf("Is Upper: %d\n", isUL);
    //balanceCheck("AAaaBbdgdmfh");
return 0;
}
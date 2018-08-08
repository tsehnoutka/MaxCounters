#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct test{
    int N;  // number of iterators
    int M;  // Size of array
    int* A; // array of operations
    int* r; // expected result
};

#define  NumofTest 2
struct test myTest[NumofTest];
void setUpTest()
{
    myTest[0].N=4;
    int tempA2[]={3, 5, 5, 1, 5};
    myTest[0].A= tempA2;
    myTest[0].M= 5;
    int tempr2[]={2,2,2,2};
    myTest[0].r= tempr2;
    
    myTest[1].N=5;
    int tempA1[]={3,4,4,6,1,4,4};
    myTest[1].A=tempA1; 
    myTest[1].M= 7;
    int tempr1[]={3, 2, 2, 4, 2};
    myTest[1].r= tempr1;
    
    
}
struct Results {
  int * C;
  int L; // Length of the array
};
struct Results myResults;

void printArray(int arr[], int n)
{
    int i=0;
    printf("(");
    for (i=0; i<n-1; i++)
      printf("%d, ", arr[i]);
    printf("%d)\n",arr[i] );
}

struct Results solution(int N, int A[], int M)
{
    int i=0,j=0;
    int max=0;
    int arraySize=sizeof (int) *N;

    for (i=0; i<M; i++){
        if (A[i] == N+1){
            for (j=0; j<N; j++){
                myResults.C[j]=max;
            }
            //printf("inLoop(%d) - ",max);
            //printArray(myResults.C,myResults.L);       
        }
        else{
            (myResults.C[A[i]-1])+=1;
            int temp = myResults.C[A[i]-1];
            //printf("temp - %d\n",temp);
            if (temp > max ){
                max = temp;
            }
            //printf("inLoop(%d) - ",max);
            //printArray(myResults.C,myResults.L);       
        }
    }
    return myResults;
}
int compareResults(struct test T){
    int same=1;  // boolean: 0-false;  1-true
/*    
    printf("Compare Results test array - ");
    printArray(T.r,T.N); 
    printf("Compare Results Results array - ");
    printArray(myResults.C,myResults.L);     
*/    
    if (myResults.L != T.N){
        return !same;
    }
    int j =T.N-1;
    while ((j>=0)&& same){
        if (myResults.C[j] != T.r[j]){
            same=0;
        }
        j--;
    }
    return same;
}

int main(int argc, char** argv) 
{
    int i=0;
    int arraySize=0;  
    
    setUpTest();
    
    for (i=0; i< NumofTest; i++){
        printf("Running test - %d\n", i);
        arraySize=sizeof(int) * myTest[i].N;
    
        myResults.C = malloc(arraySize);
        memset(myResults.C,0,arraySize);
        myResults.L=myTest[i].N;  
        
        myResults = solution(myTest[i].N,myTest[i].A,myTest[i].M);
         
        if (compareResults(myTest[i])){
            printf("PASS : ");
            printArray(myTest[i].r, myTest[i].N);
        }
        else{
            printf("FAIL\n");
        }
        free (myResults.C);
        printf("\n");
    }
    return 0;
}

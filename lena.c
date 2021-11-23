#include<stdio.h>
#include<locale.h>

int random_massive ()
    {
    int N;
    int k=0;
    float average;
    int *px;
    int raz =0;
    int sum;
    printf("Enter N: ");
    scanf("%d", &N);
    int mas[N][N];

        for (int i = 0; i<N; i++)
        {
            for (int j = 0; j<N; j++)
                {
                    mas[i][j] = rand() % 50 - 30;
                }
        }
        for (int i = 0; i<N; i++)
            {
                    for (int j = 0; j<N; j++)
                {
                      printf("%5d",mas[i][j]);  
                }
                    printf("\n");  
            }


//get average
    for (int i =0;i<N;i++)
    {   
        for (int j =0;j<N;j++)
        {
            if ( mas[i][j] > 0 )
                {
                       px=&mas[i][j];
                       raz++;
                       sum=*px;
                       k = sum +k;
                        
                }
        }
    }
    printf(" Sum: %d",k);
    average = (k/raz);
    printf("\n");
    printf(" Average: %f",average);

    for (int i = 0; i<N; i++)
    {
            mas[i][N-2]=average; 
             
    }
printf("\n"); 
printf("END:\n");
for (int i = 0; i<N; i++)
    {
            for (int j = 0; j<N; j++)
        {
              printf("%5d",mas[i][j]);  
        }
            printf("\n");  
    }





    }

  void first()
    {
    int N;
    int k=0;
    float average;
    int *px;
    int raz =0;
    int sum;
    printf("Enter N: ");
    scanf("%d", &N);
    int mas[N][N];
   
    
    for (int i = 0; i<N; i++)
        {
            for (int j = 0; j<N; j++)
                {
              printf("mas[%d][%d] = ", i, j);
              scanf("%d", &mas[i][j] );
                }
        }

  for (int i = 0; i<N; i++)
    {
            for (int j = 0; j<N; j++)
        {
              printf("%5d",mas[i][j]);  
        }
            printf("\n");  
    }
//get average
    for (int i =0;i<N;i++)
    {   
        for (int j =0;j<N;j++)
        {
            if ( mas[i][j] > 0 )
                {
                       px=&mas[i][j];
                       raz++;
                       sum=*px;
                       k = sum +k;
                        
                }
        }
    }
    printf(" Sum: %d",k);
    average = (k/raz);
    printf("\n");
    printf(" Average: %f",average);

    for (int i = 0; i<N; i++)
    {
            mas[i][N-2]=average; 
             
    }
printf("\n"); 
printf("END:\n");
for (int i = 0; i<N; i++)
    {
            for (int j = 0; j<N; j++)
        {
              printf("%5d",mas[i][j]);  
        }
            printf("\n");  
    }
}

  int main()
 {
    
    int a;
    printf("1 -- Random mass\n");
    printf("2 -- User`s mass\n");
    printf("Choice:");
   
    scanf("%d", &a);

    switch (a)
    {
        case 1 : random_massive(); break;
        case 2 : first(); break;
        
    }
    return 0;
  }
  


#include <stdio.h>

#define N 5

void first_exercise();
void second_exercise();
void third_exercise();
void fourth_exercise();

void print_array(int array[N]);
void print_matrix(int matrix[N][N]);

void first_exercise(){
    int matrix[N][N];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matrix[i][j]=(i)*N+j+1;
        }
    }
    print_matrix(matrix);
}

void second_exercise(){
    int array[N];
    int bucket;
    
    for(int i=0;i<N;i++){
        array[i]=i+1;
    }

    for(int i=0;i<(N/2);i++){
        bucket=array[i];
        array[i]=array[N-i-1];
        array[N-i-1]=bucket;
    }
    print_array(array);
}

void third_exercise(){
    int matrix[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matrix[i][j]=0;
        }    
    }
    
    for(int i=0;i<N;i++){
        for(int j=i;j>=0;j--){
            matrix[i][N-j-1]=1;
        }    
    }
    print_matrix(matrix);
}

void fourth_exercise(){
    int matrix[N][N];
    int side_size=N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matrix[i][j]=0;
        }    
    }

    matrix[0][0]=1;
    int h_move=1;
    int v_move=0;
    int counter=2;
    int i=0;
    int j=0;
    while(counter<=(N*N)){
        if((i+v_move)<N && (i+v_move)>=0 &&
        (j+h_move)<N && (j+h_move)>=0){
            if(matrix[i+v_move][j+h_move]==0){
                matrix[i+v_move][j+h_move]=counter;
                counter++;
                i+=v_move;
                j+=h_move;
                
            }
            else{
                switch(h_move){
                    case 1:
                        h_move=0;
                        v_move=1;
                        continue;
                    break;
                    case -1:
                        h_move=0;
                        v_move=-1;
                        continue;
                    break;
                }
                switch(v_move){
                    case 1:
                        h_move=-1;
                        v_move=0;
                        continue;
                    break;
                    case -1:
                        h_move=1;
                        v_move=0;
                        continue;
                    break;
                }   
            }
        }
        else{
            if(j+h_move==N){
                h_move=0;
                v_move=1;
                continue;
            }
            if(j+h_move==-1){
                h_move=0;
                v_move=-1;
                continue;
            }
            if(i+v_move==N){
                h_move=-1;
                v_move=0;
                continue;
            }
            if(i+v_move==0){
                h_move=+1;
                v_move=0;
                continue;
            }
         }
    }
    print_matrix(matrix);
}

void print_array(int array[N]){
    for(int i=0;i<N;i++){
        printf("%d ",array[i]);
    }
    printf("\n\n");
}

void print_matrix(int matrix[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%4.1d",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    printf("First:\n");
    first_exercise();
    printf("Second:\n");
    second_exercise();
    printf("Third:\n");
    third_exercise();
    printf("Fourth:\n");
    fourth_exercise();
}
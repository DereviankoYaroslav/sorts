#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void shell_sort(int arr[], int size) {
    int s, i, j, k;
    s = size;
    for (k = 0; k < size, s>1; k++) {
        s = size / pow(2, (k + 1));
        printf("%d ", s);
        for (i = 0; i < size; i++) {
            for (j = i + s; j < size; j += s) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void frank_lazarus_sort(int arr[], int size) {
    int s, i, j, k;
    s = size;
    for (k = 0; k < size, s>1; k++) {
        s = (2*floor((size / pow(2, (k + 2))))+1);
        printf("%d ", s);
        for (i = 0; i < size; i++) {
            for (j = i + s; j < size; j += s) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void papernov_sort(int arr[], int size) {
    int s, i, j, k;
    for (k = 0; k < size, s<size; k++) {
        s = (pow(2, (k)))+1;
        if (s == 2){
            s = 1;
        }
        printf("%d ", s);
        for (i = 0; i < size; i++) {
            for (j = i + s; j < size; j += s) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void knuth_sort(int arr[], int size) {
    int s, i, j, k;
    for (k = 0; k < size, s<size/3; k++) {
        s = ((pow(3, k+1))-1)/2;
        printf("%d ", s);
        for (i = 0; i < size; i++) {
            for (j = i + s; j < size; j += s) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void sedgewick_sort(int arr[], int size) {
    int s, i, j, k;
    for (k = 0; k < size, s<size; k++) {
        s = (pow(4,k))+(3*pow(2, k-1))+1;
        if (k == 0){
            s = 1;
        }
        printf("%d ", s);
        for (i = 0; i < size; i++) {
            for (j = i + s; j < size; j += s) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void sedgewick_1986_sort(int arr[], int size) {
    int s, i, j, k;
    for (k = 0; k < size, s<size; k++) {
        if (k%2==0) {
            s = (9*(pow(2,k)-pow(2,(k/2))))+1;
        }
        else {
            s = (8*pow(2,k)-6*pow(2,((k+1)/2)))+1;
        }
        printf("%d ", s);
        for (i = 0; i < size; i++) {
            for (j = i + s; j < size; j += s) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void tokuda_sort(int arr[], int size) {
    int s, i, j, k;
    for (k = 1; k < size, s<size; k++) {
        s = ceil(pow(9,k)-pow(4,k))/(5*pow(4,k-1))+1;
        if (k == 1){
            s =1;
        }
        printf("%d ", s);
        for (i = 0; i < size; i++) {
            for (j = i + s; j < size; j += s) {
                if (arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}


void ciura_sort(int arr[], int size){
    int s, i, j, iGap;
    int arGap[9] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    for(s = arGap[0],iGap = 0; iGap<9; s = arGap[iGap++]){
        printf("%d ",iGap);
        for(i=0; i<size; i++){
            for( j=i+s; j<size; j+=s){
                if(arr[i] > arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

void read_file_shell(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test1.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    shell_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}

void read_file_lazarus(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test4.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    frank_lazarus_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}


void read_file_papernov(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test5.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    papernov_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}

void read_file_knuth(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test6.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    knuth_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}

void read_file_tokuda(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test9.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    tokuda_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}

void read_file_sedgewick1986(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test8.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    sedgewick_1986_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}

void read_file_ciura(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test2.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    ciura_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent for ciura: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}
void add_file(int size,int choice){
    FILE* fp ;
    srand(time(NULL));
    char* name = "test.txt";
    fp = fopen(name,"w+");
    if(!fp){
        printf("Error open file!!");
    }
    else if(choice == 1){
        int i;
        for( i = 0;i<size;i++){
            int x = rand() % 1000 + 1;
            fprintf(fp,"%d ",x);
        }
        fclose(fp);
    }
    else if(choice == 2){
        int i;
        for( i = 0;i < size;i++){
            int x = rand() % 1000 + 1;
            fprintf(fp,"%d ",x);
        }
        int arr[size];
        i = 0;
        fclose(fp);
        fp = fopen(name,"r");
        while(fscanf(fp,"%d",&(arr[i])) != EOF){
            i++;
        }
        int j;
        for( i = 0;i<size-1;i++){
            for( j = 0;j<size-i-1;j++){
                int tmp = 0;
                if(arr[j] > arr[j+1]){
                    tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
        fclose(fp);
        fp = fopen(name,"w+");
        for( i = 0;i<size;i++){
            fprintf(fp,"%d ",arr[i]);
        }
        fclose(fp);
    }
    else if(choice == 3){
        int i;
        for( i = 0;i < size;i++){
            int x = rand() % 1000 + 1;
            fprintf(fp,"%d ",x);
        }
        int arr[size];
        i = 0;
        fclose(fp);
        fp = fopen(name,"r");
        while(fscanf(fp,"%d",&(arr[i])) != EOF){
            i++;
        }
        int j;
        for( i = 0;i<size-1;i++){
            for(j = 0;j<size-i-1;j++){
                int tmp = 0;
                if(arr[j] < arr[j+1]){
                    tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
        fclose(fp);
        fp = fopen(name,"w+");;
        for( i = 0;i<size;i++){
            fprintf(fp,"%d ",arr[i]);
        }
        fclose(fp);
    }
    else{
        printf("choice false");
    }
}

void read_file_sedgewick(char name[]){
    FILE *fp,*fl;
    char* fl_name = "test7.txt";
    int size = 1;
    int* arr =(int*)malloc(size * sizeof(int*));
    fp = fopen(name,"r");
    if(!fp){
        printf("Error open file!!");
    }
    int i = 0;
    while(fscanf(fp,"%d",&(arr[i])) != EOF){
        size++;
        arr = (int*)realloc(arr,size*sizeof(int));
        i++;
    }
    fclose(fp);

    // sort
    double time_spent = 0;
    clock_t begin = clock();
    sedgewick_sort(arr, size-1);
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent: %lf ",time_spent);
    // end sort

    fl = fopen(fl_name,"w+");
    if(!fl){
        printf("Error open file!!");
    }
    for(i = 0; i < size-1; i++){
        fprintf(fl,"%d ",arr[i]);
    }
    fclose(fl);
}

// Driver code
int main() {
    int size = 0;
    int choice = 0;
    printf("Enter size File: ");
    scanf("%d",&size);
    printf("1.File random numbers\n");
    printf("2.File sorted\n");
    printf("3.File reverse sorted\n");
    printf("Enter choice variant: ");
    scanf("%d",&choice);
    add_file(size,choice);
    //read_file_shell("test.txt");
    read_file_tokuda("test.txt");
    //read_file_ciura("test.txt");
    //read_file_Sedgewick_6("test.txt");
}
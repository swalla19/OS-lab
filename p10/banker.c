#include<stdio.h>
int main(){
    int a;
    printf("Enter Available ");
    scanf("%d",&a);
    
    int n;
    printf("Enter number of processes");
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter allocation of p %d",i);
        scanf("%d",&arr[i]);
    }
    
    int max[n];
    for(int i=0;i<n;i++){
        printf("Enter max of p %d",i);
        scanf("%d",&max[i]);
    }
    
    int need[n];
    for(int i=0;i<n;i++){
        need[i]=max[i]-arr[i];
    }
    
    int safe[n];
    int available = a;
    int completed[n];
    for(int i=0;i<n;i++){
        completed[i] = 0;
    }
    
    int count = 0;
    while(count < n){
        int found = 0;
        for(int i=0;i<n;i++){
            if(completed[i] == 0 && need[i] <= available){
                safe[count] = i;
                count++;
                available = available + arr[i];
                completed[i] = 1;
                found = 1;
            }
        }
        if(found == 0){
            printf("\nSystem is not in safe state - Deadlock!\n");
            return 0;
        }
    }
    
    printf("\nSystem is in safe state\n");
    printf("Safe Sequence: ");
    for(int i=0;i<n;i++){
        printf("P%d ", safe[i]);
        if(i < n-1)
            printf("-> ");
    }
    printf("\n");
    
    return 0;
}

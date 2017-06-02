#include <stdio.h>
typedef struct Process{
  int in;
  int at;
  int wt;
  int bt;
  int tat
}process;

int main(){
  int i=0,n,time=0,j=0;
  printf("Enter no. of processes\n");
  scanf("%d",&n);
  process p[n],t;
  int rem=n;
  for(i=0;i<n;i++){
    printf("Enter burst time and arrival time");
    scanf("%d %d",&p[i].bt,&p[i].at);
    p[i].in=i;
  }
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      if(p[j].bt > p[j+1].bt){
      t=p[j];
      p[j]=p[j+1];
      p[j+1]=p[j];  }
    }
  }

}

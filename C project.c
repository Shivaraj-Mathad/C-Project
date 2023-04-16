#include<stdio.h>
#include<math.h>
#define max_n 100
int tower[max_n][3];
int distance(int x1,int y1,int x2,int y2){
    return (int)sqrt(((x1-x2)*(x1-x2))+((y1-y2)(y1-y2)));
}
int signal_quality(int x1,int y1,int x2,int y2,int q){
    int d=distance(x1,y1,x2,y2);
    return q/(1+d);
}
int network_quality(int x,int y,int n,int rad){
    int quality=0;
    for(int i=0;i<n;i++){
        int d=distance(x,y,tower[i][0],tower[i][1]);
        if(d<=rad){
            quality+=signal_quality(x,y,tower[i][0],tower[i][1],tower[i][2]);

        }
    }
    return quality;

}

int main(){
    int n,rad;
    scanf("%d%d",&n,&rad);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&tower[i][0],&tower[i][1],&tower[i][2]);
    }
        int max_quality=-1;
        int cx=-1;
        int cy=-1;
        for(int x=0;x<100;x++){
            for(int y=0;y<100;y++){
                int quality=network_quality(x,y,n,rad);
                if(quality>max_quality){
                    max_quality=quality;
                    cx=x;
                    cy=y;
                }
                elseif(quality==max_quality){
                    if(x<cx||(x==cx&&y<cy)){
                        cx=x;
                        cy=y;
                    }
                }
            }
        }
    printf("%d%d\n",cx,cy);
    return 0;
}

#include<iostream>
using namespace std;
#include<cmath>
#include<time.h>
#include<cstdlib>

bool legal(bool k,int A[8][8],int px,int py){
    bool leg=0;
    if(px<1||px>8||py<1||py>8){
        return 0;
    }
    if(A[px-1][py-1]!=-1){
        return 0;
    }
    if(!(py==1)){
    if(A[px-1][py-2]==(int(!k))){
        for(int j=3;py-j+1>0;j++){                       //UP
            if(A[px-1][py-j]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(!(py==8)){
    if(A[px-1][py-1+1]==(int(!k))){                   //DOWN
        for(int j=1;py+j+1<=8;j++){
            if(A[px-1][py+j]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(px!=1){                                         //LEFT
    if(A[px-2][py-1]==(int(!k))){
        for(int j=3;px-j+1>0;j++){
            if(A[px-j][py-1]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(px!=8){                                       //RIGHT
    if(A[px-1+1][py-1]==(int(!k))){
        for(int j=1;px+j+1<=8;j++){
            if(A[px+j][py-1]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(!((px==1)||(py==8))){                        //NW
    if(A[px-1-1][py-1-1]==(int(!k))){
        for(int j=3;px-j+1>0&&py-j+1>0;j++){
            if(A[px-j][py-j]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(!((px==8)||(py==1))){                         //NE
    if(A[px-1+1][py-1-1]==(int(!k))){
        for(int j=1;px+j+1<=8&&py+j-1>0;j++){
            if(A[px-1+1+j][py-1-1-j]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(!((px==8)||(py==8))){                          //SE
    if(A[px-1+1][py-1+1]==(int(!k))){
        for(int j=1;px+j+1<=8&&py+j+1<=8;j++){
            if(A[px-1+1+j][py-1+1+j]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(!((px==1)||(py==1))){                             //SW
    if(A[px-1-1][py-1+1]==(int(!k))){
        for(int j=1;px-j-1>0&&py+j+1<=8;j++){
            if(A[px-1-1-j][py-1+1+j]==(int)(k)){
                leg=1;break;
            }
        }
    }
    }
    if(leg){
        return 1;
    }
    return 0;


}


void flipcoin(bool k,int A[8][8],int px,int py,int &CB1,int &CW0,int &inc){

    int leg[8]={0,0,0,0,0,0,0,0};
    A[px-1][py-1]=int(k);
    if(k){
        CB1++;inc++;
    }
    else if(!k){
        CW0++;inc++;
    }
    if(A[px-1][py-2]==((int)(!k))){                             //UP
        for(int j=3;py-j+1>0;j++){
            if(A[px-1][py-j]==(int)(k)){
                leg[0]=1;break;
            }
        }
        if(leg[0]==1){
            for(int P=1;py-1-P>=0;P++){
                if(A[px-1][py-1-P]==((int)(!k))){
                    A[px-1][py-1-P]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
                else{break;}
            }
        }
    }
    if(A[px-1][py-1+1]==((int)(!k))){                          //DOWN
        for(int j=1;py+j+1<=8;j++){
            if(A[px-1][py+j]==int(k)){
                leg[1]=1;break;
            }
        }
        if(leg[1]==1){
            for(int P=1;py-1+P<8;P++){
                if(A[px-1][py-1+P]==int((!k))){
                    A[px-1][py-1+P]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
                else{break;}
            }
        }
    }
    if(A[px-2][py-1]==((int)(!k))){                            //LEFT
        for(int j=3;px-j+1>0;j++){
            if(A[px-j][py-1]==(int)(k)){
                leg[2]=1;break;
            }
        }
        if(leg[2]==1){
            for(int P=1;px-1-P>=0;P++){
                if(A[px-1-P][py-1]==int((!k))){
                    A[px-1-P][py-1]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
                else{break;}
            }
        }
    }
    if(A[px-1+1][py-1]==((int)(!k))){                           //RIGHT
        for(int j=1;px+j+1<=8;j++){
            if(A[px+j][py-1]==(int)(k)){
                leg[3]=1;break;
            }
        }
        if(leg[3]==1){
            for(int P=1;px-1+P<8;P++){
                if(A[px-1+P][py-1]==int((!k))){
                    A[px-1+P][py-1]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
                else{break;}
            }
        }
    }
    if(A[px-1-1][py-1-1]==(int)(!k)){                        //NW
        for(int j=3;px-j+1>0&&py-j+1>0;j++){
            if(A[px-j][py-j]==(int)(k)){
                leg[4]=1;break;
            }
        }
        if(leg[4]==1){
            for(int P=1;((px-1-P>=0)&&(py-1-P>=0));P++){
                if(A[px-1-P][py-1-P]==int((!k))){
                    A[px-1-P][py-1-P]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
            }
        }
    }
    if(A[px-1+1][py-1-1]==(int)(!k)){                      //NE
        for(int j=1;px+j+1<8&&py-j-1>0;j++){
            if(A[px-1+1+j][py-1-1-j]==(int)(k)){
                leg[5]=1;break;
            }
        }
        if(leg[5]==1){
            for(int P=1;((px-1+P<8)&&(py-1-P>=0));P++){
                if(A[px-1+P][py-1-P]==int((!k))){
                    A[px-1+P][py-1-P]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
                else{break;}

            }
        }
    }
    if(A[px-1+1][py-1+1]==(int)(!k)){                       //SE
        for(int j=1;px+j+1<=8&&py+j+1<=8;j++){
            if(A[px-1+1+j][py-1+1+j]==(int)(k)){
                leg[6]=1;break;
            }
        }
        if(leg[6]==1){
            for(int P=1;px-1+P<8&&py-1+P<8;P++){
                if(A[px-1+P][py-1+P]==int((!k))){
                    A[px-1+P][py-1+P]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
                else{break;}
            }
        }
    }
    if(A[px-1-1][py-1+1]==(int)(!k)){                          //SW
        for(int j=1;px-j-1>0&&py+j+1<=8;j++){
            if(A[px-1-1-j][py-1+1+j]==(int)(k)){
                leg[7]=1;break;
            }
        }
        if(leg[7]==1){
            for(int P=1;px-1-P>=0&&py-1+P<8;P++){
                if(A[px-1-P][py-1+P]==int((!k))){
                    A[px-1-P][py-1+P]=int(k);
                    inc++;
                    if(k){
                        CB1++;CW0--;
                    }
                    else if(!k){
                        CW0++;CB1--;
                    }
                }
                else{break;}
            }
        }
    }

}


int Numminus1(int A[8][8]){
    int c=0;
    for(int j=0;j<8;j++){
        for(int k=0;k<8;k++){
            if(A[k][j]==-1){
                c++;
            }
        }
    }
    return c;
}

bool availlegal(bool u,int A[8][8]){
    for(int j=0;j<8;j++){
        for(int k=0;k<8;k++){
            if(legal(u,A,k,j)){
                return 1;
            }
        }
    }
    return 0;
}



void print(int arr [8][8]) {
    cout << endl;
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "+--------";
        } cout << "+" << endl;
        // At the top of EACH line, we do what? print + ----- to form a grid.
        for (int j = 0; j < 8; j++) {
            cout << "|";
            switch (arr [j] [i]) {
                case 0: cout << " /^^^^\\ "; break;
                case 1: cout << " /@@@@\\ "; break;
                default: cout << "        "; break;
            } // Same notation. 1 means black square. Filled across three lines. -1 means white square (or blank). ALso filled across three squares. 0 means empty space.
        } cout << "|" << endl;
        for (int j = 0; j < 8; j++) {
            cout << "|";
            switch (arr [j] [i]) {
                case 0: cout << " [    ] "; break;
                case 1: cout << " @@@@@@ "; break;
                default: cout << "        "; break;
            }
        } cout << "|" << endl;
        for (int j = 0; j < 8; j++) {
            cout << "|";
            switch (arr [j] [i]) {
                case 0: cout << " \\____/ "; break;
                case 1: cout << " \\@@@@/ "; break;
                default: cout << "        "; break;
            }
        } cout << "|" << endl; // At the end of each block, each line, there is a vertical hyphen that forms the grid.
    } for (int j = 0; j < 8; j++) {
        cout << "+--------";
    } cout << "+" << endl; // The bottom line.
} // NOTE: This program does not cout the square numbers. You are expected to know that (x, y) means x right and y top from the left corner which is (1, 1). Like first quadrant.
// Also note the order in which we printed. Top row inside memory would be x = 1 or i = 0. But here x is left column. So we traverse arr[j][i] instead. For i too, i = 0 on bottom so reverse order.

// OK. We know that for white or black the given move is legal. We know how many squares to flip on each side as well and that they are of opposite color. We flip it.


int f(bool k,int A[8][8],int &cx,int &cy,int N){
    srand(time(0));
    if(N==3){
        return 0;
    }
    int M[8][8];
    for(int G=0;G<8;G++){
        for(int H=0;H<8;H++){
            M[H][G]=0;
        }
    }
    for(int i=1;i<=8;i++){                        // x coord-j-1, y coord-i-1;
        for(int j=1;j<=8;j++){
            if(legal(k,A,j,i)){
                int B[8][8];
                for(int e=0;e<8;e++){
                    for(int f=0;f<8;f++){
                        B[f][e]=A[f][e];
                    }
                }
                int p=50,q=50;
                flipcoin(k,B,j-1,i-1,p,q,M[j-1][i-1]);

                M[j-1][i-1]=M[j-1][i-1]-f((!k),B,p,q,N+1);

            }
            else{
                M[j-1][i-1]=-10;
            }
        }
    }
    int maxpos[2]={1,1};
    for(int P=1;P<=8;P++){
        for(int Q=1;Q<=8;Q++){
            if(M[Q-1][P-1]>=M[(maxpos[0])-1][(maxpos[1])-1]){
                maxpos[0]=Q;maxpos[1]=P;
            }
            /*else if(M[Q-1][P-1]==M[(maxpos[0])-1][(maxpos[1])-1]){
                int r=((rand()%2)+1);
                if(r==2){
                    maxpos[0]=Q;maxpos[1]=P;
                }
            }*/
        }
    }
    cx=maxpos[0];cy=maxpos[1];
    return M[cx-1][cy-1];
}

void results(int CW0,int CB1,bool k){


        cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
        cout<<"   OOOO  OOOOO O   O OOOO O     O      OOOO   O                            "<<endl;
        cout<<"  O    O   O   O   O O    O     O     O    O  O                            "<<endl;
        cout<<"  O    O   O   OOOOO OOOO O     O     O    O  O                            "<<endl;
        cout<<"  O    O   O   O   O O    O     O     O    O  O                            "<<endl;
        cout<<"   OOOO    O   O   O OOOO OOOOO OOOOO  OOOO   #                            "<<endl;
        cout<<"                                                                           "<<endl;
        /*cout<<"  O   O   OOO  O   O    O       O       O  O  O   O  O                                  "<<endl;
        cout<<"     O O   O   O O   O     O     O O     O   O  OO  O  O                                 "<<endl;
        cout<<"      O    O   O O   O      O   O   O   O    O  O O O  O                               "<<endl;
        cout<<"      O    O   O O   O       O O     O O     O  O  OO  O                                "<<endl;
        cout<<"      O     OOO   OOO         O       O      O  O   O  #                              "<<endl;*/
        cout<<"     "<<endl;
        cout<<"     "<<endl;
        if((k&&(CB1>CW0))||(!k&&(CB1<CW0))){
        cout<<"       YOU WIN!!!"<<endl<<endl<<endl<<endl;
        }
        else if(!((k&&(CB1>CW0))||(!k&&(CB1<CW0)))){
        cout<<"       YOU LOSE! "<<endl<<endl<<endl<<endl;
        }
        else if(CB1==CW0){
        cout<<"       IT IS A DRAW! "<<endl<<endl<<endl<<endl;
        }
        cout<<"       Play or Continue- press 1"<<endl;
        cout<<"       Exit- press 0"<<endl<<endl;
        cout<<"___________________________________________________________________________________________________________"<<endl<<endl;

}

int main(){
    srand(time(0));
    int A[8][8];
    for(int j=0;j<8;j++){
        for(int k=0;k<8;k++){
            A[k][j]=-1;
        }
    }

    A[3][3]=0;
    A[3][4]=1;
    A[4][3]=1;
    A[4][4]=0;

    while(true){
        cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
        cout<<"   OOOO  OOOOO O   O OOOO O     O      OOOO   O                            "<<endl;
        cout<<"  O    O   O   O   O O    O     O     O    O  O                            "<<endl;
        cout<<"  O    O   O   OOOOO OOOO O     O     O    O  O                            "<<endl;
        cout<<"  O    O   O   O   O O    O     O     O    O  O                            "<<endl;
        cout<<"   OOOO    O   O   O OOOO OOOOO OOOOO  OOOO   #                            "<<endl;
        cout<<"                                                                           "<<endl;
        cout<<"       OTHELLO! "<<endl<<endl;
        cout<<"       Play or Continue- press 1"<<endl;
        cout<<"       Exit- press 0"<<endl<<endl;
        cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
        int a=-1;
        cin>>a;
        if(a==1){
            while(true){
                cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                cout<<"Black plays first!"<<endl<<endl;
                cout<<" '1' is for black       '0' is for white                                                                   "<<endl<<endl;
                cout<<"  Press 2 for main screen and 3 for Exit"<<endl<<endl<<endl;
                print(A);
                cout<<endl<<endl<<endl;
                cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                int a1=-1;
                cin>>a1;
                if(a1==1){
                    int CW0=2,CB1=2;
                    while(true){
                        if(Numminus1(A)==0||((availlegal(0,A))==0&&(availlegal(1,A)==0))){
                            cout<<endl<<endl<<"GAME OVER!"<<endl<<endl<<endl;
                            break;
                        }
                        while(true){
                            cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                            cout<<"PLAY YOUR MOVE!(place your color coin on x, y coordinates)"<<endl<<endl;
                            cout<<"Enter space separated integers x, y starting 1 to 8:                                                                    "<<endl<<endl;
                            cout<<"  Press '9 0' for Exit"<<endl<<endl<<endl;
                            print(A);
                            cout<<endl<<endl<<endl;
                            cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                            if(availlegal(1,A)==0){
                                cout<<"SORRY!, NO MOVES AVAILABLE FOR YOU!(computer plays again)"<<endl<<endl;
                                break;
                            }
                            int px,py;cin>>px>>py;
                            if(px==9&&py==0){
                                return 0;
                            }

                            else if(legal(1,A,px,py)){
                                int inc2=0;
                                flipcoin(1,A,px,py,CB1,CW0,inc2);
                                cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                                cout<<"NICE MOVE!"<<endl<<endl;
                                cout<<"SCORES: PLAYER- "<<CB1<<" COMPUTER- "<<CW0<<"                                                              "<<endl<<endl;
                                cout<<"  Press 11 to let the computer play and 12 to Exit"<<endl<<endl<<endl;
                                print(A);
                                cout<<endl<<endl<<endl;
                                cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                                int Y=0;
                                while(true){
                                    int e;cin>>e;
                                    if(e==11){
                                        Y=1;
                                        break;
                                    }
                                    else if(e==12){
                                        return 0;
                                    }
                                    else{
                                    cout<<"INVALID INPUT!"<<endl<<endl;
                                    continue;}
                                }
                                if(Y==1){
                                    break;
                                }
                            }
                            else if((!legal(1,A,px,py))&&(px!=9)&&(py!=0)){
                                cout<<"INVALID INPUT!"<<endl<<endl;
                                continue;
                            }
                        }


                        if(Numminus1(A)==0||(availlegal(1,A)==0&&(availlegal(0,A)==0))){
                            cout<<endl<<endl<<"GAME OVER!"<<endl<<endl<<endl;
                            break;
                        }

                        if(availlegal(0,A)==0){
                            cout<<endl<<endl<<"NO MOVES AVAILABLE FOR COMPUTER!, PLAY AGAIN!"<<endl<<endl;
                            continue;
                        }
                        cout<<"518!"<<endl;
                        int cx=0,cy=0;int inc1=0;
                        inc1=f(0,A,cx,cy,2);inc1=0;
                        cout<<endl<<cx<<" "<<cy<<endl;
                        flipcoin(0,A,cx,cy,CB1,CW0,inc1);
                        cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                        cout<<"COMPUTER PLAYED!"<<endl<<endl;
                        cout<<"SCORES: PLAYER- "<<CB1<<" COMPUTER- "<<CW0<<"                                                              "<<endl<<endl;
                        cout<<"  Press 11 to play your move and 12 to Exit"<<endl<<endl<<endl;
                        print(A);
                        cout<<endl<<endl<<endl;
                        cout<<"___________________________________________________________________________________________________________"<<endl<<endl;
                        while(true){
                            int i;cin>>i;
                            if(i==12){
                                return 0;
                            }
                            else if(i==11){
                                break;
                            }
                            else{
                                cout<<"INVALID INPUT!"<<endl<<endl;
                            }
                        }

                    }
                    results(CW0,CB1,a1);
                    while(true){
                        int w=-1;cin>>w;
                        if(w==0){
                            return 0;
                        }
                        else if(w==1){
                            break;
                        }
                        else{
                            cout<<"INVALID INPUT!"<<endl<<endl;
                            continue;
                        }
                    }


                }
                else if(a1==0){
                    int CW0=2,CB1=2;

                    cout<<endl<<"working!"<<endl<<endl;

                }
                else if(a1==2){
                    break;
                }
                else if(a1==3){
                    return 0;
                }
                else{
                    cout<<endl<<"INVALID INPUT!"<<endl<<endl;
                    continue;
                }
                break;
            }
        }
        else if(a==0){
            return 0;
        }
        else{
            cout<<endl<<"INVALID INPUT!"<<endl<<endl;
            continue;
        }

    }
}
                                                                                                                                                                                                                                                                                                                       //22b0990

//Adrián Montemayor Rojas A01283139
//ProyC – RailRoads O(n1 * n2) donde n1 es el número de vagones del tren 1 y n2 es el número de vagones del tren 2
#include <iostream>
#include <vector>

using namespace std;

bool evalua(int n1, int n2, vector<int> t1, vector<int> t2, vector<int> tc, bool mat[1010][1010]){
    mat[0][0]=true;

    for(int x=1;x<=n2;x++){
        if(t2[x]==tc[x] && mat[0][x-1]==true){
            mat[0][x]=true;
        }else{
            mat[0][x]=false;
        }
    }

    for(int y=1;y<=n1;y++){
        if(t1[y]==tc[y] && mat[y-1][0]==true){
            mat[y][0]=true;
        }else{
            mat[y][0]=false;
        }
    }

    for(int a=1;a<=n1;a++){
        for(int b=1;b<=n2;b++){
            if((tc[a+b] == t1[a] && mat[a-1][b] == true)||(tc[a+b] == t2[b] && mat[a][b-1] == true)){
                mat[a][b]=true;
            }else{
                mat[a][b]=false;
            }
        }
    }

    bool r=mat[n1][n2];
    return r;
}

int main(){
    int n1, n2, temp;
    cin>>n1>>n2;
    while(n1!=0 && n2!=0){
        vector<int> tren1(n1+1);
        vector<int> tren2(n2+1);
        vector<int> trenC(n1+n2+1);
        bool mat[1010][1010];
        tren1[0]= -1;
        tren2[0]= -1;
        trenC[0]= -1;
        for(int x=1;x<=n1;x++){
            cin>>temp;
            tren1[x]=temp;
        }
        for(int x=1;x<=n2;x++){
            cin>>temp;
            tren2[x]=temp;
        }
        for(int x=1;x<=n1+n2;x++){
            cin>>temp;
            trenC[x]=temp;
        }
        if(evalua(n1,n2,tren1,tren2,trenC,mat)){
            cout<<"possible"<<endl;
        }else{
            cout<<"not possible"<<endl;
        }
        cin>>n1>>n2;
    }
    return 0;
}
/*
3 3
1 2 1
2 1 1
1 2 1 1 2 1

3 3
1 2 1
2 1 2
1 1 1 2 2 2
0 0 
*/
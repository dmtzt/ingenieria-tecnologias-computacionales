#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void tuTabla(int cMatTablero[4][4]){
    cout << "Tu tabla es: " << endl;
    for (int iR = 0; iR < 4; iR++){
        for (int iC = 0; iC < 4; iC++){
            cout<<cMatTablero[iR][iC]<<"-";
        }
        cout<<endl;
    }
}


bool validacioncarta(int carta, int cartas[54]){
    if(carta<0||carta>55){
        return false;
    }else{
        for(int i=0;i<54;i++){
            if(carta==cartas[i]){
                return false;
            }
        }
    }
    return true;
}

void addcarta(int cMatTablero[4][4], int carta){
    for(int i=0; i<4; i++){
        for(int j=0;j<4;j++){
            if(cMatTablero[i][j]==carta){
                cMatTablero[i][j]=0;
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0;j<4;j++){
            cout<<cMatTablero[i][j]<<"-";
        }
        cout<<endl;
    }
    
}

bool vertical(int cMatTablero[4][4]){
    bool ganar=false;
    for(int i=0;i<4;i++){
        if((cMatTablero[0][i]==0)&&(cMatTablero[1][i]==0)&&(cMatTablero[2][i]==0)&&(cMatTablero[3][i]==0)){
            return true;
        }else{
            ganar = false;
        }
    }
    return ganar;
}
bool horizontal(int cMatTablero[4][4]){
    bool ganar=false;
    for(int i=0;i<4;i++){
        if((cMatTablero[i][0]==0)&&(cMatTablero[i][1]==0)&&(cMatTablero[i][2]==0)&&(cMatTablero[i][3]==0)){
            return true;
        }else{
            ganar = false;
        }
    }
    return ganar;
}
bool diagonal(int cMatTablero[4][4]){
    bool ganar=false;
    if((cMatTablero[0][0]==0)&&(cMatTablero[1][1]==0)&&(cMatTablero[2][2]==0)&&(cMatTablero[3][3]==0))
        ganar= true;
    else if((cMatTablero[3][0]==0)&&(cMatTablero[2][1]==0)&&(cMatTablero[1][2]==0)&&(cMatTablero[0][3]==0))
        ganar= true;
    else{
        ganar= false;
    }
    return ganar;
    
}
bool cuatroesquinas(int cMatTablero[4][4]){
    if((cMatTablero[0][0]==0)&&(cMatTablero[0][3]==0)&&(cMatTablero[3][0]==0)&&(cMatTablero[3][3]==0))
        return true;
    else
        return false;
}
bool pocito(int cMatTablero[4][4]){
    if((cMatTablero[1][1]==0)&&(cMatTablero[1][2]==0)&&(cMatTablero[2][1]==0)&&(cMatTablero[2][2]==0))
        return true;
    else
        return false;
}
bool cuadroexterior(int cMatTablero[4][4]){
    if((cMatTablero[0][0]==0)&&(cMatTablero[0][1]==0)&&(cMatTablero[0][2]==0)&&(cMatTablero[0][3]==0)&&(cMatTablero[1][0]==0)&&(cMatTablero[1][3]==0)&&(cMatTablero[2][0]==0)&&(cMatTablero[2][3]==0)&&(cMatTablero[3][0]==0)&&(cMatTablero[3][1]==0)&&(cMatTablero[3][2]==0)&&(cMatTablero[3][3]==0))
        return true;
    else
        return false;
    
}
int main(){
    int cMatTablero[4][4];
    int cMatTablero2[4][4];
    int cartas[54];
    int iR, iC, iCont, cGanar;
    int j=0;
    
    for (iR = 0; iR < 4; iR++)
        for (iC = 0; iC < 4; iC++)
            cMatTablero[iR][iC] = 1;
    
    srand((int)time(0));
    for (iCont = 1; iCont <= 15;){
        iR = rand() % 4; // esto genera un numero aleatorio
        iC = rand() % 4; // entre 0 y 3 para la posición
        if (cMatTablero[iR][iC] == 1)
        {
            cMatTablero[iR][iC] = rand() % 53+1;
            iCont++;
        }
    }
    for (iR = 0; iR < 4; iR++)
        for (iC = 0; iC < 4; iC++)
            cMatTablero2[iR][iC] = cMatTablero[iR][iC];
    
    
    
    cout<<"Bienvenido a la loteria Tec! \n Ingresa el número de la opción para ganar \n 1) Vertical \n 2) Horizontal \n 3) Diagonal \n 4) Cuatro Esquinas \n 5) Pocito \n 6) Cuadro Exterior" << endl;
    cin>>cGanar;
    tuTabla(cMatTablero);
    cout<<"¡Corre!" << endl;
    
    int carta;
    
    if(cGanar==1){
        bool Ganaste = vertical(cMatTablero);
        while(Ganaste!=true){
            
            cout<<"Teclea la Carta Que gritaron";
            cin>>carta;
            bool valida= validacioncarta(carta, cartas);
            while(valida!=true){
                cout<<"Carta invalida. Ingresa nuevamente"<<endl;
                cin>>carta;
                valida=validacioncarta(carta, cartas);
            }
            
            cartas[j++]=carta;
            addcarta(cMatTablero, carta);
            Ganaste = vertical(cMatTablero);
        }
        cout<<"¡LOTERIA!";
        cout<<" Numeros Ganadores: ";
        
        if (cMatTablero[0][0]==0 && cMatTablero[1][0]==0 && cMatTablero[2][0]==0 && cMatTablero[3][0]==0)
        {
            cout << cMatTablero2[0][0] << ", " << cMatTablero2[1][0] << ", " << cMatTablero2[2][0] << ", " << cMatTablero2[3][0] << endl;
        }
        
        else         if (cMatTablero[0][1]==0 && cMatTablero[1][1]==0 && cMatTablero[2][1]==0 && cMatTablero[3][1]==0)
        {
            cout << cMatTablero2[0][1] << ", " << cMatTablero2[1][1] << ", " << cMatTablero2[2][1] << ", " << cMatTablero2[3][1] << endl;
        }
        
        else         if (cMatTablero[0][2]==0 && cMatTablero[1][2]==0 && cMatTablero[2][2]==0 && cMatTablero[3][2]==0)
        {
            cout << cMatTablero2[0][2] << ", " << cMatTablero2[1][2] << ", " << cMatTablero2[2][2] << ", " << cMatTablero2[3][2] << endl;
        }
        
        else         if (cMatTablero[0][3]==0 && cMatTablero[1][3]==0 && cMatTablero[2][3]==0 && cMatTablero[3][3]==0)
        {
            cout << cMatTablero2[0][3] << ", " << cMatTablero2[1][3] << ", " << cMatTablero2[2][3] << ", " << cMatTablero2[3][3] << endl;
        }
        
    }
    if(cGanar==2){
        bool Ganaste = horizontal(cMatTablero);
        while(Ganaste!=true){
            
            cout<<"Teclea la Carta Que gritaron";
            cin>>carta;
            bool valida= validacioncarta(carta, cartas);
            while(valida!=true){
                cout<<"Carta invalida. Ingresa nuevamente"<<endl;
                cin>>carta;
                valida=validacioncarta(carta, cartas);
            }
            
            cartas[j++]=carta;
            addcarta(cMatTablero, carta);
            Ganaste = horizontal(cMatTablero);
        }
        cout<<"¡LOTERIA!";
        cout<<" Numeros Ganadores: ";
        
        if (cMatTablero[0][0]==0 && cMatTablero[0][1]==0 && cMatTablero[0][2]==0 && cMatTablero[0][3]==0)
        {
            cout << cMatTablero2[0][0] << ", " << cMatTablero2[0][1] << ", " << cMatTablero2[0][2] << ", " << cMatTablero2[0][3] << endl;
        }
        
        else         if (cMatTablero[1][0]==0 && cMatTablero[1][1]==0 && cMatTablero[1][2]==0 && cMatTablero[1][3]==0)
        {
            cout << cMatTablero2[1][0] << ", " << cMatTablero2[1][1] << ", " << cMatTablero2[1][2] << ", " << cMatTablero2[1][3] << endl;
        }
        
        else         if (cMatTablero[2][0]==0 && cMatTablero[2][1]==0 && cMatTablero[2][2]==0 && cMatTablero[2][3]==0)
        {
            cout << cMatTablero2[2][0] << ", " << cMatTablero2[2][1] << ", " << cMatTablero2[2][2] << ", " << cMatTablero2[2][3] << endl;
        }
        
        else         if (cMatTablero[3][0]==0 && cMatTablero[3][1]==0 && cMatTablero[3][2]==0 && cMatTablero[3][3]==0)
        {
            cout << cMatTablero2[3][0] << ", " << cMatTablero2[3][1] << ", " << cMatTablero2[3][2] << ", " << cMatTablero2[3][3] << endl;
        }
        
    }
    if(cGanar==3){
        bool Ganaste = diagonal(cMatTablero);
        while(Ganaste!=true){
            
            cout<<"Teclea la Carta Que gritaron";
            cin>>carta;
            bool valida= validacioncarta(carta, cartas);
            while(valida!=true){
                cout<<"Carta invalida. Ingresa nuevamente"<<endl;
                cin>>carta;
                valida=validacioncarta(carta, cartas);
            }
            
            cartas[j++]=carta;
            addcarta(cMatTablero, carta);
            Ganaste = diagonal(cMatTablero);
        }
        cout<<"¡LOTERIA!";
        cout<<" Numeros Ganadores: ";
        
        if (cMatTablero[0][0]==0 && cMatTablero[1][1]==0 && cMatTablero[2][2]==0 && cMatTablero[3][3]==0)
        {
            cout << cMatTablero2[0][0] << ", " << cMatTablero2[1][1] << ", " << cMatTablero2[2][2] << ", " << cMatTablero2[3][3] << endl;
        }
        
        else         if (cMatTablero[0][3]==0 && cMatTablero[1][2]==0 && cMatTablero[2][1]==0 && cMatTablero[3][0]==0)
        {
            cout << cMatTablero2[1][0] << ", " << cMatTablero2[1][1] << ", " << cMatTablero2[1][2] << ", " << cMatTablero2[1][3] << endl;
        }
        
        
        
    }
    if(cGanar==4){
        bool Ganaste = cuatroesquinas(cMatTablero);
        while(Ganaste!=true){
            
            cout<<"Teclea la Carta Que gritaron";
            cin>>carta;
            bool valida= validacioncarta(carta, cartas);
            while(valida!=true){
                cout<<"Carta invalida. Ingresa nuevamente"<<endl;
                cin>>carta;
                valida=validacioncarta(carta, cartas);
            }
            
            cartas[j++]=carta;
            addcarta(cMatTablero, carta);
            Ganaste = cuatroesquinas(cMatTablero);
        }
        cout<<"¡LOTERIA!";
        cout<<" Numeros Ganadores: ";
            cout << cMatTablero2[0][0] << ", " << cMatTablero2[0][3] << ", " << cMatTablero2[3][0] << ", " << cMatTablero2[3][3] << endl;
        
        
        
        
    }
    if(cGanar==5){
        bool Ganaste = pocito(cMatTablero);
        while(Ganaste!=true){
            
            cout<<"Teclea la Carta Que gritaron";
            cin>>carta;
            bool valida= validacioncarta(carta, cartas);
            while(valida!=true){
                cout<<"Carta invalida. Ingresa nuevamente"<<endl;
                cin>>carta;
                valida=validacioncarta(carta, cartas);
            }
            
            cartas[j++]=carta;
            addcarta(cMatTablero, carta);
            Ganaste = pocito(cMatTablero);
        }
        cout<<"¡LOTERIA!";
        cout<<" Numeros Ganadores: ";
        
        
            cout << cMatTablero2[1][1] << ", " << cMatTablero2[2][1] << ", " << cMatTablero2[1][2] << ", " << cMatTablero2[2][2] << endl;
        
        
        
    }
    if(cGanar==6){
        bool Ganaste = cuadroexterior(cMatTablero);
        while(Ganaste!=true){
            
            cout<<"Teclea la Carta Que gritaron";
            cin>>carta;
            bool valida= validacioncarta(carta, cartas);
            while(valida!=true){
                cout<<"Carta invalida. Ingresa nuevamente"<<endl;
                cin>>carta;
                valida=validacioncarta(carta, cartas);
            }
            
            cartas[j++]=carta;
            addcarta(cMatTablero, carta);
            Ganaste = cuadroexterior(cMatTablero);
        }
        cout<<"¡LOTERIA!";
        cout<<" Numeros Ganadores: ";
        
            cout << cMatTablero2[0][0] << ", " << cMatTablero2[0][1] << ", " << cMatTablero2[0][2] << ", " << cMatTablero2[0][3] << ", " << cMatTablero2[1][0] << ", " << cMatTablero2[1][3] << ", " << cMatTablero2[2][0] << ", " << cMatTablero2[2][3] << ", " << cMatTablero2[3][0] << ", " << cMatTablero2[3][1] << ", " << cMatTablero2[3][2] << ", " << cMatTablero2[3][3] << endl;
        
        
        
        
    }
    
    
    
}


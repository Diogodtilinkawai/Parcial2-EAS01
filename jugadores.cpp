#include <iostream>
#include <string>
#include <cstdlib>  // Función rand().
#include <ctime>    // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador{
 

   public:
    int vida,ataque;
    string nombre;
    Jugador *PTRu;
    Jugador(); 
    Jugador(int v,int a, string n); 
    
    void atacar(Jugador &enemigo); 
};

int main()
{
    srand(time(0));  // Seed para generar valores aleatorios
    
    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque. 
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina. 
        No importa quien ataca primero.
    */
    Jugador p1(100,15,"ania"), p2 (200,5,"kda");
    
    while (p1.vida>0 && p2.vida>0)
    {
        p1.atacar(p2);
        if (p2.vida>0) p2.atacar(p1);
    }
    if (p1.vida>0) cout << "gano "<<p1.nombre;
    else cout << "gano "<< p2.nombre; 

    return 0;
}

Jugador::Jugador()
{
   
   this -> vida=100;
   this ->ataque =5;
   this ->nombre="No definido";
}

Jugador::Jugador(int v,int a, string n){
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
   if (v<=0) this -> vida=1;
   else if (v>200) this -> vida =200;
   else this -> vida=v;
if (a<=0) this -> ataque=1;
   else if (a>20) this -> ataque =20;
   else this->ataque=a;
   this -> nombre=n;

}

void Jugador::atacar(Jugador &enemigo){
    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */
    int x=rand()%5;

   if (x!=0)
   {
    enemigo.vida-=ataque; 
    cout<< this -> nombre <<" ataco a " << enemigo.nombre<<" hizo "<< this -> ataque<<" danio la vida restante de "<<enemigo.nombre<<" es "<<enemigo.vida<<endl;
   }
   else cout << this -> nombre << " ataco a " << enemigo.nombre << " pero fallo, la vida de  "<< enemigo.nombre << " se mantiene en "<< enemigo.vida<<endl;
   PTRu=this;

    /*
    Nota:
        int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}
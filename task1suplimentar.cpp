#include <iostream>
#include <cstring>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Restaurant {
public:
    int id;
    const string nume;  
    int capacitate;     
    static string adresa;  
    char* tipRestaurant; 
    bool livrari;        

    // Constructor implicit
    Restaurant() : id(0), nume("null"), capacitate(0), livrari(true)
    {
        this->tipRestaurant = new char[strlen("null") + 1];
        strcpy(this->tipRestaurant, "null");
    }

    // Constructor cu parametrii
    Restaurant(int id, const string& nume, int capacitate, const char* tipRestaurant, bool livrari)
        : id(id), nume(nume), capacitate(capacitate), livrari(livrari) 
    {
        this->tipRestaurant = new char[strlen(tipRestaurant) + 1];
        strcpy(this->tipRestaurant, tipRestaurant);
    }

    // Constructor de copiere
    Restaurant(const Restaurant& other)
        : id(other.id), nume(other.nume), capacitate(other.capacitate), livrari(other.livrari) 
    {
        this->tipRestaurant = new char[strlen(other.tipRestaurant) + 1];
        strcpy(this->tipRestaurant, other.tipRestaurant);
    }

    // Destructor
    ~Restaurant() 
    {
        if (this->tipRestaurant != nullptr) {
            delete[] this->tipRestaurant;  
        }
    }
};

// Definirea atributului static
string Restaurant::adresa = "Strada Principala, nr.1";

class Comenzi {
public:
    const int nrComanda;
    static float comandaMinima;
    float* pret;      
    int idRestaurant;
    string status;

    // Constructor implicit
    Comenzi() : nrComanda(0), idRestaurant(0), status("null") 
    {
        this->pret = new float[1]; 
        this->pret[0] = 0.0f; 
    }

    // Constructor cu parametrii
    Comenzi(const int nrComanda, float pretVal, int idRestaurant, string status)
        : nrComanda(nrComanda), idRestaurant(idRestaurant), status(status) 
    {
        this->pret = new float[1]; 
        this->pret[0] = pretVal;    
    }

    // Constructor de copiere
    Comenzi(const Comenzi& other)
        : nrComanda(other.nrComanda), idRestaurant(other.idRestaurant), status(other.status) {
        this->pret = new float[1]; // Aloc? memorie pentru un singur pre?
        this->pret[0] = other.pret[0]; // Copiaz? pre?ul
    }

    // Destructor
    ~Comenzi() {
        delete[] pret; // Elibereaz? memoria
    }
};

float Comenzi::comandaMinima = 50;

class Client
{
public:
    int idClient;
    char* numeClient;
    static string adresa;
    const int idComanda;

    Client() : idClient(0), idComanda(0)
    {
        this->numeClient = new char[strlen("null") + 1];
        strcpy(this->numeClient, "null");
    }

    Client(int idClient, const char* numeClient, const int& idComanda) :idClient(idClient), idComanda(idComanda)
    {
        this->numeClient = new char[strlen(numeClient) + 1];
        strcpy(this->numeClient, numeClient);
    }

    Client(const Client& other) :idClient(other.idClient), idComanda(other.idComanda)
    {
        this->numeClient = new char[strlen(other.numeClient) + 1];
        strcpy(this->numeClient, other.numeClient);
    }

    ~Client() {
        if (this->numeClient != nullptr) 
        {
            delete[] this->numeClient;
        }
    }


};

string Client::adresa = "Strada Principala, nr.1";



int main() 
{
    Restaurant r1;  
    Restaurant r2(1, "Pizza Italia", 50, "Italian", true);  
    Restaurant r3 = r2;  

    cout << "Restaurant 1: " << r1.nume << ", " << r1.tipRestaurant << endl;
    cout << "Restaurant 2: " << r2.nume << ", " << r2.tipRestaurant << endl;
    cout << "Restaurant 3: " << r3.nume << ", " << r3.tipRestaurant << endl;

    Comenzi c1; 
    cout << "Comanda 1: " << c1.nrComanda << ", " << c1.status << ", Pret: " << c1.pret[0] << endl;

    Comenzi c2(1, 30.5f, 1, "In asteptare"); 
    Comenzi c3 = c2;
    cout << "Comanda 2: " << c2.nrComanda << ", " << c2.status << ", Pret: " << c2.pret[0] << endl;
    cout << "Comanda 3: " << c3.nrComanda << ", " << c3.status << ", Pret: " << c3.pret[0] << endl;


    Client cl1;
    Client cl2(1, "Oana Rusu", 1);
    Client cl3 = cl2;

    cout << "Client 1: " << cl1.idClient << ", " << cl1.numeClient << endl;
    cout << "Client 2: " << cl2.idClient << ", " << cl2.numeClient << endl;
    cout << "Client 3: " << cl3.idClient << ", " << cl3.numeClient << endl;
    return 0;
}
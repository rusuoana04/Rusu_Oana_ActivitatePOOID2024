//Rusu Oana Gabriela
//Grupa 1118, ID, ANUL 3

#include <iostream>
#include <cstring>
#include <string>


using namespace std;

class Restaurant {
private:
    int id;
    const string nume;
    int capacitate;
    static string adresa;
    char* tipRestaurant;
    bool livrari;

public:
    // Constructor implicit
    Restaurant() : id(0), nume("null"), capacitate(0), livrari(true)
    {
        this->tipRestaurant = new char[strlen("null") + 1];
        strcpy_s(this->tipRestaurant, strlen("null") + 1, "null");
    }

    // Constructor cu parametrii
    Restaurant(int id, const string& nume, int capacitate, const char* tipRestaurant, bool livrari)
        : id(id), nume(nume), capacitate(capacitate), livrari(livrari)
    {
        this->tipRestaurant = new char[strlen(tipRestaurant) + 1];
        strcpy_s(this->tipRestaurant, strlen(tipRestaurant) + 1, tipRestaurant);
    }

    // Constructor de copiere
    Restaurant(const Restaurant& other)
        : id(other.id), nume(other.nume), capacitate(other.capacitate), livrari(other.livrari)
    {
        this->tipRestaurant = new char[strlen(other.tipRestaurant) + 1];
        strcpy_s(this->tipRestaurant, strlen(other.tipRestaurant) + 1, other.tipRestaurant);
    }

    // Destructor
    ~Restaurant()
    {
        if (this->tipRestaurant != nullptr) {
            delete[] this->tipRestaurant;
        }
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        if (id > 0)
        {
            this->id = id;
        }
        else
        {
            throw "Valoare negativa";
        }
    }

    string getNume() const
    {
        return this->nume;
    }

    const char* getTipRestaurant() const
    {
        return this->tipRestaurant;
    }

    void setTipRestaurant(const char* tipRest)
    {
        if (tipRest != nullptr)
        {
            delete[] this->tipRestaurant;
            this->tipRestaurant = new char[strlen(tipRest) + 1];
            strcpy_s(this->tipRestaurant, strlen(tipRest) + 1, tipRest);
        }
    }

    int getIdRestaurant() const
    {
        return this->id;
    }

    int getCapacitate()
    {
        return this->capacitate;
    }

    void setCapacitate(int capacitate)
    {
        if (capacitate > 0)
        {
            this->capacitate = capacitate;
        }
        else
        {
            throw "Valoare negativa";
        }
    }
    bool getLivrari() const {
        return this->livrari;
    }

    void setLivrari(bool livrari) {
        this->livrari = livrari;
    }

    static string getAdresa()
    {
        return adresa;
    }


    friend void actualizareCapacitate(Restaurant r, int capacitateNoua);
};

// Definirea atributului static
string Restaurant::adresa = "Strada Principala, nr.1";

void actualizareCapacitate(Restaurant r, int capacitateNoua)
{
    if (capacitateNoua > 0)
    {
        r.capacitate = capacitateNoua;
        cout << "Capacitatea restaurantului a fost actualizata la: " << r.capacitate << endl;
    }
    else
    {
        cout << "Capacitatea nu poate fi negativa" << endl;
    }
}

class Comenzi {
private:
    const int nrComanda;
    static float comandaMinima;
    float* pret;
    int idRestaurant;
    string status;

public:
    // Constructor implicit
    Comenzi() : nrComanda(1), idRestaurant(0), status("null")
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
        this->pret = new float[1];
        this->pret[0] = other.pret[0];
    }

    // Destructor
    ~Comenzi() {
        delete[] pret;
    }

    int getNrComanda() const
    {
        return nrComanda;
    }

    float* getPret() const {
        return this->pret;
    }

    void setPret(float* preturi, int nrProduse) {
        delete[] this->pret;

        this->pret = new float[nrProduse];
        for (int i = 0; i < nrProduse; i++) {
            this->pret[i] = preturi[i];
        }
    }

    int getIdRestaurant()
    {
        return this->idRestaurant;
    }

    void setIdRestaurant(int idRest)
    {
        if (idRest > 0)
        {
            this->idRestaurant = idRest;
        }
        else
        {
            throw "Valoare negativa";
        }
    }

    string getStatus()
    {
        return this->status;
    }

    void setStatus(string& status)
    {
        this->status = status;
    }

    static float getComandaMinima()
    {
        return comandaMinima;
    }

    friend void actualizarePret(Comenzi& c, float pretNou);
};

float Comenzi::comandaMinima = 50;

void actualizarePret(Comenzi& c, float pretNou)
{
    delete[] c.pret;
    c.pret = new float[1];
    c.pret[0] = pretNou;
    cout << "Pret actualizat: " << c.pret[0] << endl;
}

class Client
{
private:
    int idClient;
    char* numeClient;
    static string adresa;
    const int idComanda;

public:
    Client() : idClient(0), idComanda(0)
    {
        this->numeClient = new char[strlen("null") + 1];
        strcpy_s(this->numeClient, strlen("null") + 1, "null");
    }

    Client(int idClient, const char* numeClient, const int& idComanda) :idClient(idClient), idComanda(idComanda)
    {
        this->numeClient = new char[strlen(numeClient) + 1];
        strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
    }

    Client(const Client& other) :idClient(other.idClient), idComanda(other.idComanda)
    {
        this->numeClient = new char[strlen(other.numeClient) + 1];
        strcpy_s(this->numeClient, strlen(other.numeClient) + 1, other.numeClient);
    }

    ~Client() {
        if (this->numeClient != nullptr)
        {
            delete[] this->numeClient;
        }
    }

    int getIdClient() const
    {
        return idClient;
    }

    void setIdClient(int idClient)
    {
        if (idClient > 0)
        {
            this->idClient = idClient;
        }
        else
        {
            throw "Valoare negativa";
        }
    }

    const char* getNumeClient() const
    {
        return numeClient;
    }

    void setNumeClient(const char* nume)
    {
        if (nume != nullptr)
        {
            delete[]this->numeClient;
            this->numeClient = new char[strlen(nume) + 1];
            strcpy_s(this->numeClient, strlen(nume) + 1, nume);
        }
    }

    int getIdComanda() const
    {
        return this->idComanda;
    }


    static string getAdresa()
    {
        return adresa;
    }

};

string Client::adresa = "Strada Principala, nr.1";



int main()
{
    Restaurant r1;
    Restaurant r2(1, "Pizza Italia", 50, "Italian", true);
    Restaurant r3 = r2;

    cout << "Restaurant 1: " << "Id: " << r1.getId() << ", Nume:  " << r1.getNume() << ", Capacitate: " << r1.getCapacitate() << ", Tip: " << r1.getTipRestaurant() << ", Livrari:  " << (r1.getLivrari() ? "Restaurantul face livrari" : "Restaurantul nu face livrari") << ", Adresa: " << Restaurant::getAdresa() << endl;
    cout << "Restaurant 2: " << r2.getId() << ", Nume: " << r2.getNume() << ", Capacitate: " << r2.getCapacitate() << ", Tip: " << r2.getTipRestaurant() << ",  Livrari: " << (r2.getLivrari() ? "Restaurantul face livrari" : "Restaurantul nu face livrari") << ", Adresa: " << Restaurant::getAdresa() << endl;
    cout << "Restaurant 3: " << r3.getId() << ", Nume: " << r3.getNume() << ", Capacitate: " << r3.getCapacitate() << ", Tip: " << r3.getTipRestaurant() << ", Livrari: " << (r3.getLivrari() ? "Restaurantul face livrari" : "Restaurantul nu face livrari") << ", Adresa: " << Restaurant::getAdresa() << endl;

    cout << "Capacitate initiala: " << r2.getCapacitate() << endl;

    actualizareCapacitate(r2, 100);



    cout << "\n";

    Comenzi c1;
    cout << "Comanda 1: " << "Nr comanda: " << c1.getNrComanda() << ", " << c1.getStatus() << ", Pret: " << c1.getPret()[0] << ", Comanda minima: " << Comenzi::getComandaMinima() << endl;

    Comenzi c2(1, 80.5f, 1, "In asteptare");
    Comenzi c3 = c2;
    cout << "Comanda 2: " << " Nr comanda: " << c2.getNrComanda() << ", Status:  " << c2.getStatus() << ", Pret: " << c2.getPret()[0] << ", Comanda minima:  " << Comenzi::getComandaMinima() << endl;
    cout << "Comanda 3: " << " Nr comanda: " << c3.getNrComanda() << ",  Status: " << c3.getStatus() << ", Pret: " << c3.getPret()[0] << ", Comanda minima: " << Comenzi::getComandaMinima() << endl;


    cout << "Pret initial: " << c2.getPret()[0] << endl;
    actualizarePret(c2, 150.8f);
    cout << "\n";

    Client cl1;
    Client cl2(1, "Oana Rusu", 1);
    Client cl3 = cl2;

    cout << "Client 1: " << "Id client: " << cl1.getIdClient() << ", Nume: " << cl1.getNumeClient() << ",  Id comanda: " << cl1.getIdComanda() << ", Adresa: " << Client::getAdresa() << endl;
    cout << "Client 2: " << "Id client: " << cl2.getIdClient() << ", Nume: " << cl2.getNumeClient() << ", Id comanda: " << cl2.getIdComanda() << "Adresa: " << Client::getAdresa() << endl;
    cout << "Client 3: " << "Id client: " << cl3.getIdClient() << ", Nume: " << cl3.getNumeClient() << ", Id comanda: " << cl3.getIdComanda() << "Adresa: " << Client::getAdresa() << endl;
    return 0;
}

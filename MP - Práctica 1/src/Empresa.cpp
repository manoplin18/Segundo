#include "Empresa.h"

Empresa::Empresa():nmaxcli(100), nmaxcon(100){
    this->ncli = 0;
    this->ncon = 0;
    this->nmaxcon = 10;
    this->contratos = new Contrato *[nmaxcon]; //Capacidad para 10 contratos

}

Empresa::~Empresa(){
    for(int i = 0; i < this->ncon; i++)
        delete this->contratos[i];          // elimino los objetos contratos
    delete [] this->contratos;             //luego elimino el array de punteros

    for(int i = 0; i < this->ncli; i++)
        delete this->clientes[i];          // elimino los objetos clientes
}

int Empresa::altaCliente(Cliente *c) {
    int pos = -1;
    if(this->ncli < nmaxcli){
        this->clientes[this->ncli] = c;
        pos = this->ncli;
        this->ncli++;
    }
    else
        cout << "Lo siento, el cupo de clientes esta lleno";

    return pos;
    
}

int Empresa::altaContrato(Contrato *c) {
    int pos = -1;
    if(this->ncon < nmaxcon){
        this->contratos[this->ncon] = c;
        pos = this->ncon;
        this->ncon++;
    }
    else
        cout << "Lo siento, el cupo de contratos esta lleno";

    return pos;
    
}

int Empresa::buscarCliente(long int dni) const {
  
    for(int i = 0; i < this->ncli; i++){
        if(this->clientes[i]->getDni() == dni){
            return i; // una vez encuentre una coincidencia parara el bucle y devuelve la pos
        }
    }
    return -1; // si no encuentra coincidencia saldra del bucle y devuelve -1
}

void Empresa::crearContrato() {
    long int dni;
    int pos;
    cout << "\nIntroduce DNI: ";
    cin >> dni;
    pos=this->buscarCliente(dni); // guardamos la pos del cliente (pos = -1 si no existe)
    int dia,mes,anio; //reutilizo las variables para optimizar (1) (2)
    if(pos == -1){ //creo el cliente si es nuevo usuario
        char nombre[100];
        Cliente *c;
        cout << "\nIntroduce Nombre: ";
        cin.ignore();
        cin.getline(nombre, 100);
        cout << "\nIntroduce Fecha (dd mm aaaa): ";
        cin >> dia >> mes >> anio; //(1)
        c = new Cliente(dni, nombre, Fecha(dia,mes,anio));
        pos = this->altaCliente(c);
    }
    if(pos != -1){ //creo un contrato para el usuario nuevo o no
        int tipo, min;
        Fecha fc;
        cout << "\nTipo de Contrato a abrir(1-Tarifa Plana, 2-Movil): ";
        cin >> tipo;      
        cout << "\nIntroduce Fecha (dd mm aaaa): ";
        cin >> dia >> mes >> anio; //(2) machaco valores anteriores 
        fc.setFecha(dia,mes,anio);
        cout << "\nMinutos hablados: ";
        cin >> min;
        if(tipo == 2){ //datos extras para ContratoMovil
            float p;
            char nac[100];
            cout << "\nPrecio minuto: ";
            cin >> p;
            cout << "\nNacionalidad: ";
            cin >> nac;
            Contrato *cM = new ContratoMovil(dni,fc,p,min,nac);
            this->altaContrato(cM);
        }
        else{ //Creo contrato de Tarifa Plana
            Contrato *cTP = new ContratoTP(dni,fc,min); 
            this->altaContrato(cTP);
        }

    }
}

void Empresa::cargarDatos(){
    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
    Cliente *cl1 = new Cliente(75547001, "Peter Lee", f1);  
    Cliente *cl2 = new Cliente(45999000, "Juan Perez", f2);
    Cliente *cl3 = new Cliente(37000017, "Luis Bono", f3);  

    this->altaCliente(cl1);
    this->altaCliente(cl2);
    this->altaCliente(cl3);   
    
    Contrato *c1 = new ContratoMovil(75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m  
    Contrato *c2 = new ContratoMovil(75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m  
    Contrato *c3 = new ContratoTP(37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)  
    Contrato *c4 = new ContratoTP(75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)  
    Contrato *c5 = new ContratoMovil(45999000, f2, 0.10, 202, "ESPANIOL"); //habla 202m a 0.10/m  
    Contrato *c6 = new ContratoMovil(75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m  
    Contrato *c7 = new ContratoTP(45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)  

    this->altaContrato(c1);
    this->altaContrato(c2);
    this->altaContrato(c3);
    this->altaContrato(c4);
    this->altaContrato(c5);
    this->altaContrato(c6);
    this->altaContrato(c7);

}

bool Empresa::cancelarContrato(int idContrato){
    for(int i = 0; i < this->ncli; i++){
       if(this->contratos[i]->getIdContrato() == idContrato){
           while( i < this->ncon){
               this->contratos[i] = this->contratos[i+1];
               i++;
            }
            this->ncon--; 
           return true;
        }
    }
    return false;
}

bool Empresa::bajaCliente(long int dni){ 
    int pos = Empresa::buscarCliente(dni);
    if(pos != -1){
        while( pos < this->ncli){
            this->clientes[pos] = this->clientes[pos+1];
            pos++;                                          // baja del cliente
        }
        this->ncli--;
        int i = 0;
        while( i < ncon){
            if(this->contratos[i]->getDniContrato() == dni ){ //busco todos los contratos que pertenezcan al mismo cliente (dni)
                Empresa::cancelarContrato(this->contratos[i]->getIdContrato()); //cancelo los contratos del cliente
            }else 
                i++;
        }
        return true;
    }
    else 
        return false;
}

int Empresa::nContratosTP() const{
    int nContratos = 0;
    for(int i = 0; i < this->ncon; i++){
        if(typeid(*contratos[i]) == typeid(ContratoTP)){ // True si el tipo de contrato de contratos[i] es TP
            nContratos++;
        } 
    }
    return nContratos;
}

int Empresa::descuento(float descuento) const {
    int nDescuentos = 0;
    ContratoMovil *c;
    for (int i = 0; i < ncon; i++){
                                           //c = dynamic_cast<ContratoMovil*>(contratos[i]);
        c = (ContratoMovil*)contratos[i]; // son lo mismo
        if(c){
            c->setPrecioMinuto(c->getPrecioMinuto()*(1-descuento/100));
            nDescuentos++;
        }
    }
    return nDescuentos;
}

void Empresa::ver() const {

    cout << "\nLa Empresa tiene " << ncli << " clientes y " << ncon << " contratos";
    
    cout << "\nClientes: ";
    for(int i = 0; i < ncli; i++){
        cout << "\n";
        clientes[i]->ver(); 
    }
    
    cout << "\n\nContratos: ";
    for(int i = 0; i < ncon; i++){
        cout << "\n";
        contratos[i]->ver(); 
    }
}
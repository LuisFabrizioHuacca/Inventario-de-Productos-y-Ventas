#include <iostream>
using namespace std;

const int limiteProductos=100;
const int limiteVentas=100;

struct Producto{
	string nombre;
	float precio;
};
struct Venta{
	int idVenta;
	string producto;
	int cantidad;
    float precioTotal;
};

void registrarProducto(Producto articulo[],int &numeroProducto){
	if (numeroProducto>=limiteProductos){
        cout<<"\nlimite de productos alcanzado, no se puede registrar mas productos"<<endl;
        return;
	}
	cout<<"\nIngrese el nombre del producto: ";
	cin>>articulo[numeroProducto].nombre;
	cout<<"Ingrese el precio del producto: ";
	cin>>articulo[numeroProducto].precio;
	cout<<"Producto registrado con exito"<<endl;
	cout<<endl;
	numeroProducto++;
}

void registrarVenta(Venta transaccion[], int &numeroVenta, int &idVentaActual){
 	if (numeroVenta>=limiteVentas){
        cout<<"\nLimite de ventas alcanzado, no se puede registrar mas Ventas"<<endl;
        return;
    }
	transaccion[numeroVenta].idVenta=idVentaActual++;
	cout<<"\nIntrodusca el nombre del producto que fue vendido: ";
	cin>>transaccion[numeroVenta].producto;
	cout<<"Ingrese la cantidad vendida del producto: ";
	cin>>transaccion[numeroVenta].cantidad;
	cout<<"Ingrese el precio total por la venta: ";
	cin>>transaccion[numeroVenta].precioTotal;
	numeroVenta++;
}


int main(){
	Producto articulo[limiteProductos];
	Venta transaccion[limiteVentas];
	int numeroProducto=0;
	int numeroVenta=0;
	int idVentaActual=1;
	int opcion;
	do{
		cout<<"Menu de inventario y ventas"<<endl;
		cout<<"1. Registrar un nuevo producto"<<endl;
		cout<<"2. Registrar una venta"<<endl;
		cout<<"3. Mostrar la lista de productos registrados"<<endl;
		cout<<"4. Eliminar un producto"<<endl;
		cout<<"5. Buscar un producto por su nombre"<<endl;
		cout<<"6. Mostrar lista de ventas registradas"<<endl;
		cout<<"7. Actualizar un producto registrado"<<endl;
		cout<<"8. Salir del programa"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		switch (opcion){
			case 1:
				registrarProducto(articulo, numeroProducto);
				break;
			case 2:
				registrarVenta(transaccion, numeroVenta, idVentaActual);
				break;	
			default:
				cout<<"Opcion no valida, seleccione una opcion del 1 al 3."<<endl;
				break;
		}
	}while(opcion!=8);
	return 0;
}

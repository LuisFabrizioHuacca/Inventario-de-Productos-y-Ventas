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

void mostrarProductos(const Producto articulo[],int numeroProducto){
	if(numeroProducto==0){
		cout<<"\nNo hay productos que hayan sido registrado de momento"<<endl;
		cout<<endl;
	}else{
		cout<<"\nLista de productos registrados: "<<endl;
		for(int i=0;i<numeroProducto;i++){
			cout<<"Producto numero "<<(i+1)<<": "<<endl;
			cout<<"Nombre del producto: "<<articulo[i].nombre<<endl;
			cout<<"Precio del producto: "<<articulo[i].precio<<endl;
			cout<<endl;
		}
	}
}

void eliminarProducto(Producto articulo[], int &numeroProducto){
	if (numeroProducto==0){
		cout<<"No se han registrado productos de momento"<<endl;
		cout<<endl;
		return;
	}
	string nombreProducto;
	cout<<"Ingrese el nombre del producto a eliminar: ";
	cin>>nombreProducto;
	
	int indice=-1;
	for(int i=0;i<numeroProducto;i++){
		if(articulo[i].nombre==nombreProducto){
			indice=i;
			break;
		}
	}
	if (indice==-1){
		cout<<"El producto no fue encontrado"<<endl;
		return;
	}
	for(int i=indice;i<(numeroProducto-1);i++){
		articulo[i]=articulo[i+1];
	}
	numeroProducto--;
	cout<<"El producto fue eliminado"<<endl;
	cout<<endl;
}

void buscarProducto(const Producto articulo[], int numeroProducto){
	if(numeroProducto==0){
		cout<<"Aun no se ha registrado productos de momento"<<endl;
		cout<<endl;
		return;
	}
	string nombreProducto;
	cout<<"Ingrese el nombre del producto que quiere buscar: ";
	cin>>nombreProducto;
	
	for(int i=0;i<numeroProducto;i++){
		if(articulo[i].nombre==nombreProducto){
			cout<<"\nEl producto encontrado es: "<<endl;
			cout<<"Nombre del producto: "<<articulo[i].nombre<<endl;
			cout<<"Precio del producto: "<<articulo[i].precio<<endl;
			cout<<endl;
			return;
		}
	}
	cout<<"El nombre ingresdo del producto no se encuentra registrado"<<endl;
	cout<<endl;
	
}

void mostrarVentas(const Venta transaccion[],int numeroVenta){
	if(numeroVenta==0){
		cout<<"\nNo hay ventas registradas de momento"<<endl;
		cout<<endl;
	}else{
		cout<<"\nVentas registradas: "<<endl;
		for (int i=0;i<numeroVenta;i++){
			cout<<"ID de la venta: "<<transaccion[i].idVenta<<endl;
			cout<<"Producto vendido: "<<transaccion[i].producto<<endl;
			cout<<"Cantidad vendidad del producto: "<<transaccion[i].cantidad<<endl;
			cout<<"Precio total: "<<transaccion[i].precioTotal<<endl;
			cout<<endl;
		}
	}
}

void actualizarProducto(Producto rticulo[],int numeroProducto){
	if(numeroProducto==0){
		cout<<"No hay productos registrado de momento"<<endl;
		cout<<endl;
		return;
	}
	string nombreProducto
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
			case 3:
				mostrarProductos(articulo, numeroProducto);
				break;
			case 4:
				eliminarProducto(articulo,numeroProducto);
				break;		
			case 5:
				buscarProducto(articulo,numeroProducto);
			case 6:
				mostrarVentas(transaccion,numeroVenta);
				break;	
			case 7:
				actualizarProducto(articulo,numeroProducto);
				break;	
			default:
				cout<<"Opcion no valida, seleccione una opcion del 1 al 3."<<endl;
				break;
		}
	}while(opcion!=8);
	return 0;
}

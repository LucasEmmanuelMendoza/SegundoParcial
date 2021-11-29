#include "Principales.h"

int main(void)
{
	//eCliente clientes [TAMCLIENTES];
	setbuf (stdout, NULL);

	int idCliente1;
	idCliente1 = 101;

	int idPedido;
	idPedido = 1;

	//case 4
	int idCliente4;

	char empresa[30];
	char cuit[13];
	char direccionEmpresa[30];
	int localidadEmpresa;
	int idChofer;
	int listaIdClientesDadosDeBaja[TAMCLIENTES];
	int retornoBaja;
	eCliente clienteReturn11;
	eCliente clienteReturn12;
	eCliente clienteReturn13;
	ePedido pedidos [TAMPEDIDOS];
	float kilos;
	int retornoPendientesLoc;
	float retornoKilosPP;
	int retorno11;
	int retorno12;
	int retorno13;
	int retorno14;
	int retornoMod;
	char seguir;
	int opcion;

	int banderaCliente;
	int banderaPedido;

	banderaCliente = 1;
	banderaPedido = 1;

	eChofer choferes[TAMCHOFERES]={{1,"Carlos Gonzalez", 8.03},{2, "Ivan Gomez", 9.25},{3,"Alberto Mendoza", 8.00},{4, "Marcos Nieves", 10.50},{5, "Jose Aguirre", 7.30}};
	eLocalidad localidades[TAMLOCALIDADES]={{1,"Avellaneda"}, {2, "Lanús"}, {3, "Wilde"}, {4, "Villa Domínico"}, {5, "Dock Sud"}, {6, "Banfield"}, {7, "Quilmes"}, {8, "Barracas"}};

	/* ;

	InicializarArray (clientes, TAMCLIENTES);*/

	Inicializar (listaIdClientesDadosDeBaja, TAMCLIENTES);

	InicializarPedidos (pedidos, TAMPEDIDOS);


				eCliente clientes [TAMCLIENTES]	={{1,"Linkbridge","11489075448","9914 Farragut Point",4,1}
			 	,{2,"LiveZ","11360099578","327 Pepper Wood Court",2,1}
				,{3,"Centimia","11150339154","1 Monument Trail",7,1}
				,{4,"Demizz","11713074809","7472 Birchwood Way",6,1}
				,{5,"Skiptube","11720235929","5 Clarendon Circle",7,1}
				,{6,"Oyondu","11709133194","95854 Autumn Leaf Trail",1,1}
				,{7,"Divavu","11466772805","34 Fairview Street",8,1}
				,{8,"Skibox","11437697744","4047 Golf Course Pass",6,1}
				,{9,"DabZ","11495398257","70453 Dapin Way",1,1}
				,{10,"Chatterbridge","11701256988","75 Farwell Hill",2,1}
				,{11,"Jaxnation","11725313666","1492 Di Loreto Street",7,1}
				,{12,"Gabtune","11314808127","53 Gateway Terrace",7,1}
				,{13,"Tavu","11530670234","29 Veith Crossing",2,1}
				,{14,"Linklinks","11966021565","161 Jay Point",1,1}
				,{15,"Tagtune","11408371927","95 Southridge Center",2,1}
				,{16,"Skynoodle","11342863633","10 Blackbird Drive",3,1}
				,{17,"Kwimbee","11739558870","859 Melrose Park",4,1}
				,{18,"Plajo","11408182671","38570 Sheridan Drive",3,1}
				,{19,"Roombo","11506461481","9089 Lakeland Drive",4,1}
				,{20,"Yacero","11484833943","57707 Dovetail Road",4,1}
				,{21,"Aimbo","11480588785","0 Karstens Way",6,1}
				,{22,"Vitz","11629884142","8141 Jackson Way",7,1}
				,{23,"Demivee","11523924730","3 Mockingbird Terrace",6,1}
				,{24,"Skyvu","11723866172","5 Tennyson Place",6,1}
				,{25,"Dazzlesphere","11251750802","773 Straubel Place",3,1}
				,{26,"Realfire","11690394433","7 Trailsway Parkway",2,1}
				,{27,"Trudoo","11165375832","508 Monica Plaza",2,1}
				,{28,"Vidoo","11107616082","1455 Mandrake Place",5,1}
				,{29,"Trudeo","11999810394","112 Loomis Point",2,1}
				,{30,"Blognation","11436893061","063 Talmadge Street",7,1}
				,{31,"Jamia","11150051103","072 Twin Pines Alley",1,1}
				,{32,"Linkbridge","11407874272","1459 Oak Road",7,1}
				,{33,"Demivee","11748652469","4782 Mariners Cove Alley",3,1}
				,{34,"Brainverse","11587193444","96 Luster Terrace",6,1}
				,{35,"Zooveo","11345626646","77 Bunting Street",8,1}
				,{36,"Photospace","11320495290","5 Burning Wood Circle",8,1}
				,{37,"BlogXS","11695057755","8 Prentice Park",7,1}
				,{38,"Mita","11606582359","6032 Canary Plaza",4,1}
				,{39,"Photobug","11153012479","43106 Erie Road",2,1}
				,{40,"Gabvine","11987232868","466 Eggendart Drive",4,1}
				,{41,"Flipbug","11773577055","54 Montana Avenue",3,1}
				,{42,"Dabjam","11498156630","07 Aberg Plaza",7,1}
				,{43,"Centimia","11750609524","5214 Kennedy Lane",7,1}
				,{44,"Youspan","11600498733","63 Barby Pass",5,1}
				,{45,"Brainverse","11775347785","1578 Lotheville Crossing",3,1}
				,{46,"Digitube","11637686061","58735 Corry Lane",8,1}
				,{47,"Kaymbo","11371719073","94257 Northport Center",2,1}
				,{48,"Chatterpoint","11476811638","9 Sutherland Hill",2,1}
				,{49,"Mudo","11380802562","7878 Farwell Parkway",6,1}
				,{50,"Tagcat","11660622466","907 Vernon Pass",7,1}
				,{51,"Feedmix","11645601433","3000 Del Sol Plaza",1,1}
				,{52,"Dabjam","11256911128","20407 Schmedeman Court",2,1}
				,{53,"Twimm","11414760336","4927 Scofield Plaza",5,1}
				,{54,"Gabvine","11816870450","27646 Harper Plaza",4,1}
				,{55,"Ooba","11352062615","8 Texas Circle",6,1}
				,{56,"Kwimbee","11548613386","3106 Russell Drive",3,1}
				,{57,"Feedbug","11374372772","1880 Summit Road",2,1}
				,{58,"Gabspot","11378559773","114 Stone Corner Park",4,1}
				,{59,"Divavu","11715150698","61945 Sachtjen Terrace",4,1}
				,{60,"Browsecat","11224818891","329 Southridge Lane",8,1}
				,{61,"Agivu","11302875510","5356 Eliot Drive",1,1}
				,{62,"Babblestorm","11836193169","9036 Rigney Road",8,1}
				,{63,"Twimm","11776775048","91 Sunnyside Lane",1,1}
				,{64,"Photospace","11377463247","055 Warbler Avenue",7,1}
				,{65,"Voolia","11306379551","96 Duke Trail",8,1}
				,{66,"LiveZ","11108458545","79 Maywood Drive",4,1}
				,{67,"Ntags","11516315752","628 Victoria Terrace",5,1}
				,{68,"Yodel","11613855098","666 High Crossing Terrace",1,1}
				,{69,"Vimbo","11821498015","694 Union Parkway",3,1}
				,{70,"Topiclounge","11710322135","9508 Tennyson Place",1,1}
				,{71,"Skivee","11932576143","37 Northview Lane",6,1}
				,{72,"Abatz","11957760066","72 South Road",8,1}
				,{73,"Mynte","11188247468","9338 Melvin Way",1,1}
				,{74,"Wikizz","11586220180","8207 Blaine Place",4,1}
				,{75,"Skimia","11540722172","5 Dovetail Alley",2,1}
				,{76,"Jabberstorm","11505726240","600 Welch Terrace",1,1}
				,{77,"Skyvuv","11900970306","7741 Shelley Hill",8,1}
				,{78,"Skimia","11851668364","89420 Thierer Crossing",3,1}
				,{79,"Browseblab","11483281707","721 Lunder Parkway",2,1}
				,{80,"Twitterworks","11707635594","2 Tomscot Trail",1,1}
				,{81,"Feedbug","11862568526","7885 Larry Place",5,1}
				,{82,"Oyoba","11705375590","20750 Dakota Circle",3,1}
				,{83,"Thoughtstorm","11940265759","4 Dennis Road",4,1}
				,{84,"Jatri","11327781528","78865 Killdeer Park",7,1}
				,{85,"Layo","11865538053","140 Shoshone Crossing",7,1}
				,{86,"Rooxo","11381375881","5784 Leroy Avenue",6,1}
				,{87,"Kwideo","11758691181","72345 Summer Ridge Parkway",5,1}
				,{88,"Mydeo","11936787651","1559 Riverside Avenue",5,1}
				,{89,"Voonyx","11744562731","8746 Stoughton Alley",6,1}
				,{90,"Twimbo","11325205965","49129 Old Shore Plaza",3,1}
				,{91,"Trupe","11514496295","865 Helena Terrace",4,1}
				,{92,"Skiptube","11901552622","908 Swallow Center",5,1}
				,{93,"Innotype","11300826890","180 Hanson Terrace",8,1}
				,{94,"Gabtune","11539057097","8 Russell Parkway",5,1}
				,{95,"Vipe","11465473479","20 Hoard Court",8,1}
				,{96,"Zoomzone","11356240432","8 Delaware Park",1,1}
				,{97,"Roomm","11829947776","1317 Fulton Pass",7,1}
				,{98,"Trunyx","11461367285","5890 Crowley Pass",5,1}
				,{99,"Midel","11323255755","354 Blue Bill Park Alley",4,1}
				,{100,"Wikido","11779532437","8332 Ramsey Plaza",6,1}};

	//listaIdClientesDadosDeBaja = {};

	seguir = 's';

	do{
	printf ("Menú de opciones: \n");
	printf ("1)Alta de cliente\n2)Modificar dato de cliente\n3)Baja de cliente\n4)Crear pedido de recoleccion\n5)Procesar residuos\n6)Imprimir clientes\n7)Imprimir Pedidos pendientes\n8)Imprimir Pedidos procesados\n9)Mostrar la cantidad de pedidos pendientes para una localidad\n10)Mostrar el promedio de kilos de polipropileno reciclado por cliente\n11)Mostrar el cliente con más pedidos pendientes\n12)Mostrar el cliente con más pedidos completados\n13)Mostrar el cliente con más pedidos\n14)Mostrar los pedidos completados que fueron recolectados por choferes que ingresaron a trabajar luego de las 8:05");


	opcion = PedirEntero("\nSeleccione una opcion: \n", 0, 15);

	while (banderaCliente == 0 && opcion != 1 )
	{
		printf ("Primero debe ingresar un cliente (opción 1)");
		opcion = PedirEntero("\nSeleccione una opcion: \n", 0, 15);
	}

	while (banderaPedido == 0 && (opcion > 6 || opcion == 5))
	{
		printf ("Primero debe generar un pedido (opción4)");
		opcion = PedirEntero("\nSeleccione una opcion: \n", 0, 15);
	}

	switch (opcion)
	{
	case 1:

 		PedirDatosCliente (clientes, TAMCLIENTES, empresa, cuit, direccionEmpresa, &localidadEmpresa, listaIdClientesDadosDeBaja, localidades,TAMLOCALIDADES);

 		AltaCliente (clientes, TAMCLIENTES, idCliente1, empresa, cuit, direccionEmpresa, localidadEmpresa);

 		idCliente1 = idCliente1 +1;

 		banderaCliente = 1;
		break;

	case 2:
		ImprimirClientes (clientes, TAMCLIENTES, localidades, TAMLOCALIDADES);

		retornoMod = ModificarDatos (clientes, TAMCLIENTES, localidades, TAMLOCALIDADES);
		if (retornoMod == 1)
		{
			printf ("Se ha modificado el dato\n");
		}
		break;

	case 3:
		ImprimirClientes (clientes, TAMCLIENTES, localidades, TAMLOCALIDADES);

		retornoBaja = BajaCliente (clientes, TAMCLIENTES, pedidos, TAMPEDIDOS);

		if (retornoBaja == 1)
		{
			printf ("Se ha dado de baja el cliente\n");
		}
		break;

	case 4: //Crear pedido de recolección
		ImprimirClientes (clientes, TAMCLIENTES, localidades, TAMLOCALIDADES);

		PedirDatosDelPedido (pedidos, TAMPEDIDOS, TAMPEDIDOS, &idCliente4, &kilos, &idChofer, choferes, TAMCHOFERES);

		AddPedido (pedidos, TAMPEDIDOS, idPedido, kilos, idCliente4, idChofer);

		idPedido = idPedido +1;

		banderaPedido = 1;
		break;

	case 5:
		ImprimirPedidosPendientesConId (clientes, TAMCLIENTES, pedidos, TAMPEDIDOS); //NO IMPRIME EL ID DEL PEDIDO

		ProcesarResiduos (pedidos, TAMPEDIDOS);

		printf ("Residuos procesados\n");
		break;
	case 6:
		ImprimirClientesPendientes (clientes, TAMCLIENTES, pedidos, TAMPEDIDOS, localidades, TAMLOCALIDADES);
		break;

	case 7:
		ImprimirPedidosPendientes (clientes, TAMCLIENTES, pedidos, TAMPEDIDOS);
		break;

	case 8:
		ImprimirPedidosProcesados (clientes, TAMCLIENTES, pedidos, TAMPEDIDOS);
		break;

	case 9:
		retornoPendientesLoc = CalcularPendientesLoc (clientes, TAMCLIENTES, pedidos, TAMPEDIDOS, localidades, TAMLOCALIDADES);
		printf ("La cantidad de pedidos pendientes para la localidad ingresada es: %d\n", retornoPendientesLoc);
		break;

	case 10:
		retornoKilosPP = PromedioPPRecicladoPorCliente (clientes, TAMCLIENTES, pedidos, TAMPEDIDOS);
		printf ("El promedio de kilos de PP reciclados por cliente es: %f\n", retornoKilosPP);
		break;

	case 11:
		//cliente con más pedidos pendientes
		retorno11 = ClienteConMasPedidosPorFiltro(clientes, TAMCLIENTES, pedidos, TAMPEDIDOS, "Pendiente", &clienteReturn11);
		if (retorno11 == 1)
		{
			printf ("El cliente con más pedidos pendientes es: ");
			ImprimirUnCliente (clienteReturn11, localidades, TAMLOCALIDADES);
		}
		break;

	case 12: // Cliente con más pedidos completados.
		retorno12 = ClienteConMasPedidosPorFiltro(clientes, TAMCLIENTES, pedidos, TAMPEDIDOS, "Completado", &clienteReturn12);
		if (retorno12 == 1)
		{
			printf ("El cliente con mas pedidos completados es: ");
			ImprimirUnCliente (clienteReturn12, localidades, TAMLOCALIDADES);
		}
		break;

	case 13: // Cliente con más pedidos
		retorno13 = CalcularClienteConMasPedidos(pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, &clienteReturn13);
		if (retorno13 == 1)
		{
			printf ("El cliente con más pedidos es: ");
			ImprimirUnCliente (clienteReturn13, localidades, TAMLOCALIDADES);
		}
		break;

	case 14: //Mostrar una lista de los pedidos completados que fueron recolectados luego de cierta hora con la información:
		// Id pedido, cuit cliente, direccion del cliente, localidad del cliente, cantidad de kilos del pedido, nombre del chofer.
		retorno14 = MostrarPedidosCompletadosLuegoDeUnaHora (pedidos, TAMPEDIDOS, clientes, TAMCLIENTES, choferes, TAMCHOFERES, 8.05);
		if (retorno14)
		{

		}
		break;

	case 15:
		seguir = 'n';
		break;
	}

	}while (seguir == 's');

	return EXIT_SUCCESS;
}

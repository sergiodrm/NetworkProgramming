//---------------------------------------------------------------------------
// serverENet.h
//---------------------------------------------------------------------------

/**
 * @file serverENet.h
 *
 * Implementa un servidor de red con ENet
 *
 *
 * @author Juan A. Recio-Garc�a, David Llans�
 * @date Junio, 2006
 */

#ifndef __SERVERENET_H
#define __SERVERENET_H


#include "server.h"
#include "enet/enet.h"


namespace Net {

/**
 * Servidor de red implementado mediante la librer�a eNet
 */
class CServerENet: public CServer {

public:

	/**
	 * Constructor
	 */ 
	CServerENet();

	/**
	 * Destructor
	 */
	virtual ~CServerENet();

	/**
	 * Inicializa el servidor escuchando en un puerto determinado.
	 * @param port es el puerto donde se escucha
	 * @param clients es el n�mero m�ximo de clientes. El m�ximo ser� establecido por la implementaci�n.
	 * @param maxinbw Ancho de banda de entrada m�ximo en bytes/segundo (0 = ilimitado)
	 * @param maxoutbw Ancho de banda de salida m�ximo en bytes/segundo (0 = ilimitado)
	 */
	bool init(int port, int clients, unsigned int maxinbw = 0, unsigned int maxoutbw = 0);
	
	/**
	 * Refresca el servidor obteniendo todos los paquetes recibidos despu�s de la �ltima llamada a este m�todo
	 * IMPORTANTE: Es responsabilidad del invocador de service() borrar los paquetes recibidos
	 * @param paquetesRecibidos Vector de CPaquete* donde se almacenan los paquetes recibidos
	 */
	void service(std::vector<CPacket*>& packets);

	/**
	 * Libera los recursos ocupados por este cliente.
	 * Es responsabilidad de este m�todo desconectar todas las conexiones en este punto.
	 */ 
	void release();
	
	/**
	 * Devuelve una lista de las conexiones creadas 
	 */
	std::vector<CConnection*>::iterator getConnectionsIt();

	/**
	 * Env�a datos a trav�s de una conexi�n.
	 * @param connection por la que enviar los datos
	 * @param data son los datos a enviar
	 * @param longData tama�o de los datos a enviar
	 * @param channel canal l�gico por el que se enviar�n los datos
	 * @param reliable indica si el cliente debe comprobar que los datos han sido recibidos por la m�quina remota
	 */
	void sendData(CConnection* connection, void* data, size_t longData, int channel, bool reliable);

	/**
	 * Env�a el mismo dato a todos los clientes conectados
	 * @param data son los datos a enviar
	 * @param longData tama�o de los datos a enviar
	 * @param channel canal l�gico por el que se enviar�n los datos
	 * @param reliable indica si el cliente debe comprobar que los datos han sido recibidos por la m�quina remota
	 */
	void sendAll(void* data, size_t longData, int channel, bool reliable);

	/**
	 * Desconecta la conexi�n indicada.
	 */
	void disconnect(CConnection * connection);

	/**
	 * Indica si el cliente tiene alguna conexi�n activa.
	 */
	bool isConnected();

	/**
	 * Indica si el cliente est� inicializado
	 */
	bool isInitialized();

private:

	enum ServerState{
		NO_INIT,
		INIT_NOT_CONNECTED,
		INIT_AND_CONNECTED
	};

	void disconnectAll();

	void disconnectReceived(CConnection* connection);
	
	ServerState state;

	std::vector<CConnection*> connections;

	ENetHost* server;
};

} // namespace Net

#endif // __SERVER_H

//---------------------------------------------------------------------------
// packet.h
//---------------------------------------------------------------------------

/**
 * @file packet.h
 *
 * Representaci�n de los datos transmitidos por red
 *
 *
 * @author Juan A. Recio-Garc�a, David Llans�
 * @date Octumbre, 2006
 */

#ifndef __PACKET_H
#define __PACKET_H

#include "connection.h"

namespace Net {

	/**
	 * Los paquetes manejar�n bytes
	 */
	typedef unsigned char byte;

	/**
	 * Identificador de paquetes
	 */
    enum EPacketType{
		DATA,
		CONNECTION,
		DISCONNECTION,
		CONTROL
	};

/**
 * Clase que representa de los datos transmitidos por red
 */
class CPacket {

public:

	/**
	 * Constructora. Crea un paquete de datos.
	 * @param type del paquete
	 * @param data es el contenido del paquete
	 * @param dataLength es el tama�o de los datos (data)
	 * @param connection es la conexi�n por la que se transmiten
	 * @param channel es el canal por el que se transmiten
	 */
	CPacket(EPacketType type, byte* data, size_t dataLength, CConnection* connection, unsigned char channel);

	/**
	 * Destructura
	 */
	~CPacket();

	/**
	 * Obtener los datos
	 */
	byte* getData();

	/**
	 * Establecer el contenido del paquete
	 */
	void setData(byte* data, size_t length);

	/**
	 * Obtener el tama�o de los datos del paquete
	 */ 
	size_t getDataLength();

	/**
	 * Obtener el tipo de los datos
	 */
	EPacketType getType();

	/**
	 * Establecer el tipo de los datos
	 */
	void setType(EPacketType type);

	/**
	 * Establecer la conexi�n que transmite los datos
	 */ 
	void setConnection(CConnection* connection);

	/**
	 * Obtener la conexi�n que transmite los datos
	 */ 
	CConnection* getConnection();

	/**
	 * Establecer el canal que transmite los datos
	 */ 
	void setChannel(unsigned char channel);

	/**
	 * Obtener el canal que transmite los datos
	 */ 
	unsigned char getChannel();

protected:
	unsigned char _channel;
	size_t _dataLength;
	byte* _data;
	EPacketType _packetType;
	CConnection* _connection;

};


} //namespace Net

#endif
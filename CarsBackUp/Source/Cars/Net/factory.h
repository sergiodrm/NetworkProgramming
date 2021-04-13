//---------------------------------------------------------------------------
// factory.h
//---------------------------------------------------------------------------

/**
 * @file factoriared.h
 *
 * Especifica una factoria (abstracta) de objetos de red
 *
 *
 * @author Juan A. Recio-Garc�a, David Llans�
 * @date Octumbre, 2006
 */

#ifndef __FACTORY_H
#define __FACTORY_H

#include "server.h"
#include "client.h"

namespace Net {

/**
 * Factor�a para obtener el servidor y cliente de red
 */
class CFactory {

public:
	virtual ~CFactory() {}
	/**
	 * Obtiene un servidor
	 */
	virtual CServer* buildServer()=0;

	/**
	 * Obtiene un cliente
	 */
	virtual CClient*  buildClient()=0;
};


} //namespace Net

#endif
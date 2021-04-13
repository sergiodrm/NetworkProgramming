//---------------------------------------------------------------------------
// factoryenet.h
//---------------------------------------------------------------------------

/**
 * @file factoryenet.h
 *
 * Especifica una factoria de objetos de red implementados con ENet
 *
 *
 * @author Juan A. Recio-Garc�a, David Llans�
 * @date Octumbre, 2006
 */

#ifndef __FACTORYENET_H
#define __FACTORYENET_H

#include "serverenet.h"
#include "clientENet.h"
#include "factory.h"

namespace Net {

/**
 * Factor�a para obtener el servidor y cliente de red implementados con la librer�a ENet
 */
class CFactoryEnet: public CFactory {

public:

	CFactoryEnet() {};

	CServer* buildServer();


	CClient*  buildClient();

};



CServer* CFactoryEnet::buildServer()
{
	return new CServerENet();
}

CClient* CFactoryEnet::buildClient()
{
	return new CClientENet();
}


} //namespace Net

#endif
/*
 *  Copyright 2013 Juha Lepola
 *
 *  This file is part of M-Files for Sailfish.
 *
 *  M-Files for Sailfish is free software: you can redistribute it
 *  and/or modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation, either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  M-Files for Sailfish is distributed in the hope that it will be
 *  useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with M-Files for Sailfish. If not, see
 *  <http://www.gnu.org/licenses/>.
 */

#ifndef VALUELISTFRONT_H
#define VALUELISTFRONT_H

#include <QJsonArray>
#include <QObject>

#include "frontbase.h"
#include "objecttypecache.h"
#include "valuelistcore.h"

// Forward declarations.
class VaultCore;

class ValueListFront : public FrontBase
{
	Q_OBJECT
	Q_ENUMS( Status )
	Q_PROPERTY( Status status READ status NOTIFY statusChanged )
public:

	enum Status
	{
		Disconnected,  //!< The value list does not have a connection to the core.
		Empty,  //!< The value list is empty.
		Searching,  //!< A new values are being searched for the value list. Old values are still available.
		Ready  //!< The value list is ready and no operations are running.
	};

	//! Initializes new value list front.
	explicit ValueListFront(
		VaultCore* vault,  //!< Vault.
		ValueListCore* core  //!< Core
	);

	//! Value list items.
	Q_INVOKABLE QJsonArray items();

	//! Status.
	Status status();

signals:

	//! Signaled when the status of the value list has changed.
	void statusChanged();

public slots:

// Protected interface.
protected:

	//! Does this front accept the specified core.
	virtual bool accept( QObject* core ) const;

// Private interface.
private:

	//! Value list core.
	ValueListCore* valueList() { return qobject_cast< ValueListCore* >( this->core() ); }

// Private data.
private:

	int m_id;  //!< The id this value list represents.
	int m_propertyDefinition;  //!< The property definition this value list is filtered with.
	VaultCore* m_vault;		

};

#endif // VALUELISTFRONT_H

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

#ifndef MFWSREQUEST_H
#define MFWSREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonValue>

// Forward declaration.
class QNetworkReply;

class MfwsRest : public QObject
{
	Q_OBJECT
public:

	//! Constructor.
	explicit MfwsRest(
		const QString& url,
		QObject *parent = 0
	);

	//! Destructor.
	virtual ~MfwsRest();
	
	//! Gets resources. The response if submitted to the given slot.
	QNetworkReply* getJson(
		QString& resource  //!< The name of the resource.
	) const;

signals:

	//! Signaled when error occurs in the prosessing of the request.
	void error( const QString& description );
	
public slots:
	
	//! Sets the authentication information.
	void setAuthentication( const QString& authentication ) { m_authentication = authentication; }

// Private data.
private:

	QString m_url;
	QString m_authentication;
	QNetworkAccessManager* m_network;
};

#endif // MFWSREQUEST_H
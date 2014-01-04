#ifndef COREBASE_H
#define COREBASE_H

#include <QObject>

// Forward declarations.
class MfwsRest;
class VaultCore;

class CoreBase : public QObject
{
	Q_OBJECT
public:

	//! State of the core.
	enum State
	{
		Initializing,  //! The core is still being initialized.
		Initialized  //!< The core has been initialized.
	};

	//! Initializes new core base.
	explicit CoreBase( VaultCore* owner );

	//! Initializes new core base.
	explicit CoreBase( VaultCore* owner, QObject* parent );

	//! Is this core initializaed.
	bool isInitialized() { return m_state == Initialized; }

signals:

	//! Signaled when the core becomes initialized.
	void initialized();

public slots:

	//! Initializes the core. Must be called from the thread that owns the core.
	void initializeBase( QObject* parent );

// Protected interface.
protected:

	//! Accesses the vault.
	VaultCore* vault() { return m_vault; }

	//! Accesses the MFWS REST API.
	MfwsRest* rest();

// Private data.
private:

	VaultCore* m_vault;  //! Vault.
	MfwsRest* m_rest;  //!< Access to M-Files REST API.
	State m_state;  //!< The state of the core.

};

#endif // COREBASE_H
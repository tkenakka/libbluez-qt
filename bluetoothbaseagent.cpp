#include "bluetoothbaseagent.h"

#include "agentadaptor.h"
#include "bluemanager.h"
#include "blueadapter.h"
#include <QTimer>

BluetoothBaseAgent::BluetoothBaseAgent(QString path, QObject *parent):QObject(parent),requestAccepted(false)
{
	new AgentAdaptor(this);
	QDBusConnection::systemBus().registerObject(path,this);

	OrgBluezManagerInterface manager(
			"org.bluez",
			"/", QDBusConnection::systemBus());

	QDBusObjectPath adapterpath = manager.DefaultAdapter();

	OrgBluezAdapterInterface adapter(
			"org.bluez",
			adapterpath.path(),
			QDBusConnection::systemBus());

	adapter.RegisterAgent(QDBusObjectPath("/pairing/agent"),"");

	qDebug()<<"last error: "<<adapter.lastError().message();

}

void BluetoothBaseAgent::authorize(OrgBluezDeviceInterface &device, QString uuid)
{
	Q_UNUSED(uuid);
	Q_UNUSED(device);
	qDebug("authorize");
}

void BluetoothBaseAgent::confirmModeChange(QString mode)
{
	qDebug()<<"mode changed "<<mode;
}

void BluetoothBaseAgent::displayPasskey(OrgBluezDeviceInterface &device, uint key)
{
	qDebug()<<"display key "<<device.path()<<" "<<key;
}

void BluetoothBaseAgent::release()
{
	qDebug("release called");
}

void BluetoothBaseAgent::requestConfirmation(OrgBluezDeviceInterface &device, uint key)
{
	QVariantMap props = device.GetProperties();

	QString alias = props["Alias"].toString();

	qDebug()<<"Pairing with "<< alias << " with key: "+QString::number(key);
}

uint BluetoothBaseAgent::requestPasskey(OrgBluezDeviceInterface &device)
{
	Q_UNUSED(device);
	qDebug("requestKey");
	return 0;
}

QString BluetoothBaseAgent::requestPidCode(OrgBluezDeviceInterface &device)
{
	Q_UNUSED(device);
	return "";
}

void BluetoothBaseAgent::accept()
{
	requestAccepted = true;
}

void BluetoothBaseAgent::doReject()
{
	if(requestAccepted)
	{
		requestAccepted=false;
		return;
	}
	reject();
}

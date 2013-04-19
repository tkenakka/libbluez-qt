/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#include <nearbydevicesmodel.h>
#include <bluetoothdevice.h>
#include <bluetoothdevicemodel.h>

#include <QObject>

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtQml/QQmlExtensionPlugin>
#include <QtQml/qqml.h>
#else
#include <QtDeclarative/qdeclarative.h>
#include <QtDeclarative/QDeclarativeExtensionPlugin>
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
class Components : public QQmlExtensionPlugin
#else
class Components : public QDeclarativeExtensionPlugin
#endif
{
    Q_OBJECT
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    Q_PLUGIN_METADATA(IID "org.nemo.bluez-qt5")
#endif

public:
    void registerTypes(const char *uri)
    {
        qmlRegisterType<NearbyDevicesModel>(uri,0,0,"NearbyDevicesModel");
        qmlRegisterType<BluetoothDevice>(uri,0,0,"BluetoothDevice");
        qmlRegisterType<BluetoothDevicesModel>(uri,0,0,"BluetoothDevicesModel");
    }
};

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
Q_EXPORT_PLUGIN(Components);
#endif

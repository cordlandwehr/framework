/* * This file is part of meego-im-framework *
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 * Contact: Nokia Corporation (directui@nokia.com)
 *
 * If you have questions regarding the use of this file, please contact
 * Nokia at directui@nokia.com.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */

#ifndef MALIIT_SERVER_DBUS_SERVERDBUSADDRESS_H
#define MALIIT_SERVER_DBUS_SERVERDBUSADDRESS_H

#include <QObject>
#include <QString>

struct DBusServer;

namespace Maliit {
namespace Server {
namespace DBus {

class AddressPublisher : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.maliit.Server.Address")

    Q_PROPERTY(QString address READ address)

public:
    explicit AddressPublisher(const QString &address);
    ~AddressPublisher();
    QString address() const;

private:
    const QString mAddress;
};

class Address
{
public:
    explicit Address();
    ~Address();

    virtual DBusServer* connect() = 0;
};

class DynamicAddress : public Address
{

public:
    explicit DynamicAddress();

    //! reimpl
    virtual DBusServer* connect();

private:
    QScopedPointer<AddressPublisher> publisher;
};

class FixedAddress : public Address
{

public:
    explicit FixedAddress(const QString &address);

    //! reimpl
    virtual DBusServer* connect();

private:
    QString mAddress;
};

} // namespace DBus
} // namespace Server
} // namespace Maliit

#endif // MALIIT_SERVER_DBUS_SERVERDBUSADDRESS_H
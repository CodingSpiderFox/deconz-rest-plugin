/*
 * Copyright (c) 2016 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */

#ifndef BINDINGS_H
#define BINDINGS_H

/*! \class Binding

    Represents a ZigBee ZDO Binding.
 */
class Binding
{
public:
    enum Constans
    {
        GroupAddressMode = 0x01,
        ExtendedAddressMode = 0x03
    };

    Binding();
    bool operator==(const Binding &rhs) const;
    bool operator!=(const Binding &rhs) const;
    /*! The source IEEE address. */
    quint64 srcAddress;
    /*! The source endpoint. */
    quint8 srcEndpoint;
    /*! The cluster on the source device that is bound to the destination device. */
    quint16 clusterId;
    /*! The addressing mode for the destination address.
        0x01 = 16-bit group address (no endpoint)
        0x03 = 64-bit extended address + endpoint
     */
    quint8 dstAddrMode;
    union
    {
        quint16 group; //!< The destination group address (if dstAddrMode = 0x01).
        quint64 ext; //!< The destination extended address (if dstAddrMode = 0x03).
    } dstAddress;
    /*! Destination endpoint (if dstAddrMode = 0x03). */
    quint8 dstEndpoint;

    bool readFromStream(QDataStream &stream);
    bool writeToStream(QDataStream &stream) const;
};

#endif // BINDINGS_H

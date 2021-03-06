/// Copyright 2010-2012 4kdownload.com (developers@4kdownload.com)
/**
    This file is part of 4k Download.

    4k Download is free software; you can redistribute it and/or modify
    it under the terms of the one of two licenses as you choose:

    1. GNU GENERAL PUBLIC LICENSE Version 3
    (See file COPYING.GPLv3 for details).

    2. 4k Download Commercial License
    (Send request to developers@4kdownload.com for details).
   
*/


#ifndef COMBOBOXBINDING_H
#define COMBOBOXBINDING_H

#include <QObject>
#include <QComboBox>
#include "componentmodel/binding/binding.h"

namespace Bindings
{

// Information: fake properties "items" and "icons" needed only for correct binding

class ComboboxBinding : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList items READ items WRITE setItems)
    Q_PROPERTY(QList<QIcon> icons READ icons WRITE setIcons)

public:
    ComboboxBinding(QComboBox* combobox, QObject* srcObject,
                    const QString& itemsProperty, const QString& indexProperty,
                    const QString& iconsProperty = QString(), QObject* parent = 0);

protected:
    QStringList items() const;
    void setItems(QStringList value);
    QList<QIcon> icons() const;
    void setIcons(QList<QIcon> value);
    bool updateItems() const;

private:
    QComboBox* m_combobox;
    QObject* m_srcObject;
    QString m_itemsProperty;
    QString m_iconsProperty;
    QSharedPointer<Binding> m_itemsBinding;
    QSharedPointer<Binding> m_iconsBinding;
    QSharedPointer<Binding> m_indexBinding;
};

} // Bindings

#endif // COMBOBOXBINDING_H

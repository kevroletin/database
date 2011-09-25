#include "picturedelegate.h"

PictureDelegate::PictureDelegate(QObject *parent) :
    QSqlRelationalDelegate(parent)
{
}


void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
    //if (qVariantCanConvert<QByteArray>(index.data())) {
    if (index.column() == 4) {
        QImage image;
//        image.load("/home/behemoth/Work/MetalDatabase/bullet_dn.png", "PNG");
        image.loadFromData(index.data().toByteArray(), "PNG");
        painter->drawImage(option.rect, image);
    } else {
        QSqlRelationalDelegate::paint(painter, option, index);
    }
}


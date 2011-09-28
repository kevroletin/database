#include "picturedelegate.h"

PictureDelegate::PictureDelegate(QSet<int> _colomnsToDraw_, QObject *parent) :
    QSqlRelationalDelegate(parent),
    colomnsToDraw(_colomnsToDraw_)
{
}


void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
    if (colomnsToDraw.contains(index.column())) {
        QImage image;
        image.loadFromData(index.data().toByteArray(), "PNG");
        painter->drawImage(option.rect, image);
    } else {
        QSqlRelationalDelegate::paint(painter, option, index);
    }
}


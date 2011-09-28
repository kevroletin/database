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
        double sy = double(option.rect.height()) / double(image.height());
        double sx = double(option.rect.width()) / double(image.width());
        QRect drawRect = option.rect;
        if (sx > sy) {
            double nx = double(image.width()) * sy;
            double dx = (drawRect.width() - nx) / 2;
            drawRect.setLeft(drawRect.left() + dx);
            drawRect.setRight(drawRect.right() - dx);
        } else {
            double ny = double(image.height()) * sx;
            double dy = (drawRect.height() - ny) / 2;
            drawRect.setTop(drawRect.top() + dy);
            drawRect.setBottom(drawRect.bottom() - dy);
        }
        painter->drawImage(drawRect, image);
    } else {
        QSqlRelationalDelegate::paint(painter, option, index);
    }
}


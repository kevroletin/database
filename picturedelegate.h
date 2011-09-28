#ifndef PICTUREDELEGATE_H
#define PICTUREDELEGATE_H

#include <QSqlRelationalDelegate>

QT_BEGIN_NAMESPACE
class QPainter;
QT_END_NAMESPACE

class PictureDelegate : public QSqlRelationalDelegate
{
    Q_OBJECT
public:
    explicit PictureDelegate(QSet<int> colomnsToDraw, QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

protected:
    QSet<int> colomnsToDraw;

signals:

public slots:

};

#endif // PICTUREDELEGATE_H

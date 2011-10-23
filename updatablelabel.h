#ifndef UPDATABLELABEL_H
#define UPDATABLELABEL_H

#include <QLabel>
#include <QtGui>

class UpdatableLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QByteArray pictureByteArr READ GetPicture WRITE SetPicture)

public:

    QByteArray GetPicture() { return pictureByteArr; }
    void SetPicture(QByteArray newPicture) {
        pictureByteArr = newPicture;
        QPixmap pix;
        pix.loadFromData(pictureByteArr, "PNG");
        setPixmap(pix);
    }

protected:
    QByteArray pictureByteArr;

signals:

public slots:
    void LoadPicture() {
        QString fileName = QFileDialog::getOpenFileName();
        QPixmap pix;
        if (pix.load(fileName)) {
            QBuffer buff;
            pix.scaled(QSize(200, 200), Qt::KeepAspectRatio).save(&buff, "PNG");
            pictureByteArr = buff.data();
            setPixmap(pix);
        }
    }
    bool SavePicture(QString) { /* TODO: */ return 0; }
};

#endif // UPDATABLELABEL_H

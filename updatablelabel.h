#ifndef UPDATABLELABEL_H
#define UPDATABLELABEL_H

#include <QLabel>
#include <QtGui>

class UpdatableLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QByteArray pictureByteArr READ GetPicture WRITE SetPicture)

public:
    explicit UpdatableLabel(QWidget *parent = 0);

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
        pix.load(fileName);
        QBuffer buff;
        pix.save(&buff, "PNG");
        pictureByteArr = buff.data();
        setPixmap(pix);
    }
    bool SavePicture(QString filename = "") {
        // TOOD:
        return 0;
    }
};

#endif // UPDATABLELABEL_H

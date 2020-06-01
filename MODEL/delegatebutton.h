#ifndef DELEGATEBUTTON_H
#define DELEGATEBUTTON_H
#include <QItemDelegate>
#include <QAbstractItemModel>
#include <QEvent>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QList>
#include <QString>
#include <QPainter>
#include <QApplication>

class DelegateButton : public QItemDelegate {
 Q_OBJECT
public:
    DelegateButton(QIcon title, QObject *parent=nullptr);
    void paint(QPainter*,const QStyleOptionViewItem& , const QModelIndex&) const override;
    bool editorEvent(QEvent*, QAbstractItemModel*, const QStyleOptionViewItem &, const QModelIndex &) override;
    ~DelegateButton() override;
private:
    QIcon TitleButton;
protected:
    typedef QMap<QModelIndex, QStyleOptionButton*> ButtonDestroy;
    ButtonDestroy BTNElement;
signals:
    void TableButtonPressed(int);
};

#endif // DELEGATEBUTTON_H

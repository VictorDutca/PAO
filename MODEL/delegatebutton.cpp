#include "delegatebutton.h"

DelegateButton::DelegateButton(QString _TitleButton, QObject *parent)
    : QItemDelegate (parent), TitleButton(_TitleButton)
{

}

void DelegateButton::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    QStyleOptionButton* button = BTNElement.value(index);
    if (!button) {
        button = new QStyleOptionButton();
        button->text = TitleButton;
        button->state |= QStyle::State_Enabled;
        (const_cast<DelegateButton *>(this))->BTNElement.insert(index, button);
    }

    button->rect = option.rect.adjusted(4, 4, -(option.rect.width() / 2 + 4) , -4);
    painter->save();

    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    painter->restore();
    QApplication::style()->drawControl(QStyle::CE_PushButton, button, painter);

}

bool DelegateButton::editorEvent(
        QEvent *event, QAbstractItemModel *model,
        const QStyleOptionViewItem &option,
        const QModelIndex &index)
{
    Q_UNUSED(option);
    Q_UNUSED(model);
    if(event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(BTNElement.contains(index)) {
            QStyleOptionButton* btns = BTNElement.value(index);
            if (btns->rect.contains(e->x(), e->y())) {
                btns->state |= QStyle::State_Sunken;
            }
        }
    }

    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if (BTNElement.contains(index)) {
            QStyleOptionButton* btns = BTNElement.value(index);
            if (btns->rect.contains(e->x(), e->y())) {
                btns->state &= (~QStyle::State_Sunken);
//AHAHAHA
                emit TableButtonPressed(index.row());
            }
        }
    }
    return true;
}

DelegateButton::~DelegateButton() {
   /**/
}

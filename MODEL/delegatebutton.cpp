#include "delegatebutton.h"

DelegateButton::DelegateButton(QIcon _TitleButton, QObject *parent)
    : QItemDelegate (parent), TitleButton(_TitleButton){}

void DelegateButton::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    QStyleOptionButton* button = BTNElement.value(index);
    if (!button) {
        button = new QStyleOptionButton();
        button->icon = TitleButton;
        QBrush tb(Qt::white);
        button->palette = QPalette(tb, tb, tb, tb, tb, tb, tb, tb, tb);
        button->iconSize = QSize(25,25) ;
        button->state |= QStyle::State_Enabled;
        (const_cast<DelegateButton *>(this))->BTNElement.insert(index, button);
    }

    button->rect = option.rect.adjusted(10, 4, -120 , -3);
    painter->save();

    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    painter->restore();
    QApplication::style()->drawControl(QStyle::CE_PushButtonLabel, button, painter);

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
                emit TableButtonPressed(index.row());
            }
        }
    }
    return true;
}

DelegateButton::~DelegateButton() {
    /**/
}

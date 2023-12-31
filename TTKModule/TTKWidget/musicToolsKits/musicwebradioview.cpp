#include "musicwebradioview.h"
#include "musicrightareawidget.h"
#include "musicwebfmradioplaywidget.h"
#include "musicttkfmradioplaywidget.h"
#include "musicimageutils.h"

#define ICON_SIZE       50

MusicWebFMRadioWidget::MusicWebFMRadioWidget(QWidget *parent)
    : MusicAbstractTableWidget(parent),
      m_radio(nullptr)
{
    setIconSize(QSize(ICON_SIZE, ICON_SIZE));
    setColumnCount(4);

    QHeaderView *headerview = horizontalHeader();
    headerview->resizeSection(0, 10);
    headerview->resizeSection(1, ICON_SIZE + 20);
    headerview->resizeSection(2, 157);
    headerview->resizeSection(3, 82);

    TTK::Widget::setTransparent(this, 0);
    verticalScrollBar()->setStyleSheet(TTK::UI::ScrollBarStyle03);

    connect(this, SIGNAL(cellDoubleClicked(int,int)), SLOT(itemDoubleClicked(int,int)));

    addListWidgetItem();
}

MusicWebFMRadioWidget::~MusicWebFMRadioWidget()
{
    delete m_radio;
}

void MusicWebFMRadioWidget::itemCellEntered(int row, int column)
{
    QTableWidgetItem *it = item(m_previousColorRow, 3);
    if(it)
    {
        it->setIcon(QIcon());
    }

    if(it = item(row, 3))
    {
        it->setIcon(QIcon(":/contextMenu/btn_play"));
    }

    if(column == 3)
    {
        setCursor(QCursor(Qt::PointingHandCursor));
    }
    else
    {
        unsetCursor();
    }

    MusicAbstractTableWidget::itemCellEntered(row, column);
}

void MusicWebFMRadioWidget::itemCellClicked(int row, int column)
{
    Q_UNUSED(row);
    if(column == 3)
    {
        itemDoubleClicked(row, TTK_NORMAL_LEVEL);
    }
}

void MusicWebFMRadioWidget::itemDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    switch(row)
    {
        case 0:
        {
            delete m_radio;
            MusicWebFMRadioPlayWidget *w = new MusicWebFMRadioPlayWidget(this);
            m_radio = w;
            w->show();
            break;
        }
        case 1:
        {
            delete m_radio;
            MusicTTKFMRadioPlayWidget *w = new MusicTTKFMRadioPlayWidget(this);
            m_radio = w;
            w->show();
            break;
        }
        case 2:
        {
            MusicRightAreaWidget::instance()->functionClicked(MusicRightAreaWidget::WebDJRadioWidget);
            break;
        }
        case 3:
        {
            MusicRightAreaWidget::instance()->functionClicked(MusicRightAreaWidget::WebMVRadioWidget);
            break;
        }
        default: break;
    }
}

void MusicWebFMRadioWidget::addListWidgetItem()
{
    struct ToolItem
    {
        QString m_icon;
        QString m_name;

        ToolItem() = default;
        ToolItem(const QString &icon, const QString &name)
        {
            m_icon = icon;
            m_name = name;
        }
    };
    TTK_DECLARE_LIST(ToolItem);

    ToolItemList pairs;
    pairs << ToolItem(":/radio/lb_fm", tr("FMRadio"))
          << ToolItem(":/radio/lb_tk", tr("TKRadio"))
          << ToolItem(":/radio/lb_dj", tr("DJRadio"))
          << ToolItem(":/radio/lb_mv", tr("MVRadio"));

    for(const ToolItem &pair : qAsConst(pairs))
    {
        const int index = rowCount();
        setRowCount(index + 1);
        setRowHeight(index, TTK_ITEM_SIZE_XL);

        QTableWidgetItem *item = new QTableWidgetItem;
        setItem(index, 0, item);

                          item = new QTableWidgetItem;
        item->setIcon(TTK::Image::roundedPixmap(QPixmap(pair.m_icon), QPixmap(":/image/lb_mask_50"), iconSize()));
        setItem(index, 1, item);

                          item = new QTableWidgetItem;
        item->setText(pair.m_name);
        item->setForeground(QColor(TTK::UI::Color02));
        QtItemSetTextAlignment(item, Qt::AlignLeft | Qt::AlignVCenter);
        setItem(index, 2, item);

                          item = new QTableWidgetItem;
        setItem(index, 3, item);
    }
}

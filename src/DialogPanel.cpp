#include "DialogPanel.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "BasePropertyDialog.h"

DialogPanel::DialogPanel(QWidget *parent)
    : QFrame(parent)
{
    setMinimumWidth(256);
    // top-level layout
    m_topLayout = new QVBoxLayout;
    m_topLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_topLayout);
    // subframe
    m_headPanel = new QFrame;
    m_topLayout->addWidget(m_headPanel, 0, Qt::AlignTop);
    m_topLayout->addStretch(1);

    m_btnHelp = new QPushButton("(?)");
    m_btnCancel = new QPushButton("[X]");
    m_btnOK = new QPushButton("[OK]");

    QHBoxLayout *bttns = new QHBoxLayout;
    bttns->setContentsMargins(0, 0, 0, 0);
    m_headPanel->setLayout(bttns);
    bttns->addWidget(m_btnHelp);
    bttns->addStretch(1);
    bttns->addWidget(m_btnCancel);
    bttns->addWidget(m_btnOK);

    connect(m_btnHelp, &QPushButton::clicked, this, &DialogPanel::onPushHelp);
    connect(m_btnCancel, &QPushButton::clicked, this, &DialogPanel::onPushCancel);
    connect(m_btnOK, &QPushButton::clicked, this, &DialogPanel::onPushOK);

    m_headPanel->setVisible(false);
}

void DialogPanel::setDialog(BasePropertyDialog *dialog)
{
    if (m_status) return;    // You can add only 1 dialog (TODO)
    m_activeWidget = dialog;
    m_headPanel->setVisible(true);
    m_topLayout->insertWidget(position, dialog, 0, Qt::AlignTop);
    m_status = true;
    connect(m_btnOK, &QPushButton::clicked, dialog, &BasePropertyDialog::accept);
    connect(m_btnCancel, &QPushButton::clicked, dialog, &BasePropertyDialog::cancel);
}

void DialogPanel::closeDialog()
{
    m_topLayout->removeWidget(m_activeWidget);
    m_activeWidget->deleteLater();
    m_headPanel->setVisible(false);
    m_status = false;   // Now a new dialog can be added
}

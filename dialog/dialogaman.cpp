#include "dialogaman.h"
#include "ui_dialogaman.h"

DialogAman::DialogAman(ATCAirspace *airspace, QWidget *parent) :
    ATCDialog(parent, "Approach Manager", 700, 900),
    airspace(airspace),
    uiInner(new Ui::DialogAman)
{
    uiInner->setupUi(this);
    windowSetup();

    createLineEdit();
}

DialogAman::~DialogAman()
{
    if(lineEditMeteringFix != nullptr) delete lineEditMeteringFix;

    delete uiInner;
}

void DialogAman::on_buttonMeteringFix_clicked()
{
    uiInner->buttonMeteringFix->hide();

    lineEditMeteringFix->setText(uiInner->buttonMeteringFix->text());
    lineEditMeteringFix->show();

    connect(lineEditMeteringFix, SIGNAL(returnPressed()), this, SLOT(slotMeteringFixEntered()));
}

void DialogAman::slotMeteringFixEntered()
{
    QString name = lineEditMeteringFix->text();

    if(!airspace->isValidNavaid(name))
    {
        lineEditMeteringFix->setStyleSheet("QLineEdit"
                                           "{"
                                           "    color: #ff0000;"
                                           "    background-color: #00153a;"
                                           "    border-style: inset;"
                                           "    border-width: 2px;"
                                           "    border-color: #3e3e3e;"
                                           "    font: 14px;"
                                           "}"
                                          );
        return;
    }

    lineEditMeteringFix->hide();

    uiInner->buttonMeteringFix->setText(name);
    uiInner->buttonMeteringFix->show();
}

void DialogAman::createLineEdit()
{
    lineEditMeteringFix = new QLineEdit(this);
    lineEditMeteringFix->setGeometry(290, 875, 120, 25);
    lineEditMeteringFix->setAlignment(Qt::AlignHCenter);
    lineEditMeteringFix->setInputMask(">nnnnn");
    lineEditMeteringFix->hide();
    lineEditMeteringFix->setStyleSheet("QLineEdit"
                                       "{"
                                       "    color: #c8c8c8;"
                                       "    background-color: #00153a;"
                                       "    border-style: inset;"
                                       "    border-width: 2px;"
                                       "    border-color: #3e3e3e;"
                                       "    font: 14px;"
                                       "}"
                                       );
}

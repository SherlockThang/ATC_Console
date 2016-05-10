#include "atcdialog.h"
#include "ui_atcdialog.h"

#include <QMouseEvent>
#include <QCursor>

ATCDialog::ATCDialog(QWidget *parent, QString title, unsigned int width,
                     unsigned int height, bool deleteOnClose) :
    QDialog(parent),
    ui(new Ui::ATCDialog),
    windowTitle(title),
    windowWidth(width),
    windowHeight(height),
    flagDeleteOnClose(deleteOnClose)
{
    ui->setupUi(this);
}

ATCDialog::~ATCDialog()
{
    delete ui;
}

void ATCDialog::maximizeWindow()
{
    ui->buttonMinMax->setText(QString::fromUtf8("▲"));
    flagMaximized = true;
    resize(windowWidth, windowHeight);
    ui->frameDialog->resize(windowWidth, windowHeight);
}

void ATCDialog::minimizeWindow()
{
    ui->buttonMinMax->setText(QString::fromUtf8("▼"));
    flagMaximized = false;
    resize(windowWidth, 30);
    ui->frameDialog->resize(windowWidth, 30);
}

bool ATCDialog::isMaximized()
{
    if(flagMaximized)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ATCDialog::isMouseOnTitleBar(QPoint mousePosition)
{
    QPoint topLeftInGlobal = QWidget::mapToGlobal(this->rect().topLeft());
    QPoint topRightInGlobal = QWidget::mapToGlobal(this->rect().topRight());

    if((mousePosition.x() >= topLeftInGlobal.x())
            && (mousePosition.x() <= topRightInGlobal.x())
            && (mousePosition.y() >= topLeftInGlobal.y())
            && (mousePosition.y() <= (topLeftInGlobal.y() + 30)))
    {
        return true;
    }
    else
        return false;
}

QPoint ATCDialog::getMouseEventPosition()
{
    return QCursor::pos();
}

void ATCDialog::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
    this->raise();

    if(isMouseOnTitleBar(getMouseEventPosition()))
    {
        setFlagClickedOnTitleBar(true);
    }

    if(event->button() == Qt::LeftButton)
    {
        setMouseDragPosition(event);
        event->accept();
    }
}

void ATCDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(getFlagStdButtonPressed() || !getFlagClickedOnTitleBar())
    {
        event->ignore();
    }
    else
    {
        if(event->buttons() & Qt::LeftButton)
        {
            move(event->globalPos() - getMouseDragPosition());
            event->accept();
        }
        else
            event->ignore();
    }
}

void ATCDialog::mouseReleaseEvent(QMouseEvent *event)
{
    setFlagStdButtonPressed(false);
    setFlagClickedOnTitleBar(false);
    event->accept();
}

void ATCDialog::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(isMouseOnTitleBar(getMouseEventPosition()))
    {
        if(isMaximized())
        {
            minimizeWindow();
        }
        else
        {
            maximizeWindow();
        }
        event->accept();
    }
    else
        event->ignore();
}

void ATCDialog::windowSetup()
{
    if(flagDeleteOnClose)
        this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowFlags(Qt::FramelessWindowHint);

    this->resize(windowWidth, windowHeight);
    ui->frameDialog->resize(windowWidth, windowHeight);
    ui->frameTitleBar->resize(windowWidth, 30);

    ui->labelTitle->setGeometry(10, 0, windowWidth/2, 30);
    ui->labelTitle->setText(windowTitle);

    ui->buttonMinMax->move(windowWidth - 50, 5);
    ui->buttonClose->move(windowWidth - 30, 5);
}

void ATCDialog::setMouseDragPosition(QMouseEvent *event)
{
    mouseDragPosition = event->globalPos() - frameGeometry().topLeft();
}

void ATCDialog::setFlagMaximized(bool flagBool)
{
    flagMaximized = flagBool;
}

void ATCDialog::setFlagClickedOnTitleBar(bool flagBool)
{
    flagClickedOnTitleBar = flagBool;
}

void ATCDialog::setFlagStdButtonPressed(bool flagBool)
{
    flagStdButtonPressed = flagBool;
}

bool ATCDialog::getFlagStdButtonPressed()
{
    return flagStdButtonPressed;
}

bool ATCDialog::getFlagClickedOnTitleBar()
{
    return flagClickedOnTitleBar;
}

QPoint ATCDialog::getMouseDragPosition()
{
    return mouseDragPosition;
}

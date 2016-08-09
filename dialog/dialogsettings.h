#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include "dialogcolorpicker.h"
#include "atcdialog.h"
#include "atcsituationaldisplay.h"
#include "atcsettings.h"

#include <QStandardItemModel>
#include <QFileDialog>
#include <QPalette>

namespace Ui {
class DialogSettings;
}

class DialogSettings : public ATCDialog
{
    Q_OBJECT

public:
    explicit DialogSettings(ATCSituationalDisplay *display, QWidget *parent = 0);
    ~DialogSettings();

private slots:
    ATC_MOUSE_HANDLER

    void slotColorPickerClosed();

    void slotUpdateTableColorARTCCLow(QColor color);
    void slotUpdateTableColorARTCCHigh(QColor color);
    void slotUpdateTableColorARTCC(QColor color);

    void onTableClicked(const QModelIndex &index);

    void on_buttonExportSettings_clicked();
    void on_buttonLoadSettings_clicked();
    void on_buttonSetDefault_clicked();

private:
    Ui::DialogSettings *uiInner;
    DialogColorPicker *dialogColorPicker = nullptr;
    ATCSituationalDisplay *situationalDisplay = nullptr;    
    QStandardItemModel *settingsModel = nullptr;

    bool flagDialogColorPickerExists = false;

    void setupTableView();
    void createSettingsModel();
    void connectSlots();
    void constructColorPicker(QColor &initColor);
    QList<QStandardItem *> createSettingsRow(QString text, QColor color);
};

#endif // DIALOGSETTINGS_H

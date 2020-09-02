/**
 * @file MainWindow.h
 * @brief Header file of the MainWindow class
 *
 * MainWindow GUI holds all PC <-> MCU communication modules
 * @author Farid Oubbati (https://github.com/faroub)
 * @date March 2020
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

namespace gui
{
class Setting;
class Console;
}
namespace io
{
class SerialPort;
}
namespace gui
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void about();

public:
    /** Constructor. Builds the MainWindow GUI
         *
         *  @param ap_applicationGUI defines pointer to application GUI
         */
    MainWindow();
    /** Destructor.
        */
    ~MainWindow();

    void enableConnectionAction(bool a_enable);

    void enableDisconnectionAction(bool a_enable);

    void enableSetSettingAction(bool a_enable);

    void showStatusMessage(const QString &a_message);

    void showErrorMessage(const QString &a_message, const QString &a_error);




protected:
    /** The event handler that receives the Main Window close event
        */
    void closeEvent(QCloseEvent *event) override;

private:

    /** user input condition for the Main Window close event
        */
    bool closeWindow();

    void setupActions();

    void setupMenuBar();

    void setupToolBar();


    Setting *mp_setting = nullptr;

    Console *mp_console = nullptr;

    io::SerialPort *mp_serialPort = nullptr;

    QLabel *mp_statusMessage = nullptr;

    QAction *mp_connectAction = nullptr;

    QAction *mp_disconnectAction = nullptr;

    QAction *mp_setSettingAction = nullptr;

    QAction *mp_setLocalEcho = nullptr;
    
    QAction *mp_clearConsoleAction = nullptr;



};
}

#endif

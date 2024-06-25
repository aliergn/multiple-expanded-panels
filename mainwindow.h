#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void animationTimerFunc();
    void on_pb_First_pressed();

    void on_pb_Second_pressed();

    void on_pb_Third_pressed();

private:
    Ui::MainWindow *ui;
    QTimer *animationTimer;
    int animationNumber;

};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_LogOp_currentIndexChanged(int index);

    void on_comboBox_OP1_currentIndexChanged( int index);

    void on_comboBox_OP2_currentIndexChanged( int index);

private:
    Ui::MainWindow *ui;
    void start_sys();
    void my_func();
    void my_func1();
    void my_func2();
    void my_func3();
    void if0();
    void if1();
};

#endif // MAINWINDOW_H

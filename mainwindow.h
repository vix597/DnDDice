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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void RollButtonPressed();
    void RollFourSided();
    void RollSixSided();
    void RollEightSided();

private:
    void RollAndDisplay(int sides,int count);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

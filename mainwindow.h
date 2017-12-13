#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0, bool isFull = false);
    ~MainWindow();
protected:
    void keyPressEvent( QKeyEvent *e );
private:
    bool m_fullscreen;
};

#endif // MAINWINDOW_H

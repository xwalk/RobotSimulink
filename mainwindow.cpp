#include "mainwindow.h"
#include "ICGLWidgit.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent, bool isFull)
    : QMainWindow(parent)
{
    m_fullscreen = isFull;  // 记录全屏
    resize(640, 480);
    setWindowTitle(tr("OpenGL"));
    if ( m_fullscreen )
    {
        showFullScreen();
    }
    setCentralWidget(new ICGLWidgit(this));
}

MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent( QKeyEvent *e )
{
    switch ( e->key() )
    {
    case Qt::Key_F2:
    {
        m_fullscreen = !m_fullscreen;
        if ( m_fullscreen )
        {
            showFullScreen();
        }
        else
        {
            showNormal();
            resize(640, 480);
        }
        ICGLWidgit* glWidget  = dynamic_cast<ICGLWidgit*>(centralWidget());
        if( glWidget != NULL )
        {
            glWidget->updateGL();
        }
        break;
    }
    case Qt::Key_Escape:
        close();
        break;
    default:break;
    }
}

#ifndef ICGLWIDGIT_H
#define ICGLWIDGIT_H

#include <QGL>

class ICGLWidgit : public QGLWidget
{
    Q_OBJECT
public:
    ICGLWidgit( QWidget* parent = 0);
    virtual ~ICGLWidgit();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );
};

#endif // ICGLWIDGIT_H

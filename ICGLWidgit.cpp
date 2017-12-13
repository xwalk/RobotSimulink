#include "ICGLWidgit.h"
#include <QKeyEvent>
#include <GL/glu.h>

ICGLWidgit::ICGLWidgit( QWidget* parent )
    :QGLWidget(parent)
{

}

ICGLWidgit::~ICGLWidgit()
{

}

void ICGLWidgit::initializeGL()
{
    glShadeModel( GL_SMOOTH );  //阴影平滑
    glClearColor( 0.0, 0.0, 0.0, 0.0 ); //设置清除屏幕时所用的颜色
    glClearDepth( 1.0 );    //设置深度缓存
    glEnable( GL_DEPTH_TEST );  //启用深度测试
    glDepthFunc( GL_LEQUAL );   //深度测试的类型
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );    //最好的透视修正
}

void ICGLWidgit::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );   //清除屏幕和深度缓存。
    glLoadIdentity();   //重置当前的模型观察矩阵。

    //坐标转移
    glTranslatef(0.0f,0.0f,-1.0f);
    //设置颜色
    glColor3f( 1.0, 1.0, 1.0 );
    //绘制一个正方形
    glBegin( GL_QUADS );
    glVertex3f( -0.5,  0.5,  0.0 );
    glVertex3f(  0.5,  0.5,  0.0 );
    glVertex3f(  0.5, -0.5,  0.0 );
    glVertex3f( -0.5, -0.5,  0.0 );
    glEnd();
}

void ICGLWidgit::resizeGL( int w, int h )
{
    if ( h == 0 )   //防止 height 为 0
    {
        h = 1;
    }

    glViewport( 0, 0, (GLint)w, (GLint)h );    //重置当前的视口(Viewport)

    glMatrixMode( GL_PROJECTION );  //选择投影矩阵。
    glLoadIdentity();   //重置投影矩阵。
    gluPerspective( 45.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0 ); //建立透视投影矩阵。
    glMatrixMode( GL_MODELVIEW );   //选择模型观察矩阵。
    glLoadIdentity();   //重置模型观察矩阵。
}


#ifndef SWORDWIDGETS_H
#define SWORDWIDGETS_H

#include <QGLWidget>

class swordwidgets : public QGLWidget
{
    Q_OBJECT

public:
    swordwidgets(QWidget *parent = 0);

public slots:
    // Lighting
    void xax(int x);
    void yax(int y);
    void zax(int z);
    void wax(int w);

    // Rotation
    void l_xax(int x);
    void l_yax(int y);
    void l_zax(int z);

    void playPause();
    void ang();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    // Rotation Position
    float rx1 = 0.0;
    float ry1 = 1.0;
    float rz1 = 0.0;

    // Light Position
    float x1 = 8.0;
    float y1 = 1.0;
    float z1 = 20.0;
    float w1 = 1.0;

    // Other private members
    // ...

    void drawSword();
    void polygon(int, int, int, int);
    void camera();

    float light_v = 1.0f;
    bool playingscene = true;
    QTimer *timer;
    float rotVal_ = 2.0f;

private slots:
};

#endif // SWORDWIDGETS_H

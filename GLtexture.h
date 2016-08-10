#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <QGLWidget>
#include <opencv2/opencv.hpp>

using namespace cv;


class GLtexture
{
public:
    GLtexture();

    void setTexture(QString texturePath);
    void setTexture(Mat textureMat);
    void setResizeWidget(bool newValue);

    GLint getWidth();
    GLint getHeight();

    GLuint getTexture();


private:
    QImage matToQImage(Mat const& image);

    GLuint texture[1];
    bool resizeWidget;
    GLint width, height;
};

#endif // GLTEXTURE_H
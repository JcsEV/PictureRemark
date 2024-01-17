#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include <QImage>
#include <QtMath>


QImage gray(QImage image_o)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);

    for(int y = 0; y < image_0.height(); y++) {
        for(int x = 0; x < image_0.width(); x++) {
            QColor old = QColor(image_o.pixel(x,y));
            int average = (old.red() + old.green() + old.blue()) / 3;
            image_0.setPixel(x, y, qRgb(average, average, average));
        }
    }
    return image_0;
}


QImage average(QImage image_o)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);
    int kernel [3][3] = { {1,1,1}, {1,1,1}, {1,1,1}};
    int sizeKernel = 3;
    int sumKernel = 9;

    for(int x = sizeKernel/2; x<image_o.width() - sizeKernel/2; x++) {
        for(int y= sizeKernel/2; y<image_o.height() - sizeKernel/2; y++) {
            int r = 0, g = 0, b = 0;
            for(int i = -sizeKernel/2; i<=sizeKernel/2; i++) {
                for(int j = -sizeKernel/2; j<=sizeKernel/2; j++) {
                  QColor color = QColor(image_o.pixel(x+i,y+j));
                  r+=color.red()*kernel[sizeKernel/2+i][sizeKernel/2+j];
                  g+=color.green()*kernel[sizeKernel/2+i][sizeKernel/2+j];
                  b+=color.blue()*kernel[sizeKernel/2+i][sizeKernel/2+j];
                 }
            }
            r = qBound(0,r/sumKernel,255);
            g = qBound(0,g/sumKernel,255);
            b = qBound(0,b/sumKernel,255);
            image_0.setPixel(x,y,qRgb( r,g,b));
         }
    }
    return image_0;
}


QImage edge(QImage image_o)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);

    for( int y = 0; y < image_o.height() - 1; y++) {
        for(int x = 0; x < image_o.width() - 1; x++) {
            QColor color0 =   QColor ( image_o.pixel(x,y));
            QColor color1 =   QColor ( image_o.pixel(x + 1,y));
            QColor color2 =   QColor ( image_o.pixel(x,y + 1));
            QColor color3 =   QColor ( image_o.pixel(x + 1,y + 1));
            int r0 = abs(color0.red() - color3.red());
            int g0 = abs(color0.green() - color3.green());
            int b0 = abs(color0.blue() - color3.blue());
            int r1 = abs(color1.red() - color2.red());
            int g1= abs(color1.green() - color2.green());
            int b1 = abs(color1.blue() - color2.blue());
            int tmp = r0 + g0 + b0 + r1 + g1 + b1;
            tmp = tmp > 255 ? 255 : tmp;
            image_0.setPixel(x,y,qRgb(tmp, tmp, tmp));
        }
    }
    return image_0;
}


QImage edge_origin(QImage image_o, double value)
{
    QImage image_0 = edge(image_o);
    int pixels = image_o.width() * image_o.height();
    unsigned int* data0 = (unsigned int *)image_o.bits();
    unsigned int* data1 = (unsigned int *)image_0.bits();

    for (int i = 0; i < pixels; ++i) {
        int red = qRed(data1[i]) * (1 - value) + qRed(data0[i]) * (1 - value);
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        int green= qGreen(data1[i]) * (1 - value) + qGreen(data0[i]) * (1 - value);
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        int blue= qBlue(data1[i]) * (1 - value) + qBlue(data0[i]) * (1 - value);
        blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;

        data1[i] = qRgba(red, green, blue, qAlpha(data1[i]));
    }
    return image_0;
}


QImage garmma(QImage image_o)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);

    for (int i = 0; i < image_o.width(); i++){
        for(int j = 0; j < image_o.height(); j++){
            QColor color = QColor(image_o.pixel(i,j));
            int R = qBound(0,(int)qPow(color.red(),1.2),255);
            int G = qBound(0,(int)qPow(color.green(),1.2),255);
            int B = qBound(0,(int)qPow(color.blue(),1.2),255);
            image_0.setPixel(i,j,qRgb(R,G,B));
        }
    }
    return image_0;
}


QImage light(QImage image_o, double value)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);
    int pixels = image_o.width() * image_o.height();
    unsigned int* data0 = (unsigned int *)image_o.bits();
    unsigned int* data1 = (unsigned int *)image_0.bits();

    for (int i = 0; i < pixels; ++i) {
        int red = qRed(data0[i]) + value;
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        int green= qGreen(data0[i]) + value;
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        int blue= qBlue(data0[i]) + value;
        blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;

        data1[i] = qRgba(red, green, blue, qAlpha(data1[i]));
    }
    return image_0;
}


QImage binary(QImage image_o, double value)
{
    QImage image_0=gray(image_o);

    for (int i = 0; i < image_0.height(); ++i) {
        for(int j = 0; j < image_0.width(); ++j){
           QColor  oldColor = QColor(image_0.pixel(j,i));
            if(oldColor.red() < value){ image_0.setPixel(j,i, qRgb(0, 0, 0)); }
            else{ image_0.setPixel(j,i, qRgb(255, 255, 255)); }
        }
    }
    return image_0;
}


QImage contrast(QImage image_o, double value)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);
    int pixels = image_o.width() * image_o.height();
    unsigned int* data0 = (unsigned int *)image_o.bits();
    unsigned int* data1 = (unsigned int *)image_0.bits();
    double param = (value > 0 && value < 256) ? (1 / (1 - value / 256.0) - 1) : (value / 100.0);

    for (int i = 0; i < pixels; ++i) {
        int red = qRed(data0[i]) + (qRed(data0[i]) - 127) * param;
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        int green = qGreen(data0[i]) + (qGreen(data0[i]) - 127) * param;
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        int blue = qBlue(data0[i]) + (qBlue(data0[i]) - 127) * param;
        blue = (blue < 0x00) ? 0x00 : (blue > 0xff) ? 0xff : blue;

        data1[i] = qRgba(red, green, blue, qAlpha(data0[i]));
    }
    return image_0;
}


QImage saturability(QImage image_o, double value)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);
    int pixels = image_o.width() * image_o.height();
    unsigned int* data0 = (unsigned int *)image_o.bits();
    unsigned int* data1 = (unsigned int *)image_0.bits();

    for (int i = 0; i < pixels; ++i) {
        float minVal = std::min(std::min(qRed(data0[i]), qGreen(data0[i])), qBlue(data0[i]));
        float maxVal = std::max(std::max(qRed(data0[i]), qGreen(data0[i])), qBlue(data0[i]));
        float delta = (maxVal - minVal) / 255.0;
        float L = 0.5*(maxVal + minVal) / 255.0;
        float S = std::max(0.5 * delta / L, 0.5 * delta / (1 - L));

        float alpha = (value > 0) ? (1.0 / std::max(S, 1 - (float)value) - 1) : (value + 1);
        int nRed = (value > 0) ? qRed(data0[i]) : L*255.0;
        int nGreen = (value > 0) ? qGreen(data0[i]) : L*255.0;
        int nBlue = (value > 0) ? qBlue(data0[i]) : L*255.0;

        int red = nRed + (nRed - L*255.0) * alpha;
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        int green = nGreen + (nGreen - L*255.0) * alpha;
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        int blue = nBlue + (nBlue - L*255.0) * alpha;
        blue = (blue < 0x00) ? 0x00 : (blue > 0xff) ? 0xff : blue;

        data1[i] = qRgba(red, green, blue, qAlpha(data0[i]));
    }
    return image_0;
}


QImage setRGB(QImage image_o, double v_r, double v_g, double v_b)
{
    QImage image_0 = image_o.convertToFormat(QImage::Format_ARGB32);

    for (int i = 0; i < image_o.height(); ++i) {
        for(int j = 0; j < image_o.width(); ++j){
            QColor oldColor = QColor(image_o.pixel(j,i));
            int r = oldColor.red() + v_r > 255 ? 255 : oldColor.red() + v_r;
            int g = oldColor.green() + v_g > 255 ? 255 : oldColor.green() + v_g;
            int b = oldColor.blue() + v_b > 255 ? 255 : oldColor.blue() + v_b;
            image_0.setPixel(j,i, qRgb(r, g, b));
        }
    }
    return image_0;
}


#endif // MAINPROCESS_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include <QImage>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_last_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_file_clicked();

    void on_pushButton_origin_clicked();

    void on_pushButton_gray_clicked();

    void on_pushButton_average_clicked();

    void on_pushButton_edge_clicked();

    void on_pushButton_edge_org_clicked();

    void on_horizontalSlider_ratio_valueChanged(int value);

    void on_pushButton_gamma_clicked();

    void on_pushButton_t_left_clicked();

    void on_pushButton_t_right_clicked();

    void on_pushButton_t_level_clicked();

    void on_pushButton_t_vertical_clicked();

    void on_horizontalSlider_light_valueChanged(int value);

    void on_horizontalSlider_binary_valueChanged(int value);

    void on_horizontalSlider_contrast_valueChanged(int value);

    void on_horizontalSlider_saturability_valueChanged(int value);

    void on_horizontalSlider_R_valueChanged(int value);

    void on_horizontalSlider_G_valueChanged(int value);

    void on_horizontalSlider_B_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QStringList srcDirPathList;//图片list
    int index;             //图片index
    QImage image_p;

};
#endif // MAINWINDOW_H

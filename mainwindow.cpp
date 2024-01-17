#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainprocess.h"

#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>

#include <QImage>
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* permanent = new QLabel(this);
    permanent->setObjectName("status");
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText("欢迎使用！");
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_last_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }
    QLabel *label=ui->statusBar->findChild<QLabel *>("status");//状态栏显示图片路径
    index=qAbs(index+srcDirPathList.size()-1);
    label->setText(srcDirPathList.at(index%srcDirPathList.size()));

    QImage image_0(srcDirPathList.at(index++%srcDirPathList.size()));
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);

//  QPixmap pixmap_0 = QPixmap::fromImage(image_0).scaled(ui->label_other_0->width(), ui->label_other_0->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_0 = QPixmap::fromImage(image_0).scaled(ui->label_other_0->width(), ui->label_other_0->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_other_0->setPixmap(pixmap_0);
    ui->label_other_0->setAlignment(Qt::AlignCenter);
    image_p = image_0;

    QImage image_1(srcDirPathList.at(index++%srcDirPathList.size()));
//  QPixmap pixmap_1 = QPixmap::fromImage(image_1).scaled(ui->label_other_1->width(), ui->label_other_1->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_1 = QPixmap::fromImage(image_1).scaled(ui->label_other_1->width(), ui->label_other_1->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_other_1->setPixmap(pixmap_1);
    ui->label_other_1->setAlignment(Qt::AlignCenter);

    if(srcDirPathList.size() > 2){
        QImage image_2(srcDirPathList.at(index++%srcDirPathList.size()));
//      QPixmap pixmap_2 = QPixmap::fromImage(image_2).scaled(ui->label_other_2->width(), ui->label_other_2->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        QPixmap pixmap_2 = QPixmap::fromImage(image_2).scaled(ui->label_other_2->width(), ui->label_other_2->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
        ui->label_other_2->setPixmap(pixmap_2);
        ui->label_other_2->setAlignment(Qt::AlignCenter);
    }
}


void MainWindow::on_pushButton_next_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }
    QLabel *label=ui->statusBar->findChild<QLabel *>("status");//状态栏显示图片路径
    index=qAbs(index+srcDirPathList.size()+1);
    label->setText(srcDirPathList.at(index%srcDirPathList.size()));

    QImage image_0(srcDirPathList.at(index++%srcDirPathList.size()));
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);

//  QPixmap pixmap_0 = QPixmap::fromImage(image_0).scaled(ui->label_other_0->width(), ui->label_other_0->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_0 = QPixmap::fromImage(image_0).scaled(ui->label_other_0->width(), ui->label_other_0->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_other_0->setPixmap(pixmap_0);
    ui->label_other_0->setAlignment(Qt::AlignCenter);
    image_p = image_0;

    QImage image_1(srcDirPathList.at(index++%srcDirPathList.size()));
//  QPixmap pixmap_1 = QPixmap::fromImage(image_1).scaled(ui->label_other_1->width(), ui->label_other_1->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_1 = QPixmap::fromImage(image_1).scaled(ui->label_other_1->width(), ui->label_other_1->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_other_1->setPixmap(pixmap_1);
    ui->label_other_1->setAlignment(Qt::AlignCenter);

    if(srcDirPathList.size() > 2){
        QImage image_2(srcDirPathList.at(index++%srcDirPathList.size()));
//      QPixmap pixmap_2 = QPixmap::fromImage(image_2).scaled(ui->label_other_2->width(), ui->label_other_2->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        QPixmap pixmap_2 = QPixmap::fromImage(image_2).scaled(ui->label_other_2->width(), ui->label_other_2->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
        ui->label_other_2->setPixmap(pixmap_2);
        ui->label_other_2->setAlignment(Qt::AlignCenter);
    }
}


void MainWindow::on_pushButton_change_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    image_p = ui->label_show->grab().toImage();
}


void MainWindow::on_pushButton_save_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage gimage(image_p);
    if(ui->checkBox->isChecked()){//要加水印
        QImage simage("./data/img/mark.png");

        for(int i=0; i<simage.height(); ++i) {
            for(int j=0; j<simage.width(); ++j) {
               QColor old=QColor(simage.pixel(j,i));
               if(old.red() <128 && old.blue() <128 && old.green() < 128) { gimage.setPixelColor(j,i,qRgb(0,0,0)); }
            }
        }
    }

    QString filename = QFileDialog::getSaveFileName(this,tr("保存图片"),"./data/example/",tr("*.png;; *.jpg;; *.bmp;; *.tif;; *.GIF")); //选择路径
    if (filename.isEmpty()) { return; }
    if (!gimage.save(filename)) {//保存图像
        QMessageBox::information(this,tr("图片保存成功！"),tr("图片保存失败！"));
        return;
    }
    ui->statusBar->showMessage("图片保存成功！");
}


void MainWindow::on_pushButton_file_clicked()
{
    srcDirPathList = QFileDialog::getOpenFileNames(this, tr("选择图片"), "./data/example/", tr("图像文件(*.jpg *.png *.bmp)"));
    if(srcDirPathList.size()==0){ return; }
    QLabel* label=ui->statusBar->findChild<QLabel*>("status"); //状态栏显示图片路径
    label->setText(srcDirPathList.at(0));
    index = 0;

    if(srcDirPathList.size() > 0){
        QImage image_0(srcDirPathList.at(0));
//      QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
        ui->label_show->setPixmap(pixmap_s);
        ui->label_show->setAlignment(Qt::AlignCenter);

//      QPixmap pixmap_0 = QPixmap::fromImage(image_0).scaled(ui->label_other_0->width(), ui->label_other_0->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        QPixmap pixmap_0 = QPixmap::fromImage(image_0).scaled(ui->label_other_0->width(), ui->label_other_0->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
        ui->label_other_0->setPixmap(pixmap_0);
        ui->label_other_0->setAlignment(Qt::AlignCenter);
        image_p = image_0;
    }

    if(srcDirPathList.size() > 1){
        QImage image_1(srcDirPathList.at(1));
//      QPixmap pixmap_1 = QPixmap::fromImage(image_1).scaled(ui->label_other_1->width(), ui->label_other_1->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        QPixmap pixmap_1 = QPixmap::fromImage(image_1).scaled(ui->label_other_1->width(), ui->label_other_1->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
        ui->label_other_1->setPixmap(pixmap_1);
        ui->label_other_1->setAlignment(Qt::AlignCenter);
    }

    if(srcDirPathList.size() > 2){
        QImage image_2(srcDirPathList.at(2));
//      QPixmap pixmap_2 = QPixmap::fromImage(image_2).scaled(ui->label_other_2->width(), ui->label_other_2->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
        QPixmap pixmap_2 = QPixmap::fromImage(image_2).scaled(ui->label_other_2->width(), ui->label_other_2->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
        ui->label_other_2->setPixmap(pixmap_2);
        ui->label_other_2->setAlignment(Qt::AlignCenter);
    }

    if(srcDirPathList.size() > 2){
        ui->pushButton_last->setDisabled(false);
        ui->pushButton_next->setDisabled(false);
        ui->label_other_1->setVisible(true);
        ui->label_other_2->setVisible(true);
    }
    else if(srcDirPathList.size() > 1){
        ui->pushButton_last->setDisabled(false);
        ui->pushButton_next->setDisabled(false);
        ui->label_other_1->setVisible(true);
        ui->label_other_2->setVisible(false);
    }
    else if(srcDirPathList.size() > 0){
        ui->pushButton_last->setDisabled(true);
        ui->pushButton_next->setDisabled(true);
        ui->label_other_2->setVisible(false);
        ui->label_other_1->setVisible(false);
    }
}


void MainWindow::on_pushButton_origin_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0(srcDirPathList.at(index%srcDirPathList.size()));
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_gray_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = gray(image_p);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_average_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = average(image_p);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_edge_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = edge(image_p);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_edge_org_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = edge_origin(image_p, 0.5);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_horizontalSlider_ratio_valueChanged(int value)
{
    double d_value = (double)value / 100;
    ui->label_ratio->setText(QString::number(d_value).append(":").append(QString::number(1 - d_value)));
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = edge_origin(image_p, d_value);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_pushButton_gamma_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = garmma(image_p);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_t_left_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QTransform matrix;
    matrix.rotate(-90.0);//逆时针旋转90度
    QImage image_0 = image_p.transformed(matrix,Qt::FastTransformation);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_t_right_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QTransform matrix;
    matrix.rotate(+90.0);//顺时针旋转90度
    QImage image_0 = image_p.transformed(matrix,Qt::FastTransformation);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_t_level_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = image_p.mirrored(true, false);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_pushButton_t_vertical_clicked()
{
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = image_p.mirrored(false, true);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
    image_p = image_0;
}


void MainWindow::on_horizontalSlider_light_valueChanged(int value)
{
    double d_value = (double)value;
    ui->label_light->setText(QString::number(value));
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = light(image_p, d_value);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_horizontalSlider_binary_valueChanged(int value)
{
    double d_value = (double)value;
    ui->label_binary->setText(QString::number(value));
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = binary(image_p, d_value);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_horizontalSlider_contrast_valueChanged(int value)
{
    double d_value = (double)value;
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = contrast(image_p, d_value);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);

}


void MainWindow::on_horizontalSlider_saturability_valueChanged(int value)
{
    double d_value = (double)value / 100.0;
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = saturability(image_p, d_value);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_horizontalSlider_R_valueChanged(int value)
{
    double d_value = (double)value;
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = setRGB(image_p, d_value, ui->horizontalSlider_G->value(), ui->horizontalSlider_B->value());
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_horizontalSlider_G_valueChanged(int value)
{
    double d_value = (double)value;
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = setRGB(image_p, ui->horizontalSlider_R->value(), d_value, ui->horizontalSlider_B->value());
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
}


void MainWindow::on_horizontalSlider_B_valueChanged(int value)
{
    double d_value = (double)value;
    if(srcDirPathList.size()==0){
        QMessageBox::warning(nullptr, "提示", "请先打开图片！", QMessageBox::Yes |  QMessageBox::Yes);
        return;
    }

    QImage image_0 = setRGB(image_p, ui->horizontalSlider_R->value(), ui->horizontalSlider_G->value(), d_value);
//  QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    QPixmap pixmap_s = QPixmap::fromImage(image_0).scaled(ui->label_show->width(), ui->label_show->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);    // 按比例缩放
    ui->label_show->setPixmap(pixmap_s);
    ui->label_show->setAlignment(Qt::AlignCenter);
}


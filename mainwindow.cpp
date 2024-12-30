#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("cm");
    ui->comboBox->addItem("dm");
    ui->comboBox->addItem("m");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_imgbutn_clicked()
{

    if (srcimg.empty()) {
        QMessageBox::information(this,"Error","请先设置图片");
        return;
    }
    if(rect_line == 0) {
        QMessageBox::information(this,"Error","请设置正方形边长");
        return;
    }
    srcimg = imread(imagePath.toStdString());
    imgoutput = srcimg;
    ui->imgLab->clear();
    Processimg(srcimg);
    Mat imgoutshow;
    cvtColor(imgoutput, imgoutshow, COLOR_BGR2RGB);
    QImage qimg = QImage((unsigned char*)(imgoutshow.data), imgoutshow.cols,
                         imgoutshow.rows, imgoutshow.cols*imgoutshow.channels(), QImage::Format_RGB888);

    ui->imgLab->setPixmap(QPixmap::fromImage(qimg.scaled(ui->imgLab->size(),Qt::KeepAspectRatio)));
    ui->disoutput->setText(QString::number(distance)+ui->comboBox->currentText());

}


void MainWindow::on_imgpath_editingFinished()
{
    imagePath = ui->imgpath->text();
}


void MainWindow::on_openfile_clicked()
{
    imagePath = QFileDialog::getOpenFileName(this,"打开图片","D:","(打开(*.png *.jpg *.bmp))");
}


void MainWindow::on_setimg_clicked()
{
    if(imagePath.isEmpty()) {
        QMessageBox::information(this,"Error","请检查文件路径是否正确");
        return;
    }

    srcimg = imread(imagePath.toStdString());
    if (srcimg.empty()) {
        QMessageBox::information(this,"Error","文件无法打开");
        return;
    }

    Mat srcimgshow;
    cvtColor(srcimg, srcimgshow, COLOR_BGR2RGB);
    QImage qimg = QImage((unsigned char*)(srcimgshow.data), srcimgshow.cols,
                         srcimgshow.rows, srcimgshow.cols*srcimgshow.channels(), QImage::Format_RGB888);

    ui->imgLab->setPixmap(QPixmap::fromImage(qimg.scaled(ui->imgLab->size(),Qt::KeepAspectRatio)));
}

void MainWindow::on_lineset_editingFinished()
{
    if(ui->lineset->text().isEmpty()) {
        QMessageBox::information(this,"Error","请输入正确的数字");
        return;
    }
    if(is_imgpath_mean(ui->lineset->text()) == false) {
        QMessageBox::information(this,"Error","请输入正确的数字");
        return;
    }
    rect_line = ui->lineset->text().toDouble();
}

bool MainWindow::is_imgpath_mean(QString str) {

    string strpath = str.toStdString();
    bool find_ = false, mean_ = true;
    for (int i = 0; strpath[i] != '\0'; i++) {
        if(strpath[i] >= '0' && strpath[i] <= '9') continue;
        else if(strpath[i] == '.' && find_ == false) {
            find_ = true;
            continue;
        }
        else {
            mean_ = false;
            break;
        }
    }
    if (mean_ == true) return true;
    else return false;
}

void MainWindow::Processimg(cv::Mat& image) {

    Mat gray, imgblur, imgdil, imgth;
    //预处理
    cvtColor(image, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, imgblur, Size(7,7),3,0);
    threshold(imgblur, imgth, 100, 255, 1);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(imgth, imgdil, kernel);

    //查找轮廓
    vector<vector<Point>> contours;
    findContours(imgdil, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    //寻找面积最大的轮廓
    double area, maxarea = 0;
    int ii;
    for (unsigned i=0; i<contours.size();i++) {
        area = contourArea(contours[i]);
        if (area > maxarea) {
            maxarea = area;
            ii = i;
        }
    }
    //绘制轮廓
    drawContours(imgoutput, contours, ii, Scalar(0, 0, 255), 10);

    //找到2D点
    vector<Point2f> approx;
    approxPolyDP(contours[ii], approx, arcLength(contours[ii], true) * 0.02, true);

    //定义3D点
    vector<Point3f> objectPoints = {
        Point3f(0, 0, 0),
        Point3f(rect_line, 0, 0),
        Point3f(rect_line, rect_line, 0),
        Point3f(0, rect_line, 0)
    };

    //进行PNP求解
    Mat rvec, tvec;
    cv::solvePnP(objectPoints, approx, cameraMatrix, distCoeffs, rvec, tvec);

    distance = norm(tvec);

}





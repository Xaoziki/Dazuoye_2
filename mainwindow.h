#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QRegion>
#include <QValidator>
#include <QRegularExpressionValidator>
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString imagePath;

    void Processimg(cv::Mat& image);
    bool is_imgpath_mean(QString str);

private slots:
    void on_imgbutn_clicked();

    void on_imgpath_editingFinished();

    void on_openfile_clicked();

    void on_setimg_clicked();

    void on_lineset_editingFinished();

private:
    Ui::MainWindow *ui;
    double distance, rect_line = 0;
    cv::Mat srcimg, imgoutput;
    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 3916.143931422424, 0, 1385.210988879861, 0, 3933.751441780795, 2208.169167568601, 0, 0, 1);
    cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << 0.2994338494009186, -1.574013213125817, 0.01718489359160927, -0.01208570734985182, 4.904165993574098);

};



#endif // MAINWINDOW_H

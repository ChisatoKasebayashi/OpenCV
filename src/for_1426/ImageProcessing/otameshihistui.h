#ifndef OTAMESHIHISTUI_H
#define OTAMESHIHISTUI_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_lib.hpp>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace cv;

namespace Ui {
class OtameshiHistUI;
}

class OtameshiHistUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtameshiHistUI(QWidget *parent = 0);
    ~OtameshiHistUI();

public slots:
    void oncheckCVImage(int state);
    void onpushStar();

private:
    Ui::OtameshiHistUI *ui;
    void connectSignals();
    static const int NUM_HISTGRAM = 64;
    IplImage *img_origin;
    IplImage *img;
    IplImage *img_ycrcb;
    int x;
    int y;
    int radius;
    CvPoint center;
    float *normalizedHistgram;
    float *referenceHistgram;
    int *histgram;
    QGraphicsScene scene;
    QGraphicsScene sceneE;
    QGraphicsScene sceneC;
    QGraphicsScene sceneN;

    void processingGetColorHistogram();
    void initHistogram();
    void destHistogram();
    void clearColorHistgram();
    bool loadReferenceColorHistgram(const char *filename);
    void mouseEvent();
    int evaluateRadius();
    void drawCircle(int radius, CvPoint center);
    int getColorHistgram(int x, int y, int r, int no_point);
    void plotColorHistogram(float hist,int cnt);
    void plotEuclid(float ref, float nor, int cnt);
    void plotCosine(float ref, float nor, int cnt);
    void plotNormalize(float ref, float nor, int cnt);

};

#endif // OTAMESHIHISTUI_H

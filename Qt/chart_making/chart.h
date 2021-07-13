#ifndef CHART_H
#define CHART_H

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui { class chart; }
using namespace QtCharts;
QT_END_NAMESPACE

class chart : public QMainWindow
{
    Q_OBJECT

public:
    chart(QWidget *parent = nullptr);
    void Axis_Config(QValueAxis *chart_axis,int min,int max,int TickCount,int MinorTickCount,const QString &title,bool flag);
    void Axis_Location_Config(QChart *chart,QValueAxis *chart_axis1,Qt::Alignment alignment1,QValueAxis *chart_axis2,Qt::Alignment alignment2);
    void Chart_Title_Config(QChart *chart,const QString &title);
    void asix_Hz_Db(QChart* chart);
    void Point_Line_Config(QLineSeries *series);
    ~chart();


private:
    Ui::chart *ui;
};
#endif // CHART_H

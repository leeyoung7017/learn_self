#include "chart.h"
#include "ui_chart.h"
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QFont>
using namespace QtCharts;


chart::chart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chart)
{
     ui->setupUi(this);
    QChart *distance_time_chart = new QChart();

    asix_Hz_Db(distance_time_chart);

    /*将表格放置QChartView中显示出来*/
    /*在这里需要使用控件 Graphics View 将其提升为 QtCharts::QChartView 后，直接调用即可*/
    ui->distance_time_chart_view->setChart(distance_time_chart);
}

chart::~chart()
{
    delete ui;
}

void chart::asix_Hz_Db(QChart* chart)
{
    chart->legend()->hide();

    /*表格背景*/
    chart->setTheme(QChart::ChartThemeDark);

    /*坐标轴的设置：Axis*/
    QValueAxis *chart_axisX = new QValueAxis();
    QValueAxis *chart_axisY = new QValueAxis();
    /*各坐标的配置：范围，刻度(主要刻度，最小刻度)，单位，数据格式*/
    /*X轴*/
    Axis_Config(chart_axisX,0,200,6,0,"时间/s",false);
    /*Y轴*/
     Axis_Config(chart_axisY,0,200,6,0,"距离/s",true);

     /*坐标轴的位置*/
     Axis_Location_Config(chart,chart_axisX,Qt::AlignBottom,chart_axisY,Qt::AlignLeft);

    /*坐标系的主题：title*/
    Chart_Title_Config(chart,"距离—时间图");

    /*添加数据*/
    QLineSeries *series = new QLineSeries();
    Point_Line_Config(series);
    chart->addSeries(series);

}

/*配置轴线*/
/*
    chart_axis：      轴线变量
    min、max：        轴线的取值范围
    TickCount：      主要尺度个数
    MinorTickCount： 次要尺度个数
    title：          轴线单位，代表的意义
    flag：           是否显示表格内线条
*/
void chart::Axis_Config(QValueAxis *chart_axis,int min,int max,int TickCount,int MinorTickCount,const QString &title,bool flag)
{
     QFont *font = new QFont();
    chart_axis->setTitleFont(*font);
    font->setFamily("楷体");
    chart_axis->setRange(min,max);
    chart_axis->setTickCount(TickCount);
    chart_axis->setGridLineVisible(flag);
    chart_axis->setMinorTickCount(MinorTickCount);
    chart_axis->setTitleText(title);
    chart_axis->setLabelFormat("%d");
}

/*配置坐标主题*/
/*
    chart：表示制作的坐标系
    title：表示坐标系的主题
*/
void chart::Chart_Title_Config(QChart *chart,const QString &title)
{
    QFont *title_font = new QFont();
    title_font->setFamily("楷体");
    chart->setTitle(title);
    chart->setTitleFont(*title_font);
}

/*配置轴线所在坐标系的位置*/
/*
 * chart：坐标系
 * chart_axis1/chart_axis2：表示坐标轴
 * alignment1、alignment2：表示坐标轴的位置         Qt::AlignBottom    Qt::AlignLeft  Qt::AlignRight  Qt::AlignTop    Qt::AlignCenter
*/
void chart::Axis_Location_Config(QChart *chart,QValueAxis *chart_axis1,Qt::Alignment alignment1,QValueAxis *chart_axis2,Qt::Alignment alignment2)
{
    chart->addAxis(chart_axis1,alignment1);
    chart->addAxis(chart_axis2,alignment2);
}


/*配置数据*/
void chart::Point_Line_Config(QLineSeries *series)
{
    series->append(5,5);
    series->append(10,150);
    series->append(200,200);

}

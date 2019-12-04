#ifndef RVIZQTTEST_H
#define RVIZQTTEST_H

#include <QWidget>
#include <rviz/panel.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ui_rvizqttest.h"
#include "std_msgs/String.h"
#include <ros/ros.h>
namespace Ui {
class RvizQTTest;
}

class RvizQTTest : public QWidget
{
    Q_OBJECT

public:
    explicit RvizQTTest(QWidget *parent = nullptr);
    ~RvizQTTest();
private Q_SLOTS:
    void click_send_button();
private:
    Ui::RvizQTTest *ui;
    ros::NodeHandle nodeHnadle;
    ros::Publisher chatterPub;
    int clickCounter;
};

class RvizPanel : public rviz::Panel{
    Q_OBJECT
public:
    RvizPanel();
private:
    RvizQTTest* ui;

};

#endif // RVIZQTTEST_H


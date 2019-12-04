#include "../include/rviz_qt_interface/rvizqttest.h"


RvizQTTest::RvizQTTest(QWidget *parent):
    QWidget(parent),
    ui(new Ui::RvizQTTest)
{
    ui->setupUi(this);
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(click_send_button()));
    chatterPub = nodeHnadle.advertise<std_msgs::String>("ui_chatter", 1000);
    clickCounter =0;
    std::cout<<"finish initial!"<<std::endl;
}

void RvizQTTest::click_send_button(){
    std::string xValue = ui->lineEditX->text().toUtf8().constData();
    std::string yValue = ui->lineEditY->text().toUtf8().constData();
    std::string zValue = ui->lineEditZ->text().toUtf8().constData();

    clickCounter++;

    std::string showString;
    showString.append(xValue);
    showString.append(",");
    showString.append(yValue);
    showString.append(",");
    showString.append(zValue);
    showString.append(", and click counter is ");
    showString.append(std::to_string(clickCounter));

    //std::cout<<showString<<std::endl;

    std_msgs::String msg;
    msg.data = showString;
    chatterPub.publish(msg);
    ros::spinOnce();

    //ui->labelDescription->setText(QString::fromStdString(showString));
}
RvizQTTest::~RvizQTTest()
{
    delete ui;
}

RvizPanel::RvizPanel(){
  ui = new RvizQTTest(this);
  QHBoxLayout* topic_layout = new QHBoxLayout;
  topic_layout->addWidget(ui);
  QVBoxLayout* layout = new QVBoxLayout;
  layout->addLayout(topic_layout);
  setLayout( layout );
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(RvizPanel, rviz::Panel)


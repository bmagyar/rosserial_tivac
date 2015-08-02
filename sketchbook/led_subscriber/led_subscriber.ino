#include <ros.h>
#include <std_msgs/ColorRGBA.h>

ros::NodeHandle nh;

void messageCb( const std_msgs::ColorRGBA& toggle_msg)
{
  analogWrite(RED_LED,toggle_msg.r);
  analogWrite(GREEN_LED,toggle_msg.g);
  analogWrite(BLUE_LED,toggle_msg.b);
}

ros::Subscriber<std_msgs::ColorRGBA> sub("toggle_led", &messageCb );

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  analogWrite(RED_LED,140);
  analogWrite(GREEN_LED,20);
  analogWrite(BLUE_LED,40);
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(100);
}

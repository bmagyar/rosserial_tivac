#include <ros.h>
#include <std_msgs/String.h>
ros::NodeHandle nh;

std_msgs::String button_msg;
ros::Publisher button_pub("button", &button_msg);

char nobutton[9] = "nobutton";
char button1[8] = "button1";
char button2[8] = "button2";
char button12[9] = "button12";

int btn1_state = 0;
int btn2_state = 0;

void setup()
{
  nh.initNode();
  nh.advertise(button_pub);  
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
}

void loop()
{
  btn1_state = digitalRead(PUSH1);  
  btn2_state = digitalRead(PUSH2); 
  
  if(btn1_state == LOW && btn2_state == LOW)
  {
    button_msg.data = button12; 
  }
  else if(btn1_state == LOW)
  {
    button_msg.data = button1;
  }
  else if(btn2_state == LOW)
  {
    button_msg.data = button2;
  }
  else
  {
    button_msg.data = nobutton;
  }
  
  button_pub.publish(&button_msg);
  
  nh.spinOnce();
  delay(100);
}

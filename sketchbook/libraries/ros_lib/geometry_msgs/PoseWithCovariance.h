#ifndef _ROS_geometry_msgs_PoseWithCovariance_h
#define _ROS_geometry_msgs_PoseWithCovariance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace geometry_msgs
{

  class PoseWithCovariance : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;
      double covariance[36];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 36; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 36; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariance[i]));
      }
     return offset;
    }

    const char * getType(){ return "geometry_msgs/PoseWithCovariance"; };
    const char * getMD5(){ return "c23e848cf1b7533a8d7c259073a97e6f"; };

  };

}
#endif
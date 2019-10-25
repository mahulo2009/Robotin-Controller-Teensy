#ifndef _ROS_SERVICE_PidTunning_h
#define _ROS_SERVICE_PidTunning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robomat_project
{

static const char PIDTUNNING[] = "robomat_project/PidTunning";

  class PidTunningRequest : public ros::Msg
  {
    public:
      typedef uint8_t _wheel_type;
      _wheel_type wheel;
      typedef float _kp_type;
      _kp_type kp;
      typedef float _ki_type;
      _ki_type ki;
      typedef float _kd_type;
      _kd_type kd;
      typedef float _vel_type;
      _vel_type vel;

    PidTunningRequest():
      wheel(0),
      kp(0),
      ki(0),
      kd(0),
      vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->wheel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wheel);
      offset += serializeAvrFloat64(outbuffer + offset, this->kp);
      offset += serializeAvrFloat64(outbuffer + offset, this->ki);
      offset += serializeAvrFloat64(outbuffer + offset, this->kd);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->wheel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wheel);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ki));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kd));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel));
     return offset;
    }

    const char * getType(){ return PIDTUNNING; };
    const char * getMD5(){ return "522b1b4f65663f03c60986fe2c51f4c6"; };

  };

  class PidTunningResponse : public ros::Msg
  {
    public:
      typedef float _rise_time_type;
      _rise_time_type rise_time;
      typedef float _percent_overshoot_type;
      _percent_overshoot_type percent_overshoot;
      typedef float _settling_time_type;
      _settling_time_type settling_time;
      typedef float _steady_state_error_type;
      _steady_state_error_type steady_state_error;

    PidTunningResponse():
      rise_time(0),
      percent_overshoot(0),
      settling_time(0),
      steady_state_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->rise_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->percent_overshoot);
      offset += serializeAvrFloat64(outbuffer + offset, this->settling_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->steady_state_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rise_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->percent_overshoot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->settling_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->steady_state_error));
     return offset;
    }

    const char * getType(){ return PIDTUNNING; };
    const char * getMD5(){ return "9f7961b22f1e262c743871a400182e9c"; };

  };

  class PidTunning {
    public:
    typedef PidTunningRequest Request;
    typedef PidTunningResponse Response;
  };

}
#endif

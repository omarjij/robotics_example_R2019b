//
// File: rasberrypi_publish_types.h
//
// Code generated for Simulink model 'rasberrypi_publish'.
//
// Model version                  : 1.186
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun May  3 19:24:49 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_rasberrypi_publish_types_h_
#define RTW_HEADER_rasberrypi_publish_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_rasberrypi_publish_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_rasberrypi_publish_ros_time_Time Stamp;
} SL_Bus_rasberrypi_publish_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_sensor_msgs_Image_
#define DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_sensor_msgs_Image_

// MsgType=sensor_msgs/Image
typedef struct {
  uint32_T Height;
  uint32_T Width;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Encoding_SL_Info:TruncateAction=warn 
  uint8_T Encoding[4];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Encoding
  SL_Bus_ROSVariableLengthArrayInfo Encoding_SL_Info;
  uint8_T IsBigendian;
  uint32_T Step;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  uint8_T Data[57600];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;

  // MsgType=std_msgs/Header
  SL_Bus_rasberrypi_publish_std_msgs_Header Header;
} SL_Bus_rasberrypi_publish_sensor_msgs_Image;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_std_msgs_UInt8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_rasberrypi_publish_std_msgs_UInt8_

// MsgType=std_msgs/UInt8
typedef struct {
  uint8_T Data;
} SL_Bus_rasberrypi_publish_std_msgs_UInt8;

#endif

#ifndef typedef_raspi_internal_ServoBlock_ras_T
#define typedef_raspi_internal_ServoBlock_ras_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  uint32_T PinNumber;
  real_T MinPulseDuration;
  real_T MaxPulseDuration;
  boolean_T Initialized;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} raspi_internal_ServoBlock_ras_T;

#endif                                 //typedef_raspi_internal_ServoBlock_ras_T

// Custom Type definition for MATLAB Function: '<S12>/MATLAB Function'
#ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
#define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
  uint32_T SafeEq;
  uint32_T Absolute;
  uint32_T NaNBias;
  uint32_T NaNWithFinite;
  uint32_T FiniteWithNaN;
  uint32_T NaNWithNaN;
};

#endif                                 //struct_tag_skA4KFEZ4HPkJJBOYCrevdH

#ifndef typedef_skA4KFEZ4HPkJJBOYCrevdH_rasbe_T
#define typedef_skA4KFEZ4HPkJJBOYCrevdH_rasbe_T

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH skA4KFEZ4HPkJJBOYCrevdH_rasbe_T;

#endif                                 //typedef_skA4KFEZ4HPkJJBOYCrevdH_rasbe_T

#ifndef struct_mdR3VzO9yVpL5cXUHVm1oJ4
#define struct_mdR3VzO9yVpL5cXUHVm1oJ4

struct mdR3VzO9yVpL5cXUHVm1oJ4
{
  int32_T S0_isInitialized;
  int16_T W0_N_PIXLIST_DW[19200];
  int16_T W1_M_PIXLIST_DW[19200];
  uint32_T W2_NUM_PIX_DW[10];
  uint8_T W3_PAD_DW[19764];
  uint32_T W4_STACK_DW[19200];
  int32_T P0_WALKER_RTP[8];
};

#endif                                 //struct_mdR3VzO9yVpL5cXUHVm1oJ4

#ifndef typedef_vision_BlobAnalysis_0_rasberr_T
#define typedef_vision_BlobAnalysis_0_rasberr_T

typedef struct mdR3VzO9yVpL5cXUHVm1oJ4 vision_BlobAnalysis_0_rasberr_T;

#endif                                 //typedef_vision_BlobAnalysis_0_rasberr_T

#ifndef struct_mdM2HXJTQNwxcsYfK36GrTEE
#define struct_mdM2HXJTQNwxcsYfK36GrTEE

struct mdM2HXJTQNwxcsYfK36GrTEE
{
  boolean_T matlabCodegenIsDeleted;
  boolean_T isSetupComplete;
  vision_BlobAnalysis_0_rasberr_T cSFunObject;
};

#endif                                 //struct_mdM2HXJTQNwxcsYfK36GrTEE

#ifndef typedef_visioncodegen_BlobAnalysis_ra_T
#define typedef_visioncodegen_BlobAnalysis_ra_T

typedef struct mdM2HXJTQNwxcsYfK36GrTEE visioncodegen_BlobAnalysis_ra_T;

#endif                                 //typedef_visioncodegen_BlobAnalysis_ra_T

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} ros_slros_internal_block_Publ_T;

#endif                                 //typedef_ros_slros_internal_block_Publ_T

// Custom Type definition for MATLAB Function: '<S12>/MATLAB Function'
#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 //struct_tag_sJCxfmxS8gBOONUZjbjUd9E

#ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E_rasbe_T
#define typedef_sJCxfmxS8gBOONUZjbjUd9E_rasbe_T

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E_rasbe_T;

#endif                                 //typedef_sJCxfmxS8gBOONUZjbjUd9E_rasbe_T

// Parameters (default storage)
typedef struct P_rasberrypi_publish_T_ P_rasberrypi_publish_T;

// Forward declaration for rtModel
typedef struct tag_RTM_rasberrypi_publish_T RT_MODEL_rasberrypi_publish_T;

#endif                                // RTW_HEADER_rasberrypi_publish_types_h_

//
// File trailer for generated code.
//
// [EOF]
//

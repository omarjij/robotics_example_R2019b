//
// File: rasberrypi_publish.h
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
#ifndef RTW_HEADER_rasberrypi_publish_h_
#define RTW_HEADER_rasberrypi_publish_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef rasberrypi_publish_COMMON_INCLUDES_
# define rasberrypi_publish_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_pigs.h"
#include "slros_initialize.h"
#include "v4l2_capture.h"
#endif                                 // rasberrypi_publish_COMMON_INCLUDES_

#include "rasberrypi_publish_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_rasberrypi_publish_sensor_msgs_Image msg;// '<S1>/MATLAB Function'
  uint8_T DrawMarkers[57600];          // '<S15>/Draw Markers'
  boolean_T bv[19200];
  real_T varargout_1_data[20];
  real_T varargout_2_data[10];
  char_T cv[53];
  char_T cv1[53];
  real_T obj_angle;                    // '<S3>/Tracking Controller'
  uint8_T PackChannels[57600];         // '<Root>/Pack Channels'
  real_T ex_data;
  real_T x;                            // '<S12>/MATLAB Function'
  real_T y;                            // '<S12>/MATLAB Function'
  real_T d;
  real_T xs;
  real_T ys;
  real_T xys;
  real_T xc;
  real_T yc;
  real_T centroid_idx_0;
  real_T centroid_idx_1;
  int32_T varargout_2_size[2];
  int32_T varargout_1_size[2];
  int32_T rowCtr;
  int32_T colCtr;
  int32_T row;
  int32_T col;
  int32_T err;
  int32_T rowDif;
  int32_T colDif;
  int32_T idxPix;
  int32_T ret;
  int32_T rtb_VectorConcatenate_idx_1;
  int32_T i;
  int32_T loop;
  int32_T i_m;
  uint32_T FixPtSum1;                  // '<S9>/FixPt Sum1'
} B_rasberrypi_publish_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  visioncodegen_BlobAnalysis_ra_T detector;// '<S12>/MATLAB Function'
  raspi_internal_ServoBlock_ras_T obj; // '<Root>/Standard Servo Write'
  ros_slros_internal_block_Publ_T obj_j;// '<S5>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_e;// '<S4>/SinkBlock'
  real_T MAX_ANGLE;                    // '<S3>/Tracking Controller'
  real_T i;                            // '<S3>/Tracking Controller'
  real_T direction;                    // '<S3>/Tracking Controller'
  uint32_T Output_DSTATE;              // '<S7>/Output'
  uint8_T is_active_c3_rasberrypi_publish;// '<S3>/Tracking Controller'
  uint8_T is_c3_rasberrypi_publish;    // '<S3>/Tracking Controller'
} DW_rasberrypi_publish_T;

// Constant parameters (default storage)
typedef struct {
  // Expression: devName
  //  Referenced by: '<Root>/V4L2 Video Capture'

  uint8_T V4L2VideoCapture_p1[12];
} ConstP_rasberrypi_publish_T;

// Parameters (default storage)
struct P_rasberrypi_publish_T_ {
  int32_T DrawMarkers_size;            // Mask Parameter: DrawMarkers_size
                                          //  Referenced by: '<S15>/Draw Markers'

  uint32_T WrapToZero_Threshold;       // Mask Parameter: WrapToZero_Threshold
                                          //  Referenced by: '<S10>/FixPt Switch'

  SL_Bus_rasberrypi_publish_sensor_msgs_Image Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S6>/Constant'

  SL_Bus_rasberrypi_publish_std_msgs_UInt8 Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                               //  Referenced by: '<S11>/Constant'

  real_T StandardServoWrite_MinPulseDura;// Expression: MinPulseDuration
                                            //  Referenced by: '<Root>/Standard Servo Write'

  real_T StandardServoWrite_MaxPulseDura;// Expression: MaxPulseDuration
                                            //  Referenced by: '<Root>/Standard Servo Write'

  real_T Constant_Value_ep;            // Expression: 0
                                          //  Referenced by: '<S13>/Constant'

  real_T Dir_Gain;                     // Expression: -1
                                          //  Referenced by: '<S3>/Dir'

  real_T Offset_Value;                 // Expression: 90
                                          //  Referenced by: '<S3>/Offset'

  uint32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S10>/Constant'

  uint32_T Output_InitialCondition;
                                  // Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S7>/Output'

  uint32_T FixPtConstant_Value;       // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S9>/FixPt Constant'

};

// Real-time Model Data Structure
struct tag_RTM_rasberrypi_publish_T {
  const char_T *errorStatus;
};

// Constant parameters (default storage)
extern const ConstP_rasberrypi_publish_T rasberrypi_publish_ConstP;

// Class declaration for model rasberrypi_publish
class publish_cameraModelClass {
  // public data and function members
 public:
  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  publish_cameraModelClass();

  // Destructor
  ~publish_cameraModelClass();

  // Real-Time Model get method
  RT_MODEL_rasberrypi_publish_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  static P_rasberrypi_publish_T rasberrypi_publish_P;

  // Block signals
  B_rasberrypi_publish_T rasberrypi_publish_B;

  // Block states
  DW_rasberrypi_publish_T rasberrypi_publish_DW;

  // Real-Time Model
  RT_MODEL_rasberrypi_publish_T rasberrypi_publish_M;

  // private member function(s) for subsystem '<Root>'
  void rasberr_BlobAnalysis_outputImpl(visioncodegen_BlobAnalysis_ra_T *obj,
    const boolean_T varargin_1[19200], real_T varargout_1_data[], int32_T
    varargout_1_size[2], real_T varargout_2_data[], int32_T varargout_2_size[2]);
  real_T rasberrypi_publish_objAngle(real_T pos);
  real_T rasberrypi_publish_setDir(real_T position);
  void matlabCodegenHandle_matlabCod_i(ros_slros_internal_block_Publ_T *obj);
  void rasberrypi_p_SystemCore_release(const raspi_internal_ServoBlock_ras_T
    *obj);
  void rasberrypi_pu_SystemCore_delete(const raspi_internal_ServoBlock_ras_T
    *obj);
  void matlabCodegenHandle_matlabCodeg(raspi_internal_ServoBlock_ras_T *obj);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/FixPt Data Type Propagation' : Unused code path elimination
//  Block '<S9>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S1>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'rasberrypi_publish'
//  '<S1>'   : 'rasberrypi_publish/Convert to //camera ROS message'
//  '<S2>'   : 'rasberrypi_publish/Convert to ROS message'
//  '<S3>'   : 'rasberrypi_publish/Image Processing and Controller Algorithm'
//  '<S4>'   : 'rasberrypi_publish/Publish'
//  '<S5>'   : 'rasberrypi_publish/Publish1'
//  '<S6>'   : 'rasberrypi_publish/Convert to //camera ROS message/Blank Message'
//  '<S7>'   : 'rasberrypi_publish/Convert to //camera ROS message/Counter Free-Running'
//  '<S8>'   : 'rasberrypi_publish/Convert to //camera ROS message/MATLAB Function'
//  '<S9>'   : 'rasberrypi_publish/Convert to //camera ROS message/Counter Free-Running/Increment Real World'
//  '<S10>'  : 'rasberrypi_publish/Convert to //camera ROS message/Counter Free-Running/Wrap To Zero'
//  '<S11>'  : 'rasberrypi_publish/Convert to ROS message/Blank Message1'
//  '<S12>'  : 'rasberrypi_publish/Image Processing and Controller Algorithm/Blob Detection'
//  '<S13>'  : 'rasberrypi_publish/Image Processing and Controller Algorithm/Compare To Zero'
//  '<S14>'  : 'rasberrypi_publish/Image Processing and Controller Algorithm/Tracking Controller'
//  '<S15>'  : 'rasberrypi_publish/Image Processing and Controller Algorithm/Vision Results Processing Subsystem'
//  '<S16>'  : 'rasberrypi_publish/Image Processing and Controller Algorithm/Blob Detection/MATLAB Function'

#endif                                 // RTW_HEADER_rasberrypi_publish_h_

//
// File trailer for generated code.
//
// [EOF]
//

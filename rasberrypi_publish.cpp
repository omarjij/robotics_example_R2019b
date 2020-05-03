//
// File: rasberrypi_publish.cpp
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
#include "rasberrypi_publish.h"
#include "rasberrypi_publish_private.h"

// Named constants for Chart: '<S3>/Tracking Controller'
const uint8_T rasberrypi_p_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T rasberrypi_publish_IN_Seeking = 1U;
const uint8_T rasberrypi_publish_IN_Tracking = 2U;
const uint8_T rasberrypi_publish_IN_Waiting = 3U;

// Function for MATLAB Function: '<S12>/MATLAB Function'
void publish_cameraModelClass::rasberr_BlobAnalysis_outputImpl
  (visioncodegen_BlobAnalysis_ra_T *obj, const boolean_T varargin_1[19200],
   real_T varargout_1_data[], int32_T varargout_1_size[2], real_T
   varargout_2_data[], int32_T varargout_2_size[2])
{
  vision_BlobAnalysis_0_rasberr_T *b_obj;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T n;
  int32_T m;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T padIdx;
  uint32_T walkerIdx;
  int32_T ns;
  int32_T ms;
  int32_T j;
  int32_T numLoops;
  int32_T p;
  b_obj = &obj->cSFunObject;

  // System object Outputs function: vision.BlobAnalysis
  maxNumBlobsReached = false;
  for (rasberrypi_publish_B.loop = 0; rasberrypi_publish_B.loop < 163;
       rasberrypi_publish_B.loop++) {
    b_obj->W3_PAD_DW[rasberrypi_publish_B.loop] = 0U;
  }

  currentLabel = 1U;
  rasberrypi_publish_B.i_m = 0;
  rasberrypi_publish_B.loop = 163;
  for (n = 0; n < 120; n++) {
    for (m = 0; m < 160; m++) {
      b_obj->W3_PAD_DW[rasberrypi_publish_B.loop] = static_cast<uint8_T>
        ((varargin_1[rasberrypi_publish_B.i_m] ? 255 : 0));
      rasberrypi_publish_B.i_m++;
      rasberrypi_publish_B.loop++;
    }

    b_obj->W3_PAD_DW[rasberrypi_publish_B.loop] = 0U;
    b_obj->W3_PAD_DW[rasberrypi_publish_B.loop + 1] = 0U;
    rasberrypi_publish_B.loop += 2;
  }

  for (rasberrypi_publish_B.i_m = 0; rasberrypi_publish_B.i_m < 161;
       rasberrypi_publish_B.i_m++) {
    b_obj->W3_PAD_DW[rasberrypi_publish_B.i_m + rasberrypi_publish_B.loop] = 0U;
  }

  rasberrypi_publish_B.loop = 1;
  pixIdx = 0U;
  rasberrypi_publish_B.i_m = 0;
  while (rasberrypi_publish_B.i_m < 120) {
    n = 1;
    m = rasberrypi_publish_B.loop * 162;
    ns = 0;
    while (ns < 160) {
      padIdx = static_cast<uint32_T>((m + n));
      start_pixIdx = pixIdx;
      if (b_obj->W3_PAD_DW[padIdx] == 255) {
        b_obj->W3_PAD_DW[padIdx] = currentLabel;
        b_obj->W0_N_PIXLIST_DW[pixIdx] = static_cast<int16_T>
          ((rasberrypi_publish_B.loop - 1));
        b_obj->W1_M_PIXLIST_DW[pixIdx] = static_cast<int16_T>((n - 1));
        pixIdx++;
        numLoops = currentLabel - 1;
        b_obj->W2_NUM_PIX_DW[numLoops] = 1U;
        b_obj->W4_STACK_DW[0U] = padIdx;
        stackIdx = 1U;
        while (stackIdx != 0U) {
          stackIdx--;
          padIdx = b_obj->W4_STACK_DW[stackIdx];
          for (ms = 0; ms < 8; ms++) {
            walkerIdx = padIdx + b_obj->P0_WALKER_RTP[ms];
            if (b_obj->W3_PAD_DW[walkerIdx] == 255) {
              b_obj->W3_PAD_DW[walkerIdx] = currentLabel;
              b_obj->W0_N_PIXLIST_DW[pixIdx] = static_cast<int16_T>((
                static_cast<int16_T>((walkerIdx / 162U)) - 1));
              b_obj->W1_M_PIXLIST_DW[pixIdx] = static_cast<int16_T>((walkerIdx %
                162U - 1U));
              pixIdx++;
              b_obj->W2_NUM_PIX_DW[numLoops]++;
              b_obj->W4_STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (b_obj->W2_NUM_PIX_DW[numLoops] < 300U) {
          currentLabel = static_cast<uint8_T>(numLoops);
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 10) {
          maxNumBlobsReached = true;
          rasberrypi_publish_B.i_m = 120;
          ns = 160;
        } else {
          currentLabel = static_cast<uint8_T>((currentLabel + 1));
        }
      }

      n++;
      ns++;
    }

    rasberrypi_publish_B.loop++;
    rasberrypi_publish_B.i_m++;
  }

  rasberrypi_publish_B.loop = maxNumBlobsReached ? static_cast<int32_T>
    (currentLabel) : static_cast<int32_T>(static_cast<uint8_T>((currentLabel -
    1U)));
  rasberrypi_publish_B.i_m = 0;
  n = 0;
  for (m = 0; m < rasberrypi_publish_B.loop; m++) {
    ns = 0;
    ms = 0;
    if (b_obj->W2_NUM_PIX_DW[m] <= 260000U) {
      for (j = 0; j < static_cast<int32_T>(b_obj->W2_NUM_PIX_DW[m]); j++) {
        ns += b_obj->W0_N_PIXLIST_DW[j + n];
        ms += b_obj->W1_M_PIXLIST_DW[j + rasberrypi_publish_B.i_m];
      }

      rasberrypi_publish_B.centroid_idx_0 = static_cast<real_T>(ms) /
        static_cast<real_T>(b_obj->W2_NUM_PIX_DW[m]);
      rasberrypi_publish_B.centroid_idx_1 = static_cast<real_T>(ns) /
        static_cast<real_T>(b_obj->W2_NUM_PIX_DW[m]);
    } else {
      numLoops = static_cast<int32_T>((static_cast<real_T>(b_obj->
        W2_NUM_PIX_DW[m]) / 260000.0));
      rasberrypi_publish_B.centroid_idx_0 = 0.0;
      rasberrypi_publish_B.centroid_idx_1 = 0.0;
      for (p = 0; p < numLoops; p++) {
        ns = 0;
        ms = 0;
        for (j = 0; j < 260000; j++) {
          ns += b_obj->W0_N_PIXLIST_DW[(n + j) + p * 260000];
          ms += b_obj->W1_M_PIXLIST_DW[(rasberrypi_publish_B.i_m + j) + p *
            260000];
        }

        rasberrypi_publish_B.centroid_idx_0 += static_cast<real_T>(ms) /
          static_cast<real_T>(b_obj->W2_NUM_PIX_DW[m]);
        rasberrypi_publish_B.centroid_idx_1 += static_cast<real_T>(ns) /
          static_cast<real_T>(b_obj->W2_NUM_PIX_DW[m]);
      }

      ns = 0;
      ms = 0;
      numLoops *= 260000;
      p = static_cast<int32_T>((b_obj->W2_NUM_PIX_DW[m] - numLoops));
      for (j = 0; j < p; j++) {
        ns += b_obj->W0_N_PIXLIST_DW[(j + n) + numLoops];
        ms += b_obj->W1_M_PIXLIST_DW[(j + rasberrypi_publish_B.i_m) + numLoops];
      }

      rasberrypi_publish_B.centroid_idx_0 += static_cast<real_T>(ms) /
        static_cast<real_T>(b_obj->W2_NUM_PIX_DW[m]);
      rasberrypi_publish_B.centroid_idx_1 += static_cast<real_T>(ns) /
        static_cast<real_T>(b_obj->W2_NUM_PIX_DW[m]);
    }

    varargout_1_data[m] = rasberrypi_publish_B.centroid_idx_1 + 1.0;
    varargout_1_data[static_cast<uint32_T>(rasberrypi_publish_B.loop) + m] =
      rasberrypi_publish_B.centroid_idx_0 + 1.0;
    rasberrypi_publish_B.xs = 0.0;
    rasberrypi_publish_B.ys = 0.0;
    rasberrypi_publish_B.xys = 0.0;
    for (stackIdx = 0U; static_cast<int32_T>(stackIdx) < static_cast<int32_T>
         (b_obj->W2_NUM_PIX_DW[m]); stackIdx++) {
      rasberrypi_publish_B.xc = static_cast<real_T>(b_obj->W0_N_PIXLIST_DW[n +
        static_cast<int32_T>(stackIdx)]) - rasberrypi_publish_B.centroid_idx_1;
      rasberrypi_publish_B.yc = static_cast<real_T>(b_obj->
        W1_M_PIXLIST_DW[rasberrypi_publish_B.i_m + static_cast<int32_T>(stackIdx)])
        - rasberrypi_publish_B.centroid_idx_0;
      rasberrypi_publish_B.xs += rasberrypi_publish_B.xc *
        rasberrypi_publish_B.xc;
      rasberrypi_publish_B.ys += rasberrypi_publish_B.yc *
        rasberrypi_publish_B.yc;
      rasberrypi_publish_B.xys += rasberrypi_publish_B.xc *
        -rasberrypi_publish_B.yc;
    }

    rasberrypi_publish_B.xs = rasberrypi_publish_B.xs / static_cast<real_T>
      (b_obj->W2_NUM_PIX_DW[m]) + 0.083333333333333329;
    rasberrypi_publish_B.ys = rasberrypi_publish_B.ys / static_cast<real_T>
      (b_obj->W2_NUM_PIX_DW[m]) + 0.083333333333333329;
    rasberrypi_publish_B.xys /= static_cast<real_T>(b_obj->W2_NUM_PIX_DW[m]);
    rasberrypi_publish_B.centroid_idx_0 = rasberrypi_publish_B.xs -
      rasberrypi_publish_B.ys;
    varargout_2_data[m] = sqrt((sqrt(rasberrypi_publish_B.centroid_idx_0 *
      rasberrypi_publish_B.centroid_idx_0 + rasberrypi_publish_B.xys *
      rasberrypi_publish_B.xys * 4.0) + (rasberrypi_publish_B.xs +
      rasberrypi_publish_B.ys)) * 8.0);
    rasberrypi_publish_B.i_m += static_cast<int32_T>(b_obj->W2_NUM_PIX_DW[m]);
    n += static_cast<int32_T>(b_obj->W2_NUM_PIX_DW[m]);
  }

  varargout_1_size[0] = rasberrypi_publish_B.loop;
  varargout_1_size[1] = 2;
  varargout_2_size[0] = rasberrypi_publish_B.loop;
  varargout_2_size[1] = 1;
}

//
// Function for Chart: '<S3>/Tracking Controller'
// function a = objAngle(pos)
//
real_T publish_cameraModelClass::rasberrypi_publish_objAngle(real_T pos)
{
  real_T a;

  // MATLAB Function 'objAngle': '<S14>:93'
  // '<S14>:93:3' deadZone = 0.2;
  // '<S14>:93:5' a =(pos - 160)/160;
  a = (pos - 160.0) / 160.0;

  // '<S14>:93:7' if abs(a)<(deadZone/2)
  if (fabs(a) < 0.1) {
    // '<S14>:93:8' a=0;
    a = 0.0;
  }

  return a;
}

//
// Function for Chart: '<S3>/Tracking Controller'
// function dir = setDir(position)
//
real_T publish_cameraModelClass::rasberrypi_publish_setDir(real_T position)
{
  real_T dir;

  // MATLAB Function 'setDir': '<S14>:114'
  // Graphical Function 'setDir': '<S14>:114'
  // '<S14>:95:1' sf_internal_predicateOutput = position > 160;
  if (position > 160.0) {
    // '<S14>:111:1' dir = 1
    dir = 1.0;
  } else {
    // '<S14>:129:1' dir = -1
    dir = -1.0;
  }

  return dir;
}

void publish_cameraModelClass::matlabCodegenHandle_matlabCod_i
  (ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void publish_cameraModelClass::rasberrypi_p_SystemCore_release(const
  raspi_internal_ServoBlock_ras_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete && obj->Initialized) {
    EXT_SERVO_terminate(obj->PinNumber);
  }
}

void publish_cameraModelClass::rasberrypi_pu_SystemCore_delete(const
  raspi_internal_ServoBlock_ras_T *obj)
{
  rasberrypi_p_SystemCore_release(obj);
}

void publish_cameraModelClass::matlabCodegenHandle_matlabCodeg
  (raspi_internal_ServoBlock_ras_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    rasberrypi_pu_SystemCore_delete(obj);
  }
}

// Model step function
void publish_cameraModelClass::step()
{
  int8_T idx_data;
  boolean_T rtb_Compare;
  SL_Bus_rasberrypi_publish_std_msgs_UInt8 rtb_BusAssignment;
  static const char_T tmp[53] =
    "Unable to configure pin %u for servo pulse output.\\n";

  // S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture'
  MW_videoCaptureOutput(rasberrypi_publish_ConstP.V4L2VideoCapture_p1,
                        &rasberrypi_publish_B.PackChannels[0],
                        &rasberrypi_publish_B.PackChannels[19200],
                        &rasberrypi_publish_B.PackChannels[38400]);

  // DataTypeConversion: '<S15>/Data Type Conversion3'
  memcpy(&rasberrypi_publish_B.DrawMarkers[0],
         &rasberrypi_publish_B.PackChannels[0], 57600U * sizeof(uint8_T));

  // MATLAB Function: '<S12>/MATLAB Function'
  // #Codegen
  // MATLAB Function 'Image Processing and Controller Algorithm/Blob Detection/MATLAB Function': '<S16>:1' 
  //  This funtcion thresholds the image based on threshold values submitted by
  //  the user
  //  Setup the detector and initialize variables
  // '<S16>:1:9' if isempty(detector)
  // '<S16>:1:14' x = 0;
  rasberrypi_publish_B.x = 0.0;

  // '<S16>:1:15' y = 0;
  rasberrypi_publish_B.y = 0.0;

  // '<S16>:1:16' threshold = [75 115; 126 202; 80 186];
  //  Threshold the image
  // frameIn = rgb2ycbcr(frameIn);
  // '<S16>:1:20' mask = (frameIn (:,:,1) >= threshold(1,1))& (frameIn (:,:,1) <= threshold(1,2))&... 
  // '<S16>:1:21'     (frameIn (:,:,2) >= threshold(2,1))& (frameIn (:,:,2) <= threshold(2,2))&... 
  // '<S16>:1:22'     (frameIn (:,:,3) >= threshold(3,1))& (frameIn (:,:,3) <= threshold(3,2)); 
  // '<S16>:1:24' [centroid,majorAxis] = detector(mask);
  for (rasberrypi_publish_B.ret = 0; rasberrypi_publish_B.ret < 120;
       rasberrypi_publish_B.ret++) {
    for (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 = 0;
         rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 < 160;
         rasberrypi_publish_B.rtb_VectorConcatenate_idx_1++) {
      rasberrypi_publish_B.i = 160 * rasberrypi_publish_B.ret +
        rasberrypi_publish_B.rtb_VectorConcatenate_idx_1;
      rasberrypi_publish_B.rowCtr = rasberrypi_publish_B.i + 19200;
      rasberrypi_publish_B.colCtr = rasberrypi_publish_B.i + 38400;
      rasberrypi_publish_B.bv[rasberrypi_publish_B.i] =
        ((rasberrypi_publish_B.PackChannels[rasberrypi_publish_B.i] >= 75) &&
         (rasberrypi_publish_B.PackChannels[rasberrypi_publish_B.i] <= 115) &&
         (rasberrypi_publish_B.PackChannels[rasberrypi_publish_B.rowCtr] >= 126)
         && (rasberrypi_publish_B.PackChannels[rasberrypi_publish_B.rowCtr] <=
             202) &&
         (rasberrypi_publish_B.PackChannels[rasberrypi_publish_B.colCtr] >= 80) &&
         (rasberrypi_publish_B.PackChannels[rasberrypi_publish_B.colCtr] <= 186));
    }
  }

  rasberr_BlobAnalysis_outputImpl(&rasberrypi_publish_DW.detector,
    rasberrypi_publish_B.bv, rasberrypi_publish_B.varargout_1_data,
    rasberrypi_publish_B.varargout_1_size, rasberrypi_publish_B.varargout_2_data,
    rasberrypi_publish_B.varargout_2_size);

  // '<S16>:1:26' if ~isempty(majorAxis)
  if ((rasberrypi_publish_B.varargout_2_size[0] != 0) &&
      (rasberrypi_publish_B.varargout_2_size[1] != 0)) {
    //  Identify Largest Blob
    // '<S16>:1:28' [~,mIdx] = max(majorAxis);
    idx_data = 1;
    rasberrypi_publish_B.ex_data = rasberrypi_publish_B.varargout_2_data[0];
    rasberrypi_publish_B.ret = 2;
    while (rasberrypi_publish_B.ret <= rasberrypi_publish_B.varargout_2_size[0])
    {
      rasberrypi_publish_B.x =
        rasberrypi_publish_B.varargout_2_data[rasberrypi_publish_B.ret - 1];
      if ((!rtIsNaN(rasberrypi_publish_B.x)) && (rtIsNaN
           (rasberrypi_publish_B.ex_data) || (rasberrypi_publish_B.ex_data <
            rasberrypi_publish_B.x))) {
        rasberrypi_publish_B.ex_data = rasberrypi_publish_B.x;
        idx_data = static_cast<int8_T>(rasberrypi_publish_B.ret);
      }

      rasberrypi_publish_B.ret++;
    }

    // '<S16>:1:28' ~
    // '<S16>:1:29' C = centroid(mIdx,:);
    // '<S16>:1:30' x = double(C(1));
    rasberrypi_publish_B.ret = idx_data;
    rasberrypi_publish_B.x =
      rasberrypi_publish_B.varargout_1_data[rasberrypi_publish_B.ret - 1];

    // '<S16>:1:31' y = double(C(2));
    rasberrypi_publish_B.y = rasberrypi_publish_B.varargout_1_data
      [(rasberrypi_publish_B.ret + rasberrypi_publish_B.varargout_1_size[0]) - 1];
  }

  // End of MATLAB Function: '<S12>/MATLAB Function'

  // DataTypeConversion: '<S15>/Data Type Conversion1'
  rasberrypi_publish_B.d = floor(rasberrypi_publish_B.x);
  if (rtIsNaN(rasberrypi_publish_B.d) || rtIsInf(rasberrypi_publish_B.d)) {
    rasberrypi_publish_B.d = 0.0;
  } else {
    rasberrypi_publish_B.d = fmod(rasberrypi_publish_B.d, 4.294967296E+9);
  }

  rasberrypi_publish_B.ret = rasberrypi_publish_B.d < 0.0 ? -static_cast<int32_T>
    (static_cast<uint32_T>(-rasberrypi_publish_B.d)) : static_cast<int32_T>(
    static_cast<uint32_T>(rasberrypi_publish_B.d));

  // End of DataTypeConversion: '<S15>/Data Type Conversion1'

  // DataTypeConversion: '<S15>/Data Type Conversion2'
  rasberrypi_publish_B.d = floor(rasberrypi_publish_B.y);
  if (rtIsNaN(rasberrypi_publish_B.d) || rtIsInf(rasberrypi_publish_B.d)) {
    rasberrypi_publish_B.d = 0.0;
  } else {
    rasberrypi_publish_B.d = fmod(rasberrypi_publish_B.d, 4.294967296E+9);
  }

  rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 = rasberrypi_publish_B.d <
    0.0 ? -static_cast<int32_T>(static_cast<uint32_T>(-rasberrypi_publish_B.d)) :
    static_cast<int32_T>(static_cast<uint32_T>(rasberrypi_publish_B.d));

  // End of DataTypeConversion: '<S15>/Data Type Conversion2'

  // S-Function (svipdrawmarkers): '<S15>/Draw Markers'
  // Update view port.
  rasberrypi_publish_B.rowCtr = rasberrypi_publish_B.rtb_VectorConcatenate_idx_1
    - 1;
  rasberrypi_publish_B.colCtr = rasberrypi_publish_B.ret - 1;
  if ((rasberrypi_publish_P.DrawMarkers_size >= 0) &&
      (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 - 1 >=
       -rasberrypi_publish_P.DrawMarkers_size) &&
      (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 - 1 <=
       rasberrypi_publish_P.DrawMarkers_size + 159) && (rasberrypi_publish_B.ret
       - 1 >= -rasberrypi_publish_P.DrawMarkers_size) &&
      (rasberrypi_publish_B.ret - 1 <= rasberrypi_publish_P.DrawMarkers_size +
       119)) {
    rasberrypi_publish_B.err = 1 - rasberrypi_publish_P.DrawMarkers_size;
    rasberrypi_publish_B.rowDif = 1;
    rasberrypi_publish_B.colDif = -2 * rasberrypi_publish_P.DrawMarkers_size;
    rasberrypi_publish_B.row = 0;
    rasberrypi_publish_B.col = rasberrypi_publish_P.DrawMarkers_size;
    while ((rasberrypi_publish_B.row <= rasberrypi_publish_B.col) ||
           ((rasberrypi_publish_P.DrawMarkers_size == 1) &&
            (rasberrypi_publish_B.row <= 1))) {
      rasberrypi_publish_B.ret = rasberrypi_publish_B.colCtr -
        rasberrypi_publish_B.row;
      rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 =
        rasberrypi_publish_B.rowCtr - rasberrypi_publish_B.col;
      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 >= 0) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 <= 159)) {
        rasberrypi_publish_B.idxPix = (rasberrypi_publish_B.ret * 160 +
          rasberrypi_publish_B.rowCtr) - rasberrypi_publish_B.col;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      rasberrypi_publish_B.i = rasberrypi_publish_B.rowCtr +
        rasberrypi_publish_B.col;
      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.i >= 0) && (rasberrypi_publish_B.i <= 159)) {
        rasberrypi_publish_B.idxPix = ((rasberrypi_publish_B.colCtr -
          rasberrypi_publish_B.row) * 160 + rasberrypi_publish_B.rowCtr) +
          rasberrypi_publish_B.col;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      rasberrypi_publish_B.ret = rasberrypi_publish_B.colCtr +
        rasberrypi_publish_B.row;
      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 >= 0) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 <= 159)) {
        rasberrypi_publish_B.idxPix = (rasberrypi_publish_B.ret * 160 +
          rasberrypi_publish_B.rowCtr) - rasberrypi_publish_B.col;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.i >= 0) && (rasberrypi_publish_B.i <= 159)) {
        rasberrypi_publish_B.idxPix = ((rasberrypi_publish_B.colCtr +
          rasberrypi_publish_B.row) * 160 + rasberrypi_publish_B.rowCtr) +
          rasberrypi_publish_B.col;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      rasberrypi_publish_B.ret = rasberrypi_publish_B.colCtr -
        rasberrypi_publish_B.col;
      rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 =
        rasberrypi_publish_B.rowCtr - rasberrypi_publish_B.row;
      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 >= 0) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 <= 159)) {
        rasberrypi_publish_B.idxPix = (rasberrypi_publish_B.ret * 160 +
          rasberrypi_publish_B.rowCtr) - rasberrypi_publish_B.row;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      rasberrypi_publish_B.i = rasberrypi_publish_B.rowCtr +
        rasberrypi_publish_B.row;
      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.i >= 0) && (rasberrypi_publish_B.i <= 159)) {
        rasberrypi_publish_B.idxPix = ((rasberrypi_publish_B.colCtr -
          rasberrypi_publish_B.col) * 160 + rasberrypi_publish_B.rowCtr) +
          rasberrypi_publish_B.row;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      rasberrypi_publish_B.ret = rasberrypi_publish_B.colCtr +
        rasberrypi_publish_B.col;
      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 >= 0) &&
          (rasberrypi_publish_B.rtb_VectorConcatenate_idx_1 <= 159)) {
        rasberrypi_publish_B.idxPix = (rasberrypi_publish_B.ret * 160 +
          rasberrypi_publish_B.rowCtr) - rasberrypi_publish_B.row;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      if ((rasberrypi_publish_B.ret >= 0) && (rasberrypi_publish_B.ret <= 119) &&
          (rasberrypi_publish_B.i >= 0) && (rasberrypi_publish_B.i <= 159)) {
        rasberrypi_publish_B.idxPix = ((rasberrypi_publish_B.colCtr +
          rasberrypi_publish_B.col) * 160 + rasberrypi_publish_B.rowCtr) +
          rasberrypi_publish_B.row;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
        rasberrypi_publish_B.idxPix += 19200;
        rasberrypi_publish_B.DrawMarkers[rasberrypi_publish_B.idxPix] = 0U;
      }

      if (rasberrypi_publish_B.err >= 0) {
        rasberrypi_publish_B.col--;
        rasberrypi_publish_B.colDif += 2;
        rasberrypi_publish_B.err += rasberrypi_publish_B.colDif;
      }

      rasberrypi_publish_B.rowDif += 2;
      rasberrypi_publish_B.err += rasberrypi_publish_B.rowDif;
      rasberrypi_publish_B.row++;
    }
  }

  // End of S-Function (svipdrawmarkers): '<S15>/Draw Markers'

  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   Constant: '<S6>/Constant'
  //   DataTypeConversion: '<S15>/Data Type Conversion'
  //   UnitDelay: '<S7>/Output'

  //  Set width and height
  // MATLAB Function 'Convert to //camera ROS message/MATLAB Function': '<S8>:1' 
  // '<S8>:1:5' msg = blankMsg;
  rasberrypi_publish_B.msg = rasberrypi_publish_P.Constant_Value;

  // '<S8>:1:6' msg.Width = uint32(160);
  rasberrypi_publish_B.msg.Width = 160U;

  // '<S8>:1:7' msg.Height = uint32(120);
  rasberrypi_publish_B.msg.Height = 120U;

  //  Published RGB8 image encoding
  // '<S8>:1:10' msg.Encoding_SL_Info.CurrentLength = uint32(4);
  rasberrypi_publish_B.msg.Encoding_SL_Info.CurrentLength = 4U;

  // '<S8>:1:11' msg.Encoding = uint8('rgb8')';
  rasberrypi_publish_B.msg.Encoding[0] = 114U;
  rasberrypi_publish_B.msg.Encoding[1] = 103U;
  rasberrypi_publish_B.msg.Encoding[2] = 98U;
  rasberrypi_publish_B.msg.Encoding[3] = 56U;

  //  Size of image buffer
  // '<S8>:1:14' msg.Data_SL_Info.CurrentLength = uint32(57600);
  rasberrypi_publish_B.msg.Data_SL_Info.CurrentLength = 57600U;

  // '<S8>:1:15' msg.Data = Y;
  memcpy(&rasberrypi_publish_B.msg.Data[0], &rasberrypi_publish_B.DrawMarkers[0],
         57600U * sizeof(uint8_T));

  //  Sequence number
  // '<S8>:1:18' msg.Header.Seq = seq;
  rasberrypi_publish_B.msg.Header.Seq = rasberrypi_publish_DW.Output_DSTATE;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_rasberrypi_publish_1.publish(&rasberrypi_publish_B.msg);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // RelationalOperator: '<S13>/Compare' incorporates:
  //   Constant: '<S13>/Constant'

  rtb_Compare = (rasberrypi_publish_B.y > rasberrypi_publish_P.Constant_Value_ep);

  // Chart: '<S3>/Tracking Controller'
  // Gateway: Image Processing and Controller Algorithm/Tracking Controller
  // During: Image Processing and Controller Algorithm/Tracking Controller
  if (rasberrypi_publish_DW.is_active_c3_rasberrypi_publish == 0U) {
    // Entry: Image Processing and Controller Algorithm/Tracking Controller
    rasberrypi_publish_DW.is_active_c3_rasberrypi_publish = 1U;

    // Entry Internal: Image Processing and Controller Algorithm/Tracking Controller 
    // Transition: '<S14>:115'
    rasberrypi_publish_DW.is_c3_rasberrypi_publish =
      rasberrypi_publish_IN_Tracking;

    // Entry 'Tracking': '<S14>:118'
    // '<S14>:118:3' obj_angle = objAngle(obj_pos)*50;
    rasberrypi_publish_B.obj_angle = rasberrypi_publish_objAngle
      (rasberrypi_publish_B.y) * 50.0;

    // '<S14>:118:4' direction = setDir(obj_pos);
    rasberrypi_publish_DW.direction = rasberrypi_publish_setDir
      (rasberrypi_publish_B.y);
  } else {
    switch (rasberrypi_publish_DW.is_c3_rasberrypi_publish) {
     case rasberrypi_publish_IN_Seeking:
      // During 'Seeking': '<S14>:109'
      // '<S14>:101:1' sf_internal_predicateOutput = valid;
      if (rtb_Compare) {
        // Transition: '<S14>:101'
        rasberrypi_publish_DW.is_c3_rasberrypi_publish =
          rasberrypi_publish_IN_Tracking;

        // Entry 'Tracking': '<S14>:118'
        // '<S14>:118:3' obj_angle = objAngle(obj_pos)*50;
        rasberrypi_publish_B.obj_angle = rasberrypi_publish_objAngle
          (rasberrypi_publish_B.y) * 50.0;

        // '<S14>:118:4' direction = setDir(obj_pos);
        rasberrypi_publish_DW.direction = rasberrypi_publish_setDir
          (rasberrypi_publish_B.y);
      } else {
        // Transition: '<S14>:100'
        // '<S14>:123:1' sf_internal_predicateOutput = direction==1;
        if (rasberrypi_publish_DW.direction == 1.0) {
          // Transition: '<S14>:123'
          // '<S14>:99:1' sf_internal_predicateOutput = obj_angle < MAX_ANGLE;
          if (rasberrypi_publish_B.obj_angle < rasberrypi_publish_DW.MAX_ANGLE)
          {
            // Transition: '<S14>:99'
            // '<S14>:99:2' obj_angle = obj_angle + 1;
            rasberrypi_publish_B.obj_angle++;
          } else {
            // Transition: '<S14>:128'
            // '<S14>:128:1' direction=-1;
            rasberrypi_publish_DW.direction = -1.0;
          }

          // Transition: '<S14>:130'
        } else {
          // Transition: '<S14>:94'
          // '<S14>:103:1' sf_internal_predicateOutput = obj_angle>-MAX_ANGLE;
          if (rasberrypi_publish_B.obj_angle > -rasberrypi_publish_DW.MAX_ANGLE)
          {
            // Transition: '<S14>:103'
            // '<S14>:103:2' obj_angle = obj_angle - 1;
            rasberrypi_publish_B.obj_angle--;
          } else {
            // Transition: '<S14>:124'
            // '<S14>:124:1' direction=1;
            rasberrypi_publish_DW.direction = 1.0;
          }

          // Transition: '<S14>:126'
        }
      }
      break;

     case rasberrypi_publish_IN_Tracking:
      // During 'Tracking': '<S14>:118'
      // '<S14>:127:1' sf_internal_predicateOutput = ~valid;
      if (!rtb_Compare) {
        // Transition: '<S14>:127'
        rasberrypi_publish_DW.is_c3_rasberrypi_publish =
          rasberrypi_publish_IN_Waiting;

        // Entry 'Waiting': '<S14>:125'
        // '<S14>:125:3' i =0;
        rasberrypi_publish_DW.i = 0.0;
      } else {
        // '<S14>:118:3' obj_angle = objAngle(obj_pos)*50;
        rasberrypi_publish_B.obj_angle = rasberrypi_publish_objAngle
          (rasberrypi_publish_B.y) * 50.0;

        // '<S14>:118:4' direction = setDir(obj_pos);
        rasberrypi_publish_DW.direction = rasberrypi_publish_setDir
          (rasberrypi_publish_B.y);
      }
      break;

     default:
      // During 'Waiting': '<S14>:125'
      // '<S14>:106:1' sf_internal_predicateOutput = i>5;
      if (rasberrypi_publish_DW.i > 5.0) {
        // Transition: '<S14>:106'
        rasberrypi_publish_DW.is_c3_rasberrypi_publish =
          rasberrypi_publish_IN_Seeking;

        // Entry 'Seeking': '<S14>:109'
      } else {
        // '<S14>:104:1' sf_internal_predicateOutput = valid;
        if (rtb_Compare) {
          // Transition: '<S14>:104'
          rasberrypi_publish_DW.is_c3_rasberrypi_publish =
            rasberrypi_publish_IN_Tracking;

          // Entry 'Tracking': '<S14>:118'
          // '<S14>:118:3' obj_angle = objAngle(obj_pos)*50;
          rasberrypi_publish_B.obj_angle = rasberrypi_publish_objAngle
            (rasberrypi_publish_B.y) * 50.0;

          // '<S14>:118:4' direction = setDir(obj_pos);
          rasberrypi_publish_DW.direction = rasberrypi_publish_setDir
            (rasberrypi_publish_B.y);
        } else {
          // '<S14>:125:5' i = i + 1;
          rasberrypi_publish_DW.i++;
        }
      }
      break;
    }
  }

  // End of Chart: '<S3>/Tracking Controller'

  // Sum: '<S3>/Sum' incorporates:
  //   Constant: '<S3>/Offset'
  //   Gain: '<S3>/Dir'

  rasberrypi_publish_B.x = rasberrypi_publish_P.Dir_Gain *
    rasberrypi_publish_B.obj_angle + rasberrypi_publish_P.Offset_Value;

  // DataTypeConversion: '<S2>/Data Type Conversion'
  rasberrypi_publish_B.d = floor(rasberrypi_publish_B.x);
  if (rtIsNaN(rasberrypi_publish_B.d) || rtIsInf(rasberrypi_publish_B.d)) {
    rasberrypi_publish_B.d = 0.0;
  } else {
    rasberrypi_publish_B.d = fmod(rasberrypi_publish_B.d, 256.0);
  }

  // BusAssignment: '<S2>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S2>/Data Type Conversion'

  rtb_BusAssignment.Data = static_cast<uint8_T>((rasberrypi_publish_B.d < 0.0 ?
    static_cast<int32_T>(static_cast<uint8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-rasberrypi_publish_B.d)))) : static_cast<int32_T>(
    static_cast<uint8_T>(rasberrypi_publish_B.d))));

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_rasberrypi_publish_103.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // MATLABSystem: '<Root>/Standard Servo Write'
  if (rasberrypi_publish_DW.obj.MinPulseDuration !=
      rasberrypi_publish_P.StandardServoWrite_MinPulseDura) {
    rasberrypi_publish_DW.obj.MinPulseDuration =
      rasberrypi_publish_P.StandardServoWrite_MinPulseDura;
  }

  if (rasberrypi_publish_DW.obj.MaxPulseDuration !=
      rasberrypi_publish_P.StandardServoWrite_MaxPulseDura) {
    rasberrypi_publish_DW.obj.MaxPulseDuration =
      rasberrypi_publish_P.StandardServoWrite_MaxPulseDura;
  }

  if ((rasberrypi_publish_B.x >= 0.0) && (rasberrypi_publish_B.x <= 180.0)) {
    if (!rasberrypi_publish_DW.obj.Initialized) {
      rasberrypi_publish_B.ret = EXT_SERVO_init
        (rasberrypi_publish_DW.obj.PinNumber);
      if (rasberrypi_publish_B.ret == 0) {
        rasberrypi_publish_DW.obj.Initialized = true;
      } else {
        for (rasberrypi_publish_B.ret = 0; rasberrypi_publish_B.ret < 53;
             rasberrypi_publish_B.ret++) {
          rasberrypi_publish_B.cv[rasberrypi_publish_B.ret] =
            tmp[rasberrypi_publish_B.ret];
        }

        printf(rasberrypi_publish_B.cv, rasberrypi_publish_DW.obj.PinNumber);
      }
    }

    EXT_SERVO_write(rasberrypi_publish_DW.obj.PinNumber, rasberrypi_publish_B.x,
                    1.0E+6 * rasberrypi_publish_DW.obj.MinPulseDuration, 1.0E+6 *
                    rasberrypi_publish_DW.obj.MaxPulseDuration);
  }

  // End of MATLABSystem: '<Root>/Standard Servo Write'

  // Sum: '<S9>/FixPt Sum1' incorporates:
  //   Constant: '<S9>/FixPt Constant'
  //   UnitDelay: '<S7>/Output'

  rasberrypi_publish_B.FixPtSum1 = rasberrypi_publish_DW.Output_DSTATE +
    rasberrypi_publish_P.FixPtConstant_Value;

  // Switch: '<S10>/FixPt Switch'
  if (rasberrypi_publish_B.FixPtSum1 > rasberrypi_publish_P.WrapToZero_Threshold)
  {
    // Update for UnitDelay: '<S7>/Output' incorporates:
    //   Constant: '<S10>/Constant'

    rasberrypi_publish_DW.Output_DSTATE = rasberrypi_publish_P.Constant_Value_b;
  } else {
    // Update for UnitDelay: '<S7>/Output'
    rasberrypi_publish_DW.Output_DSTATE = rasberrypi_publish_B.FixPtSum1;
  }

  // End of Switch: '<S10>/FixPt Switch'
}

// Model initialize function
void publish_cameraModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // block I/O
  (void) memset((static_cast<void *>(&rasberrypi_publish_B)), 0,
                sizeof(B_rasberrypi_publish_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&rasberrypi_publish_DW), 0,
                sizeof(DW_rasberrypi_publish_T));

  {
    int32_T ret;
    char_T tmp[13];
    char_T tmp_0[8];
    static const char_T tmp_1[7] = { '/', 'c', 'a', 'm', 'e', 'r', 'a' };

    static const char_T tmp_2[12] = { '/', 's', 'e', 'r', 'v', 'o', '_', 'a',
      'n', 'g', 'l', 'e' };

    static const char_T tmp_3[53] =
      "Unable to configure pin %u for servo pulse output.\\n";
    static const int16_T b[8] = { -1, 161, 162, 163, 1, -161, -162, -163 };

    // Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' 
    MW_videoCaptureInit(rasberrypi_publish_ConstP.V4L2VideoCapture_p1, 0, 0, 0,
                        0, 160U, 120U, 2U, 2U, 1U, 0.01);

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    rasberrypi_publish_DW.obj_e.matlabCodegenIsDeleted = false;
    rasberrypi_publish_DW.obj_e.isInitialized = 1;
    for (ret = 0; ret < 7; ret++) {
      tmp_0[ret] = tmp_1[ret];
    }

    tmp_0[7] = '\x00';
    Pub_rasberrypi_publish_1.createPublisher(tmp_0, 1);
    rasberrypi_publish_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // Start for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    rasberrypi_publish_DW.obj_j.matlabCodegenIsDeleted = false;
    rasberrypi_publish_DW.obj_j.isInitialized = 1;
    for (ret = 0; ret < 12; ret++) {
      tmp[ret] = tmp_2[ret];
    }

    tmp[12] = '\x00';
    Pub_rasberrypi_publish_103.createPublisher(tmp, 1);
    rasberrypi_publish_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish1'

    // Start for MATLABSystem: '<Root>/Standard Servo Write'
    rasberrypi_publish_DW.obj.Initialized = false;
    rasberrypi_publish_DW.obj.matlabCodegenIsDeleted = false;
    rasberrypi_publish_DW.obj.MinPulseDuration =
      rasberrypi_publish_P.StandardServoWrite_MinPulseDura;
    rasberrypi_publish_DW.obj.MaxPulseDuration =
      rasberrypi_publish_P.StandardServoWrite_MaxPulseDura;
    rasberrypi_publish_DW.obj.isInitialized = 1;
    rasberrypi_publish_DW.obj.PinNumber = 18U;
    ret = EXT_SERVO_init(rasberrypi_publish_DW.obj.PinNumber);
    if (ret == 0) {
      rasberrypi_publish_DW.obj.Initialized = true;
    } else {
      for (ret = 0; ret < 53; ret++) {
        rasberrypi_publish_B.cv1[ret] = tmp_3[ret];
      }

      printf(rasberrypi_publish_B.cv1, rasberrypi_publish_DW.obj.PinNumber);
    }

    rasberrypi_publish_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Standard Servo Write'

    // InitializeConditions for UnitDelay: '<S7>/Output'
    rasberrypi_publish_DW.Output_DSTATE =
      rasberrypi_publish_P.Output_InitialCondition;

    // SystemInitialize for MATLAB Function: '<S12>/MATLAB Function'
    // <|32|> detector = vision.BlobAnalysis('BoundingBoxOutputPort',false,...
    // <|32|>         'AreaOutputPort',false,'MinimumBlobArea',300, ...
    // <|32|>         'MajorAxisLengthOutputPort',true,'MaximumCount', 10);
    // System object Constructor function: vision.BlobAnalysis
    for (ret = 0; ret < 8; ret++) {
      rasberrypi_publish_DW.detector.cSFunObject.P0_WALKER_RTP[ret] = b[ret];
    }

    rasberrypi_publish_DW.detector.matlabCodegenIsDeleted = false;

    // End of SystemInitialize for MATLAB Function: '<S12>/MATLAB Function'

    // SystemInitialize for Chart: '<S3>/Tracking Controller'
    rasberrypi_publish_DW.is_active_c3_rasberrypi_publish = 0U;
    rasberrypi_publish_DW.is_c3_rasberrypi_publish =
      rasberrypi_p_IN_NO_ACTIVE_CHILD;
    rasberrypi_publish_DW.MAX_ANGLE = 90.0;
  }
}

// Model terminate function
void publish_cameraModelClass::terminate()
{
  // Terminate for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' 
  MW_videoCaptureTerminate(rasberrypi_publish_ConstP.V4L2VideoCapture_p1);

  // Terminate for MATLAB Function: '<S12>/MATLAB Function'
  if (!rasberrypi_publish_DW.detector.matlabCodegenIsDeleted) {
    rasberrypi_publish_DW.detector.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLAB Function: '<S12>/MATLAB Function'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  matlabCodegenHandle_matlabCod_i(&rasberrypi_publish_DW.obj_e);

  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  matlabCodegenHandle_matlabCod_i(&rasberrypi_publish_DW.obj_j);

  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for MATLABSystem: '<Root>/Standard Servo Write'
  matlabCodegenHandle_matlabCodeg(&rasberrypi_publish_DW.obj);
}

// Constructor
publish_cameraModelClass::publish_cameraModelClass() : rasberrypi_publish_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
publish_cameraModelClass::~publish_cameraModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_rasberrypi_publish_T * publish_cameraModelClass::getRTM()
{
  return (&rasberrypi_publish_M);
}

//
// File trailer for generated code.
//
// [EOF]
//

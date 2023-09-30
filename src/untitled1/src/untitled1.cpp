//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled1.cpp
//
// Code generated for Simulink model 'untitled1'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Fri Oct 21 15:20:36 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "untitled1.h"
#include <math.h>
#include "rtwtypes.h"
#include "untitled1_types.h"
#include "untitled1_private.h"
#include "untitled1_dt.h"

// Block states (default storage)
DW_untitled1_T untitled1_DW;

// Real-time model
RT_MODEL_untitled1_T untitled1_M_ = RT_MODEL_untitled1_T();
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;

// Model step function
void untitled1_step(void)
{
  SL_Bus_untitled1_std_msgs_Float32 rtb_BusAssignment;
  real_T lastSin_tmp;

  // Sin: '<Root>/Sine Wave'
  if (untitled1_DW.systemEnable != 0) {
    lastSin_tmp = untitled1_P.SineWave_Freq * untitled1_M->Timing.taskTime0;
    untitled1_DW.lastSin = sin(lastSin_tmp);
    untitled1_DW.lastCos = cos(lastSin_tmp);
    untitled1_DW.systemEnable = 0;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   Sin: '<Root>/Sine Wave'

  rtb_BusAssignment.Data = static_cast<real32_T>(((untitled1_DW.lastSin *
    untitled1_P.SineWave_PCos + untitled1_DW.lastCos * untitled1_P.SineWave_PSin)
    * untitled1_P.SineWave_HCos + (untitled1_DW.lastCos *
    untitled1_P.SineWave_PCos - untitled1_DW.lastSin * untitled1_P.SineWave_PSin)
    * untitled1_P.SineWave_Hsin) * untitled1_P.SineWave_Amp +
    untitled1_P.SineWave_Bias);

  // Outputs for Atomic SubSystem: '<Root>/Steering Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_untitled1_1.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Steering Publish'

  // Update for Sin: '<Root>/Sine Wave'
  lastSin_tmp = untitled1_DW.lastSin;
  untitled1_DW.lastSin = untitled1_DW.lastSin * untitled1_P.SineWave_HCos +
    untitled1_DW.lastCos * untitled1_P.SineWave_Hsin;
  untitled1_DW.lastCos = untitled1_DW.lastCos * untitled1_P.SineWave_HCos -
    lastSin_tmp * untitled1_P.SineWave_Hsin;

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.1s, 0.0s]
    rtExtModeUpload(0, (real_T)untitled1_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.1s, 0.0s]
    if ((rtmGetTFinal(untitled1_M)!=-1) &&
        !((rtmGetTFinal(untitled1_M)-untitled1_M->Timing.taskTime0) >
          untitled1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled1_M)) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  untitled1_M->Timing.taskTime0 =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;
}

// Model initialize function
void untitled1_initialize(void)
{
  // Registration code
  rtmSetTFinal(untitled1_M, 100.0);
  untitled1_M->Timing.stepSize0 = 0.1;

  // External mode info
  untitled1_M->Sizes.checksums[0] = (4257964328U);
  untitled1_M->Sizes.checksums[1] = (2810001377U);
  untitled1_M->Sizes.checksums[2] = (1519115442U);
  untitled1_M->Sizes.checksums[3] = (93899175U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    untitled1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    char_T b_zeroDelimTopic[10];
    static const char_T tmp[9] = { '/', 's', 't', 'e', 'e', 'r', 'i', 'n', 'g' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Steering Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    untitled1_DW.obj.matlabCodegenIsDeleted = false;
    untitled1_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[9] = '\x00';
    Pub_untitled1_1.createPublisher(&b_zeroDelimTopic[0], 1);
    untitled1_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Steering Publish'

    // Enable for Sin: '<Root>/Sine Wave'
    untitled1_DW.systemEnable = 1;
  }
}

// Model terminate function
void untitled1_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Steering Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Steering Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//

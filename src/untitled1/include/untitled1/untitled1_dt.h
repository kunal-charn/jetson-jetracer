//
//  untitled1_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "untitled1".
//
//  Model version              : 1.0
//  Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
//  C++ source code generated on : Fri Oct 21 15:20:36 2022
//
//  Target selection: ert.tlc
//  Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(SL_Bus_untitled1_std_msgs_Float32),
  sizeof(ros_slroscpp_internal_block_P_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "SL_Bus_untitled1_std_msgs_Float32",
  "ros_slroscpp_internal_block_P_T",
  "char_T",
  "uchar_T",
  "time_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&untitled1_DW.obj), 16, 0, 1 },

  { (char_T *)(&untitled1_DW.lastSin), 0, 0, 2 },

  { (char_T *)(&untitled1_DW.systemEnable), 6, 0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  3U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled1_P.Constant_Value), 15, 0, 1 },

  { (char_T *)(&untitled1_P.SineWave_Amp), 0, 0, 7 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

// [EOF] untitled1_dt.h

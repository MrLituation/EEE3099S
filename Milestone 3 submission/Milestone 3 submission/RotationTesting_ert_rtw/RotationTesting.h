/*
 * RotationTesting.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RotationTesting".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Oct 13 15:26:37 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RotationTesting_h_
#define RTW_HEADER_RotationTesting_h_
#ifndef RotationTesting_COMMON_INCLUDES_
#define RotationTesting_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* RotationTesting_COMMON_INCLUDES_ */

#include "RotationTesting_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S1>/Digital Output6' */
  codertarget_arduinobase_block_T obj_n;/* '<S1>/Digital Output4' */
  codertarget_arduinobase_block_T obj_i;/* '<S1>/Digital Output3' */
  codertarget_arduinobase_block_T obj_ib;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_inter_T obj_k;/* '<S1>/PWM1' */
  codertarget_arduinobase_inter_T obj_l;/* '<S1>/PWM' */
  boolean_T objisempty;                /* '<S1>/PWM1' */
  boolean_T objisempty_d;              /* '<S1>/PWM' */
  boolean_T objisempty_j;              /* '<S1>/Digital Output6' */
  boolean_T objisempty_jg;             /* '<S1>/Digital Output4' */
  boolean_T objisempty_b;              /* '<S1>/Digital Output3' */
  boolean_T objisempty_h;              /* '<S1>/Digital Output1' */
} DW_RotationTesting_T;

/* Parameters (default storage) */
struct P_RotationTesting_T_ {
  real_T InputPWM[173];                /* Variable: InputPWM
                                        * Referenced by:
                                        *   '<S1>/Left Motor LUT'
                                        *   '<S1>/Right Motor LUT'
                                        */
  real_T WheelSpeed[173];              /* Variable: WheelSpeed
                                        * Referenced by:
                                        *   '<S1>/Left Motor LUT'
                                        *   '<S1>/Right Motor LUT'
                                        */
  real_T wheelR;                       /* Variable: wheelR
                                        * Referenced by: '<S2>/vtow'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant3_Value_p;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T changeparameters_Gain[4];
                               /* Expression: [1 +axleLength/2; 1 -axleLength/2]
                                * Referenced by: '<S2>/change parameters'
                                */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RotationTesting_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_RotationTesting_T RotationTesting_P;

/* Block states (default storage) */
extern DW_RotationTesting_T RotationTesting_DW;

/* Model entry point functions */
extern void RotationTesting_initialize(void);
extern void RotationTesting_step(void);
extern void RotationTesting_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RotationTesting_T *const RotationTesting_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RotationTesting'
 * '<S1>'   : 'RotationTesting/Subsystem1'
 * '<S2>'   : 'RotationTesting/To wlwr1'
 */
#endif                                 /* RTW_HEADER_RotationTesting_h_ */

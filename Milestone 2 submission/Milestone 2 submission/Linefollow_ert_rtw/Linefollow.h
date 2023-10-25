/*
 * Linefollow.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Linefollow".
 *
 * Model version              : 5.82
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Oct  5 17:41:15 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Linefollow_h_
#define RTW_HEADER_Linefollow_h_
#ifndef Linefollow_COMMON_INCLUDES_
#define Linefollow_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* Linefollow_COMMON_INCLUDES_ */

#include "Linefollow_types.h"
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

/* Block signals (default storage) */
typedef struct {
  MW_AnalogIn_ResultDataType_Type datatype_id;
  real_T Subtract;                     /* '<Root>/Subtract' */
} B_Linefollow_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_a;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_n;/* '<S4>/Digital Output6' */
  codertarget_arduinobase_block_T obj_l;/* '<S4>/Digital Output4' */
  codertarget_arduinobase_block_T obj_m;/* '<S4>/Digital Output3' */
  codertarget_arduinobase_block_T obj_g;/* '<S4>/Digital Output1' */
  codertarget_arduinobase_int_e_T obj_f;/* '<S4>/PWM1' */
  codertarget_arduinobase_int_e_T obj_dh;/* '<S4>/PWM' */
  uint8_T is_active_c3_Linefollow;     /* '<Root>/Chart' */
  uint8_T is_c3_Linefollow;            /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<S4>/PWM1' */
  boolean_T objisempty_l;              /* '<S4>/PWM' */
  boolean_T objisempty_k;              /* '<S4>/Digital Output6' */
  boolean_T objisempty_h;              /* '<S4>/Digital Output4' */
  boolean_T objisempty_b;              /* '<S4>/Digital Output3' */
  boolean_T objisempty_n;              /* '<S4>/Digital Output1' */
  boolean_T objisempty_l1;             /* '<Root>/Analog Input3' */
  boolean_T objisempty_i;              /* '<Root>/Analog Input2' */
  boolean_T objisempty_c;              /* '<Root>/Analog Input1' */
  boolean_T objisempty_f;              /* '<Root>/Analog Input' */
} DW_Linefollow_T;

/* Parameters (default storage) */
struct P_Linefollow_T_ {
  real_T InputPWM[173];                /* Variable: InputPWM
                                        * Referenced by:
                                        *   '<S4>/Left Motor LUT'
                                        *   '<S4>/Right Motor LUT'
                                        */
  real_T WheelSpeed[173];              /* Variable: WheelSpeed
                                        * Referenced by:
                                        *   '<S4>/Left Motor LUT'
                                        *   '<S4>/Right Motor LUT'
                                        */
  real_T wheelR;                       /* Variable: wheelR
                                        * Referenced by: '<S5>/vtow'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T AnalogInput3_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input3'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T changeparameters_Gain[4];
                               /* Expression: [1 +axleLength/2; 1 -axleLength/2]
                                * Referenced by: '<S5>/change parameters'
                                */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  uint16_T Switch1_Threshold_n;       /* Computed Parameter: Switch1_Threshold_n
                                       * Referenced by: '<Root>/Switch1'
                                       */
  uint16_T Switch2_Threshold;          /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<Root>/Switch2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Linefollow_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Linefollow_T Linefollow_P;

/* Block signals (default storage) */
extern B_Linefollow_T Linefollow_B;

/* Block states (default storage) */
extern DW_Linefollow_T Linefollow_DW;

/* Model entry point functions */
extern void Linefollow_initialize(void);
extern void Linefollow_step(void);
extern void Linefollow_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Linefollow_T *const Linefollow_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant10' : Unused code path elimination
 * Block '<Root>/Constant11' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/Constant4' : Unused code path elimination
 * Block '<Root>/Constant9' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<S31>/Derivative Gain' : Unused code path elimination
 * Block '<S32>/Filter' : Unused code path elimination
 * Block '<S32>/SumD' : Unused code path elimination
 * Block '<S40>/Filter Coefficient' : Unused code path elimination
 * Block '<S42>/Proportional Gain' : Unused code path elimination
 * Block '<S46>/Sum' : Unused code path elimination
 * Block '<Root>/Switch' : Unused code path elimination
 * Block '<Root>/Switch3' : Unused code path elimination
 */

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
 * '<Root>' : 'Linefollow'
 * '<S1>'   : 'Linefollow/Chart'
 * '<S2>'   : 'Linefollow/Chart1'
 * '<S3>'   : 'Linefollow/PID Controller1'
 * '<S4>'   : 'Linefollow/Subsystem'
 * '<S5>'   : 'Linefollow/To wlwr'
 * '<S6>'   : 'Linefollow/PID Controller1/Anti-windup'
 * '<S7>'   : 'Linefollow/PID Controller1/D Gain'
 * '<S8>'   : 'Linefollow/PID Controller1/Filter'
 * '<S9>'   : 'Linefollow/PID Controller1/Filter ICs'
 * '<S10>'  : 'Linefollow/PID Controller1/I Gain'
 * '<S11>'  : 'Linefollow/PID Controller1/Ideal P Gain'
 * '<S12>'  : 'Linefollow/PID Controller1/Ideal P Gain Fdbk'
 * '<S13>'  : 'Linefollow/PID Controller1/Integrator'
 * '<S14>'  : 'Linefollow/PID Controller1/Integrator ICs'
 * '<S15>'  : 'Linefollow/PID Controller1/N Copy'
 * '<S16>'  : 'Linefollow/PID Controller1/N Gain'
 * '<S17>'  : 'Linefollow/PID Controller1/P Copy'
 * '<S18>'  : 'Linefollow/PID Controller1/Parallel P Gain'
 * '<S19>'  : 'Linefollow/PID Controller1/Reset Signal'
 * '<S20>'  : 'Linefollow/PID Controller1/Saturation'
 * '<S21>'  : 'Linefollow/PID Controller1/Saturation Fdbk'
 * '<S22>'  : 'Linefollow/PID Controller1/Sum'
 * '<S23>'  : 'Linefollow/PID Controller1/Sum Fdbk'
 * '<S24>'  : 'Linefollow/PID Controller1/Tracking Mode'
 * '<S25>'  : 'Linefollow/PID Controller1/Tracking Mode Sum'
 * '<S26>'  : 'Linefollow/PID Controller1/Tsamp - Integral'
 * '<S27>'  : 'Linefollow/PID Controller1/Tsamp - Ngain'
 * '<S28>'  : 'Linefollow/PID Controller1/postSat Signal'
 * '<S29>'  : 'Linefollow/PID Controller1/preSat Signal'
 * '<S30>'  : 'Linefollow/PID Controller1/Anti-windup/Disabled'
 * '<S31>'  : 'Linefollow/PID Controller1/D Gain/Internal Parameters'
 * '<S32>'  : 'Linefollow/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'Linefollow/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'Linefollow/PID Controller1/I Gain/Disabled'
 * '<S35>'  : 'Linefollow/PID Controller1/Ideal P Gain/Passthrough'
 * '<S36>'  : 'Linefollow/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'Linefollow/PID Controller1/Integrator/Disabled'
 * '<S38>'  : 'Linefollow/PID Controller1/Integrator ICs/Disabled'
 * '<S39>'  : 'Linefollow/PID Controller1/N Copy/Disabled'
 * '<S40>'  : 'Linefollow/PID Controller1/N Gain/Internal Parameters'
 * '<S41>'  : 'Linefollow/PID Controller1/P Copy/Disabled'
 * '<S42>'  : 'Linefollow/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'Linefollow/PID Controller1/Reset Signal/Disabled'
 * '<S44>'  : 'Linefollow/PID Controller1/Saturation/Passthrough'
 * '<S45>'  : 'Linefollow/PID Controller1/Saturation Fdbk/Disabled'
 * '<S46>'  : 'Linefollow/PID Controller1/Sum/Sum_PD'
 * '<S47>'  : 'Linefollow/PID Controller1/Sum Fdbk/Disabled'
 * '<S48>'  : 'Linefollow/PID Controller1/Tracking Mode/Disabled'
 * '<S49>'  : 'Linefollow/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'Linefollow/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'Linefollow/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'Linefollow/PID Controller1/postSat Signal/Forward_Path'
 * '<S53>'  : 'Linefollow/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_Linefollow_h_ */

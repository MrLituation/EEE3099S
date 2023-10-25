/*
 * meter1.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "meter1".
 *
 * Model version              : 5.25
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Tue Oct 10 23:23:02 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_meter1_h_
#define RTW_HEADER_meter1_h_
#ifndef meter1_COMMON_INCLUDES_
#define meter1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* meter1_COMMON_INCLUDES_ */

#include "meter1_types.h"
#include <string.h>
#include <stddef.h>
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
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_c_T obj_a;/* '<S8>/Digital Output6' */
  codertarget_arduinobase_blo_c_T obj_e;/* '<S8>/Digital Output4' */
  codertarget_arduinobase_blo_c_T obj_eu;/* '<S8>/Digital Output3' */
  codertarget_arduinobase_blo_c_T obj_pd;/* '<S8>/Digital Output1' */
  codertarget_arduinobase_inter_T obj_ez;/* '<S8>/PWM1' */
  codertarget_arduinobase_inter_T obj_i;/* '<S8>/PWM' */
  real_T Integrator_DSTATE;            /* '<S43>/Integrator' */
  real_T Filter_DSTATE;                /* '<S38>/Filter' */
  uint8_T Accumulator1_DSTATE;         /* '<Root>/Accumulator1' */
  uint8_T Accumulator_DSTATE;          /* '<Root>/Accumulator' */
  boolean_T DelayInput1_DSTATE;        /* '<S2>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S3>/Delay Input1' */
  uint8_T is_active_c3_meter1;         /* '<Root>/Chart' */
  uint8_T is_c3_meter1;                /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<S8>/PWM1' */
  boolean_T objisempty_c;              /* '<S8>/PWM' */
  boolean_T objisempty_f;              /* '<S8>/Digital Output6' */
  boolean_T objisempty_ff;             /* '<S8>/Digital Output4' */
  boolean_T objisempty_m;              /* '<S8>/Digital Output3' */
  boolean_T objisempty_b;              /* '<S8>/Digital Output1' */
  boolean_T objisempty_d;              /* '<Root>/Digital Input1' */
  boolean_T objisempty_bx;             /* '<Root>/Digital Input' */
} DW_meter1_T;

/* Parameters (default storage) */
struct P_meter1_T_ {
  real_T InputPWM[173];                /* Variable: InputPWM
                                        * Referenced by:
                                        *   '<S8>/Left Motor LUT'
                                        *   '<S8>/Right Motor LUT'
                                        */
  real_T WheelSpeed[173];              /* Variable: WheelSpeed
                                        * Referenced by:
                                        *   '<S8>/Left Motor LUT'
                                        *   '<S8>/Right Motor LUT'
                                        */
  real_T wheelR;                       /* Variable: wheelR
                                        * Referenced by: '<S9>/vtow'
                                        */
  real_T DiscretePIDController2_D;   /* Mask Parameter: DiscretePIDController2_D
                                      * Referenced by: '<S37>/Derivative Gain'
                                      */
  real_T DiscretePIDController2_I;   /* Mask Parameter: DiscretePIDController2_I
                                      * Referenced by: '<S40>/Integral Gain'
                                      */
  real_T DiscretePIDController2_InitialC;
                              /* Mask Parameter: DiscretePIDController2_InitialC
                               * Referenced by: '<S38>/Filter'
                               */
  real_T DiscretePIDController2_Initia_m;
                              /* Mask Parameter: DiscretePIDController2_Initia_m
                               * Referenced by: '<S43>/Integrator'
                               */
  real_T DiscretePIDController2_LowerSat;
                              /* Mask Parameter: DiscretePIDController2_LowerSat
                               * Referenced by:
                               *   '<S50>/Saturation'
                               *   '<S36>/DeadZone'
                               */
  real_T DiscretePIDController2_N;   /* Mask Parameter: DiscretePIDController2_N
                                      * Referenced by: '<S46>/Filter Coefficient'
                                      */
  real_T DiscretePIDController2_P;   /* Mask Parameter: DiscretePIDController2_P
                                      * Referenced by: '<S48>/Proportional Gain'
                                      */
  real_T DiscretePIDController2_UpperSat;
                              /* Mask Parameter: DiscretePIDController2_UpperSat
                               * Referenced by:
                               *   '<S50>/Saturation'
                               *   '<S36>/DeadZone'
                               */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S2>/Delay Input1'
                                        */
  boolean_T DetectIncrease1_vinit;     /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S3>/Delay Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S34>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T changeparameters_Gain[4];
                                /* Expression: [1 -axleLength/2; 1 axleLength/2]
                                 * Referenced by: '<S9>/change parameters'
                                 */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S8>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S34>/Clamping_zero'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S43>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S38>/Filter'
                                        */
  uint16_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  int8_T Constant_Value_f;             /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S34>/Constant'
                                        */
  int8_T Constant2_Value_o;            /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S34>/Constant2'
                                        */
  int8_T Constant3_Value_m;            /* Computed Parameter: Constant3_Value_m
                                        * Referenced by: '<S34>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S34>/Constant4'
                                        */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint8_T Accumulator1_IC;             /* Computed Parameter: Accumulator1_IC
                                        * Referenced by: '<Root>/Accumulator1'
                                        */
  uint8_T Accumulator_IC;              /* Computed Parameter: Accumulator_IC
                                        * Referenced by: '<Root>/Accumulator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_meter1_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_meter1_T meter1_P;

/* Block states (default storage) */
extern DW_meter1_T meter1_DW;

/* Model entry point functions */
extern void meter1_initialize(void);
extern void meter1_step(void);
extern void meter1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_meter1_T *const meter1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<S5>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S5>/Discrete-Time Integrator1' : Unused code path elimination
 * Block '<S5>/Gain2' : Unused code path elimination
 * Block '<S5>/Gain3' : Unused code path elimination
 * Block '<S5>/Gain5' : Unused code path elimination
 * Block '<S5>/Gain6' : Unused code path elimination
 * Block '<S5>/Rounding Function' : Unused code path elimination
 * Block '<S5>/Rounding Function1' : Unused code path elimination
 * Block '<Root>/Left Motor LUT' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S6>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S60>/Internal' : Unused code path elimination
 * Block '<S61>/Gain' : Unused code path elimination
 * Block '<S6>/Switch' : Unused code path elimination
 * Block '<Root>/Right Motor LUT' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S7>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S64>/Internal' : Unused code path elimination
 * Block '<S65>/Gain' : Unused code path elimination
 * Block '<S7>/Switch' : Unused code path elimination
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
 * '<Root>' : 'meter1'
 * '<S1>'   : 'meter1/Chart'
 * '<S2>'   : 'meter1/Detect Increase'
 * '<S3>'   : 'meter1/Detect Increase1'
 * '<S4>'   : 'meter1/Discrete PID Controller2'
 * '<S5>'   : 'meter1/Encoder1'
 * '<S6>'   : 'meter1/LeftMotor'
 * '<S7>'   : 'meter1/RightMotor'
 * '<S8>'   : 'meter1/Subsystem'
 * '<S9>'   : 'meter1/To wlwr'
 * '<S10>'  : 'meter1/Discrete PID Controller2/Anti-windup'
 * '<S11>'  : 'meter1/Discrete PID Controller2/D Gain'
 * '<S12>'  : 'meter1/Discrete PID Controller2/Filter'
 * '<S13>'  : 'meter1/Discrete PID Controller2/Filter ICs'
 * '<S14>'  : 'meter1/Discrete PID Controller2/I Gain'
 * '<S15>'  : 'meter1/Discrete PID Controller2/Ideal P Gain'
 * '<S16>'  : 'meter1/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S17>'  : 'meter1/Discrete PID Controller2/Integrator'
 * '<S18>'  : 'meter1/Discrete PID Controller2/Integrator ICs'
 * '<S19>'  : 'meter1/Discrete PID Controller2/N Copy'
 * '<S20>'  : 'meter1/Discrete PID Controller2/N Gain'
 * '<S21>'  : 'meter1/Discrete PID Controller2/P Copy'
 * '<S22>'  : 'meter1/Discrete PID Controller2/Parallel P Gain'
 * '<S23>'  : 'meter1/Discrete PID Controller2/Reset Signal'
 * '<S24>'  : 'meter1/Discrete PID Controller2/Saturation'
 * '<S25>'  : 'meter1/Discrete PID Controller2/Saturation Fdbk'
 * '<S26>'  : 'meter1/Discrete PID Controller2/Sum'
 * '<S27>'  : 'meter1/Discrete PID Controller2/Sum Fdbk'
 * '<S28>'  : 'meter1/Discrete PID Controller2/Tracking Mode'
 * '<S29>'  : 'meter1/Discrete PID Controller2/Tracking Mode Sum'
 * '<S30>'  : 'meter1/Discrete PID Controller2/Tsamp - Integral'
 * '<S31>'  : 'meter1/Discrete PID Controller2/Tsamp - Ngain'
 * '<S32>'  : 'meter1/Discrete PID Controller2/postSat Signal'
 * '<S33>'  : 'meter1/Discrete PID Controller2/preSat Signal'
 * '<S34>'  : 'meter1/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S35>'  : 'meter1/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S36>'  : 'meter1/Discrete PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S37>'  : 'meter1/Discrete PID Controller2/D Gain/Internal Parameters'
 * '<S38>'  : 'meter1/Discrete PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'meter1/Discrete PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'meter1/Discrete PID Controller2/I Gain/Internal Parameters'
 * '<S41>'  : 'meter1/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S42>'  : 'meter1/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'meter1/Discrete PID Controller2/Integrator/Discrete'
 * '<S44>'  : 'meter1/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S45>'  : 'meter1/Discrete PID Controller2/N Copy/Disabled'
 * '<S46>'  : 'meter1/Discrete PID Controller2/N Gain/Internal Parameters'
 * '<S47>'  : 'meter1/Discrete PID Controller2/P Copy/Disabled'
 * '<S48>'  : 'meter1/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'meter1/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S50>'  : 'meter1/Discrete PID Controller2/Saturation/Enabled'
 * '<S51>'  : 'meter1/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S52>'  : 'meter1/Discrete PID Controller2/Sum/Sum_PID'
 * '<S53>'  : 'meter1/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S54>'  : 'meter1/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S55>'  : 'meter1/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'meter1/Discrete PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'meter1/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'meter1/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S59>'  : 'meter1/Discrete PID Controller2/preSat Signal/Forward_Path'
 * '<S60>'  : 'meter1/LeftMotor/Motor'
 * '<S61>'  : 'meter1/LeftMotor/Radians to Degrees'
 * '<S62>'  : 'meter1/LeftMotor/Motor/Input Delay'
 * '<S63>'  : 'meter1/LeftMotor/Motor/Output Delay'
 * '<S64>'  : 'meter1/RightMotor/Motor'
 * '<S65>'  : 'meter1/RightMotor/Radians to Degrees'
 * '<S66>'  : 'meter1/RightMotor/Motor/Input Delay'
 * '<S67>'  : 'meter1/RightMotor/Motor/Output Delay'
 */
#endif                                 /* RTW_HEADER_meter1_h_ */

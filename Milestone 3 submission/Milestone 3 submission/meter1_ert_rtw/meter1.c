/*
 * meter1.c
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

#include "meter1.h"
#include "rtwtypes.h"
#include "meter1_types.h"
#include "meter1_private.h"
#include <math.h>
#include <string.h>

/* Named constants for Chart: '<Root>/Chart' */
#define meter1_IN_ApproachVelocity     ((uint8_T)1U)
#define meter1_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define meter1_IN_StartVelocity        ((uint8_T)2U)
#define meter1_IN_Stop                 ((uint8_T)3U)

/* Block states (default storage) */
DW_meter1_T meter1_DW;

/* Real-time model */
static RT_MODEL_meter1_T meter1_M_;
RT_MODEL_meter1_T *const meter1_M = &meter1_M_;
static void rate_scheduler(void);
uint32_T plook_u32d_binckan(real_T u, const real_T bp[], uint32_T maxIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (meter1_M->Timing.TaskCounters.TID[1])++;
  if ((meter1_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    meter1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void meter1_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_LeftPWM;
  real_T rtb_Switch1;
  real_T rtb_error;
  real_T rtb_v;
  real_T tmp;
  uint32_T rtb_Meas;
  int8_T tmp_0;
  int8_T tmp_1;
  uint8_T tmp_2;
  boolean_T rtb_DigitalInput;
  boolean_T rtb_DigitalInput1;
  if (meter1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain3' incorporates:
     *  DiscreteIntegrator: '<Root>/Accumulator'
     *  DiscreteIntegrator: '<Root>/Accumulator1'
     *  Gain: '<Root>/Gain'
     *  Gain: '<Root>/Gain1'
     *  Sum: '<Root>/Add1'
     */
    rtb_Meas = (uint32_T)(uint16_T)((uint32_T)meter1_P.Gain_Gain *
      meter1_DW.Accumulator1_DSTATE + (uint32_T)meter1_P.Gain1_Gain *
      meter1_DW.Accumulator_DSTATE) * meter1_P.Gain3_Gain;

    /* Sum: '<Root>/Subtract' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain3'
     */
    rtb_error = meter1_P.Constant_Value_h - (real_T)rtb_Meas *
      9.3132257461547852E-10;

    /* Chart: '<Root>/Chart' */
    if (meter1_DW.is_active_c3_meter1 == 0U) {
      meter1_DW.is_active_c3_meter1 = 1U;
      meter1_DW.is_c3_meter1 = meter1_IN_StartVelocity;
      rtb_v = 0.1;
    } else {
      switch (meter1_DW.is_c3_meter1) {
       case meter1_IN_ApproachVelocity:
        rtb_v = 0.04;
        if (rtb_error <= 0.0) {
          meter1_DW.is_c3_meter1 = meter1_IN_Stop;
          rtb_v = 0.0;
        }
        break;

       case meter1_IN_StartVelocity:
        rtb_v = 0.1;
        if (rtb_error < 0.15) {
          meter1_DW.is_c3_meter1 = meter1_IN_ApproachVelocity;
          rtb_v = 0.04;
        }
        break;

       default:
        /* case IN_Stop: */
        rtb_v = 0.0;
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

    /* Gain: '<S9>/vtow' */
    rtb_error = 1.0 / meter1_P.wheelR;

    /* Lookup_n-D: '<S8>/Left Motor LUT' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Gain: '<S9>/change parameters'
     *  Gain: '<S9>/vtow'
     *  SignalConversion generated from: '<S9>/change parameters'
     */
    rtb_LeftPWM = meter1_P.InputPWM[plook_u32d_binckan
      ((meter1_P.changeparameters_Gain[0] * rtb_v +
        meter1_P.changeparameters_Gain[2] * meter1_P.Constant2_Value_c) *
       rtb_error, meter1_P.WheelSpeed, 172U)];

    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Constant: '<S8>/Constant3'
     */
    if (rtb_LeftPWM > meter1_P.Switch1_Threshold) {
      rtb_Switch1 = meter1_P.Constant3_Value;
    } else {
      rtb_Switch1 = meter1_P.Constant2_Value;
    }

    /* End of Switch: '<S8>/Switch1' */

    /* MATLABSystem: '<S8>/Digital Output4' */
    tmp = rt_roundd_snf(rtb_Switch1);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_2 = (uint8_T)tmp;
      } else {
        tmp_2 = 0U;
      }
    } else {
      tmp_2 = MAX_uint8_T;
    }

    writeDigitalPin(13, tmp_2);

    /* End of MATLABSystem: '<S8>/Digital Output4' */

    /* MATLABSystem: '<S8>/Digital Output6' incorporates:
     *  Logic: '<S8>/NOT1'
     */
    writeDigitalPin(12, (uint8_T)!(rtb_Switch1 != 0.0));

    /* MATLABSystem: '<S8>/PWM' */
    obj = &meter1_DW.obj_i;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
    if (!(rtb_LeftPWM <= 255.0)) {
      rtb_LeftPWM = 255.0;
    }

    if (!(rtb_LeftPWM >= 0.0)) {
      rtb_LeftPWM = 0.0;
    }

    MW_PWM_SetDutyCycle(meter1_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, rtb_LeftPWM);

    /* End of MATLABSystem: '<S8>/PWM' */

    /* Lookup_n-D: '<S8>/Right Motor LUT' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Gain: '<S9>/change parameters'
     *  Gain: '<S9>/vtow'
     *  SignalConversion generated from: '<S9>/change parameters'
     */
    rtb_v = meter1_P.InputPWM[plook_u32d_binckan
      ((meter1_P.changeparameters_Gain[1] * rtb_v +
        meter1_P.changeparameters_Gain[3] * meter1_P.Constant2_Value_c) *
       rtb_error, meter1_P.WheelSpeed, 172U)];

    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     */
    if (rtb_v > meter1_P.Switch_Threshold) {
      rtb_LeftPWM = meter1_P.Constant1_Value;
    } else {
      rtb_LeftPWM = meter1_P.Constant_Value;
    }

    /* End of Switch: '<S8>/Switch' */

    /* MATLABSystem: '<S8>/Digital Output1' */
    rtb_error = rt_roundd_snf(rtb_LeftPWM);
    if (rtb_error < 256.0) {
      if (rtb_error >= 0.0) {
        tmp_2 = (uint8_T)rtb_error;
      } else {
        tmp_2 = 0U;
      }
    } else {
      tmp_2 = MAX_uint8_T;
    }

    writeDigitalPin(8, tmp_2);

    /* End of MATLABSystem: '<S8>/Digital Output1' */

    /* MATLABSystem: '<S8>/Digital Output3' incorporates:
     *  Logic: '<S8>/NOT'
     */
    writeDigitalPin(11, (uint8_T)!(rtb_LeftPWM != 0.0));

    /* MATLABSystem: '<S8>/PWM1' */
    obj = &meter1_DW.obj_ez;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
    if (!(rtb_v <= 255.0)) {
      rtb_v = 255.0;
    }

    if (!(rtb_v >= 0.0)) {
      rtb_v = 0.0;
    }

    MW_PWM_SetDutyCycle(meter1_DW.obj_ez.PWMDriverObj.MW_PWM_HANDLE, rtb_v);

    /* End of MATLABSystem: '<S8>/PWM1' */
  }

  /* Gain: '<S40>/Integral Gain' */
  rtb_error = meter1_P.DiscretePIDController2_I * 0.0;

  /* Gain: '<S46>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S38>/Filter'
   *  Gain: '<S37>/Derivative Gain'
   *  Sum: '<S38>/SumD'
   */
  rtb_v = (meter1_P.DiscretePIDController2_D * 0.0 - meter1_DW.Filter_DSTATE) *
    meter1_P.DiscretePIDController2_N;

  /* Sum: '<S52>/Sum' incorporates:
   *  DiscreteIntegrator: '<S43>/Integrator'
   *  Gain: '<S48>/Proportional Gain'
   */
  rtb_LeftPWM = (meter1_P.DiscretePIDController2_P * 0.0 +
                 meter1_DW.Integrator_DSTATE) + rtb_v;

  /* DeadZone: '<S36>/DeadZone' incorporates:
   *  Saturate: '<S50>/Saturation'
   */
  if (rtb_LeftPWM > meter1_P.DiscretePIDController2_UpperSat) {
    rtb_Switch1 = rtb_LeftPWM - meter1_P.DiscretePIDController2_UpperSat;
    rtb_LeftPWM = meter1_P.DiscretePIDController2_UpperSat;
  } else {
    if (rtb_LeftPWM >= meter1_P.DiscretePIDController2_LowerSat) {
      rtb_Switch1 = 0.0;
    } else {
      rtb_Switch1 = rtb_LeftPWM - meter1_P.DiscretePIDController2_LowerSat;
    }

    if (rtb_LeftPWM < meter1_P.DiscretePIDController2_LowerSat) {
      rtb_LeftPWM = meter1_P.DiscretePIDController2_LowerSat;
    }
  }

  /* End of DeadZone: '<S36>/DeadZone' */
  if (meter1_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Digital Input1' */
    if (meter1_DW.obj.SampleTime != meter1_P.DigitalInput1_SampleTime) {
      meter1_DW.obj.SampleTime = meter1_P.DigitalInput1_SampleTime;
    }

    rtb_DigitalInput1 = readDigitalPin(3);

    /* MATLABSystem: '<Root>/Digital Input' */
    if (meter1_DW.obj_p.SampleTime != meter1_P.DigitalInput_SampleTime) {
      meter1_DW.obj_p.SampleTime = meter1_P.DigitalInput_SampleTime;
    }

    rtb_DigitalInput = readDigitalPin(2);

    /* Update for DiscreteIntegrator: '<Root>/Accumulator1' incorporates:
     *  MATLABSystem: '<Root>/Digital Input'
     *  RelationalOperator: '<S3>/FixPt Relational Operator'
     *  UnitDelay: '<S3>/Delay Input1'
     */
    meter1_DW.Accumulator1_DSTATE = (uint8_T)((uint32_T)((int32_T)
      rtb_DigitalInput > (int32_T)meter1_DW.DelayInput1_DSTATE_m) +
      meter1_DW.Accumulator1_DSTATE);

    /* Update for DiscreteIntegrator: '<Root>/Accumulator' incorporates:
     *  MATLABSystem: '<Root>/Digital Input1'
     *  RelationalOperator: '<S2>/FixPt Relational Operator'
     *  UnitDelay: '<S2>/Delay Input1'
     */
    meter1_DW.Accumulator_DSTATE = (uint8_T)((uint32_T)((int32_T)
      rtb_DigitalInput1 > (int32_T)meter1_DW.DelayInput1_DSTATE) +
      meter1_DW.Accumulator_DSTATE);
  }

  /* Switch: '<S34>/Switch1' incorporates:
   *  Constant: '<S34>/Clamping_zero'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S34>/Constant2'
   *  RelationalOperator: '<S34>/fix for DT propagation issue'
   */
  if (rtb_Switch1 > meter1_P.Clamping_zero_Value) {
    tmp_0 = meter1_P.Constant_Value_f;
  } else {
    tmp_0 = meter1_P.Constant2_Value_o;
  }

  /* Switch: '<S34>/Switch2' incorporates:
   *  Constant: '<S34>/Clamping_zero'
   *  Constant: '<S34>/Constant3'
   *  Constant: '<S34>/Constant4'
   *  RelationalOperator: '<S34>/fix for DT propagation issue1'
   */
  if (rtb_error > meter1_P.Clamping_zero_Value) {
    tmp_1 = meter1_P.Constant3_Value_m;
  } else {
    tmp_1 = meter1_P.Constant4_Value;
  }

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Clamping_zero'
   *  Constant: '<S34>/Constant1'
   *  Logic: '<S34>/AND3'
   *  RelationalOperator: '<S34>/Equal1'
   *  RelationalOperator: '<S34>/Relational Operator'
   *  Switch: '<S34>/Switch1'
   *  Switch: '<S34>/Switch2'
   */
  if ((meter1_P.Clamping_zero_Value != rtb_Switch1) && (tmp_0 == tmp_1)) {
    rtb_error = meter1_P.Constant1_Value_i;
  }

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Switch: '<S34>/Switch'
   */
  meter1_DW.Integrator_DSTATE += meter1_P.Integrator_gainval * rtb_error;

  /* Update for DiscreteIntegrator: '<S38>/Filter' */
  meter1_DW.Filter_DSTATE += meter1_P.Filter_gainval * rtb_v;
  if (meter1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S2>/Delay Input1' */
    meter1_DW.DelayInput1_DSTATE = rtb_DigitalInput1;

    /* Update for UnitDelay: '<S3>/Delay Input1' */
    meter1_DW.DelayInput1_DSTATE_m = rtb_DigitalInput;
  }

  rate_scheduler();
}

/* Model initialize function */
void meter1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)meter1_M, 0,
                sizeof(RT_MODEL_meter1_T));

  /* states (dwork) */
  (void) memset((void *)&meter1_DW, 0,
                sizeof(DW_meter1_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<S8>/Digital Output4' */
    meter1_DW.obj_e.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty_ff = true;
    meter1_DW.obj_e.isInitialized = 1;
    digitalIOSetup(13, 1);
    meter1_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/Digital Output6' */
    meter1_DW.obj_a.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty_f = true;
    meter1_DW.obj_a.isInitialized = 1;
    digitalIOSetup(12, 1);
    meter1_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/PWM' */
    meter1_DW.obj_i.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty_c = true;
    obj = &meter1_DW.obj_i;
    meter1_DW.obj_i.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9U, 0.0, 0.0);
    meter1_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/Digital Output1' */
    meter1_DW.obj_pd.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty_b = true;
    meter1_DW.obj_pd.isInitialized = 1;
    digitalIOSetup(8, 1);
    meter1_DW.obj_pd.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/Digital Output3' */
    meter1_DW.obj_eu.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty_m = true;
    meter1_DW.obj_eu.isInitialized = 1;
    digitalIOSetup(11, 1);
    meter1_DW.obj_eu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/PWM1' */
    meter1_DW.obj_ez.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty = true;
    obj = &meter1_DW.obj_ez;
    meter1_DW.obj_ez.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10U, 0.0, 0.0);
    meter1_DW.obj_ez.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input1' */
    meter1_DW.obj.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty_d = true;
    meter1_DW.obj.SampleTime = meter1_P.DigitalInput1_SampleTime;
    meter1_DW.obj.isInitialized = 1;
    digitalIOSetup(3, 0);
    meter1_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    meter1_DW.obj_p.matlabCodegenIsDeleted = false;
    meter1_DW.objisempty_bx = true;
    meter1_DW.obj_p.SampleTime = meter1_P.DigitalInput_SampleTime;
    meter1_DW.obj_p.isInitialized = 1;
    digitalIOSetup(2, 0);
    meter1_DW.obj_p.isSetupComplete = true;
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Accumulator1' */
  meter1_DW.Accumulator1_DSTATE = meter1_P.Accumulator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Accumulator' */
  meter1_DW.Accumulator_DSTATE = meter1_P.Accumulator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' */
  meter1_DW.Integrator_DSTATE = meter1_P.DiscretePIDController2_Initia_m;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Filter' */
  meter1_DW.Filter_DSTATE = meter1_P.DiscretePIDController2_InitialC;

  /* InitializeConditions for UnitDelay: '<S2>/Delay Input1' */
  meter1_DW.DelayInput1_DSTATE = meter1_P.DetectIncrease_vinit;

  /* InitializeConditions for UnitDelay: '<S3>/Delay Input1' */
  meter1_DW.DelayInput1_DSTATE_m = meter1_P.DetectIncrease1_vinit;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  meter1_DW.is_active_c3_meter1 = 0U;
  meter1_DW.is_c3_meter1 = meter1_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void meter1_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S8>/Digital Output4' */
  if (!meter1_DW.obj_e.matlabCodegenIsDeleted) {
    meter1_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Output4' */

  /* Terminate for MATLABSystem: '<S8>/Digital Output6' */
  if (!meter1_DW.obj_a.matlabCodegenIsDeleted) {
    meter1_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Output6' */

  /* Terminate for MATLABSystem: '<S8>/PWM' */
  obj = &meter1_DW.obj_i;
  if (!meter1_DW.obj_i.matlabCodegenIsDeleted) {
    meter1_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((meter1_DW.obj_i.isInitialized == 1) && meter1_DW.obj_i.isSetupComplete)
    {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
      MW_PWM_SetDutyCycle(meter1_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
      MW_PWM_Close(meter1_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/PWM' */

  /* Terminate for MATLABSystem: '<S8>/Digital Output1' */
  if (!meter1_DW.obj_pd.matlabCodegenIsDeleted) {
    meter1_DW.obj_pd.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S8>/Digital Output3' */
  if (!meter1_DW.obj_eu.matlabCodegenIsDeleted) {
    meter1_DW.obj_eu.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Output3' */

  /* Terminate for MATLABSystem: '<S8>/PWM1' */
  obj = &meter1_DW.obj_ez;
  if (!meter1_DW.obj_ez.matlabCodegenIsDeleted) {
    meter1_DW.obj_ez.matlabCodegenIsDeleted = true;
    if ((meter1_DW.obj_ez.isInitialized == 1) &&
        meter1_DW.obj_ez.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
      MW_PWM_SetDutyCycle(meter1_DW.obj_ez.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
      MW_PWM_Close(meter1_DW.obj_ez.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!meter1_DW.obj.matlabCodegenIsDeleted) {
    meter1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!meter1_DW.obj_p.matlabCodegenIsDeleted) {
    meter1_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */
}

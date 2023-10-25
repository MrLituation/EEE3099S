/*
 * Linefollow.c
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

#include "Linefollow.h"
#include "rtwtypes.h"
#include "Linefollow_types.h"
#include "Linefollow_private.h"
#include <math.h>
#include <string.h>

/* Named constants for Chart: '<Root>/Chart' */
#define Linefollow_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define Linefollow_IN_SteerLeft        ((uint8_T)1U)
#define Linefollow_IN_SteerRight       ((uint8_T)2U)
#define Linefollow_IN_Straight         ((uint8_T)3U)

/* Block signals (default storage) */
B_Linefollow_T Linefollow_B;

/* Block states (default storage) */
DW_Linefollow_T Linefollow_DW;

/* Real-time model */
static RT_MODEL_Linefollow_T Linefollow_M_;
RT_MODEL_Linefollow_T *const Linefollow_M = &Linefollow_M_;
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
void Linefollow_step(void)
{
  codertarget_arduinobase_int_e_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_LeftPWM;
  real_T rtb_Switch1;
  real_T rtb_v;
  real_T rtb_w;
  real_T tmp;
  uint16_T b_varargout_1;
  uint16_T b_varargout_1_0;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (Linefollow_DW.obj_d.SampleTime != Linefollow_P.AnalogInput1_SampleTime) {
    Linefollow_DW.obj_d.SampleTime = Linefollow_P.AnalogInput1_SampleTime;
  }

  obj = &Linefollow_DW.obj_d;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16U);
  Linefollow_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Linefollow_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     Linefollow_B.datatype_id);

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (Linefollow_DW.obj_h.SampleTime != Linefollow_P.AnalogInput2_SampleTime) {
    Linefollow_DW.obj_h.SampleTime = Linefollow_P.AnalogInput2_SampleTime;
  }

  obj = &Linefollow_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(20U);
  Linefollow_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Linefollow_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1_0,
     Linefollow_B.datatype_id);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  MATLABSystem: '<Root>/Analog Input1'
   */
  if (b_varargout_1 >= Linefollow_P.Switch1_Threshold_n) {
    Linefollow_B.Subtract = Linefollow_P.Constant5_Value;
  } else {
    Linefollow_B.Subtract = Linefollow_P.Constant6_Value;
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<Root>/Constant8'
   *  MATLABSystem: '<Root>/Analog Input2'
   */
  if (b_varargout_1_0 >= Linefollow_P.Switch2_Threshold) {
    tmp = Linefollow_P.Constant7_Value;
  } else {
    tmp = Linefollow_P.Constant8_Value;
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain3'
   *  Sum: '<Root>/Add1'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch2'
   */
  Linefollow_B.Subtract = Linefollow_P.Constant1_Value_k -
    (Linefollow_P.Gain3_Gain * Linefollow_B.Subtract + Linefollow_P.Gain_Gain *
     tmp);

  /* Chart: '<Root>/Chart' */
  if (Linefollow_DW.is_active_c3_Linefollow == 0U) {
    Linefollow_DW.is_active_c3_Linefollow = 1U;
    Linefollow_DW.is_c3_Linefollow = Linefollow_IN_Straight;
    rtb_w = 0.0;
    rtb_v = 0.06;
  } else {
    switch (Linefollow_DW.is_c3_Linefollow) {
     case Linefollow_IN_SteerLeft:
      rtb_w = 3.8;
      rtb_v = 0.045;
      if (Linefollow_B.Subtract > -0.1) {
        Linefollow_DW.is_c3_Linefollow = Linefollow_IN_Straight;
        rtb_w = 0.0;
        rtb_v = 0.06;
      }
      break;

     case Linefollow_IN_SteerRight:
      rtb_w = -1.0;
      rtb_v = 0.045;
      if (Linefollow_B.Subtract < 0.1) {
        Linefollow_DW.is_c3_Linefollow = Linefollow_IN_Straight;
        rtb_w = 0.0;
        rtb_v = 0.06;
      }
      break;

     default:
      /* case IN_Straight: */
      rtb_w = 0.0;
      rtb_v = 0.06;
      if (Linefollow_B.Subtract > 0.1) {
        Linefollow_DW.is_c3_Linefollow = Linefollow_IN_SteerRight;
        rtb_w = -1.0;
        rtb_v = 0.045;
      } else if (Linefollow_B.Subtract < -0.1) {
        Linefollow_DW.is_c3_Linefollow = Linefollow_IN_SteerLeft;
        rtb_w = 3.8;
        rtb_v = 0.045;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Gain: '<S5>/vtow' */
  Linefollow_B.Subtract = 1.0 / Linefollow_P.wheelR;

  /* Lookup_n-D: '<S4>/Left Motor LUT' incorporates:
   *  Gain: '<S5>/change parameters'
   *  Gain: '<S5>/vtow'
   *  SignalConversion generated from: '<S5>/change parameters'
   */
  rtb_LeftPWM = Linefollow_P.InputPWM[plook_u32d_binckan
    ((Linefollow_P.changeparameters_Gain[0] * rtb_v +
      Linefollow_P.changeparameters_Gain[2] * rtb_w) * Linefollow_B.Subtract,
     Linefollow_P.WheelSpeed, 172U)];

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   */
  if (rtb_LeftPWM > Linefollow_P.Switch1_Threshold) {
    rtb_Switch1 = Linefollow_P.Constant3_Value;
  } else {
    rtb_Switch1 = Linefollow_P.Constant2_Value;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* MATLABSystem: '<S4>/Digital Output4' */
  tmp = rt_roundd_snf(rtb_Switch1);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp_0);

  /* End of MATLABSystem: '<S4>/Digital Output4' */

  /* MATLABSystem: '<S4>/Digital Output6' incorporates:
   *  Logic: '<S4>/NOT1'
   */
  writeDigitalPin(12, (uint8_T)!(rtb_Switch1 != 0.0));

  /* MATLABSystem: '<S4>/PWM' */
  obj_0 = &Linefollow_DW.obj_dh;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
  if (!(rtb_LeftPWM <= 255.0)) {
    rtb_LeftPWM = 255.0;
  }

  if (!(rtb_LeftPWM >= 0.0)) {
    rtb_LeftPWM = 0.0;
  }

  MW_PWM_SetDutyCycle(Linefollow_DW.obj_dh.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_LeftPWM);

  /* End of MATLABSystem: '<S4>/PWM' */

  /* Lookup_n-D: '<S4>/Right Motor LUT' incorporates:
   *  Gain: '<S5>/change parameters'
   *  Gain: '<S5>/vtow'
   *  SignalConversion generated from: '<S5>/change parameters'
   */
  rtb_w = Linefollow_P.InputPWM[plook_u32d_binckan
    ((Linefollow_P.changeparameters_Gain[1] * rtb_v +
      Linefollow_P.changeparameters_Gain[3] * rtb_w) * Linefollow_B.Subtract,
     Linefollow_P.WheelSpeed, 172U)];

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  if (rtb_w > Linefollow_P.Switch_Threshold) {
    rtb_v = Linefollow_P.Constant1_Value;
  } else {
    rtb_v = Linefollow_P.Constant_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* MATLABSystem: '<S4>/Digital Output1' */
  Linefollow_B.Subtract = rt_roundd_snf(rtb_v);
  if (Linefollow_B.Subtract < 256.0) {
    if (Linefollow_B.Subtract >= 0.0) {
      tmp_0 = (uint8_T)Linefollow_B.Subtract;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_0);

  /* End of MATLABSystem: '<S4>/Digital Output1' */

  /* MATLABSystem: '<S4>/Digital Output3' incorporates:
   *  Logic: '<S4>/NOT'
   */
  writeDigitalPin(11, (uint8_T)!(rtb_v != 0.0));

  /* MATLABSystem: '<S4>/PWM1' */
  obj_0 = &Linefollow_DW.obj_f;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
  if (!(rtb_w <= 255.0)) {
    rtb_w = 255.0;
  }

  if (!(rtb_w >= 0.0)) {
    rtb_w = 0.0;
  }

  MW_PWM_SetDutyCycle(Linefollow_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, rtb_w);

  /* End of MATLABSystem: '<S4>/PWM1' */

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Linefollow_DW.obj_a.SampleTime != Linefollow_P.AnalogInput_SampleTime) {
    Linefollow_DW.obj_a.SampleTime = Linefollow_P.AnalogInput_SampleTime;
  }

  obj = &Linefollow_DW.obj_a;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15U);
  Linefollow_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Linefollow_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     Linefollow_B.datatype_id);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* MATLABSystem: '<Root>/Analog Input3' */
  if (Linefollow_DW.obj.SampleTime != Linefollow_P.AnalogInput3_SampleTime) {
    Linefollow_DW.obj.SampleTime = Linefollow_P.AnalogInput3_SampleTime;
  }

  obj = &Linefollow_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(21U);
  Linefollow_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Linefollow_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     Linefollow_B.datatype_id);

  /* End of MATLABSystem: '<Root>/Analog Input3' */
}

/* Model initialize function */
void Linefollow_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Linefollow_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Linefollow_DW, 0,
                sizeof(DW_Linefollow_T));

  {
    codertarget_arduinobase_int_e_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    Linefollow_DW.obj_d.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_c = true;
    Linefollow_DW.obj_d.SampleTime = Linefollow_P.AnalogInput1_SampleTime;
    obj = &Linefollow_DW.obj_d;
    Linefollow_DW.obj_d.isInitialized = 1;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    Linefollow_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input2' */
    Linefollow_DW.obj_h.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_i = true;
    Linefollow_DW.obj_h.SampleTime = Linefollow_P.AnalogInput2_SampleTime;
    obj = &Linefollow_DW.obj_h;
    Linefollow_DW.obj_h.isInitialized = 1;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(20U);
    Linefollow_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output4' */
    Linefollow_DW.obj_l.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_h = true;
    Linefollow_DW.obj_l.isInitialized = 1;
    digitalIOSetup(13, 1);
    Linefollow_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output6' */
    Linefollow_DW.obj_n.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_k = true;
    Linefollow_DW.obj_n.isInitialized = 1;
    digitalIOSetup(12, 1);
    Linefollow_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM' */
    Linefollow_DW.obj_dh.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_l = true;
    obj_0 = &Linefollow_DW.obj_dh;
    Linefollow_DW.obj_dh.isInitialized = 1;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9U, 0.0, 0.0);
    Linefollow_DW.obj_dh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output1' */
    Linefollow_DW.obj_g.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_n = true;
    Linefollow_DW.obj_g.isInitialized = 1;
    digitalIOSetup(8, 1);
    Linefollow_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output3' */
    Linefollow_DW.obj_m.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_b = true;
    Linefollow_DW.obj_m.isInitialized = 1;
    digitalIOSetup(11, 1);
    Linefollow_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM1' */
    Linefollow_DW.obj_f.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty = true;
    obj_0 = &Linefollow_DW.obj_f;
    Linefollow_DW.obj_f.isInitialized = 1;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10U, 0.0, 0.0);
    Linefollow_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    Linefollow_DW.obj_a.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_f = true;
    Linefollow_DW.obj_a.SampleTime = Linefollow_P.AnalogInput_SampleTime;
    obj = &Linefollow_DW.obj_a;
    Linefollow_DW.obj_a.isInitialized = 1;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15U);
    Linefollow_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input3' */
    Linefollow_DW.obj.matlabCodegenIsDeleted = false;
    Linefollow_DW.objisempty_l1 = true;
    Linefollow_DW.obj.SampleTime = Linefollow_P.AnalogInput3_SampleTime;
    obj = &Linefollow_DW.obj;
    Linefollow_DW.obj.isInitialized = 1;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(21U);
    Linefollow_DW.obj.isSetupComplete = true;
  }

  /* SystemInitialize for Chart: '<Root>/Chart' */
  Linefollow_DW.is_active_c3_Linefollow = 0U;
  Linefollow_DW.is_c3_Linefollow = Linefollow_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void Linefollow_terminate(void)
{
  codertarget_arduinobase_int_e_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &Linefollow_DW.obj_d;
  if (!Linefollow_DW.obj_d.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Linefollow_DW.obj_d.isInitialized == 1) &&
        Linefollow_DW.obj_d.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16U);
      MW_AnalogIn_Close(Linefollow_DW.obj_d.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  obj = &Linefollow_DW.obj_h;
  if (!Linefollow_DW.obj_h.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Linefollow_DW.obj_h.isInitialized == 1) &&
        Linefollow_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(20U);
      MW_AnalogIn_Close(Linefollow_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output4' */
  if (!Linefollow_DW.obj_l.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output4' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output6' */
  if (!Linefollow_DW.obj_n.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output6' */

  /* Terminate for MATLABSystem: '<S4>/PWM' */
  obj_0 = &Linefollow_DW.obj_dh;
  if (!Linefollow_DW.obj_dh.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_dh.matlabCodegenIsDeleted = true;
    if ((Linefollow_DW.obj_dh.isInitialized == 1) &&
        Linefollow_DW.obj_dh.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
      MW_PWM_SetDutyCycle(Linefollow_DW.obj_dh.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
      MW_PWM_Close(Linefollow_DW.obj_dh.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!Linefollow_DW.obj_g.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output3' */
  if (!Linefollow_DW.obj_m.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output3' */

  /* Terminate for MATLABSystem: '<S4>/PWM1' */
  obj_0 = &Linefollow_DW.obj_f;
  if (!Linefollow_DW.obj_f.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Linefollow_DW.obj_f.isInitialized == 1) &&
        Linefollow_DW.obj_f.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
      MW_PWM_SetDutyCycle(Linefollow_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
      MW_PWM_Close(Linefollow_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &Linefollow_DW.obj_a;
  if (!Linefollow_DW.obj_a.matlabCodegenIsDeleted) {
    Linefollow_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Linefollow_DW.obj_a.isInitialized == 1) &&
        Linefollow_DW.obj_a.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15U);
      MW_AnalogIn_Close(Linefollow_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  obj = &Linefollow_DW.obj;
  if (!Linefollow_DW.obj.matlabCodegenIsDeleted) {
    Linefollow_DW.obj.matlabCodegenIsDeleted = true;
    if ((Linefollow_DW.obj.isInitialized == 1) &&
        Linefollow_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(21U);
      MW_AnalogIn_Close(Linefollow_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */
}

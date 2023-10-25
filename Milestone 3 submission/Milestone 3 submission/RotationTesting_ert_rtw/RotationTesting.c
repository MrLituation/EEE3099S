/*
 * RotationTesting.c
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

#include "RotationTesting.h"
#include "rtwtypes.h"
#include "RotationTesting_types.h"
#include "RotationTesting_private.h"
#include <math.h>
#include <string.h>

/* Block states (default storage) */
DW_RotationTesting_T RotationTesting_DW;

/* Real-time model */
static RT_MODEL_RotationTesting_T RotationTesting_M_;
RT_MODEL_RotationTesting_T *const RotationTesting_M = &RotationTesting_M_;
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
void RotationTesting_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_LeftPWM;
  real_T rtb_Switch1;
  real_T tmp;
  real_T tmp_0;
  uint8_T tmp_1;

  /* Gain: '<S2>/vtow' */
  tmp = 1.0 / RotationTesting_P.wheelR;

  /* Lookup_n-D: '<S1>/Left Motor LUT' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   *  Gain: '<S2>/change parameters'
   *  Gain: '<S2>/vtow'
   */
  rtb_LeftPWM = RotationTesting_P.InputPWM[plook_u32d_binckan
    ((RotationTesting_P.changeparameters_Gain[0] *
      RotationTesting_P.Constant_Value_e +
      RotationTesting_P.changeparameters_Gain[2] *
      RotationTesting_P.Constant3_Value_p) * tmp, RotationTesting_P.WheelSpeed,
     172U)];

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  if (rtb_LeftPWM > RotationTesting_P.Switch1_Threshold) {
    rtb_Switch1 = RotationTesting_P.Constant3_Value;
  } else {
    rtb_Switch1 = RotationTesting_P.Constant2_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* MATLABSystem: '<S1>/Digital Output4' */
  tmp_0 = rt_roundd_snf(rtb_Switch1);
  if (tmp_0 < 256.0) {
    if (tmp_0 >= 0.0) {
      tmp_1 = (uint8_T)tmp_0;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp_1);

  /* End of MATLABSystem: '<S1>/Digital Output4' */

  /* MATLABSystem: '<S1>/Digital Output6' incorporates:
   *  Logic: '<S1>/NOT1'
   */
  writeDigitalPin(12, (uint8_T)!(rtb_Switch1 != 0.0));

  /* MATLABSystem: '<S1>/PWM' */
  obj = &RotationTesting_DW.obj_l;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
  if (!(rtb_LeftPWM <= 255.0)) {
    rtb_LeftPWM = 255.0;
  }

  if (!(rtb_LeftPWM >= 0.0)) {
    rtb_LeftPWM = 0.0;
  }

  MW_PWM_SetDutyCycle(RotationTesting_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_LeftPWM);

  /* End of MATLABSystem: '<S1>/PWM' */

  /* Lookup_n-D: '<S1>/Right Motor LUT' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   *  Gain: '<S2>/change parameters'
   *  Gain: '<S2>/vtow'
   */
  rtb_LeftPWM = RotationTesting_P.InputPWM[plook_u32d_binckan
    ((RotationTesting_P.changeparameters_Gain[1] *
      RotationTesting_P.Constant_Value_e +
      RotationTesting_P.changeparameters_Gain[3] *
      RotationTesting_P.Constant3_Value_p) * tmp, RotationTesting_P.WheelSpeed,
     172U)];

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  if (rtb_LeftPWM > RotationTesting_P.Switch_Threshold) {
    rtb_Switch1 = RotationTesting_P.Constant1_Value;
  } else {
    rtb_Switch1 = RotationTesting_P.Constant_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLABSystem: '<S1>/Digital Output1' */
  tmp = rt_roundd_snf(rtb_Switch1);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_1 = (uint8_T)tmp;
    } else {
      tmp_1 = 0U;
    }
  } else {
    tmp_1 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_1);

  /* End of MATLABSystem: '<S1>/Digital Output1' */

  /* MATLABSystem: '<S1>/Digital Output3' incorporates:
   *  Logic: '<S1>/NOT'
   */
  writeDigitalPin(11, (uint8_T)!(rtb_Switch1 != 0.0));

  /* MATLABSystem: '<S1>/PWM1' */
  obj = &RotationTesting_DW.obj_k;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
  if (!(rtb_LeftPWM <= 255.0)) {
    rtb_LeftPWM = 255.0;
  }

  if (!(rtb_LeftPWM >= 0.0)) {
    rtb_LeftPWM = 0.0;
  }

  MW_PWM_SetDutyCycle(RotationTesting_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_LeftPWM);

  /* End of MATLABSystem: '<S1>/PWM1' */
}

/* Model initialize function */
void RotationTesting_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(RotationTesting_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&RotationTesting_DW, 0,
                sizeof(DW_RotationTesting_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<S1>/Digital Output4' */
    RotationTesting_DW.obj_n.matlabCodegenIsDeleted = false;
    RotationTesting_DW.objisempty_jg = true;
    RotationTesting_DW.obj_n.isInitialized = 1;
    digitalIOSetup(13, 1);
    RotationTesting_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output6' */
    RotationTesting_DW.obj.matlabCodegenIsDeleted = false;
    RotationTesting_DW.objisempty_j = true;
    RotationTesting_DW.obj.isInitialized = 1;
    digitalIOSetup(12, 1);
    RotationTesting_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    RotationTesting_DW.obj_l.matlabCodegenIsDeleted = false;
    RotationTesting_DW.objisempty_d = true;
    obj = &RotationTesting_DW.obj_l;
    RotationTesting_DW.obj_l.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9U, 0.0, 0.0);
    RotationTesting_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    RotationTesting_DW.obj_ib.matlabCodegenIsDeleted = false;
    RotationTesting_DW.objisempty_h = true;
    RotationTesting_DW.obj_ib.isInitialized = 1;
    digitalIOSetup(8, 1);
    RotationTesting_DW.obj_ib.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output3' */
    RotationTesting_DW.obj_i.matlabCodegenIsDeleted = false;
    RotationTesting_DW.objisempty_b = true;
    RotationTesting_DW.obj_i.isInitialized = 1;
    digitalIOSetup(11, 1);
    RotationTesting_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM1' */
    RotationTesting_DW.obj_k.matlabCodegenIsDeleted = false;
    RotationTesting_DW.objisempty = true;
    obj = &RotationTesting_DW.obj_k;
    RotationTesting_DW.obj_k.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10U, 0.0, 0.0);
    RotationTesting_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void RotationTesting_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Digital Output4' */
  if (!RotationTesting_DW.obj_n.matlabCodegenIsDeleted) {
    RotationTesting_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output4' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output6' */
  if (!RotationTesting_DW.obj.matlabCodegenIsDeleted) {
    RotationTesting_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output6' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &RotationTesting_DW.obj_l;
  if (!RotationTesting_DW.obj_l.matlabCodegenIsDeleted) {
    RotationTesting_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((RotationTesting_DW.obj_l.isInitialized == 1) &&
        RotationTesting_DW.obj_l.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
      MW_PWM_SetDutyCycle(RotationTesting_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9U);
      MW_PWM_Close(RotationTesting_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!RotationTesting_DW.obj_ib.matlabCodegenIsDeleted) {
    RotationTesting_DW.obj_ib.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output3' */
  if (!RotationTesting_DW.obj_i.matlabCodegenIsDeleted) {
    RotationTesting_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output3' */

  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &RotationTesting_DW.obj_k;
  if (!RotationTesting_DW.obj_k.matlabCodegenIsDeleted) {
    RotationTesting_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((RotationTesting_DW.obj_k.isInitialized == 1) &&
        RotationTesting_DW.obj_k.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
      MW_PWM_SetDutyCycle(RotationTesting_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10U);
      MW_PWM_Close(RotationTesting_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */
}

#ifndef _MW_PIGS_H_
#define _MW_PIGS_H_

#if defined(_MATLABIO_)
  #include "rpi_rtwtypes.h"
#else
  #include "rtwtypes.h"
#endif
#include <stdio.h>

#if defined(MW_PWMBLOCK)
#include <pigpio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
    
/* Error codes */
#define ERR_PWM_BASE                (2100)
#define ERR_PWM_PIGPIOINIT          (ERR_PWM_BASE+1)
#define ERR_PWM_SETMODE             (ERR_PWM_BASE+2)
#define ERR_PWM_SETFREQUENCY        (ERR_PWM_BASE+3)
#define ERR_PWM_SETRANGE            (ERR_PWM_BASE+4)
#define ERR_PWM_SETDUTYCYLE         (ERR_PWM_BASE+5)
#define ERR_SERVO_INIT              (ERR_PWM_BASE+6)
#define ERR_SERVO_SETPW             (ERR_PWM_BASE+7)

/* Function prototypes */
#if defined(_MATLABIO_) || defined(_RUNONTARGETHARDWARE_BUILD_) || defined(ARM_PROJECT)
 int32_T EXT_PWM_init(uint32_T pin, uint32_T frequency, double initialDutyCycle);
 int32_T EXT_PWM_setDutyCycle(uint32_T pin, double dutyCycle);
 int32_T EXT_PWM_setFrequency(uint32_T pin, uint32_T frequency);
 int32_T EXT_PWM_terminate(uint32_T pin);
 int32_T EXT_SERVO_init(uint32_T pin);
 int32_T EXT_SERVO_write(uint32_T pin, double shaftAngle, double minPulseWidth, double maxPulseWidth);
 int32_T EXT_SERVO_terminate(uint32_T pin);
 int32_T MW_checkAndStartPigpiod(void);
#if defined(MW_PWMBLOCK)
 int32_T EXT_PWMBlock_init(uint32_T pin, uint32_T frequency, double initialDutyCycle);
 int32_T EXT_PWMBlock_setDutyCycle(uint32_T pin, double dutyCycle);
 int32_T EXT_PWMBlock_terminate(uint32_T pin);
 int32_T EXT_PWMBlock_setFrequency(uint32_T pin, uint32_T frequency);
#endif 
#else
 #define EXT_PWM_init(pin, frequency, initialDutyCycle) (0)
 #define EXT_PWM_setDutyCycle(pin, dutyCycle) (0)
 #define EXT_PWM_setFrequency(pin, frequency) (0)
 #define EXT_PWM_terminate(pin) (0)
 #define EXT_SERVO_init(pin) (0)
 #define EXT_SERVO_write(pin, shaftAngle, minPulseWidth, maxPulseWidth) (0)
 #define EXT_SERVO_terminate(pin) (0)
 #define EXT_PWMBlock_init(pin, frequency, initialDutyCycle)  (0)
 #define EXT_PWMBlock_setDutyCycle(pin, dutyCycle)  (0)
 #define EXT_PWMBlock_terminate(pin)  (0)
 #define EXT_PWMBlock_setFrequency(pin, frequency)  (0)
#endif
    
#ifdef __cplusplus
}
#endif
#endif 
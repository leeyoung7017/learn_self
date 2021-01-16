################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
APP/leds/leds.obj: ../APP/leds/leds.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="E:/DSP_CCS/Sonometer/APP/beep" --include_path="E:/DSP_CCS/Sonometer/APP/leds" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_headers/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/leds/leds.d" --obj_directory="APP/leds" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



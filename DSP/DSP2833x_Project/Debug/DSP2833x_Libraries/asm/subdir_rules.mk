################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DSP2833x_Libraries/asm/DSP2833x_ADC_cal.obj: ../DSP2833x_Libraries/asm/DSP2833x_ADC_cal.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="E:/DSP_CCS/Sonometer/APP/beep" --include_path="E:/DSP_CCS/Sonometer/APP/leds" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_headers/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/asm/DSP2833x_ADC_cal.d" --obj_directory="DSP2833x_Libraries/asm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_Libraries/asm/DSP2833x_CodeStartBranch.obj: ../DSP2833x_Libraries/asm/DSP2833x_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="E:/DSP_CCS/Sonometer/APP/beep" --include_path="E:/DSP_CCS/Sonometer/APP/leds" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_headers/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/asm/DSP2833x_CodeStartBranch.d" --obj_directory="DSP2833x_Libraries/asm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_Libraries/asm/DSP2833x_usDelay.obj: ../DSP2833x_Libraries/asm/DSP2833x_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="E:/DSP_CCS/Sonometer/APP/beep" --include_path="E:/DSP_CCS/Sonometer/APP/leds" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_common/include" --include_path="E:/DSP_CCS/DSP2833x_Libraries/DSP2833x_headers/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/asm/DSP2833x_usDelay.d" --obj_directory="DSP2833x_Libraries/asm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



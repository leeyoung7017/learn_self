# learn_self
初学者，自学

```
├─cadence
│      cadence.md
│      
├─c_language
│  │  c_program.md
│  │  
│  └─pointer_array
│          Makefile
│          pointer_array.c
│          
├─DSP
│  │  README.md
│  │  
│  ├─DSP2833x_Libraries
│  │  ├─DSP2833x_common
│  │  │  ├─cmd
│  │  │  │      28335_RAM_lnk.cmd
│  │  │  │      F28335.cmd
│  │  │  │      
│  │  │  ├─gel
│  │  │  │      f28335.gel
│  │  │  │      
│  │  │  ├─include
│  │  │  │      DSP2833x_DefaultIsr.h
│  │  │  │      DSP2833x_Dma_defines.h
│  │  │  │      DSP2833x_EPwm_defines.h
│  │  │  │      DSP2833x_Examples.h
│  │  │  │      DSP2833x_GlobalPrototypes.h
│  │  │  │      DSP2833x_I2c_defines.h
│  │  │  │      DSP2833x_Project.h
│  │  │  │      DSP2833x_SWPrioritizedIsrLevels.h
│  │  │  │      IQmathLib.h
│  │  │  │      LED.h
│  │  │  │      SFO.h
│  │  │  │      SFO_V5.h
│  │  │  │      
│  │  │  ├─lib
│  │  │  │      IQmath.lib
│  │  │  │      IQmath_fpu32.lib
│  │  │  │      rts2800_ml.lib
│  │  │  │      SFO_TI_Build.lib
│  │  │  │      SFO_TI_Build_fpu.lib
│  │  │  │      SFO_TI_Build_V5.lib
│  │  │  │      SFO_TI_Build_V5_fpu.lib
│  │  │  │      
│  │  │  └─source
│  │  │      │  DSP2833x_Adc.c
│  │  │      │  DSP2833x_ADC_cal.asm
│  │  │      │  DSP2833x_CodeStartBranch.asm
│  │  │      │  DSP2833x_CpuTimers.c
│  │  │      │  DSP2833x_CSMPasswords.asm
│  │  │      │  DSP2833x_DBGIER.asm
│  │  │      │  DSP2833x_DefaultIsr.c
│  │  │      │  DSP2833x_DisInt.asm
│  │  │      │  DSP2833x_DMA.c
│  │  │      │  DSP2833x_ECan.c
│  │  │      │  DSP2833x_ECap.c
│  │  │      │  DSP2833x_EPwm.c
│  │  │      │  DSP2833x_EQep.c
│  │  │      │  DSP2833x_Gpio.c
│  │  │      │  DSP2833x_I2C.c
│  │  │      │  DSP2833x_Mcbsp.c
│  │  │      │  DSP2833x_Mcbsp1.c
│  │  │      │  DSP2833x_MemCopy.c
│  │  │      │  DSP2833x_PieCtrl.c
│  │  │      │  DSP2833x_PieVect.c
│  │  │      │  DSP2833x_Sci.c
│  │  │      │  DSP2833x_Sci1.c
│  │  │      │  DSP2833x_Spi.c
│  │  │      │  DSP2833x_SWPrioritizedDefaultIsr.c
│  │  │      │  DSP2833x_SWPrioritizedPieVect.c
│  │  │      │  DSP2833x_SysCtrl.c
│  │  │      │  DSP2833x_usDelay.asm
│  │  │      │  DSP2833x_Xintf.c
│  │  │      │  
│  │  │      └─Debug
│  │  │              DSP2833x_ADC_cal.obj
│  │  │              DSP2833x_CodeStartBranch.obj
│  │  │              DSP2833x_CpuTimers.obj
│  │  │              DSP2833x_DefaultIsr.obj
│  │  │              DSP2833x_I2C.obj
│  │  │              DSP2833x_PieCtrl.obj
│  │  │              DSP2833x_PieVect.obj
│  │  │              DSP2833x_Sci.obj
│  │  │              DSP2833x_SysCtrl.obj
│  │  │              DSP2833x_usDelay.obj
│  │  │              
│  │  └─DSP2833x_headers
│  │      ├─cmd
│  │      │      DSP2833x_Headers_BIOS.cmd
│  │      │      DSP2833x_Headers_nonBIOS.cmd
│  │      │      
│  │      ├─gel
│  │      │      DSP2833x_Peripheral.gel
│  │      │      
│  │      ├─include
│  │      │      DSP2833x_Adc.h
│  │      │      DSP2833x_CpuTimers.h
│  │      │      DSP2833x_DevEmu.h
│  │      │      DSP2833x_Device.h
│  │      │      DSP2833x_Device1.h
│  │      │      DSP2833x_DMA.h
│  │      │      DSP2833x_ECan.h
│  │      │      DSP2833x_ECap.h
│  │      │      DSP2833x_EPwm.h
│  │      │      DSP2833x_EQep.h
│  │      │      DSP2833x_Gpio.h
│  │      │      DSP2833x_I2c.h
│  │      │      DSP2833x_Mcbsp.h
│  │      │      DSP2833x_PieCtrl.h
│  │      │      DSP2833x_PieVect.h
│  │      │      DSP2833x_Sci.h
│  │      │      DSP2833x_Spi.h
│  │      │      DSP2833x_SysCtrl.h
│  │      │      DSP2833x_Xintf.h
│  │      │      DSP2833x_XIntrupt.h
│  │      │      f28335a.h
│  │      │      
│  │      └─source
│  │          │  DSP2833x_GlobalVariableDefs.c
│  │          │  
│  │          └─Debug
│  │                  DSP2833x_GlobalVariableDefs.obj
│  │                  
│  └─DSP2833x_Project
│      │  .ccsproject
│      │  .cproject
│      │  .project
│      │  main.c
│      │  
│      ├─.launches
│      │      Example01_DSP2833x_ClockSystem.launch
│      │      Example02_DSP2833x_LED.launch
│      │      
│      ├─.settings
│      │      org.eclipse.cdt.codan.core.prefs
│      │      org.eclipse.cdt.debug.core.prefs
│      │      org.eclipse.core.resources.prefs
│      │      
│      ├─APP
│      │  ├─beep
│      │  │      beep.c
│      │  │      beep.h
│      │  │      
│      │  └─leds
│      │          leds.c
│      │          leds.h
│      │          
│      ├─Debug
│      │  │  ccsObjs.opt
│      │  │  Example01_DSP2833x_ClockSystem.map
│      │  │  Example01_DSP2833x_ClockSystem_linkInfo.xml
│      │  │  Example02_DSP2833x_LED.map
│      │  │  Example02_DSP2833x_LED_linkInfo.xml
│      │  │  main.d
│      │  │  main.obj
│      │  │  makefile
│      │  │  objects.mk
│      │  │  Sonometer.map
│      │  │  Sonometer.out
│      │  │  Sonometer_linkInfo.xml
│      │  │  sources.mk
│      │  │  subdir_rules.mk
│      │  │  subdir_vars.mk
│      │  │  
│      │  ├─APP
│      │  │  ├─beep
│      │  │  │      beep.d
│      │  │  │      beep.obj
│      │  │  │      subdir_rules.mk
│      │  │  │      subdir_vars.mk
│      │  │  │      
│      │  │  └─leds
│      │  │          leds.d
│      │  │          leds.obj
│      │  │          leds.pp
│      │  │          subdir_rules.mk
│      │  │          subdir_vars.mk
│      │  │          
│      │  └─DSP2833x_Libraries
│      │      │  DSP2833x_DefaultIsr.pp
│      │      │  DSP2833x_GlobalVariableDefs.pp
│      │      │  DSP2833x_Gpio.pp
│      │      │  DSP2833x_PieCtrl.pp
│      │      │  DSP2833x_PieVect.pp
│      │      │  DSP2833x_SysCtrl.pp
│      │      │  subdir_rules.mk
│      │      │  subdir_vars.mk
│      │      │  
│      │      ├─asm
│      │      │      DSP2833x_ADC_cal.obj
│      │      │      DSP2833x_CodeStartBranch.obj
│      │      │      DSP2833x_usDelay.obj
│      │      │      subdir_rules.mk
│      │      │      subdir_vars.mk
│      │      │      
│      │      ├─cmd
│      │      │      subdir_rules.mk
│      │      │      subdir_vars.mk
│      │      │      
│      │      └─sources
│      │              DSP2833x_DefaultIsr.d
│      │              DSP2833x_DefaultIsr.obj
│      │              DSP2833x_GlobalVariableDefs.d
│      │              DSP2833x_GlobalVariableDefs.obj
│      │              DSP2833x_Gpio.d
│      │              DSP2833x_Gpio.obj
│      │              DSP2833x_PieCtrl.d
│      │              DSP2833x_PieCtrl.obj
│      │              DSP2833x_PieVect.d
│      │              DSP2833x_PieVect.obj
│      │              DSP2833x_SysCtrl.d
│      │              DSP2833x_SysCtrl.obj
│      │              subdir_rules.mk
│      │              subdir_vars.mk
│      │              
│      ├─DSP2833x_Libraries
│      │  │  IQmath.lib
│      │  │  
│      │  ├─asm
│      │  │      DSP2833x_ADC_cal.asm
│      │  │      DSP2833x_CodeStartBranch.asm
│      │  │      DSP2833x_usDelay.asm
│      │  │      
│      │  ├─cmd
│      │  │      28335_RAM_lnk.cmd
│      │  │      DSP2833x_Headers_nonBIOS.cmd
│      │  │      
│      │  └─sources
│      │          DSP2833x_DefaultIsr.c
│      │          DSP2833x_GlobalVariableDefs.c
│      │          DSP2833x_Gpio.c
│      │          DSP2833x_PieCtrl.c
│      │          DSP2833x_PieVect.c
│      │          DSP2833x_SysCtrl.c
│      │          
│      └─targetConfigs
│              readme.txt
│              TMS320F28335.ccxml
│              
├─linux
│  ├─driver
│  │      chr_driver.c
│  │      chr_driver.h
│  │      linux_driver.txt
│  │      
│  ├─file_io_linux
│  │  ├─basic_file_io
│  │  │      file_lock.c
│  │  │      file_lock.h
│  │  │      main.c
│  │  │      Makefile
│  │  │      
│  │  ├─multiplex_io
│  │  │      main.c
│  │  │      Makefile
│  │  │      multiplex_io.c
│  │  │      multiplex_io.h
│  │  │      
│  │  └─standard_file_io
│  │          main.c
│  │          Makefile
│  │          
│  ├─id_linux
│  │      Makefile
│  │      test.c
│  │      
│  ├─process_linux
│  │  ├─daemon
│  │  │      daemon.c
│  │  │      Makefile
│  │  │      
│  │  ├─ipc
│  │  │  │  ipc.txt
│  │  │  │  
│  │  │  ├─ipc_message_queue
│  │  │  │      消息队列.txt
│  │  │  │      
│  │  │  ├─ipc_semaphore
│  │  │  │      sem.c
│  │  │  │      sem.h
│  │  │  │      信号量.txt
│  │  │  │      
│  │  │  ├─ipc_shared_memory
│  │  │  │      shm.c
│  │  │  │      shm.h
│  │  │  │      共享内存.txt
│  │  │  │      
│  │  │  ├─pipe
│  │  │  │      ipc.c
│  │  │  │      ipc.h
│  │  │  │      main
│  │  │  │      main.c
│  │  │  │      main2
│  │  │  │      main2.c
│  │  │  │      Makefile
│  │  │  │      
│  │  │  └─signal
│  │  │      │  kill -l.txt
│  │  │      │  signal.txt
│  │  │      │  
│  │  │      ├─sigaction
│  │  │      │      main.c
│  │  │      │      Makefile
│  │  │      │      sigaction.txt
│  │  │      │      
│  │  │      ├─signal
│  │  │      │      main.c
│  │  │      │      Makefile
│  │  │      │      signal_config.c
│  │  │      │      signal_config.h
│  │  │      │      
│  │  │      └─sig_set
│  │  │              信号集合.txt
│  │  │              
│  │  └─process_terminal
│  │          Makefile
│  │          parents_process.txt
│  │          process
│  │          process.c
│  │          subprocess1.txt
│  │          subprocess2.txt
│  │          
│  └─thread_linux
│      │  线程.txt
│      │  
│      └─thread_lock
│              thread_lock.c
│              
├─Markdown
│      Markdown.md
│      
├─opencv
│  │  main.cpp
│  │  
│  ├─include
│  │      add_operation.h
│  │      attribute_operation.h
│  │      basic_operation.h
│  │      blur_operation.h
│  │      mask_operation.h
│  │      morphology_operation.h
│  │      pixel_mixing.h
│  │      pixel_operation.h
│  │      threshold_operation.h
│  │      
│  └─source
│          add_operation.cpp
│          attribute_operation.cpp
│          basic_operation.cpp
│          blur_operation.cpp
│          mask_operation.cpp
│          morphology_operation.cpp
│          pixel_mixing.cpp
│          pixel_operation.cpp
│          threshold_operation.cpp
│          
├─Qt
│  └─Serial debugging assistant
│      └─Qt_test
│          │  .qmake.stash
│          │  CeOZUX.json
│          │  compile_commands.json
│          │  logo.ico
│          │  main.cpp
│          │  mainwindow.cpp
│          │  mainwindow.h
│          │  mainwindow.ui
│          │  Makefile
│          │  Makefile.Debug
│          │  Makefile.Release
│          │  openerror.cpp
│          │  openerror.h
│          │  openerror.ui
│          │  Qt_test.pro
│          │  Qt_test.pro.user
│          │  Qt_test.pro.user.4.9-pre1
│          │  Qt_test_resource.rc
│          │  Qt_tes_resource.rc
│          │  Qt_t_resource.rc
│          │  Resource.qrc
│          │  translator.qrc
│          │  transmiterror.cpp
│          │  transmiterror.h
│          │  transmiterror.ui
│          │  ui_mainwindow.h
│          │  ui_openerror.h
│          │  ui_transmiterror.h
│          │  _resource.rc
│          │  
│          ├─debug
│          │  │  .exe
│          │  │  main.o
│          │  │  mainwindow.o
│          │  │  moc_mainwindow.cpp
│          │  │  moc_mainwindow.o
│          │  │  moc_openerror.cpp
│          │  │  moc_openerror.o
│          │  │  moc_predefs.h
│          │  │  moc_transmiterror.cpp
│          │  │  moc_transmiterror.o
│          │  │  openerror.o
│          │  │  qrc_Resource.cpp
│          │  │  qrc_Resource.o
│          │  │  qrc_translator.cpp
│          │  │  qrc_translator.o
│          │  │  Qt_t.exe
│          │  │  Qt_tes.exe
│          │  │  Qt_test.exe
│          │  │  Qt_test.sln
│          │  │  Qt_test_resource_res.o
│          │  │  Qt_tes_resource_res.o
│          │  │  Qt_t_resource_res.o
│          │  │  transmiterror.o
│          │  │  _resource_res.o
│          │  │  
│          │  └─.vs
│          │      └─Qt_test
│          │          └─v16
│          │                  .suo
│          │                  
│          ├─image
│          │      jie.png
│          │      lee.png
│          │      logo.ico
│          │      
│          ├─release
│          │      Qt_test.exe
│          │      
│          └─resources
│                  tr_en.qm
│                  tr_en.ts
│                  tr_zh.qm
│                  tr_zh.ts
│                  
└─word
        main.c
        Makefile
        新建文本文档.txt
        

```


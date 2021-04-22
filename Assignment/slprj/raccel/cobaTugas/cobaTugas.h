#include "__cf_cobaTugas.h"
#ifndef RTW_HEADER_cobaTugas_h_
#define RTW_HEADER_cobaTugas_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef cobaTugas_COMMON_INCLUDES_
#define cobaTugas_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "cobaTugas_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#define MODEL_NAME cobaTugas
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (16) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ksckpwiwcc ; real_T g5s2u0vnx2 ; real_T dhzxxjltgy ;
real_T m5503veomq ; real_T f0pi33nrpn ; real_T isafnvelss ; real_T a0iuvgeplx
; real_T hrjrbmtend ; real_T gxpbkkupno ; real_T gcrq2n31qy ; real_T
ezofrtalkk ; real_T pdooljorbl ; real_T blfryopf01 ; real_T iwmpgmd51x ;
real_T keion1nmel ; real_T bdo3hq3xqv ; } B ; typedef struct { real_T
bd42onnf0h ; real_T hr1vryqawg ; real_T mqt3wtplec ; real_T hfkewro55o ;
struct { void * LoggedData ; } pqf5godct0 ; struct { void * TimePtr ; void *
DataPtr ; void * RSimInfoPtr ; } nbmgx4rair ; struct { void * LoggedData ; }
ioyfuucobu ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} c54nvatvhi ; struct { void * LoggedData ; } c1oqc40qjx ; struct { void *
LoggedData ; } lulutqk4so ; struct { int_T PrevIndex ; } luhgv4sj0i ; struct
{ int_T PrevIndex ; } c40klxla4t ; } DW ; typedef struct { real_T blxh12egos
; real_T lqjkl0ew00 ; real_T bre00npilv ; } X ; typedef struct { real_T
blxh12egos ; real_T lqjkl0ew00 ; real_T bre00npilv ; } XDot ; typedef struct
{ boolean_T blxh12egos ; boolean_T lqjkl0ew00 ; boolean_T bre00npilv ; } XDis
; typedef struct { real_T blxh12egos ; real_T lqjkl0ew00 ; real_T bre00npilv
; } CStateAbsTol ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T Ka ; real_T Kb ; real_T Kd ; real_T Ki ;
real_T Kp ; real_T Ks ; real_T current_A ; real_T current_C ; real_T
SetPoint_Time0 [ 3001 ] ; real_T SetPoint_Data0 [ 3001 ] ; real_T velocity_A
; real_T velocity_C ; real_T Integrator_IC ; real_T SetPoint1_Time0 [ 3001 ]
; real_T SetPoint1_Data0 [ 3001 ] ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
cobaTugas_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif

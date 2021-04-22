#include "__cf_cobaTugas.h"
#include "rt_logging_mmi.h"
#include "cobaTugas_capi.h"
#include <math.h>
#include "cobaTugas.h"
#include "cobaTugas_private.h"
#include "cobaTugas_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 2 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "8.14 (R2018a) 06-Feb-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\cobaTugas\\cobaTugas_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . blxh12egos = 0.0 ; rtX .
lqjkl0ew00 = 0.0 ; rtX . bre00npilv = rtP . Integrator_IC ; rtDW . bd42onnf0h
= ( rtInf ) ; rtDW . mqt3wtplec = ( rtInf ) ; } void MdlStart ( void ) { {
void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL )
; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize =
16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { static int_T rt_ToWksWidths [ ] = {
1 } ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 1 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"cobaTugas/Subsystem/Output T(t)" ; rtDW . pqf5godct0 . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "T" , 1 , 0 , 1
, 0.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . pqf5godct0 .
LoggedData == ( NULL ) ) return ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "[t,r]" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . SetPoint_Data0 ; fromwksInfo -> nDataPoints = 3001 ; fromwksInfo ->
time = ( double * ) rtP . SetPoint_Time0 ; rtDW . nbmgx4rair . TimePtr =
fromwksInfo -> time ; rtDW . nbmgx4rair . DataPtr = fromwksInfo -> data ;
rtDW . nbmgx4rair . RSimInfoPtr = fromwksInfo ; } rtDW . luhgv4sj0i .
PrevIndex = 0 ; } { static int_T rt_ToWksWidths [ ] = { 1 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 1
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "cobaTugas/Subsystem/Output u(t)" ; rtDW
. ioyfuucobu . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "u" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if
( rtDW . ioyfuucobu . LoggedData == ( NULL ) ) return ; } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "[t,d]" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . SetPoint1_Data0 ; fromwksInfo -> nDataPoints = 3001 ; fromwksInfo
-> time = ( double * ) rtP . SetPoint1_Time0 ; rtDW . c54nvatvhi . TimePtr =
fromwksInfo -> time ; rtDW . c54nvatvhi . DataPtr = fromwksInfo -> data ;
rtDW . c54nvatvhi . RSimInfoPtr = fromwksInfo ; } rtDW . c40klxla4t .
PrevIndex = 0 ; } { static int_T rt_ToWksWidths [ ] = { 1 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 1
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "cobaTugas/Subsystem/output d" ; rtDW .
c1oqc40qjx . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "d1" , 1 , 0 , 1 , 0.001 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ;
if ( rtDW . c1oqc40qjx . LoggedData == ( NULL ) ) return ; } { static int_T
rt_ToWksWidths [ ] = { 1 } ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ;
static int_T rt_ToWksDimensions [ ] = { 1 } ; static boolean_T
rt_ToWksIsVarDims [ ] = { 0 } ; static void * rt_ToWksCurrSigDims [ ] = { (
NULL ) } ; static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static
BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_ToWksComplexSignals [ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0
} ; static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = {
( NULL ) } ; static const char_T * rt_ToWksLabels [ ] = { "" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "cobaTugas/Subsystem/utput r(t)" ; rtDW
. lulutqk4so . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "r1" , 1 , 0 , 1 , 0.001 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ;
if ( rtDW . lulutqk4so . LoggedData == ( NULL ) ) return ; } MdlInitialize (
) ; } void MdlOutputs ( int_T tid ) { real_T * lastU ; real_T lastTime ; rtB
. ksckpwiwcc = 0.0 ; rtB . ksckpwiwcc += rtP . current_C * rtX . blxh12egos ;
rtB . g5s2u0vnx2 = rtP . Ka * rtB . ksckpwiwcc ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . pqf5godct0 .
LoggedData , & locTime , & rtB . g5s2u0vnx2 ) ; } } } } if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { { real_T * pDataValues = ( real_T * ) rtDW . nbmgx4rair .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . nbmgx4rair . TimePtr ;
int_T currTimeIndex = rtDW . luhgv4sj0i . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 1 ) ; if ( t >= pTimeValues [ 3000 ] ) { rtB .
dhzxxjltgy = pDataValues [ 3000 ] ; } else { int numPoints , lastPoint ;
FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . nbmgx4rair . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . luhgv4sj0i . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . dhzxxjltgy =
pDataValues [ currTimeIndex ] ; } else { rtB . dhzxxjltgy = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; rtB . dhzxxjltgy = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } } } rtB . m5503veomq = 0.0 ; rtB .
m5503veomq += rtP . velocity_C * rtX . lqjkl0ew00 ; rtB . f0pi33nrpn = rtP .
Ks * rtB . m5503veomq ; rtB . isafnvelss = rtB . dhzxxjltgy - rtB .
f0pi33nrpn ; rtB . a0iuvgeplx = rtP . Kp * rtB . isafnvelss ; rtB .
hrjrbmtend = rtX . bre00npilv ; rtB . gxpbkkupno = rtP . Ki * rtB .
hrjrbmtend ; if ( ( rtDW . bd42onnf0h >= ssGetT ( rtS ) ) && ( rtDW .
mqt3wtplec >= ssGetT ( rtS ) ) ) { rtB . gcrq2n31qy = 0.0 ; } else { lastTime
= rtDW . bd42onnf0h ; lastU = & rtDW . hr1vryqawg ; if ( rtDW . bd42onnf0h <
rtDW . mqt3wtplec ) { if ( rtDW . mqt3wtplec < ssGetT ( rtS ) ) { lastTime =
rtDW . mqt3wtplec ; lastU = & rtDW . hfkewro55o ; } } else { if ( rtDW .
bd42onnf0h >= ssGetT ( rtS ) ) { lastTime = rtDW . mqt3wtplec ; lastU = &
rtDW . hfkewro55o ; } } rtB . gcrq2n31qy = ( rtB . isafnvelss - * lastU ) / (
ssGetT ( rtS ) - lastTime ) ; } rtB . ezofrtalkk = rtP . Kd * rtB .
gcrq2n31qy ; rtB . pdooljorbl = ( rtB . a0iuvgeplx + rtB . gxpbkkupno ) + rtB
. ezofrtalkk ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS )
-> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . ioyfuucobu . LoggedData , & locTime , & rtB .
pdooljorbl ) ; } } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { real_T *
pDataValues = ( real_T * ) rtDW . c54nvatvhi . DataPtr ; real_T * pTimeValues
= ( real_T * ) rtDW . c54nvatvhi . TimePtr ; int_T currTimeIndex = rtDW .
c40klxla4t . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 1 ) ; if ( t >=
pTimeValues [ 3000 ] ) { rtB . blfryopf01 = pDataValues [ 3000 ] ; } else {
int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
c54nvatvhi . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . c40klxla4t .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { rtB . blfryopf01 = pDataValues [ currTimeIndex ] ; } else { rtB .
blfryopf01 = pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2
- t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; rtB . blfryopf01 = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } { double locTime =
ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . c1oqc40qjx .
LoggedData , & locTime , & rtB . blfryopf01 ) ; } } } } { double locTime =
ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . lulutqk4so .
LoggedData , & locTime , & rtB . dhzxxjltgy ) ; } } } } } rtB . iwmpgmd51x =
rtP . Kb * rtB . m5503veomq ; rtB . keion1nmel = rtB . pdooljorbl - rtB .
iwmpgmd51x ; rtB . bdo3hq3xqv = rtB . g5s2u0vnx2 - rtB . blfryopf01 ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T * lastU ;
if ( rtDW . bd42onnf0h == ( rtInf ) ) { rtDW . bd42onnf0h = ssGetT ( rtS ) ;
lastU = & rtDW . hr1vryqawg ; } else if ( rtDW . mqt3wtplec == ( rtInf ) ) {
rtDW . mqt3wtplec = ssGetT ( rtS ) ; lastU = & rtDW . hfkewro55o ; } else if
( rtDW . bd42onnf0h < rtDW . mqt3wtplec ) { rtDW . bd42onnf0h = ssGetT ( rtS
) ; lastU = & rtDW . hr1vryqawg ; } else { rtDW . mqt3wtplec = ssGetT ( rtS )
; lastU = & rtDW . hfkewro55o ; } * lastU = rtB . isafnvelss ;
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> blxh12egos = 0.0 ;
_rtXdot -> blxh12egos += rtP . current_A * rtX . blxh12egos ; _rtXdot ->
blxh12egos += rtB . keion1nmel ; _rtXdot -> lqjkl0ew00 = 0.0 ; _rtXdot ->
lqjkl0ew00 += rtP . velocity_A * rtX . lqjkl0ew00 ; _rtXdot -> lqjkl0ew00 +=
rtB . bdo3hq3xqv ; _rtXdot -> bre00npilv = rtB . isafnvelss ; } void
MdlProjection ( void ) { } void MdlTerminate ( void ) { rt_FREE ( rtDW .
nbmgx4rair . RSimInfoPtr ) ; rt_FREE ( rtDW . c54nvatvhi . RSimInfoPtr ) ; if
( rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 3 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 20 ) ; ssSetNumBlockIO ( rtS , 16 ) ;
ssSetNumBlockParams ( rtS , 12015 ) ; } void MdlInitializeSampleTimes ( void
) { ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.001 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2241106536U ) ;
ssSetChecksumVal ( rtS , 1 , 609191789U ) ; ssSetChecksumVal ( rtS , 2 ,
584652481U ) ; ssSetChecksumVal ( rtS , 3 , 3791705630U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = (
real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * )
x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; }
cobaTugas_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "cobaTugas" ) ; ssSetPath
( rtS , "cobaTugas" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 3.0 )
; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 3 ] ; static
real_T absTol [ 3 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 3 ] = { 0U , 0U , 0U } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 2 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
blfryopf01 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
dhzxxjltgy ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS , 0.001 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.001 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
2 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2241106536U ) ; ssSetChecksumVal ( rtS , 1 ,
609191789U ) ; ssSetChecksumVal ( rtS , 2 , 584652481U ) ; ssSetChecksumVal (
rtS , 3 , 3791705630U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }

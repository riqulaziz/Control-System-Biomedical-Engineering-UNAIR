#include "__cf_cobaTugas.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "cobaTugas_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "cobaTugas.h"
#include "cobaTugas_capi.h"
#include "cobaTugas_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/Derivative" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/Set Point" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/Set Point1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 3 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/Gain Integral" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/Gain Proportional" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 5 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/Gain derivative" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/Gain tachometer" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 7 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/Motor torque constant" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/emf constant"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 10 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/Add" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
12 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/Sum1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"cobaTugas/Subsystem/current" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 15 , 0 , TARGET_STRING ( "cobaTugas/Subsystem/velocity " ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 16 , TARGET_STRING (
"cobaTugas/Subsystem/Set Point" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } ,
{ 17 , TARGET_STRING ( "cobaTugas/Subsystem/Set Point" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 18 , TARGET_STRING (
"cobaTugas/Subsystem/Set Point1" ) , TARGET_STRING ( "Time0" ) , 0 , 1 , 0 }
, { 19 , TARGET_STRING ( "cobaTugas/Subsystem/Set Point1" ) , TARGET_STRING (
"Data0" ) , 0 , 1 , 0 } , { 20 , TARGET_STRING (
"cobaTugas/Subsystem/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 21 , TARGET_STRING ( "cobaTugas/Subsystem/current" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING (
"cobaTugas/Subsystem/current" ) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 23
, TARGET_STRING ( "cobaTugas/Subsystem/velocity " ) , TARGET_STRING ( "A" ) ,
0 , 0 , 0 } , { 24 , TARGET_STRING ( "cobaTugas/Subsystem/velocity " ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 }
} ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 25 ,
TARGET_STRING ( "Ka" ) , 0 , 0 , 0 } , { 26 , TARGET_STRING ( "Kb" ) , 0 , 0
, 0 } , { 27 , TARGET_STRING ( "Kd" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING (
"Ki" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING ( "Kp" ) , 0 , 0 , 0 } , { 30 ,
TARGET_STRING ( "Ks" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . gcrq2n31qy , & rtB . dhzxxjltgy ,
& rtB . blfryopf01 , & rtB . gxpbkkupno , & rtB . a0iuvgeplx , & rtB .
ezofrtalkk , & rtB . f0pi33nrpn , & rtB . g5s2u0vnx2 , & rtB . iwmpgmd51x , &
rtB . hrjrbmtend , & rtB . pdooljorbl , & rtB . keion1nmel , & rtB .
isafnvelss , & rtB . bdo3hq3xqv , & rtB . ksckpwiwcc , & rtB . m5503veomq , &
rtP . SetPoint_Time0 [ 0 ] , & rtP . SetPoint_Data0 [ 0 ] , & rtP .
SetPoint1_Time0 [ 0 ] , & rtP . SetPoint1_Data0 [ 0 ] , & rtP . Integrator_IC
, & rtP . current_A , & rtP . current_C , & rtP . velocity_A , & rtP .
velocity_C , & rtP . Ka , & rtP . Kb , & rtP . Kd , & rtP . Ki , & rtP . Kp ,
& rtP . Ks , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 3001 , 1 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.0 , 0.001 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 16 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 9 ,
rtModelParameters , 6 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2241106536U , 609191789U , 584652481U , 3791705630U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo * cobaTugas_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void cobaTugas_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void cobaTugas_host_InitializeDataMapInfo ( cobaTugas_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif

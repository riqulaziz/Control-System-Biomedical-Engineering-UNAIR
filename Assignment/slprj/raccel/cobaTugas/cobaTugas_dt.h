#include "__cf_cobaTugas.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . ksckpwiwcc
) , 0 , 0 , 16 } , { ( char_T * ) ( & rtDW . bd42onnf0h ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtDW . pqf5godct0 . LoggedData ) , 11 , 0 , 6 } , { ( char_T *
) ( & rtDW . luhgv4sj0i . PrevIndex ) , 10 , 0 , 2 } } ; static
DataTypeTransitionTable rtBTransTable = { 4U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Ka ) , 0 ,
0 , 12015 } } ; static DataTypeTransitionTable rtPTransTable = { 1U ,
rtPTransitions } ;

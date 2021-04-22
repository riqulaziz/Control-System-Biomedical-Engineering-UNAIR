#include "__cf_cobaTugas.h"
#ifndef RTW_HEADER_cobaTugas_cap_host_h_
#define RTW_HEADER_cobaTugas_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
cobaTugas_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void cobaTugas_host_InitializeDataMapInfo ( cobaTugas_host_DataMapInfo_T *
dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif

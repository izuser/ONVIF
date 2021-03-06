#include "soapStub.h"
#include "onvif.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define __DEBUG
#ifdef __DEBUG
#define DBG(fmt,args...) fprintf(stdout,  fmt,  ##args)
#else
#define DBG(fmt,args...)
#endif
#define ERR(fmt,args...) fprintf(stderr,  fmt,  ##args)

int _false = 0;
int _true = 1;

NET_IPV4 ip={192,168,1,233};

int onvif_fault(struct soap *soap,char *value1,char *value2)
{
	soap->fault = (struct SOAP_ENV__Fault*)soap_malloc(soap,(sizeof(struct SOAP_ENV__Fault)));
	soap->fault->SOAP_ENV__Code = (struct SOAP_ENV__Code*)soap_malloc(soap,(sizeof(struct SOAP_ENV__Code)));
	soap->fault->SOAP_ENV__Code->SOAP_ENV__Value = "SOAP-ENV:Sender";
	soap->fault->SOAP_ENV__Code->SOAP_ENV__Subcode = (struct SOAP_ENV__Code*)soap_malloc(soap,(sizeof(struct SOAP_ENV__Code)));;
	soap->fault->SOAP_ENV__Code->SOAP_ENV__Subcode->SOAP_ENV__Value = value1;
	soap->fault->SOAP_ENV__Code->SOAP_ENV__Subcode->SOAP_ENV__Subcode = (struct SOAP_ENV__Code*)soap_malloc(soap,(sizeof(struct SOAP_ENV__Code)));
	soap->fault->SOAP_ENV__Code->SOAP_ENV__Subcode->SOAP_ENV__Subcode->SOAP_ENV__Value = value2;
	soap->fault->SOAP_ENV__Code->SOAP_ENV__Subcode->SOAP_ENV__Subcode->SOAP_ENV__Subcode = NULL;
	soap->fault->faultcode = NULL;
	soap->fault->faultstring = NULL;
	soap->fault->faultactor = NULL;
	soap->fault->detail = NULL;
	soap->fault->SOAP_ENV__Reason = NULL;
	soap->fault->SOAP_ENV__Node = NULL;
	soap->fault->SOAP_ENV__Role = NULL;
	soap->fault->SOAP_ENV__Detail = NULL;
}

/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


int  __wsdd__Hello(struct soap* soap, struct wsdd__HelloType *wsdd__Hello)
{
}

int  __wsdd__Bye(struct soap* soap, struct wsdd__ByeType *wsdd__Bye)
{

}
SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__Hello(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__HelloType *wsdd__Hello)
{	struct __wsdd__Hello soap_tmp___wsdd__Hello;
	if (!soap_action)
		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/Hello";
	soap->encodingStyle = NULL;
	soap_tmp___wsdd__Hello.wsdd__Hello = wsdd__Hello;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___wsdd__Hello(soap, &soap_tmp___wsdd__Hello);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___wsdd__Hello(soap, &soap_tmp___wsdd__Hello, "-wsdd:Hello", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___wsdd__Hello(soap, &soap_tmp___wsdd__Hello, "-wsdd:Hello", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__ProbeMatches(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ProbeMatchesType *wsdd__ProbeMatches)
{	struct __wsdd__ProbeMatches soap_tmp___wsdd__ProbeMatches;
	if (!soap_action)
		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/ProbeMatches";
	soap->encodingStyle = NULL;
	soap_tmp___wsdd__ProbeMatches.wsdd__ProbeMatches = wsdd__ProbeMatches;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches, "-wsdd:ProbeMatches", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches, "-wsdd:ProbeMatches", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}
int  __wsdd__Probe(struct soap* soap, struct wsdd__ProbeType *wsdd__Probe)
{
	DBG("__wsdd__Probe\n");
	DBG("Types=%s\n",wsdd__Probe->Types);


	char macaddr[MACH_ADDR_LENGTH];
	char _IPAddr[INFO_LENGTH];
	char _HwId[LARGE_INFO_LENGTH];
	SysInfo *oSysInfo = (SysInfo*)malloc(sizeof(SysInfo));
	memcpy(oSysInfo,&gSysInfo,sizeof(SysInfo));
	int i = 0;
	int flag = 0;
	char list[20][100];
	int len = 0;
	int index = 0;
	
	wsdd__ProbeMatchesType ProbeMatches;
	ProbeMatches.ProbeMatch = (struct wsdd__ProbeMatchType *)soap_malloc(soap, sizeof(struct wsdd__ProbeMatchType));
	ProbeMatches.ProbeMatch->XAddrs = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	ProbeMatches.ProbeMatch->Types = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	ProbeMatches.ProbeMatch->Scopes = (struct wsdd__ScopesType*)soap_malloc(soap,sizeof(struct wsdd__ScopesType));
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ReferenceProperties = (struct wsa__ReferencePropertiesType*)soap_malloc(soap,sizeof(struct wsa__ReferencePropertiesType));
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ReferenceParameters = (struct wsa__ReferenceParametersType*)soap_malloc(soap,sizeof(struct wsa__ReferenceParametersType));
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ServiceName = (struct wsa__ServiceNameType*)soap_malloc(soap,sizeof(struct wsa__ServiceNameType));
	ProbeMatches.ProbeMatch->wsa__EndpointReference.PortType = (char **)soap_malloc(soap, sizeof(char *) * SMALL_INFO_LENGTH);
	ProbeMatches.ProbeMatch->wsa__EndpointReference.__any = (char **)soap_malloc(soap, sizeof(char*) * SMALL_INFO_LENGTH);
	ProbeMatches.ProbeMatch->wsa__EndpointReference.__anyAttribute = (char *)soap_malloc(soap, sizeof(char) * SMALL_INFO_LENGTH);
	ProbeMatches.ProbeMatch->wsa__EndpointReference.Address = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);

	macaddr[0]=0x01;macaddr[1]=0x01;macaddr[2]=0x01;macaddr[3]=0x01;macaddr[4]=0x01;macaddr[5]=0x01;
	sprintf(_HwId,"urn:uuid:2419d68a-2dd2-21b2-a205-%02X%02X%02X%02X%02X%02X",macaddr[0], macaddr[1], macaddr[2], macaddr[3], macaddr[4], macaddr[5]);

	sprintf(_IPAddr, "http://%03d.%03d.%1d.%03d/onvif/device_service", 192, 168, 1, 233);
	ProbeMatches.__sizeProbeMatch = 1;
	ProbeMatches.ProbeMatch->Scopes->__item =(char *)soap_malloc(soap, LARGE_INFO_LENGTH);
	memset(ProbeMatches.ProbeMatch->Scopes->__item,0,sizeof(ProbeMatches.ProbeMatch->Scopes->__item));	

	//Scopes MUST BE
	strcat(ProbeMatches.ProbeMatch->Scopes->__item, "onvif://www.onvif.org/type/NetworkVideoTransmitter");

	ProbeMatches.ProbeMatch->Scopes->MatchBy = NULL;
	strcpy(ProbeMatches.ProbeMatch->XAddrs, _IPAddr);
	strcpy(ProbeMatches.ProbeMatch->Types, wsdd__Probe->Types);
	DBG("wsdd__Probe->Types=%s\n",wsdd__Probe->Types);
	ProbeMatches.ProbeMatch->MetadataVersion = 1;
	//ws-discovery规定 为可选项
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ReferenceProperties->__size = 0;
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ReferenceProperties->__any = NULL;
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ReferenceParameters->__size = 0;
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ReferenceParameters->__any = NULL;
	
	ProbeMatches.ProbeMatch->wsa__EndpointReference.PortType[0] = (char *)soap_malloc(soap, sizeof(char) * SMALL_INFO_LENGTH);
	//ws-discovery规定 为可选项
	strcpy(ProbeMatches.ProbeMatch->wsa__EndpointReference.PortType[0], "ttl");
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ServiceName->__item = NULL;
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ServiceName->PortName = NULL;
	ProbeMatches.ProbeMatch->wsa__EndpointReference.ServiceName->__anyAttribute = NULL;
	ProbeMatches.ProbeMatch->wsa__EndpointReference.__any[0] = (char *)soap_malloc(soap, sizeof(char) * SMALL_INFO_LENGTH);
	strcpy(ProbeMatches.ProbeMatch->wsa__EndpointReference.__any[0], "Any");
	strcpy(ProbeMatches.ProbeMatch->wsa__EndpointReference.__anyAttribute, "Attribute");
	ProbeMatches.ProbeMatch->wsa__EndpointReference.__size = 0;
	strcpy(ProbeMatches.ProbeMatch->wsa__EndpointReference.Address, _HwId);

	/*注释的部分为可选，注释掉onvif test也能发现ws-d*/
//    soap->header->wsa__To = "http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous";
//    soap->header->wsa__Action = "http://schemas.xmlsoap.org/ws/2005/04/discovery/ProbeMatches";
	soap->header->wsa__RelatesTo = (struct wsa__Relationship*)soap_malloc(soap, sizeof(struct wsa__Relationship));
	//it's here
	soap->header->wsa__RelatesTo->__item = soap->header->wsa__MessageID;
	soap->header->wsa__RelatesTo->RelationshipType = NULL;
	soap->header->wsa__RelatesTo->__anyAttribute = NULL;
	soap->header->wsa5__MessageID = NULL;
	soap->header->wsa5__To= NULL;
	soap->header->wsa5__Action = NULL;

	soap->header->wsa__MessageID =(char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	strcpy(soap->header->wsa__MessageID,_HwId+4);

    //const char *Action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/ProbeMatches";
	const char *Action ="something";
    /* send over current socket as HTTP OK response: */
	/*测试过，第二参数必须http，action随意*/
    soap_send___wsdd__ProbeMatches(soap, "http://", NULL, &ProbeMatches);
    //soap_send___wsdd__ProbeMatches(soap, "something", Action, &ProbeMatches);
	return SOAP_OK;

}

int  __wsdd__ProbeMatches(struct soap* soap, struct wsdd__ProbeMatchesType *wsdd__ProbeMatches)
{

}

int  __wsdd__Resolve(struct soap* soap, struct wsdd__ResolveType *wsdd__Resolve)
{

}

int  __wsdd__ResolveMatches(struct soap* soap, struct wsdd__ResolveMatchesType *wsdd__ResolveMatches)
{

}

int  __ns1__GetSupportedActions(struct soap* soap, struct _ns1__GetSupportedActions *ns1__GetSupportedActions, struct _ns1__GetSupportedActionsResponse *ns1__GetSupportedActionsResponse)
{

}

int  __ns1__GetActions(struct soap* soap, struct _ns1__GetActions *ns1__GetActions, struct _ns1__GetActionsResponse *ns1__GetActionsResponse)
{

}

int  __ns1__CreateActions(struct soap* soap, struct _ns1__CreateActions *ns1__CreateActions, struct _ns1__CreateActionsResponse *ns1__CreateActionsResponse)
{

}

int  __ns1__DeleteActions(struct soap* soap, struct _ns1__DeleteActions *ns1__DeleteActions, struct _ns1__DeleteActionsResponse *ns1__DeleteActionsResponse)
{

}

int  __ns1__ModifyActions(struct soap* soap, struct _ns1__ModifyActions *ns1__ModifyActions, struct _ns1__ModifyActionsResponse *ns1__ModifyActionsResponse)
{

}

int  __ns1__GetServiceCapabilities(struct soap* soap, struct _ns1__GetServiceCapabilities *ns1__GetServiceCapabilities, struct _ns1__GetServiceCapabilitiesResponse *ns1__GetServiceCapabilitiesResponse)
{

}

int  __ns1__GetActionTriggers(struct soap* soap, struct _ns1__GetActionTriggers *ns1__GetActionTriggers, struct _ns1__GetActionTriggersResponse *ns1__GetActionTriggersResponse)
{

}

int  __ns1__CreateActionTriggers(struct soap* soap, struct _ns1__CreateActionTriggers *ns1__CreateActionTriggers, struct _ns1__CreateActionTriggersResponse *ns1__CreateActionTriggersResponse)
{

}

int  __ns1__DeleteActionTriggers(struct soap* soap, struct _ns1__DeleteActionTriggers *ns1__DeleteActionTriggers, struct _ns1__DeleteActionTriggersResponse *ns1__DeleteActionTriggersResponse)
{

}

int  __ns1__ModifyActionTriggers(struct soap* soap, struct _ns1__ModifyActionTriggers *ns1__ModifyActionTriggers, struct _ns1__ModifyActionTriggersResponse *ns1__ModifyActionTriggersResponse)
{

}

int  __ns10__Renew(struct soap* soap, struct _wsnt__Renew *wsnt__Renew, struct _wsnt__RenewResponse *wsnt__RenewResponse)
{

}

int  __ns10__Unsubscribe(struct soap* soap, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse)
{

}

int  __ns10__PauseSubscription(struct soap* soap, struct _wsnt__PauseSubscription *wsnt__PauseSubscription, struct _wsnt__PauseSubscriptionResponse *wsnt__PauseSubscriptionResponse)
{

}

int  __ns10__ResumeSubscription(struct soap* soap, struct _wsnt__ResumeSubscription *wsnt__ResumeSubscription, struct _wsnt__ResumeSubscriptionResponse *wsnt__ResumeSubscriptionResponse)
{

}

int  __ns11__Hello(struct soap* soap, struct wsdd__HelloType tdn__Hello, struct wsdd__ResolveType *tdn__HelloResponse)
{

}

int  __ns11__Bye(struct soap* soap, struct wsdd__ByeType tdn__Bye, struct wsdd__ResolveType *tdn__ByeResponse)
{

}

int  __ns12__Probe(struct soap* soap, struct wsdd__ProbeType tdn__Probe, struct wsdd__ProbeMatchesType *tdn__ProbeResponse)
{

}

int  __ns13__GetSupportedRules(struct soap* soap, struct _tan__GetSupportedRules *tan__GetSupportedRules, struct _tan__GetSupportedRulesResponse *tan__GetSupportedRulesResponse)
{

}

int  __ns13__CreateRules(struct soap* soap, struct _tan__CreateRules *tan__CreateRules, struct _tan__CreateRulesResponse *tan__CreateRulesResponse)
{

}

int  __ns13__DeleteRules(struct soap* soap, struct _tan__DeleteRules *tan__DeleteRules, struct _tan__DeleteRulesResponse *tan__DeleteRulesResponse)
{

}

int  __ns13__GetRules(struct soap* soap, struct _tan__GetRules *tan__GetRules, struct _tan__GetRulesResponse *tan__GetRulesResponse)
{

}

int  __ns13__ModifyRules(struct soap* soap, struct _tan__ModifyRules *tan__ModifyRules, struct _tan__ModifyRulesResponse *tan__ModifyRulesResponse)
{

}

int  __ns14__GetServiceCapabilities(struct soap* soap, struct _tan__GetServiceCapabilities *tan__GetServiceCapabilities, struct _tan__GetServiceCapabilitiesResponse *tan__GetServiceCapabilitiesResponse)
{

}

int  __ns14__GetSupportedAnalyticsModules(struct soap* soap, struct _tan__GetSupportedAnalyticsModules *tan__GetSupportedAnalyticsModules, struct _tan__GetSupportedAnalyticsModulesResponse *tan__GetSupportedAnalyticsModulesResponse)
{

}

int  __ns14__CreateAnalyticsModules(struct soap* soap, struct _tan__CreateAnalyticsModules *tan__CreateAnalyticsModules, struct _tan__CreateAnalyticsModulesResponse *tan__CreateAnalyticsModulesResponse)
{

}

int  __ns14__DeleteAnalyticsModules(struct soap* soap, struct _tan__DeleteAnalyticsModules *tan__DeleteAnalyticsModules, struct _tan__DeleteAnalyticsModulesResponse *tan__DeleteAnalyticsModulesResponse)
{

}

int  __ns14__GetAnalyticsModules(struct soap* soap, struct _tan__GetAnalyticsModules *tan__GetAnalyticsModules, struct _tan__GetAnalyticsModulesResponse *tan__GetAnalyticsModulesResponse)
{

}

int  __ns14__ModifyAnalyticsModules(struct soap* soap, struct _tan__ModifyAnalyticsModules *tan__ModifyAnalyticsModules, struct _tan__ModifyAnalyticsModulesResponse *tan__ModifyAnalyticsModulesResponse)
{

}

int  __ns3__PullMessages(struct soap* soap, struct _tev__PullMessages *tev__PullMessages, struct _tev__PullMessagesResponse *tev__PullMessagesResponse)
{

}

int  __ns3__SetSynchronizationPoint(struct soap* soap, struct _tev__SetSynchronizationPoint *tev__SetSynchronizationPoint, struct _tev__SetSynchronizationPointResponse *tev__SetSynchronizationPointResponse)
{

}

int  __ns4__GetServiceCapabilities(struct soap* soap, struct _tev__GetServiceCapabilities *tev__GetServiceCapabilities, struct _tev__GetServiceCapabilitiesResponse *tev__GetServiceCapabilitiesResponse)
{

}

int  __ns4__CreatePullPointSubscription(struct soap* soap, struct _tev__CreatePullPointSubscription *tev__CreatePullPointSubscription, struct _tev__CreatePullPointSubscriptionResponse *tev__CreatePullPointSubscriptionResponse)
{

}

int  __ns4__GetEventProperties(struct soap* soap, struct _tev__GetEventProperties *tev__GetEventProperties, struct _tev__GetEventPropertiesResponse *tev__GetEventPropertiesResponse)
{

}

int  __ns5__Renew(struct soap* soap, struct _wsnt__Renew *wsnt__Renew, struct _wsnt__RenewResponse *wsnt__RenewResponse)
{

}

int  __ns5__Unsubscribe(struct soap* soap, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse)
{

}

int  __ns6__Subscribe(struct soap* soap, struct _wsnt__Subscribe *wsnt__Subscribe, struct _wsnt__SubscribeResponse *wsnt__SubscribeResponse)
{
	DBG("__ns6__Subscribe\n");
}

int  __ns6__GetCurrentMessage(struct soap* soap, struct _wsnt__GetCurrentMessage *wsnt__GetCurrentMessage, struct _wsnt__GetCurrentMessageResponse *wsnt__GetCurrentMessageResponse)
{

}

int  __ns7__Notify(struct soap* soap, struct _wsnt__Notify *wsnt__Notify)
{

}

int  __ns8__GetMessages(struct soap* soap, struct _wsnt__GetMessages *wsnt__GetMessages, struct _wsnt__GetMessagesResponse *wsnt__GetMessagesResponse)
{

}

int  __ns8__DestroyPullPoint(struct soap* soap, struct _wsnt__DestroyPullPoint *wsnt__DestroyPullPoint, struct _wsnt__DestroyPullPointResponse *wsnt__DestroyPullPointResponse)
{

}

int  __ns8__Notify(struct soap* soap, struct _wsnt__Notify *wsnt__Notify)
{

}

int  __ns9__CreatePullPoint(struct soap* soap, struct _wsnt__CreatePullPoint *wsnt__CreatePullPoint, struct _wsnt__CreatePullPointResponse *wsnt__CreatePullPointResponse)
{

}

int  __tad__GetServiceCapabilities(struct soap* soap, struct _tad__GetServiceCapabilities *tad__GetServiceCapabilities, struct _tad__GetServiceCapabilitiesResponse *tad__GetServiceCapabilitiesResponse)
{

}

int  __tad__DeleteAnalyticsEngineControl(struct soap* soap, struct _tad__DeleteAnalyticsEngineControl *tad__DeleteAnalyticsEngineControl, struct _tad__DeleteAnalyticsEngineControlResponse *tad__DeleteAnalyticsEngineControlResponse)
{

}

int  __tad__CreateAnalyticsEngineControl(struct soap* soap, struct _tad__CreateAnalyticsEngineControl *tad__CreateAnalyticsEngineControl, struct _tad__CreateAnalyticsEngineControlResponse *tad__CreateAnalyticsEngineControlResponse)
{

}

int  __tad__SetAnalyticsEngineControl(struct soap* soap, struct _tad__SetAnalyticsEngineControl *tad__SetAnalyticsEngineControl, struct _tad__SetAnalyticsEngineControlResponse *tad__SetAnalyticsEngineControlResponse)
{

}

int  __tad__GetAnalyticsEngineControl(struct soap* soap, struct _tad__GetAnalyticsEngineControl *tad__GetAnalyticsEngineControl, struct _tad__GetAnalyticsEngineControlResponse *tad__GetAnalyticsEngineControlResponse)
{

}

int  __tad__GetAnalyticsEngineControls(struct soap* soap, struct _tad__GetAnalyticsEngineControls *tad__GetAnalyticsEngineControls, struct _tad__GetAnalyticsEngineControlsResponse *tad__GetAnalyticsEngineControlsResponse)
{

}

int  __tad__GetAnalyticsEngine(struct soap* soap, struct _tad__GetAnalyticsEngine *tad__GetAnalyticsEngine, struct _tad__GetAnalyticsEngineResponse *tad__GetAnalyticsEngineResponse)
{

}

int  __tad__GetAnalyticsEngines(struct soap* soap, struct _tad__GetAnalyticsEngines *tad__GetAnalyticsEngines, struct _tad__GetAnalyticsEnginesResponse *tad__GetAnalyticsEnginesResponse)
{

}

int  __tad__SetVideoAnalyticsConfiguration(struct soap* soap, struct _tad__SetVideoAnalyticsConfiguration *tad__SetVideoAnalyticsConfiguration, struct _tad__SetVideoAnalyticsConfigurationResponse *tad__SetVideoAnalyticsConfigurationResponse)
{

}

int  __tad__SetAnalyticsEngineInput(struct soap* soap, struct _tad__SetAnalyticsEngineInput *tad__SetAnalyticsEngineInput, struct _tad__SetAnalyticsEngineInputResponse *tad__SetAnalyticsEngineInputResponse)
{

}

int  __tad__GetAnalyticsEngineInput(struct soap* soap, struct _tad__GetAnalyticsEngineInput *tad__GetAnalyticsEngineInput, struct _tad__GetAnalyticsEngineInputResponse *tad__GetAnalyticsEngineInputResponse)
{

}

int  __tad__GetAnalyticsEngineInputs(struct soap* soap, struct _tad__GetAnalyticsEngineInputs *tad__GetAnalyticsEngineInputs, struct _tad__GetAnalyticsEngineInputsResponse *tad__GetAnalyticsEngineInputsResponse)
{

}

int  __tad__GetAnalyticsDeviceStreamUri(struct soap* soap, struct _tad__GetAnalyticsDeviceStreamUri *tad__GetAnalyticsDeviceStreamUri, struct _tad__GetAnalyticsDeviceStreamUriResponse *tad__GetAnalyticsDeviceStreamUriResponse)
{

}

int  __tad__GetVideoAnalyticsConfiguration(struct soap* soap, struct _tad__GetVideoAnalyticsConfiguration *tad__GetVideoAnalyticsConfiguration, struct _tad__GetVideoAnalyticsConfigurationResponse *tad__GetVideoAnalyticsConfigurationResponse)
{

}

int  __tad__CreateAnalyticsEngineInputs(struct soap* soap, struct _tad__CreateAnalyticsEngineInputs *tad__CreateAnalyticsEngineInputs, struct _tad__CreateAnalyticsEngineInputsResponse *tad__CreateAnalyticsEngineInputsResponse)
{

}

int  __tad__DeleteAnalyticsEngineInputs(struct soap* soap, struct _tad__DeleteAnalyticsEngineInputs *tad__DeleteAnalyticsEngineInputs, struct _tad__DeleteAnalyticsEngineInputsResponse *tad__DeleteAnalyticsEngineInputsResponse)
{

}

int  __tad__GetAnalyticsState(struct soap* soap, struct _tad__GetAnalyticsState *tad__GetAnalyticsState, struct _tad__GetAnalyticsStateResponse *tad__GetAnalyticsStateResponse)
{

}

int  __tds__GetServices(struct soap* soap, struct _tds__GetServices *tds__GetServices, struct _tds__GetServicesResponse *tds__GetServicesResponse)
{
	DBG("__tds__GetServices\n");
	/*该函数很必要*/
	char _IPAddr[INFO_LENGTH];
	int i = 0;
	sprintf(_IPAddr, "http://%03d.%03d.%03d.%03d/onvif/services", 192, 168, 1, 233);
	tds__GetServicesResponse->__sizeService = 1;

	tds__GetServicesResponse->Service = (struct tds__Service *)soap_malloc(soap, sizeof(struct tds__Service));
	tds__GetServicesResponse->Service[0].XAddr = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	tds__GetServicesResponse->Service[0].Namespace = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	strcpy(tds__GetServicesResponse->Service[0].Namespace, "http://www.onvif.org/ver10/events/wsdl");
	strcpy(tds__GetServicesResponse[0].Service->XAddr, _IPAddr);
	tds__GetServicesResponse->Service[0].Capabilities = NULL;
	tds__GetServicesResponse->Service[0].Version = (struct tt__OnvifVersion *)soap_malloc(soap, sizeof(struct tt__OnvifVersion));
	tds__GetServicesResponse->Service[0].Version->Major = 0;
	tds__GetServicesResponse->Service[0].Version->Minor = 3;
	tds__GetServicesResponse->Service[0].__any = (char **)soap_malloc(soap, sizeof(char *));
	tds__GetServicesResponse->Service[0].__any[0] = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	strcpy(tds__GetServicesResponse->Service[0].__any[0],"why1");
	tds__GetServicesResponse->Service[0].__any[1] = (char *)soap_malloc(soap,sizeof(char) * INFO_LENGTH);
	strcpy(tds__GetServicesResponse->Service[0].__any[1],"why2");
	tds__GetServicesResponse->Service[0].__size = NULL;
	tds__GetServicesResponse->Service[0].__anyAttribute = NULL;
	return SOAP_OK;
}

int  __tds__GetServiceCapabilities(struct soap* soap, struct _tds__GetServiceCapabilities *tds__GetServiceCapabilities, struct _tds__GetServiceCapabilitiesResponse *tds__GetServiceCapabilitiesResponse)
{
	DBG("__tds__GetServiceCapabilities\n");
}

int  __tds__GetDeviceInformation(struct soap* soap, struct _tds__GetDeviceInformation *tds__GetDeviceInformation, struct _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse)
{
	DBG("__tds__GetDeviceInformation\n");
	tds__GetDeviceInformationResponse->Manufacturer=(char*)soap_malloc(soap,100);
	tds__GetDeviceInformationResponse->Model=(char*)soap_malloc(soap,100);
	tds__GetDeviceInformationResponse->FirmwareVersion=(char*)soap_malloc(soap,100);
	tds__GetDeviceInformationResponse->SerialNumber=(char*)soap_malloc(soap,100);
	tds__GetDeviceInformationResponse->HardwareId=(char*)soap_malloc(soap,100);

	strcpy(tds__GetDeviceInformationResponse->Manufacturer,"ilike co.ltd");
	strcpy(tds__GetDeviceInformationResponse->Model,"dm368-ov2715");
	strcpy(tds__GetDeviceInformationResponse->FirmwareVersion,"v3.00.01");
	strcpy(tds__GetDeviceInformationResponse->SerialNumber,"01020304050607080900");
	strcpy(tds__GetDeviceInformationResponse->HardwareId,"0101010101");
	return SOAP_OK;
}

int  __tds__SetSystemDateAndTime(struct soap* soap, struct _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, struct _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse)
{

}

int  __tds__GetSystemDateAndTime(struct soap* soap, struct _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, struct _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse)
{

}

int  __tds__SetSystemFactoryDefault(struct soap* soap, struct _tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, struct _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse)
{

}

int  __tds__UpgradeSystemFirmware(struct soap* soap, struct _tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, struct _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse)
{

}

int  __tds__SystemReboot(struct soap* soap, struct _tds__SystemReboot *tds__SystemReboot, struct _tds__SystemRebootResponse *tds__SystemRebootResponse)
{

}

int  __tds__RestoreSystem(struct soap* soap, struct _tds__RestoreSystem *tds__RestoreSystem, struct _tds__RestoreSystemResponse *tds__RestoreSystemResponse)
{

}

int  __tds__GetSystemBackup(struct soap* soap, struct _tds__GetSystemBackup *tds__GetSystemBackup, struct _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse)
{

}

int  __tds__GetSystemLog(struct soap* soap, struct _tds__GetSystemLog *tds__GetSystemLog, struct _tds__GetSystemLogResponse *tds__GetSystemLogResponse)
{

}

int  __tds__GetSystemSupportInformation(struct soap* soap, struct _tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, struct _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse)
{

}

int  __tds__GetScopes(struct soap* soap, struct _tds__GetScopes *tds__GetScopes, struct _tds__GetScopesResponse *tds__GetScopesResponse)
{
	DBG("__tds__GetScopes\n");
	int size=0;
	size = 1;
	tds__GetScopesResponse->__sizeScopes=size;
	tds__GetScopesResponse->Scopes = (struct tt__Scope*)soap_malloc(soap, size*sizeof(struct tt__Scope));
	tds__GetScopesResponse->Scopes->ScopeItem = (char*)soap_malloc(soap, 100);
	tds__GetScopesResponse->Scopes->ScopeDef=0;
	strcpy(tds__GetScopesResponse->Scopes->ScopeItem,"onvif://www.onvif.org/type/NetworkVideoTransmitter");
	return SOAP_OK;
}

int  __tds__SetScopes(struct soap* soap, struct _tds__SetScopes *tds__SetScopes, struct _tds__SetScopesResponse *tds__SetScopesResponse)
{

}

int  __tds__AddScopes(struct soap* soap, struct _tds__AddScopes *tds__AddScopes, struct _tds__AddScopesResponse *tds__AddScopesResponse)
{

}

int  __tds__RemoveScopes(struct soap* soap, struct _tds__RemoveScopes *tds__RemoveScopes, struct _tds__RemoveScopesResponse *tds__RemoveScopesResponse)
{

}

int  __tds__GetDiscoveryMode(struct soap* soap, struct _tds__GetDiscoveryMode *tds__GetDiscoveryMode, struct _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse)
{

}

int  __tds__SetDiscoveryMode(struct soap* soap, struct _tds__SetDiscoveryMode *tds__SetDiscoveryMode, struct _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse)
{

}

int  __tds__GetRemoteDiscoveryMode(struct soap* soap, struct _tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, struct _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse)
{

}

int  __tds__SetRemoteDiscoveryMode(struct soap* soap, struct _tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, struct _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse)
{

}

int  __tds__GetDPAddresses(struct soap* soap, struct _tds__GetDPAddresses *tds__GetDPAddresses, struct _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse)
{

}

int  __tds__GetEndpointReference(struct soap* soap, struct _tds__GetEndpointReference *tds__GetEndpointReference, struct _tds__GetEndpointReferenceResponse *tds__GetEndpointReferenceResponse)
{

}

int  __tds__GetRemoteUser(struct soap* soap, struct _tds__GetRemoteUser *tds__GetRemoteUser, struct _tds__GetRemoteUserResponse *tds__GetRemoteUserResponse)
{

}

int  __tds__SetRemoteUser(struct soap* soap, struct _tds__SetRemoteUser *tds__SetRemoteUser, struct _tds__SetRemoteUserResponse *tds__SetRemoteUserResponse)
{

}

int  __tds__GetUsers(struct soap* soap, struct _tds__GetUsers *tds__GetUsers, struct _tds__GetUsersResponse *tds__GetUsersResponse)
{

}

int  __tds__CreateUsers(struct soap* soap, struct _tds__CreateUsers *tds__CreateUsers, struct _tds__CreateUsersResponse *tds__CreateUsersResponse)
{

}

int  __tds__DeleteUsers(struct soap* soap, struct _tds__DeleteUsers *tds__DeleteUsers, struct _tds__DeleteUsersResponse *tds__DeleteUsersResponse)
{

}

int  __tds__SetUser(struct soap* soap, struct _tds__SetUser *tds__SetUser, struct _tds__SetUserResponse *tds__SetUserResponse)
{

}

int  __tds__GetWsdlUrl(struct soap* soap, struct _tds__GetWsdlUrl *tds__GetWsdlUrl, struct _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse)
{

}


int  __tds__GetCapabilities(struct soap* soap, struct _tds__GetCapabilities *tds__GetCapabilities, struct _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse)
{
	DBG("__tds__GetCapabilities\n");
	int _Category;
	char _IPv4Address[LARGE_INFO_LENGTH]; 

	if(tds__GetCapabilities->Category == NULL)
	{
		tds__GetCapabilities->Category=(int *)soap_malloc(soap, sizeof(int));
		*tds__GetCapabilities->Category = ALL;
		_Category = ALL;
	}
	else
	{
		_Category = *tds__GetCapabilities->Category;
	}

	sprintf(_IPv4Address, "http://%03d.%03d.%03d.%03d/onvif/services",192,168,1,233);
	tds__GetCapabilitiesResponse->Capabilities = (struct tt__Capabilities*)soap_malloc(soap, sizeof(struct tt__Capabilities));
	tds__GetCapabilitiesResponse->Capabilities->Analytics = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Events = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Imaging = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Media = NULL;
	tds__GetCapabilitiesResponse->Capabilities->PTZ = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension = (struct tt__CapabilitiesExtension*)soap_malloc(soap, sizeof(struct tt__CapabilitiesExtension));
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO = (struct tt__DeviceIOCapabilities*)soap_malloc(soap, sizeof(struct tt__DeviceIOCapabilities));
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->XAddr = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	strcpy(tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->XAddr,_IPv4Address);

	//下面的重要，这里只实现视频流，需要设置VideoSources
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->VideoSources = TRUE;
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->VideoOutputs = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->AudioSources = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->AudioOutputs = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->RelayOutputs = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->__size = 0;
	tds__GetCapabilitiesResponse->Capabilities->Extension->DeviceIO->__any = NULL;
	
	tds__GetCapabilitiesResponse->Capabilities->Extension->Display = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension->Recording = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension->Search = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension->Replay = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension->Receiver = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension->AnalyticsDevice = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension->Extensions = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Extension->__size = 0;
	tds__GetCapabilitiesResponse->Capabilities->Extension->__any = NULL;
	
	/*基础设置，很必须*/
	tds__GetCapabilitiesResponse->Capabilities->Device = (struct tt__DeviceCapabilities*)soap_malloc(soap, sizeof(struct tt__DeviceCapabilities));
	tds__GetCapabilitiesResponse->Capabilities->Device->XAddr = (char *) soap_malloc(soap, sizeof(char) * LARGE_INFO_LENGTH);
	strcpy(tds__GetCapabilitiesResponse->Capabilities->Device->XAddr, _IPv4Address);	
	tds__GetCapabilitiesResponse->Capabilities->Device->Extension = NULL;

	/*必要部分*/
	tds__GetCapabilitiesResponse->Capabilities->Device->Network = (struct tt__NetworkCapabilities*)soap_malloc(soap, sizeof(struct tt__NetworkCapabilities));
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->IPFilter = (int *)soap_malloc(soap, sizeof(int));
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->ZeroConfiguration = (int *)soap_malloc(soap, sizeof(int));
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->IPVersion6 = (int *)soap_malloc(soap, sizeof(int));
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->DynDNS = (int *)soap_malloc(soap, sizeof(int));
		
	*tds__GetCapabilitiesResponse->Capabilities->Device->Network->IPFilter = _false;	
	*tds__GetCapabilitiesResponse->Capabilities->Device->Network->ZeroConfiguration = _false;
	*tds__GetCapabilitiesResponse->Capabilities->Device->Network->IPVersion6 = _false;
	*tds__GetCapabilitiesResponse->Capabilities->Device->Network->DynDNS = _false;	
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->Extension = (struct tt__NetworkCapabilitiesExtension*)soap_malloc(soap, sizeof(struct tt__NetworkCapabilitiesExtension));
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->Extension->Dot11Configuration = (int *)soap_malloc(soap, sizeof(int)); 
	*tds__GetCapabilitiesResponse->Capabilities->Device->Network->Extension->Dot11Configuration = _false; 
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->Extension->Extension = NULL;
	/*ghostyu  MUST BE*/
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->Extension->__size= 0;
	tds__GetCapabilitiesResponse->Capabilities->Device->Network->Extension->__any = NULL;

	tds__GetCapabilitiesResponse->Capabilities->Device->System = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security = NULL;
#if 0
	tds__GetCapabilitiesResponse->Capabilities->Device->System = (struct tt__SystemCapabilities*)soap_malloc(soap, sizeof(struct tt__SystemCapabilities));		
	tds__GetCapabilitiesResponse->Capabilities->Device->System->DiscoveryResolve = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->DiscoveryBye = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->RemoteDiscovery = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->SystemBackup = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->SystemLogging = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->FirmwareUpgrade = FALSE;	
	tds__GetCapabilitiesResponse->Capabilities->Device->System->__sizeSupportedVersions = TRUE;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->SupportedVersions = (struct tt__OnvifVersion*)soap_malloc(soap, sizeof(struct tt__OnvifVersion));
	tds__GetCapabilitiesResponse->Capabilities->Device->System->SupportedVersions->Major = MAJOR;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->SupportedVersions->Minor = MINOR;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension = (struct tt__SystemCapabilitiesExtension*)soap_malloc(soap, sizeof(struct tt__SystemCapabilitiesExtension));
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpSystemBackup = (int *)soap_malloc(soap, sizeof(int));
	*tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpSystemBackup = _false;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpFirmwareUpgrade = (int *)soap_malloc(soap, sizeof(int));
	*tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpFirmwareUpgrade = _true;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpSystemLogging = (int *)soap_malloc(soap, sizeof(int));
	*tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpSystemLogging = _true;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpSupportInformation = (int *)soap_malloc(soap, sizeof(int));
	*tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->HttpSupportInformation = _true;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->Extension = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->__size = 0;
	tds__GetCapabilitiesResponse->Capabilities->Device->System->Extension->__any = NULL;

	tds__GetCapabilitiesResponse->Capabilities->Device->IO = (struct tt__IOCapabilities*)soap_malloc(soap, sizeof(struct tt__IOCapabilities));
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->InputConnectors = &_false;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->RelayOutputs = &_false;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension = (struct tt__IOCapabilitiesExtension *)soap_malloc(soap, sizeof(struct tt__IOCapabilitiesExtension));
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension->__size =0;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension->__any = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension->Auxiliary = &_false;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension->__anyAttribute = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension->__sizeAuxiliaryCommands = 0;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension->AuxiliaryCommands= NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->IO->Extension->Extension = NULL;
#endif
#if 0	
	tds__GetCapabilitiesResponse->Capabilities->Device->Security = (struct tt__SecurityCapabilities*)soap_malloc(soap, sizeof(struct tt__SecurityCapabilities));
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->TLS1_x002e1 = FALSE;	
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->TLS1_x002e2 = FALSE;	
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->OnboardKeyGeneration = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->AccessPolicyConfig = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->X_x002e509Token = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->SAMLToken = FALSE;	
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->KerberosToken = FALSE;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->RELToken = FALSE;	
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->Extension = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->__size = 0;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->__any = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->Security->__anyAttribute = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Device->Extension = NULL;
#endif

	//想要对接RTSP视频，必须设置Media
	tds__GetCapabilitiesResponse->Capabilities->Media = (struct tt__MediaCapabilities*)soap_malloc(soap, sizeof(struct tt__MediaCapabilities));
	tds__GetCapabilitiesResponse->Capabilities->Media->XAddr = (char *) soap_malloc(soap, sizeof(char) * LARGE_INFO_LENGTH);
	strcpy(tds__GetCapabilitiesResponse->Capabilities->Media->XAddr, _IPv4Address);
	tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities = (struct tt__RealTimeStreamingCapabilities*)soap_malloc(soap, sizeof(struct tt__RealTimeStreamingCapabilities));
	tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTPMulticast = (int *)soap_malloc(soap, sizeof(int));	
	*tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTPMulticast = _false;	
	tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP = (int *)soap_malloc(soap, sizeof(int));
	*tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP = _true;	
	tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP = (int *)soap_malloc(soap, sizeof(int));
	*tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP = _true;	
	tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->Extension = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Media->Extension = NULL;
	tds__GetCapabilitiesResponse->Capabilities->Media->__size = 0;
	tds__GetCapabilitiesResponse->Capabilities->Media->__any = 0;
	return SOAP_OK;
}

int  __tds__SetDPAddresses(struct soap* soap, struct _tds__SetDPAddresses *tds__SetDPAddresses, struct _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse)
{

}

int  __tds__GetHostname(struct soap* soap, struct _tds__GetHostname *tds__GetHostname, struct _tds__GetHostnameResponse *tds__GetHostnameResponse)
{
	DBG("__tds__GetHostname\n");
	tds__GetHostnameResponse->HostnameInformation = (struct tt__HostnameInformation*)soap_malloc(soap,sizeof(struct tt__HostnameInformation));
	tds__GetHostnameResponse->HostnameInformation->Name = (char*)soap_malloc(soap,100);
	tds__GetHostnameResponse->HostnameInformation->Extension = (struct tt__HostnameInformationExtension*)soap_malloc(soap,sizeof(struct tt__HostnameInformationExtension ));

	tds__GetHostnameResponse->HostnameInformation->Extension->__size = 0;
	tds__GetHostnameResponse->HostnameInformation->Extension->__any= NULL;
	tds__GetHostnameResponse->HostnameInformation->FromDHCP = 0; //not from DHCP
	strcpy(tds__GetHostnameResponse->HostnameInformation->Name,"ghostyu");
	return SOAP_OK;
}

int  __tds__SetHostname(struct soap* soap, struct _tds__SetHostname *tds__SetHostname, struct _tds__SetHostnameResponse *tds__SetHostnameResponse)
{

}

int  __tds__SetHostnameFromDHCP(struct soap* soap, struct _tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, struct _tds__SetHostnameFromDHCPResponse *tds__SetHostnameFromDHCPResponse)
{

}

int  __tds__GetDNS(struct soap* soap, struct _tds__GetDNS *tds__GetDNS, struct _tds__GetDNSResponse *tds__GetDNSResponse)
{

}

int  __tds__SetDNS(struct soap* soap, struct _tds__SetDNS *tds__SetDNS, struct _tds__SetDNSResponse *tds__SetDNSResponse)
{

}

int  __tds__GetNTP(struct soap* soap, struct _tds__GetNTP *tds__GetNTP, struct _tds__GetNTPResponse *tds__GetNTPResponse)
{

}

int  __tds__SetNTP(struct soap* soap, struct _tds__SetNTP *tds__SetNTP, struct _tds__SetNTPResponse *tds__SetNTPResponse)
{

}

int  __tds__GetDynamicDNS(struct soap* soap, struct _tds__GetDynamicDNS *tds__GetDynamicDNS, struct _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse)
{

}

int  __tds__SetDynamicDNS(struct soap* soap, struct _tds__SetDynamicDNS *tds__SetDynamicDNS, struct _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse)
{

}

int  __tds__GetNetworkInterfaces(struct soap* soap, struct _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, struct _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse)
{

}

int  __tds__SetNetworkInterfaces(struct soap* soap, struct _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, struct _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse)
{

}

int  __tds__GetNetworkProtocols(struct soap* soap, struct _tds__GetNetworkProtocols *tds__GetNetworkProtocols, struct _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse)
{

}

int  __tds__SetNetworkProtocols(struct soap* soap, struct _tds__SetNetworkProtocols *tds__SetNetworkProtocols, struct _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse)
{

}

int  __tds__GetNetworkDefaultGateway(struct soap* soap, struct _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, struct _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse)
{

}

int  __tds__SetNetworkDefaultGateway(struct soap* soap, struct _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, struct _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse)
{

}

int  __tds__GetZeroConfiguration(struct soap* soap, struct _tds__GetZeroConfiguration *tds__GetZeroConfiguration, struct _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse)
{

}

int  __tds__SetZeroConfiguration(struct soap* soap, struct _tds__SetZeroConfiguration *tds__SetZeroConfiguration, struct _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse)
{

}

int  __tds__GetIPAddressFilter(struct soap* soap, struct _tds__GetIPAddressFilter *tds__GetIPAddressFilter, struct _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse)
{

}

int  __tds__SetIPAddressFilter(struct soap* soap, struct _tds__SetIPAddressFilter *tds__SetIPAddressFilter, struct _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse)
{

}

int  __tds__AddIPAddressFilter(struct soap* soap, struct _tds__AddIPAddressFilter *tds__AddIPAddressFilter, struct _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse)
{

}

int  __tds__RemoveIPAddressFilter(struct soap* soap, struct _tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, struct _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse)
{

}

int  __tds__GetAccessPolicy(struct soap* soap, struct _tds__GetAccessPolicy *tds__GetAccessPolicy, struct _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse)
{

}

int  __tds__SetAccessPolicy(struct soap* soap, struct _tds__SetAccessPolicy *tds__SetAccessPolicy, struct _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse)
{

}

int  __tds__CreateCertificate(struct soap* soap, struct _tds__CreateCertificate *tds__CreateCertificate, struct _tds__CreateCertificateResponse *tds__CreateCertificateResponse)
{

}

int  __tds__GetCertificates(struct soap* soap, struct _tds__GetCertificates *tds__GetCertificates, struct _tds__GetCertificatesResponse *tds__GetCertificatesResponse)
{

}

int  __tds__GetCertificatesStatus(struct soap* soap, struct _tds__GetCertificatesStatus *tds__GetCertificatesStatus, struct _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse)
{

}

int  __tds__SetCertificatesStatus(struct soap* soap, struct _tds__SetCertificatesStatus *tds__SetCertificatesStatus, struct _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse)
{

}

int  __tds__DeleteCertificates(struct soap* soap, struct _tds__DeleteCertificates *tds__DeleteCertificates, struct _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse)
{

}

int  __tds__GetPkcs10Request(struct soap* soap, struct _tds__GetPkcs10Request *tds__GetPkcs10Request, struct _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse)
{

}

int  __tds__LoadCertificates(struct soap* soap, struct _tds__LoadCertificates *tds__LoadCertificates, struct _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse)
{

}

int  __tds__GetClientCertificateMode(struct soap* soap, struct _tds__GetClientCertificateMode *tds__GetClientCertificateMode, struct _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse)
{

}

int  __tds__SetClientCertificateMode(struct soap* soap, struct _tds__SetClientCertificateMode *tds__SetClientCertificateMode, struct _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse)
{

}

int  __tds__GetRelayOutputs(struct soap* soap, struct _tds__GetRelayOutputs *tds__GetRelayOutputs, struct _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse)
{

}

int  __tds__SetRelayOutputSettings(struct soap* soap, struct _tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, struct _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse)
{

}

int  __tds__SetRelayOutputState(struct soap* soap, struct _tds__SetRelayOutputState *tds__SetRelayOutputState, struct _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse)
{

}

int  __tds__SendAuxiliaryCommand(struct soap* soap, struct _tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, struct _tds__SendAuxiliaryCommandResponse *tds__SendAuxiliaryCommandResponse)
{

}

int  __tds__GetCACertificates(struct soap* soap, struct _tds__GetCACertificates *tds__GetCACertificates, struct _tds__GetCACertificatesResponse *tds__GetCACertificatesResponse)
{

}

int  __tds__LoadCertificateWithPrivateKey(struct soap* soap, struct _tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, struct _tds__LoadCertificateWithPrivateKeyResponse *tds__LoadCertificateWithPrivateKeyResponse)
{

}

int  __tds__GetCertificateInformation(struct soap* soap, struct _tds__GetCertificateInformation *tds__GetCertificateInformation, struct _tds__GetCertificateInformationResponse *tds__GetCertificateInformationResponse)
{

}

int  __tds__LoadCACertificates(struct soap* soap, struct _tds__LoadCACertificates *tds__LoadCACertificates, struct _tds__LoadCACertificatesResponse *tds__LoadCACertificatesResponse)
{

}

int  __tds__CreateDot1XConfiguration(struct soap* soap, struct _tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, struct _tds__CreateDot1XConfigurationResponse *tds__CreateDot1XConfigurationResponse)
{

}

int  __tds__SetDot1XConfiguration(struct soap* soap, struct _tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, struct _tds__SetDot1XConfigurationResponse *tds__SetDot1XConfigurationResponse)
{

}

int  __tds__GetDot1XConfiguration(struct soap* soap, struct _tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, struct _tds__GetDot1XConfigurationResponse *tds__GetDot1XConfigurationResponse)
{

}

int  __tds__GetDot1XConfigurations(struct soap* soap, struct _tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, struct _tds__GetDot1XConfigurationsResponse *tds__GetDot1XConfigurationsResponse)
{

}

int  __tds__DeleteDot1XConfiguration(struct soap* soap, struct _tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, struct _tds__DeleteDot1XConfigurationResponse *tds__DeleteDot1XConfigurationResponse)
{

}

int  __tds__GetDot11Capabilities(struct soap* soap, struct _tds__GetDot11Capabilities *tds__GetDot11Capabilities, struct _tds__GetDot11CapabilitiesResponse *tds__GetDot11CapabilitiesResponse)
{

}

int  __tds__GetDot11Status(struct soap* soap, struct _tds__GetDot11Status *tds__GetDot11Status, struct _tds__GetDot11StatusResponse *tds__GetDot11StatusResponse)
{

}

int  __tds__ScanAvailableDot11Networks(struct soap* soap, struct _tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, struct _tds__ScanAvailableDot11NetworksResponse *tds__ScanAvailableDot11NetworksResponse)
{

}

int  __tds__GetSystemUris(struct soap* soap, struct _tds__GetSystemUris *tds__GetSystemUris, struct _tds__GetSystemUrisResponse *tds__GetSystemUrisResponse)
{

}

int  __tds__StartFirmwareUpgrade(struct soap* soap, struct _tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, struct _tds__StartFirmwareUpgradeResponse *tds__StartFirmwareUpgradeResponse)
{

}

int  __tds__StartSystemRestore(struct soap* soap, struct _tds__StartSystemRestore *tds__StartSystemRestore, struct _tds__StartSystemRestoreResponse *tds__StartSystemRestoreResponse)
{

}

int  __tds__GetServices_(struct soap* soap, struct _tds__GetServices *tds__GetServices, struct _tds__GetServicesResponse *tds__GetServicesResponse)
{

}

int  __tds__GetServiceCapabilities_(struct soap* soap, struct _tds__GetServiceCapabilities *tds__GetServiceCapabilities, struct _tds__GetServiceCapabilitiesResponse *tds__GetServiceCapabilitiesResponse)
{

}

int  __tds__GetDeviceInformation_(struct soap* soap, struct _tds__GetDeviceInformation *tds__GetDeviceInformation, struct _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse)
{

}

int  __tds__SetSystemDateAndTime_(struct soap* soap, struct _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, struct _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse)
{

}

int  __tds__GetSystemDateAndTime_(struct soap* soap, struct _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, struct _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse)
{

}

int  __tds__SetSystemFactoryDefault_(struct soap* soap, struct _tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, struct _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse)
{

}

int  __tds__UpgradeSystemFirmware_(struct soap* soap, struct _tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, struct _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse)
{

}

int  __tds__SystemReboot_(struct soap* soap, struct _tds__SystemReboot *tds__SystemReboot, struct _tds__SystemRebootResponse *tds__SystemRebootResponse)
{

}

int  __tds__RestoreSystem_(struct soap* soap, struct _tds__RestoreSystem *tds__RestoreSystem, struct _tds__RestoreSystemResponse *tds__RestoreSystemResponse)
{

}

int  __tds__GetSystemBackup_(struct soap* soap, struct _tds__GetSystemBackup *tds__GetSystemBackup, struct _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse)
{

}

int  __tds__GetSystemLog_(struct soap* soap, struct _tds__GetSystemLog *tds__GetSystemLog, struct _tds__GetSystemLogResponse *tds__GetSystemLogResponse)
{

}

int  __tds__GetSystemSupportInformation_(struct soap* soap, struct _tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, struct _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse)
{

}

int  __tds__GetScopes_(struct soap* soap, struct _tds__GetScopes *tds__GetScopes, struct _tds__GetScopesResponse *tds__GetScopesResponse)
{
	
}

int  __tds__SetScopes_(struct soap* soap, struct _tds__SetScopes *tds__SetScopes, struct _tds__SetScopesResponse *tds__SetScopesResponse)
{

}

int  __tds__AddScopes_(struct soap* soap, struct _tds__AddScopes *tds__AddScopes, struct _tds__AddScopesResponse *tds__AddScopesResponse)
{

}

int  __tds__RemoveScopes_(struct soap* soap, struct _tds__RemoveScopes *tds__RemoveScopes, struct _tds__RemoveScopesResponse *tds__RemoveScopesResponse)
{

}

int  __tds__GetDiscoveryMode_(struct soap* soap, struct _tds__GetDiscoveryMode *tds__GetDiscoveryMode, struct _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse)
{

}

int  __tds__SetDiscoveryMode_(struct soap* soap, struct _tds__SetDiscoveryMode *tds__SetDiscoveryMode, struct _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse)
{

}

int  __tds__GetRemoteDiscoveryMode_(struct soap* soap, struct _tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, struct _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse)
{

}

int  __tds__SetRemoteDiscoveryMode_(struct soap* soap, struct _tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, struct _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse)
{

}

int  __tds__GetDPAddresses_(struct soap* soap, struct _tds__GetDPAddresses *tds__GetDPAddresses, struct _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse)
{

}

int  __tds__GetEndpointReference_(struct soap* soap, struct _tds__GetEndpointReference *tds__GetEndpointReference, struct _tds__GetEndpointReferenceResponse *tds__GetEndpointReferenceResponse)
{

}

int  __tds__GetRemoteUser_(struct soap* soap, struct _tds__GetRemoteUser *tds__GetRemoteUser, struct _tds__GetRemoteUserResponse *tds__GetRemoteUserResponse)
{

}

int  __tds__SetRemoteUser_(struct soap* soap, struct _tds__SetRemoteUser *tds__SetRemoteUser, struct _tds__SetRemoteUserResponse *tds__SetRemoteUserResponse)
{

}

int  __tds__GetUsers_(struct soap* soap, struct _tds__GetUsers *tds__GetUsers, struct _tds__GetUsersResponse *tds__GetUsersResponse)
{

}

int  __tds__CreateUsers_(struct soap* soap, struct _tds__CreateUsers *tds__CreateUsers, struct _tds__CreateUsersResponse *tds__CreateUsersResponse)
{

}

int  __tds__DeleteUsers_(struct soap* soap, struct _tds__DeleteUsers *tds__DeleteUsers, struct _tds__DeleteUsersResponse *tds__DeleteUsersResponse)
{

}

int  __tds__SetUser_(struct soap* soap, struct _tds__SetUser *tds__SetUser, struct _tds__SetUserResponse *tds__SetUserResponse)
{

}

int  __tds__GetWsdlUrl_(struct soap* soap, struct _tds__GetWsdlUrl *tds__GetWsdlUrl, struct _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse)
{

}

int  __tds__GetCapabilities_(struct soap* soap, struct _tds__GetCapabilities *tds__GetCapabilities, struct _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse)
{

}

int  __tds__SetDPAddresses_(struct soap* soap, struct _tds__SetDPAddresses *tds__SetDPAddresses, struct _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse)
{

}

int  __tds__GetHostname_(struct soap* soap, struct _tds__GetHostname *tds__GetHostname, struct _tds__GetHostnameResponse *tds__GetHostnameResponse)
{

}

int  __tds__SetHostname_(struct soap* soap, struct _tds__SetHostname *tds__SetHostname, struct _tds__SetHostnameResponse *tds__SetHostnameResponse)
{

}

int  __tds__SetHostnameFromDHCP_(struct soap* soap, struct _tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, struct _tds__SetHostnameFromDHCPResponse *tds__SetHostnameFromDHCPResponse)
{

}

int  __tds__GetDNS_(struct soap* soap, struct _tds__GetDNS *tds__GetDNS, struct _tds__GetDNSResponse *tds__GetDNSResponse)
{

}

int  __tds__SetDNS_(struct soap* soap, struct _tds__SetDNS *tds__SetDNS, struct _tds__SetDNSResponse *tds__SetDNSResponse)
{

}

int  __tds__GetNTP_(struct soap* soap, struct _tds__GetNTP *tds__GetNTP, struct _tds__GetNTPResponse *tds__GetNTPResponse)
{

}

int  __tds__SetNTP_(struct soap* soap, struct _tds__SetNTP *tds__SetNTP, struct _tds__SetNTPResponse *tds__SetNTPResponse)
{

}

int  __tds__GetDynamicDNS_(struct soap* soap, struct _tds__GetDynamicDNS *tds__GetDynamicDNS, struct _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse)
{

}

int  __tds__SetDynamicDNS_(struct soap* soap, struct _tds__SetDynamicDNS *tds__SetDynamicDNS, struct _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse)
{

}

int  __tds__GetNetworkInterfaces_(struct soap* soap, struct _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, struct _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse)
{

}

int  __tds__SetNetworkInterfaces_(struct soap* soap, struct _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, struct _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse)
{

}

int  __tds__GetNetworkProtocols_(struct soap* soap, struct _tds__GetNetworkProtocols *tds__GetNetworkProtocols, struct _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse)
{

}

int  __tds__SetNetworkProtocols_(struct soap* soap, struct _tds__SetNetworkProtocols *tds__SetNetworkProtocols, struct _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse)
{

}

int  __tds__GetNetworkDefaultGateway_(struct soap* soap, struct _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, struct _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse)
{

}

int  __tds__SetNetworkDefaultGateway_(struct soap* soap, struct _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, struct _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse)
{

}

int  __tds__GetZeroConfiguration_(struct soap* soap, struct _tds__GetZeroConfiguration *tds__GetZeroConfiguration, struct _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse)
{

}

int  __tds__SetZeroConfiguration_(struct soap* soap, struct _tds__SetZeroConfiguration *tds__SetZeroConfiguration, struct _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse)
{

}

int  __tds__GetIPAddressFilter_(struct soap* soap, struct _tds__GetIPAddressFilter *tds__GetIPAddressFilter, struct _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse)
{

}

int  __tds__SetIPAddressFilter_(struct soap* soap, struct _tds__SetIPAddressFilter *tds__SetIPAddressFilter, struct _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse)
{

}

int  __tds__AddIPAddressFilter_(struct soap* soap, struct _tds__AddIPAddressFilter *tds__AddIPAddressFilter, struct _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse)
{

}

int  __tds__RemoveIPAddressFilter_(struct soap* soap, struct _tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, struct _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse)
{

}

int  __tds__GetAccessPolicy_(struct soap* soap, struct _tds__GetAccessPolicy *tds__GetAccessPolicy, struct _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse)
{

}

int  __tds__SetAccessPolicy_(struct soap* soap, struct _tds__SetAccessPolicy *tds__SetAccessPolicy, struct _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse)
{

}

int  __tds__CreateCertificate_(struct soap* soap, struct _tds__CreateCertificate *tds__CreateCertificate, struct _tds__CreateCertificateResponse *tds__CreateCertificateResponse)
{

}

int  __tds__GetCertificates_(struct soap* soap, struct _tds__GetCertificates *tds__GetCertificates, struct _tds__GetCertificatesResponse *tds__GetCertificatesResponse)
{

}

int  __tds__GetCertificatesStatus_(struct soap* soap, struct _tds__GetCertificatesStatus *tds__GetCertificatesStatus, struct _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse)
{

}

int  __tds__SetCertificatesStatus_(struct soap* soap, struct _tds__SetCertificatesStatus *tds__SetCertificatesStatus, struct _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse)
{

}

int  __tds__DeleteCertificates_(struct soap* soap, struct _tds__DeleteCertificates *tds__DeleteCertificates, struct _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse)
{

}

int  __tds__GetPkcs10Request_(struct soap* soap, struct _tds__GetPkcs10Request *tds__GetPkcs10Request, struct _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse)
{

}

int  __tds__LoadCertificates_(struct soap* soap, struct _tds__LoadCertificates *tds__LoadCertificates, struct _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse)
{

}

int  __tds__GetClientCertificateMode_(struct soap* soap, struct _tds__GetClientCertificateMode *tds__GetClientCertificateMode, struct _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse)
{

}

int  __tds__SetClientCertificateMode_(struct soap* soap, struct _tds__SetClientCertificateMode *tds__SetClientCertificateMode, struct _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse)
{

}

int  __tds__GetRelayOutputs_(struct soap* soap, struct _tds__GetRelayOutputs *tds__GetRelayOutputs, struct _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse)
{

}

int  __tds__SetRelayOutputSettings_(struct soap* soap, struct _tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, struct _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse)
{

}

int  __tds__SetRelayOutputState_(struct soap* soap, struct _tds__SetRelayOutputState *tds__SetRelayOutputState, struct _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse)
{

}

int  __tds__SendAuxiliaryCommand_(struct soap* soap, struct _tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, struct _tds__SendAuxiliaryCommandResponse *tds__SendAuxiliaryCommandResponse)
{

}

int  __tds__GetCACertificates_(struct soap* soap, struct _tds__GetCACertificates *tds__GetCACertificates, struct _tds__GetCACertificatesResponse *tds__GetCACertificatesResponse)
{

}

int  __tds__LoadCertificateWithPrivateKey_(struct soap* soap, struct _tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, struct _tds__LoadCertificateWithPrivateKeyResponse *tds__LoadCertificateWithPrivateKeyResponse)
{

}

int  __tds__GetCertificateInformation_(struct soap* soap, struct _tds__GetCertificateInformation *tds__GetCertificateInformation, struct _tds__GetCertificateInformationResponse *tds__GetCertificateInformationResponse)
{

}

int  __tds__LoadCACertificates_(struct soap* soap, struct _tds__LoadCACertificates *tds__LoadCACertificates, struct _tds__LoadCACertificatesResponse *tds__LoadCACertificatesResponse)
{

}

int  __tds__CreateDot1XConfiguration_(struct soap* soap, struct _tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, struct _tds__CreateDot1XConfigurationResponse *tds__CreateDot1XConfigurationResponse)
{

}

int  __tds__SetDot1XConfiguration_(struct soap* soap, struct _tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, struct _tds__SetDot1XConfigurationResponse *tds__SetDot1XConfigurationResponse)
{

}

int  __tds__GetDot1XConfiguration_(struct soap* soap, struct _tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, struct _tds__GetDot1XConfigurationResponse *tds__GetDot1XConfigurationResponse)
{

}

int  __tds__GetDot1XConfigurations_(struct soap* soap, struct _tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, struct _tds__GetDot1XConfigurationsResponse *tds__GetDot1XConfigurationsResponse)
{

}

int  __tds__DeleteDot1XConfiguration_(struct soap* soap, struct _tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, struct _tds__DeleteDot1XConfigurationResponse *tds__DeleteDot1XConfigurationResponse)
{

}

int  __tds__GetDot11Capabilities_(struct soap* soap, struct _tds__GetDot11Capabilities *tds__GetDot11Capabilities, struct _tds__GetDot11CapabilitiesResponse *tds__GetDot11CapabilitiesResponse)
{

}

int  __tds__GetDot11Status_(struct soap* soap, struct _tds__GetDot11Status *tds__GetDot11Status, struct _tds__GetDot11StatusResponse *tds__GetDot11StatusResponse)
{

}

int  __tds__ScanAvailableDot11Networks_(struct soap* soap, struct _tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, struct _tds__ScanAvailableDot11NetworksResponse *tds__ScanAvailableDot11NetworksResponse)
{

}

int  __tds__GetSystemUris_(struct soap* soap, struct _tds__GetSystemUris *tds__GetSystemUris, struct _tds__GetSystemUrisResponse *tds__GetSystemUrisResponse)
{

}

int  __tds__StartFirmwareUpgrade_(struct soap* soap, struct _tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, struct _tds__StartFirmwareUpgradeResponse *tds__StartFirmwareUpgradeResponse)
{

}

int  __tds__StartSystemRestore_(struct soap* soap, struct _tds__StartSystemRestore *tds__StartSystemRestore, struct _tds__StartSystemRestoreResponse *tds__StartSystemRestoreResponse)
{

}

int  __timg__GetServiceCapabilities(struct soap* soap, struct _timg__GetServiceCapabilities *timg__GetServiceCapabilities, struct _timg__GetServiceCapabilitiesResponse *timg__GetServiceCapabilitiesResponse)
{

}

int  __timg__GetImagingSettings(struct soap* soap, struct _timg__GetImagingSettings *timg__GetImagingSettings, struct _timg__GetImagingSettingsResponse *timg__GetImagingSettingsResponse)
{

}

int  __timg__SetImagingSettings(struct soap* soap, struct _timg__SetImagingSettings *timg__SetImagingSettings, struct _timg__SetImagingSettingsResponse *timg__SetImagingSettingsResponse)
{

}

int  __timg__GetOptions(struct soap* soap, struct _timg__GetOptions *timg__GetOptions, struct _timg__GetOptionsResponse *timg__GetOptionsResponse)
{

}

int  __timg__Move(struct soap* soap, struct _timg__Move *timg__Move, struct _timg__MoveResponse *timg__MoveResponse)
{

}

int  __timg__Stop(struct soap* soap, struct _timg__Stop *timg__Stop, struct _timg__StopResponse *timg__StopResponse)
{

}

int  __timg__GetStatus(struct soap* soap, struct _timg__GetStatus *timg__GetStatus, struct _timg__GetStatusResponse *timg__GetStatusResponse)
{

}

int  __timg__GetMoveOptions(struct soap* soap, struct _timg__GetMoveOptions *timg__GetMoveOptions, struct _timg__GetMoveOptionsResponse *timg__GetMoveOptionsResponse)
{

}

int  __tls__GetServiceCapabilities(struct soap* soap, struct _tls__GetServiceCapabilities *tls__GetServiceCapabilities, struct _tls__GetServiceCapabilitiesResponse *tls__GetServiceCapabilitiesResponse)
{

}

int  __tls__GetLayout(struct soap* soap, struct _tls__GetLayout *tls__GetLayout, struct _tls__GetLayoutResponse *tls__GetLayoutResponse)
{

}

int  __tls__SetLayout(struct soap* soap, struct _tls__SetLayout *tls__SetLayout, struct _tls__SetLayoutResponse *tls__SetLayoutResponse)
{

}

int  __tls__GetDisplayOptions(struct soap* soap, struct _tls__GetDisplayOptions *tls__GetDisplayOptions, struct _tls__GetDisplayOptionsResponse *tls__GetDisplayOptionsResponse)
{

}

int  __tls__GetPaneConfigurations(struct soap* soap, struct _tls__GetPaneConfigurations *tls__GetPaneConfigurations, struct _tls__GetPaneConfigurationsResponse *tls__GetPaneConfigurationsResponse)
{

}

int  __tls__GetPaneConfiguration(struct soap* soap, struct _tls__GetPaneConfiguration *tls__GetPaneConfiguration, struct _tls__GetPaneConfigurationResponse *tls__GetPaneConfigurationResponse)
{

}

int  __tls__SetPaneConfigurations(struct soap* soap, struct _tls__SetPaneConfigurations *tls__SetPaneConfigurations, struct _tls__SetPaneConfigurationsResponse *tls__SetPaneConfigurationsResponse)
{

}

int  __tls__SetPaneConfiguration(struct soap* soap, struct _tls__SetPaneConfiguration *tls__SetPaneConfiguration, struct _tls__SetPaneConfigurationResponse *tls__SetPaneConfigurationResponse)
{

}

int  __tls__CreatePaneConfiguration(struct soap* soap, struct _tls__CreatePaneConfiguration *tls__CreatePaneConfiguration, struct _tls__CreatePaneConfigurationResponse *tls__CreatePaneConfigurationResponse)
{

}

int  __tls__DeletePaneConfiguration(struct soap* soap, struct _tls__DeletePaneConfiguration *tls__DeletePaneConfiguration, struct _tls__DeletePaneConfigurationResponse *tls__DeletePaneConfigurationResponse)
{

}

int  __tmd__GetServiceCapabilities(struct soap* soap, struct _tmd__GetServiceCapabilities *tmd__GetServiceCapabilities, struct _tmd__GetServiceCapabilitiesResponse *tmd__GetServiceCapabilitiesResponse)
{

}

int  __tmd__GetRelayOutputOptions(struct soap* soap, struct _tmd__GetRelayOutputOptions *tmd__GetRelayOutputOptions, struct _tmd__GetRelayOutputOptionsResponse *tmd__GetRelayOutputOptionsResponse)
{

}

int  __tmd__GetAudioSources(struct soap* soap, struct _trt__GetAudioSources *trt__GetAudioSources, struct _trt__GetAudioSourcesResponse *trt__GetAudioSourcesResponse)
{

}

int  __tmd__GetAudioOutputs(struct soap* soap, struct _trt__GetAudioOutputs *trt__GetAudioOutputs, struct _trt__GetAudioOutputsResponse *trt__GetAudioOutputsResponse)
{

}

int  __tmd__GetVideoSources(struct soap* soap, struct _trt__GetVideoSources *trt__GetVideoSources, struct _trt__GetVideoSourcesResponse *trt__GetVideoSourcesResponse)
{
	DBG("__tmd__GetVideoSources\n");

	int size1;
	size1 = 1;
	trt__GetVideoSourcesResponse->__sizeVideoSources = size1;
	trt__GetVideoSourcesResponse->VideoSources = (struct tt__VideoSource *)soap_malloc(soap, sizeof(struct tt__VideoSource) * size1);
	trt__GetVideoSourcesResponse->VideoSources[0].Framerate = 30;
	trt__GetVideoSourcesResponse->VideoSources[0].Resolution = (struct tt__VideoResolution *)soap_malloc(soap, sizeof(struct tt__VideoResolution));
	trt__GetVideoSourcesResponse->VideoSources[0].Resolution->Height = 720;
	trt__GetVideoSourcesResponse->VideoSources[0].Resolution->Width = 1280;
	trt__GetVideoSourcesResponse->VideoSources[0].token = (char *)soap_malloc(soap, sizeof(char)*INFO_LENGTH);
	strcpy(trt__GetVideoSourcesResponse->VideoSources[0].token,"GhostyuSource_token"); //注意这里需要和GetProfile中的sourcetoken相同

	trt__GetVideoSourcesResponse->VideoSources[0].Imaging =(struct tt__ImagingSettings*)soap_malloc(soap, sizeof(struct tt__ImagingSettings));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Brightness = (float*)soap_malloc(soap,sizeof(float));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Brightness[0] = 128;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->ColorSaturation = (float*)soap_malloc(soap,sizeof(float));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->ColorSaturation[0] = 128;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Contrast = (float*)soap_malloc(soap,sizeof(float));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Contrast[0] = 128;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->IrCutFilter = (int *)soap_malloc(soap,sizeof(int));
	*trt__GetVideoSourcesResponse->VideoSources[0].Imaging->IrCutFilter = 0; 
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Sharpness = (float*)soap_malloc(soap,sizeof(float));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Sharpness[0] = 128;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->BacklightCompensation = (struct tt__BacklightCompensation*)soap_malloc(soap, sizeof(struct tt__BacklightCompensation));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->BacklightCompensation->Mode = 0;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->BacklightCompensation->Level = 20;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Exposure = NULL;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Focus = NULL;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->WideDynamicRange = (struct tt__WideDynamicRange*)soap_malloc(soap, sizeof(struct tt__WideDynamicRange));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->WideDynamicRange->Mode = 0;   
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->WideDynamicRange->Level = 20;
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->WhiteBalance = (struct tt__WhiteBalance*)soap_malloc(soap, sizeof(struct tt__WhiteBalance));
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->WhiteBalance->Mode = 0;	
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->WhiteBalance->CrGain = 0; 
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->WhiteBalance->CbGain = 0; 
	trt__GetVideoSourcesResponse->VideoSources[0].Imaging->Extension = NULL;
	trt__GetVideoSourcesResponse->VideoSources[0].Extension = NULL;	
	return SOAP_OK;
}

int  __tmd__GetVideoOutputs(struct soap* soap, struct _tmd__GetVideoOutputs *tmd__GetVideoOutputs, struct _tmd__GetVideoOutputsResponse *tmd__GetVideoOutputsResponse)
{

}

int  __tmd__GetVideoSourceConfiguration(struct soap* soap, struct _tmd__GetVideoSourceConfiguration *tmd__GetVideoSourceConfiguration, struct _tmd__GetVideoSourceConfigurationResponse *tmd__GetVideoSourceConfigurationResponse)
{
	DBG("__tmd__GetVideoSourceConfiguration\n");
	//return SOAP_OK;
}

int  __tmd__GetVideoOutputConfiguration(struct soap* soap, struct _tmd__GetVideoOutputConfiguration *tmd__GetVideoOutputConfiguration, struct _tmd__GetVideoOutputConfigurationResponse *tmd__GetVideoOutputConfigurationResponse)
{

}

int  __tmd__GetAudioSourceConfiguration(struct soap* soap, struct _tmd__GetAudioSourceConfiguration *tmd__GetAudioSourceConfiguration, struct _tmd__GetAudioSourceConfigurationResponse *tmd__GetAudioSourceConfigurationResponse)
{

}

int  __tmd__GetAudioOutputConfiguration(struct soap* soap, struct _tmd__GetAudioOutputConfiguration *tmd__GetAudioOutputConfiguration, struct _tmd__GetAudioOutputConfigurationResponse *tmd__GetAudioOutputConfigurationResponse)
{

}

int  __tmd__SetVideoSourceConfiguration(struct soap* soap, struct _tmd__SetVideoSourceConfiguration *tmd__SetVideoSourceConfiguration, struct _tmd__SetVideoSourceConfigurationResponse *tmd__SetVideoSourceConfigurationResponse)
{

}

int  __tmd__SetVideoOutputConfiguration(struct soap* soap, struct _tmd__SetVideoOutputConfiguration *tmd__SetVideoOutputConfiguration, struct _tmd__SetVideoOutputConfigurationResponse *tmd__SetVideoOutputConfigurationResponse)
{

}

int  __tmd__SetAudioSourceConfiguration(struct soap* soap, struct _tmd__SetAudioSourceConfiguration *tmd__SetAudioSourceConfiguration, struct _tmd__SetAudioSourceConfigurationResponse *tmd__SetAudioSourceConfigurationResponse)
{

}

int  __tmd__SetAudioOutputConfiguration(struct soap* soap, struct _tmd__SetAudioOutputConfiguration *tmd__SetAudioOutputConfiguration, struct _tmd__SetAudioOutputConfigurationResponse *tmd__SetAudioOutputConfigurationResponse)
{

}

int  __tmd__GetVideoSourceConfigurationOptions(struct soap* soap, struct _tmd__GetVideoSourceConfigurationOptions *tmd__GetVideoSourceConfigurationOptions, struct _tmd__GetVideoSourceConfigurationOptionsResponse *tmd__GetVideoSourceConfigurationOptionsResponse)
{

}

int  __tmd__GetVideoOutputConfigurationOptions(struct soap* soap, struct _tmd__GetVideoOutputConfigurationOptions *tmd__GetVideoOutputConfigurationOptions, struct _tmd__GetVideoOutputConfigurationOptionsResponse *tmd__GetVideoOutputConfigurationOptionsResponse)
{

}

int  __tmd__GetAudioSourceConfigurationOptions(struct soap* soap, struct _tmd__GetAudioSourceConfigurationOptions *tmd__GetAudioSourceConfigurationOptions, struct _tmd__GetAudioSourceConfigurationOptionsResponse *tmd__GetAudioSourceConfigurationOptionsResponse)
{

}

int  __tmd__GetAudioOutputConfigurationOptions(struct soap* soap, struct _tmd__GetAudioOutputConfigurationOptions *tmd__GetAudioOutputConfigurationOptions, struct _tmd__GetAudioOutputConfigurationOptionsResponse *tmd__GetAudioOutputConfigurationOptionsResponse)
{

}

int  __tmd__GetRelayOutputs(struct soap* soap, struct _tds__GetRelayOutputs *tds__GetRelayOutputs, struct _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse)
{

}

int  __tmd__SetRelayOutputSettings(struct soap* soap, struct _tmd__SetRelayOutputSettings *tmd__SetRelayOutputSettings, struct _tmd__SetRelayOutputSettingsResponse *tmd__SetRelayOutputSettingsResponse)
{

}

int  __tmd__SetRelayOutputState(struct soap* soap, struct _tds__SetRelayOutputState *tds__SetRelayOutputState, struct _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse)
{

}

int  __tmd__GetDigitalInputs(struct soap* soap, struct _tmd__GetDigitalInputs *tmd__GetDigitalInputs, struct _tmd__GetDigitalInputsResponse *tmd__GetDigitalInputsResponse)
{

}

int  __tmd__GetSerialPorts(struct soap* soap, struct _tmd__GetSerialPorts *tmd__GetSerialPorts, struct _tmd__GetSerialPortsResponse *tmd__GetSerialPortsResponse)
{

}

int  __tmd__GetSerialPortConfiguration(struct soap* soap, struct _tmd__GetSerialPortConfiguration *tmd__GetSerialPortConfiguration, struct _tmd__GetSerialPortConfigurationResponse *tmd__GetSerialPortConfigurationResponse)
{

}

int  __tmd__SetSerialPortConfiguration(struct soap* soap, struct _tmd__SetSerialPortConfiguration *tmd__SetSerialPortConfiguration, struct _tmd__SetSerialPortConfigurationResponse *tmd__SetSerialPortConfigurationResponse)
{

}

int  __tmd__GetSerialPortConfigurationOptions(struct soap* soap, struct _tmd__GetSerialPortConfigurationOptions *tmd__GetSerialPortConfigurationOptions, struct _tmd__GetSerialPortConfigurationOptionsResponse *tmd__GetSerialPortConfigurationOptionsResponse)
{

}

int  __tmd__SendReceiveSerialCommand(struct soap* soap, struct _tmd__SendReceiveSerialCommand *tmd__SendReceiveSerialCommand, struct _tmd__SendReceiveSerialCommandResponse *tmd__SendReceiveSerialCommandResponse)
{

}

int  __tptz__GetServiceCapabilities(struct soap* soap, struct _tptz__GetServiceCapabilities *tptz__GetServiceCapabilities, struct _tptz__GetServiceCapabilitiesResponse *tptz__GetServiceCapabilitiesResponse)
{

}

int  __tptz__GetConfigurations(struct soap* soap, struct _tptz__GetConfigurations *tptz__GetConfigurations, struct _tptz__GetConfigurationsResponse *tptz__GetConfigurationsResponse)
{

}

int  __tptz__GetPresets(struct soap* soap, struct _tptz__GetPresets *tptz__GetPresets, struct _tptz__GetPresetsResponse *tptz__GetPresetsResponse)
{

}

int  __tptz__SetPreset(struct soap* soap, struct _tptz__SetPreset *tptz__SetPreset, struct _tptz__SetPresetResponse *tptz__SetPresetResponse)
{

}

int  __tptz__RemovePreset(struct soap* soap, struct _tptz__RemovePreset *tptz__RemovePreset, struct _tptz__RemovePresetResponse *tptz__RemovePresetResponse)
{

}

int  __tptz__GotoPreset(struct soap* soap, struct _tptz__GotoPreset *tptz__GotoPreset, struct _tptz__GotoPresetResponse *tptz__GotoPresetResponse)
{

}

int  __tptz__GetStatus(struct soap* soap, struct _tptz__GetStatus *tptz__GetStatus, struct _tptz__GetStatusResponse *tptz__GetStatusResponse)
{

}

int  __tptz__GetConfiguration(struct soap* soap, struct _tptz__GetConfiguration *tptz__GetConfiguration, struct _tptz__GetConfigurationResponse *tptz__GetConfigurationResponse)
{

}

int  __tptz__GetNodes(struct soap* soap, struct _tptz__GetNodes *tptz__GetNodes, struct _tptz__GetNodesResponse *tptz__GetNodesResponse)
{

}

int  __tptz__GetNode(struct soap* soap, struct _tptz__GetNode *tptz__GetNode, struct _tptz__GetNodeResponse *tptz__GetNodeResponse)
{

}

int  __tptz__SetConfiguration(struct soap* soap, struct _tptz__SetConfiguration *tptz__SetConfiguration, struct _tptz__SetConfigurationResponse *tptz__SetConfigurationResponse)
{

}

int  __tptz__GetConfigurationOptions(struct soap* soap, struct _tptz__GetConfigurationOptions *tptz__GetConfigurationOptions, struct _tptz__GetConfigurationOptionsResponse *tptz__GetConfigurationOptionsResponse)
{

}

int  __tptz__GotoHomePosition(struct soap* soap, struct _tptz__GotoHomePosition *tptz__GotoHomePosition, struct _tptz__GotoHomePositionResponse *tptz__GotoHomePositionResponse)
{

}

int  __tptz__SetHomePosition(struct soap* soap, struct _tptz__SetHomePosition *tptz__SetHomePosition, struct _tptz__SetHomePositionResponse *tptz__SetHomePositionResponse)
{

}

int  __tptz__ContinuousMove(struct soap* soap, struct _tptz__ContinuousMove *tptz__ContinuousMove, struct _tptz__ContinuousMoveResponse *tptz__ContinuousMoveResponse)
{

}

int  __tptz__RelativeMove(struct soap* soap, struct _tptz__RelativeMove *tptz__RelativeMove, struct _tptz__RelativeMoveResponse *tptz__RelativeMoveResponse)
{

}

int  __tptz__SendAuxiliaryCommand(struct soap* soap, struct _tptz__SendAuxiliaryCommand *tptz__SendAuxiliaryCommand, struct _tptz__SendAuxiliaryCommandResponse *tptz__SendAuxiliaryCommandResponse)
{

}

int  __tptz__AbsoluteMove(struct soap* soap, struct _tptz__AbsoluteMove *tptz__AbsoluteMove, struct _tptz__AbsoluteMoveResponse *tptz__AbsoluteMoveResponse)
{

}

int  __tptz__Stop(struct soap* soap, struct _tptz__Stop *tptz__Stop, struct _tptz__StopResponse *tptz__StopResponse)
{

}

int  __tptz__GetPresetTours(struct soap* soap, struct _tptz__GetPresetTours *tptz__GetPresetTours, struct _tptz__GetPresetToursResponse *tptz__GetPresetToursResponse)
{

}

int  __tptz__GetPresetTour(struct soap* soap, struct _tptz__GetPresetTour *tptz__GetPresetTour, struct _tptz__GetPresetTourResponse *tptz__GetPresetTourResponse)
{

}

int  __tptz__GetPresetTourOptions(struct soap* soap, struct _tptz__GetPresetTourOptions *tptz__GetPresetTourOptions, struct _tptz__GetPresetTourOptionsResponse *tptz__GetPresetTourOptionsResponse)
{

}

int  __tptz__CreatePresetTour(struct soap* soap, struct _tptz__CreatePresetTour *tptz__CreatePresetTour, struct _tptz__CreatePresetTourResponse *tptz__CreatePresetTourResponse)
{

}

int  __tptz__ModifyPresetTour(struct soap* soap, struct _tptz__ModifyPresetTour *tptz__ModifyPresetTour, struct _tptz__ModifyPresetTourResponse *tptz__ModifyPresetTourResponse)
{

}

int  __tptz__OperatePresetTour(struct soap* soap, struct _tptz__OperatePresetTour *tptz__OperatePresetTour, struct _tptz__OperatePresetTourResponse *tptz__OperatePresetTourResponse)
{

}

int  __tptz__RemovePresetTour(struct soap* soap, struct _tptz__RemovePresetTour *tptz__RemovePresetTour, struct _tptz__RemovePresetTourResponse *tptz__RemovePresetTourResponse)
{

}

int  __trc__GetServiceCapabilities(struct soap* soap, struct _trc__GetServiceCapabilities *trc__GetServiceCapabilities, struct _trc__GetServiceCapabilitiesResponse *trc__GetServiceCapabilitiesResponse)
{

}

int  __trc__CreateRecording(struct soap* soap, struct _trc__CreateRecording *trc__CreateRecording, struct _trc__CreateRecordingResponse *trc__CreateRecordingResponse)
{

}

int  __trc__DeleteRecording(struct soap* soap, struct _trc__DeleteRecording *trc__DeleteRecording, struct _trc__DeleteRecordingResponse *trc__DeleteRecordingResponse)
{

}

int  __trc__GetRecordings(struct soap* soap, struct _trc__GetRecordings *trc__GetRecordings, struct _trc__GetRecordingsResponse *trc__GetRecordingsResponse)
{

}

int  __trc__SetRecordingConfiguration(struct soap* soap, struct _trc__SetRecordingConfiguration *trc__SetRecordingConfiguration, struct _trc__SetRecordingConfigurationResponse *trc__SetRecordingConfigurationResponse)
{

}

int  __trc__GetRecordingConfiguration(struct soap* soap, struct _trc__GetRecordingConfiguration *trc__GetRecordingConfiguration, struct _trc__GetRecordingConfigurationResponse *trc__GetRecordingConfigurationResponse)
{

}

int  __trc__CreateTrack(struct soap* soap, struct _trc__CreateTrack *trc__CreateTrack, struct _trc__CreateTrackResponse *trc__CreateTrackResponse)
{

}

int  __trc__DeleteTrack(struct soap* soap, struct _trc__DeleteTrack *trc__DeleteTrack, struct _trc__DeleteTrackResponse *trc__DeleteTrackResponse)
{

}

int  __trc__GetTrackConfiguration(struct soap* soap, struct _trc__GetTrackConfiguration *trc__GetTrackConfiguration, struct _trc__GetTrackConfigurationResponse *trc__GetTrackConfigurationResponse)
{

}

int  __trc__SetTrackConfiguration(struct soap* soap, struct _trc__SetTrackConfiguration *trc__SetTrackConfiguration, struct _trc__SetTrackConfigurationResponse *trc__SetTrackConfigurationResponse)
{

}

int  __trc__CreateRecordingJob(struct soap* soap, struct _trc__CreateRecordingJob *trc__CreateRecordingJob, struct _trc__CreateRecordingJobResponse *trc__CreateRecordingJobResponse)
{

}

int  __trc__DeleteRecordingJob(struct soap* soap, struct _trc__DeleteRecordingJob *trc__DeleteRecordingJob, struct _trc__DeleteRecordingJobResponse *trc__DeleteRecordingJobResponse)
{

}

int  __trc__GetRecordingJobs(struct soap* soap, struct _trc__GetRecordingJobs *trc__GetRecordingJobs, struct _trc__GetRecordingJobsResponse *trc__GetRecordingJobsResponse)
{

}

int  __trc__SetRecordingJobConfiguration(struct soap* soap, struct _trc__SetRecordingJobConfiguration *trc__SetRecordingJobConfiguration, struct _trc__SetRecordingJobConfigurationResponse *trc__SetRecordingJobConfigurationResponse)
{

}

int  __trc__GetRecordingJobConfiguration(struct soap* soap, struct _trc__GetRecordingJobConfiguration *trc__GetRecordingJobConfiguration, struct _trc__GetRecordingJobConfigurationResponse *trc__GetRecordingJobConfigurationResponse)
{

}

int  __trc__SetRecordingJobMode(struct soap* soap, struct _trc__SetRecordingJobMode *trc__SetRecordingJobMode, struct _trc__SetRecordingJobModeResponse *trc__SetRecordingJobModeResponse)
{

}

int  __trc__GetRecordingJobState(struct soap* soap, struct _trc__GetRecordingJobState *trc__GetRecordingJobState, struct _trc__GetRecordingJobStateResponse *trc__GetRecordingJobStateResponse)
{

}

int  __trp__GetServiceCapabilities(struct soap* soap, struct _trp__GetServiceCapabilities *trp__GetServiceCapabilities, struct _trp__GetServiceCapabilitiesResponse *trp__GetServiceCapabilitiesResponse)
{

}

int  __trp__GetReplayUri(struct soap* soap, struct _trp__GetReplayUri *trp__GetReplayUri, struct _trp__GetReplayUriResponse *trp__GetReplayUriResponse)
{

}

int  __trp__GetReplayConfiguration(struct soap* soap, struct _trp__GetReplayConfiguration *trp__GetReplayConfiguration, struct _trp__GetReplayConfigurationResponse *trp__GetReplayConfigurationResponse)
{

}

int  __trp__SetReplayConfiguration(struct soap* soap, struct _trp__SetReplayConfiguration *trp__SetReplayConfiguration, struct _trp__SetReplayConfigurationResponse *trp__SetReplayConfigurationResponse)
{

}

int  __trt__GetServiceCapabilities(struct soap* soap, struct _trt__GetServiceCapabilities *trt__GetServiceCapabilities, struct _trt__GetServiceCapabilitiesResponse *trt__GetServiceCapabilitiesResponse)
{

}

int  __trt__GetVideoSources(struct soap* soap, struct _trt__GetVideoSources *trt__GetVideoSources, struct _trt__GetVideoSourcesResponse *trt__GetVideoSourcesResponse)
{

}

int  __trt__GetAudioSources(struct soap* soap, struct _trt__GetAudioSources *trt__GetAudioSources, struct _trt__GetAudioSourcesResponse *trt__GetAudioSourcesResponse)
{

}

int  __trt__GetAudioOutputs(struct soap* soap, struct _trt__GetAudioOutputs *trt__GetAudioOutputs, struct _trt__GetAudioOutputsResponse *trt__GetAudioOutputsResponse)
{

}

int  __trt__CreateProfile(struct soap* soap, struct _trt__CreateProfile *trt__CreateProfile, struct _trt__CreateProfileResponse *trt__CreateProfileResponse)
{

}

int  __trt__GetProfile(struct soap* soap, struct _trt__GetProfile *trt__GetProfile, struct _trt__GetProfileResponse *trt__GetProfileResponse)
{
	DBG("__trt__GetProfile\n");
	if(trt__GetProfile){
		DBG("trt__GetProfile=%s\n",trt__GetProfile->ProfileToken );
	}
	/*这里的ProfileToken是选定的，得到特定的profile描述*/
	//但odm单击一个profile时，需要获取，不然不会出现live video和video streaming
	trt__GetProfileResponse->Profile = (struct tt__Profile *)soap_malloc(soap,sizeof(struct tt__Profile));
	trt__GetProfileResponse->Profile->Name = (char *)soap_malloc(soap,sizeof(char)*20);
	trt__GetProfileResponse->Profile->token = (char *)soap_malloc(soap,sizeof(char)*20);
	strcpy(trt__GetProfileResponse->Profile->Name,"my_profile");
	strcpy(trt__GetProfileResponse->Profile->token,"token_profile");
	trt__GetProfileResponse->Profile->fixed = &_false;
	trt__GetProfileResponse->Profile->__anyAttribute = NULL;
	
	trt__GetProfileResponse->Profile->VideoSourceConfiguration = NULL;
	trt__GetProfileResponse->Profile->AudioSourceConfiguration = NULL;
	
	/*VideoEncoderConfiguration*/
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration = (struct tt__VideoEncoderConfiguration *)soap_malloc(soap,sizeof(struct tt__VideoEncoderConfiguration));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Name = (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->token= (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	strcpy(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Name,"VE_Name");
	strcpy(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->token,"VE_token");
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->UseCount = 1;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Quality = 10;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Encoding = 1;//JPEG = 0, MPEG4 = 1, H264 = 2;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Resolution = (struct tt__VideoResolution *)soap_malloc(soap, sizeof(struct tt__VideoResolution));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Resolution->Height = 720;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Resolution->Width = 1280;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl = (struct tt__VideoRateControl *)soap_malloc(soap, sizeof(struct tt__VideoRateControl));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl->FrameRateLimit = 30;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl->EncodingInterval = 1;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl->BitrateLimit = 500;

	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->MPEG4 = NULL;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264 = NULL;
#if 0
	/*可选，可以不设置*/
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->MPEG4 = (struct tt__Mpeg4Configuration *)soap_malloc(soap, sizeof(struct tt__Mpeg4Configuration));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->MPEG4->GovLength = 1;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->MPEG4->Mpeg4Profile = 1;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264 = (struct tt__H264Configuration *)soap_malloc(soap, sizeof(struct tt__H264Configuration));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264->GovLength = 1;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264->H264Profile = 1;
#endif

	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast = (struct tt__MulticastConfiguration *)soap_malloc(soap, sizeof(struct tt__MulticastConfiguration));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->Address = (struct tt__IPAddress *)soap_malloc(soap, sizeof(struct tt__IPAddress));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->Address->IPv4Address = (char **)soap_malloc(soap, sizeof(char *));
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->Address->IPv4Address[0] = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->Address->IPv6Address = NULL;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->Address->Type = 0;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->Port = 554;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->TTL = 60;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->AutoStart = 1;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->__size = 0;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->__any = NULL;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Multicast->__anyAttribute = NULL;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->SessionTimeout = 720000;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->__size = 0;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->__any = NULL;
	trt__GetProfileResponse->Profile->VideoEncoderConfiguration->__anyAttribute = NULL;
	
	trt__GetProfileResponse->Profile->AudioEncoderConfiguration = NULL;
	trt__GetProfileResponse->Profile->VideoAnalyticsConfiguration = NULL;
	trt__GetProfileResponse->Profile->PTZConfiguration = NULL;
	trt__GetProfileResponse->Profile->MetadataConfiguration = NULL;
	trt__GetProfileResponse->Profile->Extension = NULL;

	return SOAP_OK;
}

int  __trt__GetProfiles(struct soap* soap, struct _trt__GetProfiles *trt__GetProfiles, struct _trt__GetProfilesResponse *trt__GetProfilesResponse)
{
	DBG("__trt__GetProfiles\n");
	int i;
	int size;
	char _IPAddr[LARGE_INFO_LENGTH];
	sprintf(_IPAddr, "%3d.%3d.%3d.%3d", ip.str[0], ip.str[1], ip.str[2], ip.str[3]); 

	size = 1;
	trt__GetProfilesResponse->Profiles =(struct tt__Profile *)soap_malloc(soap, sizeof(struct tt__Profile) * size);
	trt__GetProfilesResponse->__sizeProfiles = size;

	i=0;
	trt__GetProfilesResponse->Profiles[i].Name = (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	strcpy(trt__GetProfilesResponse->Profiles[i].Name,"my_profile");
	trt__GetProfilesResponse->Profiles[i].token= (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	strcpy(trt__GetProfilesResponse->Profiles[i].token,"token_profile");
	trt__GetProfilesResponse->Profiles[i].fixed = _false;
	trt__GetProfilesResponse->Profiles[i].__anyAttribute = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoAnalyticsConfiguration = NULL;

	/*必须包含VideoEncoderConfiguration的配置
	不然不会出现live video 和 video streaming*/
	/*VideoEncoderConfiguration*/
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration = NULL;
#if 1
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration = (struct tt__VideoEncoderConfiguration *)soap_malloc(soap,sizeof(struct tt__VideoEncoderConfiguration));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Name = (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->token= (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	strcpy(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Name,"VE_Name1");
	strcpy(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->token,"VE_token1");
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->UseCount = 1;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Quality = 10;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Encoding = 1;//JPEG = 0, MPEG4 = 1, H264 = 2;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Resolution = (struct tt__VideoResolution *)soap_malloc(soap, sizeof(struct tt__VideoResolution));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Resolution->Height = 720;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Resolution->Width = 1280;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl = (struct tt__VideoRateControl *)soap_malloc(soap, sizeof(struct tt__VideoRateControl));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl->FrameRateLimit = 30;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl->EncodingInterval = 1;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl->BitrateLimit = 500;

	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->MPEG4 = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264 = NULL;
#if 1
	/*可选项，可以不配置*/
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->MPEG4 = (struct tt__Mpeg4Configuration *)soap_malloc(soap, sizeof(struct tt__Mpeg4Configuration));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->MPEG4->GovLength = 30;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->MPEG4->Mpeg4Profile = 1;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264 = (struct tt__H264Configuration *)soap_malloc(soap, sizeof(struct tt__H264Configuration));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264->GovLength = 30;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264->H264Profile = 1;
#endif	
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast = (struct tt__MulticastConfiguration *)soap_malloc(soap, sizeof(struct tt__MulticastConfiguration));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->Address = (struct tt__IPAddress *)soap_malloc(soap, sizeof(struct tt__IPAddress));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->Address->IPv4Address = (char **)soap_malloc(soap, sizeof(char *));
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->Address->IPv4Address[0] = (char *)soap_malloc(soap, sizeof(char) * INFO_LENGTH);
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->Address->IPv6Address = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->Address->Type = 0;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->Port = 554;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->TTL = 60;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->AutoStart = 1;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->__size = 0;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->__any = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Multicast->__anyAttribute = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->SessionTimeout = 720000;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->__size = 0;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->__any = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->__anyAttribute = NULL;
#endif
	
	/* VideoSourceConfiguration */
	//trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration = (struct tt__VideoSourceConfiguration *)soap_malloc(soap,sizeof(struct tt__VideoSourceConfiguration ));
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Name = (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->token = (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->SourceToken = (char *)soap_malloc(soap,sizeof(char)*MAX_PROF_TOKEN);
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds = (struct tt__IntRectangle *)soap_malloc(soap,sizeof(struct tt__IntRectangle));
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Extension = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->__any = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->__anyAttribute = NULL;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->__size = 0;
	/*注意SourceToken*/
	strcpy(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Name,"VS_Name");
	strcpy(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->token,"VS_Token");
	strcpy(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->SourceToken,"GhostyuSource_token"); /*必须与__tmd__GetVideoSources中的token相同*/
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->UseCount = 1;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->x = 1;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->y = 1;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->height = 720;
	trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->width = 1280;
	

	trt__GetProfilesResponse->Profiles[i].AudioEncoderConfiguration = NULL;
	trt__GetProfilesResponse->Profiles[i].AudioSourceConfiguration= NULL;
	trt__GetProfilesResponse->Profiles[i].PTZConfiguration = NULL;
	trt__GetProfilesResponse->Profiles[i].MetadataConfiguration = NULL;
	trt__GetProfilesResponse->Profiles[i].Extension = NULL;
	
	return SOAP_OK;
}

int  __trt__AddVideoEncoderConfiguration(struct soap* soap, struct _trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, struct _trt__AddVideoEncoderConfigurationResponse *trt__AddVideoEncoderConfigurationResponse)
{

}

int  __trt__AddVideoSourceConfiguration(struct soap* soap, struct _trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, struct _trt__AddVideoSourceConfigurationResponse *trt__AddVideoSourceConfigurationResponse)
{

}

int  __trt__AddAudioEncoderConfiguration(struct soap* soap, struct _trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, struct _trt__AddAudioEncoderConfigurationResponse *trt__AddAudioEncoderConfigurationResponse)
{

}

int  __trt__AddAudioSourceConfiguration(struct soap* soap, struct _trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, struct _trt__AddAudioSourceConfigurationResponse *trt__AddAudioSourceConfigurationResponse)
{

}

int  __trt__AddPTZConfiguration(struct soap* soap, struct _trt__AddPTZConfiguration *trt__AddPTZConfiguration, struct _trt__AddPTZConfigurationResponse *trt__AddPTZConfigurationResponse)
{

}

int  __trt__AddVideoAnalyticsConfiguration(struct soap* soap, struct _trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, struct _trt__AddVideoAnalyticsConfigurationResponse *trt__AddVideoAnalyticsConfigurationResponse)
{

}

int  __trt__AddMetadataConfiguration(struct soap* soap, struct _trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, struct _trt__AddMetadataConfigurationResponse *trt__AddMetadataConfigurationResponse)
{

}

int  __trt__AddAudioOutputConfiguration(struct soap* soap, struct _trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, struct _trt__AddAudioOutputConfigurationResponse *trt__AddAudioOutputConfigurationResponse)
{

}

int  __trt__AddAudioDecoderConfiguration(struct soap* soap, struct _trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, struct _trt__AddAudioDecoderConfigurationResponse *trt__AddAudioDecoderConfigurationResponse)
{

}

int  __trt__RemoveVideoEncoderConfiguration(struct soap* soap, struct _trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, struct _trt__RemoveVideoEncoderConfigurationResponse *trt__RemoveVideoEncoderConfigurationResponse)
{

}

int  __trt__RemoveVideoSourceConfiguration(struct soap* soap, struct _trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, struct _trt__RemoveVideoSourceConfigurationResponse *trt__RemoveVideoSourceConfigurationResponse)
{

}

int  __trt__RemoveAudioEncoderConfiguration(struct soap* soap, struct _trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, struct _trt__RemoveAudioEncoderConfigurationResponse *trt__RemoveAudioEncoderConfigurationResponse)
{

}

int  __trt__RemoveAudioSourceConfiguration(struct soap* soap, struct _trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, struct _trt__RemoveAudioSourceConfigurationResponse *trt__RemoveAudioSourceConfigurationResponse)
{

}

int  __trt__RemovePTZConfiguration(struct soap* soap, struct _trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, struct _trt__RemovePTZConfigurationResponse *trt__RemovePTZConfigurationResponse)
{

}

int  __trt__RemoveVideoAnalyticsConfiguration(struct soap* soap, struct _trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, struct _trt__RemoveVideoAnalyticsConfigurationResponse *trt__RemoveVideoAnalyticsConfigurationResponse)
{

}

int  __trt__RemoveMetadataConfiguration(struct soap* soap, struct _trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, struct _trt__RemoveMetadataConfigurationResponse *trt__RemoveMetadataConfigurationResponse)
{

}

int  __trt__RemoveAudioOutputConfiguration(struct soap* soap, struct _trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, struct _trt__RemoveAudioOutputConfigurationResponse *trt__RemoveAudioOutputConfigurationResponse)
{

}

int  __trt__RemoveAudioDecoderConfiguration(struct soap* soap, struct _trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, struct _trt__RemoveAudioDecoderConfigurationResponse *trt__RemoveAudioDecoderConfigurationResponse)
{

}

int  __trt__DeleteProfile(struct soap* soap, struct _trt__DeleteProfile *trt__DeleteProfile, struct _trt__DeleteProfileResponse *trt__DeleteProfileResponse)
{

}

int  __trt__GetVideoSourceConfigurations(struct soap* soap, struct _trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, struct _trt__GetVideoSourceConfigurationsResponse *trt__GetVideoSourceConfigurationsResponse)
{
	DBG("__trt__GetVideoSourceConfigurations\n");
	//return SOAP_OK;
}

int  __trt__GetVideoEncoderConfigurations(struct soap* soap, struct _trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, struct _trt__GetVideoEncoderConfigurationsResponse *trt__GetVideoEncoderConfigurationsResponse)
{
	DBG("__trt__GetVideoEncoderConfigurations\n");
	//return SOAP_OK;
	
}

int  __trt__GetAudioSourceConfigurations(struct soap* soap, struct _trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, struct _trt__GetAudioSourceConfigurationsResponse *trt__GetAudioSourceConfigurationsResponse)
{

}

int  __trt__GetAudioEncoderConfigurations(struct soap* soap, struct _trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, struct _trt__GetAudioEncoderConfigurationsResponse *trt__GetAudioEncoderConfigurationsResponse)
{

}

int  __trt__GetVideoAnalyticsConfigurations(struct soap* soap, struct _trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, struct _trt__GetVideoAnalyticsConfigurationsResponse *trt__GetVideoAnalyticsConfigurationsResponse)
{

}

int  __trt__GetMetadataConfigurations(struct soap* soap, struct _trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, struct _trt__GetMetadataConfigurationsResponse *trt__GetMetadataConfigurationsResponse)
{

}

int  __trt__GetAudioOutputConfigurations(struct soap* soap, struct _trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, struct _trt__GetAudioOutputConfigurationsResponse *trt__GetAudioOutputConfigurationsResponse)
{

}

int  __trt__GetAudioDecoderConfigurations(struct soap* soap, struct _trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, struct _trt__GetAudioDecoderConfigurationsResponse *trt__GetAudioDecoderConfigurationsResponse)
{

}

int  __trt__GetVideoSourceConfiguration(struct soap* soap, struct _trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, struct _trt__GetVideoSourceConfigurationResponse *trt__GetVideoSourceConfigurationResponse)
{
	DBG("__trt__GetVideoSourceConfiguration\n");
	//该函数必要，live video需要
	return SOAP_OK;
}

int  __trt__GetVideoEncoderConfiguration(struct soap* soap, struct _trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, struct _trt__GetVideoEncoderConfigurationResponse *trt__GetVideoEncoderConfigurationResponse)
{
	DBG("__trt__GetVideoEncoderConfiguration\n");
	//return SOAP_OK;
}

int  __trt__GetAudioSourceConfiguration(struct soap* soap, struct _trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, struct _trt__GetAudioSourceConfigurationResponse *trt__GetAudioSourceConfigurationResponse)
{

}

int  __trt__GetAudioEncoderConfiguration(struct soap* soap, struct _trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, struct _trt__GetAudioEncoderConfigurationResponse *trt__GetAudioEncoderConfigurationResponse)
{

}

int  __trt__GetVideoAnalyticsConfiguration(struct soap* soap, struct _trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, struct _trt__GetVideoAnalyticsConfigurationResponse *trt__GetVideoAnalyticsConfigurationResponse)
{

}

int  __trt__GetMetadataConfiguration(struct soap* soap, struct _trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, struct _trt__GetMetadataConfigurationResponse *trt__GetMetadataConfigurationResponse)
{

}

int  __trt__GetAudioOutputConfiguration(struct soap* soap, struct _trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, struct _trt__GetAudioOutputConfigurationResponse *trt__GetAudioOutputConfigurationResponse)
{

}

int  __trt__GetAudioDecoderConfiguration(struct soap* soap, struct _trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, struct _trt__GetAudioDecoderConfigurationResponse *trt__GetAudioDecoderConfigurationResponse)
{

}

int  __trt__GetCompatibleVideoEncoderConfigurations(struct soap* soap, struct _trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, struct _trt__GetCompatibleVideoEncoderConfigurationsResponse *trt__GetCompatibleVideoEncoderConfigurationsResponse)
{

}

int  __trt__GetCompatibleVideoSourceConfigurations(struct soap* soap, struct _trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, struct _trt__GetCompatibleVideoSourceConfigurationsResponse *trt__GetCompatibleVideoSourceConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioEncoderConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, struct _trt__GetCompatibleAudioEncoderConfigurationsResponse *trt__GetCompatibleAudioEncoderConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioSourceConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, struct _trt__GetCompatibleAudioSourceConfigurationsResponse *trt__GetCompatibleAudioSourceConfigurationsResponse)
{

}

int  __trt__GetCompatibleVideoAnalyticsConfigurations(struct soap* soap, struct _trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, struct _trt__GetCompatibleVideoAnalyticsConfigurationsResponse *trt__GetCompatibleVideoAnalyticsConfigurationsResponse)
{

}

int  __trt__GetCompatibleMetadataConfigurations(struct soap* soap, struct _trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, struct _trt__GetCompatibleMetadataConfigurationsResponse *trt__GetCompatibleMetadataConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioOutputConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, struct _trt__GetCompatibleAudioOutputConfigurationsResponse *trt__GetCompatibleAudioOutputConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioDecoderConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, struct _trt__GetCompatibleAudioDecoderConfigurationsResponse *trt__GetCompatibleAudioDecoderConfigurationsResponse)
{

}

int  __trt__SetVideoSourceConfiguration(struct soap* soap, struct _trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, struct _trt__SetVideoSourceConfigurationResponse *trt__SetVideoSourceConfigurationResponse)
{

}

int  __trt__SetVideoEncoderConfiguration(struct soap* soap, struct _trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, struct _trt__SetVideoEncoderConfigurationResponse *trt__SetVideoEncoderConfigurationResponse)
{

}

int  __trt__SetAudioSourceConfiguration(struct soap* soap, struct _trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, struct _trt__SetAudioSourceConfigurationResponse *trt__SetAudioSourceConfigurationResponse)
{

}

int  __trt__SetAudioEncoderConfiguration(struct soap* soap, struct _trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, struct _trt__SetAudioEncoderConfigurationResponse *trt__SetAudioEncoderConfigurationResponse)
{

}

int  __trt__SetVideoAnalyticsConfiguration(struct soap* soap, struct _trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, struct _trt__SetVideoAnalyticsConfigurationResponse *trt__SetVideoAnalyticsConfigurationResponse)
{

}

int  __trt__SetMetadataConfiguration(struct soap* soap, struct _trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, struct _trt__SetMetadataConfigurationResponse *trt__SetMetadataConfigurationResponse)
{

}

int  __trt__SetAudioOutputConfiguration(struct soap* soap, struct _trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, struct _trt__SetAudioOutputConfigurationResponse *trt__SetAudioOutputConfigurationResponse)
{

}

int  __trt__SetAudioDecoderConfiguration(struct soap* soap, struct _trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, struct _trt__SetAudioDecoderConfigurationResponse *trt__SetAudioDecoderConfigurationResponse)
{

}

int  __trt__GetVideoSourceConfigurationOptions(struct soap* soap, struct _trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, struct _trt__GetVideoSourceConfigurationOptionsResponse *trt__GetVideoSourceConfigurationOptionsResponse)
{

}

int  __trt__GetVideoEncoderConfigurationOptions(struct soap* soap, struct _trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, struct _trt__GetVideoEncoderConfigurationOptionsResponse *trt__GetVideoEncoderConfigurationOptionsResponse)
{
	DBG("__trt__GetVideoEncoderConfigurationOptions\n");
	//该函数必要，video streaming需要
	return SOAP_OK;
}

int  __trt__GetAudioSourceConfigurationOptions(struct soap* soap, struct _trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, struct _trt__GetAudioSourceConfigurationOptionsResponse *trt__GetAudioSourceConfigurationOptionsResponse)
{

}

int  __trt__GetAudioEncoderConfigurationOptions(struct soap* soap, struct _trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, struct _trt__GetAudioEncoderConfigurationOptionsResponse *trt__GetAudioEncoderConfigurationOptionsResponse)
{

}

int  __trt__GetMetadataConfigurationOptions(struct soap* soap, struct _trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, struct _trt__GetMetadataConfigurationOptionsResponse *trt__GetMetadataConfigurationOptionsResponse)
{

}

int  __trt__GetAudioOutputConfigurationOptions(struct soap* soap, struct _trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, struct _trt__GetAudioOutputConfigurationOptionsResponse *trt__GetAudioOutputConfigurationOptionsResponse)
{

}

int  __trt__GetAudioDecoderConfigurationOptions(struct soap* soap, struct _trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, struct _trt__GetAudioDecoderConfigurationOptionsResponse *trt__GetAudioDecoderConfigurationOptionsResponse)
{

}

int  __trt__GetGuaranteedNumberOfVideoEncoderInstances(struct soap* soap, struct _trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, struct _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse *trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse)
{

}

int  __trt__GetStreamUri(struct soap* soap, struct _trt__GetStreamUri *trt__GetStreamUri, struct _trt__GetStreamUriResponse *trt__GetStreamUriResponse)
{
	DBG("__trt__GetStreamUri\n");
	char _IPAddr[INFO_LENGTH];
	sprintf(_IPAddr, "rtsp://192.168.1.201/petrov.m4e");
	/* Response */
	trt__GetStreamUriResponse->MediaUri = (struct tt__MediaUri *)soap_malloc(soap, sizeof(struct tt__MediaUri));
	trt__GetStreamUriResponse->MediaUri->Uri = (char *)soap_malloc(soap, sizeof(char) * LARGE_INFO_LENGTH);
    strcpy(trt__GetStreamUriResponse->MediaUri->Uri,_IPAddr);
	trt__GetStreamUriResponse->MediaUri->InvalidAfterConnect = 0;
	trt__GetStreamUriResponse->MediaUri->InvalidAfterReboot = 0;
	trt__GetStreamUriResponse->MediaUri->Timeout = 200;
	return SOAP_OK; 
}

int  __trt__StartMulticastStreaming(struct soap* soap, struct _trt__StartMulticastStreaming *trt__StartMulticastStreaming, struct _trt__StartMulticastStreamingResponse *trt__StartMulticastStreamingResponse)
{

}

int  __trt__StopMulticastStreaming(struct soap* soap, struct _trt__StopMulticastStreaming *trt__StopMulticastStreaming, struct _trt__StopMulticastStreamingResponse *trt__StopMulticastStreamingResponse)
{

}

int  __trt__SetSynchronizationPoint(struct soap* soap, struct _trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, struct _trt__SetSynchronizationPointResponse *trt__SetSynchronizationPointResponse)
{

}

int  __trt__GetSnapshotUri(struct soap* soap, struct _trt__GetSnapshotUri *trt__GetSnapshotUri, struct _trt__GetSnapshotUriResponse *trt__GetSnapshotUriResponse)
{
	DBG("__trt__GetSnapshotUri\n");
	trt__GetSnapshotUriResponse->MediaUri = (struct tt__MediaUri *)soap_malloc(soap,sizeof(struct tt__MediaUri));
	trt__GetSnapshotUriResponse->MediaUri->Uri = (char *)soap_malloc(soap,sizeof(char)*200);
	strcpy(trt__GetSnapshotUriResponse->MediaUri->Uri,"http://avatar.csdn.net/7/E/1/1_ghostyu.jpg");
	trt__GetSnapshotUriResponse->MediaUri->InvalidAfterConnect = 0;
	trt__GetSnapshotUriResponse->MediaUri->InvalidAfterReboot = 0;
	trt__GetSnapshotUriResponse->MediaUri->Timeout = 2;	//seconds
	trt__GetSnapshotUriResponse->MediaUri->__size = 0;
	trt__GetSnapshotUriResponse->MediaUri->__any = NULL;
	trt__GetSnapshotUriResponse->MediaUri->__anyAttribute = NULL;
	return SOAP_OK;
}

int  __trt__GetServiceCapabilities_(struct soap* soap, struct _trt__GetServiceCapabilities *trt__GetServiceCapabilities, struct _trt__GetServiceCapabilitiesResponse *trt__GetServiceCapabilitiesResponse)
{

}

int  __trt__GetVideoSources_(struct soap* soap, struct _trt__GetVideoSources *trt__GetVideoSources, struct _trt__GetVideoSourcesResponse *trt__GetVideoSourcesResponse)
{

}

int  __trt__GetAudioSources_(struct soap* soap, struct _trt__GetAudioSources *trt__GetAudioSources, struct _trt__GetAudioSourcesResponse *trt__GetAudioSourcesResponse)
{

}

int  __trt__GetAudioOutputs_(struct soap* soap, struct _trt__GetAudioOutputs *trt__GetAudioOutputs, struct _trt__GetAudioOutputsResponse *trt__GetAudioOutputsResponse)
{

}

int  __trt__CreateProfile_(struct soap* soap, struct _trt__CreateProfile *trt__CreateProfile, struct _trt__CreateProfileResponse *trt__CreateProfileResponse)
{

}

int  __trt__GetProfile_(struct soap* soap, struct _trt__GetProfile *trt__GetProfile, struct _trt__GetProfileResponse *trt__GetProfileResponse)
{

}

int  __trt__GetProfiles_(struct soap* soap, struct _trt__GetProfiles *trt__GetProfiles, struct _trt__GetProfilesResponse *trt__GetProfilesResponse)
{

}

int  __trt__AddVideoEncoderConfiguration_(struct soap* soap, struct _trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, struct _trt__AddVideoEncoderConfigurationResponse *trt__AddVideoEncoderConfigurationResponse)
{

}

int  __trt__AddVideoSourceConfiguration_(struct soap* soap, struct _trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, struct _trt__AddVideoSourceConfigurationResponse *trt__AddVideoSourceConfigurationResponse)
{

}

int  __trt__AddAudioEncoderConfiguration_(struct soap* soap, struct _trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, struct _trt__AddAudioEncoderConfigurationResponse *trt__AddAudioEncoderConfigurationResponse)
{

}

int  __trt__AddAudioSourceConfiguration_(struct soap* soap, struct _trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, struct _trt__AddAudioSourceConfigurationResponse *trt__AddAudioSourceConfigurationResponse)
{

}

int  __trt__AddPTZConfiguration_(struct soap* soap, struct _trt__AddPTZConfiguration *trt__AddPTZConfiguration, struct _trt__AddPTZConfigurationResponse *trt__AddPTZConfigurationResponse)
{

}

int  __trt__AddVideoAnalyticsConfiguration_(struct soap* soap, struct _trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, struct _trt__AddVideoAnalyticsConfigurationResponse *trt__AddVideoAnalyticsConfigurationResponse)
{

}

int  __trt__AddMetadataConfiguration_(struct soap* soap, struct _trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, struct _trt__AddMetadataConfigurationResponse *trt__AddMetadataConfigurationResponse)
{

}

int  __trt__AddAudioOutputConfiguration_(struct soap* soap, struct _trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, struct _trt__AddAudioOutputConfigurationResponse *trt__AddAudioOutputConfigurationResponse)
{

}

int  __trt__AddAudioDecoderConfiguration_(struct soap* soap, struct _trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, struct _trt__AddAudioDecoderConfigurationResponse *trt__AddAudioDecoderConfigurationResponse)
{

}

int  __trt__RemoveVideoEncoderConfiguration_(struct soap* soap, struct _trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, struct _trt__RemoveVideoEncoderConfigurationResponse *trt__RemoveVideoEncoderConfigurationResponse)
{

}

int  __trt__RemoveVideoSourceConfiguration_(struct soap* soap, struct _trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, struct _trt__RemoveVideoSourceConfigurationResponse *trt__RemoveVideoSourceConfigurationResponse)
{

}

int  __trt__RemoveAudioEncoderConfiguration_(struct soap* soap, struct _trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, struct _trt__RemoveAudioEncoderConfigurationResponse *trt__RemoveAudioEncoderConfigurationResponse)
{

}

int  __trt__RemoveAudioSourceConfiguration_(struct soap* soap, struct _trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, struct _trt__RemoveAudioSourceConfigurationResponse *trt__RemoveAudioSourceConfigurationResponse)
{

}

int  __trt__RemovePTZConfiguration_(struct soap* soap, struct _trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, struct _trt__RemovePTZConfigurationResponse *trt__RemovePTZConfigurationResponse)
{

}

int  __trt__RemoveVideoAnalyticsConfiguration_(struct soap* soap, struct _trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, struct _trt__RemoveVideoAnalyticsConfigurationResponse *trt__RemoveVideoAnalyticsConfigurationResponse)
{

}

int  __trt__RemoveMetadataConfiguration_(struct soap* soap, struct _trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, struct _trt__RemoveMetadataConfigurationResponse *trt__RemoveMetadataConfigurationResponse)
{

}

int  __trt__RemoveAudioOutputConfiguration_(struct soap* soap, struct _trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, struct _trt__RemoveAudioOutputConfigurationResponse *trt__RemoveAudioOutputConfigurationResponse)
{

}

int  __trt__RemoveAudioDecoderConfiguration_(struct soap* soap, struct _trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, struct _trt__RemoveAudioDecoderConfigurationResponse *trt__RemoveAudioDecoderConfigurationResponse)
{

}

int  __trt__DeleteProfile_(struct soap* soap, struct _trt__DeleteProfile *trt__DeleteProfile, struct _trt__DeleteProfileResponse *trt__DeleteProfileResponse)
{

}

int  __trt__GetVideoSourceConfigurations_(struct soap* soap, struct _trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, struct _trt__GetVideoSourceConfigurationsResponse *trt__GetVideoSourceConfigurationsResponse)
{

}

int  __trt__GetVideoEncoderConfigurations_(struct soap* soap, struct _trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, struct _trt__GetVideoEncoderConfigurationsResponse *trt__GetVideoEncoderConfigurationsResponse)
{

}

int  __trt__GetAudioSourceConfigurations_(struct soap* soap, struct _trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, struct _trt__GetAudioSourceConfigurationsResponse *trt__GetAudioSourceConfigurationsResponse)
{

}

int  __trt__GetAudioEncoderConfigurations_(struct soap* soap, struct _trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, struct _trt__GetAudioEncoderConfigurationsResponse *trt__GetAudioEncoderConfigurationsResponse)
{

}

int  __trt__GetVideoAnalyticsConfigurations_(struct soap* soap, struct _trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, struct _trt__GetVideoAnalyticsConfigurationsResponse *trt__GetVideoAnalyticsConfigurationsResponse)
{

}

int  __trt__GetMetadataConfigurations_(struct soap* soap, struct _trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, struct _trt__GetMetadataConfigurationsResponse *trt__GetMetadataConfigurationsResponse)
{

}

int  __trt__GetAudioOutputConfigurations_(struct soap* soap, struct _trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, struct _trt__GetAudioOutputConfigurationsResponse *trt__GetAudioOutputConfigurationsResponse)
{

}

int  __trt__GetAudioDecoderConfigurations_(struct soap* soap, struct _trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, struct _trt__GetAudioDecoderConfigurationsResponse *trt__GetAudioDecoderConfigurationsResponse)
{

}

int  __trt__GetVideoSourceConfiguration_(struct soap* soap, struct _trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, struct _trt__GetVideoSourceConfigurationResponse *trt__GetVideoSourceConfigurationResponse)
{

}

int  __trt__GetVideoEncoderConfiguration_(struct soap* soap, struct _trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, struct _trt__GetVideoEncoderConfigurationResponse *trt__GetVideoEncoderConfigurationResponse)
{

}

int  __trt__GetAudioSourceConfiguration_(struct soap* soap, struct _trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, struct _trt__GetAudioSourceConfigurationResponse *trt__GetAudioSourceConfigurationResponse)
{

}

int  __trt__GetAudioEncoderConfiguration_(struct soap* soap, struct _trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, struct _trt__GetAudioEncoderConfigurationResponse *trt__GetAudioEncoderConfigurationResponse)
{

}

int  __trt__GetVideoAnalyticsConfiguration_(struct soap* soap, struct _trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, struct _trt__GetVideoAnalyticsConfigurationResponse *trt__GetVideoAnalyticsConfigurationResponse)
{

}

int  __trt__GetMetadataConfiguration_(struct soap* soap, struct _trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, struct _trt__GetMetadataConfigurationResponse *trt__GetMetadataConfigurationResponse)
{

}

int  __trt__GetAudioOutputConfiguration_(struct soap* soap, struct _trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, struct _trt__GetAudioOutputConfigurationResponse *trt__GetAudioOutputConfigurationResponse)
{

}

int  __trt__GetAudioDecoderConfiguration_(struct soap* soap, struct _trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, struct _trt__GetAudioDecoderConfigurationResponse *trt__GetAudioDecoderConfigurationResponse)
{

}

int  __trt__GetCompatibleVideoEncoderConfigurations_(struct soap* soap, struct _trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, struct _trt__GetCompatibleVideoEncoderConfigurationsResponse *trt__GetCompatibleVideoEncoderConfigurationsResponse)
{

}

int  __trt__GetCompatibleVideoSourceConfigurations_(struct soap* soap, struct _trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, struct _trt__GetCompatibleVideoSourceConfigurationsResponse *trt__GetCompatibleVideoSourceConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioEncoderConfigurations_(struct soap* soap, struct _trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, struct _trt__GetCompatibleAudioEncoderConfigurationsResponse *trt__GetCompatibleAudioEncoderConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioSourceConfigurations_(struct soap* soap, struct _trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, struct _trt__GetCompatibleAudioSourceConfigurationsResponse *trt__GetCompatibleAudioSourceConfigurationsResponse)
{

}

int  __trt__GetCompatibleVideoAnalyticsConfigurations_(struct soap* soap, struct _trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, struct _trt__GetCompatibleVideoAnalyticsConfigurationsResponse *trt__GetCompatibleVideoAnalyticsConfigurationsResponse)
{

}

int  __trt__GetCompatibleMetadataConfigurations_(struct soap* soap, struct _trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, struct _trt__GetCompatibleMetadataConfigurationsResponse *trt__GetCompatibleMetadataConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioOutputConfigurations_(struct soap* soap, struct _trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, struct _trt__GetCompatibleAudioOutputConfigurationsResponse *trt__GetCompatibleAudioOutputConfigurationsResponse)
{

}

int  __trt__GetCompatibleAudioDecoderConfigurations_(struct soap* soap, struct _trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, struct _trt__GetCompatibleAudioDecoderConfigurationsResponse *trt__GetCompatibleAudioDecoderConfigurationsResponse)
{

}

int  __trt__SetVideoSourceConfiguration_(struct soap* soap, struct _trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, struct _trt__SetVideoSourceConfigurationResponse *trt__SetVideoSourceConfigurationResponse)
{

}

int  __trt__SetVideoEncoderConfiguration_(struct soap* soap, struct _trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, struct _trt__SetVideoEncoderConfigurationResponse *trt__SetVideoEncoderConfigurationResponse)
{

}

int  __trt__SetAudioSourceConfiguration_(struct soap* soap, struct _trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, struct _trt__SetAudioSourceConfigurationResponse *trt__SetAudioSourceConfigurationResponse)
{

}

int  __trt__SetAudioEncoderConfiguration_(struct soap* soap, struct _trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, struct _trt__SetAudioEncoderConfigurationResponse *trt__SetAudioEncoderConfigurationResponse)
{

}

int  __trt__SetVideoAnalyticsConfiguration_(struct soap* soap, struct _trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, struct _trt__SetVideoAnalyticsConfigurationResponse *trt__SetVideoAnalyticsConfigurationResponse)
{

}

int  __trt__SetMetadataConfiguration_(struct soap* soap, struct _trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, struct _trt__SetMetadataConfigurationResponse *trt__SetMetadataConfigurationResponse)
{

}

int  __trt__SetAudioOutputConfiguration_(struct soap* soap, struct _trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, struct _trt__SetAudioOutputConfigurationResponse *trt__SetAudioOutputConfigurationResponse)
{

}

int  __trt__SetAudioDecoderConfiguration_(struct soap* soap, struct _trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, struct _trt__SetAudioDecoderConfigurationResponse *trt__SetAudioDecoderConfigurationResponse)
{

}

int  __trt__GetVideoSourceConfigurationOptions_(struct soap* soap, struct _trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, struct _trt__GetVideoSourceConfigurationOptionsResponse *trt__GetVideoSourceConfigurationOptionsResponse)
{

}

int  __trt__GetVideoEncoderConfigurationOptions_(struct soap* soap, struct _trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, struct _trt__GetVideoEncoderConfigurationOptionsResponse *trt__GetVideoEncoderConfigurationOptionsResponse)
{

}

int  __trt__GetAudioSourceConfigurationOptions_(struct soap* soap, struct _trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, struct _trt__GetAudioSourceConfigurationOptionsResponse *trt__GetAudioSourceConfigurationOptionsResponse)
{

}

int  __trt__GetAudioEncoderConfigurationOptions_(struct soap* soap, struct _trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, struct _trt__GetAudioEncoderConfigurationOptionsResponse *trt__GetAudioEncoderConfigurationOptionsResponse)
{

}

int  __trt__GetMetadataConfigurationOptions_(struct soap* soap, struct _trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, struct _trt__GetMetadataConfigurationOptionsResponse *trt__GetMetadataConfigurationOptionsResponse)
{

}

int  __trt__GetAudioOutputConfigurationOptions_(struct soap* soap, struct _trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, struct _trt__GetAudioOutputConfigurationOptionsResponse *trt__GetAudioOutputConfigurationOptionsResponse)
{

}

int  __trt__GetAudioDecoderConfigurationOptions_(struct soap* soap, struct _trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, struct _trt__GetAudioDecoderConfigurationOptionsResponse *trt__GetAudioDecoderConfigurationOptionsResponse)
{

}

int  __trt__GetGuaranteedNumberOfVideoEncoderInstances_(struct soap* soap, struct _trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, struct _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse *trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse)
{

}

int  __trt__GetStreamUri_(struct soap* soap, struct _trt__GetStreamUri *trt__GetStreamUri, struct _trt__GetStreamUriResponse *trt__GetStreamUriResponse)
{

}

int  __trt__StartMulticastStreaming_(struct soap* soap, struct _trt__StartMulticastStreaming *trt__StartMulticastStreaming, struct _trt__StartMulticastStreamingResponse *trt__StartMulticastStreamingResponse)
{

}

int  __trt__StopMulticastStreaming_(struct soap* soap, struct _trt__StopMulticastStreaming *trt__StopMulticastStreaming, struct _trt__StopMulticastStreamingResponse *trt__StopMulticastStreamingResponse)
{

}

int  __trt__SetSynchronizationPoint_(struct soap* soap, struct _trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, struct _trt__SetSynchronizationPointResponse *trt__SetSynchronizationPointResponse)
{

}

int  __trt__GetSnapshotUri_(struct soap* soap, struct _trt__GetSnapshotUri *trt__GetSnapshotUri, struct _trt__GetSnapshotUriResponse *trt__GetSnapshotUriResponse)
{

}

int  __trv__GetServiceCapabilities(struct soap* soap, struct _trv__GetServiceCapabilities *trv__GetServiceCapabilities, struct _trv__GetServiceCapabilitiesResponse *trv__GetServiceCapabilitiesResponse)
{

}

int  __trv__GetReceivers(struct soap* soap, struct _trv__GetReceivers *trv__GetReceivers, struct _trv__GetReceiversResponse *trv__GetReceiversResponse)
{

}

int  __trv__GetReceiver(struct soap* soap, struct _trv__GetReceiver *trv__GetReceiver, struct _trv__GetReceiverResponse *trv__GetReceiverResponse)
{

}

int  __trv__CreateReceiver(struct soap* soap, struct _trv__CreateReceiver *trv__CreateReceiver, struct _trv__CreateReceiverResponse *trv__CreateReceiverResponse)
{

}

int  __trv__DeleteReceiver(struct soap* soap, struct _trv__DeleteReceiver *trv__DeleteReceiver, struct _trv__DeleteReceiverResponse *trv__DeleteReceiverResponse)
{

}

int  __trv__ConfigureReceiver(struct soap* soap, struct _trv__ConfigureReceiver *trv__ConfigureReceiver, struct _trv__ConfigureReceiverResponse *trv__ConfigureReceiverResponse)
{

}

int  __trv__SetReceiverMode(struct soap* soap, struct _trv__SetReceiverMode *trv__SetReceiverMode, struct _trv__SetReceiverModeResponse *trv__SetReceiverModeResponse)
{

}

int  __trv__GetReceiverState(struct soap* soap, struct _trv__GetReceiverState *trv__GetReceiverState, struct _trv__GetReceiverStateResponse *trv__GetReceiverStateResponse)
{

}

int  __tse__GetServiceCapabilities(struct soap* soap, struct _tse__GetServiceCapabilities *tse__GetServiceCapabilities, struct _tse__GetServiceCapabilitiesResponse *tse__GetServiceCapabilitiesResponse)
{

}

int  __tse__GetRecordingSummary(struct soap* soap, struct _tse__GetRecordingSummary *tse__GetRecordingSummary, struct _tse__GetRecordingSummaryResponse *tse__GetRecordingSummaryResponse)
{

}

int  __tse__GetRecordingInformation(struct soap* soap, struct _tse__GetRecordingInformation *tse__GetRecordingInformation, struct _tse__GetRecordingInformationResponse *tse__GetRecordingInformationResponse)
{

}

int  __tse__GetMediaAttributes(struct soap* soap, struct _tse__GetMediaAttributes *tse__GetMediaAttributes, struct _tse__GetMediaAttributesResponse *tse__GetMediaAttributesResponse)
{

}

int  __tse__FindRecordings(struct soap* soap, struct _tse__FindRecordings *tse__FindRecordings, struct _tse__FindRecordingsResponse *tse__FindRecordingsResponse)
{

}

int  __tse__GetRecordingSearchResults(struct soap* soap, struct _tse__GetRecordingSearchResults *tse__GetRecordingSearchResults, struct _tse__GetRecordingSearchResultsResponse *tse__GetRecordingSearchResultsResponse)
{

}

int  __tse__FindEvents(struct soap* soap, struct _tse__FindEvents *tse__FindEvents, struct _tse__FindEventsResponse *tse__FindEventsResponse)
{

}

int  __tse__GetEventSearchResults(struct soap* soap, struct _tse__GetEventSearchResults *tse__GetEventSearchResults, struct _tse__GetEventSearchResultsResponse *tse__GetEventSearchResultsResponse)
{

}

int  __tse__FindPTZPosition(struct soap* soap, struct _tse__FindPTZPosition *tse__FindPTZPosition, struct _tse__FindPTZPositionResponse *tse__FindPTZPositionResponse)
{

}

int  __tse__GetPTZPositionSearchResults(struct soap* soap, struct _tse__GetPTZPositionSearchResults *tse__GetPTZPositionSearchResults, struct _tse__GetPTZPositionSearchResultsResponse *tse__GetPTZPositionSearchResultsResponse)
{

}

int  __tse__GetSearchState(struct soap* soap, struct _tse__GetSearchState *tse__GetSearchState, struct _tse__GetSearchStateResponse *tse__GetSearchStateResponse)
{

}

int  __tse__EndSearch(struct soap* soap, struct _tse__EndSearch *tse__EndSearch, struct _tse__EndSearchResponse *tse__EndSearchResponse)
{

}

int  __tse__FindMetadata(struct soap* soap, struct _tse__FindMetadata *tse__FindMetadata, struct _tse__FindMetadataResponse *tse__FindMetadataResponse)
{

}

int  __tse__GetMetadataSearchResults(struct soap* soap, struct _tse__GetMetadataSearchResults *tse__GetMetadataSearchResults, struct _tse__GetMetadataSearchResultsResponse *tse__GetMetadataSearchResultsResponse)
{

}

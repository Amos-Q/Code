#define _CRT_SECURE_NO_WARNINGS 1
#include "hospital.h"

void OpInit(void)
{
	int i;
	/*��OJ����δ�������� error C2059: �﷨����:��{�� ����
	������VS2015��ͨ���ˣ������䷨������
	��ʵ�˴����������Ŀ��Ҫ��Ҳ�Ƕ����==
	gPatientIniCfg[0] = { "pat01", 0, 100, 0};
	gPatientIniCfg[1] = { "pat02", 1, 100, 100};
	gPatientIniCfg[2] = { "pat03", 0, 100, 0};
	gPatientIniCfg[3] = { "pat04", 1, 100, 50};
	gPatientIniCfg[4] = { "pat05", 1, 10 , 10};
	gPatientIniCfg[5] = { "pat06", 1, 20 , 10};
	*/
	for (i = 0; i < MAX_PATIENT_RECORD; i++) {
		Status[i] = PS_IDLE;
	}
	Queue.queueNum = 0;
	for (i = 0; i < MAX_DOCTOR_CAPABILITY; i++) {
		Queue.pPatientIdInfo[i] = NULL;
	}
	api_print_operation_result(E000_INITITIAL_SUCC);
	return;
};


void OpRegister(const char *pPatientId)
{
	int id = 0, i = 0;
	sscanf(pPatientId, "pat0%d", &id);
	id--;
	if (Status[id] != PS_IDLE) {
		api_print_operation_result(E002_DIAGNOSE_NOT_END);
		return;
	}
	if (Queue.queueNum == MAX_DOCTOR_CAPABILITY) {
		api_print_operation_result(E003_QUEUE_EXCEED_OF_PER_DOCTOR);
		return;
	}
	if (gPatientIniCfg[id].patientLevel == PM_INSURE) {
		if (gPatientIniCfg[id].insureBalance >= REG_FEE) {
			gPatientIniCfg[id].insureBalance -= REG_FEE;
		}
		else if (gPatientIniCfg[i].creditBalance >= REG_FEE) {
			gPatientIniCfg[i].creditBalance -= REG_FEE;
		}
		else {
			api_print_operation_result(E004_LACK_FEE_FOR_REGISTER);
			return;
		}
	}
	else {
		if (gPatientIniCfg[id].creditBalance >= REG_FEE) {
			gPatientIniCfg[id].creditBalance -= REG_FEE;
		}
		else {
			api_print_operation_result(E004_LACK_FEE_FOR_REGISTER);
			return;
		}
	}
	Queue.pPatientIdInfo[Queue.queueNum] = gPatientIniCfg[id].patientId;
	Queue.queueNum++;
	Status[id] = PS_IN_QUEUE;
	api_print_register_succ();
	return;
}

void OpDiag(void)
{
	int id = 0, i = 0;
	if (Queue.queueNum == 0) {
		api_print_operation_result(E006_NO_PATIENT_IN_QUEUE);
		return;
	}
	sscanf(Queue.pPatientIdInfo[0], "pat0%d", &id);
	id--;
	Status[id] = PS_WAIT_PAY;
	Queue.queueNum--;
	for (i = 0; i < Queue.queueNum; i++) {
		Queue.pPatientIdInfo[i] = Queue.pPatientIdInfo[i + 1];
	}
	Queue.pPatientIdInfo[Queue.queueNum] = NULL;
	api_print_operation_result(E005_DIAGNOSE_SUCC);
	return;
}

void OpPay(const char *pPatientId)
{
	int id;
	sscanf(pPatientId, "pat0%d", &id);
	id--;
	if (Status[id] != PS_WAIT_PAY) {
		api_print_operation_result(E014_PATIENT_NOT_BE_PAY_STATUS);
		return;
	}
	Status[id] = PS_IDLE;
	if (gPatientIniCfg[id].patientLevel == PM_INSURE) {
		if (gPatientIniCfg[id].insureBalance >= DIAG_FEE) {
			gPatientIniCfg[id].insureBalance -= DIAG_FEE;
		}
		else if (gPatientIniCfg[id].creditBalance >= DIAG_FEE) {
			gPatientIniCfg[id].creditBalance -= DIAG_FEE;
		}
		else {
			api_print_operation_result(E008_BALANCE_NOT_ENOUGH);
			return;
		}
	}
	else {
		if (gPatientIniCfg[id].creditBalance >= DIAG_FEE) {
			gPatientIniCfg[id].creditBalance -= DIAG_FEE;
		}
		else {
			api_print_operation_result(E008_BALANCE_NOT_ENOUGH);
			return;
		}
	}
	api_print_operation_result(E007_PAY_SUCC);
	return;
}

void OpQuery(QueryType queryType, const char *pQueryId)
{
	int id = 0, i = 0;
	if (queryType == Q_DOCTOR) {
		api_print_doctor_query_info(&Queue);
	}
	else {
		sscanf(pQueryId, "pat0%d", &id);
		id--;
		for (i = 0; i < Queue.queueNum; i++) {
			if (strcmp(Queue.pPatientIdInfo[i], pQueryId) == 0) {
				api_print_patient_query_info(pQueryId, Status[id], i + 1,
					gPatientIniCfg[id].insureBalance, gPatientIniCfg[id].creditBalance);
				break;
			}
		}
		if (i == Queue.queueNum) {
			api_print_patient_query_info(pQueryId, Status[id], 0,
				gPatientIniCfg[id].insureBalance, gPatientIniCfg[id].creditBalance);
		}
	}
	return;
}

void libOutputStr(char* pcStr);

void cmd_process(int argc, char* argv[]);


//ִ�������
void cmd_dispatch(char *pszCmd)
{
	char    Buff1[32];
	char    Buff2[32];
	char    Buff3[32];
	int     tmpParaA;
	int             GetParaCount;
	const char      *p = NULL;
	const char      *p1 = NULL;
	if (NULL == pszCmd)
	{
		return;
	}
	p = pszCmd;
	memset(Buff1, 0, sizeof(Buff1));
	memset(Buff2, 0, sizeof(Buff2));
	memset(Buff3, 0, sizeof(Buff3));
	//��Ϊi��ִ�г�ʼ������
	if (p == strstr(p, "i"))
	{
		OpInit();
		return;
	}
	//��Ϊ�Һţ���Buff1�洢�ҺŵĲ��˵�ID����ִ�йҺź���
	else if (p == strstr(p, "reg_"))
	{
		GetParaCount = sscanf(p, "reg_%s", Buff1);
		if (1 == GetParaCount)
		{
			OpRegister(Buff1);
			return;
		}
	}
	//��Ϊ���Σ���ִ�����κ���
	else if (p == strstr(p, "diag"))
	{
		OpDiag();
		return;
	}
	//��Ϊ�ɷ����ò���Buff1���нɷѡ�
	else if (p == strstr(p, "pay"))
	{
		GetParaCount = sscanf(p, "pay_%s", Buff1);
		if (1 == GetParaCount)
		{
			OpPay(Buff1);
			return;
		}
	}
	else if (p == strstr(p, "qu"))
	{
		GetParaCount = sscanf(p, "qu_%d-%s", &tmpParaA, Buff1);
		//��Ϊ��ѯ������ִ�в�ѯ����tmpParaAΪ0��buffer1==dct�Ǳ�ʾ��ʾ��ѯҽ����ǰ�Ĳ����Ŷ����
		//��tmpParaAΪ1��buffer1==patID���ʾ��ѯIDΪpat01�Ĳ�����Ϣ��
		if (2 == GetParaCount)
		{
			OpQuery((QueryType)tmpParaA, Buff1);
			return;
		}
	}
	libOutputStr("��Ч����");
	return;
}
void user_cmdproc(char *pszCmd, int iLen)
{
	if (NULL == pszCmd)
	{
		return;
	}
	cmd_dispatch(pszCmd);
	return;
}
void api_print_operation_result(OpRet opRet)
{
	switch (opRet)
	{
	case E000_INITITIAL_SUCC:
		libOutputStr("E000"); //:��ʼ���ɹ�
		break;
	case E002_DIAGNOSE_NOT_END:
		libOutputStr("E002"); //:���ο���δ����
		break;
	case E003_QUEUE_EXCEED_OF_PER_DOCTOR:
		libOutputStr("E003");  //:ҽ���Ŷ������ﵽ����
		break;
	case E004_LACK_FEE_FOR_REGISTER:
		libOutputStr("E004"); //:���㹻�Һŷ���
		break;
	case E005_DIAGNOSE_SUCC:
		libOutputStr("E005"); //:���γɹ�
		break;
	case E006_NO_PATIENT_IN_QUEUE:
		libOutputStr("E006"); //:�޲����Ŷ�
		break;
	case E007_PAY_SUCC:
		libOutputStr("E007"); //:�ɷѳɹ�
		break;
	case E008_BALANCE_NOT_ENOUGH:
		libOutputStr("E008"); //:����
		break;
	case E014_PATIENT_NOT_BE_PAY_STATUS:
		libOutputStr("E014"); //:�޸ò��˴��ɷ�
		break;
	case E016_NO_PATIENT_IN_HOSP:
		libOutputStr("E016"); //:��Ժ�޸ò���
		break;
	case E017_DCT_DIAG_NOBODY:
		libOutputStr("E017"); //:ҽ����δ��Ϲ��κβ���
		break;
	default:
		break;
	}
	return;
}
void api_print_register_succ(void)
{
	libOutputStr("E001"); //:�Һųɹ�
	return;
}


void libOutputStr(char* pcStr)
{
	if (NULL != pcStr)
	{
		printf("%s\n", pcStr);
	}
}
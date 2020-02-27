#define _CRT_SECURE_NO_WARNINGS 1

#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "stdlib.h"

#define min(a,b)    (((a) < (b)) ? (a) : (b))
	//医生初始信息的记录数
#define MAX_DOCTOR_RECORD       1
	//病人初始信息的记录数
#define MAX_PATIENT_RECORD      6
	//医生允许排队就诊的病人最大数量
#define MAX_DOCTOR_CAPABILITY   4
	//挂号费
#define REG_FEE                 10
	//处方费
#define DIAG_FEE                50
	//命名字符串最大长度
#define CMD_LEN                 10000
	//命令分隔符
#define CMD_SEPARATRIX          ","
#define true 1
	//操作码定义
	typedef enum _OpRet
	{
		E000_INITITIAL_SUCC = 0, //E000:初始化成功
		E002_DIAGNOSE_NOT_END = 2, //E002:本次看病未结束
		E003_QUEUE_EXCEED_OF_PER_DOCTOR = 3, //E003:医生排队人数达到上限
		E004_LACK_FEE_FOR_REGISTER = 4, //E004:无足够挂号费用
		E005_DIAGNOSE_SUCC = 5, //E005:诊治成功
		E006_NO_PATIENT_IN_QUEUE = 6, //E006:无病人排队
		E007_PAY_SUCC = 7, //E007:缴费成功
		E008_BALANCE_NOT_ENOUGH = 8, //E008:余额不足
		E014_PATIENT_NOT_BE_PAY_STATUS = 14, //E014:无该病人待缴费
		E016_NO_PATIENT_IN_HOSP = 16, //E016:本院无该病人
		E017_DCT_DIAG_NOBODY = 17, //E017:医生尚未诊断过任何病人
	}OpRet;
	//病人就诊的状态
	typedef enum
	{
		PS_IDLE,    //未挂号
		PS_IN_QUEUE,//待就诊
		PS_WAIT_PAY,//待缴费
	}PatientStatus;
	//病人类型
	typedef enum
	{
		PM_CREDIT,  //无社保病人
		PM_INSURE,  //有社保病人
					//在挂号和缴费是有区别
	}PayMethod;
	//查询方式
	typedef enum
	{
		Q_DOCTOR,   //按医生ID查询
		Q_PATIENT,  //按病人ID查询
	}QueryType;
	//单条的病人初始信息记录
	struct PatientIni
	{
		const char *patientId;  //病人ID
		int patientLevel;       //病人类型
		int creditBalance;      //现金金额
		int insureBalance;      //社保金额
	};
	//查询医生的信息结果
	typedef struct
	{
		int queueNum;                               //排队的病人数量
		const char *pPatientIdInfo[MAX_DOCTOR_CAPABILITY];//排队的病人ID列表
													//用指针数组，Queue->pPatientIdInfo[0]表示的为排在第一位的病人。
	}DoctorQueue;
	//病人信息，测试的依据，考生不允许更改其数值
	static struct PatientIni gPatientIniCfg[] =
	{
		//病人ID  病人类型 现金金额 社保金额
		{ "pat01", 0,       100,     0  , },
		{ "pat02", 1,       100,     100, },
		{ "pat03", 0,       100,     0  , },
		{ "pat04", 1,       100,     50 , },
		{ "pat05", 1,       10 ,     10 , },
		{ "pat06", 1,       20 ,     10 , },
	};
	static PatientStatus Status[] = { PS_IDLE,PS_IDLE,PS_IDLE,PS_IDLE,PS_IDLE,PS_IDLE };
	static DoctorQueue Queue = { 0,"" };

	void api_print_operation_result(OpRet opRet);

	void api_print_register_succ(void);

	void api_print_patient_query_info(const char *pPatientId,
		PatientStatus patientStatus,
		int sequence,
		int insureBalance,
		int creditBalance);

	void api_print_doctor_query_info(DoctorQueue *pDoctorQueue);
	//需考生实现的函数声明 BEGIN
	void OpInit(void);
	void OpRegister(const char *pPatientId);
	void OpDiag();
	void OpPay(const char *pPatientId);
	void OpQuery(QueryType queryType, const char *pQueryId);
	//需考生实现的函数声明 END
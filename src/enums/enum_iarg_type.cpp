#include "pin.H"
extern "C" {
#include <lua.h>
}
#include <map>
using namespace std;
static void error(lua_State* L, string val){
lua_pushstring(L,("unable to find define "+val+" in enum IARG_TYPE").c_str());
lua_error(L);
}
static map<string,IARG_TYPE> init_map(){
	map<string,IARG_TYPE> smap;
	smap["IARG_BRANCH_TAKEN"]=IARG_BRANCH_TAKEN;
	smap["IARG_LINE_NO"]=IARG_LINE_NO;
	smap["IARG_INVALID"]=IARG_INVALID;
	smap["IARG_PREDICATE"]=IARG_PREDICATE;
	smap["IARG_SYSCALL_ARG4"]=IARG_SYSCALL_ARG4;
	smap["IARG_REG_NAT_VALUE"]=IARG_REG_NAT_VALUE;
	smap["IARG_STACK_VALUE"]=IARG_STACK_VALUE;
	smap["IARG_MEMORY_VALUE"]=IARG_MEMORY_VALUE;
	smap["IARG_MEMORYWRITE_EA"]=IARG_MEMORYWRITE_EA;
	smap["IARG_PARTIAL_CONTEXT"]=IARG_PARTIAL_CONTEXT;
	smap["IARG_MEMORY_REFERENCE"]=IARG_MEMORY_REFERENCE;
	smap["IARG_G_ARG1_CALLEE"]=IARG_G_ARG1_CALLEE;
	smap["IARG_SYSCALL_ARG1"]=IARG_SYSCALL_ARG1;
	smap["IARG_G_ARG4_CALLEE"]=IARG_G_ARG4_CALLEE;
	smap["IARG_G_ARG5_CALLER"]=IARG_G_ARG5_CALLER;
	smap["IARG_MULTI_MEMORYACCESS_EA"]=IARG_MULTI_MEMORYACCESS_EA;
	smap["IARG_CALL_ORDER"]=IARG_CALL_ORDER;
	smap["IARG_G_ARG2_CALLER"]=IARG_G_ARG2_CALLER;
	smap["IARG_MEMORYOP_PTR"]=IARG_MEMORYOP_PTR;
	smap["IARG_STACK_REFERENCE"]=IARG_STACK_REFERENCE;
	smap["IARG_FUNCARG_CALLSITE_REFERENCE"]=IARG_FUNCARG_CALLSITE_REFERENCE;
	smap["IARG_SYSCALL_NUMBER"]=IARG_SYSCALL_NUMBER;
	smap["IARG_MEMORYOP_EA"]=IARG_MEMORYOP_EA;
	smap["IARG_MEMORYREAD_SIZE"]=IARG_MEMORYREAD_SIZE;
	smap["IARG_G_ARG1_CALLER"]=IARG_G_ARG1_CALLER;
	smap["IARG_G_ARG4_CALLER"]=IARG_G_ARG4_CALLER;
	smap["IARG_G_ARG3_CALLEE"]=IARG_G_ARG3_CALLEE;
	smap["IARG_FIRST_REP_ITERATION"]=IARG_FIRST_REP_ITERATION;
	smap["IARG_REG_OUTPUT_FRAME_REFERENCE"]=IARG_REG_OUTPUT_FRAME_REFERENCE;
	smap["IARG_G_ARG0_CALLEE"]=IARG_G_ARG0_CALLEE;
	smap["IARG_THREAD_ID"]=IARG_THREAD_ID;
	smap["IARG_SYSCALL_ARG3"]=IARG_SYSCALL_ARG3;
	smap["IARG_SYSARG_REFERENCE"]=IARG_SYSARG_REFERENCE;
	smap["IARG_RETURN_REGS"]=IARG_RETURN_REGS;
	smap["IARG_FILE_NAME"]=IARG_FILE_NAME;
	smap["IARG_REG_CONST_REFERENCE"]=IARG_REG_CONST_REFERENCE;
	smap["IARG_SYSRET_ERRNO"]=IARG_SYSRET_ERRNO;
	smap["IARG_ORIG_FUNCPTR"]=IARG_ORIG_FUNCPTR;
	smap["IARG_G_RESULT0"]=IARG_G_RESULT0;
	smap["IARG_EXECUTING"]=IARG_EXECUTING;
	smap["IARG_SYSCALL_ARG0"]=IARG_SYSCALL_ARG0;
	smap["IARG_FUNCRET_EXITPOINT_REFERENCE"]=IARG_FUNCRET_EXITPOINT_REFERENCE;
	smap["IARG_FAST_ANALYSIS_CALL"]=IARG_FAST_ANALYSIS_CALL;
	smap["IARG_MEMORYREAD_PTR"]=IARG_MEMORYREAD_PTR;
	smap["IARG_REG_REFERENCE"]=IARG_REG_REFERENCE;
	smap["IARG_PRESERVE"]=IARG_PRESERVE;
	smap["IARG_G_ARG3_CALLER"]=IARG_G_ARG3_CALLER;
	smap["IARG_G_ARG0_CALLER"]=IARG_G_ARG0_CALLER;
	smap["IARG_BRANCH_TARGET_ADDR"]=IARG_BRANCH_TARGET_ADDR;
	smap["IARG_MEMORYOP_MASKED_ON"]=IARG_MEMORYOP_MASKED_ON;
	smap["IARG_PTR"]=IARG_PTR;
	smap["IARG_SYSCALL_ARG5"]=IARG_SYSCALL_ARG5;
	smap["IARG_MEMORYREAD2_EA"]=IARG_MEMORYREAD2_EA;
	smap["IARG_SYSARG_VALUE"]=IARG_SYSARG_VALUE;
	smap["IARG_REG_VALUE"]=IARG_REG_VALUE;
	smap["IARG_ADDRINT"]=IARG_ADDRINT;
	smap["IARG_REG_OUTPUT_FRAME_VALUE"]=IARG_REG_OUTPUT_FRAME_VALUE;
	smap["IARG_FUNCARG_ENTRYPOINT_REFERENCE"]=IARG_FUNCARG_ENTRYPOINT_REFERENCE;
	smap["IARG_LAST"]=IARG_LAST;
	smap["IARG_FUNCARG_ENTRYPOINT_VALUE"]=IARG_FUNCARG_ENTRYPOINT_VALUE;
	smap["IARG_MEMORYREAD2_PTR"]=IARG_MEMORYREAD2_PTR;
	smap["IARG_IARGLIST"]=IARG_IARGLIST;
	smap["IARG_UINT32"]=IARG_UINT32;
	smap["IARG_SYSCALL_ARG2"]=IARG_SYSCALL_ARG2;
	smap["IARG_MEMORYREAD_EA"]=IARG_MEMORYREAD_EA;
	smap["IARG_INST_PTR"]=IARG_INST_PTR;
	smap["IARG_PROTOTYPE"]=IARG_PROTOTYPE;
	smap["IARG_SYSRET_VALUE"]=IARG_SYSRET_VALUE;
	smap["IARG_BOOL"]=IARG_BOOL;
	smap["IARG_RETURN_IP"]=IARG_RETURN_IP;
	smap["IARG_CONST_CONTEXT"]=IARG_CONST_CONTEXT;
	smap["IARG_MEMORYWRITE_PTR"]=IARG_MEMORYWRITE_PTR;
	smap["IARG_MEMORYWRITE_SIZE"]=IARG_MEMORYWRITE_SIZE;
	smap["IARG_TSC"]=IARG_TSC;
	smap["IARG_G_ARG5_CALLEE"]=IARG_G_ARG5_CALLEE;
	smap["IARG_FUNCRET_EXITPOINT_VALUE"]=IARG_FUNCRET_EXITPOINT_VALUE;
	smap["IARG_G_ARG2_CALLEE"]=IARG_G_ARG2_CALLEE;
	smap["IARG_FALLTHROUGH_ADDR"]=IARG_FALLTHROUGH_ADDR;
	smap["IARG_CONTEXT"]=IARG_CONTEXT;
	smap["IARG_FUNCARG_CALLSITE_VALUE"]=IARG_FUNCARG_CALLSITE_VALUE;
	return smap;
}
IARG_TYPE lookup_string_to_iarg_type(lua_State *L, string str){
  static const map<string,IARG_TYPE> sym_map = init_map();
  if(sym_map.find(str)!=sym_map.end()){
    return sym_map.find(str)->second;
  }
 error(L,str);
 return sym_map.begin()->second; //this will never be reached just to prevent compiler warning
}
string lookup_iarg_type_to_string(lua_State* L,IARG_TYPE sym) {
 switch (sym) {
    case(IARG_BRANCH_TAKEN): return "IARG_BRANCH_TAKEN";
    case(IARG_LINE_NO): return "IARG_LINE_NO";
    case(IARG_INVALID): return "IARG_INVALID";
    case(IARG_PREDICATE): return "IARG_PREDICATE";
    case(IARG_SYSCALL_ARG4): return "IARG_SYSCALL_ARG4";
    case(IARG_REG_NAT_VALUE): return "IARG_REG_NAT_VALUE";
    case(IARG_STACK_VALUE): return "IARG_STACK_VALUE";
    case(IARG_MEMORY_VALUE): return "IARG_MEMORY_VALUE";
    case(IARG_MEMORYWRITE_EA): return "IARG_MEMORYWRITE_EA";
    case(IARG_PARTIAL_CONTEXT): return "IARG_PARTIAL_CONTEXT";
    case(IARG_MEMORY_REFERENCE): return "IARG_MEMORY_REFERENCE";
    case(IARG_G_ARG1_CALLEE): return "IARG_G_ARG1_CALLEE";
    case(IARG_SYSCALL_ARG1): return "IARG_SYSCALL_ARG1";
    case(IARG_G_ARG4_CALLEE): return "IARG_G_ARG4_CALLEE";
    case(IARG_G_ARG5_CALLER): return "IARG_G_ARG5_CALLER";
    case(IARG_MULTI_MEMORYACCESS_EA): return "IARG_MULTI_MEMORYACCESS_EA";
    case(IARG_CALL_ORDER): return "IARG_CALL_ORDER";
    case(IARG_G_ARG2_CALLER): return "IARG_G_ARG2_CALLER";
    case(IARG_MEMORYOP_PTR): return "IARG_MEMORYOP_PTR";
    case(IARG_STACK_REFERENCE): return "IARG_STACK_REFERENCE";
    case(IARG_FUNCARG_CALLSITE_REFERENCE): return "IARG_FUNCARG_CALLSITE_REFERENCE";
    case(IARG_SYSCALL_NUMBER): return "IARG_SYSCALL_NUMBER";
    case(IARG_MEMORYOP_EA): return "IARG_MEMORYOP_EA";
    case(IARG_MEMORYREAD_SIZE): return "IARG_MEMORYREAD_SIZE";
    case(IARG_G_ARG1_CALLER): return "IARG_G_ARG1_CALLER";
    case(IARG_G_ARG4_CALLER): return "IARG_G_ARG4_CALLER";
    case(IARG_G_ARG3_CALLEE): return "IARG_G_ARG3_CALLEE";
    case(IARG_FIRST_REP_ITERATION): return "IARG_FIRST_REP_ITERATION";
    case(IARG_REG_OUTPUT_FRAME_REFERENCE): return "IARG_REG_OUTPUT_FRAME_REFERENCE";
    case(IARG_G_ARG0_CALLEE): return "IARG_G_ARG0_CALLEE";
    case(IARG_THREAD_ID): return "IARG_THREAD_ID";
    case(IARG_SYSCALL_ARG3): return "IARG_SYSCALL_ARG3";
    case(IARG_SYSARG_REFERENCE): return "IARG_SYSARG_REFERENCE";
    case(IARG_RETURN_REGS): return "IARG_RETURN_REGS";
    case(IARG_FILE_NAME): return "IARG_FILE_NAME";
    case(IARG_REG_CONST_REFERENCE): return "IARG_REG_CONST_REFERENCE";
    case(IARG_SYSRET_ERRNO): return "IARG_SYSRET_ERRNO";
    case(IARG_ORIG_FUNCPTR): return "IARG_ORIG_FUNCPTR";
    case(IARG_G_RESULT0): return "IARG_G_RESULT0";
    case(IARG_EXECUTING): return "IARG_EXECUTING";
    case(IARG_SYSCALL_ARG0): return "IARG_SYSCALL_ARG0";
    case(IARG_FUNCRET_EXITPOINT_REFERENCE): return "IARG_FUNCRET_EXITPOINT_REFERENCE";
    case(IARG_FAST_ANALYSIS_CALL): return "IARG_FAST_ANALYSIS_CALL";
    case(IARG_MEMORYREAD_PTR): return "IARG_MEMORYREAD_PTR";
    case(IARG_REG_REFERENCE): return "IARG_REG_REFERENCE";
    case(IARG_PRESERVE): return "IARG_PRESERVE";
    case(IARG_G_ARG3_CALLER): return "IARG_G_ARG3_CALLER";
    case(IARG_G_ARG0_CALLER): return "IARG_G_ARG0_CALLER";
    case(IARG_BRANCH_TARGET_ADDR): return "IARG_BRANCH_TARGET_ADDR";
    case(IARG_MEMORYOP_MASKED_ON): return "IARG_MEMORYOP_MASKED_ON";
    case(IARG_PTR): return "IARG_PTR";
    case(IARG_SYSCALL_ARG5): return "IARG_SYSCALL_ARG5";
    case(IARG_MEMORYREAD2_EA): return "IARG_MEMORYREAD2_EA";
    case(IARG_SYSARG_VALUE): return "IARG_SYSARG_VALUE";
    case(IARG_REG_VALUE): return "IARG_REG_VALUE";
    case(IARG_ADDRINT): return "IARG_ADDRINT";
    case(IARG_REG_OUTPUT_FRAME_VALUE): return "IARG_REG_OUTPUT_FRAME_VALUE";
    case(IARG_FUNCARG_ENTRYPOINT_REFERENCE): return "IARG_FUNCARG_ENTRYPOINT_REFERENCE";
    case(IARG_LAST): return "IARG_LAST";
    case(IARG_FUNCARG_ENTRYPOINT_VALUE): return "IARG_FUNCARG_ENTRYPOINT_VALUE";
    case(IARG_MEMORYREAD2_PTR): return "IARG_MEMORYREAD2_PTR";
    case(IARG_IARGLIST): return "IARG_IARGLIST";
    case(IARG_UINT32): return "IARG_UINT32";
    case(IARG_SYSCALL_ARG2): return "IARG_SYSCALL_ARG2";
    case(IARG_MEMORYREAD_EA): return "IARG_MEMORYREAD_EA";
    case(IARG_INST_PTR): return "IARG_INST_PTR";
    case(IARG_PROTOTYPE): return "IARG_PROTOTYPE";
    case(IARG_SYSRET_VALUE): return "IARG_SYSRET_VALUE";
    case(IARG_BOOL): return "IARG_BOOL";
    case(IARG_RETURN_IP): return "IARG_RETURN_IP";
    case(IARG_CONST_CONTEXT): return "IARG_CONST_CONTEXT";
    case(IARG_MEMORYWRITE_PTR): return "IARG_MEMORYWRITE_PTR";
    case(IARG_MEMORYWRITE_SIZE): return "IARG_MEMORYWRITE_SIZE";
    case(IARG_TSC): return "IARG_TSC";
    case(IARG_G_ARG5_CALLEE): return "IARG_G_ARG5_CALLEE";
    case(IARG_FUNCRET_EXITPOINT_VALUE): return "IARG_FUNCRET_EXITPOINT_VALUE";
    case(IARG_G_ARG2_CALLEE): return "IARG_G_ARG2_CALLEE";
    case(IARG_FALLTHROUGH_ADDR): return "IARG_FALLTHROUGH_ADDR";
    case(IARG_CONTEXT): return "IARG_CONTEXT";
    case(IARG_FUNCARG_CALLSITE_VALUE): return "IARG_FUNCARG_CALLSITE_VALUE";
  }
error(L, "unknown enum value");
return "never reached";
}

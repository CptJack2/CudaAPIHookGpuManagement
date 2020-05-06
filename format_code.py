import re
import sys
import os

def add_trace_api(matched):
    funcn=matched.group("funcn")
    print(funcn)
    return matched.group(0)+"\n"+'''#ifdef TRACE_API_CALL
    printf("'''+funcn+r''' wrapper called\n");
#endif'''

def libcuda_addtrace():
    f=open(os.path.dirname(os.path.abspath(__file__))+"/cudadev100_stub.cpp.bak")
    code=f.read()
    res=re.sub(r"(?P<funcn>cu[A-Z].*)\(.*{",add_trace_api,code)
    #print(res)
    with open("/home/cptjack/a.cpp",'w') as f2:
        f2.write(res)

def libcudart_addtrace():
    f=open(os.path.dirname(os.path.abspath(__file__))+"/cudart100_stub.cpp.bak")
    code=f.read()
    res=re.sub(r"(?P<funcn>cuda[A-Z].*)\(.*{",add_trace_api,code)
    #print(res)
    with open("/home/cptjack/a.cpp",'w') as f2:
        f2.write(res)

libcudart_addtrace()
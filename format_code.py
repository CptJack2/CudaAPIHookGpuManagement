import re
import sys
import os

def add_trace_api(matched):
    funcn=matched.group("funcn")
    print(matched.group(0))
    return matched.group(0)+"\n"+'''#ifdef TRACE_API_CALL
    printf("'''+funcn+r''' wrapper called\n");
#endif'''

def libcuda_addtrace():
    f=open(os.path.dirname(os.path.abspath(__file__))+"/cudadev100_stub.cpp.bak")
    code=f.read()
    res=re.sub(r"(__)?(?P<funcn>cu[A-Z][A-Za-z0-9]*)\([\s\S]*?\{",add_trace_api,code)
    #print(res)
    with open(os.path.dirname(os.path.abspath(__file__))+"/a.cpp",'w') as f2:
        f2.write(res)

def libcudart_addtrace():
    f=open(os.path.dirname(os.path.abspath(__file__))+"/cudart100_stub.cpp.bak")
    code=f.read()
    res=re.sub(r"(__)?(?P<funcn>cuda[A-Z][A-Za-z0-9]*)\([\s\S]*?\{",add_trace_api,code)
    #print(res)
    with open(os.path.dirname(os.path.abspath(__file__))+"/a.cpp",'w') as f2:
        f2.write(res)

libcuda_addtrace()
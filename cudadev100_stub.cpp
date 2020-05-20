#include <cuda.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#define TRACE_API_CALL

static void *cudadev_handle = nullptr;
static size_t gmem_visible=3*1024*1024*1024;
static size_t gmem_used=0;

static void LoadLibrary() {
	cudadev_handle = dlopen("/usr/lib/x86_64-linux-gnu/libcuda.so.1.orig", RTLD_NOW | RTLD_LOCAL);
	if (!cudadev_handle) {
		printf("original libcuda.so.1 not found, exiting\n");
		exit(1);
	}
}

template<typename T>
static T LoadSymbol(const char *symbol_name) {
	if (!cudadev_handle) LoadLibrary();
	void *symbol = dlsym(cudadev_handle, symbol_name);
	return reinterpret_cast<T>(symbol);
}

CUresult GetSymbolNotFoundError() {
	return CUDA_ERROR_SHARED_OBJECT_INIT_FAILED;
}

// Forward-declare types introduced in CUDA 9.0.
typedef struct CUDA_LAUNCH_PARAMS_st CUDA_LAUNCH_PARAMS;

#ifndef __CUDA_DEPRECATED
#define __CUDA_DEPRECATED
#endif

#if CUDA_VERSION < 10000
// Define fake enums introduced in CUDA 10.0.
typedef enum CUgraphNodeType_enum {} CUgraphNodeType;
typedef enum CUstreamCaptureStatus_enum {} CUstreamCaptureStatus;
typedef enum CUexternalMemoryHandleType_enum {} CUexternalMemoryHandleType;
typedef enum CUexternalSemaphoreHandleType_enum {
} CUexternalSemaphoreHandleType;
#endif

// Forward-declare types introduced in CUDA 10.0.
typedef struct CUextMemory_st *CUexternalMemory;
typedef struct CUextSemaphore_st *CUexternalSemaphore;
typedef struct CUgraph_st *CUgraph;
typedef struct CUgraphNode_st *CUgraphNode;
typedef struct CUgraphExec_st *CUgraphExec;
typedef struct CUDA_KERNEL_NODE_PARAMS_st CUDA_KERNEL_NODE_PARAMS;
typedef struct CUDA_MEMSET_NODE_PARAMS_st CUDA_MEMSET_NODE_PARAMS;
typedef struct CUDA_HOST_NODE_PARAMS_st CUDA_HOST_NODE_PARAMS;
typedef struct CUDA_EXTERNAL_MEMORY_HANDLE_DESC_st
		CUDA_EXTERNAL_MEMORY_HANDLE_DESC;
typedef struct CUDA_EXTERNAL_MEMORY_BUFFER_DESC_st
		CUDA_EXTERNAL_MEMORY_BUFFER_DESC;
typedef struct CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC_st
		CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC;
typedef struct CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC_st
		CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC;
typedef struct CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_st
		CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS;
typedef struct CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS_st
		CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS;

typedef void(CUDA_CB *CUhostFn)(void *userData);

// For now only one stub implementation is needed. If a function that is not
// available in the given CUDA release, the corresponding wrapper returns
// CUDA_ERROR_SHARED_OBJECT_INIT_FAILED.
// Auto-generated, do not edit.

extern "C" {
CUresult CUDAAPI cuGetErrorString(CUresult error, const char **pStr) {
#ifdef TRACE_API_CALL
	printf("cuGetErrorString wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUresult, const char **);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGetErrorString");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(error, pStr);
}

CUresult CUDAAPI cuGetErrorName(CUresult error, const char **pStr) {
#ifdef TRACE_API_CALL
	printf("cuGetErrorName wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUresult, const char **);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGetErrorName");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(error, pStr);
}

CUresult CUDAAPI cuInit(unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuInit wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuInit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(Flags);
}

CUresult CUDAAPI cuDriverGetVersion(int *driverVersion) {
#ifdef TRACE_API_CALL
	printf("cuDriverGetVersion wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDriverGetVersion");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(driverVersion);
}

CUresult CUDAAPI cuDeviceGet(CUdevice *device, int ordinal) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGet wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevice *, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGet");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(device, ordinal);
}

CUresult CUDAAPI cuDeviceGetCount(int *count) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetCount wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetCount");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(count);
}

CUresult CUDAAPI cuDeviceGetName(char *name, int len, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetName wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(char *, int, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetName");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(name, len, dev);
}

CUresult CUDAAPI cuDeviceGetUuid(CUuuid *uuid, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetUuid wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUuuid *, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetUuid");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(uuid, dev);
}

CUresult CUDAAPI cuDeviceTotalMem(size_t *bytes, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceTotalMem wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(size_t *, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceTotalMem_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	auto ret = func_ptr(bytes, dev);
	if(ret==CUDA_SUCCESS){
		printf("changed return mem size\n");
		*bytes=gmem_visible;
	}
	return ret;
}

CUresult CUDAAPI cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetAttribute wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, CUdevice_attribute, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pi, attrib, dev);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuDeviceGetProperties(CUdevprop *prop, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetProperties wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevprop *, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetProperties");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(prop, dev);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuDeviceComputeCapability(int *major, int *minor, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceComputeCapability wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, int *, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceComputeCapability");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(major, minor, dev);
}

CUresult CUDAAPI cuDevicePrimaryCtxRetain(CUcontext *pctx, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDevicePrimaryCtxRetain wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext *, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDevicePrimaryCtxRetain");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pctx, dev);
}

CUresult CUDAAPI cuDevicePrimaryCtxRelease(CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDevicePrimaryCtxRelease wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDevicePrimaryCtxRelease");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dev);
}

CUresult CUDAAPI cuDevicePrimaryCtxSetFlags(CUdevice dev, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuDevicePrimaryCtxSetFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevice, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDevicePrimaryCtxSetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dev, flags);
}

CUresult CUDAAPI cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int *flags, int *active) {
#ifdef TRACE_API_CALL
	printf("cuDevicePrimaryCtxGetState wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevice, unsigned int *, int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDevicePrimaryCtxGetState");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dev, flags, active);
}

CUresult CUDAAPI cuDevicePrimaryCtxReset(CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDevicePrimaryCtxReset wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDevicePrimaryCtxReset");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dev);
}

CUresult CUDAAPI cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuCtxCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext *, unsigned int, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxCreate_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pctx, flags, dev);
}

CUresult CUDAAPI cuCtxDestroy(CUcontext ctx) {
#ifdef TRACE_API_CALL
	printf("cuCtxDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxDestroy_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ctx);
}

CUresult CUDAAPI cuCtxPushCurrent(CUcontext ctx) {
#ifdef TRACE_API_CALL
	printf("cuCtxPushCurrent wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxPushCurrent_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ctx);
}

CUresult CUDAAPI cuCtxPopCurrent(CUcontext *pctx) {
#ifdef TRACE_API_CALL
	printf("cuCtxPopCurrent wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxPopCurrent_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pctx);
}

CUresult CUDAAPI cuCtxSetCurrent(CUcontext ctx) {
#ifdef TRACE_API_CALL
	printf("cuCtxSetCurrent wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxSetCurrent");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ctx);
}

CUresult CUDAAPI cuCtxGetCurrent(CUcontext *pctx) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetCurrent wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetCurrent");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pctx);
}

CUresult CUDAAPI cuCtxGetDevice(CUdevice *device) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetDevice wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevice *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetDevice");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(device);
}

CUresult CUDAAPI cuCtxGetFlags(unsigned int *flags) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(flags);
}

CUresult CUDAAPI cuCtxSynchronize(void) {
#ifdef TRACE_API_CALL
	printf("cuCtxSynchronize wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)();
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxSynchronize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr();
}

CUresult CUDAAPI cuCtxSetLimit(CUlimit limit, size_t value) {
#ifdef TRACE_API_CALL
	printf("cuCtxSetLimit wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUlimit, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxSetLimit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(limit, value);
}

CUresult CUDAAPI cuCtxGetLimit(size_t *pvalue, CUlimit limit) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetLimit wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(size_t *, CUlimit);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetLimit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pvalue, limit);
}

CUresult CUDAAPI cuCtxGetCacheConfig(CUfunc_cache *pconfig) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetCacheConfig wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunc_cache *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pconfig);
}

CUresult CUDAAPI cuCtxSetCacheConfig(CUfunc_cache config) {
#ifdef TRACE_API_CALL
	printf("cuCtxSetCacheConfig wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunc_cache);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxSetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(config);
}

CUresult CUDAAPI cuCtxGetSharedMemConfig(CUsharedconfig *pConfig) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetSharedMemConfig wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUsharedconfig *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetSharedMemConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pConfig);
}

CUresult CUDAAPI cuCtxSetSharedMemConfig(CUsharedconfig config) {
#ifdef TRACE_API_CALL
	printf("cuCtxSetSharedMemConfig wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUsharedconfig);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxSetSharedMemConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(config);
}

CUresult CUDAAPI cuCtxGetApiVersion(CUcontext ctx, unsigned int *version) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetApiVersion wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext, unsigned int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetApiVersion");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ctx, version);
}

CUresult CUDAAPI cuCtxGetStreamPriorityRange(int *leastPriority, int *greatestPriority) {
#ifdef TRACE_API_CALL
	printf("cuCtxGetStreamPriorityRange wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxGetStreamPriorityRange");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(leastPriority, greatestPriority);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuCtxAttach(CUcontext *pctx, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuCtxAttach wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxAttach");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pctx, flags);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuCtxDetach(CUcontext ctx) {
#ifdef TRACE_API_CALL
	printf("cuCtxDetach wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxDetach");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ctx);
}

CUresult CUDAAPI cuModuleLoad(CUmodule *module, const char *fname) {
#ifdef TRACE_API_CALL
	printf("cuModuleLoad wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmodule *, const char *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleLoad");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(module, fname);
}

CUresult CUDAAPI cuModuleLoadData(CUmodule *module, const void *image) {
#ifdef TRACE_API_CALL
	printf("cuModuleLoadData wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmodule *, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleLoadData");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(module, image);
}

CUresult CUDAAPI cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options,
									void **optionValues) {
#ifdef TRACE_API_CALL
	printf("cuModuleLoadDataEx wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmodule *, const void *, unsigned int, CUjit_option *, void **);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleLoadDataEx");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(module, image, numOptions, options, optionValues);
}

CUresult CUDAAPI cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin) {
#ifdef TRACE_API_CALL
	printf("cuModuleLoadFatBinary wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmodule *, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleLoadFatBinary");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(module, fatCubin);
}

CUresult CUDAAPI cuModuleUnload(CUmodule hmod) {
#ifdef TRACE_API_CALL
	printf("cuModuleUnload wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmodule);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleUnload");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hmod);
}

CUresult CUDAAPI cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name) {
#ifdef TRACE_API_CALL
	printf("cuModuleGetFunction wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction *, CUmodule, const char *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleGetFunction");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, hmod, name);
}

CUresult CUDAAPI cuModuleGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name) {
#ifdef TRACE_API_CALL
	printf("cuModuleGetGlobal wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, size_t *, CUmodule, const char *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleGetGlobal_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dptr, bytes, hmod, name);
}

CUresult CUDAAPI cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name) {
#ifdef TRACE_API_CALL
	printf("cuModuleGetTexRef wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref *, CUmodule, const char *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleGetTexRef");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pTexRef, hmod, name);
}

CUresult CUDAAPI cuModuleGetSurfRef(CUsurfref *pSurfRef, CUmodule hmod, const char *name) {
#ifdef TRACE_API_CALL
	printf("cuModuleGetSurfRef wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUsurfref *, CUmodule, const char *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuModuleGetSurfRef");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pSurfRef, hmod, name);
}

CUresult CUDAAPI
cuLinkCreate(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut) {
#ifdef TRACE_API_CALL
	printf("cuLinkCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int, CUjit_option *, void **, CUlinkState *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLinkCreate_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(numOptions, options, optionValues, stateOut);
}

CUresult CUDAAPI
cuLinkAddData(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name,
			  unsigned int numOptions, CUjit_option *options, void **optionValues) {
#ifdef TRACE_API_CALL
	printf("cuLinkAddData wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUlinkState, CUjitInputType, void *, size_t, const char *, unsigned int,
										CUjit_option *, void **);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLinkAddData_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(state, type, data, size, name, numOptions, options, optionValues);
}

CUresult CUDAAPI
cuLinkAddFile(CUlinkState state, CUjitInputType type, const char *path,
			  unsigned int numOptions, CUjit_option *options, void **optionValues) {
#ifdef TRACE_API_CALL
	printf("cuLinkAddFile wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUlinkState, CUjitInputType, const char *, unsigned int, CUjit_option *,
										void **);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLinkAddFile_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(state, type, path, numOptions, options, optionValues);
}

CUresult CUDAAPI
cuLinkComplete(CUlinkState state, void **cubinOut, size_t *sizeOut) {
#ifdef TRACE_API_CALL
	printf("cuLinkComplete wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUlinkState, void **, size_t *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLinkComplete");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(state, cubinOut, sizeOut);
}

CUresult CUDAAPI
cuLinkDestroy(CUlinkState state) {
#ifdef TRACE_API_CALL
	printf("cuLinkDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUlinkState);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLinkDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(state);
}

CUresult CUDAAPI cuMemGetInfo(size_t *free, size_t *total) {
#ifdef TRACE_API_CALL
	printf("cuMemGetInfo wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(size_t *, size_t *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemGetInfo_v2");
	if (!func_ptr) return GetSymbolNotFoundError();

	auto ret = func_ptr(free, total);
	if(ret==CUDA_SUCCESS){
		*free=gmem_visible-gmem_used;
		*total=gmem_visible;
	}
	return ret;
}

CUresult CUDAAPI cuMemAlloc(CUdeviceptr *dptr, size_t bytesize) {
#ifdef TRACE_API_CALL
	printf("cuMemAlloc wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemAlloc_v2");
	if (!func_ptr) return GetSymbolNotFoundError();

	if(gmem_used+bytesize<=gmem_visible) {
		gmem_used+=bytesize;
		return func_ptr(dptr, bytesize);
	}
	else
		return CUDA_ERROR_OUT_OF_MEMORY;
}

CUresult CUDAAPI
cuMemAllocPitch(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes) {
#ifdef TRACE_API_CALL
	printf("cuMemAllocPitch wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, size_t *, size_t, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemAllocPitch_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
}

CUresult CUDAAPI cuMemFree(CUdeviceptr dptr) {
#ifdef TRACE_API_CALL
	printf("cuMemFree wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemFree_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dptr);
}

CUresult CUDAAPI cuMemGetAddressRange(CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr) {
#ifdef TRACE_API_CALL
	printf("cuMemGetAddressRange wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, size_t *, CUdeviceptr);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemGetAddressRange_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pbase, psize, dptr);
}

CUresult CUDAAPI cuMemAllocHost(void **pp, size_t bytesize) {
#ifdef TRACE_API_CALL
	printf("cuMemAllocHost wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void **, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemAllocHost_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pp, bytesize);
}

CUresult CUDAAPI cuMemFreeHost(void *p) {
#ifdef TRACE_API_CALL
	printf("cuMemFreeHost wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemFreeHost");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(p);
}

CUresult CUDAAPI cuMemHostAlloc(void **pp, size_t bytesize, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuMemHostAlloc wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void **, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemHostAlloc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pp, bytesize, Flags);
}

CUresult CUDAAPI cuMemHostGetDevicePointer(CUdeviceptr *pdptr, void *p, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuMemHostGetDevicePointer wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, void *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemHostGetDevicePointer_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pdptr, p, Flags);
}

CUresult CUDAAPI cuMemHostGetFlags(unsigned int *pFlags, void *p) {
#ifdef TRACE_API_CALL
	printf("cuMemHostGetFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int *, void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemHostGetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pFlags, p);
}

CUresult CUDAAPI cuMemAllocManaged(CUdeviceptr *dptr, size_t bytesize, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuMemAllocManaged wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemAllocManaged");
	if (!func_ptr) return GetSymbolNotFoundError();

	if(gmem_used+bytesize<=gmem_visible) {
		gmem_used+=bytesize;
		return func_ptr(dptr, bytesize, flags);
	}
	else
		return CUDA_ERROR_OUT_OF_MEMORY;
}

CUresult CUDAAPI cuDeviceGetByPCIBusId(CUdevice *dev, const char *pciBusId) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetByPCIBusId wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdevice *, const char *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetByPCIBusId");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dev, pciBusId);
}

CUresult CUDAAPI cuDeviceGetPCIBusId(char *pciBusId, int len, CUdevice dev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetPCIBusId wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(char *, int, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetPCIBusId");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pciBusId, len, dev);
}

CUresult CUDAAPI cuIpcGetEventHandle(CUipcEventHandle *pHandle, CUevent event) {
#ifdef TRACE_API_CALL
	printf("cuIpcGetEventHandle wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUipcEventHandle *, CUevent);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuIpcGetEventHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pHandle, event);
}

CUresult CUDAAPI cuIpcOpenEventHandle(CUevent *phEvent, CUipcEventHandle handle) {
#ifdef TRACE_API_CALL
	printf("cuIpcOpenEventHandle wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUevent *, CUipcEventHandle);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuIpcOpenEventHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(phEvent, handle);
}

CUresult CUDAAPI cuIpcGetMemHandle(CUipcMemHandle *pHandle, CUdeviceptr dptr) {
#ifdef TRACE_API_CALL
	printf("cuIpcGetMemHandle wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUipcMemHandle *, CUdeviceptr);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuIpcGetMemHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pHandle, dptr);
}

CUresult CUDAAPI cuIpcOpenMemHandle(CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuIpcOpenMemHandle wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, CUipcMemHandle, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuIpcOpenMemHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pdptr, handle, Flags);
}

CUresult CUDAAPI cuIpcCloseMemHandle(CUdeviceptr dptr) {
#ifdef TRACE_API_CALL
	printf("cuIpcCloseMemHandle wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuIpcCloseMemHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dptr);
}

CUresult CUDAAPI cuMemHostRegister(void *p, size_t bytesize, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuMemHostRegister wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemHostRegister_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(p, bytesize, Flags);
}

CUresult CUDAAPI cuMemHostUnregister(void *p) {
#ifdef TRACE_API_CALL
	printf("cuMemHostUnregister wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemHostUnregister");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(p);
}

CUresult CUDAAPI cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, src, ByteCount);
}

CUresult CUDAAPI cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext,
							  size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyPeer wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyPeer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstContext, srcDevice, srcContext, ByteCount);
}

CUresult CUDAAPI cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyHtoD wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, const void *, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyHtoD_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, srcHost, ByteCount);
}

CUresult CUDAAPI cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyDtoH wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyDtoH_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstHost, srcDevice, ByteCount);
}

CUresult CUDAAPI cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyDtoD wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyDtoD_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, srcDevice, ByteCount);
}

CUresult CUDAAPI cuMemcpyDtoA(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyDtoA wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray, size_t, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyDtoA_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstArray, dstOffset, srcDevice, ByteCount);
}

CUresult CUDAAPI cuMemcpyAtoD(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyAtoD wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, CUarray, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyAtoD_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, srcArray, srcOffset, ByteCount);
}

CUresult CUDAAPI cuMemcpyHtoA(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyHtoA wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray, size_t, const void *, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyHtoA_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstArray, dstOffset, srcHost, ByteCount);
}

CUresult CUDAAPI cuMemcpyAtoH(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyAtoH wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *, CUarray, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyAtoH_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstHost, srcArray, srcOffset, ByteCount);
}

CUresult CUDAAPI
cuMemcpyAtoA(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyAtoA wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray, size_t, CUarray, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyAtoA_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstArray, dstOffset, srcArray, srcOffset, ByteCount);
}

CUresult CUDAAPI cuMemcpy2D(const CUDA_MEMCPY2D *pCopy) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy2D wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUDA_MEMCPY2D *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy2D_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCopy);
}

CUresult CUDAAPI cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *pCopy) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy2DUnaligned wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUDA_MEMCPY2D *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy2DUnaligned_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCopy);
}

CUresult CUDAAPI cuMemcpy3D(const CUDA_MEMCPY3D *pCopy) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy3D wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUDA_MEMCPY3D *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy3D_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCopy);
}

CUresult CUDAAPI cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER *pCopy) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy3DPeer wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUDA_MEMCPY3D_PEER *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy3DPeer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCopy);
}

CUresult CUDAAPI cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, CUdeviceptr, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, src, ByteCount, hStream);
}

CUresult CUDAAPI
cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext,
				  size_t ByteCount, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyPeerAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyPeerAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyHtoDAsync(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyHtoDAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, const void *, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyHtoDAsync_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, srcHost, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyDtoHAsync(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyDtoHAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *, CUdeviceptr, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyDtoHAsync_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstHost, srcDevice, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpyDtoDAsync(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyDtoDAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, CUdeviceptr, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyDtoDAsync_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, srcDevice, ByteCount, hStream);
}

CUresult CUDAAPI
cuMemcpyHtoAAsync(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyHtoAAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray, size_t, const void *, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyHtoAAsync_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstArray, dstOffset, srcHost, ByteCount, hStream);
}

CUresult CUDAAPI
cuMemcpyAtoHAsync(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpyAtoHAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *, CUarray, size_t, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpyAtoHAsync_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstHost, srcArray, srcOffset, ByteCount, hStream);
}

CUresult CUDAAPI cuMemcpy2DAsync(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy2DAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUDA_MEMCPY2D *, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy2DAsync_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCopy, hStream);
}

CUresult CUDAAPI cuMemcpy3DAsync(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy3DAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUDA_MEMCPY3D *, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy3DAsync_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCopy, hStream);
}

CUresult CUDAAPI cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemcpy3DPeerAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUDA_MEMCPY3D_PEER *, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemcpy3DPeerAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCopy, hStream);
}

CUresult CUDAAPI cuMemsetD8(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD8 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, unsigned char, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD8_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, uc, N);
}

CUresult CUDAAPI cuMemsetD16(CUdeviceptr dstDevice, unsigned short us, size_t N) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD16 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, unsigned short, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD16_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, us, N);
}

CUresult CUDAAPI cuMemsetD32(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD32 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, unsigned int, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD32_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, ui, N);
}

CUresult CUDAAPI cuMemsetD2D8(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD2D8 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, unsigned char, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD2D8_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstPitch, uc, Width, Height);
}

CUresult CUDAAPI cuMemsetD2D16(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD2D16 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, unsigned short, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD2D16_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstPitch, us, Width, Height);
}

CUresult CUDAAPI cuMemsetD2D32(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD2D32 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, unsigned int, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD2D32_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstPitch, ui, Width, Height);
}

CUresult CUDAAPI cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD8Async wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, unsigned char, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD8Async");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, uc, N, hStream);
}

CUresult CUDAAPI cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD16Async wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, unsigned short, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD16Async");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, us, N, hStream);
}

CUresult CUDAAPI cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD32Async wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, unsigned int, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD32Async");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, ui, N, hStream);
}

CUresult CUDAAPI
cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height,
				  CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD2D8Async wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD2D8Async");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstPitch, uc, Width, Height, hStream);
}

CUresult CUDAAPI
cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height,
				   CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD2D16Async wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, unsigned short, size_t, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD2D16Async");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstPitch, us, Width, Height, hStream);
}

CUresult CUDAAPI
cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height,
				   CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemsetD2D32Async wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemsetD2D32Async");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dstDevice, dstPitch, ui, Width, Height, hStream);
}

CUresult CUDAAPI cuArrayCreate(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
#ifdef TRACE_API_CALL
	printf("cuArrayCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuArrayCreate_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pHandle, pAllocateArray);
}

CUresult CUDAAPI cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
#ifdef TRACE_API_CALL
	printf("cuArrayGetDescriptor wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUDA_ARRAY_DESCRIPTOR *, CUarray);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuArrayGetDescriptor_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pArrayDescriptor, hArray);
}

CUresult CUDAAPI cuArrayDestroy(CUarray hArray) {
#ifdef TRACE_API_CALL
	printf("cuArrayDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuArrayDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hArray);
}

CUresult CUDAAPI cuArray3DCreate(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
#ifdef TRACE_API_CALL
	printf("cuArray3DCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuArray3DCreate_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pHandle, pAllocateArray);
}

CUresult CUDAAPI cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
#ifdef TRACE_API_CALL
	printf("cuArray3DGetDescriptor wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuArray3DGetDescriptor_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pArrayDescriptor, hArray);
}

CUresult CUDAAPI cuMipmappedArrayCreate(CUmipmappedArray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pMipmappedArrayDesc,
										unsigned int numMipmapLevels) {
#ifdef TRACE_API_CALL
	printf("cuMipmappedArrayCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmipmappedArray *, const CUDA_ARRAY3D_DESCRIPTOR *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMipmappedArrayCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pHandle, pMipmappedArrayDesc, numMipmapLevels);
}

CUresult CUDAAPI cuMipmappedArrayGetLevel(CUarray *pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level) {
#ifdef TRACE_API_CALL
	printf("cuMipmappedArrayGetLevel wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray *, CUmipmappedArray, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMipmappedArrayGetLevel");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pLevelArray, hMipmappedArray, level);
}

CUresult CUDAAPI cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray) {
#ifdef TRACE_API_CALL
	printf("cuMipmappedArrayDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmipmappedArray);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMipmappedArrayDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hMipmappedArray);
}

CUresult CUDAAPI cuPointerGetAttribute(void *data, CUpointer_attribute attribute, CUdeviceptr ptr) {
#ifdef TRACE_API_CALL
	printf("cuPointerGetAttribute wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *, CUpointer_attribute, CUdeviceptr);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuPointerGetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(data, attribute, ptr);
}

CUresult CUDAAPI cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuMemPrefetchAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, CUdevice, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemPrefetchAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, count, dstDevice, hStream);
}

CUresult CUDAAPI cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device) {
#ifdef TRACE_API_CALL
	printf("cuMemAdvise wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr, size_t, CUmem_advise, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemAdvise");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, count, advice, device);
}

CUresult CUDAAPI
cuMemRangeGetAttribute(void *data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count) {
#ifdef TRACE_API_CALL
	printf("cuMemRangeGetAttribute wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void *, size_t, CUmem_range_attribute, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemRangeGetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(data, dataSize, attribute, devPtr, count);
}

CUresult CUDAAPI
cuMemRangeGetAttributes(void **data, size_t *dataSizes, CUmem_range_attribute *attributes, size_t numAttributes,
						CUdeviceptr devPtr, size_t count) {
#ifdef TRACE_API_CALL
	printf("cuMemRangeGetAttributes wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(void **, size_t *, CUmem_range_attribute *, size_t, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuMemRangeGetAttributes");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(data, dataSizes, attributes, numAttributes, devPtr, count);
}

CUresult CUDAAPI cuPointerSetAttribute(const void *value, CUpointer_attribute attribute, CUdeviceptr ptr) {
#ifdef TRACE_API_CALL
	printf("cuPointerSetAttribute wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const void *, CUpointer_attribute, CUdeviceptr);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuPointerSetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(value, attribute, ptr);
}

CUresult CUDAAPI
cuPointerGetAttributes(unsigned int numAttributes, CUpointer_attribute *attributes, void **data, CUdeviceptr ptr) {
#ifdef TRACE_API_CALL
	printf("cuPointerGetAttributes wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int, CUpointer_attribute *, void **, CUdeviceptr);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuPointerGetAttributes");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(numAttributes, attributes, data, ptr);
}

CUresult CUDAAPI cuStreamCreate(CUstream *phStream, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(phStream, Flags);
}

CUresult CUDAAPI cuStreamCreateWithPriority(CUstream *phStream, unsigned int flags, int priority) {
#ifdef TRACE_API_CALL
	printf("cuStreamCreateWithPriority wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream *, unsigned int, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamCreateWithPriority");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(phStream, flags, priority);
}

CUresult CUDAAPI cuStreamGetPriority(CUstream hStream, int *priority) {
#ifdef TRACE_API_CALL
	printf("cuStreamGetPriority wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamGetPriority");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, priority);
}

CUresult CUDAAPI cuStreamGetFlags(CUstream hStream, unsigned int *flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamGetFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, unsigned int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamGetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, flags);
}

CUresult CUDAAPI cuStreamGetCtx(CUstream hStream, CUcontext *pctx) {
#ifdef TRACE_API_CALL
	printf("cuStreamGetCtx wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUcontext *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamGetCtx");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, pctx);
}

CUresult CUDAAPI cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamWaitEvent wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUevent, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamWaitEvent");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, hEvent, Flags);
}

CUresult CUDAAPI cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void *userData, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamAddCallback wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUstreamCallback, void *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamAddCallback");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, callback, userData, flags);
}

CUresult CUDAAPI cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamAttachMemAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUdeviceptr, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamAttachMemAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, dptr, length, flags);
}

CUresult CUDAAPI cuStreamQuery(CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuStreamQuery wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamQuery");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream);
}

CUresult CUDAAPI cuStreamSynchronize(CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuStreamSynchronize wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamSynchronize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream);
}

CUresult CUDAAPI cuStreamDestroy(CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuStreamDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamDestroy_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream);
}

CUresult CUDAAPI cuEventCreate(CUevent *phEvent, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuEventCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUevent *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuEventCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(phEvent, Flags);
}

CUresult CUDAAPI cuEventRecord(CUevent hEvent, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuEventRecord wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUevent, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuEventRecord");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hEvent, hStream);
}

CUresult CUDAAPI cuEventQuery(CUevent hEvent) {
#ifdef TRACE_API_CALL
	printf("cuEventQuery wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUevent);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuEventQuery");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hEvent);
}

CUresult CUDAAPI cuEventSynchronize(CUevent hEvent) {
#ifdef TRACE_API_CALL
	printf("cuEventSynchronize wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUevent);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuEventSynchronize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hEvent);
}

CUresult CUDAAPI cuEventDestroy(CUevent hEvent) {
#ifdef TRACE_API_CALL
	printf("cuEventDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUevent);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuEventDestroy_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hEvent);
}

CUresult CUDAAPI cuEventElapsedTime(float *pMilliseconds, CUevent hStart, CUevent hEnd) {
#ifdef TRACE_API_CALL
	printf("cuEventElapsedTime wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(float *, CUevent, CUevent);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuEventElapsedTime");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pMilliseconds, hStart, hEnd);
}

CUresult CUDAAPI
cuImportExternalMemory(CUexternalMemory *extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc) {
#ifdef TRACE_API_CALL
	printf("cuImportExternalMemory wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUexternalMemory *, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuImportExternalMemory");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extMem_out, memHandleDesc);
}

CUresult CUDAAPI cuExternalMemoryGetMappedBuffer(CUdeviceptr *devPtr, CUexternalMemory extMem,
												 const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc) {
#ifdef TRACE_API_CALL
	printf("cuExternalMemoryGetMappedBuffer wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, CUexternalMemory, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuExternalMemoryGetMappedBuffer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, extMem, bufferDesc);
}

CUresult CUDAAPI cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray *mipmap, CUexternalMemory extMem,
														 const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc) {
#ifdef TRACE_API_CALL
	printf("cuExternalMemoryGetMappedMipmappedArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmipmappedArray *, CUexternalMemory,
										const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuExternalMemoryGetMappedMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(mipmap, extMem, mipmapDesc);
}

CUresult CUDAAPI cuDestroyExternalMemory(CUexternalMemory extMem) {
#ifdef TRACE_API_CALL
	printf("cuDestroyExternalMemory wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUexternalMemory);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDestroyExternalMemory");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extMem);
}

CUresult CUDAAPI
cuImportExternalSemaphore(CUexternalSemaphore *extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc) {
#ifdef TRACE_API_CALL
	printf("cuImportExternalSemaphore wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuImportExternalSemaphore");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSem_out, semHandleDesc);
}

CUresult CUDAAPI cuSignalExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray,
												 const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray,
												 unsigned int numExtSems, CUstream stream) {
#ifdef TRACE_API_CALL
	printf("cuSignalExternalSemaphoresAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *,
										unsigned int, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuSignalExternalSemaphoresAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSemArray, paramsArray, numExtSems, stream);
}

CUresult CUDAAPI cuWaitExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray,
											   const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray,
											   unsigned int numExtSems, CUstream stream) {
#ifdef TRACE_API_CALL
	printf("cuWaitExternalSemaphoresAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *,
										unsigned int, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuWaitExternalSemaphoresAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSemArray, paramsArray, numExtSems, stream);
}

CUresult CUDAAPI cuDestroyExternalSemaphore(CUexternalSemaphore extSem) {
#ifdef TRACE_API_CALL
	printf("cuDestroyExternalSemaphore wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUexternalSemaphore);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDestroyExternalSemaphore");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSem);
}

CUresult CUDAAPI cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamWaitValue32 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUdeviceptr, cuuint32_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamWaitValue32");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWaitValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamWaitValue64 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUdeviceptr, cuuint64_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamWaitValue64");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamWriteValue32 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUdeviceptr, cuuint32_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamWriteValue32");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, addr, value, flags);
}

CUresult CUDAAPI cuStreamWriteValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamWriteValue64 wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUdeviceptr, cuuint64_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamWriteValue64");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, addr, value, flags);
}

CUresult CUDAAPI
cuStreamBatchMemOp(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuStreamBatchMemOp wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuStreamBatchMemOp");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, count, paramArray, flags);
}

CUresult CUDAAPI cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc) {
#ifdef TRACE_API_CALL
	printf("cuFuncGetAttribute wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, CUfunction_attribute, CUfunction);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuFuncGetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pi, attrib, hfunc);
}

CUresult CUDAAPI cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int value) {
#ifdef TRACE_API_CALL
	printf("cuFuncSetAttribute wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, CUfunction_attribute, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuFuncSetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, attrib, value);
}

CUresult CUDAAPI cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config) {
#ifdef TRACE_API_CALL
	printf("cuFuncSetCacheConfig wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, CUfunc_cache);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuFuncSetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, config);
}

CUresult CUDAAPI cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config) {
#ifdef TRACE_API_CALL
	printf("cuFuncSetSharedMemConfig wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, CUsharedconfig);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuFuncSetSharedMemConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, config);
}

CUresult CUDAAPI cuLaunchKernel(CUfunction f,
								unsigned int gridDimX,
								unsigned int gridDimY,
								unsigned int gridDimZ,
								unsigned int blockDimX,
								unsigned int blockDimY,
								unsigned int blockDimZ,
								unsigned int sharedMemBytes,
								CUstream hStream,
								void **kernelParams,
								void **extra) {
#ifdef TRACE_API_CALL
	printf("cuLaunchKernel wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int,
										unsigned int, unsigned int, unsigned int, CUstream, void **, void **);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLaunchKernel");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream,
					kernelParams, extra);
}

CUresult CUDAAPI cuLaunchCooperativeKernel(CUfunction f,
										   unsigned int gridDimX,
										   unsigned int gridDimY,
										   unsigned int gridDimZ,
										   unsigned int blockDimX,
										   unsigned int blockDimY,
										   unsigned int blockDimZ,
										   unsigned int sharedMemBytes,
										   CUstream hStream,
										   void **kernelParams) {
#ifdef TRACE_API_CALL
	printf("cuLaunchCooperativeKernel wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int,
										unsigned int, unsigned int, unsigned int, CUstream, void **);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLaunchCooperativeKernel");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream,
					kernelParams);
}

CUresult CUDAAPI cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS *launchParamsList, unsigned int numDevices,
													  unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuLaunchCooperativeKernelMultiDevice wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUDA_LAUNCH_PARAMS *, unsigned int, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLaunchCooperativeKernelMultiDevice");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(launchParamsList, numDevices, flags);
}

CUresult CUDAAPI cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void *userData) {
#ifdef TRACE_API_CALL
	printf("cuLaunchHostFunc wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUstream, CUhostFn, void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLaunchHostFunc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, fn, userData);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuFuncSetBlockShape(CUfunction hfunc, int x, int y, int z) {
#ifdef TRACE_API_CALL
	printf("cuFuncSetBlockShape wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, int, int, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuFuncSetBlockShape");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, x, y, z);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes) {
#ifdef TRACE_API_CALL
	printf("cuFuncSetSharedSize wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuFuncSetSharedSize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, bytes);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetSize(CUfunction hfunc, unsigned int numbytes) {
#ifdef TRACE_API_CALL
	printf("cuParamSetSize wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuParamSetSize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, numbytes);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSeti(CUfunction hfunc, int offset, unsigned int value) {
#ifdef TRACE_API_CALL
	printf("cuParamSeti wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, int, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuParamSeti");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, offset, value);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetf(CUfunction hfunc, int offset, float value) {
#ifdef TRACE_API_CALL
	printf("cuParamSetf wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, int, float);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuParamSetf");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, offset, value);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetv(CUfunction hfunc, int offset, void *ptr, unsigned int numbytes) {
#ifdef TRACE_API_CALL
	printf("cuParamSetv wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, int, void *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuParamSetv");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, offset, ptr, numbytes);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuLaunch(CUfunction f) {
#ifdef TRACE_API_CALL
	printf("cuLaunch wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLaunch");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(f);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuLaunchGrid(CUfunction f, int grid_width, int grid_height) {
#ifdef TRACE_API_CALL
	printf("cuLaunchGrid wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, int, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLaunchGrid");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(f, grid_width, grid_height);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuLaunchGridAsync(CUfunction f, int grid_width, int grid_height, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuLaunchGridAsync wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, int, int, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuLaunchGridAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(f, grid_width, grid_height, hStream);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuParamSetTexRef wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfunction, int, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuParamSetTexRef");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hfunc, texunit, hTexRef);
}

CUresult CUDAAPI
cuOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize) {
#ifdef TRACE_API_CALL
	printf("cuOccupancyMaxActiveBlocksPerMultiprocessor wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, CUfunction, int, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuOccupancyMaxActiveBlocksPerMultiprocessor");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(numBlocks, func, blockSize, dynamicSMemSize);
}

CUresult CUDAAPI cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *numBlocks, CUfunction func, int blockSize,
																	  size_t dynamicSMemSize, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, CUfunction, int, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(numBlocks, func, blockSize, dynamicSMemSize, flags);
}

CUresult CUDAAPI cuOccupancyMaxPotentialBlockSize(int *minGridSize, int *blockSize, CUfunction func,
												  CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize,
												  int blockSizeLimit) {
#ifdef TRACE_API_CALL
	printf("cuOccupancyMaxPotentialBlockSize wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuOccupancyMaxPotentialBlockSize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit);
}

CUresult CUDAAPI cuOccupancyMaxPotentialBlockSizeWithFlags(int *minGridSize, int *blockSize, CUfunction func,
														   CUoccupancyB2DSize blockSizeToDynamicSMemSize,
														   size_t dynamicSMemSize, int blockSizeLimit,
														   unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuOccupancyMaxPotentialBlockSizeWithFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuOccupancyMaxPotentialBlockSizeWithFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags);
}

CUresult CUDAAPI cuTexRefSetArray(CUtexref hTexRef, CUarray hArray, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, CUarray, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, hArray, Flags);
}

CUresult CUDAAPI cuTexRefSetMipmappedArray(CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetMipmappedArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, CUmipmappedArray, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, hMipmappedArray, Flags);
}

CUresult CUDAAPI cuTexRefSetAddress(size_t *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetAddress wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(size_t *, CUtexref, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetAddress_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ByteOffset, hTexRef, dptr, bytes);
}

CUresult CUDAAPI
cuTexRefSetAddress2D(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetAddress2D wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetAddress2D_v3");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, desc, dptr, Pitch);
}

CUresult CUDAAPI cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetFormat wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, CUarray_format, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetFormat");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, fmt, NumPackedComponents);
}

CUresult CUDAAPI cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetAddressMode wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, int, CUaddress_mode);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetAddressMode");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, dim, am);
}

CUresult CUDAAPI cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetFilterMode wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, CUfilter_mode);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetFilterMode");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, fm);
}

CUresult CUDAAPI cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetMipmapFilterMode wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, CUfilter_mode);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetMipmapFilterMode");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, fm);
}

CUresult CUDAAPI cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetMipmapLevelBias wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, float);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetMipmapLevelBias");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, bias);
}

CUresult CUDAAPI cuTexRefSetMipmapLevelClamp(CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetMipmapLevelClamp wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, float, float);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetMipmapLevelClamp");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
}

CUresult CUDAAPI cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned int maxAniso) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetMaxAnisotropy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetMaxAnisotropy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, maxAniso);
}

CUresult CUDAAPI cuTexRefSetBorderColor(CUtexref hTexRef, float *pBorderColor) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetBorderColor wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, float *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetBorderColor");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, pBorderColor);
}

CUresult CUDAAPI cuTexRefSetFlags(CUtexref hTexRef, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuTexRefSetFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefSetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef, Flags);
}

CUresult CUDAAPI cuTexRefGetAddress(CUdeviceptr *pdptr, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetAddress wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetAddress_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pdptr, hTexRef);
}

CUresult CUDAAPI cuTexRefGetArray(CUarray *phArray, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(phArray, hTexRef);
}

CUresult CUDAAPI cuTexRefGetMipmappedArray(CUmipmappedArray *phMipmappedArray, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetMipmappedArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmipmappedArray *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(phMipmappedArray, hTexRef);
}

CUresult CUDAAPI cuTexRefGetAddressMode(CUaddress_mode *pam, CUtexref hTexRef, int dim) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetAddressMode wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUaddress_mode *, CUtexref, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetAddressMode");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pam, hTexRef, dim);
}

CUresult CUDAAPI cuTexRefGetFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetFilterMode wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfilter_mode *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetFilterMode");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pfm, hTexRef);
}

CUresult CUDAAPI cuTexRefGetFormat(CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetFormat wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray_format *, int *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetFormat");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pFormat, pNumChannels, hTexRef);
}

CUresult CUDAAPI cuTexRefGetMipmapFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetMipmapFilterMode wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUfilter_mode *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetMipmapFilterMode");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pfm, hTexRef);
}

CUresult CUDAAPI cuTexRefGetMipmapLevelBias(float *pbias, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetMipmapLevelBias wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(float *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetMipmapLevelBias");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pbias, hTexRef);
}

CUresult CUDAAPI
cuTexRefGetMipmapLevelClamp(float *pminMipmapLevelClamp, float *pmaxMipmapLevelClamp, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetMipmapLevelClamp wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(float *, float *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetMipmapLevelClamp");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
}

CUresult CUDAAPI cuTexRefGetMaxAnisotropy(int *pmaxAniso, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetMaxAnisotropy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetMaxAnisotropy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pmaxAniso, hTexRef);
}

CUresult CUDAAPI cuTexRefGetBorderColor(float *pBorderColor, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetBorderColor wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(float *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetBorderColor");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pBorderColor, hTexRef);
}

CUresult CUDAAPI cuTexRefGetFlags(unsigned int *pFlags, CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefGetFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int *, CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefGetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pFlags, hTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefCreate(CUtexref *pTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pTexRef);
}

__CUDA_DEPRECATED CUresult CUDAAPI cuTexRefDestroy(CUtexref hTexRef) {
#ifdef TRACE_API_CALL
	printf("cuTexRefDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexRefDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hTexRef);
}

CUresult CUDAAPI cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuSurfRefSetArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUsurfref, CUarray, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuSurfRefSetArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hSurfRef, hArray, Flags);
}

CUresult CUDAAPI cuSurfRefGetArray(CUarray *phArray, CUsurfref hSurfRef) {
#ifdef TRACE_API_CALL
	printf("cuSurfRefGetArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray *, CUsurfref);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuSurfRefGetArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(phArray, hSurfRef);
}

CUresult CUDAAPI
cuTexObjectCreate(CUtexObject *pTexObject, const CUDA_RESOURCE_DESC *pResDesc, const CUDA_TEXTURE_DESC *pTexDesc,
				  const CUDA_RESOURCE_VIEW_DESC *pResViewDesc) {
#ifdef TRACE_API_CALL
	printf("cuTexObjectCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexObject *, const CUDA_RESOURCE_DESC *, const CUDA_TEXTURE_DESC *,
										const CUDA_RESOURCE_VIEW_DESC *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexObjectCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pTexObject, pResDesc, pTexDesc, pResViewDesc);
}

CUresult CUDAAPI cuTexObjectDestroy(CUtexObject texObject) {
#ifdef TRACE_API_CALL
	printf("cuTexObjectDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUtexObject);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexObjectDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(texObject);
}

CUresult CUDAAPI cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUtexObject texObject) {
#ifdef TRACE_API_CALL
	printf("cuTexObjectGetResourceDesc wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUDA_RESOURCE_DESC *, CUtexObject);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexObjectGetResourceDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pResDesc, texObject);
}

CUresult CUDAAPI cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC *pTexDesc, CUtexObject texObject) {
#ifdef TRACE_API_CALL
	printf("cuTexObjectGetTextureDesc wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUDA_TEXTURE_DESC *, CUtexObject);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexObjectGetTextureDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pTexDesc, texObject);
}

CUresult CUDAAPI cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC *pResViewDesc, CUtexObject texObject) {
#ifdef TRACE_API_CALL
	printf("cuTexObjectGetResourceViewDesc wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUDA_RESOURCE_VIEW_DESC *, CUtexObject);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuTexObjectGetResourceViewDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pResViewDesc, texObject);
}

CUresult CUDAAPI cuSurfObjectCreate(CUsurfObject *pSurfObject, const CUDA_RESOURCE_DESC *pResDesc) {
#ifdef TRACE_API_CALL
	printf("cuSurfObjectCreate wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUsurfObject *, const CUDA_RESOURCE_DESC *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuSurfObjectCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pSurfObject, pResDesc);
}

CUresult CUDAAPI cuSurfObjectDestroy(CUsurfObject surfObject) {
#ifdef TRACE_API_CALL
	printf("cuSurfObjectDestroy wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUsurfObject);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuSurfObjectDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(surfObject);
}

CUresult CUDAAPI cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUsurfObject surfObject) {
#ifdef TRACE_API_CALL
	printf("cuSurfObjectGetResourceDesc wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUDA_RESOURCE_DESC *, CUsurfObject);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuSurfObjectGetResourceDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pResDesc, surfObject);
}

CUresult CUDAAPI cuDeviceCanAccessPeer(int *canAccessPeer, CUdevice dev, CUdevice peerDev) {
#ifdef TRACE_API_CALL
	printf("cuDeviceCanAccessPeer wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, CUdevice, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceCanAccessPeer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(canAccessPeer, dev, peerDev);
}

CUresult CUDAAPI cuCtxEnablePeerAccess(CUcontext peerContext, unsigned int Flags) {
#ifdef TRACE_API_CALL
	printf("cuCtxEnablePeerAccess wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxEnablePeerAccess");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(peerContext, Flags);
}

CUresult CUDAAPI cuCtxDisablePeerAccess(CUcontext peerContext) {
#ifdef TRACE_API_CALL
	printf("cuCtxDisablePeerAccess wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUcontext);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuCtxDisablePeerAccess");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(peerContext);
}

CUresult CUDAAPI
cuDeviceGetP2PAttribute(int *value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice) {
#ifdef TRACE_API_CALL
	printf("cuDeviceGetP2PAttribute wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(int *, CUdevice_P2PAttribute, CUdevice, CUdevice);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuDeviceGetP2PAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(value, attrib, srcDevice, dstDevice);
}

CUresult CUDAAPI cuGraphicsUnregisterResource(CUgraphicsResource resource) {
#ifdef TRACE_API_CALL
	printf("cuGraphicsUnregisterResource wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUgraphicsResource);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGraphicsUnregisterResource");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(resource);
}

CUresult CUDAAPI
cuGraphicsSubResourceGetMappedArray(CUarray *pArray, CUgraphicsResource resource, unsigned int arrayIndex,
									unsigned int mipLevel) {
#ifdef TRACE_API_CALL
	printf("cuGraphicsSubResourceGetMappedArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUarray *, CUgraphicsResource, unsigned int, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGraphicsSubResourceGetMappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pArray, resource, arrayIndex, mipLevel);
}

CUresult CUDAAPI
cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray *pMipmappedArray, CUgraphicsResource resource) {
#ifdef TRACE_API_CALL
	printf("cuGraphicsResourceGetMappedMipmappedArray wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUmipmappedArray *, CUgraphicsResource);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGraphicsResourceGetMappedMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pMipmappedArray, resource);
}

CUresult CUDAAPI cuGraphicsResourceGetMappedPointer(CUdeviceptr *pDevPtr, size_t *pSize, CUgraphicsResource resource) {
#ifdef TRACE_API_CALL
	printf("cuGraphicsResourceGetMappedPointer wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUdeviceptr *, size_t *, CUgraphicsResource);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGraphicsResourceGetMappedPointer_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pDevPtr, pSize, resource);
}

CUresult CUDAAPI cuGraphicsResourceSetMapFlags(CUgraphicsResource resource, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cuGraphicsResourceSetMapFlags wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(CUgraphicsResource, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGraphicsResourceSetMapFlags_v2");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(resource, flags);
}

CUresult CUDAAPI cuGraphicsMapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuGraphicsMapResources wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int, CUgraphicsResource *, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGraphicsMapResources");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(count, resources, hStream);
}

CUresult CUDAAPI cuGraphicsUnmapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
#ifdef TRACE_API_CALL
	printf("cuGraphicsUnmapResources wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(unsigned int, CUgraphicsResource *, CUstream);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGraphicsUnmapResources");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(count, resources, hStream);
}

CUresult CUDAAPI cuGetExportTable(const void **ppExportTable, const CUuuid *pExportTableId) {
#ifdef TRACE_API_CALL
	printf("cuGetExportTable wrapper called\n");
#endif
	using FuncPtr = CUresult(CUDAAPI *)(const void **, const CUuuid *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cuGetExportTable");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ppExportTable, pExportTableId);
}

}// extern "C"
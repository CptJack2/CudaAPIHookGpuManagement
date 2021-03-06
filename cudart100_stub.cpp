#include <dlfcn.h>
#include <cuda_runtime_api.h>
#include <stdio.h>
#include <stdlib.h>

#define TRACE_API_CALL

static void *cudart_handle = nullptr;

static void LoadLibrary() {
	cudart_handle = dlopen("/usr/local/cuda/lib64/libcudart.so.10.0.orig", RTLD_NOW | RTLD_LOCAL);
	if (!cudart_handle) {
		printf("original libcudart.so not found, exiting\n");
		exit(1);
	}
}

template<typename T>
static T LoadSymbol(const char *symbol_name) {
	if (!cudart_handle) LoadLibrary();
	void *symbol = dlsym(cudart_handle, symbol_name);
	return reinterpret_cast<T>(symbol);
}

cudaError_t GetSymbolNotFoundError() {
	return cudaErrorSharedObjectSymbolNotFound;
}

//CUDA 10.0 APIs
extern "C" {

extern __host__ cudaError_t CUDARTAPI cudaDeviceReset(void) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceReset wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)();
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceReset");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr();
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaDeviceSynchronize(void) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceSynchronize wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)();
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceSynchronize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr();
}

extern __host__ cudaError_t CUDARTAPI cudaDeviceSetLimit(enum cudaLimit limit,
														 size_t value) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceSetLimit wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaLimit, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceSetLimit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(limit, value);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaDeviceGetLimit(size_t *pValue, enum cudaLimit limit) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetLimit wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(size_t *, enum cudaLimit);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceGetLimit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pValue, limit);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaDeviceGetCacheConfig(enum cudaFuncCache *pCacheConfig) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetCacheConfig wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaFuncCache *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceGetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCacheConfig);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaDeviceGetStreamPriorityRange(int *leastPriority, int *greatestPriority) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetStreamPriorityRange wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *, int *);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaDeviceGetStreamPriorityRange");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(leastPriority, greatestPriority);
}

extern __host__ cudaError_t CUDARTAPI
cudaDeviceSetCacheConfig(enum cudaFuncCache cacheConfig) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceSetCacheConfig wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaFuncCache);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceSetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(cacheConfig);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaDeviceGetSharedMemConfig(enum cudaSharedMemConfig *pConfig) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetSharedMemConfig wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaSharedMemConfig *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceGetSharedMemConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pConfig);
}

extern __host__ cudaError_t CUDARTAPI
cudaDeviceSetSharedMemConfig(enum cudaSharedMemConfig config) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceSetSharedMemConfig wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaSharedMemConfig);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceSetSharedMemConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(config);
}

extern __host__ cudaError_t CUDARTAPI
cudaDeviceGetByPCIBusId(int *device, const char *pciBusId) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetByPCIBusId wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *, const char *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceGetByPCIBusId");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(device, pciBusId);
}

extern __host__ cudaError_t CUDARTAPI cudaDeviceGetPCIBusId(char *pciBusId,
															int len,
															int device) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetPCIBusId wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(char *, int, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceGetPCIBusId");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pciBusId, len, device);
}

extern __host__ cudaError_t CUDARTAPI
cudaIpcGetEventHandle(cudaIpcEventHandle_t *handle, cudaEvent_t event) {
#ifdef TRACE_API_CALL
	printf("cudaIpcGetEventHandle wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaIpcEventHandle_t *, cudaEvent_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaIpcGetEventHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(handle, event);
}

extern __host__ cudaError_t CUDARTAPI
cudaIpcOpenEventHandle(cudaEvent_t *event, cudaIpcEventHandle_t handle) {
#ifdef TRACE_API_CALL
	printf("cudaIpcOpenEventHandle wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaEvent_t *, cudaIpcEventHandle_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaIpcOpenEventHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(event, handle);
}

extern __host__ cudaError_t CUDARTAPI
cudaIpcGetMemHandle(cudaIpcMemHandle_t *handle, void *devPtr) {
#ifdef TRACE_API_CALL
	printf("cudaIpcGetMemHandle wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaIpcMemHandle_t *, void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaIpcGetMemHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(handle, devPtr);
}

extern __host__ cudaError_t CUDARTAPI cudaIpcOpenMemHandle(
		void **devPtr, cudaIpcMemHandle_t handle, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaIpcOpenMemHandle wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void **, cudaIpcMemHandle_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaIpcOpenMemHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, handle, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaIpcCloseMemHandle(void *devPtr) {
#ifdef TRACE_API_CALL
	printf("cudaIpcCloseMemHandle wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaIpcCloseMemHandle");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr);
}

extern  __host__ cudaError_t CUDARTAPI cudaThreadExit(void) {
#ifdef TRACE_API_CALL
	printf("cudaThreadExit wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)();
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaThreadExit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr();
}

extern  __host__ cudaError_t CUDARTAPI
cudaThreadSynchronize(void) {
#ifdef TRACE_API_CALL
	printf("cudaThreadSynchronize wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)();
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaThreadSynchronize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr();
}

extern  __host__ cudaError_t CUDARTAPI
cudaThreadSetLimit(enum cudaLimit limit, size_t value) {
#ifdef TRACE_API_CALL
	printf("cudaThreadSetLimit wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaLimit, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaThreadSetLimit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(limit, value);
}

extern  __host__ cudaError_t CUDARTAPI
cudaThreadGetLimit(size_t *pValue, enum cudaLimit limit) {
#ifdef TRACE_API_CALL
	printf("cudaThreadGetLimit wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(size_t *, enum cudaLimit);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaThreadGetLimit");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pValue, limit);
}

extern  __host__ cudaError_t CUDARTAPI
cudaThreadGetCacheConfig(enum cudaFuncCache *pCacheConfig) {
#ifdef TRACE_API_CALL
	printf("cudaThreadGetCacheConfig wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaFuncCache *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaThreadGetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pCacheConfig);
}

extern  __host__ cudaError_t CUDARTAPI
cudaThreadSetCacheConfig(enum cudaFuncCache cacheConfig) {
#ifdef TRACE_API_CALL
	printf("cudaThreadSetCacheConfig wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(enum cudaFuncCache);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaThreadSetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(cacheConfig);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaGetLastError(void) {
#ifdef TRACE_API_CALL
	printf("cudaGetLastError wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)();
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetLastError");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr();
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaPeekAtLastError(void) {
#ifdef TRACE_API_CALL
	printf("cudaPeekAtLastError wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)();
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaPeekAtLastError");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr();
}

extern __host__ __cudart_builtin__ const char *CUDARTAPI
cudaGetErrorName(cudaError_t error) {
#ifdef TRACE_API_CALL
	printf("cudaGetErrorName wrapper called\n");
#endif
	using FuncPtr = const char *(CUDARTAPI *)(cudaError_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetErrorName");
	if (!func_ptr) return "cudaGetErrorName symbol not found.";
	return func_ptr(error);
}

extern __host__ __cudart_builtin__ const char *CUDARTAPI
cudaGetErrorString(cudaError_t error) {
#ifdef TRACE_API_CALL
	printf("cudaGetErrorString wrapper called\n");
#endif
	using FuncPtr = const char *(CUDARTAPI *)(cudaError_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetErrorString");
	if (!func_ptr) return "cudaGetErrorString symbol not found.";
	return func_ptr(error);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaGetDeviceCount(int *count) {
#ifdef TRACE_API_CALL
	printf("cudaGetDeviceCount wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetDeviceCount");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(count);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device) {
#ifdef TRACE_API_CALL
	printf("cudaGetDeviceProperties wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(struct cudaDeviceProp *, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetDeviceProperties");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(prop, device);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaDeviceGetAttribute(int *value, enum cudaDeviceAttr attr, int device) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetAttribute wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *, enum cudaDeviceAttr, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceGetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(value, attr, device);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaDeviceGetP2PAttribute(int *value, enum cudaDeviceP2PAttr attr,
						  int srcDevice, int dstDevice) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceGetP2PAttribute wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(int *, enum cudaDeviceP2PAttr, int, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceGetP2PAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(value, attr, srcDevice, dstDevice);
}

extern __host__ cudaError_t CUDARTAPI
cudaChooseDevice(int *device, const struct cudaDeviceProp *prop) {
#ifdef TRACE_API_CALL
	printf("cudaChooseDevice wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(int *, const struct cudaDeviceProp *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaChooseDevice");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(device, prop);
}

extern __host__ cudaError_t CUDARTAPI cudaSetDevice(int device) {
#ifdef TRACE_API_CALL
	printf("cudaSetDevice wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaSetDevice");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(device);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaGetDevice(int *device) {
#ifdef TRACE_API_CALL
	printf("cudaGetDevice wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetDevice");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(device);
}

extern __host__ cudaError_t CUDARTAPI cudaSetValidDevices(int *device_arr,
														  int len) {
#ifdef TRACE_API_CALL
	printf("cudaSetValidDevices wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaSetValidDevices");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(device_arr, len);
}

extern __host__ cudaError_t CUDARTAPI cudaSetDeviceFlags(unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaSetDeviceFlags wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaSetDeviceFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(flags);
}

extern __host__ cudaError_t CUDARTAPI cudaGetDeviceFlags(unsigned int *flags) {
#ifdef TRACE_API_CALL
	printf("cudaGetDeviceFlags wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(unsigned int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetDeviceFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(flags);
}

extern __host__ cudaError_t CUDARTAPI cudaStreamCreate(cudaStream_t *pStream) {
#ifdef TRACE_API_CALL
	printf("cudaStreamCreate wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pStream);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaStreamCreateWithFlags(cudaStream_t *pStream, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaStreamCreateWithFlags wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamCreateWithFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pStream, flags);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaStreamCreateWithPriority(cudaStream_t *pStream, unsigned int flags,
							 int priority) {
#ifdef TRACE_API_CALL
	printf("cudaStreamCreateWithPriority wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t *, unsigned int, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamCreateWithPriority");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pStream, flags, priority);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaStreamGetPriority(cudaStream_t hStream, int *priority) {
#ifdef TRACE_API_CALL
	printf("cudaStreamGetPriority wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t, int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamGetPriority");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, priority);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaStreamGetFlags(cudaStream_t hStream, unsigned int *flags) {
#ifdef TRACE_API_CALL
	printf("cudaStreamGetFlags wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t, unsigned int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamGetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(hStream, flags);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaStreamDestroy(cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaStreamDestroy wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaStreamWaitEvent(
		cudaStream_t stream, cudaEvent_t event, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaStreamWaitEvent wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaStream_t, cudaEvent_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamWaitEvent");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, event, flags);
}

extern __host__ cudaError_t CUDARTAPI
cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback,
					  void *userData, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaStreamAddCallback wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t, cudaStreamCallback_t,
											 void *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamAddCallback");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, callback, userData, flags);
}

extern __host__ cudaError_t CUDARTAPI
cudaStreamSynchronize(cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaStreamSynchronize wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamSynchronize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream);
}

extern __host__ cudaError_t CUDARTAPI cudaStreamQuery(cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaStreamQuery wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamQuery");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaStreamAttachMemAsync(cudaStream_t stream, void *devPtr,
						 size_t length,
						 unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaStreamAttachMemAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaStream_t, void *, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamAttachMemAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, devPtr, length, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaStreamIsCapturing(
		cudaStream_t stream, enum cudaStreamCaptureStatus *pCaptureStatus) {
#ifdef TRACE_API_CALL
	printf("cudaStreamIsCapturing wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaStream_t, enum cudaStreamCaptureStatus *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaStreamIsCapturing");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, pCaptureStatus);
}

extern __host__ cudaError_t CUDARTAPI cudaEventCreate(cudaEvent_t *event) {
#ifdef TRACE_API_CALL
	printf("cudaEventCreate wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaEvent_t *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaEventCreate");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(event);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaEventCreateWithFlags(cudaEvent_t *event, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaEventCreateWithFlags wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaEvent_t *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaEventCreateWithFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(event, flags);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaEventRecord(cudaEvent_t event, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaEventRecord wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaEvent_t, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaEventRecord");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(event, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaEventQuery(cudaEvent_t event) {
#ifdef TRACE_API_CALL
	printf("cudaEventQuery wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaEvent_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaEventQuery");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(event);
}

extern __host__ cudaError_t CUDARTAPI cudaEventSynchronize(cudaEvent_t event) {
#ifdef TRACE_API_CALL
	printf("cudaEventSynchronize wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaEvent_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaEventSynchronize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(event);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaEventDestroy(cudaEvent_t event) {
#ifdef TRACE_API_CALL
	printf("cudaEventDestroy wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaEvent_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaEventDestroy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(event);
}

extern __host__ cudaError_t CUDARTAPI cudaEventElapsedTime(float *ms,
														   cudaEvent_t start,
														   cudaEvent_t end) {
#ifdef TRACE_API_CALL
	printf("cudaEventElapsedTime wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(float *, cudaEvent_t, cudaEvent_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaEventElapsedTime");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ms, start, end);
}

extern __host__ cudaError_t CUDARTAPI cudaImportExternalMemory(
		cudaExternalMemory_t *extMem_out,
		const struct cudaExternalMemoryHandleDesc *memHandleDesc) {
#ifdef TRACE_API_CALL
	printf("cudaImportExternalMemory wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			cudaExternalMemory_t *, const struct cudaExternalMemoryHandleDesc *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaImportExternalMemory");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extMem_out, memHandleDesc);
}

extern __host__ cudaError_t CUDARTAPI cudaExternalMemoryGetMappedBuffer(
		void **devPtr, cudaExternalMemory_t extMem,
		const struct cudaExternalMemoryBufferDesc *bufferDesc) {
#ifdef TRACE_API_CALL
	printf("cudaExternalMemoryGetMappedBuffer wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void **, cudaExternalMemory_t,
							 const struct cudaExternalMemoryBufferDesc *);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaExternalMemoryGetMappedBuffer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, extMem, bufferDesc);
}

extern __host__ cudaError_t CUDARTAPI cudaExternalMemoryGetMappedMipmappedArray(
		cudaMipmappedArray_t *mipmap, cudaExternalMemory_t extMem,
		const struct cudaExternalMemoryMipmappedArrayDesc *mipmapDesc) {
#ifdef TRACE_API_CALL
	printf("cudaExternalMemoryGetMappedMipmappedArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			cudaMipmappedArray_t *, cudaExternalMemory_t,
			const struct cudaExternalMemoryMipmappedArrayDesc *);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaExternalMemoryGetMappedMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(mipmap, extMem, mipmapDesc);
}

extern __host__ cudaError_t CUDARTAPI
cudaDestroyExternalMemory(cudaExternalMemory_t extMem) {
#ifdef TRACE_API_CALL
	printf("cudaDestroyExternalMemory wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaExternalMemory_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDestroyExternalMemory");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extMem);
}

extern __host__ cudaError_t CUDARTAPI cudaImportExternalSemaphore(
		cudaExternalSemaphore_t *extSem_out,
		const struct cudaExternalSemaphoreHandleDesc *semHandleDesc) {
#ifdef TRACE_API_CALL
	printf("cudaImportExternalSemaphore wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaExternalSemaphore_t *,
							 const struct cudaExternalSemaphoreHandleDesc *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaImportExternalSemaphore");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSem_out, semHandleDesc);
}

extern __host__ cudaError_t CUDARTAPI cudaSignalExternalSemaphoresAsync(
		const cudaExternalSemaphore_t *extSemArray,
		const struct cudaExternalSemaphoreSignalParams *paramsArray,
		unsigned int numExtSems, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaSignalExternalSemaphoresAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const cudaExternalSemaphore_t *,
							 const struct cudaExternalSemaphoreSignalParams *,
							 unsigned int, cudaStream_t);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaSignalExternalSemaphoresAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSemArray, paramsArray, numExtSems, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaWaitExternalSemaphoresAsync(
		const cudaExternalSemaphore_t *extSemArray,
		const struct cudaExternalSemaphoreWaitParams *paramsArray,
		unsigned int numExtSems, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaWaitExternalSemaphoresAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const cudaExternalSemaphore_t *,
							 const struct cudaExternalSemaphoreWaitParams *,
							 unsigned int, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaWaitExternalSemaphoresAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSemArray, paramsArray, numExtSems, stream);
}

extern __host__ cudaError_t CUDARTAPI
cudaDestroyExternalSemaphore(cudaExternalSemaphore_t extSem) {
#ifdef TRACE_API_CALL
	printf("cudaDestroyExternalSemaphore wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaExternalSemaphore_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDestroyExternalSemaphore");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(extSem);
}

extern __host__ cudaError_t CUDARTAPI
cudaLaunchKernel(const void *func, dim3 gridDim, dim3 blockDim, void **args,
				 size_t sharedMem, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaLaunchKernel wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void *, dim3, dim3, void **,
											 size_t, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaLaunchKernel");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(func, gridDim, blockDim, args, sharedMem, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaLaunchCooperativeKernel(
		const void *func, dim3 gridDim, dim3 blockDim, void **args,
		size_t sharedMem, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaLaunchCooperativeKernel wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void *, dim3, dim3, void **,
											 size_t, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaLaunchCooperativeKernel");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(func, gridDim, blockDim, args, sharedMem, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaLaunchCooperativeKernelMultiDevice(
		struct cudaLaunchParams *launchParamsList, unsigned int numDevices,
		unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaLaunchCooperativeKernelMultiDevice wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(struct cudaLaunchParams *,
											 unsigned int, unsigned int);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaLaunchCooperativeKernelMultiDevice");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(launchParamsList, numDevices, flags);
}

extern __host__ cudaError_t CUDARTAPI
cudaFuncSetCacheConfig(const void *func, enum cudaFuncCache cacheConfig) {
#ifdef TRACE_API_CALL
	printf("cudaFuncSetCacheConfig wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void *, enum cudaFuncCache);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFuncSetCacheConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(func, cacheConfig);
}

extern __host__ cudaError_t CUDARTAPI
cudaFuncSetSharedMemConfig(const void *func, enum cudaSharedMemConfig config) {
#ifdef TRACE_API_CALL
	printf("cudaFuncSetSharedMemConfig wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const void *, enum cudaSharedMemConfig);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFuncSetSharedMemConfig");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(func, config);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const void *func) {
#ifdef TRACE_API_CALL
	printf("cudaFuncGetAttributes wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(struct cudaFuncAttributes *, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFuncGetAttributes");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(attr, func);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaFuncSetAttribute(const void *func, enum cudaFuncAttribute attr, int value) {
#ifdef TRACE_API_CALL
	printf("cudaFuncSetAttribute wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const void *, enum cudaFuncAttribute, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFuncSetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(func, attr, value);
}

extern  __host__ cudaError_t CUDARTAPI
cudaSetDoubleForDevice(double *d) {
#ifdef TRACE_API_CALL
	printf("cudaSetDoubleForDevice wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(double *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaSetDoubleForDevice");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(d);
}

extern  __host__ cudaError_t CUDARTAPI
cudaSetDoubleForHost(double *d) {
#ifdef TRACE_API_CALL
	printf("cudaSetDoubleForHost wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(double *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaSetDoubleForHost");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(d);
}

extern __host__ cudaError_t CUDARTAPI cudaLaunchHostFunc(cudaStream_t stream,
														 cudaHostFn_t fn,
														 void *userData) {
#ifdef TRACE_API_CALL
	printf("cudaLaunchHostFunc wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaStream_t, cudaHostFn_t, void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaLaunchHostFunc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(stream, fn, userData);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, const void *func,
											  int blockSize,
											  size_t dynamicSMemSize) {
#ifdef TRACE_API_CALL
	printf("cudaOccupancyMaxActiveBlocksPerMultiprocessor wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *, const void *, int, size_t);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaOccupancyMaxActiveBlocksPerMultiprocessor");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(numBlocks, func, blockSize, dynamicSMemSize);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *numBlocks,
													   const void *func,
													   int blockSize,
													   size_t dynamicSMemSize,
													   unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(int *, const void *, int, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>(
			"cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(numBlocks, func, blockSize, dynamicSMemSize, flags);
}

extern __host__ cudaError_t CUDARTAPI
cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem,
				  cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaConfigureCall wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(dim3, dim3, size_t, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaConfigureCall");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(gridDim, blockDim, sharedMem, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaSetupArgument(const void *arg,
														size_t size,
														size_t offset) {
#ifdef TRACE_API_CALL
	printf("cudaSetupArgument wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void *, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaSetupArgument");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(arg, size, offset);
}

extern __host__ cudaError_t CUDARTAPI cudaLaunch(const void *func) {
#ifdef TRACE_API_CALL
	printf("cudaLaunch wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaLaunch");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(func);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMallocManaged(
		void **devPtr, size_t size, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaMallocManaged wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void **, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMallocManaged");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, size, flags);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaMalloc(void **devPtr, size_t size) {
#ifdef TRACE_API_CALL
	printf("cudaMalloc wrapper called\n");
	//system("touch /home/cptjack/cudaMalloc");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void **, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMalloc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, size);
}

extern __host__ cudaError_t CUDARTAPI cudaMallocHost(void **ptr, size_t size) {
#ifdef TRACE_API_CALL
	printf("cudaMallocHost wrapper called\n");
	//system("touch /home/cptjack/cudaMallocHost");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void **, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMallocHost");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ptr, size);
}

extern __host__ cudaError_t CUDARTAPI cudaMallocPitch(void **devPtr,
													  size_t *pitch,
													  size_t width,
													  size_t height) {
#ifdef TRACE_API_CALL
	printf("cudaMallocPitch wrapper called\n");
	//system("touch /home/cptjack/cudaMallocPitch");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void **, size_t *, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMallocPitch");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, pitch, width, height);
}

extern __host__ cudaError_t CUDARTAPI cudaMallocArray(
		cudaArray_t *array, const struct cudaChannelFormatDesc *desc, size_t width,
		size_t height, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaMallocArray wrapper called\n");
	//system("touch /home/cptjack/cudaMallocArray");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaArray_t *,
											 const struct cudaChannelFormatDesc *,
											 size_t, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMallocArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(array, desc, width, height, flags);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaFree(void *devPtr) {
#ifdef TRACE_API_CALL
	printf("cudaFree wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFree");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr);
}

extern __host__ cudaError_t CUDARTAPI cudaFreeHost(void *ptr) {
#ifdef TRACE_API_CALL
	printf("cudaFreeHost wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFreeHost");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ptr);
}

extern __host__ cudaError_t CUDARTAPI cudaFreeArray(cudaArray_t array) {
#ifdef TRACE_API_CALL
	printf("cudaFreeArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaArray_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFreeArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(array);
}

extern __host__ cudaError_t CUDARTAPI
cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray) {
#ifdef TRACE_API_CALL
	printf("cudaFreeMipmappedArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaMipmappedArray_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaFreeMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(mipmappedArray);
}

extern __host__ cudaError_t CUDARTAPI cudaHostAlloc(void **pHost, size_t size,
													unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaHostAlloc wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void **, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaHostAlloc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pHost, size, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaHostRegister(void *ptr, size_t size,
													   unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaHostRegister wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, size_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaHostRegister");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ptr, size, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaHostUnregister(void *ptr) {
#ifdef TRACE_API_CALL
	printf("cudaHostUnregister wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaHostUnregister");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ptr);
}

extern __host__ cudaError_t CUDARTAPI
cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaHostGetDevicePointer wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void **, void *, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaHostGetDevicePointer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pDevice, pHost, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaHostGetFlags(unsigned int *pFlags,
													   void *pHost) {
#ifdef TRACE_API_CALL
	printf("cudaHostGetFlags wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(unsigned int *, void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaHostGetFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pFlags, pHost);
}

extern __host__ cudaError_t CUDARTAPI
cudaMalloc3D(struct cudaPitchedPtr *pitchedDevPtr, struct cudaExtent extent) {
#ifdef TRACE_API_CALL
	printf("cudaMalloc3D wrapper called\n");
	//system("touch /home/cptjack/cudaMalloc3D");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(struct cudaPitchedPtr *, struct cudaExtent);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMalloc3D");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pitchedDevPtr, extent);
}

extern __host__ cudaError_t CUDARTAPI
cudaMalloc3DArray(cudaArray_t *array, const struct cudaChannelFormatDesc *desc,
				  struct cudaExtent extent, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaMalloc3DArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaArray_t *,
											 const struct cudaChannelFormatDesc *,
											 struct cudaExtent, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMalloc3DArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(array, desc, extent, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaMallocMipmappedArray(
		cudaMipmappedArray_t *mipmappedArray,
		const struct cudaChannelFormatDesc *desc, struct cudaExtent extent,
		unsigned int numLevels, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaMallocMipmappedArray wrapper called\n");
	//system("touch /home/cptjack/cudaMallocMipMappedArray");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			cudaMipmappedArray_t *, const struct cudaChannelFormatDesc *,
			struct cudaExtent, unsigned int, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMallocMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(mipmappedArray, desc, extent, numLevels, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaGetMipmappedArrayLevel(
		cudaArray_t *levelArray, cudaMipmappedArray_const_t mipmappedArray,
		unsigned int level) {
#ifdef TRACE_API_CALL
	printf("cudaGetMipmappedArrayLevel wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			cudaArray_t *, cudaMipmappedArray_const_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetMipmappedArrayLevel");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(levelArray, mipmappedArray, level);
}

extern __host__ cudaError_t CUDARTAPI
cudaMemcpy3D(const struct cudaMemcpy3DParms *p) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy3D wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const struct cudaMemcpy3DParms *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy3D");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(p);
}

extern __host__ cudaError_t CUDARTAPI
cudaMemcpy3DPeer(const struct cudaMemcpy3DPeerParms *p) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy3DPeer wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const struct cudaMemcpy3DPeerParms *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy3DPeer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(p);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemcpy3DAsync(
		const struct cudaMemcpy3DParms *p, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy3DAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const struct cudaMemcpy3DParms *, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy3DAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(p, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy3DPeerAsync(
		const struct cudaMemcpy3DPeerParms *p, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy3DPeerAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const struct cudaMemcpy3DPeerParms *,
											 cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy3DPeerAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(p, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemGetInfo(size_t *free,
													 size_t *total) {
#ifdef TRACE_API_CALL
	printf("cudaMemGetInfo wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(size_t *, size_t *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemGetInfo");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(free, total);
}

extern __host__ cudaError_t CUDARTAPI
cudaArrayGetInfo(struct cudaChannelFormatDesc *desc, struct cudaExtent *extent,
				 unsigned int *flags, cudaArray_t array) {
#ifdef TRACE_API_CALL
	printf("cudaArrayGetInfo wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(struct cudaChannelFormatDesc *,
											 struct cudaExtent *, unsigned int *,
											 cudaArray_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaArrayGetInfo");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(desc, extent, flags, array);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy(void *dst, const void *src,
												 size_t count,
												 enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, const void *, size_t,
											 enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, src, count, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyPeer(void *dst, int dstDevice,
													 const void *src,
													 int srcDevice,
													 size_t count) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyPeer wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void *, int, const void *, int, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyPeer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, dstDevice, src, srcDevice, count);
}

extern __host__ cudaError_t CUDARTAPI
cudaMemcpyToArray(cudaArray_t dst, size_t wOffset, size_t hOffset,
				  const void *src, size_t count, enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyToArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			cudaArray_t, size_t, size_t, const void *, size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyToArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, wOffset, hOffset, src, count, kind);
}

extern __host__ cudaError_t CUDARTAPI
cudaMemcpyFromArray(void *dst, cudaArray_const_t src, size_t wOffset,
					size_t hOffset, size_t count, enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyFromArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, cudaArray_const_t, size_t,
											 size_t, size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyFromArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, src, wOffset, hOffset, count, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyArrayToArray(
		cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst,
		cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count,
		enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyArrayToArray wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaArray_t, size_t, size_t, cudaArray_const_t,
							 size_t, size_t, size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyArrayToArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc,
					count, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2D(void *dst, size_t dpitch,
												   const void *src,
												   size_t spitch, size_t width,
												   size_t height,
												   enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy2D wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, size_t, const void *, size_t,
											 size_t, size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy2D");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, dpitch, src, spitch, width, height, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArray(
		cudaArray_t dst, size_t wOffset, size_t hOffset, const void *src,
		size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy2DToArray wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaArray_t, size_t, size_t, const void *,
							 size_t, size_t, size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy2DToArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, wOffset, hOffset, src, spitch, width, height, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArray(
		void *dst, size_t dpitch, cudaArray_const_t src, size_t wOffset,
		size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy2DFromArray wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void *, size_t, cudaArray_const_t, size_t,
							 size_t, size_t, size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy2DFromArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, dpitch, src, wOffset, hOffset, width, height, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DArrayToArray(
		cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst,
		cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width,
		size_t height, enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy2DArrayToArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaArray_t, size_t, size_t,
											 cudaArray_const_t, size_t, size_t,
											 size_t, size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy2DArrayToArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc,
					width, height, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbol(
		const void *symbol, const void *src, size_t count, size_t offset,
		enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyToSymbol wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void *, const void *, size_t,
											 size_t, enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyToSymbol");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(symbol, src, count, offset, kind);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbol(
		void *dst, const void *symbol, size_t count, size_t offset,
		enum cudaMemcpyKind kind) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyFromSymbol wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, const void *, size_t, size_t,
											 enum cudaMemcpyKind);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyFromSymbol");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, symbol, count, offset, kind);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaMemcpyAsync(void *dst, const void *src, size_t count,
				enum cudaMemcpyKind kind, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, const void *, size_t,
											 enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, src, count, kind, stream);
}

extern __host__ cudaError_t CUDARTAPI
cudaMemcpyPeerAsync(void *dst, int dstDevice, const void *src, int srcDevice,
					size_t count, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyPeerAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, int, const void *, int,
											 size_t, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyPeerAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, dstDevice, src, srcDevice, count, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyToArrayAsync(
		cudaArray_t dst, size_t wOffset, size_t hOffset, const void *src,
		size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyToArrayAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaArray_t, size_t, size_t, const void *,
							 size_t, enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyToArrayAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, wOffset, hOffset, src, count, kind, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromArrayAsync(
		void *dst, cudaArray_const_t src, size_t wOffset, size_t hOffset,
		size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyFromArrayAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void *, cudaArray_const_t, size_t, size_t,
							 size_t, enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyFromArrayAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, src, wOffset, hOffset, count, kind, stream);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemcpy2DAsync(
		void *dst, size_t dpitch, const void *src, size_t spitch, size_t width,
		size_t height, enum cudaMemcpyKind kind, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy2DAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void *, size_t, const void *, size_t, size_t,
							 size_t, enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy2DAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, dpitch, src, spitch, width, height, kind, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArrayAsync(
		cudaArray_t dst, size_t wOffset, size_t hOffset, const void *src,
		size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind,
		cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy2DToArrayAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaArray_t, size_t, size_t,
											 const void *, size_t, size_t, size_t,
											 enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy2DToArrayAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, wOffset, hOffset, src, spitch, width, height, kind,
					stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArrayAsync(
		void *dst, size_t dpitch, cudaArray_const_t src, size_t wOffset,
		size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind,
		cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpy2DFromArrayAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, size_t, cudaArray_const_t,
											 size_t, size_t, size_t, size_t,
											 enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpy2DFromArrayAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, dpitch, src, wOffset, hOffset, width, height, kind,
					stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbolAsync(
		const void *symbol, const void *src, size_t count, size_t offset,
		enum cudaMemcpyKind kind, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyToSymbolAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const void *, const void *, size_t, size_t,
							 enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyToSymbolAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(symbol, src, count, offset, kind, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbolAsync(
		void *dst, const void *symbol, size_t count, size_t offset,
		enum cudaMemcpyKind kind, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemcpyFromSymbolAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, const void *, size_t, size_t,
											 enum cudaMemcpyKind, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemcpyFromSymbolAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(dst, symbol, count, offset, kind, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaMemset(void *devPtr, int value,
												 size_t count) {
#ifdef TRACE_API_CALL
	printf("cudaMemset wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, int, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemset");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, value, count);
}

extern __host__ cudaError_t CUDARTAPI cudaMemset2D(void *devPtr, size_t pitch,
												   int value, size_t width,
												   size_t height) {
#ifdef TRACE_API_CALL
	printf("cudaMemset2D wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, size_t, int, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemset2D");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, pitch, value, width, height);
}

extern __host__ cudaError_t CUDARTAPI cudaMemset3D(
		struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent) {
#ifdef TRACE_API_CALL
	printf("cudaMemset3D wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(struct cudaPitchedPtr, int, struct cudaExtent);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemset3D");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pitchedDevPtr, value, extent);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI cudaMemsetAsync(
		void *devPtr, int value, size_t count, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemsetAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, int, size_t, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemsetAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, value, count, stream);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaMemset2DAsync(void *devPtr, size_t pitch, int value, size_t width,
				  size_t height, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemset2DAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void *, size_t, int, size_t, size_t,
											 cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemset2DAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, pitch, value, width, height, stream);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaMemset3DAsync(struct cudaPitchedPtr pitchedDevPtr, int value,
				  struct cudaExtent extent, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemset3DAsync wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(struct cudaPitchedPtr, int,
											 struct cudaExtent, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemset3DAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pitchedDevPtr, value, extent, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaGetSymbolAddress(void **devPtr,
														   const void *symbol) {
#ifdef TRACE_API_CALL
	printf("cudaGetSymbolAddress wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(void **, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetSymbolAddress");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, symbol);
}

extern __host__ cudaError_t CUDARTAPI cudaGetSymbolSize(size_t *size,
														const void *symbol) {
#ifdef TRACE_API_CALL
	printf("cudaGetSymbolSize wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(size_t *, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetSymbolSize");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(size, symbol);
}

extern __host__ cudaError_t CUDARTAPI
cudaMemPrefetchAsync(const void *devPtr, size_t count, int dstDevice,
					 cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaMemPrefetchAsync wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const void *, size_t, int, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemPrefetchAsync");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, count, dstDevice, stream);
}

extern __host__ cudaError_t CUDARTAPI
cudaMemAdvise(const void *devPtr, size_t count, enum cudaMemoryAdvise advice,
			  int device) {
#ifdef TRACE_API_CALL
	printf("cudaMemAdvise wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void *, size_t,
											 enum cudaMemoryAdvise, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemAdvise");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, count, advice, device);
}

extern __host__ cudaError_t CUDARTAPI cudaMemRangeGetAttribute(
		void *data, size_t dataSize, enum cudaMemRangeAttribute attribute,
		const void *devPtr, size_t count) {
#ifdef TRACE_API_CALL
	printf("cudaMemRangeGetAttribute wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			void *, size_t, enum cudaMemRangeAttribute, const void *, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemRangeGetAttribute");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(data, dataSize, attribute, devPtr, count);
}

extern __host__ cudaError_t CUDARTAPI cudaMemRangeGetAttributes(
		void **data, size_t *dataSizes, enum cudaMemRangeAttribute *attributes,
		size_t numAttributes, const void *devPtr, size_t count) {
#ifdef TRACE_API_CALL
	printf("cudaMemRangeGetAttributes wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void **, size_t *, enum cudaMemRangeAttribute *,
							 size_t, const void *, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaMemRangeGetAttributes");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(data, dataSizes, attributes, numAttributes, devPtr, count);
}

extern __host__ cudaError_t CUDARTAPI cudaPointerGetAttributes(
		struct cudaPointerAttributes *attributes, const void *ptr) {
#ifdef TRACE_API_CALL
	printf("cudaPointerGetAttributes wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(struct cudaPointerAttributes *, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaPointerGetAttributes");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(attributes, ptr);
}

extern __host__ cudaError_t CUDARTAPI
cudaDeviceCanAccessPeer(int *canAccessPeer, int device, int peerDevice) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceCanAccessPeer wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *, int, int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceCanAccessPeer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(canAccessPeer, device, peerDevice);
}

extern __host__ cudaError_t CUDARTAPI
cudaDeviceEnablePeerAccess(int peerDevice, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceEnablePeerAccess wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceEnablePeerAccess");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(peerDevice, flags);
}

extern __host__ cudaError_t CUDARTAPI
cudaDeviceDisablePeerAccess(int peerDevice) {
#ifdef TRACE_API_CALL
	printf("cudaDeviceDisablePeerAccess wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDeviceDisablePeerAccess");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(peerDevice);
}

extern __host__ cudaError_t CUDARTAPI
cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource) {
#ifdef TRACE_API_CALL
	printf("cudaGraphicsUnregisterResource wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaGraphicsResource_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGraphicsUnregisterResource");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(resource);
}

extern __host__ cudaError_t CUDARTAPI cudaGraphicsResourceSetMapFlags(
		cudaGraphicsResource_t resource, unsigned int flags) {
#ifdef TRACE_API_CALL
	printf("cudaGraphicsResourceSetMapFlags wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaGraphicsResource_t, unsigned int);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGraphicsResourceSetMapFlags");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(resource, flags);
}

extern __host__ cudaError_t CUDARTAPI cudaGraphicsMapResources(
		int count, cudaGraphicsResource_t *resources, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaGraphicsMapResources wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(int, cudaGraphicsResource_t *, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGraphicsMapResources");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(count, resources, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaGraphicsUnmapResources(
		int count, cudaGraphicsResource_t *resources, cudaStream_t stream) {
#ifdef TRACE_API_CALL
	printf("cudaGraphicsUnmapResources wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(int, cudaGraphicsResource_t *, cudaStream_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGraphicsUnmapResources");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(count, resources, stream);
}

extern __host__ cudaError_t CUDARTAPI cudaGraphicsResourceGetMappedPointer(
		void **devPtr, size_t *size, cudaGraphicsResource_t resource) {
#ifdef TRACE_API_CALL
	printf("cudaGraphicsResourceGetMappedPointer wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(void **, size_t *, cudaGraphicsResource_t);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaGraphicsResourceGetMappedPointer");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(devPtr, size, resource);
}

extern __host__ cudaError_t CUDARTAPI cudaGraphicsSubResourceGetMappedArray(
		cudaArray_t *array, cudaGraphicsResource_t resource,
		unsigned int arrayIndex, unsigned int mipLevel) {
#ifdef TRACE_API_CALL
	printf("cudaGraphicsSubResourceGetMappedArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			cudaArray_t *, cudaGraphicsResource_t, unsigned int, unsigned int);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaGraphicsSubResourceGetMappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(array, resource, arrayIndex, mipLevel);
}

extern __host__ cudaError_t CUDARTAPI
cudaGraphicsResourceGetMappedMipmappedArray(
		cudaMipmappedArray_t *mipmappedArray, cudaGraphicsResource_t resource) {
#ifdef TRACE_API_CALL
	printf("cudaGraphicsResourceGetMappedMipmappedArray wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(cudaMipmappedArray_t *, cudaGraphicsResource_t);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaGraphicsResourceGetMappedMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(mipmappedArray, resource);
}

extern __host__ cudaError_t CUDARTAPI cudaGetChannelDesc(
		struct cudaChannelFormatDesc *desc, cudaArray_const_t array) {
#ifdef TRACE_API_CALL
	printf("cudaGetChannelDesc wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(struct cudaChannelFormatDesc *,
											 cudaArray_const_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetChannelDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(desc, array);
}

extern __host__ cudaError_t CUDARTAPI cudaBindTexture(
		size_t *offset, const struct textureReference *texref, const void *devPtr,
		const struct cudaChannelFormatDesc *desc, size_t size) {
#ifdef TRACE_API_CALL
	printf("cudaBindTexture wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			size_t *, const struct textureReference *, const void *,
			const struct cudaChannelFormatDesc *, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaBindTexture");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(offset, texref, devPtr, desc, size);
}

extern __host__ cudaError_t CUDARTAPI
cudaBindTexture2D(size_t *offset, const struct textureReference *texref,
				  const void *devPtr, const struct cudaChannelFormatDesc *desc,
				  size_t width, size_t height, size_t pitch) {
#ifdef TRACE_API_CALL
	printf("cudaBindTexture2D wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			size_t *, const struct textureReference *, const void *,
			const struct cudaChannelFormatDesc *, size_t, size_t, size_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaBindTexture2D");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(offset, texref, devPtr, desc, width, height, pitch);
}

extern __host__ cudaError_t CUDARTAPI cudaBindTextureToArray(
		const struct textureReference *texref, cudaArray_const_t array,
		const struct cudaChannelFormatDesc *desc) {
#ifdef TRACE_API_CALL
	printf("cudaBindTextureToArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			const struct textureReference *, cudaArray_const_t,
			const struct cudaChannelFormatDesc *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaBindTextureToArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(texref, array, desc);
}

extern __host__ cudaError_t CUDARTAPI
cudaBindTextureToMipmappedArray(const struct textureReference *texref,
								cudaMipmappedArray_const_t mipmappedArray,
								const struct cudaChannelFormatDesc *desc) {
#ifdef TRACE_API_CALL
	printf("cudaBindTextureToMipmappedArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			const struct textureReference *, cudaMipmappedArray_const_t,
			const struct cudaChannelFormatDesc *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaBindTextureToMipmappedArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(texref, mipmappedArray, desc);
}

extern __host__ cudaError_t CUDARTAPI
cudaUnbindTexture(const struct textureReference *texref) {
#ifdef TRACE_API_CALL
	printf("cudaUnbindTexture wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const struct textureReference *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaUnbindTexture");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(texref);
}

extern __host__ cudaError_t CUDARTAPI cudaGetTextureAlignmentOffset(
		size_t *offset, const struct textureReference *texref) {
#ifdef TRACE_API_CALL
	printf("cudaGetTextureAlignmentOffset wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(size_t *, const struct textureReference *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetTextureAlignmentOffset");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(offset, texref);
}

extern __host__ cudaError_t CUDARTAPI cudaGetTextureReference(
		const struct textureReference **texref, const void *symbol) {
#ifdef TRACE_API_CALL
	printf("cudaGetTextureReference wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const struct textureReference **, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetTextureReference");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(texref, symbol);
}

extern __host__ cudaError_t CUDARTAPI cudaBindSurfaceToArray(
		const struct surfaceReference *surfref, cudaArray_const_t array,
		const struct cudaChannelFormatDesc *desc) {
#ifdef TRACE_API_CALL
	printf("cudaBindSurfaceToArray wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			const struct surfaceReference *, cudaArray_const_t,
			const struct cudaChannelFormatDesc *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaBindSurfaceToArray");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(surfref, array, desc);
}

extern __host__ cudaError_t CUDARTAPI cudaGetSurfaceReference(
		const struct surfaceReference **surfref, const void *symbol) {
#ifdef TRACE_API_CALL
	printf("cudaGetSurfaceReference wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(const struct surfaceReference **, const void *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetSurfaceReference");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(surfref, symbol);
}

extern __host__ cudaError_t CUDARTAPI cudaCreateTextureObject(
		cudaTextureObject_t *pTexObject, const struct cudaResourceDesc *pResDesc,
		const struct cudaTextureDesc *pTexDesc,
		const struct cudaResourceViewDesc *pResViewDesc) {
#ifdef TRACE_API_CALL
	printf("cudaCreateTextureObject wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(
			cudaTextureObject_t *, const struct cudaResourceDesc *,
			const struct cudaTextureDesc *, const struct cudaResourceViewDesc *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaCreateTextureObject");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pTexObject, pResDesc, pTexDesc, pResViewDesc);
}

extern __host__ cudaError_t CUDARTAPI
cudaDestroyTextureObject(cudaTextureObject_t texObject) {
#ifdef TRACE_API_CALL
	printf("cudaDestroyTextureObject wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaTextureObject_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDestroyTextureObject");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(texObject);
}

extern __host__ cudaError_t CUDARTAPI cudaGetTextureObjectResourceDesc(
		struct cudaResourceDesc *pResDesc, cudaTextureObject_t texObject) {
#ifdef TRACE_API_CALL
	printf("cudaGetTextureObjectResourceDesc wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(struct cudaResourceDesc *, cudaTextureObject_t);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaGetTextureObjectResourceDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pResDesc, texObject);
}

extern __host__ cudaError_t CUDARTAPI cudaGetTextureObjectTextureDesc(
		struct cudaTextureDesc *pTexDesc, cudaTextureObject_t texObject) {
#ifdef TRACE_API_CALL
	printf("cudaGetTextureObjectTextureDesc wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(struct cudaTextureDesc *, cudaTextureObject_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetTextureObjectTextureDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pTexDesc, texObject);
}

extern __host__ cudaError_t CUDARTAPI cudaGetTextureObjectResourceViewDesc(
		struct cudaResourceViewDesc *pResViewDesc, cudaTextureObject_t texObject) {
#ifdef TRACE_API_CALL
	printf("cudaGetTextureObjectResourceViewDesc wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(struct cudaResourceViewDesc *,
											 cudaTextureObject_t);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaGetTextureObjectResourceViewDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pResViewDesc, texObject);
}

extern __host__ cudaError_t CUDARTAPI cudaCreateSurfaceObject(
		cudaSurfaceObject_t *pSurfObject, const struct cudaResourceDesc *pResDesc) {
#ifdef TRACE_API_CALL
	printf("cudaCreateSurfaceObject wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaSurfaceObject_t *,
											 const struct cudaResourceDesc *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaCreateSurfaceObject");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pSurfObject, pResDesc);
}

extern __host__ cudaError_t CUDARTAPI
cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject) {
#ifdef TRACE_API_CALL
	printf("cudaDestroySurfaceObject wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(cudaSurfaceObject_t);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDestroySurfaceObject");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(surfObject);
}

extern __host__ cudaError_t CUDARTAPI cudaGetSurfaceObjectResourceDesc(
		struct cudaResourceDesc *pResDesc, cudaSurfaceObject_t surfObject) {
#ifdef TRACE_API_CALL
	printf("cudaGetSurfaceObjectResourceDesc wrapper called\n");
#endif
	using FuncPtr =
	cudaError_t(CUDARTAPI *)(struct cudaResourceDesc *, cudaSurfaceObject_t);
	static auto func_ptr =
			LoadSymbol<FuncPtr>("cudaGetSurfaceObjectResourceDesc");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(pResDesc, surfObject);
}

extern __host__ cudaError_t CUDARTAPI cudaDriverGetVersion(int *driverVersion) {
#ifdef TRACE_API_CALL
	printf("cudaDriverGetVersion wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaDriverGetVersion");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(driverVersion);
}

extern __host__ __cudart_builtin__ cudaError_t CUDARTAPI
cudaRuntimeGetVersion(int *runtimeVersion) {
#ifdef TRACE_API_CALL
	printf("cudaRuntimeGetVersion wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(int *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaRuntimeGetVersion");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(runtimeVersion);
}

extern __host__ cudaError_t CUDARTAPI cudaGetExportTable(
		const void **ppExportTable, const cudaUUID_t *pExportTableId) {
#ifdef TRACE_API_CALL
	printf("cudaGetExportTable wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(const void **, const cudaUUID_t *);
	static auto func_ptr = LoadSymbol<FuncPtr>("cudaGetExportTable");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(ppExportTable, pExportTableId);
}
}  // extern "C"
//CUDA 10.0 APIs ends

extern "C" {

// Following are private symbols in libcudart that got inserted by nvcc.

extern void CUDARTAPI __cudaInitModule() {
#ifdef TRACE_API_CALL
	printf("cudaInitModule wrapper called\n");
#endif
}

extern void CUDARTAPI __cudaRegisterFunction(
		void **fatCubinHandle, const char *hostFun, char *deviceFun,
		const char *deviceName, int thread_limit, uint3 *tid, uint3 *bid,
		dim3 *bDim, dim3 *gDim, int *wSize) {
#ifdef TRACE_API_CALL
	printf("cudaRegisterFunction wrapper called\n");
#endif
	using FuncPtr = void (CUDARTAPI *)(void **fatCubinHandle, const char *hostFun,
									   char *deviceFun, const char *deviceName,
									   int thread_limit, uint3 *tid, uint3 *bid,
									   dim3 *bDim, dim3 *gDim, int *wSize);
	static auto func_ptr = LoadSymbol<FuncPtr>("__cudaRegisterFunction");
	if (!func_ptr) return;
	func_ptr(fatCubinHandle, hostFun, deviceFun, deviceName, thread_limit, tid,
			 bid, bDim, gDim, wSize);
}

extern void CUDARTAPI __cudaUnregisterFatBinary(void **fatCubinHandle) {
#ifdef TRACE_API_CALL
	printf("cudaUnregisterFatBinary wrapper called\n");
#endif
	using FuncPtr = void (CUDARTAPI *)(void **fatCubinHandle);
	static auto func_ptr = LoadSymbol<FuncPtr>("__cudaUnregisterFatBinary");
	if (!func_ptr) return;
	func_ptr(fatCubinHandle);
}

extern void CUDARTAPI __cudaRegisterVar(void **fatCubinHandle, char *hostVar,
										char *deviceAddress,
										const char *deviceName, int ext,
										size_t size, int constant, int global) {
#ifdef TRACE_API_CALL
	printf("cudaRegisterVar wrapper called\n");
#endif
	using FuncPtr = void (CUDARTAPI *)(
			void **fatCubinHandle, char *hostVar, char *deviceAddress,
			const char *deviceName, int ext, size_t size, int constant, int global);
	static auto func_ptr = LoadSymbol<FuncPtr>("__cudaRegisterVar");
	if (!func_ptr) return;
	func_ptr(fatCubinHandle, hostVar, deviceAddress, deviceName, ext, size,
			 constant, global);
}

extern void **CUDARTAPI __cudaRegisterFatBinary(void *fatCubin) {
#ifdef TRACE_API_CALL
	printf("cudaRegisterFatBinary wrapper called\n");
#endif
	using FuncPtr = void **(CUDARTAPI *)(void *fatCubin);
	static auto func_ptr = LoadSymbol<FuncPtr>("__cudaRegisterFatBinary");
	if (!func_ptr) return nullptr;
	return (void **) func_ptr(fatCubin);
}

extern cudaError_t CUDARTAPI __cudaPopCallConfiguration(dim3 *gridDim,
														dim3 *blockDim,
														size_t *sharedMem,
														void *stream) {
#ifdef TRACE_API_CALL
	printf("cudaPopCallConfiguration wrapper called\n");
#endif
	using FuncPtr = cudaError_t(CUDARTAPI *)(dim3 *gridDim, dim3 *blockDim,
											 size_t *sharedMem, void *stream);
	static auto func_ptr = LoadSymbol<FuncPtr>("__cudaPopCallConfiguration");
	if (!func_ptr) return GetSymbolNotFoundError();
	return func_ptr(gridDim, blockDim, sharedMem, stream);
}

extern __host__ __device__ unsigned CUDARTAPI __cudaPushCallConfiguration(
		dim3 gridDim, dim3 blockDim, size_t sharedMem = 0, void *stream = 0) {
#ifdef TRACE_API_CALL
	printf("cudaPushCallConfiguration wrapper called\n");
#endif
	using FuncPtr = unsigned (CUDARTAPI *)(dim3 gridDim, dim3 blockDim,
										   size_t sharedMem, void *stream);
	static auto func_ptr = LoadSymbol<FuncPtr>("__cudaPushCallConfiguration");
	if (!func_ptr) return 0;
	return func_ptr(gridDim, blockDim, sharedMem, stream);
}

}  // extern "C"
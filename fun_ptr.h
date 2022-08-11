#ifndef __FUNC_PTR_H__
#define __FUNC_PTR_H__

template <typename ret, typename ...params>
using function_t = ret (*)(params ...args);

template <typename ret, typename obj, typename ...params>
using method_t = ret (obj::*)(params ...args);

#endif //__FUNC_PTR_H__
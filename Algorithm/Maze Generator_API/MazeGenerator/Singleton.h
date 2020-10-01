#pragma once

template <class T>

class CSingleton
{
public:
	static T *ms_pSingleton;


public:
	CSingleton()
	{
		unsigned __int64 ulOffset = (unsigned __int64)((T*)(1)) - (unsigned __int64)((CSingleton<T>*)(T*)1);

		ms_pSingleton = (T*)((unsigned __int64)this + ulOffset);
	}
	
	virtual ~CSingleton()
	{
		ms_pSingleton = 0;
	}

	static T* GetSingleton()
	{
		return4(ms_pSingleton);
	}
};

template <class T> T* CSingleton<T>::ms_pSingleton = 0;
#ifndef UTILS_H
#define UTILS_H


template<typename T>
inline void DeletePointer(T* a_pObject)
{
	if (a_pObject != nullptr)
	{
		delete a_pObject;
		a_pObject == nullptr;
	}
}


#endif // !UTILS_H



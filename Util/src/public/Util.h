#pragma once
#include <utility>

/*
	일반 생성 방법
	UniquePtr<T> Ptr = UniquePtr<T>(new T());

	Make 팩토리 함수
	UniquePtr<T> Ptr = Make_Functions<T>(value of T); 
*/

namespace KKJ
{

template <typename T>
class UniquePtr
{
public:
	explicit UniquePtr(T* InPtr = nullptr) : PrimitivePtr(InPtr) {}

	// 복사 방지
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	// 이동 생성자
	UniquePtr(const UniquePtr&& Rhs) noexcept : PrimitivePtr(Rhs.PrimitivePtr)
	{
		Rhs.PrimitivePtr = nullptr;
	}
	UniquePtr& operator=(UniquePtr&& Rhs) noexcept
	{
		if (this != &Rhs)
		{
			delete PrimitivePtr;
			PrimitivePtr = Rhs.PrimitivePtr;
			Rhs.PrimitivePtr = nullptr;
		}
		return *this;
	}

	~UniquePtr()
	{
		delete PrimitivePtr;
	}

	// 포인터 연산자 기능 구현
	T& operator*() const { return *PrimitivePtr; }
	T* operator->() const { return PrimitivePtr; }

	// 소유권 Handle
	void Reset(T* InPtr = nullptr)
	{
		delete PrimitivePtr;
		PrimitivePtr = InPtr;
		InPtr = nullptr;
	}
	T* Get() const
	{
		return PrimitivePtr;
	}

private:
	T* PrimitivePtr;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* InPtr) : PrimitivePtr(InPtr) { RefCount = new int(1); }

	// 복사 연산 허용
	SharedPtr(const SharedPtr& InSharedPtr) : PrimitivePtr(InSharedPtr.PrimitivePtr), RefCount(InSharedPtr.RefCount)
	{
		++(*RefCount);
	}
	SharedPtr& operator=(const SharedPtr& InSharedPtr)
	{
		if (this != &InSharedPtr)
		{
			PrimitivePtr = InSharedPtr.PrimitivePtr;
			RefCount = InSharedPtr.RefCount;
			++(*RefCount);
		}
		return *this;
	}

	// 이동 연산 제거
	SharedPtr(const SharedPtr&&) = delete;
	SharedPtr& operator=(const SharedPtr&&) = delete;
		
	~SharedPtr()
	{
		--(*RefCount);
		if (*RefCount == 0)
		{
			delete PrimitivePtr;
			delete RefCount;
		}
	}

	// 포인터 연산자 기능
	T& operator*() const { return *PrimitivePtr; }
	T* operator->() const { return PrimitivePtr; }

	// 소유권 Handle
	T* Get() const
	{
		return PrimitivePtr;
	}

private:
	T* PrimitivePtr;
	int* RefCount;
};


template <typename T, typename... Args>
UniquePtr<T> Make_Unique(Args&&... args)
{
	return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

template <typename T, typename... Args>
SharedPtr<T> Make_Shared(Args&&... args)
{
	return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

}
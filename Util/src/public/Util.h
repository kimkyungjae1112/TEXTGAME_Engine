#pragma once
#include <utility>

/*
	�Ϲ� ���� ���
	UniquePtr<T> Ptr = UniquePtr<T>(new T());

	Make ���丮 �Լ�
	UniquePtr<T> Ptr = Make_Functions<T>(value of T); 
*/

namespace KKJ
{

template <typename T>
class UniquePtr
{
public:
	explicit UniquePtr(T* InPtr = nullptr) : PrimitivePtr(InPtr) {}

	// ���� ����
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	// �̵� ������
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

	// ������ ������ ��� ����
	T& operator*() const { return *PrimitivePtr; }
	T* operator->() const { return PrimitivePtr; }

	// ������ Handle
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

	// ���� ���� ���
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

	// �̵� ���� ����
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

	// ������ ������ ���
	T& operator*() const { return *PrimitivePtr; }
	T* operator->() const { return PrimitivePtr; }

	// ������ Handle
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

#pragma once





class __attribute__((lockable)) cCriticalSection
{
public:
	cCriticalSection(void);
	~cCriticalSection();

	void Lock(void) __attribute__((exclusive_lock_function));
	void Unlock(void) __attribute__((unlock_function));
	
	#ifdef _DEBUG
	bool IsLocked(void);
	bool IsLockedByCurrentThread(void);
	#endif  // _DEBUG
	
private:
	#ifdef _DEBUG
	int           m_IsLocked;  // Number of times this CS is locked
	unsigned long m_OwningThreadID;
	#endif  // _DEBUG
	
	#ifdef _WIN32
		CRITICAL_SECTION m_CriticalSection;
	#else  // _WIN32
		pthread_mutex_t     m_CriticalSection;
		pthread_mutexattr_t m_Attributes;
	#endif  // else _WIN32
} ALIGN_8;




/// RAII for cCriticalSection - locks the CS on creation, unlocks on destruction
class cCSLock
{
	cCriticalSection * m_CS;

	// Unlike a cCriticalSection, this object should be used from a single thread, therefore access to m_IsLocked is not threadsafe
	// In Windows, it is an error to call cCriticalSection::Unlock() multiple times if the lock is not held, 
	// therefore we need to check this value whether we are locked or not.
	bool m_IsLocked;
	
public:
	cCSLock(cCriticalSection * a_CS);
	cCSLock(cCriticalSection & a_CS);
	~cCSLock();
	
	// Temporarily unlock or re-lock:
	void Lock(void) __attribute__((exclusive_lock_function(m_CS)));
	void Unlock(void)  __attribute__((unlock_function(m_CS)));

private:
	DISALLOW_COPY_AND_ASSIGN(cCSLock);
} ;





/// Temporary RAII unlock for a cCSLock. Useful for unlock-wait-relock scenarios
class cCSUnlock
{
	cCSLock & m_Lock;
public:
	cCSUnlock(cCSLock & a_Lock);
	~cCSUnlock();
	
private:
	DISALLOW_COPY_AND_ASSIGN(cCSUnlock);
} ;





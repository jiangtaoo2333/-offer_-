#include<stdio.h>
#include<string.h>

class CMyString {
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
	CMyString& operator=(const CMyString& str);
private:
	char* m_pData;
};

CMyString& CMyString::operator=(const CMyString& str) {

	if (this == &str) {
		return *this;
	}
	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	m_pData = str.m_pData;

	return *this;
}

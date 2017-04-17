#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//==============================================================================
class YuVector {
private:
	double mE1;
	double mE2;
	double mE3;
public:
	YuVector();

	YuVector(bool pDiag);

	YuVector(const YuVector& pVec);

	YuVector(double pE1, double pE2, double pE3);

	~YuVector();

	double getE1() const { return mE1; };

	double getE2() const { return mE2; };

	double getE3() const { return mE3; };

	double getLength() const;

	void setE1(double pE1) { mE1 = pE1; };

	void setE2(double pE2) { mE2 = pE2; };

	void setE3(double pE3) { mE3 = pE3; };

	void show() const;

	friend YuVector operator+(const YuVector& pLeftVec, const YuVector& pRightVec);

	friend YuVector operator-(const YuVector& pLeftVec, const YuVector& pRightVec);

	friend double operator*(const YuVector& pLeftVec, const YuVector& pRightVec);

	const YuVector& operator=(const YuVector& pVec);
};
//==============================================================================
class YuVectorListItem {
private:
	YuVector* mVec;
	YuVectorListItem* mNext;
	YuVectorListItem* mPrev;
public:
	YuVectorListItem();

	YuVectorListItem(const YuVector& pVec);

	YuVectorListItem(YuVector* pVec);

	~YuVectorListItem();

	YuVector* getVector() const { return mVec; };

	YuVectorListItem* getNext() const { return mNext; };

	YuVectorListItem* getPrev() const { return mPrev; };

	void setVector(const YuVector& pVec) { mVec = new YuVector(pVec); };

	void setVector(YuVector* pVec) { mVec = pVec; };

	void setNext(YuVectorListItem* pNext) { mNext = pNext; };

	void setPrev(YuVectorListItem* pPrev) { mPrev = pPrev; };

};
//==============================================================================
class YuVectorList {
private:
	size_t mLength;
	YuVectorListItem* mFirst;
	YuVectorListItem* mCurr;
	mutable YuVectorListItem* mCursor;
public:
	YuVectorList();

	~YuVectorList();

	size_t getLength() const { return mLength; };

	YuVectorListItem* getFirstItem() const { return mFirst; };

	YuVectorListItem* getCurrentItem() const { return mCurr; };

	void add(const YuVector& pVec);

	void add(const YuVector& pVec, size_t pIndex);

	void add(YuVector* pVec);

	void add(YuVector* pVec, size_t pIndex);

	void show() const;

	YuVectorListItem* operator[] (size_t pIndex) const;
};
//==============================================================================

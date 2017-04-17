#include "YuVector.h"
//==============================================================================
//initialize list
YuVector::YuVector() : mE1(0.0), mE2(0.0), mE3(0.0) {};
//==============================================================================
YuVector::YuVector(bool pDiag){
	if (pDiag == true) {
		cout << "¬ведите координату e1: ";
		cin >> mE1;
		cout << "¬ведите координату e2: ";
		cin >> mE2;
		cout << "¬ведите координату e3: ";
		cin >> mE3;
	}
	else {
		mE1 = 0.0;
		mE2 = 0.0;
		mE3 = 0.0;
	}
};
//==============================================================================
YuVector::YuVector(const YuVector& pVec) : mE1(pVec.getE1()), mE2(pVec.getE2()), mE3(pVec.getE3()) {};
//==============================================================================
YuVector::YuVector(double pE1, double pE2, double pE3) :mE1(pE1), mE2(pE2), mE3(pE3) {};
//==============================================================================
YuVector::~YuVector() {
	mE1 = 0.0;
	mE2 = 0.0;
	mE3 = 0.0;
}
//==============================================================================
double YuVector::getLength() const {
	return sqrt(pow(mE1, 2) + pow(mE2, 2) + pow(mE3, 2));
};
//==============================================================================
void YuVector::show() const {
	cout << "[" << this << "] vector's components:" << endl;
	cout << "e1 = " << mE1 << endl;
	cout << "e2 = " << mE2 << endl;
	cout << "e3 = " << mE3 << endl;
	cout << endl;
};
//==============================================================================
YuVector operator+(const YuVector& pLeftVec, const YuVector& pRightVec) {
	return YuVector(
		pLeftVec.getE1() + pRightVec.getE1(),
		pLeftVec.getE2() + pRightVec.getE2(),
		pLeftVec.getE3() + pRightVec.getE3()
		);
};
//==============================================================================
YuVector operator-(const YuVector& pLeftVec, const YuVector& pRightVec) {
	return YuVector(
		pLeftVec.getE1() - pRightVec.getE1(),
		pLeftVec.getE2() - pRightVec.getE2(),
		pLeftVec.getE3() - pRightVec.getE3()
		);
};
//==============================================================================
double operator*(const YuVector& pLeftVec, const YuVector& pRightVec) {
	return double(
		(pLeftVec.getE1() * pRightVec.getE1()) +
		(pLeftVec.getE2() * pRightVec.getE2()) +
		(pLeftVec.getE3() * pRightVec.getE3())
		);
};
//==============================================================================
const YuVector& YuVector::operator=(const YuVector& pVec) {
	this->mE1 = pVec.getE1();
	this->mE2 = pVec.getE2();
	this->mE3 = pVec.getE3();
	return *this;
}
//==============================================================================
YuVectorListItem::YuVectorListItem() :mVec(new YuVector()), mNext(NULL), mPrev(NULL) {}
//==============================================================================
YuVectorListItem::YuVectorListItem(const YuVector& pVec) : mVec(new YuVector(pVec)), mNext(NULL), mPrev(NULL) {};
//==============================================================================
YuVectorListItem::YuVectorListItem(YuVector* pVec) :mVec(pVec), mNext(NULL), mPrev(NULL) {}
//==============================================================================
YuVectorListItem::~YuVectorListItem() {
	mVec->~YuVector();
	mNext = mPrev = NULL;
}
//==============================================================================
YuVectorList::YuVectorList() :mLength(0), mFirst(NULL), mCurr(NULL), mCursor(NULL) {};
//==============================================================================
YuVectorList::~YuVectorList() {
	//@BUG
	for (size_t i = (mLength - 1); i >= 0; i--) {
		(*this)[i]->~YuVectorListItem();
		mLength--;
	}
	mLength = 0;
	mFirst = mCurr = mCursor = NULL;
}
//==============================================================================
void YuVectorList::add(const YuVector& pVec, size_t pIndex) {
	if (pIndex < 0 || pIndex > mLength) {
		return;
	}
	if (mLength == 0) {
		YuVectorListItem* vItem = new YuVectorListItem(pVec);
		mFirst = vItem;
		mCurr = vItem;
		mLength++;
	}
	else if (mLength > 0) {
		if (pIndex == 0) {
			YuVectorListItem* vItem = new YuVectorListItem(pVec);
			vItem->setNext(mFirst);
			mFirst->setPrev(vItem);
			mFirst = vItem;
			mLength++;
		}
		else if (pIndex < mLength) {
			YuVectorListItem* vItem = new YuVectorListItem(pVec);
			(*this)[pIndex]->setPrev(vItem);
			vItem->setNext((*this)[pIndex]);
			vItem->setPrev((*this)[pIndex - 1]);
			(*this)[pIndex - 1]->setNext(vItem);
			mLength++;
		}
		else if (pIndex == mLength) {
			YuVectorListItem* vItem = new YuVectorListItem(pVec);
			mCurr->setNext(vItem);
			vItem->setPrev(mCurr);
			mCurr = vItem;
			mLength++;
		}
	}
}
//==============================================================================
void YuVectorList::add(const YuVector& pVec) {
	add(pVec, mLength);
}
//==============================================================================
void YuVectorList::add(YuVector* pVec, size_t pIndex) {
	if (pIndex < 0 || pIndex > mLength) {
		return;
	}
	if (mLength == 0) {
		YuVectorListItem* vItem = new YuVectorListItem(pVec);
		mFirst = vItem;
		mCurr = vItem;
		mLength++;
	}
	else if (mLength > 0) {
		if (pIndex == 0) {
			YuVectorListItem* vItem = new YuVectorListItem(pVec);
			vItem->setNext(mFirst);
			mFirst->setPrev(vItem);
			mFirst = vItem;
			mLength++;
		}
		else if (pIndex < mLength) {
			YuVectorListItem* vItem = new YuVectorListItem(pVec);
			(*this)[pIndex]->setPrev(vItem);
			vItem->setNext((*this)[pIndex]);
			vItem->setPrev((*this)[pIndex - 1]);
			(*this)[pIndex - 1]->setNext(vItem);
			mLength++;
		}
		else if (pIndex == mLength) {
			YuVectorListItem* vItem = new YuVectorListItem(pVec);
			mCurr->setNext(vItem);
			vItem->setPrev(mCurr);
			mCurr = vItem;
			mLength++;
		}
	}
}
//==============================================================================
void YuVectorList::add(YuVector* pVec) {
	add(pVec, mLength);
}
//==============================================================================
YuVectorListItem* YuVectorList::operator[] (size_t pIndex) const {
	if (pIndex < mLength && pIndex >= 0) {
		mCursor = this->getFirstItem();
		for (size_t i = 0; i < pIndex; i++) {
			mCursor = mCursor->getNext();
		}
		return mCursor;
	}
	else {
		return NULL;
	}
}
//==============================================================================
void YuVectorList::show() const{
	mCursor = this->getFirstItem();
	if (mCursor != NULL) {
		for (size_t i = 0; i < mLength; i++) {
			cout << i + 1 << "-й вектор списка" << endl;
			mCursor->getVector()->show();
			mCursor = mCursor->getNext();
		};
	}
	else {
		cout << "—писок пуст" << endl;
	}
}
//==============================================================================
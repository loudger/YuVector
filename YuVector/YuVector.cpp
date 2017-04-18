#include "YuVector.h"
//==============================================================================
//initialize list
YuVector::YuVector() : mE1(0.0), mE2(0.0), mE3(0.0) {};
//==============================================================================
YuVector::YuVector(bool pDiag){
	if (pDiag == true) {
		cout << "������� ���������� e1: ";
		cin >> mE1;
		cout << "������� ���������� e2: ";
		cin >> mE2;
		cout << "������� ���������� e3: ";
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
	cout << "[0x" << this << "]" << endl;
	cout << "e1 = " << mE1 << endl;
	cout << "e2 = " << mE2 << endl;
	cout << "e3 = " << mE3 << endl;
	//cout << endl;
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
	size_t i = 0;
	while (mLength > 1) {
		mCursor = mFirst;
		mFirst = mFirst->getNext();
		mFirst->setPrev(NULL);
		mLength--;
		mCursor->~YuVectorListItem();
		i++;
	}
	if (mLength == 1) {
		mLength--;
		mFirst->~YuVectorListItem();
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
void YuVectorList::remove(size_t pIndex) {
	if (mLength > 1) {
		if (pIndex == 0) {
			mCursor = this->getFirstItem();
			mCursor->getNext()->setPrev(NULL);
			mCursor->~YuVectorListItem();
			mLength--;
		}
		else if (pIndex == (mLength - 1)) {
			mCursor = this->getCurrentItem();
			mCursor->getPrev()->setNext(NULL);
			mCursor->~YuVectorListItem();
			mLength--;
		}
		else if ((pIndex > 0) && (pIndex < (mLength - 1))) {
			mCursor = this->getFirstItem();
			for (size_t i = 0; i < pIndex; i++) {
				mCursor = mCursor->getNext();
			};
			mCursor->getPrev()->setNext(mCursor->getNext());
			mCursor->getNext()->setPrev(mCursor->getPrev());
			mCursor->~YuVectorListItem();
			mLength--;
		}
		else {
			; // error code
		}
	}
	else if (mLength == 1) {
		this->getFirstItem()->~YuVectorListItem();
		mLength--;
	}
	else {
		; // empty list
	}
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
			cout << i + 1 << "-� ������ ������" << endl;
			mCursor->getVector()->show();
			mCursor = mCursor->getNext();
		};
	}
	else {
		cout << "������ ����" << endl;
	}
}
//==============================================================================
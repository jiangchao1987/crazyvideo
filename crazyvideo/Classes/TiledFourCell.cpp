#include "TiledFourCell.h"

bool TiledFourCell::init() {
    iLeftTop = 0; // ���Ͻ�
    iLeftBottom = 0;// ���½�
    iRightTop = 0; // ���Ͻ�
    iRightBottom = 0; // ���½�

    return true;
}

void TiledFourCell::setiLeftTop( int _iLeftTop ) {
    iLeftTop = _iLeftTop;
}

int TiledFourCell::getiLeftTop() {
    return iLeftTop;
}

void TiledFourCell::setiLeftBottom( int _iLeftBottom ) {
    iLeftBottom = _iLeftBottom;
}

int TiledFourCell::getiLeftBottom() {
    return iLeftBottom;
}

void TiledFourCell::setiRightTop( int _iRightTop ) {
    iRightTop = _iRightTop;
}

int TiledFourCell::getiRightTop() {
    return iRightTop;
}

void TiledFourCell::setiRightBottom( int _iRightBottom ) {
    iRightBottom = _iRightBottom;
}

int TiledFourCell::getiRightBottom() {
    return iRightBottom;
}

int TiledFourCell::getiTotalNum() {
    return (iLeftTop + iLeftBottom + iRightTop + iRightBottom);
}
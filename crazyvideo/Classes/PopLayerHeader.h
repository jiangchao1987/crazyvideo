//
//  PopLayerHeader.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-20.
//
//

#ifndef crazyvideo_PopLayerHeader_h
#define crazyvideo_PopLayerHeader_h

#include "PopUpShareLayer.h"
#include "PopUpWrongLayer.h"
#include "PopUpBombLayer.h"
#include "PopUpRightLayer.h"
#include "PopUpNoBombLayer.h"
#include "PopCanNotUseBombLayer.h"
#include "PopUpGoldNotEnough.h"

#define POPUPSHARELAYER_TAG  324234
#define POPUPWRONGLAYER_TAG  (POPUPSHARELAYER_TAG + 1)
#define POPUPRIGHTLAYER_TAG  (POPUPSHARELAYER_TAG + 2)
#define POPUPBOMBLAYER_TAG  (POPUPSHARELAYER_TAG + 3)
#define POPUPNOBOMBLAYER_TAG  (POPUPSHARELAYER_TAG + 4)
#define POPUPNOCANNOTUSEBOMBLAYER_TAG  (POPUPSHARELAYER_TAG + 5)
#define POPUPNOGOLDNOTENOUGHLAYER_TAG  (POPUPSHARELAYER_TAG + 6)

#endif

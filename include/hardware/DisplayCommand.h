/*
* Copyright (C) 2012 Freescale Semiconductor, Inc. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef ANDROID_DISPLAY_COMMAND_H
#define ANDROID_DISPLAY_COMMAND_H

#include <stdint.h>
#include <sys/types.h>
#include <binder/Parcel.h>
#include <utils/Errors.h>
#include <utils/String16.h>

//namespace android {
using namespace android;

enum DISPLAY_OPERATE_CODE {
    OPERATE_CODE_ENABLE = 0x1000,
    OPERATE_CODE_DISABLE = 0x2000,
    OPERATE_CODE_CHANGE = 0x4000,
    OPERATE_CODE_INVALIDE = 0x8000,

    OPERATE_CODE_CHANGE_RESOLUTION = 0x1,
    OPERATE_CODE_CHANGE_OVERSCAN = 0x2,
    OPERATE_CODE_CHANGE_MIRROR = 0x4,
    OPERATE_CODE_CHANGE_COLORDEPTH = 0x8,
    OPERATE_CODE_CHANGE_ROTATION = 0x10,
};

struct configParam {
    configParam() : displayId(-1), operateCode(OPERATE_CODE_INVALIDE),
      rotation(0), overScan(0), mirror(0), colorDepth(0), mode()
    {
    }

    status_t write(Parcel& output) const;
    status_t read(const Parcel& input);
    int displayId;
    int operateCode; //operate code: enable, change or disable display.
    //int width;
    //int height;
    int rotation;
    int overScan;
    int mirror;
    int colorDepth;
    String16 mode;
};

//};
#endif


﻿/**
 * Tencent is pleased to support the open source community by making Tars available.
 *
 * Copyright (C) 2016THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this file except 
 * in compliance with the License. You may obtain a copy of the License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software distributed 
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the 
 * specific language governing permissions and limitations under the License.
 */

#include "HelloImp.h"
#include "servant/Application.h"
#include "servant/TarsCookie.h"

using namespace std;

//////////////////////////////////////////////////////
void HelloImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void HelloImp::destroy()
{
    //destroy servant here:
    //...
}

int HelloImp::testHello(const std::string &sReq, std::string &sRsp, tars::TarsCurrentPtr current)
{
    TLOGDEBUG("HelloImp::testHellosReq:"<<sReq<<endl);

    map<string, string> & cookie = TarsCookieOp::getCookie();
    TLOGDEBUG("cookie:" << TC_Common::tostr(cookie.begin(), cookie.end()) << endl);

    TLOGDEBUG("msgno:" << cookie["msgno"] << endl);
    TLOGDEBUG("uid:" << cookie["uid"] << endl);

    {
        map<string, string> & cookie = current->getCookie();
        TLOGDEBUG("current cookie:" << TC_Common::tostr(cookie.begin(), cookie.end()) << endl);
    }

    sRsp = sReq;

    return 0;
}


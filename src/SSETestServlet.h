/**
 * Copyright (c) 2015 - The CM Authors <legal@clickmatcher.com>
 *   All Rights Reserved.
 *
 * This file is CONFIDENTIAL -- Distribution or duplication of this material or
 * the information contained herein is strictly forbidden unless prior written
 * permission is obtained.
 */
#ifndef _CM_SSETESTSERVLET_H
#define _CM_SSETESTSERVLET_H
#include "fnord-http/httpservice.h"

using namespace fnord;

namespace cm {

class SSETestServlet : public http::StreamingHTTPService {
public:

  void handleHTTPRequest(
      http::HTTPRequestStream* req,
      http::HTTPResponseStream* res);

  bool streamRequestBody() override {
    return "false";
  }

};

}
#endif

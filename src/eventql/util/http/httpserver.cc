/**
 * Copyright (c) 2016 DeepCortex GmbH <legal@eventql.io>
 * Authors:
 *   - Paul Asmuth <paul@eventql.io>
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License ("the license") as
 * published by the Free Software Foundation, either version 3 of the License,
 * or any later version.
 *
 * In accordance with Section 7(e) of the license, the licensing of the Program
 * under the license does not imply a trademark license. Therefore any rights,
 * title and interest in our trademarks remain entirely with us.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You can be released from the requirements of the license by purchasing a
 * commercial license. Buying such a license is mandatory as soon as you develop
 * commercial activities involving this program without disclosing the source
 * code of your own applications
 */
#include <eventql/util/exception.h>
#include <eventql/util/inspect.h>
#include <eventql/util/logging.h>
#include <eventql/util/wallclock.h>
#include "eventql/util/http/httpserverconnection.h"
#include <eventql/util/http/httpserver.h>

/*
TODO:
  - timeouts
  - httpconnection -> httpserverconnection
  - eventloop
  - 100 continue
  - chunked encoding
  - https
*/

namespace http {

HTTPServer::HTTPServer(
    HTTPHandlerFactory* handler_factory,
    TaskScheduler* scheduler) :
    handler_factory_(handler_factory),
    scheduler_(scheduler),
    ssock_(scheduler) {
  ssock_.onConnection([this] (std::unique_ptr<net::TCPConnection> conn) {
    HTTPServerConnection::start(
        handler_factory_,
        std::move(conn),
        scheduler_,
        &stats_);
  });
}

void HTTPServer::listen(int port) {
  logNotice("http.server", "Starting HTTP server on port $0", port);
  ssock_.listen(port);
}

HTTPServerStats* HTTPServer::stats() {
  return &stats_;
}

}

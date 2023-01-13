#include "server.hpp"
#include <oatpp/core/base/Environment.hpp>

class Handler : public oatpp::web::server::HttpRequestHandler 
{
    public:
    /**
    * Handle incoming request and return outgoing response.
    */
        std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
            return ResponseFactory::createResponse(Status::CODE_200, "Hello World!");
        }

};

void run(void) 
{
  /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();
    router->route("GET", "/hello", std::make_shared<Handler>());
 /* Create HTTP connection handler with router */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

  /* Create TCP connection provider */
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 4040, oatpp::network::Address::IP_4});

  /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

  /* Print info about server port */
    OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

  /* Run server */
    server.run();
}

int main()
{
    oatpp::base::Environment::init();
    run();
    oatpp::base::Environment::destroy();


    return 0;
}

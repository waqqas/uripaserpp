#include "uriparserpp/uriparserpp.hpp"

namespace uriparserpp;

TEST_CASE("Parsing")
{
   uri uri("http://www.google.com/");

   REQUIRE(uri.scheme() == "http");
   REQUIRE(uri.host() == "www.google.com");
   REQUIRE(uri.path() == "/");
}
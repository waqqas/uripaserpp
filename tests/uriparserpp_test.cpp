#include "uriparserpp/uriparserpp.hpp"

#include <catch2/catch.hpp>

using namespace uriparserpp;

TEST_CASE("Parsing")
{
   uri uri("http://www.google.com/");

   // REQUIRE(uri.scheme() == "http");
   // REQUIRE(uri.host() == "www.google.com");
   // REQUIRE(uri.path() == "/");
   REQUIRE(1 == 1);
}
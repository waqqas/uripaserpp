#include "uriparserpp/uriparserpp.hpp"

#include <catch2/catch.hpp>
#include <sstream>

using namespace uriparserpp;

TEST_CASE("Parsing")
{
   uri uri("http://user:pass@www.test.com:81/static/index.html?q=books#fragment");

   REQUIRE(uri.scheme() == "http");
   REQUIRE(uri.host() == "www.test.com");
   REQUIRE(uri.port() == "81");
   std::stringstream ss;
   ss << uri.path();
   REQUIRE(ss.str() == "/static/index.html");
}

TEST_CASE("Prepend in path")
{
   uri uri("http://www.test.com:81/static/index.html");

   auto path = uri.path();
   path.push_front("abc");
   std::stringstream ss;
   ss << path;
   REQUIRE(ss.str() == "/abc/static/index.html");
}

TEST_CASE("Append in path")
{
   uri uri("http://www.test.com:81/static/index.html");

   auto path = uri.path();
   path.push_back("abc");
   std::stringstream ss;
   ss << path;
   REQUIRE(ss.str() == "/static/index.html/abc");
}
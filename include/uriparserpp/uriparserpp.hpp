#ifndef URI_PARSER_PP_H
#define URI_PARSER_PP_H

#include <string>
#include <uriparser/Uri.h>

namespace uriparserpp {
class uri
{
 private:
   UriUriA _url;

 public:
   uri(const std::string &url)
   {
      if (uriParseSingleUriA(&_url, url.c_str(), NULL) != URI_SUCCESS)
      {
         throw std::invalid_argument("Invalid url");
      }
   }
   uri(const uri &) = delete;             // non construction-copyable
   uri &operator=(const uri &) = delete;  // non copyable
   ~uri()
   {
      uriFreeUriMembersA(&_url);
   }
};
}  // namespace uriparserpp

#endif

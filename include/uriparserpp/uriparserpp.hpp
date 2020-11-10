#ifndef URI_PARSER_PP_H
#define URI_PARSER_PP_H

#include <list>
#include <stdexcept>
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

   std::string scheme()
   {
      if (_url.scheme.first != NULL && _url.scheme.afterLast != NULL)
      {
         return std::string(_url.scheme.first, _url.scheme.afterLast);
      }
      return "";
   }

   std::string host()
   {
      if (_url.hostText.first != NULL && _url.hostText.afterLast != NULL)
      {
         return std::string(_url.hostText.first, _url.hostText.afterLast);
      }
      return "";
   }

   std::string port()
   {
      if (_url.portText.first != NULL && _url.portText.afterLast != NULL)
      {
         return std::string(_url.portText.first, _url.portText.afterLast);
      }
      return "";
   }

   std::string path()
   {
      std::string            path = "";
      std::list<std::string> pathSegments;

      for (auto segment = _url.pathHead; segment != NULL; segment = segment->next)
      {
         if (segment->text.first != NULL && segment->text.afterLast != NULL)
         {
            pathSegments.push_back(std::string(segment->text.first, segment->text.afterLast));
         }
      }
      std::for_each(pathSegments.begin(), pathSegments.end(), [&path](const auto &segment) { path += "/" + segment; });

      return path;
   }

   ~uri()
   {
      uriFreeUriMembersA(&_url);
   }
};
}  // namespace uriparserpp

#endif

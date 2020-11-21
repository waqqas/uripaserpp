#ifndef URI_PARSER_PP_H
#define URI_PARSER_PP_H

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <uriparser/Uri.h>

namespace uriparserpp {

class path
{
 private:
   std::list<std::string_view> _segments;

 public:
   friend std::ostream &operator<<(std::ostream &os, const path &);

   void push_back(std::string_view const &segment)
   {
      _segments.push_back(segment);
   }
   void push_front(std::string_view const &segment)
   {
      _segments.push_front(segment);
   }
};

std::ostream &operator<<(std::ostream &os, const path &path)
{
   std::for_each(path._segments.cbegin(), path._segments.cend(),
                 [&os](const std::string_view &segment) { os << '/' << segment; });

   return os;
}

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

   path path()
   {
      uriparserpp::path p;

      for (auto segment = _url.pathHead; segment != NULL; segment = segment->next)
      {
         if (segment->text.first != NULL && segment->text.afterLast != NULL)
         {
            p.push_back(std::string_view(segment->text.first, (segment->text.afterLast - segment->text.first)));
         }
      }

      return p;
   }

   ~uri()
   {
      uriFreeUriMembersA(&_url);
   }
};
}  // namespace uriparserpp

#endif

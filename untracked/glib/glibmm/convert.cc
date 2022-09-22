// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!


#include <glibmm.h>

#include <glibmm/convert.h>
#include <glibmm/private/convert_p.h>


/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

//#include <glib/gtestutils.h> //For g_assert() in glib >= 2.15.0
//#include <glib/gmessages.h> //For g_assert() in glib < 2.15.0
#include <glib.h> //For g_assert() in all versions of glib.

#include <glibmm/utility.h>

namespace Glib
{

/**** Glib::IConv **********************************************************/

IConv::IConv(const std::string& to_codeset, const std::string& from_codeset)
: gobject_(g_iconv_open(to_codeset.c_str(), from_codeset.c_str()))
{
  if (gobject_ == reinterpret_cast<GIConv>(-1))
  {
    GError* gerror = nullptr;

    // Abuse g_convert() to create a GError object.  This may seem a weird
    // thing to do, but it gives us consistently translated error messages
    // at no further cost.
    g_convert("", 0, to_codeset.c_str(), from_codeset.c_str(), nullptr, nullptr, &gerror);

    // If this should ever fail we're fucked.
    g_assert(gerror != nullptr);

    if (gerror)
      ::Glib::Error::throw_exception(gerror);
  }
}

IConv::IConv(GIConv gobject) : gobject_(gobject)
{
}

IConv::~IConv()
{
  g_iconv_close(gobject_);
}

std::size_t
IConv::iconv(char** inbuf, gsize* inbytes_left, char** outbuf, gsize* outbytes_left)
{
  return g_iconv(gobject_, inbuf, inbytes_left, outbuf, outbytes_left);
}

void
IConv::reset()
{
  // Apparently iconv() on Solaris <= 7 segfaults if you pass in
  // NULL for anything but inbuf; work around that. (NULL outbuf
  // or NULL *outbuf is allowed by Unix98.)

  char* outbuf = nullptr;
  gsize inbytes_left = 0;
  gsize outbytes_left = 0;

  g_iconv(gobject_, nullptr, &inbytes_left, &outbuf, &outbytes_left);
}

std::string
IConv::convert(const std::string& str)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_convert_with_iconv(str.data(), str.size(), gobject_, nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

/**** charset conversion functions *****************************************/

bool
get_charset()
{
  return g_get_charset(nullptr);
}

bool
get_charset(std::string& charset)
{
  const char* charset_cstr = nullptr;
  const bool is_utf8 = g_get_charset(&charset_cstr);

  charset = charset_cstr;
  return is_utf8;
}

std::string
convert(const std::string& str, const std::string& to_codeset, const std::string& from_codeset)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf = g_convert(str.data(), str.size(), to_codeset.c_str(), from_codeset.c_str(),
    nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

std::string
convert_with_fallback(
  const std::string& str, const std::string& to_codeset, const std::string& from_codeset)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf = g_convert_with_fallback(str.data(), str.size(), to_codeset.c_str(),
    from_codeset.c_str(), nullptr, nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

std::string
convert_with_fallback(const std::string& str, const std::string& to_codeset,
  const std::string& from_codeset, const Glib::ustring& fallback)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf = g_convert_with_fallback(str.data(), str.size(), to_codeset.c_str(),
    from_codeset.c_str(), const_cast<char*>(fallback.c_str()), nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

Glib::ustring
locale_to_utf8(const std::string& opsys_string)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_locale_to_utf8(opsys_string.data(), opsys_string.size(), nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  const auto scoped_buf = make_unique_ptr_gfree(buf);
  return Glib::ustring(scoped_buf.get(), scoped_buf.get() + bytes_written);
}

std::string
locale_from_utf8(const Glib::ustring& utf8_string)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_locale_from_utf8(utf8_string.data(), utf8_string.bytes(), nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

Glib::ustring
filename_to_utf8(const std::string& opsys_string)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_filename_to_utf8(opsys_string.data(), opsys_string.size(), nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  const auto scoped_buf = make_unique_ptr_gfree(buf);
  return Glib::ustring(scoped_buf.get(), scoped_buf.get() + bytes_written);
}

std::string
filename_from_utf8(const Glib::ustring& utf8_string)
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_filename_from_utf8(utf8_string.data(), utf8_string.bytes(), nullptr, &bytes_written, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

std::string
filename_from_uri(const Glib::ustring& uri, Glib::ustring& hostname)
{
  char* hostname_buf = nullptr;
  GError* gerror = nullptr;

  char* const buf = g_filename_from_uri(uri.c_str(), &hostname_buf, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  // Let's take ownership at this point.
  const auto scoped_buf = make_unique_ptr_gfree(buf);

  if (hostname_buf)
    hostname = make_unique_ptr_gfree(buf).get();
  else
    hostname.erase();

  return std::string(scoped_buf.get());
}

std::string
filename_from_uri(const Glib::ustring& uri)
{
  GError* gerror = nullptr;
  char* const buf = g_filename_from_uri(uri.c_str(), nullptr, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get());
}

Glib::ustring
filename_to_uri(const std::string& filename, const Glib::ustring& hostname)
{
  GError* gerror = nullptr;
  char* const buf = g_filename_to_uri(filename.c_str(), hostname.c_str(), &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return Glib::ustring(make_unique_ptr_gfree(buf).get());
}

Glib::ustring
filename_to_uri(const std::string& filename)
{
  GError* gerror = nullptr;
  char* const buf = g_filename_to_uri(filename.c_str(), nullptr, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return Glib::ustring(make_unique_ptr_gfree(buf).get());
}

Glib::ustring
filename_display_basename(const std::string& filename)
{
  char* const buf = g_filename_display_basename(filename.c_str());

  return Glib::ustring(make_unique_ptr_gfree(buf).get());
}

Glib::ustring
filename_display_name(const std::string& filename)
{
  char* const buf = g_filename_display_name(filename.c_str());

  return Glib::ustring(make_unique_ptr_gfree(buf).get());
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::ConvertError::ConvertError(Glib::ConvertError::Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (G_CONVERT_ERROR, error_code, error_message)
{}

Glib::ConvertError::ConvertError(GError* gobject)
:
  Glib::Error (gobject)
{}

Glib::ConvertError::Code Glib::ConvertError::code() const
{
  return static_cast<Code>(Glib::Error::code());
}

void Glib::ConvertError::throw_func(GError* gobject)
{
  throw Glib::ConvertError(gobject);
}



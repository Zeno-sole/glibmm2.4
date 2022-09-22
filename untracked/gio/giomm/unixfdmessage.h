// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!
#ifndef _GIOMM_UNIXFDMESSAGE_H
#define _GIOMM_UNIXFDMESSAGE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The giomm Development Team
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

#include <glibmm/arrayhandle.h>
#include <giomm/socketcontrolmessage.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixFDMessage = struct _GUnixFDMessage;
using GUnixFDMessageClass = struct _GUnixFDMessageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API UnixFDMessage_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API UnixFDList;

/** UnixFDMessage — A GSocketControlMessage containing a GUnixFDList.
 * This SocketControlMessage contains a UnixFDList. It may be sent using
 * Gio::Socket::send() and received using Gio::Socket::receive() over
 * UNIX sockets (ie: sockets in the Gio::SOCKET_ADDRESS_UNIX family). The file
 * descriptors are copied between processes by the kernel.
 *
 * For an easier way to send and receive file descriptors over stream-oriented
 * UNIX sockets, see Gio::UnixConnection::send_fd() and
 * Gio::UnixConnection::receive_fd().
 *
 * @ingroup NetworkIO
 * @newin{2,28}
 */

class GIOMM_API UnixFDMessage : public SocketControlMessage
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = UnixFDMessage;
  using CppClassType = UnixFDMessage_Class;
  using BaseObjectType = GUnixFDMessage;
  using BaseClassType = GUnixFDMessageClass;

  // noncopyable
  UnixFDMessage(const UnixFDMessage&) = delete;
  UnixFDMessage& operator=(const UnixFDMessage&) = delete;

private:  friend class UnixFDMessage_Class;
  static CppClassType unixfdmessage_class_;

protected:
  explicit UnixFDMessage(const Glib::ConstructParams& construct_params);
  explicit UnixFDMessage(GUnixFDMessage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  UnixFDMessage(UnixFDMessage&& src) noexcept;
  UnixFDMessage& operator=(UnixFDMessage&& src) noexcept;

  ~UnixFDMessage() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GUnixFDMessage*       gobj()       { return reinterpret_cast<GUnixFDMessage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GUnixFDMessage* gobj() const { return reinterpret_cast<GUnixFDMessage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GUnixFDMessage* gobj_copy();

private:

  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


protected:
  UnixFDMessage();
    explicit UnixFDMessage(const Glib::RefPtr<UnixFDList>& fd_list);


public:
  
  /** Creates a new UnixFDMessage containing an empty file descriptor
   * list.
   * 
   * @newin{2,22}
   * 
   * @return A new UnixFDMessage.
   */

  
  static Glib::RefPtr<UnixFDMessage> create();


  /** Creates a new UnixFDMessage containing @a list.
   * 
   * @newin{2,24}
   * 
   * @param fd_list A UnixFDList.
   * @return A new UnixFDMessage.
   */

  
  static Glib::RefPtr<UnixFDMessage> create(const Glib::RefPtr<UnixFDList>& fd_list);


  /** Gets the UnixFDList contained in @a message.  This function does not
   * return a reference to the caller, but the returned list is valid for
   * the lifetime of @a message.
   * 
   * @newin{2,24}
   * 
   * @return The UnixFDList from @a message.
   */
  Glib::RefPtr<UnixFDList> get_fd_list();
  
  /** Gets the UnixFDList contained in @a message.  This function does not
   * return a reference to the caller, but the returned list is valid for
   * the lifetime of @a message.
   * 
   * @newin{2,24}
   * 
   * @return The UnixFDList from @a message.
   */
  Glib::RefPtr<const UnixFDList> get_fd_list() const;

  
  /** Adds a file descriptor to @a message.
   * 
   * The file descriptor is duplicated using dup(). You keep your copy
   * of the descriptor and the copy contained in @a message will be closed
   * when @a message is finalized.
   * 
   * A possible cause of failure is exceeding the per-process or
   * system-wide file descriptor limit.
   * 
   * @newin{2,22}
   * 
   * @param fd A valid open file descriptor.
   * @return <tt>true</tt> in case of success, else <tt>false</tt> (and @a error is set).
   * 
   * @throws Glib::Error
   */
  bool append_fd(int fd);

  /** Returns the array of file descriptors that is contained in this object.
   *
   * After this call, the descriptors are no longer contained in message.
   * Further calls will return an empty list (unless more descriptors have
   * been added).
   *
   * The caller is responsible for closing all of the file descriptors.
   *
   * @return An array of file descriptors.
   *
   * @newin{2,28}
   */
  Glib::ArrayHandle<int> steal_fds();
  

  /** The GUnixFDList object to send with the message.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<UnixFDList> > property_fd_list() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::UnixFDMessage
   */
  GIOMM_API
  Glib::RefPtr<Gio::UnixFDMessage> wrap(GUnixFDMessage* object, bool take_copy = false);
}


#endif /* _GIOMM_UNIXFDMESSAGE_H */


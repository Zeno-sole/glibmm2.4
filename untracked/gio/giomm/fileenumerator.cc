// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/fileenumerator.h>
#include <giomm/private/fileenumerator_p.h>


/* Copyright (C) 2007 The gtkmm Development Team
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

#include <gio/gio.h>
#include <giomm/file.h>
#include <glibmm/error.h>
#include <glibmm/exceptionhandler.h>
#include <giomm/slot_async.h>

namespace Gio
{

void
FileEnumerator::next_files_async(const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, int num_files, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_next_files_async(gobj(), num_files, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

void
FileEnumerator::next_files_async(const SlotAsyncReady& slot, int num_files, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_next_files_async(gobj(), num_files, io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

void
FileEnumerator::close_async(
  int io_priority, const Glib::RefPtr<Cancellable>& cancellable, const SlotAsyncReady& slot)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_close_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
FileEnumerator::close_async(int io_priority, const SlotAsyncReady& slot)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_file_enumerator_close_async(gobj(), io_priority,
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::FileEnumerator> wrap(GFileEnumerator* object, bool take_copy)
{
  return Glib::RefPtr<Gio::FileEnumerator>( dynamic_cast<Gio::FileEnumerator*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& FileEnumerator_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileEnumerator_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_file_enumerator_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void FileEnumerator_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* FileEnumerator_Class::wrap_new(GObject* object)
{
  return new FileEnumerator((GFileEnumerator*)object);
}


/* The implementation: */

GFileEnumerator* FileEnumerator::gobj_copy()
{
  reference();
  return gobj();
}

FileEnumerator::FileEnumerator(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

FileEnumerator::FileEnumerator(GFileEnumerator* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


FileEnumerator::FileEnumerator(FileEnumerator&& src) noexcept
: Glib::Object(std::move(src))
{}

FileEnumerator& FileEnumerator::operator=(FileEnumerator&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


FileEnumerator::~FileEnumerator() noexcept
{}


FileEnumerator::CppClassType FileEnumerator::fileenumerator_class_; // initialize static member

GType FileEnumerator::get_type()
{
  return fileenumerator_class_.init().get_type();
}


GType FileEnumerator::get_base_type()
{
  return g_file_enumerator_get_type();
}


Glib::RefPtr<FileInfo> FileEnumerator::next_file(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  Glib::RefPtr<FileInfo> retvalue = Glib::wrap(g_file_enumerator_next_file(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<FileInfo> FileEnumerator::next_file()
{
  GError* gerror = nullptr;
  Glib::RefPtr<FileInfo> retvalue = Glib::wrap(g_file_enumerator_next_file(gobj(), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool FileEnumerator::close(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  bool retvalue = g_file_enumerator_close(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool FileEnumerator::close()
{
  GError* gerror = nullptr;
  bool retvalue = g_file_enumerator_close(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::ListHandle< Glib::RefPtr<FileInfo> > FileEnumerator::next_files_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  Glib::ListHandle< Glib::RefPtr<FileInfo> > retvalue = Glib::ListHandle< Glib::RefPtr<FileInfo> >((g_file_enumerator_next_files_finish(gobj(), Glib::unwrap(result), &(gerror))), Glib::OWNERSHIP_DEEP);
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool FileEnumerator::close_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  bool retvalue = g_file_enumerator_close_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool FileEnumerator::is_closed() const
{
  return g_file_enumerator_is_closed(const_cast<GFileEnumerator*>(gobj()));
}

bool FileEnumerator::has_pending() const
{
  return g_file_enumerator_has_pending(const_cast<GFileEnumerator*>(gobj()));
}

void FileEnumerator::set_pending(bool pending)
{
  g_file_enumerator_set_pending(gobj(), static_cast<int>(pending));
}

Glib::RefPtr<File> FileEnumerator::get_container()
{
  Glib::RefPtr<File> retvalue = Glib::wrap(g_file_enumerator_get_container(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const File> FileEnumerator::get_container() const
{
  Glib::RefPtr<const File> retvalue = Glib::wrap(g_file_enumerator_get_container(const_cast<GFileEnumerator*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<File> FileEnumerator::get_child(const Glib::RefPtr<FileInfo>& info)
{
  return Glib::wrap(g_file_enumerator_get_child(gobj(), Glib::unwrap(info)));
}

Glib::RefPtr<const File> FileEnumerator::get_child(const Glib::RefPtr<FileInfo>& info) const
{
  return Glib::wrap(g_file_enumerator_get_child(const_cast<GFileEnumerator*>(gobj()), Glib::unwrap(info)));
}


} // namespace Gio



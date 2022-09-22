// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/simpleiostream.h>
#include <giomm/private/simpleiostream_p.h>


/* Copyright (C) 2015 The giomm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::SimpleIOStream> wrap(GSimpleIOStream* object, bool take_copy)
{
  return Glib::RefPtr<Gio::SimpleIOStream>( dynamic_cast<Gio::SimpleIOStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& SimpleIOStream_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SimpleIOStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_simple_io_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void SimpleIOStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* SimpleIOStream_Class::wrap_new(GObject* object)
{
  return new SimpleIOStream((GSimpleIOStream*)object);
}


/* The implementation: */

GSimpleIOStream* SimpleIOStream::gobj_copy()
{
  reference();
  return gobj();
}

SimpleIOStream::SimpleIOStream(const Glib::ConstructParams& construct_params)
:
  Gio::IOStream(construct_params)
{

}

SimpleIOStream::SimpleIOStream(GSimpleIOStream* castitem)
:
  Gio::IOStream((GIOStream*)(castitem))
{}


SimpleIOStream::SimpleIOStream(SimpleIOStream&& src) noexcept
: Gio::IOStream(std::move(src))
{}

SimpleIOStream& SimpleIOStream::operator=(SimpleIOStream&& src) noexcept
{
  Gio::IOStream::operator=(std::move(src));
  return *this;
}


SimpleIOStream::~SimpleIOStream() noexcept
{}


SimpleIOStream::CppClassType SimpleIOStream::simpleiostream_class_; // initialize static member

GType SimpleIOStream::get_type()
{
  return simpleiostream_class_.init().get_type();
}


GType SimpleIOStream::get_base_type()
{
  return g_simple_io_stream_get_type();
}


SimpleIOStream::SimpleIOStream(const Glib::RefPtr<InputStream>& input_stream, const Glib::RefPtr<OutputStream>& output_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gio::IOStream(Glib::ConstructParams(simpleiostream_class_.init(), "input_stream", const_cast<GInputStream*>(Glib::unwrap(input_stream)), "output_stream", const_cast<GOutputStream*>(Glib::unwrap(output_stream)), nullptr))
{
  

}

Glib::RefPtr<SimpleIOStream> SimpleIOStream::create(const Glib::RefPtr<InputStream>& input_stream, const Glib::RefPtr<OutputStream>& output_stream)
{
  return Glib::RefPtr<SimpleIOStream>( new SimpleIOStream(input_stream, output_stream) );
}


Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InputStream> > SimpleIOStream::property_input_stream() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InputStream> >(this, "input-stream");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<OutputStream> > SimpleIOStream::property_output_stream() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<OutputStream> >(this, "output-stream");
}


} // namespace Gio



// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!


#include <glibmm.h>

#include <glibmm/binding.h>
#include <glibmm/private/binding_p.h>


/* Copyright (C) 2014 The glibmm Development Team
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

#include <glibmm/binding.h>
#include <glib.h>

namespace
{
// TODO: When we can break ABI, replace this GQuark by a new data member in Glib::Binding.
GQuark quark_manage = g_quark_from_string("glibmm__Glib::Binding::manage");

struct BindingTransformSlots
{
  BindingTransformSlots(const Glib::Binding::SlotTransform& transform_to,
    const Glib::Binding::SlotTransform& transform_from)
  : from_source_to_target(transform_to), from_target_to_source(transform_from)
  {
  }

  Glib::Binding::SlotTransform from_source_to_target;
  Glib::Binding::SlotTransform from_target_to_source;
};

gboolean
Binding_transform_callback_common(
  const GValue* from_value, GValue* to_value, Glib::Binding::SlotTransform& the_slot)
{
  bool result = false;
  try
  {
    result = the_slot(from_value, to_value);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return result;
}

gboolean
Binding_transform_to_callback(
  GBinding*, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  Glib::Binding::SlotTransform& the_slot =
    static_cast<BindingTransformSlots*>(user_data)->from_source_to_target;

  return Binding_transform_callback_common(from_value, to_value, the_slot);
}

gboolean
Binding_transform_from_callback(
  GBinding*, const GValue* from_value, GValue* to_value, gpointer user_data)
{
  Glib::Binding::SlotTransform& the_slot =
    static_cast<BindingTransformSlots*>(user_data)->from_target_to_source;

  return Binding_transform_callback_common(from_value, to_value, the_slot);
}

void
Binding_transform_callback_destroy(gpointer user_data)
{
  delete static_cast<BindingTransformSlots*>(user_data);
}

} // anonymous namespace

namespace Glib
{
// static
Glib::RefPtr<Binding>
Binding::bind_property_value(const PropertyProxy_Base& source_property,
  const PropertyProxy_Base& target_property, BindingFlags flags, const SlotTransform& transform_to,
  const SlotTransform& transform_from)
{
  GBinding* binding = nullptr;
  if (transform_to.empty() && transform_from.empty())
  {
    // No user-supplied transformations.
    binding =
      g_object_bind_property(source_property.get_object()->gobj(), source_property.get_name(),
        target_property.get_object()->gobj(), target_property.get_name(), (GBindingFlags)flags);
  }
  else
  {
    // Create copies of the slots. A pointer to this will be passed
    // through the callback's data parameter. It will be deleted
    // when Binding_transform_callback_destroy() is called.
    BindingTransformSlots* slots_copy = new BindingTransformSlots(transform_to, transform_from);

    binding = g_object_bind_property_full(source_property.get_object()->gobj(),
      source_property.get_name(), target_property.get_object()->gobj(), target_property.get_name(),
      (GBindingFlags)flags, transform_to.empty() ? nullptr : &Binding_transform_to_callback,
      transform_from.empty() ? nullptr : &Binding_transform_from_callback, slots_copy,
      &Binding_transform_callback_destroy);
  }

  if (!binding)
    return Glib::RefPtr<Binding>();

  // Take an extra ref. GBinding uses one ref itself, and drops it if
  // either the source object or the target object is finalized.
  // The GBinding object must not be destroyed while there are RefPtrs around,
  // unless set_manage() was called.
  g_object_ref(binding);
  return Glib::RefPtr<Binding>(new Binding(binding));
}

// We must hand-code get_source() and get_target().
// g_binding_get_source() and g_binding_get_target() are deprecated in glib 2.68.
// We can't use the replacements g_binding_dup_source() and g_binding_dup_target(),
// which are new in glib 2.68. This version of glibmm does not require glib 2.68.
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
Glib::RefPtr<Glib::ObjectBase> Binding::get_source()
{
  Glib::RefPtr<Glib::ObjectBase> retvalue = Glib::wrap(g_binding_get_source(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Glib::ObjectBase> Binding::get_source() const
{
  return const_cast<Binding*>(this)->get_source();
}

Glib::RefPtr<Glib::ObjectBase> Binding::get_target()
{
  Glib::RefPtr<Glib::ObjectBase> retvalue = Glib::wrap(g_binding_get_target(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Glib::ObjectBase> Binding::get_target() const
{
  return const_cast<Binding*>(this)->get_target();
}

void
Binding::unbind()
{
  // Call g_binding_unbind() only once. It always calls g_object_unref().
  if (g_binding_get_source(gobj()))
    g_binding_unbind(gobj());
}

// Override unreference() from ObjectBase.
//
// Why is this necessary? Because GBinding is an unusual kind of GObject.
// It calls g_object_unref() itself, if either the source object or the
// target object is finalized, almost like g_binding_unbind().
// But the GBinding object shall be destroyed when and only when the last
// reference from a Glib::RefPtr is dropped, unless set_manage() was called.
void
Binding::unreference() const
{
  if (!g_object_get_qdata(gobject_, quark_manage))
  {
    GBinding* const binding = const_cast<GBinding*>(gobj());

    // If the last Glib::RefPtr is being deleted, and the binding has not been unbound,
    // then drop the extra reference that was added by bind_property_value().
    if (gobject_->ref_count == 2 && g_binding_get_source(binding))
      g_object_unref(binding);
  }

  Object::unreference();
}
G_GNUC_END_IGNORE_DEPRECATIONS

void
Binding::set_manage()
{
  // Any pointer can be set, just not nullptr.
  g_object_set_qdata(gobject_, quark_manage, this);
}

const Glib::RefPtr<Glib::Binding>&
manage(const Glib::RefPtr<Glib::Binding>& binding)
{
  if (binding)
    binding->set_manage();

  return binding;
}

} // namespace Glib

namespace
{
} // anonymous namespace

// static
GType Glib::Value<Glib::BindingFlags>::value_type()
{
  return g_binding_flags_get_type();
}


namespace Glib
{

Glib::RefPtr<Glib::Binding> wrap(GBinding* object, bool take_copy)
{
  return Glib::RefPtr<Glib::Binding>( dynamic_cast<Glib::Binding*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Glib
{


/* The *_Class implementation: */

const Glib::Class& Binding_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Binding_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_binding_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Binding_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Binding_Class::wrap_new(GObject* object)
{
  return new Binding((GBinding*)object);
}


/* The implementation: */

GBinding* Binding::gobj_copy()
{
  reference();
  return gobj();
}

Binding::Binding(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Binding::Binding(GBinding* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Binding::Binding(Binding&& src) noexcept
: Glib::Object(std::move(src))
{}

Binding& Binding::operator=(Binding&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


Binding::~Binding() noexcept
{}


Binding::CppClassType Binding::binding_class_; // initialize static member

GType Binding::get_type()
{
  return binding_class_.init().get_type();
}


GType Binding::get_base_type()
{
  return g_binding_get_type();
}


Glib::ustring Binding::get_source_property() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_binding_get_source_property(const_cast<GBinding*>(gobj())));
}

Glib::ustring Binding::get_target_property() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_binding_get_target_property(const_cast<GBinding*>(gobj())));
}

BindingFlags Binding::get_flags() const
{
  return ((BindingFlags)(g_binding_get_flags(const_cast<GBinding*>(gobj()))));
}


Glib::PropertyProxy_ReadOnly< Glib::BindingFlags > Binding::property_flags() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::BindingFlags >(this, "flags");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> > Binding::property_source() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >(this, "source");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Binding::property_source_property() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "source-property");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> > Binding::property_target() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >(this, "target");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > Binding::property_target_property() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "target-property");
}


} // namespace Glib



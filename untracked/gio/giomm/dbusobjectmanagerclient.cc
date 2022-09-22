// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/dbusobjectmanagerclient.h>
#include <giomm/private/dbusobjectmanagerclient_p.h>


/* Copyright (C) 2019 The giomm Development Team
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

namespace
{
GType get_proxy_type_callback(GDBusObjectManagerClient* manager,
  const gchar* object_path, const gchar* interface_name, gpointer user_data)
{
  auto slot_proxy_type = static_cast<Gio::DBus::ObjectManagerClient::SlotProxyType*>(user_data);
  try
  {
    return (*slot_proxy_type)(Glib::wrap(manager, true),
           Glib::convert_const_gchar_ptr_to_ustring(object_path),
           Glib::convert_const_gchar_ptr_to_ustring(interface_name));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return 0;
}

} // anonymous namespace

namespace Gio
{

namespace DBus
{
using MapChangedProperties = ObjectManagerClient::MapChangedProperties;

ObjectManagerClient::ObjectManagerClient(const Glib::RefPtr<Connection>& connection,
  const Glib::ustring& name, const Glib::ustring& object_path,
  const SlotAsyncReady& slot_async_ready,
  const Glib::RefPtr<Cancellable>& cancellable,
  const SlotProxyType& slot_proxy_type, ObjectManagerClientFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(objectmanagerclient_class_.init(), "connection",Glib::unwrap(connection),"flags",static_cast<GDBusObjectManagerClientFlags>(flags),"name",Glib::c_str_or_nullptr(name),"object-path",Glib::c_str_or_nullptr(object_path),"get-proxy-type-func",slot_proxy_type ? get_proxy_type_callback : nullptr,"get-proxy-type-user-data",slot_proxy_type ? new SlotProxyType(slot_proxy_type) : nullptr,"get-proxy-type-destroy-notify",slot_proxy_type ? Glib::destroy_notify_delete<SlotProxyType> : nullptr
, nullptr))
{
  if (slot_async_ready)
  {
    // Asynchronous construction
    if (cancellable)
      init_async(slot_async_ready, cancellable);
    else
      init_async(slot_async_ready);
  }
  else
  {
    // Synchronous construction
    if (cancellable)
      init(cancellable);
    else
      init();
  }
}

ObjectManagerClient::ObjectManagerClient(BusType bus_type,
  const Glib::ustring& name, const Glib::ustring& object_path,
  const SlotAsyncReady& slot_async_ready,
  const Glib::RefPtr<Cancellable>& cancellable,
  const SlotProxyType& slot_proxy_type, ObjectManagerClientFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(objectmanagerclient_class_.init(), "bus-type",bus_type,"flags",static_cast<GDBusObjectManagerClientFlags>(flags),"name",Glib::c_str_or_nullptr(name),"object-path",Glib::c_str_or_nullptr(object_path),"get-proxy-type-func",slot_proxy_type ? get_proxy_type_callback : nullptr,"get-proxy-type-user-data",slot_proxy_type ? new SlotProxyType(slot_proxy_type) : nullptr,"get-proxy-type-destroy-notify",slot_proxy_type ? Glib::destroy_notify_delete<SlotProxyType> : nullptr
, nullptr))
{
  if (slot_async_ready)
  {
    // Asynchronous construction
    if (cancellable)
      init_async(slot_async_ready, cancellable);
    else
      init_async(slot_async_ready);
  }
  else
  {
    // Synchronous construction
    if (cancellable)
      init(cancellable);
    else
      init();
  }
}

void ObjectManagerClient::create(const Glib::RefPtr<Connection>& connection,
  const Glib::ustring& name, const Glib::ustring& object_path,
  const SlotAsyncReady& slot_async_ready,
  const Glib::RefPtr<Cancellable>& cancellable,
  const SlotProxyType& slot_proxy_type, ObjectManagerClientFlags flags)
{
  // This does not return anything, because it is async - see create_finish().
  ObjectManagerClient(connection, name, object_path, slot_async_ready, cancellable, slot_proxy_type, flags);
}

Glib::RefPtr<Gio::DBus::ObjectManagerClient> ObjectManagerClient::create_sync(
  const Glib::RefPtr<Connection>& connection,
  const Glib::ustring& name, const Glib::ustring& object_path,
  const Glib::RefPtr<Cancellable>& cancellable,
  const SlotProxyType& slot_proxy_type, ObjectManagerClientFlags flags)
{
  return Glib::RefPtr<ObjectManagerClient>(
    new ObjectManagerClient(connection, name, object_path, {}, cancellable, slot_proxy_type, flags));
}

void ObjectManagerClient::create_for_bus(BusType bus_type,
  const Glib::ustring& name, const Glib::ustring& object_path,
  const SlotAsyncReady& slot_async_ready,
  const Glib::RefPtr<Cancellable>& cancellable,
  const SlotProxyType& slot_proxy_type, ObjectManagerClientFlags flags)
{
  // This does not return anything, because it is async - see create_for_bus_finish().
  ObjectManagerClient(bus_type, name, object_path, slot_async_ready, cancellable, slot_proxy_type, flags);
}

Glib::RefPtr<Gio::DBus::ObjectManagerClient> ObjectManagerClient::create_for_bus_sync(
  BusType bus_type,
  const Glib::ustring& name, const Glib::ustring& object_path,
  const Glib::RefPtr<Cancellable>& cancellable,
  const SlotProxyType& slot_proxy_type, ObjectManagerClientFlags flags)
{
  return Glib::RefPtr<ObjectManagerClient>(
    new ObjectManagerClient(bus_type, name, object_path, {}, cancellable, slot_proxy_type, flags));
}

} // namespace DBus

} // namespace Gio

namespace
{


static void ObjectManagerClient_signal_interface_proxy_signal_callback(GDBusObjectManagerClient* self, GDBusObjectProxy* p0,GDBusProxy* p1,const gchar* p2,const gchar* p3,GVariant* p4,void* data)
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot< void,const Glib::RefPtr<Gio::DBus::ObjectProxy>&,const Glib::RefPtr<Gio::DBus::Proxy>&,const Glib::ustring&,const Glib::ustring&,const Glib::VariantContainerBase& >;

  auto obj = dynamic_cast<ObjectManagerClient*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
, Glib::convert_const_gchar_ptr_to_ustring(p2)
, Glib::convert_const_gchar_ptr_to_ustring(p3)
, Glib::VariantContainerBase(p4, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

static const Glib::SignalProxyInfo ObjectManagerClient_signal_interface_proxy_signal_info =
{
  "interface-proxy-signal",
  (GCallback) &ObjectManagerClient_signal_interface_proxy_signal_callback,
  (GCallback) &ObjectManagerClient_signal_interface_proxy_signal_callback
};


static void ObjectManagerClient_signal_interface_proxy_properties_changed_callback(GDBusObjectManagerClient* self, GDBusObjectProxy* p0,GDBusProxy* p1,GVariant* p2,const gchar*const* p3,void* data)
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot< void,const Glib::RefPtr<Gio::DBus::ObjectProxy>&,const Glib::RefPtr<Gio::DBus::Proxy>&,const MapChangedProperties&,const std::vector<Glib::ustring>& >;

  auto obj = dynamic_cast<ObjectManagerClient*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
, Glib::Variant<MapChangedProperties>(p2, true).get()
, Glib::ArrayHandler<Glib::ustring>::array_to_vector(p3, Glib::OWNERSHIP_NONE)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

static const Glib::SignalProxyInfo ObjectManagerClient_signal_interface_proxy_properties_changed_info =
{
  "interface-proxy-properties-changed",
  (GCallback) &ObjectManagerClient_signal_interface_proxy_properties_changed_callback,
  (GCallback) &ObjectManagerClient_signal_interface_proxy_properties_changed_callback
};


} // anonymous namespace

// static
GType Glib::Value<Gio::DBus::ObjectManagerClientFlags>::value_type()
{
  return g_dbus_object_manager_client_flags_get_type();
}


namespace Glib
{

Glib::RefPtr<Gio::DBus::ObjectManagerClient> wrap(GDBusObjectManagerClient* object, bool take_copy)
{
  return Glib::RefPtr<Gio::DBus::ObjectManagerClient>( dynamic_cast<Gio::DBus::ObjectManagerClient*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{

namespace DBus
{


/* The *_Class implementation: */

const Glib::Class& ObjectManagerClient_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ObjectManagerClient_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_object_manager_client_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Initable::add_interface(get_type());
  AsyncInitable::add_interface(get_type());
  DBus::ObjectManager::add_interface(get_type());

  }

  return *this;
}


void ObjectManagerClient_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->interface_proxy_signal = &interface_proxy_signal_callback;
  klass->interface_proxy_properties_changed = &interface_proxy_properties_changed_callback;
}


void ObjectManagerClient_Class::interface_proxy_signal_callback(GDBusObjectManagerClient* self, GDBusObjectProxy* p0, GDBusProxy* p1, const gchar* p2, const gchar* p3, GVariant* p4)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_interface_proxy_signal(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
, Glib::convert_const_gchar_ptr_to_ustring(p2)
, Glib::convert_const_gchar_ptr_to_ustring(p3)
, Glib::VariantContainerBase(p4, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->interface_proxy_signal)
    (*base->interface_proxy_signal)(self, p0, p1, p2, p3, p4);
}
void ObjectManagerClient_Class::interface_proxy_properties_changed_callback(GDBusObjectManagerClient* self, GDBusObjectProxy* p0, GDBusProxy* p1, GVariant* p2, const gchar*const* p3)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_interface_proxy_properties_changed(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
, Glib::Variant<MapChangedProperties>(p2, true).get()
, Glib::ArrayHandler<Glib::ustring>::array_to_vector(p3, Glib::OWNERSHIP_NONE)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->interface_proxy_properties_changed)
    (*base->interface_proxy_properties_changed)(self, p0, p1, p2, p3);
}


Glib::ObjectBase* ObjectManagerClient_Class::wrap_new(GObject* object)
{
  return new ObjectManagerClient((GDBusObjectManagerClient*)object);
}


/* The implementation: */

GDBusObjectManagerClient* ObjectManagerClient::gobj_copy()
{
  reference();
  return gobj();
}

ObjectManagerClient::ObjectManagerClient(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

ObjectManagerClient::ObjectManagerClient(GDBusObjectManagerClient* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


ObjectManagerClient::ObjectManagerClient(ObjectManagerClient&& src) noexcept
: Glib::Object(std::move(src))
  , Initable(std::move(src))
  , AsyncInitable(std::move(src))
  , DBus::ObjectManager(std::move(src))
{}

ObjectManagerClient& ObjectManagerClient::operator=(ObjectManagerClient&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  Initable::operator=(std::move(src));
  AsyncInitable::operator=(std::move(src));
  DBus::ObjectManager::operator=(std::move(src));
  return *this;
}


ObjectManagerClient::~ObjectManagerClient() noexcept
{}


ObjectManagerClient::CppClassType ObjectManagerClient::objectmanagerclient_class_; // initialize static member

GType ObjectManagerClient::get_type()
{
  return objectmanagerclient_class_.init().get_type();
}


GType ObjectManagerClient::get_base_type()
{
  return g_dbus_object_manager_client_get_type();
}


Glib::RefPtr<Gio::DBus::ObjectManagerClient> ObjectManagerClient::create_finish(const Glib::RefPtr<AsyncResult>& res)
{
  GError* gerror = nullptr;
  Glib::RefPtr<Gio::DBus::ObjectManagerClient> retvalue = Glib::wrap((GDBusObjectManagerClient*)(g_dbus_object_manager_client_new_finish(Glib::unwrap(res), &(gerror))));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<Gio::DBus::ObjectManagerClient> ObjectManagerClient::create_for_bus_finish(const Glib::RefPtr<AsyncResult>& res)
{
  GError* gerror = nullptr;
  Glib::RefPtr<Gio::DBus::ObjectManagerClient> retvalue = Glib::wrap((GDBusObjectManagerClient*)(g_dbus_object_manager_client_new_for_bus_finish(Glib::unwrap(res), &(gerror))));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<Connection> ObjectManagerClient::get_connection()
{
  Glib::RefPtr<Connection> retvalue = Glib::wrap(g_dbus_object_manager_client_get_connection(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Connection> ObjectManagerClient::get_connection() const
{
  return const_cast<ObjectManagerClient*>(this)->get_connection();
}

ObjectManagerClientFlags ObjectManagerClient::get_flags() const
{
  return ((ObjectManagerClientFlags)(g_dbus_object_manager_client_get_flags(const_cast<GDBusObjectManagerClient*>(gobj()))));
}

Glib::ustring ObjectManagerClient::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_object_manager_client_get_name(const_cast<GDBusObjectManagerClient*>(gobj())));
}

Glib::ustring ObjectManagerClient::get_name_owner() const
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_dbus_object_manager_client_get_name_owner(const_cast<GDBusObjectManagerClient*>(gobj())));
}


Glib::SignalProxy< void,const Glib::RefPtr<Gio::DBus::ObjectProxy>&,const Glib::RefPtr<Gio::DBus::Proxy>&,const Glib::ustring&,const Glib::ustring&,const Glib::VariantContainerBase& > ObjectManagerClient::signal_interface_proxy_signal()
{
  return Glib::SignalProxy< void,const Glib::RefPtr<Gio::DBus::ObjectProxy>&,const Glib::RefPtr<Gio::DBus::Proxy>&,const Glib::ustring&,const Glib::ustring&,const Glib::VariantContainerBase& >(this, &ObjectManagerClient_signal_interface_proxy_signal_info);
}


Glib::SignalProxy< void,const Glib::RefPtr<Gio::DBus::ObjectProxy>&,const Glib::RefPtr<Gio::DBus::Proxy>&,const MapChangedProperties&,const std::vector<Glib::ustring>& > ObjectManagerClient::signal_interface_proxy_properties_changed()
{
  return Glib::SignalProxy< void,const Glib::RefPtr<Gio::DBus::ObjectProxy>&,const Glib::RefPtr<Gio::DBus::Proxy>&,const MapChangedProperties&,const std::vector<Glib::ustring>& >(this, &ObjectManagerClient_signal_interface_proxy_properties_changed_info);
}


Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> > ObjectManagerClient::property_connection() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >(this, "connection");
}

Glib::PropertyProxy_ReadOnly< ObjectManagerClientFlags > ObjectManagerClient::property_flags() const
{
  return Glib::PropertyProxy_ReadOnly< ObjectManagerClientFlags >(this, "flags");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ObjectManagerClient::property_object_path() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "object-path");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ObjectManagerClient::property_name() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "name");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ObjectManagerClient::property_name_owner() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "name-owner");
}


void Gio::DBus::ObjectManagerClient::on_interface_proxy_signal(const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy, const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy, const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->interface_proxy_signal)
    (*base->interface_proxy_signal)(gobj(),Glib::unwrap(object_proxy),Glib::unwrap(interface_proxy),sender_name.c_str(),signal_name.c_str(),const_cast<GVariant*>((parameters).gobj()));
}
void Gio::DBus::ObjectManagerClient::on_interface_proxy_properties_changed(const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy, const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy, const MapChangedProperties& changed_properties, const std::vector<Glib::ustring>& invalidated_properties)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->interface_proxy_properties_changed)
    (*base->interface_proxy_properties_changed)(gobj(),Glib::unwrap(object_proxy),Glib::unwrap(interface_proxy),const_cast<GVariant*>(Glib::Variant<MapChangedProperties>::create(changed_properties).gobj()),Glib::ArrayHandler<Glib::ustring>::vector_to_array(invalidated_properties).data());
}


} // namespace DBus

} // namespace Gio



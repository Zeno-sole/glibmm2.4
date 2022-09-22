// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!
#ifndef _GLIBMM_BALANCEDTREE_H
#define _GLIBMM_BALANCEDTREE_H

#include <glibmmconfig.h>

#ifndef GLIBMM_DISABLE_DEPRECATED


/* Copyright (C) 2010 Szilárd Pfeiffer <mailbox@pfeifferszilard.hu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


 // This whole file is deprecated.

#include <glibmm/refptr.h>
#include <glibmm/ustring.h>
#include <glibmm/error.h>
#include <glibmm/arrayhandle.h>
#include <glib.h>

namespace Glib
{

/** Balanced Binary Trees — a sorted collection of key/value pairs optimized for searching and traversing in order.
 * The BalancedTree structure and its associated functions provide a sorted
 * collection of key/value pairs optimized for searching and traversing in
 * order.
 *
 * To insert a key/value pair into a BalancedTree use insert().
 *
 * To lookup the value corresponding to a given key, use lookup().
 *
 * To find out the number of nodes in a BalancedTree, use nnodes(). To get the height of a BalancedTree, use height().
 *
 * To traverse a BalancedTree, calling a function for each node visited in the traversal, use foreach().
 *
 * To remove a key/value pair use remove().
 *
 * Any type to be used with this template must implement copy constructor.
 * Compiler-generated implementations are OK, provided they do the right
 * thing for the type. Both keys and values are stored in the balanced binary
 * tree as copies, created by copy constructors.
 *
 * Type of key to be used with this template must implement:
 * - less than operator
 * - greater than operator
 *
 * @deprecated Use std::map or std::unordered_map instead.
 *
 * @newin{2,24}
 */
template <typename K, typename V>
class BalancedTree
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = BalancedTree;
  using BaseObjectType = GTree;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  using TraverseFunc = sigc::slot<bool, const K&, const V&>;
  using CompareFunc = sigc::slot<int, const K&, const K&>;

protected:
  BalancedTree() :
    key_compare_slot(sigc::ptr_fun(key_compare))
  {
    gobject_ = g_tree_new_full(on_compare_tree, &key_compare_slot, on_destroy_key, on_destroy_value);
  }

  BalancedTree(const CompareFunc &key_compare_slot_) :
    key_compare_slot(key_compare_slot_)
  {
    gobject_ = g_tree_new_full(on_compare_tree, &key_compare_slot, on_destroy_key, on_destroy_value);
  }

  //TODO: Add move operations, being careful of universal references and overload resolution.

public:
  static Glib::RefPtr< BalancedTree<K, V> > create()
  {
    return Glib::RefPtr< BalancedTree<K, V> >(new BalancedTree());
  }

  static Glib::RefPtr< BalancedTree<K, V> > create(const CompareFunc &key_compare_slot)
  {
    return Glib::RefPtr< BalancedTree<K, V> >(new BalancedTree(key_compare_slot));
  }

  ~BalancedTree()
  {
    g_tree_destroy(gobject_);
  }
  

  /// Provides access to the underlying C GObject.
  inline GTree* gobj()
  {
    return gobject_;
  }

  /// Provides access to the underlying C GObject.
  inline const GTree* gobj() const
  {
    return gobject_;
  }

  /** Increments the reference count of tree by one.  It is safe to call
   * this function from any thread.
   */
  void reference()
  {
    g_tree_ref(gobject_);
  }
  

  /** Decrements the reference count of tree by one. If the reference count
   * drops to 0, all keys and values will be destroyed and all memory allocated
   * by tree will be released.
   *
   * It is safe to call this function from any thread.
   */
  void unreference()
  {
    g_tree_unref(gobject_);
  }
  

  /** Inserts a key/value pair into a BalancedTree. If the given key already
   * exists in the BalancedTree its corresponding value is set to the new
   * value.
   *
   * The tree is automatically 'balanced' as new key/value pairs are added,
   * so that the distance from the root to every leaf is as small as possible.
   *
   * @param key The key to insert.
   * @param value The value corresponding to the key.
   */
  void insert(const K &key, const V &value)
  {
    g_tree_insert(gobj(), reinterpret_cast<void *>(new K(key)), reinterpret_cast<void *>(new V(value)));
  }
  

  /** Removes a key/value pair from a BalancedTree.
   *
   * If the key does not exist in the BalancedTree, the function does nothing.
   *
   * @param key The key to remove.
   * @result true if the key was found (prior to 2.8, this function returned
   *   nothing)
   */
  bool remove(const K &key)
  {
    return g_tree_remove(const_cast<GTree*>(gobj()), &key);
  }
  

  /** Gets the value corresponding to the given key. Since a BalancedTree is
   * automatically balanced as key/value pairs are added, key lookup is very
   * fast.
   *
   * @param key The key to look up.
   * @result The value corresponding to the key, or <tt>nullptr</tt> if the key was
   * not found.
   */
  V* lookup(const K &key)
  {
    return reinterpret_cast<V *>(g_tree_lookup(gobj(), &key));
  }
  

  const V* lookup(const K &key) const
  {
    return reinterpret_cast<const V *>(g_tree_lookup(gobj(), &key));
  }
  

  /** Gets the height of a BalancedTree.
   *
   * If the BalancedTree contains no nodes, the height is 0.
   * If the BalancedTree contains only one root node the height is 1.
   * If the root node has children the height is 2, etc.
   *
   * @result the height of the BalancedTree.
   */
  gint height() const
  {
    return g_tree_height(const_cast<GTree*>(gobj()));
  }
  

  /** Gets the number of nodes in a BalancedTree.
   *
   * @result the number of nodes in the BalancedTree.
   */
  gint nnodes() const
  {
    return g_tree_nnodes(const_cast<GTree*>(gobj()));
  }
  

  /** Calls the given function for each of the key/value pairs in the
   * BalancedTree.
   * The function is passed the key and value of each pair. The tree is
   * traversed in sorted order.
   *
   * The tree may not be modified while iterating over it (you can't
   * add/remove items). To remove all items matching a predicate, you need
   * to add each item to a list in your TraverseFunc as you walk over
   * the tree, then walk the list and remove each item.
   *
   * @param func The function to call for each node visited. If this function
   *   returns true, the traversal is stopped.
   */
  void foreach(const TraverseFunc& func) const
  {
    TraverseFunc func_copy = func;
    g_tree_foreach(const_cast<GTree*>(gobj()), c_callback_traverse, reinterpret_cast<gpointer>(&func_copy));
  }
  ;

  /** Searches a BalancedTree using @a search_func.
   *
   * The @a search_func is called with a reference to the key of a key/value pair
   * in the tree. If @a search_func returns 0 for a key/value pair, then search()
   * will return the value of that pair. If @a search_func returns -1,  searching
   * will proceed among the key/value pairs that have a smaller key; if
   * @a search_func returns 1, searching will proceed among the key/value pairs
   * that have a larger key.
   *
   * @param search_func A function used to search the BalancedTree.
   * @param key The key to search for.
   * @result The value corresponding to the found key, or <tt>nullptr</tt> if the key
   * was not found.
   */
  V* search(const CompareFunc &search_func, const K& key)
  {
    sigc::slot<int, const K&, const CompareFunc&, const K&> real_slot = sigc::ptr_fun(on_compare_key);
    sigc::slot<int, const K&> bound_slot = sigc::bind(real_slot, search_func, key);
    gpointer value = g_tree_search(gobj(), c_callback_search, reinterpret_cast<gconstpointer>(&bound_slot));

    return reinterpret_cast<V*>(value);
  }

  /** Searches a BalancedTree using @a search_func.
   *
   * The @a search_func is called with a reference to the key of a key/value pair
   * in the tree. If @a search_func returns 0 for a key/value pair, then search()
   * will return the value of that pair. If @a search_func returns -1,  searching
   * will proceed among the key/value pairs that have a smaller key; if
   * @a search_func returns 1, searching will proceed among the key/value pairs
   * that have a larger key.
   *
   * @param search_func A function used to search the BalancedTree.
   * @param key The key to search for.
   * @result The value corresponding to the found key, or <tt>nullptr</tt> if the key
   * was not found.
   */
  const V* search(const CompareFunc &search_func, const K& key) const
  {
    return const_cast<BalancedTree<K, V>*>(this)->search(search_func, key);
  }
  

  // The following functions don't make sense for the C++ wrapper.
  
  
private:
  /// Method for comparing keys by func (Internal use).
  static gint on_compare_key(const K& key_a, const CompareFunc& func, const K& key_b)
  {
    return func(key_a, key_b);
  }

  /// Wrapper for invoking GCompareFunc.
  static gint c_callback_search(gconstpointer a, gconstpointer b)
  {
    const sigc::slot<int, const K&>* slot = reinterpret_cast<const sigc::slot<int, const K&> *>(b);
    return (*slot)(*reinterpret_cast<const K*>(a));
  }

  /// Wrapper for invoking GTraverseFunc.
  static gboolean c_callback_traverse(gpointer key, gpointer value, gpointer slot)
  {
    const TraverseFunc* tf = reinterpret_cast<const TraverseFunc*>(slot);
    return (*tf)(*reinterpret_cast<const K*>(key), *reinterpret_cast<const V*>(value));
  }

  /// Method for comparing key values (Internal use).
  static gint on_compare_tree(gconstpointer a, gconstpointer b, gpointer data)
  {
    const K& key_a = *reinterpret_cast<const K*>(a);
    const K& key_b = *reinterpret_cast<const K*>(b);
    const CompareFunc& func = *reinterpret_cast<const CompareFunc*>(data);

    return func(key_a, key_b);
  }

  /// Method for destroying keys (Internal use).
  static void on_destroy_key(gpointer data)
  {
    K* key = reinterpret_cast<K*>(data);
    delete key;
  }

  /// Method for destroying values (Internal use).
  static void on_destroy_value(gpointer data)
  {
    V* value = reinterpret_cast<V*>(data);
    delete value;
  }

  /// Key compare function when it is not by the user (Internal use).
  static int key_compare(const K& key_a, const K& key_b)
  {
    if(key_a < key_b)
      return -1;

    if(key_a > key_b)
      return 1;

    return 0;
  }

  GTree* gobject_;
  CompareFunc key_compare_slot;


};

} // namespace Glib


#endif // GLIBMM_DISABLE_DEPRECATED


#endif /* _GLIBMM_BALANCEDTREE_H */


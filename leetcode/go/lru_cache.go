/*
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 * LRUCache cache = new LRUCache( 2 ); // 2 = capacity
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);    // returns 1
 * cache.put(3, 3); // evicts key 2
 * cache.get(2);    // returns -1 (not found)
 * cache.put(4, 4); // evicts key 1
 * cache.get(1);    // returns -1 (not found)
 * cache.get(3);    // returns 3
 * cache.get(4);    // returns 4
 */

package main

// LRUNode ...
type LRUNode struct {
	key  int
	val  int
	next *LRUNode
	prev *LRUNode
}

// LRUList ...
type LRUList interface {
	Begin() *LRUNode
	End() *LRUList
	Size() int
	Erase(it *LRUNode)
	PushFront(key, val int)
	MoveFront(it *LRUNode)
	Front() *LRUNode
	Back() *LRUNode
	PopBack()
}

func newLRUList() LRUList {
	return &LRUListImpl{
		head: nil,
		tail: nil,
		size: 0,
	}
}

// LRUListImpl ...
type LRUListImpl struct {
	head *LRUNode
	tail *LRUNode
	size int
}

// Begin ...
func (list *LRUListImpl) Begin() *LRUNode {
	return list.head
}

// End ...
func (list *LRUListImpl) End() *LRUList {
	return nil
}

// Size ...
func (list *LRUListImpl) Size() int {
	return list.size
}

func (list *LRUListImpl) remove(it *LRUNode) {
	if it == nil {
		return
	}

	if prev := it.prev; prev != nil {
		prev.next = it.next
	} else {
		list.head = it.next
	}

	if next := it.next; next != nil {
		next.prev = it.prev
	} else {
		list.tail = it.prev
	}
}

// Erase ...
func (list *LRUListImpl) Erase(it *LRUNode) {
	list.remove(it)
	if list.size > 0 {
		list.size--
	}
}

// PushFront ...
func (list *LRUListImpl) PushFront(key, val int) {
	node := &LRUNode{
		key:  key,
		val:  val,
		next: list.head,
	}
	if list.head != nil {
		list.head.prev = node
	} else {
		list.tail = node
	}

	list.head = node
	list.size++
}

// MoveFront ...
func (list *LRUListImpl) MoveFront(it *LRUNode) {
	list.remove(it)
	it.next = list.head
	it.prev = nil

	if list.head != nil {
		list.head.prev = it
	} else {
		list.tail = it
	}
	list.head = it
}

// Front ...
func (list *LRUListImpl) Front() *LRUNode {
	return list.head
}

// Back ...
func (list *LRUListImpl) Back() *LRUNode {
	return list.tail
}

// PopBack ...
func (list *LRUListImpl) PopBack() {
	list.Erase(list.tail)
}

// LRUCache ...
type LRUCache struct {
	list LRUList
	mp   map[int]*LRUNode
	cap  int
}

// Constructor ...
func Constructor(capacity int) LRUCache {
	return LRUCache{
		list: newLRUList(),
		mp:   map[int]*LRUNode{},
		cap:  capacity,
	}
}

// Get ...
func (cache *LRUCache) Get(key int) int {
	it, ok := cache.mp[key]
	if !ok {
		return -1
	}

	cache.list.MoveFront(it)

	return it.val
}

// Put ...
func (cache *LRUCache) Put(key int, value int) {
	it, ok := cache.mp[key]

	if !ok && cache.list.Size() == cache.cap {
		if listIt := cache.list.Back(); listIt != nil {
			cache.list.PopBack()
			delete(cache.mp, listIt.key)
		}
	}

	if ok {
		it.val = value
		cache.list.MoveFront(it)
	} else {
		cache.list.PushFront(key, value)
		cache.mp[key] = cache.list.Front()
	}
}

func main() {
	{
		cache := Constructor(2)
		cache.Put(1, 1)
		cache.Put(2, 2)
		assert(cache.Get(1) == 1, "Failed")  // returns 1
		cache.Put(3, 3)                      // evicts key 2
		assert(cache.Get(2) == -1, "Failed") // returns -1 (not found)
		cache.Put(4, 4)                      // evicts key 1
		assert(cache.Get(1) == -1, "Failed") // returns -1 (not found)
		assert(cache.Get(3) == 3, "Failed")  // returns 3
		assert(cache.Get(4) == 4, "Failed")  // returns 4
	}

	{
		cache := Constructor(1)
		cache.Put(2, 1)
		assert(cache.Get(2) == 1, "Failed")
	}
}

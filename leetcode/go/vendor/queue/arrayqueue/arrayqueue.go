package arrqueue

// NewArrayQueue ...
func NewArrayQueue() *ArrayQueue {
	return &ArrayQueue{
		arr:    make([]interface{}, 0),
		length: 0,
	}
}

// ArrayQueue ...
type ArrayQueue struct {
	arr    []interface{}
	length int
}

// Push ...
func (q *ArrayQueue) Push(val interface{}) {
	q.arr = append(q.arr, val)
	q.length++
}

// Pop ...
func (q *ArrayQueue) Pop() {
	q.arr = q.arr[1:]
	q.length--
}

// Front ...
func (q *ArrayQueue) Front() interface{} {
	if q.length == 0 {
		return nil
	}
	return q.arr[0]
}

// Size ...
func (q *ArrayQueue) Size() int {
	return q.length
}

// IsEmpty ...
func (q *ArrayQueue) IsEmpty() bool {
	return q.length == 0
}

// Clear ...
func (q *ArrayQueue) Clear() {
	q.arr = make([]interface{}, 0)
}

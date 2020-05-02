package queue

import arrqueue "queue/arrayqueue"

// Queue ...
type Queue interface {
	Push(interface{})
	Pop()
	Front() interface{}
	Size() int
	IsEmpty() bool
	Clear()
}

// NewArrayQueue ...
func NewArrayQueue() Queue {
	return arrqueue.NewArrayQueue()
}

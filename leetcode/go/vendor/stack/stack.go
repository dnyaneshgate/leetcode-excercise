package stack

import "stack/arraystack"

// Stack ...
type Stack interface {
	Push(interface{})
	Pop()
	Top() interface{}
	Size() int
	IsEmpty() bool
	Clear()
}

// NewArrayStack ...
func NewArrayStack() Stack {
	return arraystack.NewArrayStack()
}

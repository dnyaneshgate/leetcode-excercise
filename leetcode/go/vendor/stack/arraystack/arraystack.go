package arraystack

// NewArrayStack ...
func NewArrayStack() *ArrayStack {
	return &ArrayStack{
		arr: make([]interface{}, 0),
		top: -1,
	}
}

// ArrayStack ...
type ArrayStack struct {
	arr []interface{}
	top int
}

// Push ...
func (stack *ArrayStack) Push(val interface{}) {
	stack.arr = append(stack.arr, val)
	stack.top++
}

// Pop ...
func (stack *ArrayStack) Pop() {
	if stack.top == -1 {
		return
	}
	stack.arr = stack.arr[:stack.top]
	stack.top--
}

// Top ...
func (stack *ArrayStack) Top() interface{} {
	if stack.top >= 0 {
		return stack.arr[stack.top]
	}
	return nil
}

// Size ...
func (stack *ArrayStack) Size() int {
	return len(stack.arr)
}

// IsEmpty ...
func (stack *ArrayStack) IsEmpty() bool {
	return stack.top == -1
}

// Clear ...
func (stack *ArrayStack) Clear() {
	stack.arr = make([]interface{}, 0)
}

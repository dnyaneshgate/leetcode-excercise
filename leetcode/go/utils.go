package main

var assert = func(ok bool, msg string) {
	if !ok {
		panic(msg)
	}
}

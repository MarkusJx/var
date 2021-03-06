# var [![test](https://github.com/MarkusJx/var/workflows/test/badge.svg)](https://github.com/MarkusJx/var/actions?query=workflow%3Atest)
A (JavaScript-like) variable data type for C++. Accepts strings, numbers, arrays,
objects (maps) and functions. May throw weird errors.

I honestly don't know why anybody wants such a behaviour in C++, but here it is.

## Usage
### Creating values
Create a var type
```c++
markusjx::var v;
```

#### Create a number
```c++
markusjx::var n = 5;
```

#### Create a string
```c++
markusjx::var s = "some string";
```

#### Create a boolean
```c++
markusjx::var b = false;
```

#### Create a function

**NOTE: Functions can only take arguments of types ``markusjx::var`` can accept**
```c++
markusjx::var fn = [] (int i) {
    return i;
};
```

#### Create an array

**NOTE: Arrays must be created with explicit ``markusjx::array(1)`` constructor.
Arrays can only accept arguments of types ``markusjx::var`` can accept.**

Create using ``std::initializer_list``:
```c++
markusjx::var arr = markusjx::array({0, 1, "abc", false});
```

#### Create an object

**NOTE: Objects must be created with explicit ``markusjx::object(1)`` constructor.
Objects can only accept arguments of types ``markusjx::var`` can accept.**

Also note that functions cannot be used as keys in objects. If tried, an
```markusjx::argumentMismatchException``` will be thrown.

Create using ``std::initializer_list``:
```c++
markusjx::var obj = markusjx::object({{0, "1"},
                                      {"a", "b"},
                                      {"value", false}});
```

### Accessing values
Numbers, strings and booleans can be accessed "as normal", e.g.:
```c++
int i = n;
std::string str = s;
bool b1 = b;
```

Functions can be called like functions
```c++
markusjx::var res = fn(5);
```

Array values can be accessed by indices
```c++
markusjx::var a_1 = arr[1];
```

Array values can be set by indices. It is also possible to set a value for an index
which is out of range. In this case, the underlying ``std::vector`` will be expanded
to the requested index, all unset values will be set to ``markusjx::undefined`` and
the value at the requested index will be set to the new value. If no value is set,
the value at the requested index will remain ``markusjx::undefined``.
```c++
markusjx::var arr = markusjx::array({0, 1, 2, 3});

arr[0] = "a"; // arr[0] is now "a"

// Set arr[5] to "b", arr[4] will be undefined
// the size of arr will be 6
arr[5] = "b"; 
```

The same applies to objects:
```c++
markusjx::var obj = markusjx::object({{0, 1},
                                      {1, 1},
                                      {2, 3},
                                      {3, 5}});

obj[0] = "a"; // obj[0] is now "a"

// expand obj and set value for new key "a"
// to "b"
obj["a"] = "b";
```

Object values can be accessed by their key values
```c++
markusjx::var o_0 = o[0];

// or
markusjx::var o_a = o["a"];
```

It is also possible to iterate over arrays

**NOTE: It is only possible to iterate over arrays when their actual type is array
using ``asArray()``**
```c++
// must call asArray() on a var type to iterate
for (const markusjx::var& v : arr.asArray()) {
    // Do something with value v
}
```

This is also possible with objects
```c++
// must call asObject() on a var type to iterate
for (const auto& p : obj.asObject()) {
    // p is of type std::pair
    markusjx::var key = v.first;
    markusjx::var value = v.second;
}
```

## Exceptions
Various actions can cause exceptions to be thrown, e.g. when trying to get
a double value from a string. All exceptions thrown are subclasses of
``markusjx::exception``, so catching this seems to be a good idea.

Example:
```c++
try {
    var s = "abc";

    // Will throw a conversionException as it tries to convert
    // "abc" to a double value, which is not possible
    int i = s;
} catch (markusjx::exception &e) {
    // The exception message can be read with e.what()
    const char *what = e.what();

    // The type of the exception can be read using e.getType()
    // This will return the exception type, e.g. conversionException
    const char *type = e.getType();
}
```

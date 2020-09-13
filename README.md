# var
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
var res = fn(5);
```

Array values can be accessed by indices
```c++
var a_1 = arr[1];
```

Object values can be accessed by their key values
```c++
var o_0 = o[0];

// or
var o_a = a["a"];
```

It is also possible to iterate over arrays

**NOTE: It is only possible to iterate over arrays when their actual type is array
using ``asArray()``**
```c++
// must call asArray() on a var type to iterate
for (const var& v : arr.asArray()) {
    // Do something with value v
}
```

This is also possible with objects
```c++
// must call asObject() on a var type to iterate
for (const auto& p : obj.asObject()) {
    // p is of type std::pair
    var key = v.first;
    var value = v.second;
}
```
# Compiler
Making a language and compiler for fun.

## Language Goals
This is mainly for fun, but I do have some goals:
(Note that these are very rough)
* Relatively fast
* Relatively easy to use
  * Relatively suited to stuff I want to do I guess
  * Cleaner than C++

## Resources
* https://stackoverflow.com/questions/14357918/examples-where-compiler-optimized-functional-code-performs-better-than-imperativ
* Superoptimization
* http://conal.net/papers/compiling-to-categories/
* Point-free code
* https://tromp.github.io/cl/diagrams.html
* https://crypto.stanford.edu/~blynn

## Stages of a Compiler
### Front-end
* Lexing
* Parser (outputs AST)
* Semantic Analysis
* * Intermediate Representation Generation
  * A good IR is accurate and independent of hardware
    * Either an intermediate language* or a data structure
#### Intermediate Language
* C (some pros of p-code apply here as well)
* Threaded code
  * Generates small code
  * Used for microcomputers and amateur radio satelites
* p-code
  * Idealized
  * Easier to check
  * Better than having to write a new IR for each new machine
  * Good for getting compilers up-and-running quickly
  * Execution is slower, but this can be remedied by JIT
### Middle-end
* Targeted machine independent optimizations on IR (outputs optimized IR)
### Back-end
* Targeted machine dependent optimizations on IR
* Generates machine code


## Language Notes
Initial syntax sketch.

```
(int, int -> int) myfunc1 = (a, b) { return a + b }

// Explicit typing is only necessary for function arguments and return types.
(int) myvar = 42

(str) mystr = "foo"

(int...) myarr = [1, 2, 3]

(int... -> int) myfunc2 (a) { return 0 }

((int, int -> int) -> int) myfunc3 (f) { return 0 }

print(myfunc1(1, 1))

(str... -> nil) main = (args) {
  print("Hello, world.")

  x = 1
  y = 1
  print(x == y)

  (int -> int) mult = (a) { return 2 * a }
  (int...) A = [1, 2, 3]
  A = f:A
  // A is now [2, 4, 6]
}

// Experimental syntax for OOP.
type Object ((int) a, (int) b, (int, int -> this) new)
Object.new = (a, b) {
  
}
```
